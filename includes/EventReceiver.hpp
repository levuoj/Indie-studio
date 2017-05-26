//
// EventReceiver.hpp for EventReceiver in /home/pashervz/Epitech/C++/Indie/Indie_studio/includes
//
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
//
// Started on  Mon May 15 17:27:11 2017 Pashervz
// Last update Thu May 25 19:02:48 2017 Pierre Zawadil
//

#pragma once

#include <unistd.h>
#include <irrlicht.h>

class EventReceiver : public irr::IEventReceiver
{
  irr::EKEY_CODE			_key = irr::KEY_OEM_8;

public:
  EventReceiver() : _key(irr::KEY_OEM_8) {}
  virtual bool		OnEvent(const irr::SEvent & event)
  {
    if (event.EventType == irr::EET_KEY_INPUT_EVENT && event.KeyInput.PressedDown)
      {
	this->_key = event.KeyInput.Key;
	return (true);
      }
    return (false);
  }
  irr::EKEY_CODE	getKey() const { return _key; }
  void			setKey(irr::EKEY_CODE key) { _key = key; }
};
