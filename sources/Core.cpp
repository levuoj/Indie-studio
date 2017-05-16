//
// Core.cpp for Core in /home/pashervz/Epitech/C++/Indie/Indie_studio/sources
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Wed May 10 13:12:37 2017 Pashervz
// Last update Tue May 16 14:13:16 2017 Pashervz
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

  this->_graphic->_device->setEventReceiver(&receiver);
  
  int lastFPS = -1;
  // irr::u32 then = this->_graphic->_device->getTimer()->getTime();
  
  //const irr::f32 MOVEMENT_SPEED = 5.f;
  
  while (this->_graphic->_device->run())
    {
      // const irr::u32 now = this->_graphic->_device->getTimer()->getTime();
      //      const irr::f32 frameDeltaTime = (irr::f32)(now - then) / 1000.f;
      // then = now;
      this->_graphic->_driver->beginScene(true, true, irr::video::SColor(255, 100, 101, 140));
      this->_menu->transferKey(receiver.getKey());
      receiver.setKey(irr::KEY_F24);
      this->_graphic->_sceneManager->drawAll();
      this->_graphic->_driver->endScene();

      int fps = this->_graphic->_driver->getFPS();

      if (lastFPS != fps)
	{
	  irr::core::stringw tmp(L"Bite [");
	  tmp += this->_graphic->_driver->getName();
	  tmp += L"] fps: ";
	  tmp += fps;
	  this->_graphic->_device->setWindowCaption(tmp.c_str());
	  lastFPS = fps;
	}
    }
  this->_graphic->_device->drop();
}
