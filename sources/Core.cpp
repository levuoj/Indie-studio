//
// Core.cpp for Core in /home/pashervz/Epitech/C++/Indie/Indie_studio/sources
//
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
//
// Started on  Wed May 10 13:12:37 2017 Pashervz
// Last update Tue May 23 10:24:03 2017 Pashervz
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
  while (this->_graphic->running())
    {
      this->_menu->transferKey(receiver.getKey());
      receiver.setKey(irr::KEY_OEM_8);
      this->_menu->notify();
    }
}
