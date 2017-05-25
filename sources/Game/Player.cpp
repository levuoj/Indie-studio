//
// Player.cpp for  in /home/Kilian/Rendu/C++/Indie_studio/sources/Game
// 
// Made by Lebrun Kilian
// Login   <kilian.lebrun@epitech.eu>
// 
// Started on  Tue May 23 16:11:27 2017 Lebrun Kilian
// Last update Tue May 23 16:11:29 2017 Lebrun Kilian
//

#include "test.hpp"
#include "Player.hpp"

Player::Player(std::pair<int, int> &carPos)
{
  this->_car.setPosMap(carPos);
}


void		Player::driver(const irr::EKEY_CODE &key)
{
  const auto        &it = _functors.find(key);

  if (it != _functors.end())
    it->second();
  else
    this->_car.slowDown();
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
