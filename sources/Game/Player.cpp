//
// Player.cpp for  in /home/Kilian/Rendu/C++/Indie_studio/sources/Game
// 
// Made by Lebrun Kilian
// Login   <kilian.lebrun@epitech.eu>
// 
// Started on  Tue May 23 16:11:27 2017 Lebrun Kilian
// Last update Wed May 31 10:57:39 2017 DaZe
//

#include "test.hpp"
#include "Player.hpp"

Player::Player(const std::pair<int, int> &carPos, const Element::EType type)
{
  std::cout << carPos.first << " -- " << carPos.second << std::endl;
  this->_car = std::shared_ptr<Car>(new Car(carPos, type));
    //  this->_car->setPosMap(carPos);
}

Car::EDirection	Player::dirFromAngle(int angle)
{
  static Car::EDirection	slices[] = { Car::EDirection::RIGHT, Car::EDirection::UP_RIGHT, Car::EDirection::UP, Car::EDirection::UP, Car::EDirection::UP_LEFT, Car::EDirection::LEFT, Car::EDirection::LEFT, Car::EDirection::DOWN_LEFT, Car::EDirection::DOWN, Car::EDirection::DOWN, Car::EDirection::DOWN_RIGHT, Car::EDirection::RIGHT };
  
  return (slices[angle / 30]);
}

void    Player::initDir()
{
  this->_car->edir = dirFromAngle(this->_car->getAbsoluteAngle());
}

void		Player::driver(const irr::EKEY_CODE &key)
{
  this->initDir();
  const auto        &it = _functors.find(key);

  if (it != _functors.end())
    it->second();
  else
    std::cout << "\nchut" << std::endl;//this->_car->slowDown();
   this->_car.get()->move();
  // std::cout << this->_car->getSpeed() << std::endl;
  // std::cout << this->_car->getPos().first << " ------------------------- " << this->_car->getPos().second << std::endl;
  // std::cout << this->_car->getPosMap().first << " ------------------------- " << this->_car->getPosMap().second << std::endl;
}

void		Player::setKeys(const std::array<irr::EKEY_CODE, 5> &keys)
{
  this->_keys = keys;
  _functors[this->_keys.at(0)] = std::bind(&Car::accelerate, this->_car);
  _functors[this->_keys.at(1)] = std::bind(&Car::deccelerate, this->_car);
  _functors[this->_keys.at(2)] = std::bind(&Car::turnLeft, this->_car);
  _functors[this->_keys.at(3)] = std::bind(&Car::turnRight, this->_car);
  _functors[this->_keys.at(4)] = std::bind(&Car::launchPowerUp, this->_car);
}

void  Player::setArroundingCar(const std::array<Element::EType, 8> &arrounding)
{
   this->_car->setArrounding(arrounding);
}
