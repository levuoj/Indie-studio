//
// Car.hpp for  in /home/Kilian/Rendu/C++/Indie_studio
//
// Made by Lebrun Kilian
// Login   <kilian.lebrun@epitech.eu>
//
// Started on  Tue May 23 09:38:23 2017 Lebrun Kilian
// Last update Fri Jun  2 13:27:45 2017 DaZe
//

#pragma once

#include <utility>
#include <array>
#include "GameElement.hpp"
#include "PowerUp.hpp"

class Car : public GameElement
{
public:
  static const float		_maxSpeed;
  static const float		_fps;
  static const float		_inertia;
  static const float		_pi;

private:
  enum  EState
    {
      NORMAL,
      BANANA,
      WALL,
      SHOOT
    };
  std::pair<int, int>			_posMap;
  float					_speed;
  std::pair<float, float>		_dir;
  float					_angle;
  PowerUp				_pu;
  EState				_state;
  std::pair<int, int>			_prevPos;
  std::array<Element::EType, 8>		_arrounding;
  short int				_lap;
  bool					_isFinished;
public:
  enum  EDirection
    {
      UP,
      UP_RIGHT,
      UP_LEFT,
      DOWN,
      DOWN_LEFT,
      DOWN_RIGHT,
      LEFT,
      RIGHT
    };
  EDirection                edir;
  Car() = default;
  Car(std::pair<int, int> posMap, const Element::EType type);
  ~Car() {}

  void					accelerate();
  void					deccelerate();
  void					slowDown();
  void					move();
  void					turnLeft();
  void					turnRight();
  void					launchPowerUp();
  void					setPosMap(std::pair<int, int> const& pos);
  void					setLap(const short int);
  void					setSpeed(const float);
  void					setFinished(bool);
  bool					getFinished() const;
  float					getAbsoluteAngle() const;
  float					getAngle() const;
  float					getSpeed() const;
  short int				getLap() const;
  void					incLap();
  void					stop();

  std::pair<int, int> const &		getPrevPos() const;
  std::pair<float, float> const&	getDir() const;
  std::pair<float, float> const&	getPos() const;
  std::pair<int, int> const&		getPosMap() const;

  bool					checkArrounding();
  void					setArrounding(const std::array<Element::EType, 8> &arrounding);
};
