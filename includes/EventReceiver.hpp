//
// EventReceiver.hpp for indie in /home/zgore/Projects/cpp_2017/Indie_studio
// 
// Made by Pierre Zawadil
// Login   <pierre.zawadil@epitech.eu>
// 
// Started on  Wed May 10 16:17:39 2017 Pierre Zawadil
// Last update Wed May 10 16:24:39 2017 Pierre Zawadil
//

#ifndef EVENTRECEIVER_HPP_
# define EVENTRECEIVER_HPP_

#include <irrlicht.h>

class EventReceiver : public irr::IEventReceiver
{
  private:
  // We use this array to store the current state of each key
  bool KeyIsDown[irr::KEY_KEY_CODES_COUNT];
public:
  EventReceiver()
  {
    for (irr::u32 i = 0; i < irr::KEY_KEY_CODES_COUNT; ++i)
      KeyIsDown[i] = false;
  }

  // This is the one method that we have to implement
  virtual bool OnEvent(const irr::SEvent& event)
  {
    // Remember whether each key is down or up
    if (event.EventType == irr::EET_KEY_INPUT_EVENT)
      KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;

    return false;
  }

  // This is used to check whether a key is being held down
  virtual bool IsKeyDown(irr::EKEY_CODE keyCode) const
  {
    return KeyIsDown[keyCode];
  }
};

#endif /* !EVENTRECEIVER_HPP_ */
