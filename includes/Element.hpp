//
// Element.hpp for Element in /home/pashervz/Epitech/C++/Indie/Indie_studio/includes
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Tue May  9 11:09:58 2017 Pashervz
// Last update Mon May 22 16:34:25 2017 DaZe
//

#pragma once

#include <iostream>

class Element
{
public:
  
  enum		EType
    {
      CAR,
      POWERUP,
      BUTTON,
      ARROW_LEFT,
      ARROW_RIGHT,
      BLOCK,
      ROAD,
      LINE,
      ENDLINE,
      DEFAULT
    };
  
protected:
  std::string		_path;
  EType			_type;
  
public:
    Element() {};
    Element(const std::string &path, EType type) : _path(path), _type(type) {}
    virtual ~Element() {}
    std::string const &	getPath() const;
    EType		    	getType() const;
    void		    	setPath(std::string const &);
    void		    	setType(EType);
};
