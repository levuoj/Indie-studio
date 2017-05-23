//
// Ai.hpp for Ai.hpp in /home/tvigier/Indie_studio/includes
// 
// Made by thomas vigier
// Login   <thomas.vigier@epitech.eu>
// 
// Started on  Tue May  9 11:35:04 2017 thomas vigier
// Last update Tue May 23 18:57:50 2017 DaZe
//

#pragma once

#include <vector>
#include <memory>
#include <functional>
#include "GameElement.hpp"
#include "Car.hpp"

class				AI
{
  std::shared_ptr<Car>				_car;
  std::vector<std::shared_ptr<Element>>		_map;
  int				_prevPos;
public:
  void				setMap(std::vector<std::shared_ptr<Element>> const &);
  std::shared_ptr<Car>				getCar() const;
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

  explicit AI();
  AI(std::pair<int, int> const& pos);
  //  AI(const AI&) = delete;
  AI& operator=(const AI&) = delete;
  ~AI() = default;
};
