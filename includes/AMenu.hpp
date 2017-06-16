//
// AMenu.hpp for AMenu in /home/pashervz/Epitech/C++/Indie/Indie_studio/includes
//
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
//
// Started on  Tue May  9 12:26:19 2017 Pashervz
// Last update Fri Jun 16 13:29:00 2017 jouvel
//

#pragma once

#include <irrlicht.h>
#include <unordered_map>
#include "Observable.hpp"
#include "Utils.hpp"
#include "Music.hpp"

class AMenu : public Observable
{
protected:
  std::string						_name;
  Music							*_music;

public:
  AMenu(std::string const & name, DType type, Music *music) : Observable(type), _name(name), _music(music) {}
  virtual ~AMenu() {}
  std::string const &	getName() const
  {
    return (_name);
  }
  virtual DType	transferKey(irr::EKEY_CODE) = 0;
  void		goDown();
  void		goUp();
};
