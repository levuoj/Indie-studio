//
// Chrono.cpp for Chrono in /home/pashervz/Epitech/C++/Indie/Indie_studio/sources
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Wed May 10 14:02:13 2017 Pashervz
// Last update Sun Jun 18 18:50:51 2017 Lebrun Kilian
//

#include "Chrono.hpp"

Chrono::Chrono() : _time(0.0f), _isStopped(false) {}

void			Chrono::start()
{
  _isStopped = false;
}

void			Chrono::stop()
{
  _isStopped = true;
}

void			Chrono::incTime()
{
  if (!_isStopped)
    _time += 0.016f;
}

void			Chrono::setTime(const double time)
{
  _time = time;
}

double			Chrono::getTime() const
{
  return (_time);
}
