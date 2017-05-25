//
// Ai.hpp for Ai.hpp in /home/tvigier/Indie_studio/includes
// 
// Made by thomas vigier
// Login   <thomas.vigier@epitech.eu>
// 
// Started on  Tue May  9 11:35:04 2017 thomas vigier
// Last update Thu May 25 18:16:14 2017 DaZe
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
  int						_idx;
  //  std::unordered_map<int, std::function<void()>> _functors;
public:
  void				setMap(std::vector<std::shared_ptr<Element>> const &);
  std::shared_ptr<Car>		getCar() const;
  void				chooseAction();

  AI();
  AI(std::pair<int, int> const& pos);
  ~AI() = default;
};
