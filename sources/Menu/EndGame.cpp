//
// EndGame.cpp for EndGame in /home/pashervz/Epitech/C++/Indie/Indie_studio/sources/Menu
//
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
//
// Started on  Thu Jun 15 10:21:36 2017 Pashervz
// Last update Fri Jun 16 14:03:07 2017 jouvel
//

#include "EndGame.hpp"

DType				EndGame::transferKey(irr::EKEY_CODE key)
{
  switch (key)
    {
    case irr::KEY_ESCAPE:
      this->_music->playSound("assets/music/escape.wav");
      return (MAIN_MENU);
    default:
      break;
    }
  return (ENDGAME);
}
