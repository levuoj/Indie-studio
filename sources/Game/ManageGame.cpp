//
// ManageGame.cpp for ManageGame.cpp in /home/tvigier/Indie_studio/sources
//
// Made by thomas vigier
// Login   <thomas.vigier@epitech.eu>
//
// Started on  Tue May  9 17:32:16 2017 thomas vigier
// Last update Sun Jun 18 22:03:12 2017 Lebrun Kilian
//

#include <chrono>
#include <sstream>
#include <iomanip>
#include <time.h>
#include "ManageGame.hpp"
#include "Convert.hpp"

const int	ManageGame::_col = 60;

void			ManageGame::initPlayerAndIa(int nbPlayers, int pos, int & i, const Element::EType &type)
{
  int			x, y;

  x = pos % _col;
  y = (pos - x) / _col;
  if (i < nbPlayers)
    {
      this->_players.push_back(Player(std::make_pair(x, y), type));
      ++i;
    }
  else
    {
      this->_AIs.push_back(AI(std::make_pair(x, y), type));
      _AIs.back().setMap(_map);
    }
}

void			ManageGame::construct(int nbPlayers)
{
  int			pos(0);
  int			i(0);

  _isStarted = false;
  _music->playSound("assets/music/tie_fighter.ogg");
  this->loadMap("NORMAL");
  for (auto it = this->_map.begin(); it != _map.end(); ++it)
    {
      switch ((*it)->getType())
	{
	case Element::EType::POD1 :
	  this->initPlayerAndIa(nbPlayers, pos, i, (*it)->getType());
	  break;
	case Element::EType::POD2 :
	  this->initPlayerAndIa(nbPlayers, pos, i, (*it)->getType());
	  break;
	case Element::EType::POD3 :
	  this->initPlayerAndIa(nbPlayers, pos, i, (*it)->getType());
	  break;
	case Element::EType::POD4 :
	  this->initPlayerAndIa(nbPlayers, pos, i, (*it)->getType());
	  break;
	default:
	  break;
	}
      pos++;
    }
  _tieSound[0] = 426;
  _tieSound[1] = 1207;
  _tieSound[2] = 997;
  _tieSound[3] = 472;
}

ManageGame::ManageGame(std::string const &file, const std::vector<std::vector<irr::EKEY_CODE>> &keys, Music *music) : _victory(false), _nbFinish(0), _music(music)
{
  _type = DType::GAME;
  loadMap("BACKUP");

  if (loadSave(file) == false)
    {
      _map.clear();
      _AIs.clear();
      _players.clear();
      _chrono.setTime(0.0);
      construct(1);
    }

  _isStarted = false;
  int i = 0;
  for (auto &it : this->_players)
    {
      it.setKeys(keys.at(i));
      ++i;
    }
  _chrono.start();

  _finishLine[0] = 89;
  _finishLine[1] = 149;
  _finishLine[2] = 209;
  _finishLine[3] = 269;
  _finishLine[4] = 329;
  _finishLine[5] = 389;
}

ManageGame::ManageGame(int nbPlayers, const std::vector<std::vector<irr::EKEY_CODE>> & keys, Music *music) : _victory(false), _nbFinish(0), _music(music)
{
  this->_type = DType::GAME;
  construct(nbPlayers);

  int i = 0;
  for (auto &it : this->_players)
    {
      it.setKeys(keys.at(i));
      ++i;
    }

  _finishLine[0] = 89;
  _finishLine[1] = 149;
  _finishLine[2] = 209;
  _finishLine[3] = 269;
  _finishLine[4] = 329;
  _finishLine[5] = 389;
  
  _chrono.start();
}

DType			ManageGame::transferKey(EventReceiver const& receiver)
{
  _startChrono.incTime();

  if (receiver.keyDown(irr::KEY_ESCAPE) == true)
    return (PAUSE);

  if (_victory == false)
    {
      if (_startChrono.getTime() >= 7.0 &&
	  _startChrono.getTime() <= 7.1
	  && _isStarted == false)
	{
	  _isStarted = true,
	    _startChrono.setTime(0.0);
	  _type = DType::GAME;
	}
      else if (_isStarted == true)
	{
	  _chrono.incTime();

	  int				pos;
	  std::array<Element::EType, 8>	arr;

	  for (auto &it : _AIs)
	    {
	      pos = Convert::coordToPos<int>(it.getPosMap());
	      arr = this->arrounding(pos);
	      it.setArroundingCar(arr);
	    }
	  for (auto &it : _players)
	    {
	      pos = Convert::coordToPos<int>(it.getPosMap());
	      arr = this->arrounding(pos);
	      it.setArroundingCar(arr);
	      if (it.getCar()->getStop() == false)
		it.driver(receiver);
	    }
	  updateMap();
	}
    }
  else
    {
      _chrono.stop();
      makeRanking();
      makeEndScore();
      return (DType::ENDGAME);
    }
  return (_type);
}

