//
// Car.cpp for  in /home/Kilian/Rendu/C++/Indie_studio/sources
//
// Made by Lebrun Kilian
// Login   <kilian.lebrun@epitech.eu>
//
// Started on  Sat May 13 12:00:41 2017 Lebrun Kilian
// Last update Thu Jun 15 13:52:17 2017 Lebrun Kilian
//

#include <cmath>
#include "Convert.hpp"
#include "Car.hpp"

const float Car::_fps = 60;
const float Car::_pi = 3.141592f;

Car::Car(std::pair<int, int> posMap, const Element::EType type, float angle, short int lap, bool isFinished, EDirection dir) : _posMap(posMap), _speed(0.0f), _angle(angle), _lap(lap), _isFinished(isFinished), _edir(dir), _isStopped(false), _isRank(true), _maxSpeed(550), _inertia(550 / _fps)
{
  //  _prevPos = std::make_pair<int, int>(posMap.first - 1, posMap.second - 1);
  _pos = std::make_pair(50.0f, 50.0f);
  _type = type;
  this->_dir.first = cosf(this->_angle * _pi / 180.0f);
  this->_dir.second = sinf(this->_angle * _pi / 180.0f);
}

Car::Car(std::pair<int, int> posMap, const Element::EType type) : _posMap(posMap), _speed(0.0f), _dir(1.0f, 0.0f), _angle(0.0f), _lap(-1), _isFinished(false), _edir(EDirection::RIGHT), _isStopped(false), _isRank(true), _maxSpeed(550), _inertia(550 / _fps)
{
  _prevPos = std::make_pair<int, int>(posMap.first - 1, posMap.second - 1);
  _pos = std::make_pair(50.0f, 50.0f);
  _type = type;
}

void            Car::accelerate()
{
  if (this->_speed <= this->_maxSpeed)
    this->_speed += this->_inertia;
}

void            Car::deccelerate()
{
  if (this->_speed >= -this->_maxSpeed / 2)
    this->_speed -= this->_inertia;
}

void            Car::slowDown()
{
  if (this->_speed > 0)
    this->_speed -= this->_inertia / 0.5;
  else if (this->_speed < 0)
    this->_speed += this->_inertia / 0.5;
}

void				Car::Power()
{
  int	random = rand() % 3 + 1;

  switch (random)
    {
    case 1:
      this->_maxSpeed = 800;
      this->_inertia = this->_maxSpeed / this->_fps;
	break;
    case 2:
      this->_maxSpeed = 200;
      this->_speed = 200;
      this->_inertia = this->_maxSpeed / this->_fps;
	break;
    case 3:
      break;
    }
  this->_chrono.start();
}

void                            Car::launchPowerUp()
{
}

void            Car::move()
{
  this->_chrono.incTime();
  if (this->_chrono.getTime() >= 2.0)
    {
      this->_chrono.stop();
      this->_chrono.setTime(0.0);
    }
  std::cout << "MAX SPEED = " << this->_maxSpeed << std::endl;
  if (this->_speed >= 0)
    {
      if (checkArrounding() == Element::EType::BLOCK)
	{
	  this->_speed = 0.0f;
	  return;
	}
      else if (checkArrounding() == Element::EType::POWERUP)
	Power();
    }
  else
    if (checkBackArrounding() == Element::EType::BLOCK)
      {
	this->_speed = 0.0f;
	return;
      }
    else if (checkBackArrounding() == Element::EType::POWERUP)
      Power();
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
}

void            Car::turnLeft()
{
  // std::cout << "ANGLE = " << _angle << std::endl;
  if (this->_angle >= 360)
    this->_angle = 0.0f;
  this->_angle += 2.5f;

  this->_dir.first = cosf(this->_angle * _pi / 180.0f);
  this->_dir.second = sinf(this->_angle * _pi / 180.0f);
}

void            Car::turnRight()
{
  // std::cout << "ANGLE = " << _angle << std::endl;
  if (this->_angle <= -360)
    this->_angle = 0.0f;
  this->_angle -= 2.5f;
  this->_dir.first = cosf(this->_angle * _pi / 180.0f);
  this->_dir.second = sinf(this->_angle * _pi / 180.0f);
}

