//
// Leaderboard.cpp for Leaderboard in /home/pashervz/Epitech/C++/Indie/Indie_studio/sources/Menu
//
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
//
// Started on  Tue Jun 13 12:15:45 2017 Pashervz
// Last update Fri Jun 16 14:04:09 2017 jouvel
//

#include "Leaderboard.hpp"

DType				Leaderboard::transferKey(irr::EKEY_CODE key)
{
  switch (key)
    {
    case irr::KEY_ESCAPE:
      this->_music->playSound("assets/music/escape.wav");
      return (MAIN_MENU);
    default:
      break;
    }
  return (LEADERBOARD);
}