const std::array<Element::EType, 8>	ManageGame::arrounding(int pos) const
{
  std::array<Element::EType, 8>		arr;

  arr[0] = this->_map[pos- 61]->getType();
  arr[1] = this->_map[pos - 60]->getType();
  arr[2] = this->_map[pos - 59]->getType();
  arr[3] = this->_map[pos + 1]->getType();
  arr[4] = this->_map[pos + 61]->getType();
  arr[5] = this->_map[pos + 60]->getType();
  arr[6] = this->_map[pos + 59]->getType();
  arr[7] = this->_map[pos - 1]->getType();
  return (arr);
}

GameElement			*ManageGame::ElementFromCharCar(const char c) const
{
  irr::io::path			path;
  Element::EType		type;
  std::pair<float, float>	pos(50.0f, 50.0f);

  switch (c)
    {
    case 'X':
      path = "X";
      type = Element::EType::BLOCK;
      break;
    case '.':
      path = ".";
      type = Element::EType::BLOCK;
      break;
    case '|':
      path = "|";
      type = Element::EType::BLOCK;
      break;
    case '\\':
      path = "\\";
      type = Element::EType::BLOCK;
      break;
    case '/':
      path = "/";
      type = Element::EType::BLOCK;
      break;
    case '-':
      path = "-";
      type = Element::EType::BLOCK;
      break;
    case ' ':
      path = " ";
      type = Element::EType::ROAD;
      break;
    case 'c':
      path = "c";
      type = Element::EType::ENDLINE;
      break;
    case 'o':
      path = "o";
      type = Element::EType::ENDLINE;
      break;
    case 'P':
      path = "P";
      type = Element::EType::POWERUP;
      break;
    case '>':
      path = "./assets/TieBomber.obj";
      type = Element::EType::POD1;
      break;
    case 'p':
      path = "./assets/TieDefender.obj";
      type = Element::EType::POD2;
      break;
    case 's':
      path = "./assets/TieInterceptor.obj";
      type = Element::EType::POD3;
      break;
    case 'g':
      path = "./assets/TiePhantom.obj";
      type = Element::EType::POD4;
      break;
    default:
      path = "";
      type = Element::EType::DEFAULT;
    }
  return (new GameElement(path, type, pos));
}

GameElement			*ManageGame::ElementFromChar(const char c) const
{
  irr::io::path			path;
  Element::EType		type;
  std::pair<float, float>	pos(50.0f, 50.0f);

  switch (c)
    {
    case 'X':
      path = "X";
      type = Element::EType::BLOCK;
      break;
    case '.':
      path = ".";
      type = Element::EType::BLOCK;
      break;
    case '|':
      path = "|";
      type = Element::EType::BLOCK;
      break;
    case '\\':
      path = "\\";
      type = Element::EType::BLOCK;
      break;
    case '/':
      path = "/";
      type = Element::EType::BLOCK;
      break;
    case '-':
      path = "-";
      type = Element::EType::BLOCK;
      break;
    case ' ':
      path = " ";
      type = Element::EType::ROAD;
      break;
    case 'c':
      path = "c";
      type = Element::EType::ENDLINE;
      break;
    case 'o':
      path = "o";
      type = Element::EType::ENDLINE;
      break;
    case 'P':
      path = "P";
      type = Element::EType::POWERUP;
      break;
    default:
      path = " ";
      type = Element::EType::ROAD;
    }
  return (new GameElement(path, type, pos));
}

void				ManageGame::loadMap(std::string const &str)
{
  ManageFile      file("./assets/circuit/newCircuit.txt");
  std::string     map;

  map = file.readFile();

  if (str == "BACKUP")
    {
      for (const auto &c : map)
	{
	  if (c != '\n')
	    this->_map.push_back(std::shared_ptr<Element>(ElementFromChar(c)));
	}
    }
  else if (str == "NORMAL")
    {
      for (const auto &c : map)
	{
	  if (c != '\n')
	    this->_map.push_back(std::shared_ptr<Element>(ElementFromCharCar(c)));
	}
    }
}

