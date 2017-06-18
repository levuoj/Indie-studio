//
// AI.cpp for  in /home/Kilian/Rendu/C++/Indie_studio
//
// Made by Lebrun Kilian
// Login   <kilian.lebrun@epitech.eu>
//
// Started on  Tue May 23 09:35:42 2017 Lebrun Kilian
// Last update Sun Jun 18 14:31:34 2017 DaZe
//

#include "Convert.hpp"
#include "AI.hpp"

AI::AI(std::pair<int, int> posMap, const Element::EType type, float angle, short int lap, bool isFinished, Car::EDirection dir, int idx) : _idx(idx)
{
  _car = std::shared_ptr<Car>(new Car(posMap, type, angle, lap, isFinished, dir));
}

AI::AI(std::pair<int, int> const& pos, const Element::EType type) : _idx(1)
{
  _car = std::shared_ptr<Car>(new Car(pos, type));
}

void			AI::part1()
{
  if (_car->getType() == Element::EType::POD3 && _car->getLap() != 0)
    {
      if (_map[Convert::coordToPos<int>(_car->getPosMap()) + 7]->getType()
	  == Element::EType::BLOCK)
	_idx = 2;
    }
  else
    if (_map[Convert::coordToPos<int>(_car->getPosMap()) + 6]->getType()
	== Element::EType::BLOCK)
      _idx = 2;
}

void			AI::part2()
{
  if (this->_car->getAbsoluteAngle() != 270.0f)
    this->_car->turnRight();
  else
    this->_idx = 3;
}

void			AI::part3()
{
  if (_car->getType() == Element::EType::POD3)
    {
      if (_map[Convert::coordToPos<int>(_car->getPosMap()) + 300]->getType()
      == Element::EType::BLOCK && _idx != 0)
	_idx = 4;
    }
  else
    if (_map[Convert::coordToPos<int>(_car->getPosMap()) + 240]->getType()
	== Element::EType::BLOCK && _idx != 0)
      _idx = 4;
}

void			AI::part4()
{
  if (_car->getAbsoluteAngle() != 180.0f)
    _car->turnRight();
  else if (this->_map[Convert::coordToPos<int>(this->_car->getPosMap()) - 5]->getType()
	   == Element::EType::BLOCK)
    _idx = 5;
}

void			AI::part5()
{
  if (_car->getType() == Element::EType::POD3)
    {
      if (_car->getAbsoluteAngle() != 140.0f)
	_car->turnRight();
      else
	_idx = 6;
    }
  else
    {
      if (_car->getAbsoluteAngle() != 120.0f)
	_car->turnRight();
      else
	_idx = 6;
    }
}

void			AI::part6()
{
  if (_car->getType() == Element::EType::POD3)
    {
      if (this->_map[Convert::coordToPos<int>(this->_car->getPosMap()) - 240]->getType()
	  == Element::EType::BLOCK)
	_idx = 7;
    }
  else
    if (this->_map[Convert::coordToPos<int>(this->_car->getPosMap()) - 120]->getType()
	== Element::EType::BLOCK)
      _idx = 7;
}

void			AI::part7()
{
  if (_car->getAbsoluteAngle() != 180.0f)
    _car->turnLeft();
  else
    _idx = 8;
}

void			AI::part8()
{
  if (this->_map[Convert::coordToPos<int>(this->_car->getPosMap()) - 5]->getType()
      == Element::EType::BLOCK)
    _idx = 9;
}

void			AI::part9()
{
  if (_car->getType() == Element::EType::POD3)
    {
      if (_car->getAbsoluteAngle() != 220.0f)
	_car->turnLeft();
      else
	_idx = 10;
    }
  else
    {
      if (_car->getAbsoluteAngle() != 240.0f)
	_car->turnLeft();
      else
	_idx = 10;
    }
}

void			AI::part10()
{
  if (_car->getType() == Element::EType::POD3)
    {
      if (this->_map[Convert::coordToPos<int>(this->_car->getPosMap()) + 295]->getType()
	  == Element::EType::BLOCK)
	_idx = 11;
    }
  else
    if (this->_map[Convert::coordToPos<int>(this->_car->getPosMap()) + 177]->getType()
	== Element::EType::BLOCK)
      _idx = 11;
}

void			AI::part11()
{
  if (_car->getAbsoluteAngle() != 180.0f)
    _car->turnRight();
  else
    _idx = 12;
}

void			AI::part12()
{
  if (_car->getType() == Element::EType::POD3)
    {
      if (this->_map[Convert::coordToPos<int>(this->_car->getPosMap()) - 7]->getType()
	  == Element::EType::BLOCK)
	_idx = 13;
    }
  else
    if (this->_map[Convert::coordToPos<int>(this->_car->getPosMap()) - 5]->getType()
	== Element::EType::BLOCK)
      _idx = 13;
}

void			AI::part13()
{
  if (_car->getAbsoluteAngle() != 90.0f)
    _car->turnRight();
  else
    _idx = 14;
}

void			AI::part14()
{
  if (_car->getType() == Element::EType::POD3)
    {
      if (this->_map[Convert::coordToPos<int>(this->_car->getPosMap()) - 360]->getType()
	  == Element::EType::BLOCK)
	_idx = 15;
    }
  else if (_car->getType() == Element::EType::POD1)
    {
      if (this->_map[Convert::coordToPos<int>(this->_car->getPosMap()) - 300]->getType()
	  == Element::EType::BLOCK)
	_idx = 15;
    }
  else
    if (this->_map[Convert::coordToPos<int>(this->_car->getPosMap()) - 240]->getType()
	== Element::EType::BLOCK)
      _idx = 15;
}

void			AI::part15()
{
  if (_car->getAbsoluteAngle() != 0.0f)
    _car->turnRight();
  else
    _idx = 1;
}

void			AI::chooseAction()
{
  /*  const auto it = _functors.find(_idx);

  if (it != _functors.end())
  it->second(); */

  if (_car->getType() == Element::EType::POD4)
    {
      if (_car->getSpeed() <= _car->getMaxSpeed() - 60)
	_car->accelerate();
    }
  else
    if (_car->getSpeed() <= _car->getMaxSpeed())
      _car->accelerate();
  switch (_idx)
    {
    case 1:
      part1();
      break ;
    case 2:
      part2();
      break ;
    case 3:
      part3();
      break ;
    case 4:
      part4();
      break ;
    case 5:
      part5();
      break ;
    case 6:
      part6();
      break ;
    case 7:
      part7();
      break ;
    case 8:
      part8();
      break ;
    case 9:
      part9();
      break ;
    case 10:
      part10();
      break ;
    case 11:
      part11();
      break ;
    case 12:
      part12();
      break ;
    case 13:
      part13();
      break ;
    case 14:
      part14();
      break ;
    case 15:
      part15();
    default:
      break ;
    }
  _car.get()->move();
}

void			AI::setMap(std::vector<std::shared_ptr<Element>> const& map)
{
  _map = map;
}

void			AI::setArroundingCar(const std::array<Element::EType, 8> arr)
{
  this->_car->setArrounding(arr);
}

std::shared_ptr<Car>		AI::getCar() const
{
  return (_car);
}

int			AI::getIdx() const
{
  return (_idx);
}
