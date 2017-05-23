//
// Created by Kilian on 09/05/17.
//

#pragma once

#include <utility>
#include "GameElement.hpp"
#include "PowerUp.hpp"

class Car : public GameElement
{
  static const float		_maxSpeed;
  static const float		_fps;
  static const float		_inertia;

    enum EState
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
public:
  Car();
  Car(std::pair<int, int> posMap);
  ~Car() {}
  void					accelerate();
  void					deccelerate();
  void					move();
  void					turnLeft();
  void					turnRight();
  float					getAbsoluteAngle();
  float					getAngle()
  {
    return (this->_angle);
  }
  const std::pair<float, float>		getDir() const
  {
    return (this->_dir);
  }
  const std::pair<float, float>		getPos() const
  {
    return (this->_pos);
  };
  const std::pair<int, int>		getPosMap() const
  {
    return (this->_posMap);
  };
};