void				ManageGame::checkVictory(std::shared_ptr<Car> const &car)
{
  for (const auto &it : _finishLine)
    if (it + 480 == Convert::coordToPos<int>(car->getPosMap()))
      {
	car->setFinished(false);
	break ;
      }
  for (const auto &it : _finishLine)
    if (it == Convert::coordToPos<int>(car->getPosMap()) && car->getFinished() == false)
      {
	car->incLap();
	car->setFinished(true);
	break ;
      }
  if (car->getLap() == 3 && car->getStop() == false)
    {
      car->stop();
      car->setStop(true);
      ++_nbFinish;
    }
  if (_nbFinish == 3)
    {
      _victory = true;
    }
}

void				ManageGame::updateMap()
{
  for (auto &it : _AIs)
    {
      for (const auto &ite : _tieSound)
	if (ite == Convert::coordToPos<int>(it.getCar()->getPosMap()))
	  {
	    _music->playSound("assets/music/tie_fighter.ogg");
	    break ;
	  }
      if (it.getCar()->getStop() == false)
	it.chooseAction();
      checkVictory(it.getCar());
      if (it.getCar()->getStop() == true && it.getCar()->getIsRank() == true)
	{
	  _endScore.push_back(_chrono.getTime());
	  it.getCar()->setIsRank(false);
	}

      _map.at(Convert::coordToPos<int>(it.getCar()->getPosMap())) = it.getCar();

      if (_map.at(Convert::coordToPos<int>(it.getCar()->getPrevPos()))->getType() !=
	  Element::EType::ROAD)
	_map.at(Convert::coordToPos<int>(it.getCar()->getPrevPos())) =
	  std::shared_ptr<Element>(new Element(" ", Element::EType::ROAD));
    }

  for (const auto &it : _players)
    {
      _map.at(Convert::coordToPos<int>(it.getCar()->getPosMap())) = it.getCar();

      for (const auto &ite : _tieSound)
	if (ite == Convert::coordToPos<int>(it.getCar()->getPosMap()))
	  {
	    _music->playSound("assets/music/tie_fighter.ogg");
	    break ;
	  }
      if (it.getCar()->getStop() == false)
	checkVictory(it.getCar());

      if (it.getCar()->getStop() == true && it.getCar()->getIsRank() == true)
	{
	  _ranking.push_back(_chrono.getTime());
	  _endScore.push_back(_chrono.getTime());
	  it.getCar()->setIsRank(false);
	}

      if (_map.at(Convert::coordToPos<int>(it.getCar()->getPrevPos()))->getType() !=
	  Element::EType::ROAD)
	_map.at(Convert::coordToPos<int>(it.getCar()->getPrevPos())) =
	  std::shared_ptr<Element>(new Element(" ", Element::EType::ROAD));
    }
  this->_powerUp.incTime();

  for (int i = 2; i <= 4; i = i + 2)
    if (this->_map.at(Convert::coordToPos<int>(std::make_pair(11, i)))->getType() == Element::EType::ROAD)
      {
	this->_map.at(Convert::coordToPos<int>(std::make_pair(11, i))) =
	  std::shared_ptr<Element>(new Element(" ", Element::EType::POWERUPHIDE));
      }

  for (int i = 3; i <= 5; i = i + 2)
    if (this->_map.at(Convert::coordToPos<int>(std::make_pair(13, i)))->getType() == Element::EType::ROAD)
      {
	this->_map.at(Convert::coordToPos<int>(std::make_pair(13, i))) =
	  std::shared_ptr<Element>(new Element(" ", Element::EType::POWERUPHIDE));
      }
  
  if (this->_powerUp.getTime() > 5)
    {
      this->_powerUp.setTime(0.0);
      for (int i = 2; i <= 4; i = i + 2 )
	if (this->_map.at(Convert::coordToPos<int>(std::make_pair(11, i)))->getType() != Element::EType::POWERUP)
	  {
	    this->_map.at(Convert::coordToPos<int>(std::make_pair(11, i))) =
	      std::shared_ptr<Element>(new Element("P", Element::EType::POWERUP));
	  }


      for (int i = 3; i <= 5; i = i + 2 )
	if (this->_map.at(Convert::coordToPos<int>(std::make_pair(13, i)))->getType() != Element::EType::POWERUP)
	  {
	    this->_map.at(Convert::coordToPos<int>(std::make_pair(13, i))) =
	      std::shared_ptr<Element>(new Element("P", Element::EType::POWERUP));
	  }
    }
}

Chrono const&			ManageGame::getChrono() const
{
  return (_chrono);
}


