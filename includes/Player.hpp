//
// Player.hpp for Player.hpp in /home/tvigier/Indie_studio/includes
// 
// Made by thomas vigier
// Login   <thomas.vigier@epitech.eu>
// 
// Started on  Tue May  9 11:32:29 2017 thomas vigier
// Last update Wed May 10 10:37:01 2017 thomas vigier
//

#pragma once

#include <array>
#include "Car.hpp"

enum EKey {};

class			Player
{
  Car			_car;
  std::array<EKey, 5>	_keys;
public:

  void			setKeys(std::array<EKey, 5> const &) {};
};
