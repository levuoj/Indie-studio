//
// Button.hpp for Button in /home/pashervz/Epitech/C++/Indie/Indie_studio/includes
//
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
//
// Started on  Tue May  9 14:43:05 2017 Pashervz
// Last update Wed Jun  7 11:16:11 2017 Pashervz
//

#pragma once

#include "Element.hpp"

class Button : public Element
{
public:
  enum BType
    {
      MENU,
      SWITCH,
      BIND,
      PLAYER,
      NBPLAYER,
      RESUME,
      EXIT,
      SAVE
    };
  
private:
  std::wstring	_content;
  bool		_isSelected;
  BType		_ButtonType;

public:
  Button(std::wstring const& content, irr::io::path const& path, BType type) : Element(path, EType::BUTTON),
									       _content(content),
									       _isSelected(false),
									       _ButtonType(type) {}
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

  BType			getButtonType() const
  {
    return (_ButtonType);
  }
};
