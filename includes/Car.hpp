//
// Car.hpp for  in /home/Kilian/Rendu/C++/Indie_studio
// 
// Made by Lebrun Kilian
// Login   <kilian.lebrun@epitech.eu>
// 
// Started on  Tue May 23 09:38:23 2017 Lebrun Kilian
// Last update Tue May 23 13:56:04 2017 DaZe
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
  void                            accelerate();
  void                            deccelerate();
  void                            slowDown();
  void                            move();
  float				  getAbsoluteAngle();
  void                            turnLeft();
  void                            turnRight();
  void                            launchPowerUp();
  void                            setPosMap(std::pair<int, int> pos);
  float                           getAngle();
  const std::pair<float, float>&  getDir() const;
  const std::pair<float, float>&  getPos() const;
  const std::pair<int, int>&      getPosMap() const;
};
