//
// Convert.hpp for Convert.hpp in /home/tvigier/Indie_studio
// 
// Made by thomas vigier
// Login   <thomas.vigier@epitech.eu>
// 
// Started on  Fri May 12 17:06:19 2017 thomas vigier
// Last update Thu Jun 15 23:01:12 2017 DaZe
//

#pragma once

#include <utility>
#include "Car.hpp"

class		Convert
{
public:
  template <class T>
  static std::pair<T, T> const	posToCoord(int pos)
  {
    return (std::make_pair(pos % 60, (pos - pos % 60) / 60));
  }
  
  template <class T>
  static int				coordToPos(std::pair<T, T> const& coord)
  {
    return (coord.second * 60 + coord.first);
  }

  static Element::EType			strToCarType(std::string const &type)
  {
    switch (std::stoi(type))
      {
      case 1 :
	std::cout << "JE PARSE LE TYPE = " << type << std::endl;
	return (Element::EType::POD1);
	break ;
      case 2 :
	std::cout << "JE PARSE LE TYPE = " << type << std::endl;
	return (Element::EType::POD2);
	break ;
      case 3 :
	std::cout << "JE PARSE LE TYPE = " << type << std::endl;
	return (Element::EType::POD3);
	break ;
      case 4 :
	std::cout << "JE PARSE LE TYPE = " << type << std::endl;
	return (Element::EType::POD4);
	break ;
      default :
	break;
      }
    return (Element::EType::POD1);
  }

  static Car::EDirection			strToDir(std::string const &type)
  {
    switch (std::stoi(type))
      {
      case 0 :
	return (Car::EDirection::UP);
	break ;
      case 1 :
	return (Car::EDirection::UP_RIGHT);
	break ;
      case 2 :
	return (Car::EDirection::UP_LEFT);
	break ;
      case 3 :
	return (Car::EDirection::DOWN);
	break ;
      case 4 :
	return (Car::EDirection::DOWN_LEFT);
	break ;
      case 5 :
	return (Car::EDirection::DOWN_RIGHT);
	break ;
      case 6 :
	return (Car::EDirection::LEFT);
	break ;
      case 7 :
	return (Car::EDirection::RIGHT);
	break ;
      default :
	break;
      }
    return (Car::EDirection::RIGHT);
  }

  static bool				strToBool(std::string const &b)
  {
    if (b == "0")
      return (false);
    else
      return (true);
  }      

};
