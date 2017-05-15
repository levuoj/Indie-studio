//
// Core.hpp for Core in /home/pashervz/Epitech/C++/Indie/Indie_studio/includes
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Mon May  8 19:43:34 2017 Pashervz
// Last update Sat May 13 16:39:30 2017 Pashervz
//

#pragma once

#include <memory>
#include "Menu.hpp"
#include "Graphic.hpp"

#define EXIT_ERROR 84

class Core
{
private:
  std::unique_ptr<Graphic>	_graphic;
  std::unique_ptr<Menu>		_menu;
  
public:
  Core();
  ~Core() {}
  void		launch();
};
