//
// MainMenu.cpp for MainMenu in /home/pashervz/Epitech/C++/Indie/Indie_studio/sources
//
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
//
// Started on  Tue May  9 15:18:43 2017 Pashervz
// Last update Mon May 22 14:51:20 2017 Pashervz
//

#include <memory>
#include "Button.hpp"
#include "MainMenu.hpp"

MainMenu::MainMenu() : AMenu("Main Menu", MAIN_MENU)
{
  this->_type = DType::MAIN_MENU;
  this->_map.push_back(std::unique_ptr<Button>(new Button(L"Play", "assets/deathStar.jpg", Button::BType::MENU)));
  this->_map.push_back(std::unique_ptr<Button>(new Button(L"Leaderboard", "assets/deathStar.jpg", Button::BType::MENU)));
  this->_map.push_back(std::unique_ptr<Button>(new Button(L"Options", "assets/deathStar.jpg", Button::BType::MENU)));
  this->_map.push_back(std::unique_ptr<Button>(new Button(L"Exit", "assets/deathStar.jpg", Button::BType::MENU)));
  static_cast<Button *>(this->_map[0].get())->setIsSelected(true);
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
