//
// MainMenu.cpp for MainMenu in /home/pashervz/Epitech/C++/Indie/Indie_studio/sources
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Tue May  9 15:18:43 2017 Pashervz
// Last update Tue May 16 16:50:02 2017 Pierre Zawadil
//

#include <memory>
#include "Button.hpp"
#include "MainMenu.hpp"

MainMenu::MainMenu() : AMenu("Main Menu", MAIN_MENU)
{
  this->_map.push_back(std::unique_ptr<Button>(new Button("Play")));
  this->_map.push_back(std::unique_ptr<Button>(new Button("Leaderboard")));
  this->_map.push_back(std::unique_ptr<Button>(new Button("Options")));
  this->_map.push_back(std::unique_ptr<Button>(new Button("Exit")));
  static_cast<Button *>(this->_map[0].get())->setIsSelected(true);
}

void		MainMenu::goDown()
{
  for (auto it = this->_map.begin() ; it != this->_map.end() ; ++it)
    {
      if (static_cast<Button *>((*it).get())->getIsSelected() == true &&
	  (it + 1) != this->_map.end())
	{
	  static_cast<Button *>((*it).get())->setIsSelected(false);
	  ++it;
	  static_cast<Button *>((*it).get())->setIsSelected(true);
	}
    }
}

void		MainMenu::goUp()
{
  for (auto it = this->_map.begin() ; it != this->_map.end() ; ++it)
    {
      if (static_cast<Button *>((*it).get())->getIsSelected() == true &&
	  it != this->_map.begin())
	{
	  static_cast<Button *>((*it).get())->setIsSelected(false);
	  --it;
	  static_cast<Button *>((*it).get())->setIsSelected(true);
	}
    }
}

DType		MainMenu::select() const
{
  for (auto it = this->_map.begin() ; it != this->_map.end() ; ++it)
   {
     if (static_cast<Button *>((*it).get())->getIsSelected() == true)
	return (this->_corresMap.at(static_cast<Button *>((*it).get())->getContent()));
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
