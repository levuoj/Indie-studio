//
// Observable.cpp for Observable in /home/pashervz/Epitech/C++/Indie/Indie_studio/sources
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Mon May  8 18:57:04 2017 Pashervz
// Last update Sun Jun 18 18:52:52 2017 Lebrun Kilian
//

#include "Observable.hpp"
#include "AObserver.hpp"

Observable::Observable() : _type(DType::NOTHING) {}

Observable::~Observable() {}

void			Observable::notify()
{
  this->_observer->actualize(*this);
}
