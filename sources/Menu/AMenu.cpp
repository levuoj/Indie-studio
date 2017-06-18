//
// AMenu.cpp for AMenu in /home/pashervz/Epitech/C++/Indie/Indie_studio/sources
//
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
//
// Started on  Mon May 22 14:04:36 2017 Pashervz
// Last update Fri Jun 16 13:42:18 2017 jouvel
//

#include <memory>
#include "Button.hpp"
#include "AMenu.hpp"

void		AMenu::goDown()
{
  this->_music->playSound("assets/music/mouvement.wav");
  for (auto it = this->_map.begin() ; it != this->_map.end() ; ++it)
    {
      if (static_cast<Button *>((*it).get())->getIsSelected() == true &&
	  (it + 1) != this->_map.end())
	{
	  static_cast<Button *>((*it).get())->setIsSelected(false);
	  ++it;
	  static_cast<Button *>((*it).get())->setIsSelected(true);
	  break;
	}
    }
}

void		AMenu::goUp()
{
  this->_music->playSound("assets/music/mouvement.wav");
  for (auto it = this->_map.begin() ; it != this->_map.end() ; ++it)
    {
      if (static_cast<Button *>((*it).get())->getIsSelected() == true &&
	  it != this->_map.begin())
	{
	  static_cast<Button *>((*it).get())->setIsSelected(false);
	  --it;
	  static_cast<Button *>((*it).get())->setIsSelected(true);
	  break;
	}
    }
}
