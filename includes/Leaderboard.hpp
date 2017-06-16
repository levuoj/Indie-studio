//
// Leaderboard.hpp for Leaderboard in /home/pashervz/Epitech/C++/Indie/Indie_studio/includes
//
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
//
// Started on  Tue Jun 13 12:05:24 2017 Pashervz
// Last update Fri Jun 16 13:35:17 2017 jouvel
//

#pragma once

#include "AMenu.hpp"

class Leaderboard : public AMenu
{
public:
  Leaderboard(Music *music) : AMenu ("Leaderboard", LEADERBOARD, music)
  {
    _type = LEADERBOARD;
  }
  virtual ~Leaderboard() {}
  DType					transferKey(irr::EKEY_CODE);
};
