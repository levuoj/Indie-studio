//
// Core.cpp for Core in /home/pashervz/Epitech/C++/Indie/Indie_studio/sources
//
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
//
// Started on  Wed May 10 13:12:37 2017 Pashervz
// Last update Fri May 26 10:12:40 2017 Pierre Zawadil
//

#include <iostream>
#include <irrlicht.h>
#include "EventReceiver.hpp"
#include "Core.hpp"

Core::Core()
{
  this->_graphic = std::unique_ptr<Graphic>(new Graphic());
  // this->_toLoad = MAIN_MENU;
  // --- TEST --- //
  this->_toLoad = GAME;
  std::vector<std::array<irr::EKEY_CODE, 5>>  molft;
  molft.push_back({ irr::KEY_UP, irr::KEY_DOWN, irr::KEY_LEFT, irr::KEY_RIGHT, irr::KEY_SPACE});
  this->_game = std::unique_ptr<ManageGame>(new ManageGame(1, molft));
  this->_game->setObserver(this->_graphic.get());
  // --- TEST --- //
  this->_menu.emplace(MAIN_MENU, std::shared_ptr<AMenu>(new MainMenu));
  // this->_menu[this->_toLoad]->setObserver(this->_graphic.get());
}

void			Core::launch()
{
  EventReceiver		receiver;
  DType			loaded		= this->_toLoad;
  irr::u32		then		= this->_graphic->getTime();
  irr::f32		lag		= 0.f;
  const irr::f32	MS_PER_UPDATE	= 16.f;

  this->_graphic->setEventReceiver(&receiver);
  while (this->_graphic->running())
    {
      const irr::u32	now		= this->_graphic->getTime();
      const irr::f32	elapsed		= (irr::f32)(now - then);
      then = now;
      lag += elapsed;

      while (lag >= MS_PER_UPDATE)
	{
	  if (loaded != GAME)
	    {
	      std::cout << "MENU LOADED" << std::endl;
	      this->_toLoad = this->_menu[this->_toLoad]->transferKey(receiver.getKey());
	      if (loaded != this->_toLoad && this->_toLoad != GAME)
		this->_menu[this->_toLoad]->setObserver(this->_graphic.get());
	      else if (this->_toLoad == GAME)
		this->_game->setObserver(this->_graphic.get());
	    }
	  else
	    {
	      this->_toLoad = this->_game->transferKey(receiver.getKey());
	      std::cout << "GAME : " << GAME << std::endl;
	      std::cout << "GAME : " << this->_toLoad << std::endl;
	      if (this->_toLoad != GAME)
		this->_menu[this->_toLoad]->setObserver(this->_graphic.get());
	    }
	  lag -= MS_PER_UPDATE;
	  receiver.setKey(irr::KEY_OEM_8);
	  loaded = this->_toLoad;
	}

      if (this->_toLoad != GAME)
	this->_menu[this->_toLoad]->notify();
      else
	{
	  std::cout << "Game notify" << std::endl;
	  this->_game->notify();
	}
    }
}
