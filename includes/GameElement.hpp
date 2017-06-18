//
// Element.hpp for Element in /home/pashervz/Epitech/C++/Indie/Indie_studio/includes
//
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
//
// Started on  Tue May  9 11:09:58 2017 Pashervz
// Last update Sun Jun 18 18:38:06 2017 Lebrun Kilian
//

#pragma once

#include <iostream>
#include "Element.hpp"

class GameElement : public Element
{
protected:
  std::pair<float, float>	_pos;

public:
  void				setPos(std::pair<float, float> const &);
  std::pair<float, float> const& getPos() const;

  GameElement() : Element() {}
  GameElement(irr::io::path const &path, Element::EType type, std::pair<float, float> const &pos) : Element(path, type), _pos(pos) {}
  ~GameElement() {}

};
