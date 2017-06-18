//
// OptionMenu.hpp for OptionMenu in /home/pashervz/Epitech/C++/Indie/Indie_studio/includes
//
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
//
// Started on  Mon May 22 13:33:06 2017 Pashervz
// Last update Fri Jun 16 13:29:48 2017 jouvel
//

#pragma once

#include "AMenu.hpp"

class OptionMenu : public AMenu
{
private:
  std::string			_player;

public:
  OptionMenu(Music *);
  virtual ~OptionMenu() {}
  DType				transferKey(irr::EKEY_CODE);
  DType				select();
  std::string const &		getPlayer() const
  {
    return (_player);
  }
};