Element::EType            Car::checkArrounding()
{
  switch (this->_edir)
    {
    case EDirection::RIGHT:
      if (getAbsoluteAngle() >= 5 && getAbsoluteAngle() < 30)
	return (this->_arrounding.at(2));
      else if (getAbsoluteAngle() <= 355 && getAbsoluteAngle() > 330)
	{
	  if (this->_arrounding.at(4) == Element::EType::BLOCK)
	    return (Element::EType::BLOCK);
	}
      if (this->_arrounding.at(3) == Element::EType::BLOCK)
	return (Element::EType::BLOCK);
      else if (this->_arrounding.at(3) == Element::EType::POWERUP)
	return (Element::EType::POWERUP);
      break;
	  
    case EDirection::LEFT:
      if (getAbsoluteAngle() >= 185 && getAbsoluteAngle() < 210)
	{
	  if (this->_arrounding.at(6) == Element::EType::BLOCK)
	    return (Element::EType::BLOCK);
	}
      else if (getAbsoluteAngle() <= 175 && getAbsoluteAngle() > 150)
	{
	  if (this->_arrounding.at(0) == Element::EType::BLOCK)
	    return (Element::EType::BLOCK);
	}
      if (this->_arrounding.at(7) == Element::EType::BLOCK)
	return (Element::EType::BLOCK);
      else if (this->_arrounding.at(7) == Element::EType::POWERUP)
	return (Element::EType::POWERUP);
      break;
	  
    case EDirection::UP:
      if (getAbsoluteAngle() >= 95 && getAbsoluteAngle() < 120)
	{
	  if (this->_arrounding.at(0) == Element::EType::BLOCK)
	    return (Element::EType::BLOCK);
	}
      else if (getAbsoluteAngle() <= 85 && getAbsoluteAngle() > 60)
	{
	  if (this->_arrounding.at(2) == Element::EType::BLOCK)
	    return (Element::EType::BLOCK);
	}
      if (this->_arrounding.at(1) == Element::EType::BLOCK)
	return (Element::EType::BLOCK);
      else if (this->_arrounding.at(1) == Element::EType::POWERUP)
	return (Element::EType::POWERUP);
      break;
	  
    case EDirection::UP_LEFT:
      if (this->_arrounding.at(0) == Element::EType::BLOCK)
	return (Element::EType::BLOCK);
      else if (this->_arrounding.at(0) == Element::EType::POWERUP)
	return (Element::EType::POWERUP);
      break;

    case EDirection::UP_RIGHT:
      if (this->_arrounding.at(2) == Element::EType::BLOCK)
	return (Element::EType::BLOCK);
      else if (this->_arrounding.at(2) == Element::EType::POWERUP)
	return (Element::EType::POWERUP);
      break;
	 
    case EDirection::DOWN:
      if (getAbsoluteAngle() >= 275 && getAbsoluteAngle() < 300)
	{
	  if (this->_arrounding.at(4) == Element::EType::BLOCK)
	    return (Element::EType::BLOCK);
	}
      else if (getAbsoluteAngle() <= 265 && getAbsoluteAngle() > 240)
	{
	  if (this->_arrounding.at(6) == Element::EType::BLOCK)
	    return (Element::EType::BLOCK);
	}
      if (this->_arrounding.at(5) == Element::EType::BLOCK)
	return (Element::EType::BLOCK);
      else if (this->_arrounding.at(5) == Element::EType::POWERUP)
	return (Element::EType::POWERUP);
      break;
	  
    case EDirection::DOWN_RIGHT:
      if (this->_arrounding.at(4) == Element::EType::BLOCK)
	return (Element::EType::BLOCK);
      else if (this->_arrounding.at(4) == Element::EType::POWERUP)
	return (Element::EType::POWERUP);
      break;
	  
    case EDirection::DOWN_LEFT:
      if (this->_arrounding.at(6) == Element::EType::BLOCK)
	return (Element::EType::BLOCK);
      else if (this->_arrounding.at(6) == Element::EType::POWERUP)
	return (Element::EType::POWERUP);
      break;
	  
    default:
      break;
    }
  return (Element::EType::DEFAULT);
}

