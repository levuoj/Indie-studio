//
// EndGame.hpp for EndGame in /home/pashervz/Epitech/C++/Indie/Indie_studio/includes
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Thu Jun 15 10:17:17 2017 Pashervz
// Last update Thu Jun 15 11:11:27 2017 Pashervz
//

#pragma once

#include "AMenu.hpp"

class EndGame : public AMenu
{
public:
  EndGame() : AMenu ("EndGame", ENDGAME)
  {
    _type = ENDGAME;
  }
  ~EndGame() {}
  DType				transferKey(irr::EKEY_CODE);
};
