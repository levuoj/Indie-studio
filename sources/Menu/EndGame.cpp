//
// EndGame.cpp for EndGame in /home/pashervz/Epitech/C++/Indie/Indie_studio/sources/Menu
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Thu Jun 15 10:21:36 2017 Pashervz
// Last update Thu Jun 15 10:23:09 2017 Pashervz
//

#include "EndGame.hpp"

DType				EndGame::transferKey(irr::EKEY_CODE key)
{
  switch (key)
    {
    case irr::KEY_ESCAPE:
      return (MAIN_MENU);
    default:
      break;
    }
  return (ENDGAME);
}
