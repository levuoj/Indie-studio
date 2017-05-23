//
// Bind.hpp for Bind in /home/pashervz/Epitech/C++/Indie/Indie_studio/includes
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Tue May 23 09:25:19 2017 Pashervz
// Last update Tue May 23 10:18:37 2017 Pashervz
//

#pragma once

#include "Button.hpp"

class Bind : public Button
{
private:
  bool		_bindingMode = false;
  
public:
  Bind(std::wstring const& content,
       irr::io::path const& path,
       BType type) : Button(content,
			    path,
			    EType::BUTTON,
			    Button::BType::BIND) {}
  ~Bind() {}
  
  bool		getMode() const;
  void		setMode(bool);
};
