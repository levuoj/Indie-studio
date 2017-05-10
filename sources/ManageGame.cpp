//
// ManageGame.cpp for ManageGame.cpp in /home/tvigier/Indie_studio/sources
// 
// Made by thomas vigier
// Login   <thomas.vigier@epitech.eu>
// 
// Started on  Tue May  9 17:32:16 2017 thomas vigier
// Last update Wed May 10 10:37:05 2017 thomas vigier
//

#include "ManageGame.hpp"
#include "ManageFile.hpp"

ManageGame::ManageGame(int nbPlayers, std::vector<std::array<EKey, 5>> keys)
{
  for (int i = 0; i < 4 - nbPlayers; ++i)
    _AIs.push_back(AI());
  for (int i = 0; i < nbPlayers; ++i)
    _players.push_back(Player());

  int i = 0;
  for (auto it : _players)
    {
      it.setKeys(keys.at(i));
      ++i;
    }
}

std::vector<Element> const&	ManageGame::getMap() const
{
  return (_map);
}

void				ManageGame::loadMap(std::string const &)
{
  ManageFile			file("map.txt");
  file.readFile();
}
