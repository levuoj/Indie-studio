//
// Observable.cpp for Observable in /home/pashervz/Epitech/C++/Indie/Indie_studio/sources
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Mon May  8 18:57:04 2017 Pashervz
// Last update Mon May  8 18:57:06 2017 Pashervz
//

#include <iostream>
#include "Observable.hpp"
#include "AObserver.hpp"

Observable::Observable() {}

Observable::~Observable() {}

void		Observable::notify()
{
  this->_observer->actualize(*this);
}

void		Observable::setObserver(AObserver *observer)
{
  this->_observer = observer;
}
