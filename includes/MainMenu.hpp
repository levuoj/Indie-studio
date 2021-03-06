//
// MainMenu.hpp for MainMenu in /home/pashervz/Epitech/C++/Indie/Indie_studio/includes
//
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
//
// Started on  Tue May  9 12:24:22 2017 Pashervz
// Last update Fri Jun 16 13:29:47 2017 jouvel
//

#pragma once

#include "AMenu.hpp"

class MainMenu : public AMenu
{
  std::unordered_map<std::wstring, DType>                _corresMap =
    {
      {L"main Menu", MAIN_MENU},
      {L"play", PLAY},
      {L"options", OPTIONS},
      {L"ranking", LEADERBOARD},
      {L"exit", EXIT}
    };

public:
  MainMenu(Music *);
  virtual ~MainMenu() {}
  DType		transferKey(irr::EKEY_CODE);
  DType		select() const;
};
