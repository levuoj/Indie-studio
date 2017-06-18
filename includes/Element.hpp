//
// Element.hpp for Element in /home/pashervz/Epitech/C++/Indie/Indie_studio/includes
//
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
//
// Started on  Tue May  9 11:09:58 2017 Pashervz
// Last update Sun Jun 18 19:53:50 2017 Lebrun Kilian
//

#pragma once

#include <iostream>
#include <path.h>

class Element
{
public:

  enum		EType
    {
      DEFAULT,
      POD1,
      POD2,
      POD3,
      POD4,
      POWERUP,
      POWERUPHIDE,
      BUTTON,
      ARROW_LEFT,
      ARROW_RIGHT,
      BLOCK,
      ROAD,
      LINE,
      ENDLINE,
    };

protected:
  irr::io::path		_path;
  EType			_type;

public:
  Element() {};
  Element(irr::io::path const& path, EType type) : _path(path), _type(type) {}
  virtual ~Element() {}


  irr::io::path const &			getPath() const
  {
    return (_path);
  }

  Element::EType			getType() const
  {
    return (_type);
  }

  void					setPath(irr::io::path const& path)
  {
    this->_path = path;
  }

  void					setType(EType type)
  {
    this->_type = type;
  }

};
