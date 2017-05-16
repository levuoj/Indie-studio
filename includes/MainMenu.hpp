//
// MainMenu.hpp for MainMenu in /home/pashervz/Epitech/C++/Indie/Indie_studio/includes
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Tue May  9 12:24:22 2017 Pashervz
// Last update Mon May 15 16:42:00 2017 Pashervz
//

#pragma once

#include "AMenu.hpp"

class MainMenu : public AMenu
{
public:
  MainMenu();
  ~MainMenu() {}
  DType		transferKey(irr::EKEY_CODE);
  void		goDown();
  void		goUp();
  DType		select() const;
};
