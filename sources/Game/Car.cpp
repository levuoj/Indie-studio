//
// Car.cpp for  in /home/Kilian/Rendu/C++/Indie_studio/sources
// 
// Made by Lebrun Kilian
// Login   <kilian.lebrun@epitech.eu>
// 
// Started on  Sat May 13 12:00:41 2017 Lebrun Kilian
// Last update Fri May 26 10:35:13 2017 Lebrun Kilian
//

#define _USE_MATH_DEFINES

#include <cmath>
#include "Car.hpp"

const float Car::_maxSpeed = 8;
const float Car::_fps = 60;
const float Car::_inertia = Car::_maxSpeed / Car::_fps;

Car::Car() : _speed(0.0f), _dir(1.0f, 0.0f), _angle(0.0f), edir(EDirection::RIGHT)
{
  _path = ">";
  _pos = std::make_pair(50.0f, 50.0f);
  _type = Element::EType::CAR;
}

Car::Car(std::pair<int, int> posMap) : _posMap(posMap), _speed(0.0f), _dir(1.0f, 0.0f), _angle(0.0f), edir(EDirection::RIGHT)
{
  _path = ">";
  _pos = std::make_pair(50.0f, 50.0f);
  _type = Element::EType::CAR;
}

bool            Car::checkArrounding()
{
  switch (this->edir)
    {
    case EDirection::RIGHT:
      if (this->_arrouding.at(3) == Element::EType::BLOCK)
        return (false);
      break;
    case EDirection::LEFT:
      if (this->_arrouding.at(7) == Element::EType::BLOCK)
        return (false);
      break;
    case EDirection::UP:
      if (this->_arrouding.at(1) == Element::EType::BLOCK)
        return (false);
    case EDirection::UP_LEFT:
      if (this->_arrouding.at(0) == Element::EType::BLOCK)
	return (false);
      break;
    case EDirection::UP_RIGHT:
      if (this->_arrouding.at(2) == Element::EType::BLOCK)
	return (false);
      break;
    case EDirection::DOWN:
      if (this->_arrouding.at(5) == Element::EType::BLOCK)
	return (false);
    case EDirection::DOWN_RIGHT:
      if (this->_arrouding.at(4) == Element::EType::BLOCK)
	return (false);
      break;
    case EDirection::DOWN_LEFT:
      if (this->_arrouding.at(6) == Element::EType::BLOCK)
	return (false);
      break;
    default:
      break;
    }
  return (true);
}

void            Car::accelerate()
{
  std::cout << "En avant toute !!!" << std::endl;
  if (checkArrounding() == false)
    {
      this->_speed = 0.0f;
      return;
    }
  if (this->_speed <= this->_maxSpeed)
    this->_speed += this->_inertia;
}

void            Car::deccelerate()
{
  std::cout << "J'enlève les voiles, Capitaine" << std::endl;
  if (checkArrounding() == false)
    {
      this->_speed = 0.0f;
      return;
    }
  if (this->_speed >= -this->_maxSpeed / 2)
    this->_speed -= this->_inertia;
}

void            Car::slowDown()
{
  std::cout << "J'enlève les voiles de moitié, Capitaine" << std::endl;
  if (checkArrounding() == false)
    {
      this->_speed = 0.0f;
      return;
    }
  if (this->_speed > 0)
    this->_speed -= this->_inertia / 2;
}

void            Car::move()
{
  std::cout << _pos.first << " --- " << _pos.second << std::endl;
  this->_pos.first = this->_pos.first + (this->_speed / this->_fps) * this->_dir.first;
  if (this->_pos.first > 100)
    {
      this->_prevPos.first = this->_posMap.first;
      this->_posMap.first += 1;
      this->_pos.first -= 100.0f;
    }
  else if (this->_pos.first < 0)
    {
      this->_prevPos.first = this->_posMap.first;
      this->_posMap.first -= 1;
      this->_pos.first += 100.0f;
    }
  this->_pos.second = this->_pos.second + (this->_speed / this->_fps) * this->_dir.second * -1;
  if (this->_pos.second > 100)
    {
      this->_prevPos.second = this->_posMap.second;
      this->_posMap.second += 1;
      this->_pos.second -= 100.0f;
    }
  else if (this->_pos.second < 0)
    {
      this->_prevPos.second = this->_posMap.second;
      this->_posMap.second -= 1;
      this->_pos.second += 100.0f;
    }
}

void            Car::turnLeft()
{
  std::cout << "A BABOOOOOOORD" << std::endl;
  if (checkArrounding() == false)
    {
      this->_speed = 0.0f;
      return;
    }
  if (this->_angle >= 360)
    this->_angle = 0.0f;
  this->_angle += 2.0f;

  this->_dir.first = cosf(this->_angle * M_PI / 180.0f);
  this->_dir.second = sinf(this->_angle * M_PI / 180.0f);
   
  std::cout << _dir.first << " --- " << _dir.second << std::endl;
}

void            Car::turnRight()
{
  std::cout << "A TRIBOOOOOOORD" << std::endl;
  if (checkArrounding() == false)
    {
      this->_speed = 0.0f;
      return;
    }
  if (this->_angle <= -360)
    this->_angle = 0.0f;
  this->_angle -= 2.0f;

  this->_dir.first = cosf(this->_angle * M_PI / 180.0f);
  this->_dir.second = sinf(this->_angle * M_PI / 180.0f);

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

void                            Car::setPosMap(const std::pair<int, int> & pos)
{
  std::cout << pos.first << " --- " << pos.second << std::endl;
  this->_posMap = pos;
}

float                           Car::getAngle()
{
  return (this->_angle);
}

std::pair<float, float> const   &Car::getDir() const
{
  return (this->_dir);
}

std::pair<float, float> const   &Car::getPos() const
{
  return (this->_pos);
};

std::pair<int, int> const       &Car::getPosMap() const
{
  return (this->_posMap);
};

std::pair<int, int> const       &Car::getPrevPos() const
{
  return (this->_prevPos);
};

float				Car::getSpeed() const
{
  return (this->_speed);
}
