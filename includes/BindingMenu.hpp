//
// BindingMenu.hpp for BindingMenu in /home/pashervz/Epitech/C++/Indie/Indie_studio/includes
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Mon May 22 17:09:23 2017 Pashervz
// Last update Tue May 23 11:57:27 2017 Pashervz
//

#pragma once

#include "AMenu.hpp"

class BindingMenu : public AMenu
{
private:
  std::wstring		_player;
  
public:
  BindingMenu(std::wstring const & player);
  ~BindingMenu() {}
  DType			transferKey(irr::EKEY_CODE);
  void			select();
};
