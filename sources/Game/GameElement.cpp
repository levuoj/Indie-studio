//
// GameElement.cpp for GameElement.cpp in /home/tvigier/Indie_studio
// 
// Made by thomas vigier
// Login   <thomas.vigier@epitech.eu>
// 
// Started on  Wed May 10 13:50:08 2017 thomas vigier
// Last update Sun Jun 18 18:37:14 2017 Lebrun Kilian
//

#include "GameElement.hpp"

std::pair<float, float> const &	GameElement::getPos() const
{
  return (_pos);
}

void				GameElement::setPos(std::pair<float, float> const &pos)
{
  this->_pos = pos;
}
