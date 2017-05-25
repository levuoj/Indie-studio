//
// Core.cpp for Core in /home/pashervz/Epitech/C++/Indie/Indie_studio/sources
//
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
//
// Started on  Wed May 10 13:12:37 2017 Pashervz
// Last update Thu May 25 18:44:13 2017 Pierre Zawadil
//

#include <iostream>
#include <irrlicht.h>
#include "EventReceiver.hpp"
#include "Core.hpp"

Core::Core()
{
  this->_graphic = std::unique_ptr<Graphic>(new Graphic());
  this->_loadedMenu = MAIN_MENU;
  this->_menu.emplace(MAIN_MENU, std::shared_ptr<AMenu>(new MainMenu));
  this->_menu[this->_loadedMenu]->setObserver(this->_graphic.get());
}

void			Core::launch()
{
  EventReceiver		receiver;
  DType			lastMenu = this->_loadedMenu;

  this->_graphic->setEventReceiver(&receiver);

  irr::u32		then = this->_graphic->getTime();
  irr::f32		lag = 0.f;
  const irr::f32	MS_PER_UPDATE = 16.f;

  while (this->_graphic->running())
    {
      const irr::u32	now = this->_graphic->getTime();
      const irr::f32	elapsed = (irr::f32)(now - then) / 1000.f;
      then = now;
      lag += elapsed;
      while (lag >= MS_PER_UPDATE)
	{
	  this->_loadedMenu = this->_menu[this->_loadedMenu]->transferKey(receiver.getKey());
	  if (lastMenu != this->_loadedMenu)
	    {
	      this->_menu[this->_loadedMenu]->setObserver(this->_graphic.get());
	      lastMenu = this->_loadedMenu;
	    }
	  lag -= MS_PER_UPDATE;
	}
      receiver.setKey(irr::KEY_OEM_8);
      this->_menu[this->_loadedMenu]->notify();
    }
}



// TO DISPLAY FPS APROXIMATELY
// int lastFPS = -1;
// int fps = this->_graphic->_driver->getFPS(); // --> Aproximatif

// if (lastFPS != fps)
//	{
//	  irr::core::stringw tmp(L" Racer : [");
//	  tmp += this->_graphic->_driver->getName();
//	  tmp += L"] fps: ";
//	  tmp += fps;
//	  this->_graphic->_device->setWindowCaption(tmp.c_str());
//	  lastFPS = fps;
//	}
