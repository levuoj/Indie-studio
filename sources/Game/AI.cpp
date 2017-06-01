//
// AI.cpp for  in /home/Kilian/Rendu/C++/Indie_studio
// 
// Made by Lebrun Kilian
// Login   <kilian.lebrun@epitech.eu>
// 
// Started on  Tue May 23 09:35:42 2017 Lebrun Kilian
// Last update Thu Jun  1 11:46:26 2017 Lebrun Kilian
//

#include "Convert.hpp"
#include "AI.hpp"

AI::AI(std::pair<int, int> const& pos, const Element::EType type) : _idx(1)
{
  _car = std::shared_ptr<Car>(new Car(pos, type));
  /*  _functors.reserve(6);
  _functors[1] = [this](){this->part1();};
  _functors[2] = [this](){this->part2();};
  _functors[3] = [this](){this->part3();};
  _functors[4] = [this](){this->part4();};
  _functors[5] = [this](){this->part5();};
  _functors[6] = [this](){this->part6();}; */
}

void			AI::part1()
{
  if (this->_car->getSpeed() <= Car::_maxSpeed)
    this->_car->accelerate();
  else if (this->_map[Convert::coordToPos<int>(this->_car->getPosMap()) + 6]->getType()
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
  if (_car->getAbsoluteAngle() != 120.0f)
    _car->turnRight();
  else
    _idx = 6;
}

void			AI::part6()
{
  if (this->_map[Convert::coordToPos<int>(this->_car->getPosMap()) - 180]->getType()
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
  if (_car->getAbsoluteAngle() != 240.0f)
    _car->turnLeft();
  else
    _idx = 10;
}

void			AI::part10()
{
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
/*  std::cout << "ChooseAction" << std::endl;
  const auto it = _functors.find(_idx);
  
  if (it != _functors.end())
  it->second(); */
  
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
  
  //  part1();
  /*
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
     std::cout << _car->getAbsoluteAngle() << std::endl; */
  //   _car.get()->move();
}

void			AI::setMap(std::vector<std::shared_ptr<Element>> const& map)
{
  _map = map;
}

std::shared_ptr<Car>		AI::getCar() const
{
  return (_car);
}
