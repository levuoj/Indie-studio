//
// Created by Kilian on 09/05/17.
//

#pragma once

#include <utility>
#include "GameElement.hpp"
#include "PowerUp.hpp"

class Car : public GameElement
{
    enum EState
    {
        NORMAL,
        BANANA,
        WALL,
        SHOOT
    };
    std::pair<float, float> _pos;
    float                   _speed;
    std::pair<float, float> _dir;
    PowerUp                 _pu;
    EState                  _state;
public:
  Car() {};
    Car(std::pair<float, float> pos) : _pos(pos) {};
    ~Car() {}
    void                            moveForward();
    void                            moveLeft();
    void                            moveRight();
    const std::pair<float, float>   getPos()
    {
        return (this->_pos);
    };
};
