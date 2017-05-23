//
// Created by Kilian on 12/05/17.
//

#include "test.hpp"
#include "Player.hpp"

void                Player::driver(const irr::EKEY_CODE &key)
{
  const auto        &it = _functors.find(key);

  if (it != _functors.end())
    it->second();
  else
    this->_car.slowDown();
}
