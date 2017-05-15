//
// Element.hpp for Element in /home/pashervz/Epitech/C++/Indie/Indie_studio/includes
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Tue May  9 11:09:58 2017 Pashervz
// Last update Mon May 15 10:02:04 2017 Pierre Zawadil
//

#pragma once

#include <iostream>

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
      ENDLINE
    };
  
protected:
  std::string		_path;
  EType			_type;
  
public:
  Element();
  Element(std::string const & path, Element::EType type) : _path(path), _type(type) {}
  ~Element() {}
  std::string const &	getPath() const;
  EType			getType() const;
  void			setPath(std::string const &);
  void			setType(EType);
};
