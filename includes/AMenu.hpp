//
// AMenu.hpp for AMenu in /home/pashervz/Epitech/C++/Indie/Indie_studio/includes
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Tue May  9 12:26:19 2017 Pashervz
// Last update Mon May 15 16:41:53 2017 Pashervz
//

#pragma once

#include <irrlicht.h>
#include <unordered_map>
#include "Observable.hpp"
#include "Utils.hpp"

class AMenu : public Observable
{
protected:
  std::string						_name;
  std::unordered_map<std::string, DType>                _corresMap =
    {
      {"Main Menu", MAIN_MENU},                                 
      {"PLAY", PLAY},                                                                             
      {"OPTIONS", OPTIONS},                                                                            
      {"LEADERBOARD", LEADERBOARD}
    };
  
public:
  AMenu(std::string const & name, DType type) : Observable(type), _name(name) {}
  virtual ~AMenu() {}
  std::string const &	getName() const
  {
    return (_name);
  }
  virtual DType	transferKey(irr::EKEY_CODE) = 0;
};
