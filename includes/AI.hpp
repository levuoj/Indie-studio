//
// Ai.hpp for Ai.hpp in /home/tvigier/Indie_studio/includes
// 
// Made by thomas vigier
// Login   <thomas.vigier@epitech.eu>
// 
// Started on  Tue May  9 11:35:04 2017 thomas vigier
// Last update Mon May 22 17:00:31 2017 DaZe
//

#pragma once

#include <vector>
#include <functional>
#include <unordered_map>
#include "GameElement.hpp"
#include "Car.hpp"

class				AI
{
  Car				_car;
  std::vector<Element>		_map;
  int				_prevPos;
  //  std::unordered_map<int, std::function<void()>> _functors;
  std::vector<std::function<void()>> _functors;
public:
  void				setMap(std::vector<Element> const &);
  Car const &			getCar() const;
  void				chooseAction();
  void				detectLine();
  bool				isLine(int);
  void				upLeft();
  void				up();
  void				upRight();
  void				left();
  void				right();
  void				downLeft();
  void				down();
  void				downRight();

  AI();
  AI(std::pair<int, int> pos);
};
