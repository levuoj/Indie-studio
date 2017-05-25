//
// ManageGame.hpp for ManageGame.hpp in /home/tvigier/Indie_studio/includes
// 
// Made by thomas vigier
// Login   <thomas.vigier@epitech.eu>
// 
// Started on  Tue May  9 11:24:19 2017 thomas vigier
// Last update Wed May 24 09:47:42 2017 DaZe
//

#pragma once

#include <vector>
#include <string>
#include <Keycodes.h>
#include "ManageFile.hpp"
#include "Observable.hpp"
#include "AI.hpp"
#include "Player.hpp"

class	ManageGame : public Observable
{
private:
  std::vector<std::shared_ptr<Element>>	_map;
  std::vector<AI>   		_AIs;
  std::vector<Player>		_players;
public:
  ManageGame(int, const std::vector<std::array<irr::EKEY_CODE, 5>> &);
  ManageGame() = default;
  ~ManageGame() = default;

  void				controlDriver(const irr::EKEY_CODE &);
  GameElement*	                ElementFromChar(char);
  void	        	        loadMap();
  void				updateMap();
  std::vector<std::shared_ptr<Element>> const&	getMap() const;
  void				printMap();
};
