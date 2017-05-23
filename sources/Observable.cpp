//
// Observable.cpp for Observable in /home/pashervz/Epitech/C++/Indie/Indie_studio/sources
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Mon May  8 18:57:04 2017 Pashervz
// Last update Tue May 16 19:09:04 2017 Pierre Zawadil
//

#include <iostream>
#include "Observable.hpp"
#include "AObserver.hpp"

Observable::Observable() : _type(DType::NOTHING) {}

Observable::~Observable() {}

void			Observable::notify()
{
  this->_observer->actualize(*this);
}
