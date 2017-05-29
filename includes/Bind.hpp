//
// Bind.hpp for Bind in /home/pashervz/Epitech/C++/Indie/Indie_studio/includes
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Tue May 23 09:25:19 2017 Pashervz
// Last update Fri May 26 11:08:08 2017 Lebrun Kilian
//

#pragma once

#include <Keycodes.h>
#include "Button.hpp"

class Bind : public Button
{
private:
  bool			_bindingMode = false;
  irr::EKEY_CODE	_key;
  
public:
  Bind(std::wstring const& content,
       irr::io::path const& path,
       BType type) : Button(content,
			    path,
			    type) {}
  ~Bind() {}
  
  bool			getMode() const
  {
    return (_bindingMode);
  }
  
  void			setMode(bool set)
  {
    _bindingMode = set;
  }

  irr::EKEY_CODE       getKey() const
  {
    return (_key);
  }

  void			setKey(irr::EKEY_CODE key)
  {
    _key = key;
  }
};
