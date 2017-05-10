//
// Core.hpp for Core in /home/pashervz/Epitech/C++/Indie/Indie_studio/includes
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Mon May  8 19:43:34 2017 Pashervz
// Last update Wed May 10 14:18:48 2017 Pashervz
//

#pragma once

#include "Chrono.hpp"

#define EXIT_ERROR 84

class Core
{
private:
  Chrono	_chrono;
  
public:
  Core()
  {
    this->_chrono.setEndingValue(5.0);
  }
  ~Core() {}
  void		launch();
};
