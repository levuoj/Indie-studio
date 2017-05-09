//
// Element.hpp for Element in /home/pashervz/Epitech/C++/Indie/Indie_studio/includes
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Tue May  9 11:09:58 2017 Pashervz
// Last update Tue May  9 13:36:01 2017 Pashervz
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
      DEFAULT
    };
  
private:
  std::string		_path;
  EType			_type;
  
public:
  Element(){}
  ~Element() {}
  std::string const &	getPath() const;
  EType			getType() const;
  void			setPath(std::string const &);
  void			setType(EType);
};
