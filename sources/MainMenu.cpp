//
// MainMenu.cpp for MainMenu in /home/pashervz/Epitech/C++/Indie/Indie_studio/sources
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Tue May  9 15:18:43 2017 Pashervz
// Last update Tue May 16 16:10:59 2017 Pashervz
//

#include <memory>
#include "Button.hpp"
#include "MainMenu.hpp"

MainMenu::MainMenu() : AMenu("Main Menu", MAIN_MENU)
{
  this->_map.push_back(new Button("Play"));
  this->_map.push_back(new Button("Leaderboard"));
  this->_map.push_back(new Button("Options"));
  this->_map.push_back(new Button("Exit"));
  static_cast<Button *>(this->_map[0])->setIsSelected(true);
}

void		MainMenu::goDown()
{
  for (auto it = this->_map.begin() ; it != this->_map.end() ; ++it)
    {
      if (static_cast<Button *>(*it)->getIsSelected() == true &&
	  (it + 1) != this->_map.end())
	{
	  static_cast<Button *>(*it)->setIsSelected(false);
	  ++it;
	  static_cast<Button *>(*it)->setIsSelected(true);
	}
    }
}

void		MainMenu::goUp()
{
  for (auto it = this->_map.begin() ; it != this->_map.end() ; ++it)
    {
      if (static_cast<Button *>(*it)->getIsSelected() == true &&
	  it != this->_map.begin())
	{
	  static_cast<Button *>(*it)->setIsSelected(false);
	  --it;
	  static_cast<Button *>(*it)->setIsSelected(true);
	}
    }
}

DType		MainMenu::select() const
{
  for (auto it : this->_map)
    {
      if (static_cast<Button *>(it)->getIsSelected() == true)
	return (this->_corresMap.at(static_cast<Button *>(it)->getContent()));
    }
  return (NOTHING);
}

DType		MainMenu::transferKey(irr::EKEY_CODE key)
{
  switch (key)
    {
    case irr::KEY_DOWN:
      this->goDown();
      break;
    case irr::KEY_UP:
      this->goUp();
      break;
    case irr::KEY_RETURN:
      return (this->select());
    case irr::KEY_ESCAPE:
      return (EXIT);
    default:
      break;
    }
  return (MAIN_MENU);
}
