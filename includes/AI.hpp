//
// Ai.hpp for Ai.hpp in /home/tvigier/Indie_studio/includes
// 
// Made by thomas vigier
// Login   <thomas.vigier@epitech.eu>
// 
// Started on  Tue May  9 11:35:04 2017 thomas vigier
// Last update Mon Jun  5 14:56:59 2017 DaZe
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
  //  std::unordered_map<int, std::function<void()>> _functors;
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
  void				part7();
  void				part8();
  void				part9();
  void				part10();
  void				part11();
  void				part12();
  void				part13();
  void				part14();
  void				part15();
  int			getIdx() const;

  AI() = default;
  AI(std::pair<int, int> const& pos, const Element::EType);
  AI(std::pair<int, int> posMap, const Element::EType type, float angle, short int lap,
     bool isFinished, Car::EDirection dir, int idx);
  ~AI() = default;
  AI(AI const &) = default;
};
