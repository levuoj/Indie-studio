//
// Leaderboard.cpp for Leaderboard in /home/pashervz/Epitech/C++/Indie/Indie_studio/sources/Menu
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Tue Jun 13 12:15:45 2017 Pashervz
// Last update Thu Jun 15 10:23:11 2017 Pashervz
//

#include "Leaderboard.hpp"

DType				Leaderboard::transferKey(irr::EKEY_CODE key)
{
  switch (key)
    {
    case irr::KEY_ESCAPE:
      return (MAIN_MENU);
    default:
      break;
    }
  return (LEADERBOARD);
}
