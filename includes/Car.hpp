//
// Car.hpp for  in /home/Kilian/Rendu/C++/Indie_studio
// 
// Made by Lebrun Kilian
// Login   <kilian.lebrun@epitech.eu>
// 
// Started on  Tue May 23 09:38:23 2017 Lebrun Kilian
// Last update Thu May 25 17:55:04 2017 DaZe
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
  std::array<Element::EType, 8> _arrouding;
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
    RIGHT,
    NONE
    };
  EDirection                edir;
  EDirection                exactdir;
  Car();
  Car(std::pair<int, int> posMap);
  ~Car() {}
  
  void					accelerate();
  void					deccelerate();
  void				        slowDown();
  void					move();
  float					getAbsoluteAngle();
  void					turnLeft();
  void					turnRight();
  void					launchPowerUp();
  void					setPosMap(std::pair<int, int> const& pos);
  float					getAngle();
  float					getSpeed() const;
  std::pair<float, float> const&	getDir() const;
  std::pair<float, float> const&	getPos() const;
  std::pair<int, int> const&		getPosMap() const;
  std::pair<int, int> const&		getPrevPos() const;
  bool					checkArrounding();
 
  void					setArrounding(const std::array<Element::EType, 8> &arrounding);
 };
