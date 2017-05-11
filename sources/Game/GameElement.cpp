//
// GameElement.cpp for GameElement.cpp in /home/tvigier/Indie_studio
// 
// Made by thomas vigier
// Login   <thomas.vigier@epitech.eu>
// 
// Started on  Wed May 10 13:50:08 2017 thomas vigier
// Last update Wed May 10 13:54:32 2017 thomas vigier
//

#include "GameElement.hpp"

std::pair<float, float> const &	GameElement::getPos() const
{
  return (_pos);
}

void				GameElement::setPos(std::pair<float, float> pos)
{
  this->_pos = pos;
}
