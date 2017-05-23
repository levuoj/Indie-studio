//
// Car.hpp for  in /home/Kilian/Rendu/C++/Indie_studio
// 
// Made by Lebrun Kilian
// Login   <kilian.lebrun@epitech.eu>
// 
// Started on  Tue May 23 09:38:23 2017 Lebrun Kilian
// Last update Tue May 23 09:38:24 2017 Lebrun Kilian
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
  Car() : _posMap(0.0f, 0.0f), _pos(50.0f, 50.0f), _speed(0.0f), _dir(1.0f, 0.0f), _angle(0.0f) {std::cout << "sexe" << std::endl;};
  Car(std::pair<int, int> posMap) : _posMap(posMap), _pos(50.0f, 50.0f), _speed(0.0f), _dir(1.0f, 0.0f), _angle(0.0f) {};
  ~Car() {}
  void                            accelerate();
  void                            deccelerate();
  void                            slowDown();
  void                            move();
  float					getAbsoluteAngle();
  void                            turnLeft();
  void                            turnRight();
  void                            launchPowerUp()
  {
    std::cout << "BOUYAAAAAAA" << std::endl;
  }
  void                            setPosMap(std::pair<int, int> pos)
  {
    this->_posMap = pos;
  }
  float                           getAngle()
  {
    return (this->_angle);
  }
  const std::pair<float, float>   getDir() const
  {
    return (this->_dir);
  }
  const std::pair<float, float>   getPos() const
  {
    return (this->_pos);
  };
  const std::pair<int, int>       getPosMap() const
  {
    return (this->_posMap);
  };
};
