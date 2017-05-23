//
// Button.hpp for Button in /home/pashervz/Epitech/C++/Indie/Indie_studio/includes
//
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
//
// Started on  Tue May  9 14:43:05 2017 Pashervz
// Last update Mon May 22 11:03:41 2017 Pierre Zawadil
//

#pragma once

#include "Element.hpp"

class Button : public Element
{
private:
  std::wstring	_content;
  bool		_isSelected;

public:
  Button(std::wstring const& content, irr::io::path const& path) : Element(path, EType::BUTTON),
					_content(content), _isSelected(false) {}
  ~Button() {}

  std::wstring const&	getContent() const
  {
    return (_content);
  }

  bool			getIsSelected() const
  {
    return (_isSelected);
  }

  void			setContent(std::wstring const& content)
  {
    this->_content = content;
  }

  void			setIsSelected(bool value)
  {
    this->_isSelected = value;
  }
};
