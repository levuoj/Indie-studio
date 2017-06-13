//
// Player.hpp for Player.hpp in /home/tvigier/Indie_studio/includes
//
// Made by thomas vigier
// Login   <thomas.vigier@epitech.eu>
//
// Started on  Tue May  9 11:32:29 2017 thomas vigier
// Last update Tue Jun 13 18:28:22 2017 DaZe
//

#pragma once

#include <vector>
#include <array>
#include <unordered_map>
#include <Keycodes.h>
#include <functional>
#include <memory>
#include "EventReceiver.hpp"
#include "Car.hpp"

class			Player
{
  std::pair<int, int>						_posMap;
  std::shared_ptr<Car>						_car;
  std::unordered_map<irr::EKEY_CODE, std::function<void()>>	_functors;
  std::vector<irr::EKEY_CODE>					_keys;
public:

  Player(const std::pair<int, int> &carPos, const Element::EType type);
  Player(std::pair<int, int> posMap, const Element::EType type, float angle, short int lap, bool isFinished, Car::EDirection dir);
  ~Player() {};
  void			initDir();
  void			driver(EventReceiver const& key);
  void			setKeys(const std::vector<irr::EKEY_CODE> &keys);

  void			setArroundingCar(const std::array<Element::EType, 8> &arrounding);
  Car::EDirection	dirFromAngle(int angle);
  std::pair<int, int>	getPosMap()
  {
    return (this->_car->getPosMap());
  }
  std::shared_ptr<Car>  getCar() const
  {
    return (this->_car);
  }
};
