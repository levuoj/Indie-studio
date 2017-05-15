//
// Chrono.hpp for Chrono in /home/pashervz/Epitech/C++/Indie/Indie_studio/includes
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Wed May 10 13:56:36 2017 Pashervz
// Last update Wed May 10 14:18:19 2017 Pashervz
//

#pragma once

class Chrono
{
private:
  double	_endingValue;
  
public:
  Chrono() {}
  ~Chrono() {}
  void		start();
  void		stop();

  double	getEndingValue() const
  {
    return (_endingValue);
  }

  void		setEndingValue(double value)
  {
    _endingValue = value;
  }
};
