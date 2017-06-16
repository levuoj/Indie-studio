//
// EndGame.hpp for EndGame in /home/pashervz/Epitech/C++/Indie/Indie_studio/includes
//
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
//
// Started on  Thu Jun 15 10:17:17 2017 Pashervz
// Last update Fri Jun 16 13:29:29 2017 jouvel
//

#pragma once

#include "AMenu.hpp"

class EndGame : public AMenu
{
public:
  EndGame(Music *music) : AMenu ("EndGame", ENDGAME, music)
  {
    _type = ENDGAME;
  }
  virtual ~EndGame() {}
  DType				transferKey(irr::EKEY_CODE);
};
