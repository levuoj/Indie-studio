//
// Car.cpp for  in /home/Kilian/Rendu/C++/Indie_studio/sources
// 
// Made by Lebrun Kilian
// Login   <kilian.lebrun@epitech.eu>
// 
// Started on  Sat May 13 12:00:41 2017 Lebrun Kilian
// Last update Tue May 23 18:58:48 2017 DaZe
//

#define _USE_MATH_DEFINES

#include <cmath>
#include "Car.hpp"

const float Car::_maxSpeed = 30;
const float Car::_fps = 60;
const float Car::_inertia = Car::_maxSpeed / Car::_fps;

Car::Car() : _speed(0.0f), _dir(1.0f, 0.0f), _angle(0.0f)
{
  _path = ">";
  _pos = std::make_pair(50.0f, 50.0f);
}

Car::Car(std::pair<int, int> posMap) : _posMap(posMap), _speed(0.0f), _dir(1.0f, 0.0f), _angle(0.0f)
{
  _path = ">";
  _pos = std::make_pair(50.0f, 50.0f);
}

void            Car::accelerate()
{
  std::cout << "En avant toute !!!" << std::endl;
  if (this->_speed <= this->_maxSpeed)
    this->_speed += this->_inertia;
}

void            Car::deccelerate()
{
  std::cout << "J'enlève les voiles, Capitaine" << std::endl;
  if (this->_speed >= -this->_maxSpeed / 2)
    this->_speed -= this->_inertia;
}

void            Car::slowDown()
{
  std::cout << "J'enlève les voiles de moitié, Capitaine" << std::endl;
  if (this->_speed > 0)
    this->_speed -= this->_inertia / 2;
}

void            Car::move()
{
  std::cout << _pos.first << " --- " << _pos.second << std::endl;
  this->_pos.first = this->_pos.first + (this->_speed / this->_fps) * this->_dir.first;
  if (this->_pos.first > 100)
    {
      this->_posMap.first += 1;
      this->_pos.first -= 100.0f;
    }
  else if (this->_pos.first < 0)
    {
      this->_posMap.first -= 1;
      this->_pos.first += 100.0f;
    }
  this->_pos.second = this->_pos.second + (this->_speed / this->_fps) * this->_dir.second * -1;
  if (this->_pos.second > 100)
    {
      this->_posMap.second += 1;
      this->_pos.second -= 100.0f;
    }
  else if (this->_pos.second < 0)
    {
      this->_posMap.second -= 1;
      this->_pos.second += 100.0f;
    }
}

void            Car::turnLeft()
{
  std::cout << "A BABOOOOOOORD" << std::endl;
  if (this->_angle >= 360)
    this->_angle = 0.0f;
  this->_angle += 2.0f;

  this->_dir.first = cos(this->_angle * M_PI / 180.0f);
  this->_dir.second = sin(this->_angle * M_PI / 180.0f);
   
  std::cout << _dir.first << " --- " << _dir.second << std::endl;
}

void            Car::turnRight()
{
  std::cout << "A TRIBOOOOOOORD" << std::endl;
  if (this->_angle <= -360)
    this->_angle = 0.0f;
  this->_angle -= 2.0f;

  this->_dir.first = cos(this->_angle * M_PI / 180.0f);
  this->_dir.second = sin(this->_angle * M_PI / 180.0f);

   std::cout << "TURN RIGHT dir == " << _dir.first << " --- " << _dir.second << std::endl;
}

float		Car::getAbsoluteAngle()
{
  if (_angle < 0.0f)
    return (_angle + 360.0f);
  return (_angle);
}

void                            Car::launchPowerUp()
{
  std::cout << "BOUYAAAAAAA" << std::endl;
}

void                            Car::setPosMap(std::pair<int, int> const& pos)
{
  std::cout << pos.first << " --- " << pos.second << std::endl;
  this->_posMap = pos;
}

float                           Car::getAngle()
{
  return (this->_angle);
}

const std::pair<float, float>   &Car::getDir() const
{
  return (this->_dir);
}

const std::pair<float, float>   &Car::getPos() const
{
  return (this->_pos);
};

const std::pair<int, int>       &Car::getPosMap() const
{
  return (this->_posMap);
};
