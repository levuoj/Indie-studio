//
// ManageGame.hpp for ManageGame.hpp in /home/tvigier/Indie_studio/includes
//
// Made by thomas vigier
// Login   <thomas.vigier@epitech.eu>
//
// Started on  Tue May  9 11:24:19 2017 thomas vigier
// Last update Fri Jun  2 18:10:04 2017 DaZe
//

#pragma once

#include <vector>
#include <string>
#include <Keycodes.h>
#include "ManageFile.hpp"
#include "Observable.hpp"
#include "Chrono.hpp"
#include "AI.hpp"
#include "Player.hpp"
#include "Utils.hpp"

class	ManageGame : public Observable
{
  static const int		_col;
private:
  std::vector<AI>		_AIs;
  std::vector<Player>		_players;
  std::array<int, 6>		_finishLine;
  bool				_victory;
  Chrono			_chrono;
public:
  ManageGame(int, const std::vector<std::array<irr::EKEY_CODE, 5>> &);
  ManageGame() = default;
  ~ManageGame() = default;

  void				initPlayerAndIa(int, int, int &, const Element::EType &);
  DType				transferKey(const irr::EKEY_CODE &);
  GameElement			*ElementFromChar(char);
  void				loadMap();
  void				updateMap();
  void				printMap();
  void				checkVictory(std::shared_ptr<Car>);
  Chrono const&			getChrono() const;
};
