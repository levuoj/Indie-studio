//
// AI.cpp for AI.cpp in /home/tvigier/Indie_studio/sources/Game
// 
// Made by thomas vigier
// Login   <thomas.vigier@epitech.eu>
// 
// Started on  Fri May 12 15:23:36 2017 thomas vigier
// Last update Mon May 22 18:00:26 2017 DaZe
//

#include <unistd.h>
#include "Convert.hpp"
#include "AI.hpp"

AI::AI()
{
  /*  _functors[0] = std::bind(&AI::upLeft, this);
  _functors[1] = std::bind(&AI::up, this);
  _functors[2] = std::bind(&AI::upRight, this);
  _functors[3] = std::bind(&AI::left, this);
  _functors[4] = std::bind(&AI::right, this);
  _functors[5] = std::bind(&AI::downLeft, this);
  _functors[6] = std::bind(&AI::down, this);
  _functors[7] = std::bind(&AI::downRight, this); */
  _functors.push_back([this](){this->upLeft();});
  //  _functors.push_back(std::bind(&AI::upLeft, this));
  _functors.push_back(std::bind(&AI::up, this));
  _functors.push_back(std::bind(&AI::upRight, this));
  _functors.push_back(std::bind(&AI::left, this));
  _functors.push_back(std::bind(&AI::right, this));
  _functors.push_back(std::bind(&AI::downLeft, this));
  _functors.push_back(std::bind(&AI::down, this));
  _functors.push_back(std::bind(&AI::downRight, this));
}

AI::AI(std::pair<int, int> pos)
{
  _car = Car(pos);
  _functors.push_back(std::bind(&AI::upLeft, this));
  _functors.push_back(std::bind(&AI::up, this));
  _functors.push_back(std::bind(&AI::upRight, this));
  _functors.push_back(std::bind(&AI::left, this));
  _functors.push_back(std::bind(&AI::right, this));
  _functors.push_back(std::bind(&AI::downLeft, this));
  _functors.push_back(std::bind(&AI::down, this));
  _functors.push_back(std::bind(&AI::downRight, this));
}

void			AI::chooseAction()
{
  detectLine();
  _car.move();
}

bool			AI::isLine(int pos)
{
  if (_map[Convert::coordToPos<int>(_car.getPosMap()) + pos].getType()
      == Element::EType::LINE
      && Convert::coordToPos<int>(_car.getPosMap()) + pos != _prevPos)
    return (true);
  return (false);
}

void			AI::detectLine()
{
  for (auto const &it : _functors)
    {
      std::cout << Convert::coordToPos<int>(_car.getPosMap()) << std::endl;
      it();
    }
}

void			AI::upLeft()
{
  std::cout << Convert::coordToPos<int>(_car.getPosMap()) << std::endl;
  if (isLine(-51) == true)
    _car.turnLeft();
}

void			AI::up()
{
  if (isLine(-50) == true)
    _car.accelerate();
}

void			AI::upRight()
{
  if (isLine(-49) == true)
    _car.turnRight();
}

void			AI::left()
{
  if (isLine(-1) == true)
    _car.accelerate();
}

void			AI::right()
{
  std::cout << "lol" << std::endl;
  if (isLine(-50) == true)
    _car.accelerate();
}

void			AI::downLeft()
{
  if (isLine(49) == true)
    _car.turnLeft();
}

void			AI::down()
{
  if (isLine(50) == true)
    _car.accelerate();
}

void			AI::downRight()
{
  if (isLine(51) == true)
    _car.turnRight();
}

void			AI::setMap(std::vector<Element> const &map)
{
  _map = map;
}

Car const &		AI::getCar() const
{
  return (_car);
}
