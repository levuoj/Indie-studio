//
// Button.hpp for Button in /home/pashervz/Epitech/C++/Indie/Indie_studio/includes
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Tue May  9 14:43:05 2017 Pashervz
// Last update Wed May 10 13:35:02 2017 Pashervz
//

#pragma once

#include "Element.hpp"

class Button : public Element
{
private:
  std::string	_content;
  bool		_isSelected;
  
public:
  Button(std::string const & content) : Element("Button", EType::BUTTON),
					_content(content), _isSelected(false) {}
  ~Button() {}
  
  std::string const &	getContent() const
  {
    return (_content);
  }

  bool			getIsSelected() const
  {
    return (_isSelected);
  }
  
  void			setContent(std::string const & content)
  {
    this->_content = content;
  }

  void			setIsSelected(bool value)
  {
    this->_isSelected = value;
  }
};
