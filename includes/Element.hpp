//
// Element.hpp for Element in /home/pashervz/Epitech/C++/Indie/Indie_studio/includes
//
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
//
// Started on  Tue May  9 11:09:58 2017 Pashervz
<<<<<<< HEAD
// Last update Mon May 22 13:27:48 2017 Pashervz
=======
// Last update Fri May 26 15:37:42 2017 Pashervz
>>>>>>> 8e0116a94d22b16cb05eefad7db7cd5c057a0ff0
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
      CAR,
      POWERUP,
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
