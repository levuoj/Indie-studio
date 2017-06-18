//
// MainMenu.cpp for MainMenu in /home/pashervz/Epitech/C++/Indie/Indie_studio/sources
//
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
//
// Started on  Tue May  9 15:18:43 2017 Pashervz
// Last update Sun Jun 18 19:44:17 2017 Lebrun Kilian
//

#include <memory>
#include "Error.hpp"
#include "Button.hpp"
#include "MainMenu.hpp"

MainMenu::MainMenu(Music *music) : AMenu("Main Menu", MAIN_MENU, music)
{
  this->_type = DType::MAIN_MENU;
  this->_map.push_back(std::shared_ptr<Button>(new Button(L"play", "", Button::BType::MENU)));
  this->_map.push_back(std::shared_ptr<Button>(new Button(L"ranking", "", Button::BType::MENU)));
  this->_map.push_back(std::shared_ptr<Button>(new Button(L"options", "", Button::BType::MENU)));
  this->_map.push_back(std::shared_ptr<Button>(new Button(L"exit", "", Button::BType::MENU)));
  static_cast<Button *>(this->_map[0].get())->setIsSelected(true);
}

DType		MainMenu::select() const
{
  for (auto it = this->_map.begin() ; it != this->_map.end() ; ++it)
   {
     if (static_cast<Button *>((*it).get())->getIsSelected() == true)
       return (this->_corresMap.at(static_cast<Button *>((*it).get())->getContent()));
    }
  return (MAIN_MENU);
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
      this->_music->playSound("assets/music/selection.wav");
      return (this->select());
    case irr::KEY_ESCAPE:
      this->_music->playSound("assets/music/escape.wav");
      return (EXIT);
    default:
      break;
    }
  return (MAIN_MENU);
}
