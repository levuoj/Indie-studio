//
// ManageGame.cpp for ManageGame.cpp in /home/tvigier/Indie_studio/sources
//
// Made by thomas vigier
// Login   <thomas.vigier@epitech.eu>
//
// Started on  Tue May  9 17:32:16 2017 thomas vigier
// Last update Mon Jun  5 15:45:23 2017 Lebrun Kilian
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

ManageGame::ManageGame(int nbPlayers, const std::vector<std::array<irr::EKEY_CODE, 5>> & keys)
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
}

DType			ManageGame::transferKey(const irr::EKEY_CODE &key)
{
  std::array<Element::EType, 8>   arr;
  int a = Convert::coordToPos<int>(this->_players.at(0).getPosMap());
  arr[0] = this->_map[a - 61]->getType();
  arr[1] = this->_map[a - 60]->getType();
  arr[2] = this->_map[a - 59]->getType();
  arr[3] = this->_map[a + 1]->getType();
  arr[4] = this->_map[a + 61]->getType();
  arr[5] = this->_map[a + 60]->getType();
  arr[6] = this->_map[a + 59]->getType();
  arr[7] = this->_map[a - 1]->getType();
  this->_players.at(0).setArroundingCar(arr);
  this->_players.at(0).driver(key);
  updateMap();
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

void				ManageGame::updateMap()
{
  _AIs.at(0).chooseAction();
  _AIs.at(1).chooseAction();
  _AIs.at(2).chooseAction();
  _map.at(Convert::coordToPos<int>(_AIs.at(0).getCar()->getPosMap())) = _AIs.at(0).getCar();
  _map.at(Convert::coordToPos<int>(_AIs.at(1).getCar()->getPosMap())) = _AIs.at(1).getCar();
  _map.at(Convert::coordToPos<int>(_AIs.at(2).getCar()->getPosMap())) = _AIs.at(2).getCar();
  _map.at(Convert::coordToPos<int>(_players.at(0).getCar()->getPosMap())) = _players.at(0).getCar();
  if (_AIs.at(0).getCar()->getPrevPos() != _AIs.at(0).getCar()->getPosMap())
    _map.at(Convert::coordToPos<int>(_AIs.at(0).getCar()->getPrevPos())) =
      std::shared_ptr<Element>(new Element(" ", Element::EType::ROAD));
  
  if (_AIs.at(1).getCar()->getPrevPos() != _AIs.at(1).getCar()->getPosMap())
    _map.at(Convert::coordToPos<int>(_AIs.at(1).getCar()->getPrevPos())) =
      std::shared_ptr<Element>(new Element(" ", Element::EType::ROAD));
  
  if (_AIs.at(2).getCar()->getPrevPos() != _AIs.at(2).getCar()->getPosMap())
    _map.at(Convert::coordToPos<int>(_AIs.at(2).getCar()->getPrevPos())) =
      std::shared_ptr<Element>(new Element(" ", Element::EType::ROAD));
  
  if (_players.at(0).getCar()->getPrevPos() != _players.at(0).getCar()->getPosMap())
    _map.at(Convert::coordToPos<int>(_players.at(0).getCar()->getPrevPos())) = 
      std::shared_ptr<Element>(new Element(" ", Element::EType::ROAD));
  printMap();
}

void                        ManageGame::printMap()
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
  std::cout << std::endl;
}
