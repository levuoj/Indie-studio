//
// ManageGame.cpp for ManageGame.cpp in /home/tvigier/Indie_studio/sources
//
// Made by thomas vigier
// Login   <thomas.vigier@epitech.eu>
//
// Started on  Tue May  9 17:32:16 2017 thomas vigier
// Last update Sat Jun  3 16:34:53 2017 DaZe
//

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

ManageGame::ManageGame(int nbPlayers, const std::vector<std::array<irr::EKEY_CODE, 5>> & keys) : _victory(false)
{
  int     pos(0);
  int     i(0);

  this->_type = DType::GAME;
  this->loadMap();

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

  i = 0;

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

DType			ManageGame::transferKey(const irr::EKEY_CODE &key)
{
  // std::array<Element::EType, 8>   arr;
  // int a = Convert::coordToPos<int>(this->_players.at(0).getPosMap());
  // arr[0] = this->_map[a - 51].get()->getType();
  // arr[1] = this->_map[a - 50].get()->getType();
  // arr[2] = this->_map[a - 49].get()->getType();
  // arr[3] = this->_map[a + 1].get()->getType();
  // arr[4] = this->_map[a + 51].get()->getType();
  // arr[5] = this->_map[a + 50].get()->getType();
  // arr[6] = this->_map[a + 49].get()->getType();
  // arr[7] = this->_map[a - 1].get()->getType();
  // this->_players.at(0).setArroundingCar(arr);
  _chrono.incTime();

  if (!_victory)
    {
      for (auto &it : _players)
	it.driver(key);
      updateMap();
    }
  else
    {
      _chrono.stop();
      std::cout << "CHRONO FINAL = " << _chrono.getTime() << std::endl;
      makeSave();
      // return DType::VICTORY
    }
  // std::cout << "LA KEYYYYY EST EGALE A = " << key << std::endl;

  return (DType::GAME);
}

GameElement			*ManageGame::ElementFromChar(const char c)
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
    case '>':
      path = "./assets/Anakin_podracer/AnakinsPodRacer.obj";
      type = Element::EType::POD1;
      break;
    case 'p':
      path = "./assets/Anakin_podracer/AnakinsPodRacer.obj";
      type = Element::EType::POD2;
      break;
    case 's':
      path = "./assets/Anakin_podracer/AnakinsPodRacer.obj";
      type = Element::EType::POD3;
      break;
    case 'g':
      path = "./assets/Anakin_podracer/AnakinsPodRacer.obj";
      type = Element::EType::POD4;
      break;
    case '-':
      path = "-";
      type = Element::EType::LINE;
      break;
    default:
      path = "";
      type = Element::EType::DEFAULT;
    }
  return (new GameElement(path, type, pos));
}

void				ManageGame::loadMap()
{
  ManageFile      file("./assets/circuit/newCircuit.txt");
  std::string     map;

  map = file.readFile();

  for (const auto &c : map)
    {
      if (c != '\n')
	this->_map.push_back(std::shared_ptr<Element>(ElementFromChar(c)));
    }
}

void				ManageGame::checkVictory(std::shared_ptr<Car> car)
{
  std::cout << "LAP = " << car->getLap() << std::endl;
  for (const auto &it : _finishLine)
    if (it + 480 == Convert::coordToPos<int>(car->getPosMap()))
      {
	car->setFinished(false);
	std::cout << "CheckPoint" << std::endl;
	break ;
      }
  for (const auto &it : _finishLine)
    if (it == Convert::coordToPos<int>(car->getPosMap()) && car->getFinished() == false)
      {
	car->incLap();
	car->setFinished(true);
	std::cout << "INC LAP" << std::endl;
	break ;
      }
  if (car->getLap() == 3)
    {
      car->stop();
      _victory = true;
    }
}

void				ManageGame::updateMap()
{
  for (auto &it : _AIs)
    {
      it.chooseAction();
      
      _map.at(Convert::coordToPos<int>(it.getCar()->getPosMap())) = it.getCar();

      checkVictory(it.getCar());
      if (it.getCar()->getPrevPos() != it.getCar()->getPosMap())
	_map.at(Convert::coordToPos<int>(it.getCar()->getPrevPos())) =
	  std::shared_ptr<Element>(new Element(" ", Element::EType::ROAD));
    }
  
  for (auto &it : _players)
    {
      _map.at(Convert::coordToPos<int>(it.getCar()->getPosMap())) = it.getCar();

      checkVictory(it.getCar());
      if (it.getCar()->getPrevPos() != it.getCar()->getPosMap())
	_map.at(Convert::coordToPos<int>(it.getCar()->getPrevPos())) =
	  std::shared_ptr<Element>(new Element(" ", Element::EType::ROAD));
    }
  printMap();
}

Chrono const&			ManageGame::getChrono() const
{
  return (_chrono);
}

void				ManageGame::printMap()
{
  int	i = 0;
  for (auto it = this->_map.begin(); it != _map.end(); ++it)
    {
      if (i % 60 == 0)
	std::cout << std::endl;
      switch (it->get()->getType())
	{
	case Element::EType::BLOCK:
	  std::cout << "X";
	  break;
	case Element::EType::ROAD:
	  std::cout << " ";
	  break;
	case Element::EType::ENDLINE:
	  std::cout << "o";
	  break;
	case Element::EType::POD1:
	  std::cout << ">";
	  break;
	case Element::EType::POD2:
	  std::cout << ">";
	  break;
	case Element::EType::POD3:
	  std::cout << ">";
	  break;
	case Element::EType::POD4:
	  std::cout << ">";
	  break;
	case Element::EType::LINE:
	  std::cout << "-";
	  break;
	default:
	  std::cout << "";
	  break;
	}
      ++i;
    }
}

void				ManageGame::loadSave()
{
  
}

void				ManageGame::makeSave()
{
  std::string			str;
  for (auto &it : _players)
    {
      str += "PLAYER ";
      str += it.getCar()->getPosMap().first + " ";
      str += it.getCar()->getPosMap().second + " ";
      str += it.getCar()->getType() + " ";
      str += std::to_string(it.getCar()->getAbsoluteAngle()) + " ";
      str += it.getCar()->getLap() + " ";
      str += it.getCar()->getFinished() + " \n";
    }
  for (auto &it : _AIs)
    {
      str += "AI ";
      str += it.getCar()->getPosMap().first + " ";
      str += it.getCar()->getPosMap().second + " ";
      str += it.getCar()->getType() + " ";
      str += std::to_string(it.getCar()->getAbsoluteAngle()) + " ";
      str += it.getCar()->getLap() + " ";
      str += it.getCar()->getFinished() + " \n";
    }
  str += _chrono.getTime();
  str += "\n";

  ManageFile			file("Save1");

  file.writeFile(str);
}
