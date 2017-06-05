//
// PlayMenu.hpp for PlayMenu.hpp in /home/pashervz/Epitech/C++/Indie/Indie_studio/includes
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Sat Jun  3 15:51:03 2017 Pashervz
// Last update Sat Jun  3 19:46:23 2017 Pashervz
//

#pragma once

#include "AMenu.hpp"

class PlayMenu : public AMenu
{
private:
  std::wstring				_save;
  int					_nbPlayer;
  std::vector<std::wstring>		_savesName;
  
public:
  PlayMenu();
  ~PlayMenu() {}
  void			openSave(std::string const &);
  bool			getSaveName(std::string const &);
  DType			select();
  DType			transferKey(irr::EKEY_CODE);
  std::wstring const &	getSave() const
  {
    return (_save);
  }
  int			getNbPlayer() const
  {
    return (_nbPlayer);
  }
};