bool				ManageGame::loadSave(std::string const &number)
{
  if (loadFile("./Saves/Save" + number + ".save") == false)
    return (false);
  else
    return (true);
}

bool				ManageGame::loadFile(std::string const& fileName)
{
  try
    {
      ManageFile		manageFile(fileName);
      std::string		file = manageFile.readFile();
      std::istringstream	iss(file);
      bool			skipFirst = false;
      std::string		tmp;

      while (std::getline(iss, tmp))
	{
	  if (skipFirst == true)
	    if (loadLine(tmp) == false)
	      return (false);
	  skipFirst = true;
	}
    }
  catch (std::exception const &)
    {
      return (false);
    }
  return (true);
}

bool				ManageGame::loadLine(std::string const& line)
{
  std::string			tmp;
  std::istringstream		iss(line);
  std::vector<std::string>	input;

  while (std::getline(iss, tmp, ' '))
    input.push_back(tmp);
  if ((input.size() != 8 && input.at(0) == "AI") ||
      (input.size() != 7 && input.at(0) == "PLAYER") ||
      (input.size() != 2 && input.at(0) == "CHRONO"))
    {
      return (false);
    }
  if (input.at(0) == "CHRONO")
    {
      if (checkChrono(input.at(1)) == false)
	  return (false);
      else
	_chrono.setTime(std::stod(input.at(1)));
    }
  else
    if (checkType(input) == false)
      return (false);
  return (true);
}

void				ManageGame::determineCarPath(const std::shared_ptr<Car> &car)
{
  switch (car->getType())
    {
    case Element::EType::POD1:
      car->setPath("./assets/TieBomber.b3d");
      break;
    case Element::EType::POD2:
      car->setPath("./assets/TieDefender.b3d");
      break;
    case Element::EType::POD3:
      car->setPath("./assets/TieInterceptor.b3d");
      break;
    case Element::EType::POD4:
      car->setPath("./assets/TiePhantom.b3d");
      break;
    default:
      break;
    }
}

bool				ManageGame::checkType(const std::vector<std::string> &input)
{
  if (input.at(0) == "PLAYER")
    {
      if (checkPosMap(input.at(1)) == false || checkCarType(input.at(2)) == false ||
	  checkAngle(input.at(3)) == false || checkLap(input.at(4)) == false ||
	  checkCheckpoint(input.at(5)) == false || checkDir(input.at(6)) == false)
	return (false);
    _players.push_back(Player(Convert::posToCoord<int>(std::stoi(input.at(1))),
			      Convert::strToCarType(input.at(2)),
			      std::stof(input.at(3)),
			      std::stoi(input.at(4)),
			      Convert::strToBool(input.at(5)),
			      Convert::strToDir(input.at(6))
			      ));
    determineCarPath(_players.back().getCar());
    _map.at(Convert::coordToPos<int>(_players.back().getCar()->getPosMap())) = _players.back().getCar();
    }
  else if (input.at(0) == "AI")
    {
      if (checkPosMap(input.at(1)) == false || checkCarType(input.at(2)) == false ||
	  checkAngle(input.at(3)) == false || checkLap(input.at(4)) == false ||
	  checkCheckpoint(input.at(5)) == false || checkDir(input.at(6)) == false ||
	  checkIdx(input.at(7)) == false)
	return (false);
    _AIs.push_back(AI(Convert::posToCoord<int>(std::stoi(input.at(1))),
		      Convert::strToCarType(input.at(2)),
		      std::stof(input.at(3)),
		      std::stoi(input.at(4)),
		      Convert::strToBool(input.at(5)),
		      Convert::strToDir(input.at(6)),
		      std::stoi(input.at(7))
		      ));
    _AIs.back().setMap(_map);
    determineCarPath(_AIs.back().getCar());
    _map.at(Convert::coordToPos<int>(_AIs.back().getCar()->getPosMap())) = _AIs.back().getCar();
    }
  else
    {
      return (false);
    }
  return (true);
}

bool				ManageGame::checkPosMap(std::string const& pos) const
{
  if (std::stoi(pos) >= 0 && std::stoi(pos) <= 1440 && _map[std::stoi(pos)]->getType() != Element::EType::BLOCK)
    return (true);
  else
    {
      return (false);
    }
}

bool				ManageGame::checkCarType(std::string const& cType) const
{
  if (cType == "1" || cType == "2"
      || cType == "3" || cType == "4")
    return (true);
  else
    {
      return (false);
    }
}

