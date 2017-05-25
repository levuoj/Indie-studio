//
// AI.cpp for  in /home/Kilian/Rendu/C++/Indie_studio
// 
// Made by Lebrun Kilian
// Login   <kilian.lebrun@epitech.eu>
// 
// Started on  Tue May 23 09:35:42 2017 Lebrun Kilian
// Last update Thu May 25 17:10:06 2017 DaZe
//

#include <unistd.h>
#include "Convert.hpp"
#include "AI.hpp"

AI::AI() : _idx(0)
{
}
 
AI::AI(std::pair<int, int> const& pos) : _idx(0)
{
  _car = std::shared_ptr<Car>(new Car(pos));
}

void			AI::chooseAction()
{
   if (_car->getSpeed() <= Car::_maxSpeed)
    _car->accelerate();
  if (_map[Convert::coordToPos<int>(_car->getPosMap()) + 3]->getType()
      == Element::EType::BLOCK && _idx != 2)
    _idx = 1;
  if (_idx == 1 && _car->getAngle() != -90.0f)
    _car->turnRight();
  if (_idx == 1 && _map[Convert::coordToPos<int>(_car->getPosMap()) + 300]->getType()
    == Element::EType::BLOCK)
    _idx = 2;
  if (_idx == 2 && _car->getAngle() != -180.0f)
    _car->turnRight();
  if (_idx == 2 && _map[Convert::coordToPos<int>(_car->getPosMap()) - 4]->getType()
    == Element::EType::BLOCK)
    _idx = 3;
  if (_idx == 2 && _car->getAngle() != -180.0f)
    _car->turnRight();
  _car.get()->move();
}

void			AI::setMap(std::vector<std::shared_ptr<Element>> const& map)
{
  _map = map;
}

std::shared_ptr<Car>		AI::getCar() const
{
  return (_car);
}
