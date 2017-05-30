//
// Player.hpp for Player.hpp in /home/tvigier/Indie_studio/includes
// 
// Made by thomas vigier
// Login   <thomas.vigier@epitech.eu>
// 
// Started on  Tue May  9 11:32:29 2017 thomas vigier
// Last update Fri May 26 15:29:57 2017 Lebrun Kilian
//

#pragma once

#include <array>
#include <unordered_map>
#include <Keycodes.h>
#include <functional>
#include <memory>
#include "Car.hpp"

class			Player
{
  std::pair<int, int>						_posMap;
  std::shared_ptr<Car>								_car;
  std::unordered_map<irr::EKEY_CODE, std::function<void()>>	_functors;
  std::array<irr::EKEY_CODE, 5>					_keys;
public:

  Player(const std::pair<int, int> &carPos);
  ~Player() {};
  void			initDir();
  void			driver(const irr::EKEY_CODE &key);
  void			setKeys(const std::array<irr::EKEY_CODE, 5> &keys);
  void			setArroundingCar(const std::array<Element::EType, 8> &arrounding);
  Car::EDirection	dirFromAngle(int angle);
  std::pair<int, int>	getPosMap()
  {
    return (this->_posMap);
  }
  std::shared_ptr<Car>  getCar() const
  {
    return (this->_car);
  }
};
