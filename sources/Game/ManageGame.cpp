//
// ManageGame.cpp for ManageGame.cpp in /home/tvigier/Indie_studio/sources
// 
// Made by thomas vigier
// Login   <thomas.vigier@epitech.eu>
// 
// Started on  Tue May  9 17:32:16 2017 thomas vigier
// Last update Tue May 16 18:13:50 2017 Lebrun Kilian
//

#include "test.hpp"
#include "ManageGame.hpp"

#define COL 50;

ManageGame::ManageGame(int nbPlayers, const std::vector<std::array<irr::EKEY_CODE, 5>> &keys)
{
  this->loadMap();
  int     pos(0);
  int     x(0);
  int     y(0);
  int     i(0);

  for (const auto &it : this->_map)
   {
     if (it.getType() == Element::EType::CAR)
        {
      	  x = pos % COL;
          y = (pos - x) / COL;
          if (i < nbPlayers )
            {
              this->_players.push_back(Player(std::make_pair(x, y)));
              ++i;
      	    }
//          else
//            this->_AIs.push_back(AI(std::make_pair(x, y)));
        }
      pos++;
    }

  unsigned long int index = 0;

  for (auto &it : this->_players)
    {
      it.setKeys(keys.at(index));
      ++i;
    }
}

void                    ManageGame::controlDriver(const irr::EKEY_CODE &key)
{
  this->_players.at(0).driver(key);
}

GameElement             ManageGame::ElementFromChar(const char c)
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
      default:
        path = "";
        type = Element::EType::DEFAULT;
    }
  GameElement gameElement(path, type, pos);
  return (gameElement);
}

void				ManageGame::loadMap()
{
  ManageFile      file("./assets/circuit/circuit1.txt");
  std::string     map;

  map = file.readFile();

  for (const auto &c : map)
    {
      if (c != '\n')
        this->_map.push_back(ElementFromChar(c));
    }
}

std::vector<Element> const&	ManageGame::getMap() const
{
  return (this->_map);
}

void                        ManageGame::printMap()
{
  for (const auto &it : this->_map)
    std::cout << it.getPath() << std::endl;
}