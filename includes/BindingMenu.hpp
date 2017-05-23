//
// BindingMenu.hpp for BindingMenu in /home/pashervz/Epitech/C++/Indie/Indie_studio/includes
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Mon May 22 17:09:23 2017 Pashervz
// Last update Mon May 22 17:12:52 2017 Pashervz
//

#pragma once

#include "AMenu.hpp"

class BindingMenu : public AMenu
{
public:
  BindingMenu();
  ~BindingMenu() {}
  DType			transferKey(irr::EKEY_CODE);
  DType			select();
};
