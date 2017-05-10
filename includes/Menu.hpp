//
// AMenu.hpp for AMenu in /home/pashervz/Epitech/C++/Indie/Indie_studio/includes
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Tue May  9 12:26:19 2017 Pashervz
// Last update Wed May 10 12:02:00 2017 Pashervz
//

#pragma once

#include "Observable.hpp"

class Menu : public Observable
{
protected:
  std::string		_name;
  
public:
  Menu(std::string const & name) : _name(name) {}
  virtual ~Menu() {}
  std::string const &	getName() const
  {
    return (_name);
  }
};
