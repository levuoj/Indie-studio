//
// ManageGame.hpp for ManageGame.hpp in /home/tvigier/Indie_studio/includes
//
// Made by thomas vigier
// Login   <thomas.vigier@epitech.eu>
//
// Started on  Tue May  9 11:24:19 2017 thomas vigier
// Last update Fri May 26 09:42:42 2017 Pierre Zawadil
//

#pragma once

#include <vector>
#include <string>
#include <Keycodes.h>
#include "ManageFile.hpp"
#include "Observable.hpp"
#include "AI.hpp"
#include "Player.hpp"
#include "Utils.hpp"

class	ManageGame : public Observable
{
private:
  std::vector<AI>		_AIs;
  std::vector<Player>		_players;
public:
  ManageGame(int, const std::vector<std::array<irr::EKEY_CODE, 5>> &);
  ManageGame() = default;
  ~ManageGame() = default;

  DType				transferKey(const irr::EKEY_CODE &);
  // std::unique_ptr<GameElement>			ElementFromChar(char);
  GameElement			*ElementFromChar(char);
  void				loadMap();
  void				updateMap();
  void				printMap();
};
