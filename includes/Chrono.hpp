//
// Chrono.hpp for Chrono in /home/pashervz/Epitech/C++/Indie/Indie_studio/includes
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Wed May 10 13:56:36 2017 Pashervz
// Last update Fri Jun  2 16:32:09 2017 DaZe
//

#pragma once

class Chrono
{
private:
  double	_time;
  bool		_isStopped;
  
public:
  
  void		start();
  void		stop();
  void		incTime();
  void		setTime(const double);
  double	getTime() const;

  Chrono();
  ~Chrono() = default;
};
