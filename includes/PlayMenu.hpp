//
// PlayMenu.hpp for PlayMenu.hpp in /home/pashervz/Epitech/C++/Indie/Indie_studio/includes
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Sat Jun  3 15:51:03 2017 Pashervz
// Last update Tue Jun  6 17:49:51 2017 Pashervz
//

#pragma once

#include "AMenu.hpp"

class PlayMenu : public AMenu
{
private:
  std::string				_save;
  int					_nbPlayer;
  std::vector<std::wstring>		_savesName;
  bool					_newGame;
  
public:
  PlayMenu();
  ~PlayMenu() {}
  void			openSave(std::string const &);
  bool			getSaveName(std::string const &);
  DType			select();
  DType			transferKey(irr::EKEY_CODE);
  void			assignContent();
  std::string const &	getSave() const
  {
    return (_save);
  }
  int			getNbPlayer() const
  {
    return (_nbPlayer);
  }
  bool			getNewGame() const
  {
    return (_newGame);
  }
};