//
// Element.cpp for Element in /home/pashervz/Epitech/C++/Indie/Indie_studio/sources
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Tue May  9 11:17:12 2017 Pashervz
// Last update Tue May  9 11:34:07 2017 Pashervz
//

#include "Element.hpp"

std::string const &		Element::getPath() const
{
  return (_path);
}

Element::EType			Element::getType() const
{
  return (_type);
}

void				Element::setPath(std::string const & path)
{
  this->_path = path;
}

void				Element::setType(EType type)
{
  this->_type = type;
}
