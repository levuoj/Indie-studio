//
// SaveButton.hpp for SaveButton in /home/pashervz/Epitech/C++/Indie/Indie_studio/includes
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Tue Jun  6 17:24:05 2017 Pashervz
// Last update Thu Jun 15 12:10:03 2017 Pashervz
//

#pragma once

#include "Button.hpp"

class SaveButton : public Button
{
private:
  int		_number;
  
public:
  SaveButton(std::wstring const& content,
	       irr::io::path const& path,
	       BType type,
	       int number) : Button(content,
				    path,
				    type),
			     _number(number) {}
  virtual ~SaveButton() {}
  
  int			getNumber() const
  {
    return (_number);
  }
  void			setNumber(int number)
  {
    _number = number;
  }
};
