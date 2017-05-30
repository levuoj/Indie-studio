//
// AI.cpp for  in /home/Kilian/Rendu/C++/Indie_studio
// 
// Made by Lebrun Kilian
// Login   <kilian.lebrun@epitech.eu>
// 
// Started on  Tue May 23 09:35:42 2017 Lebrun Kilian
// Last update Tue May 30 11:04:56 2017 DaZe
//

#include <unistd.h>
#include "Convert.hpp"
#include "AI.hpp"

AI::AI(std::pair<int, int> const& pos) : _idx(1)
{
  _car = std::shared_ptr<Car>(new Car(pos));
  /*  _functors.reserve(6);
  _functors[1] = [this](){this->part1();};
  _functors[2] = [this](){this->part2();};
  _functors[3] = [this](){this->part3();};
  _functors[4] = [this](){this->part4();};
  _functors[5] = [this](){this->part5();};
  _functors[6] = [this](){this->part6();}; */
  std::cout << "JE souis constructor AI" << std::endl;
}

void			AI::part1()
{
  std::cout << "PART 1" << std::endl;
  if (this->_car->getSpeed() <= Car::_maxSpeed)
    this->_car->accelerate();
  else if (this->_map[Convert::coordToPos<int>(this->_car->getPosMap()) + 4]->getType()
	   == Element::EType::BLOCK)
    _idx = 2;
  std::cout << "POS = " << Convert::coordToPos<int>(this->_car->getPosMap()) << std::endl; 
}

void			AI::part2()
{
  std::cout << "PART 2" << std::endl;
  if (this->_car->getAbsoluteAngle() != 270.0f)
    this->_car->turnRight();
  else
    this->_idx = 3;
}

void			AI::part3()
{
  std::cout << "PART 3" << std::endl;
  if (_map[Convert::coordToPos<int>(_car->getPosMap()) + 240]->getType()
      == Element::EType::BLOCK && _idx != 0)
    _idx = 4;
}

void			AI::part4()
{
  std::cout << "PART 4" << std::endl;
  if (_car->getAngle() != -180.0f)
    _car->turnRight();
  else
    _idx = 5;
}

void			AI::part5()
{
}

void			AI::part6()
{
}

void			AI::chooseAction()
{
/*  std::cout << "ChooseAction" << std::endl;
  const auto it = _functors.find(_idx);
  
  if (it != _functors.end())
  it->second(); */
  
  std::cout << "IDX = " << _idx << std::endl;
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
