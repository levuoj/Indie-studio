//
// OptionMenu.hpp for OptionMenu in /home/pashervz/Epitech/C++/Indie/Indie_studio/includes
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Mon May 22 13:33:06 2017 Pashervz
// Last update Tue May 23 10:43:28 2017 Pashervz
//

#pragma once

#include "AMenu.hpp"

class OptionMenu : public AMenu
{
private:
  std::wstring			_player;
  
public:
  OptionMenu();
  ~OptionMenu() {}
  DType				transferKey(irr::EKEY_CODE);
  DType				select();
  std::wstring const &		getPlayer() const;
};
