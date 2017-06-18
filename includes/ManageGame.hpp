//
// ManageGame.hpp for ManageGame.hpp in /home/tvigier/Indie_studio/includes
//
// Made by thomas vigier
// Login   <thomas.vigier@epitech.eu>
//
// Started on  Tue May  9 11:24:19 2017 thomas vigier
// Last update Sun Jun 18 19:52:35 2017 Lebrun Kilian
//

#pragma once

#include <algorithm>
#include <string>
#include "ManageFile.hpp"
#include "Observable.hpp"
#include "AI.hpp"
#include "Player.hpp"
#include "Utils.hpp"
#include "Music.hpp"

class	ManageGame : public Observable
{
  static const int		_col;
private:
  std::vector<AI>		_AIs;
  std::vector<Player>		_players;
  std::array<int, 6>		_finishLine;
  std::array<int, 4>		_tieSound;
  bool				_victory;
  short int			_nbFinish;
  std::vector<double>		_ranking;
  Chrono			_startChrono;
  Chrono			_powerUp;
  std::vector<double>		_endScore;
  Music				*_music;

public:
  ManageGame(int, const std::vector<std::vector<irr::EKEY_CODE>> &, Music *);
  ManageGame(std::string const &, const std::vector<std::vector<irr::EKEY_CODE>> &, Music *);
  ManageGame() = default;
  ~ManageGame() = default;

  void					initPlayerAndIa(int, int, int &, const Element::EType &);
  void					construct(int);
  DType					transferKey(EventReceiver const&);
  const std::array<Element::EType, 8>	arrounding(int) const;
  GameElement				*ElementFromChar(char) const;
  GameElement				*ElementFromCharCar(char) const;
  void					loadMap(std::string const &);
  void					updateMap();
  void					checkVictory(std::shared_ptr<Car> const&);
  Chrono const&				getChrono() const;
  bool					loadSave(std::string const &);
  bool					loadFile(std::string const &);
  bool					loadLine(std::string const &);
  bool					checkType(const std::vector<std::string> &);
  bool					checkPosMap(const std::string &) const;
  bool					checkCarType(const std::string &) const;
  bool					checkAngle(const std::string &) const;
  bool					checkLap(const std::string &) const;
  bool					checkCheckpoint(const std::string &) const;
  bool					checkDir(const std::string &) const;
  bool					checkIdx(const std::string &) const;
  bool					checkChrono(const std::string &) const;
  bool					getStarted() const;
  void					determineCarPath(const std::shared_ptr<Car> &);
  void					makeSave(int) const;
  void					makeRanking();
  void					makeEndScore();
  void					writeRanking();
};