bool				ManageGame::checkAngle(std::string const& angle) const
{
  if ((std::stof(angle) >= 0.0f && std::stof(angle) <= 360.0f) ||
    (std::stof(angle) <= 0.0f && std::stof(angle) >= -360.0f))
    return (true);
  else
    {
      return (false);
    }
}

bool				ManageGame::checkLap(std::string const& lap) const
{
  if (std::stoi(lap) >= -1 && std::stoi(lap) <= 2)
    return (true);
  else
    {
      return (false);
    }
}

bool				ManageGame::checkCheckpoint(std::string const& cp) const
{
  if (cp == "0" || cp == "1")
    return (true);
  else
    {
      return (false);
    }
}

bool				ManageGame::checkDir(std::string const& dir) const
{
  if (std::stoi(dir) >= 0 && std::stoi(dir) <= 7)
    return (true);
  else
    {
      return (false);
    }
}

bool				ManageGame::checkIdx(std::string const &idx) const
{
  if (std::stoi(idx) >= 1 && std::stoi(idx) <= 15)
    return (true);
  else
    {
      return (false);
    }
}

bool				ManageGame::checkChrono(std::string const &chrono) const
{
  if (std::stoi(chrono) >= 0)
    return (true);
  else
    {
      return (false);
    }
}

void				ManageGame::makeSave(int number) const
{
  std::string			str;

  auto now = std::chrono::system_clock::now();

  std::stringstream		ss;
  auto in_time_t = std::chrono::system_clock::to_time_t(now);

#ifdef __linux__
  ss << std::put_time(localtime(&in_time_t), "%Y-%m-%d-%X");

#elif WIN64
  struct tm			newtime;

  localtime_s(&newtime, &in_time_t);
  ss << std::put_time(&newtime, "%Y-%m-%d-%X");
#endif

  str += ss.str();
  str += "\n";
  for (const auto &it : _players)
    {
      str += "PLAYER ";
      str += std::to_string(Convert::coordToPos<int>(it.getCar()->getPosMap())) + " ";
      str += std::to_string(it.getCar()->getType()) + " ";
      str += std::to_string(it.getCar()->getAngle()) + " ";
      str += std::to_string(it.getCar()->getLap()) + " ";
      str += std::to_string(it.getCar()->getFinished()) + " ";
      str += std::to_string(it.getCar()->getEDir()) + "\n";
    }
  for (const auto &it : _AIs)
    {
      str += "AI ";
      str += std::to_string(Convert::coordToPos<int>(it.getCar()->getPosMap())) + " ";
      str += std::to_string(it.getCar()->getType()) + " ";
      str += std::to_string(it.getCar()->getAngle()) + " ";
      str += std::to_string(it.getCar()->getLap()) + " ";
      str += std::to_string(it.getCar()->getFinished()) + " ";
      str += std::to_string(it.getCar()->getEDir()) + " ";
      str += std::to_string(it.getIdx()) + "\n";
    }
  str += "CHRONO " + std::to_string(_chrono.getTime());
  str += "\n";

  std::ofstream			stream;

  stream.open("./Saves/Save" + std::to_string(number) + ".save");
  stream << str;
  stream.close();
}

void				ManageGame::writeRanking()
{
  std::string		toWrite;
  std::ofstream		stream;

  std::sort(_ranking.begin(), _ranking.end(), std::less<double>());

  if (_ranking.size() < 3)
    {
      for (auto it : _ranking)
	toWrite += std::to_string(it) + "\n";
    }
  else
    {
      for (int idx = 0; idx < 3; ++idx)
	toWrite += std::to_string(_ranking.at(idx)) + "\n";
    }

  stream.open("Saves/leaderboard");
  stream << toWrite;
  stream.close();
}

void				ManageGame::makeRanking()
{
  try
    {
      ManageFile		manageFile("Saves/leaderboard");
      std::string		file = manageFile.readFile();
      std::istringstream	iss(file);
      std::string		tmp;

      while (getline(iss, tmp))
	_ranking.push_back(std::stod(tmp));
      writeRanking();
    }
  catch (std::exception const &)
    {
      writeRanking();
    }
}

void				ManageGame::makeEndScore()
{
  std::string		toWrite;
  std::ofstream		stream;

  std::sort(_endScore.begin(), _endScore.end(), std::less<double>());

  for (int idx = 0; idx < 3; ++idx)
    toWrite += std::to_string(_endScore.at(idx)) + "\n";

  stream.open("Saves/endgame");
  stream << toWrite;
  stream.close();
}
