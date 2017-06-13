//
// BindingMenu.hpp for BindingMenu in /home/pashervz/Epitech/C++/Indie/Indie_studio/includes
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Mon May 22 17:09:23 2017 Pashervz
// Last update Tue Jun 13 15:29:11 2017 Pashervz
//

#pragma once

#include <irrlicht.h>
#include <functional>
#include "ManageFile.hpp"
#include "Bind.hpp"
#include "AMenu.hpp"

class BindingMenu : public AMenu
{
private:
  std::unordered_map<std::wstring, irr::EKEY_CODE>	_corresMap =
    {
      {L"a", irr::KEY_KEY_A},
      {L"b", irr::KEY_KEY_B},
      {L"c", irr::KEY_KEY_C},
      {L"d", irr::KEY_KEY_D},
      {L"e", irr::KEY_KEY_E},
      {L"f", irr::KEY_KEY_F},
      {L"g", irr::KEY_KEY_G},
      {L"h", irr::KEY_KEY_H},
      {L"i", irr::KEY_KEY_I},
      {L"j", irr::KEY_KEY_J},
      {L"k", irr::KEY_KEY_K},
      {L"l", irr::KEY_KEY_L},
      {L"m", irr::KEY_KEY_M},
      {L"n", irr::KEY_KEY_N},
      {L"o", irr::KEY_KEY_O},
      {L"p", irr::KEY_KEY_P},
      {L"q", irr::KEY_KEY_Q},
      {L"r", irr::KEY_KEY_R},
      {L"s", irr::KEY_KEY_S},
      {L"t", irr::KEY_KEY_T},
      {L"u", irr::KEY_KEY_U},
      {L"v", irr::KEY_KEY_V},
      {L"w", irr::KEY_KEY_W},
      {L"x", irr::KEY_KEY_X},
      {L"y", irr::KEY_KEY_Y},
      {L"z", irr::KEY_KEY_Z},
      {L"shift", irr::KEY_LSHIFT},
      {L"space", irr::KEY_SPACE},
      {L"ctrl", irr::KEY_LCONTROL},
      {L"alt", irr::KEY_LMENU},
      {L"0", irr::KEY_NUMPAD0},
      {L"1", irr::KEY_NUMPAD1},
      {L"2", irr::KEY_NUMPAD2},
      {L"3", irr::KEY_NUMPAD3},
      {L"4", irr::KEY_NUMPAD4},
      {L"5", irr::KEY_NUMPAD5},
      {L"6", irr::KEY_NUMPAD6},
      {L"7", irr::KEY_NUMPAD7},
      {L"8", irr::KEY_NUMPAD8},
      {L"9", irr::KEY_NUMPAD9},
      {L"down", irr::KEY_DOWN},
      {L"up", irr::KEY_UP},
      {L"left", irr::KEY_LEFT},
      {L"right", irr::KEY_RIGHT}
    };

  std::unordered_map<std::string, std::function<void()>>	_defaultMap =
    {
      {"1", std::bind(&BindingMenu::defaultP1, this)},
      {"2", std::bind(&BindingMenu::defaultP2, this)},
      {"3", std::bind(&BindingMenu::defaultP3, this)},
      {"4", std::bind(&BindingMenu::defaultP4, this)}
    };

  bool				_bindMode = false;
  std::string			_player;
  std::vector<irr::EKEY_CODE>	_bindings;
  std::vector<std::wstring>	_bindingsStrings;
  
public:
  BindingMenu(std::string const & player);
  ~BindingMenu() {}

  DType			transferKey(irr::EKEY_CODE);
  void			assignContent();
  void			keyToString();
  void			select(irr::EKEY_CODE);
  void			openBindingConf();
  bool			fillBindingMap(std::string const &);
  void			defaultFill(std::string const &);
  bool			getPlayerInfo(std::string const &);
  bool			stringsToKey();
  void			bindMode(Bind *, irr::EKEY_CODE);
  bool			checkKey(irr::EKEY_CODE key);
  void			defaultP1();
  void			defaultP2();
  void			defaultP3();
  void			defaultP4();
  std::wstring const	stringToWstring(std::string const &) const;
  void			saveChanges();
  std::string const 	writeChanges();
  void			getBinds();
  void			assignBinds();
  std::string const &	getPlayer() const
  {
    return (_player);
  }
  std::vector<irr::EKEY_CODE> const & getBindings() const
  {
    return (_bindings);
  }
};
