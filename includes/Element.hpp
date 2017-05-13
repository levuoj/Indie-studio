//
// Element.hpp for Element in /home/pashervz/Epitech/C++/Indie/Indie_studio/includes
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Tue May  9 11:09:58 2017 Pashervz
// Last update Sat May 13 16:34:22 2017 Pashervz
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
      ENDLINE,
    };
  
protected:
  std::string		_path;
  EType			_type;
  
public:
    Element();
    Element(const std::string &path, EType type) : _path(path), _type(type) {}
    virtual ~Element() {}
    std::string const	&	getPath() const;
    EType		    	getType() const;
    void		    	setPath(std::string const &);
    void		    	setType(EType);
};
