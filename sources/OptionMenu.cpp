//
// OptionMenu.cpp for OptionMenu in /home/pashervz/Epitech/C++/Indie/Indie_studio/sources
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Mon May 22 13:28:27 2017 Pashervz
// Last update Mon May 22 17:36:08 2017 Pashervz
//

#include <memory>
#include "Button.hpp"
#include "OptionMenu.hpp"

OptionMenu::OptionMenu() : AMenu("Options", OPTIONS)
{
  this->_type = DType::OPTIONS;
  this->_map.push_back(std::unique_ptr<Button>(new Button(L"Player 1", "assets/deathStar.jpg", Button::BType::BINDING)));
  this->_map.push_back(std::unique_ptr<Button>(new Button(L"Player 2", "assets/deathStar.jpg", Button::BType::BINDING)));
  this->_map.push_back(std::unique_ptr<Button>(new Button(L"Player 3", "assets/deathStar.jpg", Button::BType::BINDING))); 
  this->_map.push_back(std::unique_ptr<Button>(new Button(L"Player 4", "assets/deathStar.jpg", Button::BType::BINDING)));
  this->_map.push_back(std::unique_ptr<Button>(new Button(L"ON", "assets/deathStar.jpg", Button::BType::SWITCH)));
  this->_map.push_back(std::unique_ptr<Button>(new Button(L"ON", "assets/deathStar.jpg", Button::BType::SWITCH)));
  static_cast<Button *>(this->_map[0].get())->setIsSelected(true);
}

DType			OptionMenu::select()
{
  std::wstring		on(L"ON");
  std::wstring		off(L"OFF");
  
  for (auto it = this->_map.begin() ; it != this->_map.end() ; ++it)
    {
      if (static_cast<Button *>((*it).get())->getIsSelected() == true)
	{
	  if (static_cast<Button *>((*it).get())->getButtonType() == Button::BType::SWITCH)
	    {
	      if (static_cast<Button *>((*it).get())->getContent() == on)
		static_cast<Button *>((*it).get())->setContent(off);
	      else
		static_cast<Button *>((*it).get())->setContent(on);
	      break;
	    }
	  else
	    {
	      this->_player = static_cast<Button *>((*it).get())->getContent();
	      return (BINDINGS);
	    }
	}
    }
  return (OPTIONS);
}

DType			OptionMenu::transferKey(irr::EKEY_CODE key)
{
  switch (key)
    {
    case irr::KEY_RIGHT:
      this->goDown();
      break;
    case irr::KEY_LEFT:
      this->goUp();
      break;
    case irr::KEY_RETURN:
      return (this->select());
      break;
    case irr::KEY_ESCAPE:
      return (MAIN_MENU);
      break;
    default:
      break;
    }
  return (OPTIONS);
}
