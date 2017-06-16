//
// PauseMenu.hpp for PauseMenu in /home/pashervz/Epitech/C++/Indie/Indie_studio/includes
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Wed Jun  7 11:03:33 2017 Pashervz
// Last update Thu Jun 15 12:09:29 2017 Pashervz
//

#pragma once

#include "AMenu.hpp"
#include "ManageGame.hpp"

class PauseMenu : public AMenu
{
private:
  ManageGame			*_game;
  std::vector<std::wstring>	_savesName;
  
public:
  PauseMenu() : AMenu("Pause", PAUSE) {}
  PauseMenu(ManageGame *);
  virtual ~PauseMenu() {}
  void			openSave(std::string const &);
  bool			getSaveName(std::string const &);
  void			assignContent();
  DType			select();
  DType			transferKey(irr::EKEY_CODE);
  void			printVector();
};
