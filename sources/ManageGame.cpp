//
// ManageGame.cpp for ManageGame.cpp in /home/tvigier/Indie_studio/sources
// 
// Made by thomas vigier
// Login   <thomas.vigier@epitech.eu>
// 
// Started on  Tue May  9 17:32:16 2017 thomas vigier
// Last update Tue May  9 17:47:21 2017 thomas vigier
//

#include "ManageGame.hpp"
#include "ManageFile.hpp"

ManageGame::ManageGame(int nbPlayers, std::vector<std::array<EKey>> keys)
{
  for (int i = 0; i < 4 - nbPlayers; ++i)
    _AIs.push_back(AI());
  for (int i = 0; i < nbPlayers; ++i)
    _players.push_back(Player());

  for (int i = 0; auto it : _players(); ++i)
    it.setKeys(keys.at(i));
}

std::vector<Element> const&	getMap() const
{
  return (_map);
}

void				loadMap(std::string const &)
{
  ManageFile			file("map.txt");
  file.readFile();
}
