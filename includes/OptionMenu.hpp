//
// OptionMenu.hpp for OptionMenu in /home/pashervz/Epitech/C++/Indie/Indie_studio/includes
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Mon May 22 13:33:06 2017 Pashervz
// Last update Wed May 24 14:41:46 2017 Pashervz
//

#pragma once

#include "AMenu.hpp"

class OptionMenu : public AMenu
{
private:
  std::string			_player;
  
public:
  OptionMenu();
  ~OptionMenu() {}
  DType				transferKey(irr::EKEY_CODE);
  DType				select();
  std::wstring const &		getPlayer() const;
};
