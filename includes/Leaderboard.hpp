//
// Leaderboard.hpp for Leaderboard in /home/pashervz/Epitech/C++/Indie/Indie_studio/includes
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Tue Jun 13 12:05:24 2017 Pashervz
// Last update Thu Jun 15 10:21:15 2017 Pashervz
//

#pragma once

#include "AMenu.hpp"

class Leaderboard : public AMenu
{
public:
  Leaderboard() : AMenu ("Leaderboard", LEADERBOARD)
  {
    _type = LEADERBOARD;
  }
  ~Leaderboard() {}
  DType					transferKey(irr::EKEY_CODE);
};
