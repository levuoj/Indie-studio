//
// AI.cpp for  in /home/Kilian/Rendu/C++/Indie_studio
// 
// Made by Lebrun Kilian
// Login   <kilian.lebrun@epitech.eu>
// 
// Started on  Tue May 23 09:35:42 2017 Lebrun Kilian
// Last update Tue May 23 17:01:12 2017 Lebrun Kilian
//

#include <unistd.h>
#include "Convert.hpp"
#include "AI.hpp"

AI::AI()
{
}

AI::AI(std::pair<int, int> pos)
{
  _car = Car(pos);
}

void			AI::chooseAction()
{
  detectLine();
  _car.move();
}

bool			AI::isLine(int pos)
{
  if (_map[Convert::coordToPos<int>(_car.getPosMap()) + pos].get()->getType()
      == Element::EType::LINE
      && Convert::coordToPos<int>(_car.getPosMap()) + pos != _prevPos)
    {
      std::cout << "POS + X" << Convert::coordToPos<int>(_car.getPosMap()) + pos << std::endl;
      return (true);
    }
  return (false);
}

void			AI::detectLine()
{
  std::cout << "ANGLE = " << _car.getAbsoluteAngle() << std::endl;
  std::cout << "POS MAP = " << Convert::coordToPos<int>(_car.getPosMap()) << std::endl;
  upLeft();
  up();
  upRight();
  left();
  right();
  downLeft();
  down();
  downRight();
}

void			AI::upLeft()
{
  if (isLine(-51) == true)
    {
      std::cout << "UP LEFT" << std::endl;
      _car.turnLeft();
    }
}

void			AI::up()
{
  if (isLine(-50) == true)
    {
      std::cout << "UP" << std::endl;
      _car.accelerate();
    }
}

void			AI::upRight()
{
  if (isLine(-49) == true)
    {
      std::cout << "UP RIGHT" << std::endl;
      _car.turnRight();
    }
}

void			AI::left()
{
  if (isLine(-1) == true)
    {
      std::cout << "LEFT" << std::endl;
      _car.accelerate();
    }
}

void			AI::right()
{
  if (isLine(1) == true)
    {
      std::cout << "RIGHT" << std::endl;
      _car.accelerate();
    }
}

void			AI::downLeft()
{
  if (isLine(49) == true)
    {
      std::cout << "DOWN LEFT" << std::endl;
      _car.turnLeft();
    }
}

void			AI::down()
{
  if (isLine(50) == true)
    {
      std::cout << "DOWN" << std::endl;
      _car.accelerate();
    }
}

void			AI::downRight()
{
  if (isLine(51) == true)
    {
      std::cout << "DOWN RIGHT" << std::endl;
      _car.turnRight();
    }
}

void			AI::setMap(std::vector<std::unique_ptr<Element>> const &map)
{
  _map = map;
}

Car const &		AI::getCar() const
{
  return (_car);
}
