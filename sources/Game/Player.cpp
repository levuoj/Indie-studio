//
// Player.cpp for  in /home/Kilian/Rendu/C++/Indie_studio/sources/Game
//
// Made by Lebrun Kilian
// Login   <kilian.lebrun@epitech.eu>
//
// Started on  Tue May 23 16:11:27 2017 Lebrun Kilian
// Last update Sun Jun 18 14:38:43 2017 DaZe
//

#include "Player.hpp"

Player::Player(std::pair<int, int> posMap, const Element::EType type, float angle, short int lap, bool isFinished, Car::EDirection dir)
{
  _car = std::shared_ptr<Car>(new Car(posMap, type, angle, lap, isFinished, dir));
}

Player::Player(const std::pair<int, int> &carPos, const Element::EType type)
{
  this->_car = std::shared_ptr<Car>(new Car(carPos, type));
}

Car::EDirection	Player::dirFromAngle(int angle)
{
  static Car::EDirection	slices[] = { Car::EDirection::RIGHT, Car::EDirection::UP_RIGHT, Car::EDirection::UP, Car::EDirection::UP, Car::EDirection::UP_LEFT, Car::EDirection::LEFT, Car::EDirection::LEFT, Car::EDirection::DOWN_LEFT, Car::EDirection::DOWN, Car::EDirection::DOWN, Car::EDirection::DOWN_RIGHT, Car::EDirection::RIGHT };

  return (slices[angle / 30]);
}

void    Player::initDir()
{
  this->_car->setEdir(dirFromAngle(this->_car->getAbsoluteAngle()));
}

void		Player::driver(EventReceiver const& receiver)
{
  this->initDir();

  for (auto const& it : this->_functors)
    if (receiver.keyDown(it.first))
      {
	it.second();
      }

  this->_car->move();
}

void		Player::setKeys(const std::vector<irr::EKEY_CODE> &keys)
{
  this->_keys = keys;
  _functors[this->_keys.at(0)] = [this](){this->_car->accelerate();};
  _functors[this->_keys.at(1)] = [this](){this->_car->deccelerate();};
  _functors[this->_keys.at(2)] = [this](){this->_car->turnLeft();};
  _functors[this->_keys.at(3)] = [this](){this->_car->turnRight();};
}

void  Player::setArroundingCar(const std::array<Element::EType, 8> &arrounding)
{
   this->_car->setArrounding(arrounding);
}
