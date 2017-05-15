//
// Core.cpp for Core in /home/pashervz/Epitech/C++/Indie/Indie_studio/sources
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Wed May 10 13:12:37 2017 Pashervz
// Last update Wed May 10 16:28:12 2017 Pierre Zawadil
//

#include <iostream>
#include <irrlicht.h>
#include "EventReceiver.hpp"
#include "Core.hpp"

void			Core::launch()
{
  EventReceiver		receiver;
  this->_chrono.start();

  if(receiver.IsKeyDown(irr::KEY_KEY_W))
    std::cout << "Press me et Press moi sont sur un bateau ma bite tombe à l'eau qui reste il ?!!!!" << std::endl;

  // else if(receiver.IsKeyDown(irr::KEY_KEY_S))


  // if(receiver.IsKeyDown(irr::KEY_KEY_A))

  // else if(receiver.IsKeyDown(irr::KEY_KEY_D))

}
