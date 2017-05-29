//
// Convert.hpp for Convert.hpp in /home/tvigier/Indie_studio
// 
// Made by thomas vigier
// Login   <thomas.vigier@epitech.eu>
// 
// Started on  Fri May 12 17:06:19 2017 thomas vigier
// Last update Mon May 29 16:15:46 2017 Lebrun Kilian
//

#pragma once

#include <utility>

class		Convert
{
public:
  template <class T>
  static std::pair<T, T> const	posToCoord(int pos)
  {
    return (std::make_pair(pos % 60, (pos - pos % 60) / 60));
  }
  template <class T>
  static int				coordToPos(std::pair<T, T> const& coord)
  {
    return (coord.second * 60 + coord.first);
  }
};
