//
// Core.cpp for Core in /home/pashervz/Epitech/C++/Indie/Indie_studio/sources
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Wed May 10 13:12:37 2017 Pashervz
// Last update Sat May 13 16:41:56 2017 Pashervz
//

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

  irr::IrrlichtDevice* device = createDevice(irr::video::EDT_SOFTWARE,
					     irr::core::dimension2d<irr::u32>(640, 480), 16, false, false, false, &receiver);
  
  if (device == 0)
    return ; // could not create selected driver.
  
  irr::video::IVideoDriver* driver = device->getVideoDriver();
  irr::scene::ISceneManager* smgr = device->getSceneManager();

  while (device->run())
    {
      driver->beginScene(true, true, irr::video::SColor(255, 100, 101, 140));
      
      if (receiver.IsKeyDown(irr::KEY_KEY_W))
	std::cout << "Ma grosse bite en marbre !! <<<3" << std::endl;
      smgr->drawAll();
      
      driver->endScene();
    }
  device->drop();
  // else if(receiver.IsKeyDown(irr::KEY_KEY_S))


  // if(receiver.IsKeyDown(irr::KEY_KEY_A))

  // else if(receiver.IsKeyDown(irr::KEY_KEY_D))

}
