//
// ManageGame.cpp for ManageGame.cpp in /home/tvigier/Indie_studio/sources
// 
// Made by thomas vigier
// Login   <thomas.vigier@epitech.eu>
// 
// Started on  Tue May  9 17:32:16 2017 thomas vigier
// Last update Mon May 22 16:23:29 2017 DaZe
//

#include <stdio.h>
#include "ManageGame.hpp"
#include "Convert.hpp"

ManageGame::ManageGame()//int nbPlayers, std::vector<std::array<EKey, 5>> keys)
{
/*    for (int i = 0; i < 4 - nbPlayers; ++i)
        _AIs.push_back(AI());
    for (int i = 0; i < nbPlayers; ++i)
        _players.push_back(Player());

    int i = 0;
    for (auto it : _players)
    {
        it.setKeys(keys.at(i));
        ++i;
    }
*/
}

GameElement             ManageGame::ElementFromChar(char c)
{
    std::string             path;
    Element::EType          type;
    std::pair<float, float> pos(50.0, 50.0);

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
	path = ">";
	type = Element::EType::CAR;
	break;
      case '-':
	path = "-";
	type = Element::EType::LINE;
	break;
      default:
	path = "";
	type = Element::EType::DEFAULT;
      }
    return (GameElement(path, type, pos));
}

void				ManageGame::loadMap()
{
    ManageFile      file("./assets/circuit/circuit2.txt");
    std::string     map;

    map = file.readFile();

    for (const auto& c : map)
    {
        if (c != '\n')
            this->_map.push_back(ElementFromChar(c));
    }
    _AIs.push_back(AI(std::make_pair(20, 5)));
    _AIs.at(0).setMap(_map);
}

void				ManageGame::updateMap()
{
  _AIs.at(0).chooseAction();
  _map.at(Convert::coordToPos<int>(_AIs.at(0).getCar().getPosMap())) = _AIs.at(0).getCar();
  printMap();
}

std::vector<Element> const&	ManageGame::getMap() const
{
    return (this->_map);
}

void                        ManageGame::printMap()
{
  int	i = 0;
  for (const auto it : this->_map)
    {
      if (i % 51 == 0)
	std::cout << std::endl;
      std::cout << it.getPath();
      ++i;
    }
}
