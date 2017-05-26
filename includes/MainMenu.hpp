//
// MainMenu.hpp for MainMenu in /home/pashervz/Epitech/C++/Indie/Indie_studio/includes
//
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
//
// Started on  Tue May  9 12:24:22 2017 Pashervz
// Last update Thu May 25 19:07:41 2017 Pierre Zawadil
//

#pragma once

#include "AMenu.hpp"

class MainMenu : public AMenu
{
  std::unordered_map<std::wstring, DType>                _corresMap =
    {
      {L"Main Menu", MAIN_MENU},
      {L"PLAY", PLAY},
      {L"OPTIONS", OPTIONS},
      {L"LEADERBOARD", LEADERBOARD}
    };

public:
  MainMenu();
  ~MainMenu() {}
  DType		transferKey(irr::EKEY_CODE);
  DType		select() const;
};
