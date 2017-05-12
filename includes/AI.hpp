//
// Ai.hpp for Ai.hpp in /home/tvigier/Indie_studio/includes
// 
// Made by thomas vigier
// Login   <thomas.vigier@epitech.eu>
// 
// Started on  Tue May  9 11:35:04 2017 thomas vigier
// Last update Fri May 12 15:36:10 2017 thomas vigier
//

#pragma once

#include <vector>
#include "GameElement.hpp"
#include "Car.hpp"

class				AI
{
  Car				_car;
  std::vector<Element>		_map;
public:
  void				setMap(std::vector<Element> const &);
  std::string const		getWall();
  void				chooseAction();
};
