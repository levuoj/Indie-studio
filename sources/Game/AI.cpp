//
// AI.cpp for  in /home/Kilian/Rendu/C++/Indie_studio
// 
// Made by Lebrun Kilian
// Login   <kilian.lebrun@epitech.eu>
// 
// Started on  Tue May 23 09:35:42 2017 Lebrun Kilian
// Last update Tue May 23 19:16:31 2017 DaZe
//

#include <unistd.h>
#include "Convert.hpp"
#include "AI.hpp"

AI::AI()
{
}

AI::AI(std::pair<int, int> const& pos)
{
  _car = std::shared_ptr<Car>(new Car);
  _car->setPosMap(pos);
}

void			AI::chooseAction()
{
  detectLine();
  _car.get()->move();
}

bool			AI::isLine(int pos)
{
  if (_map[Convert::coordToPos<int>(_car.get()->getPosMap()) + pos].get()->getType()
      == Element::EType::LINE
      && Convert::coordToPos<int>(_car.get()->getPosMap()) + pos != _prevPos)
    {
      std::cout << "POS + X" << Convert::coordToPos<int>(_car.get()->getPosMap()) + pos << std::endl;
      return (true);
    }
  return (false);
}

void			AI::detectLine()
{
  std::cout << "ANGLE = " << _car.get()->getAbsoluteAngle() << std::endl;
  std::cout << "POS MAP = " << Convert::coordToPos<int>(_car.get()->getPosMap()) << std::endl;
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
      _car.get()->turnLeft();
    }
}

void			AI::up()
{
  if (isLine(-50) == true)
    {
      std::cout << "UP" << std::endl;
      _car.get()->accelerate();
    }
}

void			AI::upRight()
{
  if (isLine(-49) == true)
    {
      std::cout << "UP RIGHT" << std::endl;
      _car.get()->turnRight();
    }
}

void			AI::left()
{
  if (isLine(-1) == true)
    {
      std::cout << "LEFT" << std::endl;
      _car.get()->accelerate();
    }
}

void			AI::right()
{
  if (isLine(1) == true)
    {
      std::cout << "RIGHT" << std::endl;
      _car.get()->accelerate();
    }
}

void			AI::downLeft()
{
  if (isLine(49) == true)
    {
      std::cout << "DOWN LEFT" << std::endl;
      _car.get()->turnLeft();
    }
}

void			AI::down()
{
  if (isLine(50) == true)
    {
      std::cout << "DOWN" << std::endl;
      _car.get()->accelerate();
    }
}

void			AI::downRight()
{
  if (isLine(51) == true)
    {
      std::cout << "DOWN RIGHT" << std::endl;
      _car.get()->turnRight();
    }
}

void			AI::setMap(std::vector<std::shared_ptr<Element>> const& map)
{
  _map = map;
}

std::shared_ptr<Car>		AI::getCar() const
{
  return (_car);
}
