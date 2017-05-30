//
// Ai.hpp for Ai.hpp in /home/tvigier/Indie_studio/includes
// 
// Made by thomas vigier
// Login   <thomas.vigier@epitech.eu>
// 
// Started on  Tue May  9 11:35:04 2017 thomas vigier
// Last update Tue May 30 17:51:35 2017 Lebrun Kilian
//

#pragma once

#include <vector>
#include <memory>
#include <unordered_map>
#include <functional>
#include "GameElement.hpp"
#include "Car.hpp"

class				AI
{
  std::shared_ptr<Car>				_car;
  std::vector<std::shared_ptr<Element>>		_map;
  int						_idx;
  std::unordered_map<int, std::function<void()>> _functors;
public:
  void				setMap(std::vector<std::shared_ptr<Element>> const &);
  std::shared_ptr<Car>		getCar() const;
  void				chooseAction();
  void				part1();
  void				part2();
  void				part3();
  void				part4();
  void				part5();
  void				part6();

  AI() = default;
  AI(std::pair<int, int> const& pos, const Element::EType );
  ~AI() = default;
  AI(AI const &) = default;
};
