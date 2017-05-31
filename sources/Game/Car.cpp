//
// Car.cpp for  in /home/Kilian/Rendu/C++/Indie_studio/sources
//
// Made by Lebrun Kilian
// Login   <kilian.lebrun@epitech.eu>
//
// Started on  Sat May 13 12:00:41 2017 Lebrun Kilian
// Last update Wed May 31 15:59:50 2017 DaZe
//

#include <cmath>
#include "Convert.hpp"
#include "Car.hpp"

const float Car::_maxSpeed = 500;
const float Car::_fps = 60;
const float Car::_inertia = Car::_maxSpeed / Car::_fps;
const float Car::_pi = 3.141592f;

Car::Car(std::pair<int, int> posMap, const Element::EType type) : _posMap(posMap), _speed(0.0f), _dir(1.0f, 0.0f), _angle(0.0f), edir(EDirection::RIGHT)
{
  _prevPos = std::make_pair<int, int>(posMap.first - 1, posMap.second - 1);
  _pos = std::make_pair(50.0f, 50.0f);
  _type = type;
}

bool            Car::checkArrounding()
{
  switch (this->edir)
    {
    case EDirection::RIGHT:
      if (this->_arrounding.at(3) == Element::EType::BLOCK)
	return (false);
      break;
    case EDirection::LEFT:
      if (this->_arrounding.at(7) == Element::EType::BLOCK)
	return (false);
      break;
    case EDirection::UP:
      if (this->_arrounding.at(1) == Element::EType::BLOCK)
	return (false);
    case EDirection::UP_LEFT:
      if (this->_arrounding.at(0) == Element::EType::BLOCK)
	return (false);
      break;
    case EDirection::UP_RIGHT:
      if (this->_arrounding.at(2) == Element::EType::BLOCK)
	return (false);
      break;
    case EDirection::DOWN:
      if (this->_arrounding.at(5) == Element::EType::BLOCK)
	return (false);
    case EDirection::DOWN_RIGHT:
      if (this->_arrounding.at(4) == Element::EType::BLOCK)
	return (false);
      break;
    case EDirection::DOWN_LEFT:
      if (this->_arrounding.at(6) == Element::EType::BLOCK)
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
  std::cout << "speed : " << this->_speed << std::endl;
  if (checkArrounding() == false)
    {
      this->_speed = 0.0f;
      return;
    }
  if (this->_speed <= this->_maxSpeed)
  {
    std::cout << "sexe" << std::endl;
    this->_speed += this->_inertia;
  }
}

void            Car::deccelerate()
{
  std::cout << "J'enlève les voiles, Capitaine" << std::endl;
  std::cout << "speed : " << this->_speed << std::endl;
  // if (checkArrounding() == false)
  //   {
  //     this->_speed = 0.0f;
  //     return;
  //   }
  if (this->_speed >= -this->_maxSpeed / 2)
    this->_speed -= this->_inertia;
}

void            Car::slowDown()
{
  // std::cout << "J'enlève les voiles de moitié, Capitaine" << std::endl;
  // std::cout << "speed : " << this->_speed;
  // if (checkArrounding() == false)
  //   {
  //     this->_speed = 0.0f;
  //     return;
  //   }
  if (this->_speed > 0)
    this->_speed -= this->_inertia / 2;
  else if (this->_speed < 0)
    this->_speed += this->_inertia / 2;
}

void            Car::move()
{
  std::cout << _pos.first << " --- " << _pos.second << std::endl;
  auto tmp = this->_prevPos;
  this->_prevPos = this->_posMap;
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

  if (this->_posMap == this->_prevPos)
    this->_prevPos = tmp;
  std::cout << "POS = " << Convert::coordToPos<int>(_posMap) << std::endl;
  std::cout << "PREV POS = " << Convert::coordToPos<int>(_prevPos) << std::endl;
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
  this->_angle += 5.0f;

  this->_dir.first = cosf(this->_angle * _pi / 180.0f);
  this->_dir.second = sinf(this->_angle * _pi / 180.0f);

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
  this->_angle -= 5.0f;
  this->_dir.first = cosf(this->_angle * _pi / 180.0f);
  this->_dir.second = sinf(this->_angle * _pi / 180.0f);

  // std::cout << "TURN RIGHT dir == " << _dir.first << " --- " << _dir.second << std::endl;
}

float		Car::getAbsoluteAngle() const
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
  // std::cout << pos.first << " --- " << pos.second << std::endl;
  this->_posMap = pos;
}

float                           Car::getAngle() const
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

void				Car::setArrounding(const std::array<Element::EType, 8> &arrounding)
{
  this->_arrounding = arrounding;
}
