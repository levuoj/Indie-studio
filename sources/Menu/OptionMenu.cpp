//1;4601;0c
// OptionMenu.cpp for OptionMenu in /home/pashervz/Epitech/C++/Indie/Indie_studio/sources
//
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
//
// Started on  Mon May 22 13:28:27 2017 Pashervz
// Last update Sun Jun 18 12:45:00 2017 Pashervz
//

#include <memory>
#include "Button.hpp"
#include "PlayerButton.hpp"
#include "OptionMenu.hpp"

OptionMenu::OptionMenu(Music *music) : AMenu("Options", OPTIONS, music)
{
  this->_type = DType::OPTIONS;
  this->_map.push_back(std::shared_ptr<PlayerButton>(new PlayerButton(L"p1", "assets/deathStar.jpg", Button::BType::PLAYER, "1")));
  this->_map.push_back(std::shared_ptr<PlayerButton>(new PlayerButton(L"p2", "assets/deathStar.jpg", Button::BType::PLAYER, "2")));
  this->_map.push_back(std::shared_ptr<PlayerButton>(new PlayerButton(L"p3", "assets/deathStar.jpg", Button::BType::PLAYER, "3")));
  this->_map.push_back(std::shared_ptr<PlayerButton>(new PlayerButton(L"p4", "assets/deathStar.jpg", Button::BType::PLAYER, "4")));
  this->_map.push_back(std::shared_ptr<Button>(new Button(L"on", "assets/deathStar.jpg", Button::BType::SWITCH)));
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
      this->_music->playSound("assets/music/selection.wav");
      return (this->select());
    case irr::KEY_ESCAPE:
      this->_music->playSound("assets/music/escape.wav");
      return (MAIN_MENU);
    default:
      break;
    }
  return (OPTIONS);
}
