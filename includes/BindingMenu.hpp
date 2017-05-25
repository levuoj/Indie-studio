//
// BindingMenu.hpp for BindingMenu in /home/pashervz/Epitech/C++/Indie/Indie_studio/includes
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Mon May 22 17:09:23 2017 Pashervz
// Last update Thu May 25 14:45:32 2017 Pashervz
//

#pragma once

#include <irrlicht/Keycodes.h> 
#include "AMenu.hpp"

class BindingMenu : public AMenu
{
private:
  std::unordered_map<std::string, irr::EKEY_CODE>	_corresMap =
    {
      {"A", irr::KEY_KEY_A},
      {"B", irr::KEY_KEY_B},
      {"C", irr::KEY_KEY_C},
      {"D", irr::KEY_KEY_D},
      {"E", irr::KEY_KEY_E},
      {"F", irr::KEY_KEY_F},
      {"G", irr::KEY_KEY_G},
      {"H", irr::KEY_KEY_H},
      {"I", irr::KEY_KEY_I},
      {"J", irr::KEY_KEY_J},
      {"K", irr::KEY_KEY_K},
      {"L", irr::KEY_KEY_L},
      {"M", irr::KEY_KEY_M},
      {"N", irr::KEY_KEY_N},
      {"O", irr::KEY_KEY_O},
      {"P", irr::KEY_KEY_P},
      {"Q", irr::KEY_KEY_Q},
      {"R", irr::KEY_KEY_R},
      {"S", irr::KEY_KEY_S},
      {"T", irr::KEY_KEY_T},
      {"U", irr::KEY_KEY_U},
      {"V", irr::KEY_KEY_V},
      {"W", irr::KEY_KEY_W},
      {"X", irr::KEY_KEY_X},
      {"Y", irr::KEY_KEY_Y},
      {"Z", irr::KEY_KEY_Z},
      {"SHIFT", irr::KEY_SHIFT},
      {"SPACE", irr::KEY_SPACE},
      {"CTRL", irr::KEY_CONTROL},
      {"ALT", irr::KEY_MENU},
      {"0", irr::KEY_NUMPAD0},
      {"1", irr::KEY_NUMPAD1},
      {"2", irr::KEY_NUMPAD2},
      {"3", irr::KEY_NUMPAD3},
      {"4", irr::KEY_NUMPAD4},
      {"5", irr::KEY_NUMPAD5},
      {"6", irr::KEY_NUMPAD6},
      {"7", irr::KEY_NUMPAD7},
      {"8", irr::KEY_NUMPAD8},
      {"9", irr::KEY_NUMPAD9}
    };

  std::unordered_map<std::string, std::function<void()>>	_defaultMap =
    {
      {"Player 1", std::bind(&BindingMenu::defaultP1, this)},
      {"Player 2", std::bind(&BindingMenu::defaultP2, this)},
      {"Player 3", std::bind(&BindingMenu::defaultP3, this)},
      {"Player 4", std::bind(&BindingMenu::defaultP4, this)}
    };
  
  std::string			_player;
  std::vector<irr::EKEY_CODE>	_bindings;
  std::vector<std::string>	_bindingsStrings;
  
public:
  BindingMenu(std::string const & player);
  ~BindingMenu() {}
  DType			transferKey(irr::EKEY_CODE);
  void			select(irr::EKEY_CODE);
  void			openBindingConf();
  bool			fillBindingMap(std::string const &);
  void			defaultFill(std::string const &);
  bool			getPlayerInfo(std::string const &);
  bool			stringsToKey(std::vector<std::string> const &);
  void			bindMode(Bind *, irr::EKEY_CODE);
  bool			checkKey(irr::EKEY_CODE key);
  void			defaultP1();
  void			defaultP2();
  void			defaultP3();
  void			defaultP4();
  std::wstring const	stringToWstring(std::string const &) const;
  void			saveChanges();
};
