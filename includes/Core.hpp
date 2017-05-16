//
// Core.hpp for Core in /home/pashervz/Epitech/C++/Indie/Indie_studio/includes
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Mon May  8 19:43:34 2017 Pashervz
// Last update Mon May 15 22:12:34 2017 Pashervz
//

#pragma once

#include "AMenu.hpp"
#include "Graphic.hpp"

#define EXIT_ERROR 84

class Core
{
private:
  std::unique_ptr<Graphic>	_graphic;
  std::unique_ptr<AMenu>	_menu;
  
public:
  Core();
  ~Core() {}
  void		launch();
};
