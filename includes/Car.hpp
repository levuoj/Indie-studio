//
// Car.hpp for  in /home/Kilian/Rendu/C++/Indie_studio
//
// Made by Lebrun Kilian
// Login   <kilian.lebrun@epitech.eu>
//
// Started on  Tue May 23 09:38:23 2017 Lebrun Kilian
// Last update Sun Jun 18 17:32:55 2017 Lebrun Kilian
//

#pragma once

#include <utility>
#include <array>
#include "GameElement.hpp"
#include "PowerUp.hpp"
#include "Chrono.hpp"

class Car : public GameElement
{
public:
  static const float		_fps;
  static const float		_pi;

  enum	EState
    {
      FAST,
      SLOW,
      OIL,
      NONE
    };

  enum  EDirection
    {
      UP_LEFT,
      UP,
      UP_RIGHT,
      RIGHT,
      DOWN_RIGHT,
      DOWN,
      DOWN_LEFT,
      LEFT
    };

private:
  std::pair<int, int>			_posMap;
  float					_speed;
  std::pair<float, float>		_dir;
  float					_angle;
  PowerUp				_pu;
  std::pair<int, int>			_prevPos;
  std::array<Element::EType, 8>		_arrounding;
  short int				_lap;
  bool					_isFinished;
  EDirection				_edir;
  bool					_isStopped;
  bool					_isRank;
  float					_maxSpeed;
  float					_inertia;
  Chrono				_powerchrono;
  EState				_state;
  float					_speedSave;

public:

  Car() = default;
  Car(std::pair<int, int> posMap, const Element::EType type, float angle, short int lap, bool isFinished, EDirection dir);
  Car(std::pair<int, int> posMap, const Element::EType type);
  ~Car() {}

  void					accelerate();
  void					deccelerate();
  void					slowDown();
  void					move();
  void					turnLeft();
  void					turnRight();
  void					launchPowerUp();
  void					Power();
  void					managePowerUp();
  void					setPosMap(std::pair<int, int> const& pos);
  void					setLap(const short int);
  void					setSpeed(const float);
  void					setFinished(bool);
  void					setStop(const bool);
  void					setIsRank(const bool);
  bool					getStop() const;
  bool					getFinished() const;
  bool					getIsRank() const;
  float					getAbsoluteAngle() const;
  float					getAngle() const;
  float					getSpeed() const;
  float					getMaxSpeed() const;
  short int				getLap() const;
  Car::EDirection			getEDir() const;
  void					incLap();
  void					stop();

  std::pair<int, int> const &		getPrevPos() const;
  std::pair<float, float> const&	getDir() const;
  std::pair<float, float> const&	getPos() const;
  std::pair<int, int> const&		getPosMap() const;

  Element::EType			checkArrounding() const;
  Element::EType			checkBackArrounding() const;
  void					setArrounding(const std::array<Element::EType, 8> &arrounding);
  void					setEdir(const EDirection &);
};
