//
// EventReceiver.hpp for indie in /home/zgore/Projects/cpp_2017/Indie_studio/includes
//
// Made by Pierre Zawadil
// Login   <pierre.zawadil@epitech.eu>
//
// Started on  Tue Jun 13 14:04:06 2017 Pierre Zawadil
// Last update Tue Jun 13 16:17:23 2017 Pierre Zawadil
//


#pragma once

#include <irrlicht.h>
#include <iostream>

class EventReceiver : public irr::IEventReceiver
{

protected:

  enum keyStatesENUM
    {
      UP,
      DOWN,
      PRESSED,
      RELEASED
    };

  enum processStateENUM
    {
      STARTED,
      ENDED
    };

  keyStatesENUM		keyState[irr::KEY_KEY_CODES_COUNT];
  processStateENUM	processState;
  irr::EKEY_CODE	key;

  virtual bool		OnEvent(irr::SEvent const& event)
  {
    bool		eventprocessed = false;

    if (event.EventType == irr::EET_KEY_INPUT_EVENT)
      {
	if (processState == STARTED)
	  {
	    if (event.KeyInput.PressedDown == true)
	      {
		this->key = event.KeyInput.Key;
		if (keyState[event.KeyInput.Key] != DOWN)
		  keyState[event.KeyInput.Key] = PRESSED;
		else
		  keyState[event.KeyInput.Key] = DOWN;
	      }
	    else
	      {
		if (keyState[event.KeyInput.Key] != UP)
		  keyState[event.KeyInput.Key] = RELEASED;
	      }
	  }
	eventprocessed = true;
      }
    return (eventprocessed);
  }

public:

  irr::EKEY_CODE	getKey()
  {
    irr::EKEY_CODE tmp = this->key;
    this->key = irr::KEY_OEM_8;
    return (tmp);
  }

  bool		keyPressed(int keycode) const
  {
    if (keyState[keycode] == PRESSED)
      return true;
    else
      return false;
  }

  bool		keyDown(int keycode) const
  {
    if (keyState[keycode] == DOWN || keyState[keycode] == PRESSED)
      return true;
    else
      return false;
  }

  bool		keyUp(int keycode) const
  {
    if (keyState[keycode] == UP || keyState[keycode] == RELEASED)
      return true;
    else
      return false;
  }

  bool		keyReleased(int keycode) const
  {
    if (keyState[keycode] == RELEASED)
      return true;
    else
      return false;
  }

  void		endEventProcess()
  {
    this->processState = ENDED;
  }

  void		startEventProcess()
  {
    this->processState = STARTED;

    for (int i = 0; i < irr::KEY_KEY_CODES_COUNT; i++)
      {
	if (this->keyState[i] == RELEASED)
	  this->keyState[i] = UP;

	if (this->keyState[i] == PRESSED)
	  this->keyState[i] = DOWN;
      }
  }

  void		init()
  {
    this->key = irr::KEY_OEM_8;
    for (int i = 0; i < irr::KEY_KEY_CODES_COUNT; i++)
      {
	this->keyState[i] = UP;
      }
  }
};
