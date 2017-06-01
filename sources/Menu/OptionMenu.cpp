//
// OptionMenu.cpp for OptionMenu in /home/pashervz/Epitech/C++/Indie/Indie_studio/sources
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Mon May 22 13:28:27 2017 Pashervz
// Last update Thu Jun  1 14:59:54 2017 Pashervz
//

#include <memory>
#include "Button.hpp"
#include "PlayerButton.hpp"
#include "OptionMenu.hpp"

OptionMenu::OptionMenu() : AMenu("Options", OPTIONS)
{
  this->_type = DType::OPTIONS;
  this->_map.push_back(std::shared_ptr<PlayerButton>(new PlayerButton(L"p1", "assets/deathStar.jpg", Button::BType::PLAYER, "P1")));
  this->_map.push_back(std::shared_ptr<PlayerButton>(new PlayerButton(L"p2", "assets/deathStar.jpg", Button::BType::PLAYER, "P2")));
  this->_map.push_back(std::shared_ptr<PlayerButton>(new PlayerButton(L"p3", "assets/deathStar.jpg", Button::BType::PLAYER, "P3"))); 
  this->_map.push_back(std::shared_ptr<PlayerButton>(new PlayerButton(L"p4", "assets/deathStar.jpg", Button::BType::PLAYER, "P4")));
  this->_map.push_back(std::shared_ptr<Button>(new Button(L"on", "assets/deathStar.jpg", Button::BType::SWITCH)));
  this->_map.push_back(std::shared_ptr<Button>(new Button(L"off", "assets/deathStar.jpg", Button::BType::SWITCH)));
  static_cast<Button *>(this->_map[0].get())->setIsSelected(true);
}

DType			OptionMenu::select()
{
  std::wstring		on(L"on");
  std::wstring		off(L"off");
  
  for (auto it = this->_map.begin() ; it != this->_map.end() ; ++it)
    {
      if (static_cast<Button *>((*it).get())->getIsSelected() == true)
	{
	  if (static_cast<Button *>((*it).get())->getButtonType()
	      == Button::BType::SWITCH)
	    {
	      if (static_cast<Button *>((*it).get())->getContent() == on)
		static_cast<Button *>((*it).get())->setContent(off);
	      else
		static_cast<Button *>((*it).get())->setContent(on);
	      break;
	    }
	  else if (static_cast<Button *>((*it).get())->getButtonType()
		   == Button::BType::PLAYER)
	    {
	      this->_player = static_cast<PlayerButton *>((*it).get())->getName();
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
