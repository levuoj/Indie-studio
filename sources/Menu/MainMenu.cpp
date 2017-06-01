//
// MainMenu.cpp for MainMenu in /home/pashervz/Epitech/C++/Indie/Indie_studio/sources
//
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
//
// Started on  Tue May  9 15:18:43 2017 Pashervz
// Last update Thu Jun  1 17:21:02 2017 Pashervz
//

#include <memory>
#include "Button.hpp"
#include "MainMenu.hpp"

MainMenu::MainMenu() : AMenu("Main Menu", MAIN_MENU)
{
  this->_type = DType::MAIN_MENU;
  this->_map.push_back(std::shared_ptr<Button>(new Button(L"play", "assets/deathStar.jpg", Button::BType::MENU)));
  this->_map.push_back(std::shared_ptr<Button>(new Button(L"scores", "assets/deathStar.jpg", Button::BType::MENU)));
  this->_map.push_back(std::shared_ptr<Button>(new Button(L"options", "assets/deathStar.jpg", Button::BType::MENU)));
  this->_map.push_back(std::shared_ptr<Button>(new Button(L"exit", "assets/deathStar.jpg", Button::BType::MENU)));
  static_cast<Button *>(this->_map[0].get())->setIsSelected(true);
}

DType		MainMenu::select() const
{
  for (auto it = this->_map.begin() ; it != this->_map.end() ; ++it)
   {
     if (static_cast<Button *>((*it).get())->getIsSelected() == true)
       {
	 return (this->_corresMap.at(static_cast<Button *>((*it).get())->getContent()));
       }
    }
  return (MAIN_MENU);
}

DType		MainMenu::transferKey(irr::EKEY_CODE key)
{
  static bool	checker = false;
  DType		selection = NOTHING;

  if (checker == false)
    {
      this->printer();
      std::cout << std::endl;
      checker = true;
    }
  switch (key)
    {
    case irr::KEY_DOWN:
      this->goDown();
      checker = false;
      break;
    case irr::KEY_UP:
      this->goUp();
      checker = false;
      break;
    case irr::KEY_RETURN:
      selection = this->select();
      return (selection);
    case irr::KEY_ESCAPE:
      return (EXIT);
    default:
      break;
    }
  return (MAIN_MENU);
}