Element::EType            Car::checkBackArrounding()
{
  switch (this->_edir)
    {
    case EDirection::RIGHT:
      if (getAbsoluteAngle() >= 5 && getAbsoluteAngle() < 30)
	{
	  if (this->_arrounding.at(6) == Element::EType::BLOCK)
	    return (Element::EType::BLOCK);
	}
      else if (getAbsoluteAngle() <= 355 && getAbsoluteAngle() > 330)
	{
	  if (this->_arrounding.at(0) == Element::EType::BLOCK)
	    return (Element::EType::BLOCK);
	}
      if (this->_arrounding.at(7) == Element::EType::BLOCK)
	return (Element::EType::BLOCK);
      else if (this->_arrounding.at(7) == Element::EType::POWERUP)
	return (Element::EType::POWERUP);
      break;
	  
    case EDirection::LEFT:
      if (getAbsoluteAngle() >= 185 && getAbsoluteAngle() < 210)
	{
	  if (this->_arrounding.at(2) == Element::EType::BLOCK)
	    return (Element::EType::BLOCK);
	}
      else if (getAbsoluteAngle() <= 175 && getAbsoluteAngle() > 150)
	{
	  if (this->_arrounding.at(4) == Element::EType::BLOCK)
	    return (Element::EType::BLOCK);
	}
      if (this->_arrounding.at(3) == Element::EType::BLOCK)
	return (Element::EType::BLOCK);
      else if (this->_arrounding.at(3) == Element::EType::POWERUP)
	return (Element::EType::POWERUP);
      break;
	  
    case EDirection::UP:
      if (getAbsoluteAngle() >= 95 && getAbsoluteAngle() < 120)
	{
	  if (this->_arrounding.at(4) == Element::EType::BLOCK)
	    return (Element::EType::BLOCK);
	}
      else if (getAbsoluteAngle() <= 85 && getAbsoluteAngle() > 60)
	{
	  if (this->_arrounding.at(6) == Element::EType::BLOCK)
	    return (Element::EType::BLOCK);
	}
      if (this->_arrounding.at(5) == Element::EType::BLOCK)
	return (Element::EType::BLOCK);
      else if (this->_arrounding.at(5) == Element::EType::POWERUP)
	return (Element::EType::POWERUP);
      break;
	  
    case EDirection::UP_LEFT:
      if (this->_arrounding.at(4) == Element::EType::BLOCK)
	return (Element::EType::BLOCK);
      else if (this->_arrounding.at(4) == Element::EType::POWERUP)
	return (Element::EType::POWERUP);
      break;
	  
    case EDirection::UP_RIGHT:
      if (this->_arrounding.at(6) == Element::EType::BLOCK)
	return (Element::EType::BLOCK);
      else if (this->_arrounding.at(6) == Element::EType::POWERUP)
	return (Element::EType::POWERUP);
      break;
	  
    case EDirection::DOWN:
      if (getAbsoluteAngle() >= 275 && getAbsoluteAngle() < 300)
	{
	  if (this->_arrounding.at(0) == Element::EType::BLOCK)
	    return (Element::EType::BLOCK);
	}
      else if (getAbsoluteAngle() <= 265 && getAbsoluteAngle() > 240)
	{
	  if (this->_arrounding.at(2) == Element::EType::BLOCK)
	    return (Element::EType::BLOCK);
	}
      if (this->_arrounding.at(1) == Element::EType::BLOCK)
	return (Element::EType::BLOCK);
      else if (this->_arrounding.at(1) == Element::EType::POWERUP)
	return (Element::EType::POWERUP);
      break;
	  
    case EDirection::DOWN_RIGHT:
      if (this->_arrounding.at(0) == Element::EType::BLOCK)
	return (Element::EType::BLOCK);
      else if (this->_arrounding.at(0) == Element::EType::POWERUP)
	return (Element::EType::POWERUP);
      break;
	  
    case EDirection::DOWN_LEFT:
      if (this->_arrounding.at(2) == Element::EType::BLOCK)
	return (Element::EType::BLOCK);
      else if (this->_arrounding.at(2) == Element::EType::POWERUP)
	return (Element::EType::POWERUP);
      break;
	  
    default:
      break;
    }
  return (Element::EType::DEFAULT);
}

void                            Car::setPosMap(const std::pair<int, int> & pos)
{
  this->_posMap = pos;
}

void				Car::setLap(const short int lap)
{
  _lap = lap;
}

void				Car::setSpeed(const float speed)
{
  _speed = speed;
}

void				Car::setFinished(bool finish)
{
  _isFinished = finish;
}

void				Car::setIsRank(const bool rank)
{
  _isRank = rank;
}

float				Car::getAbsoluteAngle() const
{
  if (_angle < 0.0f)
    return (_angle + 360.0f);
  return (_angle);
}

bool				Car::getIsRank() const
{
  return (_isRank);
}

bool				Car::getFinished() const
{
  return (_isFinished);
}

short int			Car::getLap() const
{
  return (_lap);
}

void				Car::incLap()
{
  _lap += 1;
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

float				Car::getMaxSpeed() const
{
  return (this->_maxSpeed);
}

float				Car::getSpeed() const
{
  return (this->_speed);
}

Car::EDirection			Car::getEDir() const
{
  return (_edir);
}

void				Car::setArrounding(const std::array<Element::EType, 8> &arrounding)
{
  this->_arrounding = arrounding;
}

void				Car::setEdir(const EDirection &dir)
{
  this->_edir = dir;
}

void				Car::setStop(const bool b)
{
  _isStopped = b;
}

bool				Car::getStop() const
{
  return (_isStopped);
}

void				Car::stop()
{
  setSpeed(0.0f);
}
