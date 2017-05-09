//
// Player.hpp for Player.hpp in /home/tvigier/Indie_studio/includes
// 
// Made by thomas vigier
// Login   <thomas.vigier@epitech.eu>
// 
// Started on  Tue May  9 11:32:29 2017 thomas vigier
// Last update Tue May  9 17:39:27 2017 thomas vigier
//

#pragma once

#include "Car.hpp"

class			Player
{
  Car			_car;
  std::array<EKey>	_keys;
public:

  void			setKeys(std::array<EKey> const &);
};
