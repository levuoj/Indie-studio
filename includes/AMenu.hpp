//
// AMenu.hpp for AMenu in /home/pashervz/Epitech/C++/Indie/Indie_studio/includes
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Tue May  9 12:26:19 2017 Pashervz
// Last update Mon May 15 13:32:35 2017 Pierre Zawadil
//

#pragma once

#include "Observable.hpp"
#include "Utils.hpp"
#include <irrlicht.h>

class AMenu : public Observable
{
protected:
  std::string		_name;
  
public:
  AMenu(std::string const & name) : _name(name) {}
  virtual ~AMenu() {}
  std::string const &	getName() const
  {
    return (_name);
  }
  virtual DType	transferKey(irr::EKEY_CODE) = 0;
};
