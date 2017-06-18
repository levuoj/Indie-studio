//
// ManageGame.hpp for ManageGame.hpp in /home/tvigier/Indie_studio/includes
//
// Made by thomas vigier
// Login   <thomas.vigier@epitech.eu>
//
// Started on  Tue May  9 11:24:19 2017 thomas vigier
// Last update Sun Jun 18 15:44:16 2017 DaZe
//

#pragma once

#include <vector>
#include <algorithm>
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
  std::array<int, 6>		_tieSound;
  bool				_victory;
  short int			_nbFinish;
  std::vector<double>		_ranking;
  Chrono			_startChrono;
  std::vector<double>		_endScore;

public:
  ManageGame(int, const std::vector<std::vector<irr::EKEY_CODE>> &);
  ManageGame(std::string const &, const std::vector<std::vector<irr::EKEY_CODE>> &);
  ManageGame() = default;
  ~ManageGame() = default;

  void					initPlayerAndIa(int, int, int &, const Element::EType &);
  void					construct(int);
  DType					transferKey(EventReceiver const&);
  const std::array<Element::EType, 8>	arrounding(int);
  GameElement				*ElementFromChar(char);
  GameElement				*ElementFromCharCar(char);
  void					loadMap(std::string const &);
  void					updateMap();
  void					printMap();
  void					checkVictory(std::shared_ptr<Car> const&);
  Chrono const&				getChrono() const;
  bool					loadSave(std::string const &);
  bool					loadFile(std::string const &);
  bool					loadLine(std::string const &);
  bool					checkType(const std::vector<std::string> &);
  bool					checkPosMap(const std::string &);
  bool					checkCarType(const std::string &);
  bool					checkAngle(const std::string &);
  bool					checkLap(const std::string &);
  bool					checkCheckpoint(const std::string &);
  bool					checkDir(const std::string &);
  bool					checkIdx(const std::string &);
  bool					checkChrono(const std::string &);
  bool					getStarted() const;
  void					determineCarPath(std::shared_ptr<Car>);
  void					makeSave(int);
  void					makeRanking();
  void					makeEndScore();
  void					writeRanking();
};
