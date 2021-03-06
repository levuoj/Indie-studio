//
// Car.cpp for  in /home/Kilian/Rendu/C++/Indie_studio/sources
//
// Made by Lebrun Kilian
// Login   <kilian.lebrun@epitech.eu>
//
// Started on  Sat May 13 12:00:41 2017 Lebrun Kilian
// Last update Sun Jun 18 21:58:36 2017 Lebrun Kilian
//

#include <random>
#include <cmath>
#include "Convert.hpp"
#include "Car.hpp"

const float Car::_fps = 60;
const float Car::_pi = 3.141592f;

Car::Car(const std::pair<int, int> &posMap, Element::EType type, float angle, short int lap, bool isFinished, EDirection dir) : _posMap(posMap), _speed(0.0f), _angle(angle), _lap(lap), _isFinished(isFinished), _edir(dir), _isStopped(false), _isRank(true), _maxSpeed(550), _inertia(550 / _fps), _state(NONE), _speedSave(0)

{
  _pos = std::make_pair(50.0f, 50.0f);
  _type = type;
  this->_dir.first = cosf(this->_angle * _pi / 180.0f);
  this->_dir.second = sinf(this->_angle * _pi / 180.0f);
  this->_powerchrono.stop();
  this->_powerchrono.setTime(0.0);
}

