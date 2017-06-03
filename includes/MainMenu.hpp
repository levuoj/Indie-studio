//
// MainMenu.hpp for MainMenu in /home/pashervz/Epitech/C++/Indie/Indie_studio/includes
//
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
//
// Started on  Tue May  9 12:24:22 2017 Pashervz
// Last update Sat Jun  3 15:04:41 2017 Pashervz
//

#pragma once

#include "AMenu.hpp"

class MainMenu : public AMenu
{
  irrklang::ISoundEngine				*_engine;
  std::unordered_map<std::wstring, DType>                _corresMap =
    {
      {L"main Menu", MAIN_MENU},
      {L"play", GAME},
      {L"options", OPTIONS},
      {L"scores", LEADERBOARD},
      {L"exit", EXIT}
    };

public:
  MainMenu();
  ~MainMenu() {}
  DType		transferKey(irr::EKEY_CODE);
  DType		select() const;
};
