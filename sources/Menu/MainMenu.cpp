//
// MainMenu.cpp for MainMenu in /home/pashervz/Epitech/C++/Indie/Indie_studio/sources
//
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
//
// Started on  Tue May  9 15:18:43 2017 Pashervz
// Last update Fri Jun  2 17:49:25 2017 jouvel
//

#include <memory>
#include <irrKlang.h>
#include "Error.hpp"
#include "Button.hpp"
#include "MainMenu.hpp"

MainMenu::MainMenu() : AMenu("Main Menu", MAIN_MENU)
{
  _engine = irrklang::createIrrKlangDevice();
  if (!_engine)
    throw Error("irrklang can't be launched");

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
  std::cout << "Le prout c'est cool" << std::endl;
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
      _engine->play2D("assets/music/fx4.wav", false);
      break;
    case irr::KEY_UP:
      this->goUp();
      checker = false;
      _engine->play2D("assets/music/fx4.wav", false);
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