Car::Car(const std::pair<int, int> &posMap, Element::EType type) : _posMap(posMap), _speed(0.0f), _dir(1.0f, 0.0f), _angle(0.0f), _lap(-1), _isFinished(false), _edir(EDirection::RIGHT), _isStopped(false), _isRank(true), _maxSpeed(550), _inertia(550 / _fps), _state(NONE), _speedSave(0)
{
  _prevPos = std::make_pair<int, int>(posMap.first - 1, posMap.second - 1);
  _pos = std::make_pair(50.0f, 50.0f);
  _type = type;
  this->_powerchrono.stop();
  this->_powerchrono.setTime(0.0);
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

void				Car::Power()
{
  std::random_device			rd;
  std::default_random_engine		generator(rd());
  std::uniform_int_distribution<int>	distribution(1, 3);

  switch (distribution(generator))
    {
      case 1:
        this->_maxSpeed += 700;
        if (this->_speed < 550)
          this->_speedSave = this->_speed;
        this->_speed += 700;
        this->_inertia = this->_maxSpeed / this->_fps;
        this->_state = FAST;
        break;
      case 2:
        this->_maxSpeed -= 300;
        this->_speedSave = this->_speed;
        this->_speed -= 250;
        this->_inertia = this->_maxSpeed / this->_fps;
        this->_state = SLOW;
        break;
    case 3:
      this->_state = OIL;
      break;
    default:
      break;
    }
  this->_powerchrono.start();
}

void				Car::managePowerUp()
{
  if (this->_state != NONE)
    {
      if (this->_state == OIL)
	{
	  if (this->_powerchrono.getTime() < 1.16)
	    {
	      this->_speed = 0;
	      this->_maxSpeed = 0;
	      this->_angle -= 5;
	    }
	  else
	    {
	      this->_maxSpeed = 550;
	      this->_speed = this->_speedSave;
	      this->_powerchrono.stop();
	      this->_powerchrono.setTime(0.0);
	      this->_state = NONE;
	    }
	}
      else
	if (this->_powerchrono.getTime() >= 2)
	  {
	    this->_powerchrono.stop();
	    this->_powerchrono.setTime(0.0);
	    if (this->_state == SLOW)
	      this->_speed += 300;
	    else
	      this->_speed = this->_speedSave;
	    this->_maxSpeed = 550;
	    this->_inertia = this->_maxSpeed / this->_fps;
	    this->_state = NONE;
	  }
    }
}

void				Car::move()
{
  this->_powerchrono.incTime();
  managePowerUp();
  if (this->_speed >= 0)
    {
      if (checkArrounding() == Element::EType::BLOCK)
	{
	  this->_speed = 0.0f;
	  return;
	}
      if (checkArrounding() == Element::EType::POWERUP && this->_state == NONE)
	Power();
    }
  else
    if (checkBackArrounding() == Element::EType::BLOCK)
      {
	this->_speed = 0.0f;
	return;
      }
    else if (checkBackArrounding() == Element::EType::POWERUP && this->_state == NONE)
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
  if (this->_state == OIL)
    return ;
  if (this->_angle >= 360)
    this->_angle = 0.0f;
  this->_angle += 2.5f;

  this->_dir.first = cosf(this->_angle * _pi / 180.0f);
  this->_dir.second = sinf(this->_angle * _pi / 180.0f);
}

void            Car::turnRight()
{
  if (this->_state == OIL)
    return ;
  if (this->_angle <= -360)
    this->_angle = 0.0f;
  this->_angle -= 2.5f;

  this->_dir.first = cosf(this->_angle * _pi / 180.0f);
  this->_dir.second = sinf(this->_angle * _pi / 180.0f);
}

Element::EType            Car::checkArrounding() const
{
  switch (this->_edir)
    {
    case EDirection::RIGHT:
      if (getAbsoluteAngle() >= 0 && getAbsoluteAngle() < 30)
	return (this->_arrounding.at(2));
      else if (getAbsoluteAngle() <= 360 && getAbsoluteAngle() > 330)
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
      if (getAbsoluteAngle() >= 190 && getAbsoluteAngle() < 210)
	{
	  if (this->_arrounding.at(6) == Element::EType::BLOCK)
	    return (Element::EType::BLOCK);
	}
      else if (getAbsoluteAngle() <= 180 && getAbsoluteAngle() > 150)
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
      if (getAbsoluteAngle() >= 100 && getAbsoluteAngle() < 120)
	{
	  if (this->_arrounding.at(0) == Element::EType::BLOCK)
	    return (Element::EType::BLOCK);
	}
      else if (getAbsoluteAngle() <= 90 && getAbsoluteAngle() > 60)
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
      if (getAbsoluteAngle() >= 280 && getAbsoluteAngle() < 300)
	{
	  if (this->_arrounding.at(4) == Element::EType::BLOCK)
	    return (Element::EType::BLOCK);
	}
      else if (getAbsoluteAngle() <= 270 && getAbsoluteAngle() > 240)
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

Element::EType            Car::checkBackArrounding() const
{
  switch (this->_edir)
    {
    case EDirection::RIGHT:
      if (getAbsoluteAngle() >= 0 && getAbsoluteAngle() < 30)
	{
	  if (this->_arrounding.at(6) == Element::EType::BLOCK)
	    return (Element::EType::BLOCK);
	}
      else if (getAbsoluteAngle() <= 360 && getAbsoluteAngle() > 330)
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
      if (getAbsoluteAngle() >= 190 && getAbsoluteAngle() < 210)
	{
	  if (this->_arrounding.at(2) == Element::EType::BLOCK)
	    return (Element::EType::BLOCK);
	}
      else if (getAbsoluteAngle() <= 180 && getAbsoluteAngle() > 150)
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
      if (getAbsoluteAngle() >= 10 && getAbsoluteAngle() < 120)
	{
	  if (this->_arrounding.at(4) == Element::EType::BLOCK)
	    return (Element::EType::BLOCK);
	}
      else if (getAbsoluteAngle() <= 90 && getAbsoluteAngle() > 60)
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
      if (getAbsoluteAngle() >= 280 && getAbsoluteAngle() < 300)
	{
	  if (this->_arrounding.at(0) == Element::EType::BLOCK)
	    return (Element::EType::BLOCK);
	}
      else if (getAbsoluteAngle() <= 270 && getAbsoluteAngle() > 240)
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

float		Car::getAbsoluteAngle() const
{
  if (_angle < 0.0f)
    return (_angle + 360.0f);
  return (_angle);
}

void				Car::incLap()
{
  _lap += 1;
}

void				Car::stop()
{
  setSpeed(0.0f);
}

void                            Car::setPosMap(const std::pair<int, int> & pos)
{
  this->_posMap = pos;
}

void				Car::setLap(const short int lap)
{
  this->_lap = lap;
}

void				Car::setSpeed(const float speed)
{
  this->_speed = speed;
}

void				Car::setFinished(const bool finish)
{
  this->_isFinished = finish;
}

void				Car::setIsRank(const bool rank)
{
  this->_isRank = rank;
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

bool				Car::getStop() const
{
  return (_isStopped);
}
