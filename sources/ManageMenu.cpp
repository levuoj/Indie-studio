//
// ManageMenu.cpp for ManageMenu in /home/pashervz/Epitech/C++/Indie/Indie_studio/sources
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Tue May  9 13:30:16 2017 Pashervz
// Last update Tue May  9 13:37:21 2017 Pashervz
//

#include "ManageMenu.hpp"

AMenu const &		ManageMenu::getCurrentMenu() const
{
  return (_currentMenu);
}

void			ManageMenu::setCurrentMenu(AMenu const & menu)
{
  this->_currentMenu = menu;
}
