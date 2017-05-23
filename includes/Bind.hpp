//
// Bind.hpp for Bind in /home/pashervz/Epitech/C++/Indie/Indie_studio/includes
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Tue May 23 09:25:19 2017 Pashervz
// Last update Tue May 23 11:56:33 2017 Pashervz
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
			    type) {}
  ~Bind() {}
  
  bool		getMode() const;
  void		setMode(bool);
};
