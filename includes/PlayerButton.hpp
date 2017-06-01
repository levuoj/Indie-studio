//
// PlayerButton.hpp for PlayerButton in /home/pashervz/Epitech/C++/Indie/Indie_studio/includes
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Wed May 24 14:48:13 2017 Pashervz
// Last update Thu Jun  1 15:01:37 2017 Pashervz
//

#pragma once

#include "Button.hpp"

class PlayerButton : public Button
{
private:
  std::string		_name;
  
public:
  PlayerButton(std::wstring const& content,
	       irr::io::path const& path,
	       BType type,
	       std::string const & name) : Button(content,
						  path,
						  type),
					   _name(name) {}
  ~PlayerButton() {}
  
  std::string const &	getName() const
  {
    return (_name);
  }
};
