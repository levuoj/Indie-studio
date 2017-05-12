//
// AI.cpp for AI.cpp in /home/tvigier/Indie_studio/sources/Game
// 
// Made by thomas vigier
// Login   <thomas.vigier@epitech.eu>
// 
// Started on  Fri May 12 15:23:36 2017 thomas vigier
// Last update Fri May 12 17:48:41 2017 thomas vigier
//

#include "AI.hpp"

void			AI::setMap(std::vector<Element> const& map)
{
  _map = map;
}

std::string const	AI::getWall()
{
  int factor = 51;
  int x = 0, y = 0;
  
  while (_map[Convert::coordToPos<int>(_car.getPosMap()) + factor].getType() != Element::BLOCK)
    {
      factor += 51;
      ++x;
    }
  factor = -49;
  while (_map[Convert::coordToPos<int>(_car.getPosMap()) + factor].getType() != Element::BLOCK)
    {
      factor -= 49;
      ++y;
    }
  if (x < y)
    return ("RIGHT");
  else if (x > y)
    return ("LEFT");
  else
    return ("FORWARD");
}

void			AI::chooseAction()
{
  if (getWall() == "RIGHT")
    {
      _car.deccelerate();
      _car.turnRight();
    }
  else if (getWall() == "LEFT")
    {
      _car.deccelerate();
      _car.turnLeft();
    }
  else
    _car.accelerate();
  _car.move();
}
