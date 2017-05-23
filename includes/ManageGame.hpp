//
// ManageGame.hpp for ManageGame.hpp in /home/tvigier/Indie_studio/includes
// 
// Made by thomas vigier
// Login   <thomas.vigier@epitech.eu>
// 
// Started on  Tue May  9 11:24:19 2017 thomas vigier
// Last update Sat May 13 13:59:01 2017 thomas vigier
//

#pragma once

#include <vector>
#include <string>
#include "ManageFile.hpp"
#include "Observable.hpp"
#include "AI.hpp"
#include "Player.hpp"

class	ManageGame : public Observable
{
  std::vector<Element>		_map;
  std::vector<AI>   		_AIs;
  std::vector<Player>		_players;
public:
  ManageGame();//int, std::vector<std::array<EKey, 5>>);
  ~ManageGame() {};

  GameElement                   ElementFromChar(char c);
  void			        loadMap();
  void				updateMap();
  std::vector<Element> const&	getMap() const;
  void                          printMap();
};
