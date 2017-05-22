//
// Core.cpp for Core in /home/pashervz/Epitech/C++/Indie/Indie_studio/sources
//
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
//
// Started on  Wed May 10 13:12:37 2017 Pashervz
// Last update Mon May 22 10:17:54 2017 Pierre Zawadil
//

#include <unistd.h>
#include <iostream>
#include <irrlicht.h>
#include "EventReceiver.hpp"
#include "Core.hpp"
#include "MainMenu.hpp"

Core::Core()
{
  this->_menu = std::unique_ptr<MainMenu>(new MainMenu());
  this->_graphic = std::unique_ptr<Graphic>(new Graphic());
  this->_menu->setObserver(this->_graphic.get());
}

void			Core::launch()
{
  EventReceiver		receiver;

  this->_graphic->setEventReceiver(&receiver);

  //irr::u32 then = this->_graphic->_device->getTimer()->getTime();
  //irr::f32 lag = 0.f;
  //const irr::f32 MS_PER_UPDATE = 16.f; // PAS SUR DE CA

  while (this->_graphic->running())
    {
      // const irr::u32 now = this->_graphic->_device->getTimer()->getTime();
      //      const irr::f32 elapsed = (irr::f32)(now - then) / 1000.f;
      // then = now;
      // lag += elapsed;
      //while (lag <= MS_PER_UPDATE)
      //{
      this->_menu->transferKey(receiver.getKey());
      //lag -= MS_PER_UPDATE;
      //}
      receiver.setKey(irr::KEY_F24);

      this->_menu->notify();

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
