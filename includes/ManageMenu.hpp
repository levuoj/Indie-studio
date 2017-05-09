//
// ManageMenu.hpp for ManageMenu in /home/pashervz/Epitech/C++/Indie/Indie_studio/includes
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Mon May  8 19:44:05 2017 Pashervz
// Last update Tue May  9 13:31:26 2017 Pashervz
//

#pragma once

#include "Observable.hpp"
#include "AMenu.hpp"

class ManageMenu : public Observable
{
private:
  AMenu			_currentMenu;
  
public:
  ManageMenu() {}
  virtual ~ManageMenu() {}
  AMenu const &		getCurrentMenu() const;
  void			setCurrentMenu(AMenu const &);
};
