//
// Player.hpp for Player.hpp in /home/tvigier/Indie_studio/includes
// 
// Made by thomas vigier
// Login   <thomas.vigier@epitech.eu>
// 
// Started on  Tue May  9 11:32:29 2017 thomas vigier
// Last update Tue May 16 13:47:14 2017 Lebrun Kilian
//

#pragma once

#include <array>
#include <unordered_map>
#include <Keycodes.h>
#include <functional>
#include "Car.hpp"

class			Player
{
  std::pair<int, int>   _posMap;
  Car	                  _car;
  std::unordered_map<irr::EKEY_CODE, std::function<void()>> _functors;
  std::array<irr::EKEY_CODE, 5>   _keys;
public:

  Player(const std::pair<int, int> &carPos)
  {
    this->_car.setPosMap(carPos);
  }
  ~Player() {};
  void		driver(const irr::EKEY_CODE &key);
  void		setKeys(const std::array<irr::EKEY_CODE, 5> &keys)
  {
    this->_keys = keys;
    _functors[this->_keys.at(0)] = std::bind(&Car::accelerate, this->_car);
    _functors[this->_keys.at(1)] = std::bind(&Car::deccelerate, this->_car);
    _functors[this->_keys.at(2)] = std::bind(&Car::turnLeft, this->_car);
    _functors[this->_keys.at(3)] = std::bind(&Car::turnRight, this->_car);
    _functors[this->_keys.at(4)] = std::bind(&Car::launchPowerUp, this->_car);
  }
};
