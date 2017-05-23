//
// Convert.hpp for Convert.hpp in /home/tvigier/Indie_studio
// 
// Made by thomas vigier
// Login   <thomas.vigier@epitech.eu>
// 
// Started on  Fri May 12 17:06:19 2017 thomas vigier
// Last update Sat May 13 10:51:18 2017 thomas vigier
//

#pragma once

#include <utility>

class		Convert
{
public:
  template <class T>
  static std::pair<T, T> const	posToCoord(int pos)
  {
    return (std::make_pair(pos % 50, (pos - pos % 50) / 50));
  }
  template <class T>
  static int				coordToPos(std::pair<T, T> const& coord)
  {
    return (coord.second * 50 + coord.first);
  }
};
