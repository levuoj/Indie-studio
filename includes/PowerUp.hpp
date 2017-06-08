//
// Created by Kilian on 09/05/17.
//

#pragma once

#include "GameElement.hpp"

class PowerUp : public GameElement
{
  int		_duration;
public:
  
  void		setDuration(const int dur) { _duration = dur; };
  int		getDuration() const { return (_duration); };
  
  PowerUp()
  {
    _pos = std::make_pair(50.0f, 50.0f);
  };
  ~PowerUp() = default;
};
