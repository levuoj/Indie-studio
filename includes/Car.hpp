//
// Car.hpp for  in /home/Kilian/Rendu/C++/Indie_studio
// 
// Made by Lebrun Kilian
// Login   <kilian.lebrun@epitech.eu>
// 
// Started on  Tue May 23 09:38:23 2017 Lebrun Kilian
// Last update Wed May 24 10:17:30 2017 Lebrun Kilian
//

#pragma once

#include <utility>
#include <array>
#include "GameElement.hpp"
#include "PowerUp.hpp"

class Car : public GameElement
{
  static const float		_maxSpeed;
  static const float		_fps;
  static const float		_inertia;

  enum  EDirection
    {
      UP,
      DOWN,
      LEFT,
      RIGHT
    };

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
  EDirection                _edir;
  PowerUp				_pu;
  EState				_state;
  std::array<Element::EType, 8> _arrouding;
public:
  Car();
  Car(std::pair<int, int> posMap);
  ~Car() {}
  void                            accelerate();
  void                            deccelerate();
  void                            slowDown();
  void                            move();
  float				                    getAbsoluteAngle();
  void                            turnLeft();
  void                            turnRight();
  void                            launchPowerUp();
  void                            setPosMap(std::pair<int, int> pos);
  void                            setArrounding(const std::array<Element::EType, 8> &arrounding);
  float                           getAngle();
  const std::pair<float, float>&  getDir() const;
  const std::pair<float, float>&  getPos() const;
  const std::pair<int, int>&      getPosMap() const;
};
