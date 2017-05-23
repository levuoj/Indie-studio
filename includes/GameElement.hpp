//
// Element.hpp for Element in /home/pashervz/Epitech/C++/Indie/Indie_studio/includes
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Tue May  9 11:09:58 2017 Pashervz
// Last update Mon May 15 13:14:00 2017 thomas vigier
//

#pragma once

#include <iostream>
#include "Element.hpp"

class GameElement : public Element
{
protected:
  std::pair<float, float>	_pos;
  
public:
  void				setPos(std::pair<float, float>);
  std::pair<float, float> const& getPos() const;

    GameElement() : Element() {}
    GameElement(const std::string &path, Element::EType type, std::pair<float, float> pos) : Element(path, type), _pos(pos) {}
  ~GameElement() {}

};
