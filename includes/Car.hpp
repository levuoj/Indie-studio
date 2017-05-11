//
// Created by Kilian on 09/05/17.
//

#pragma once

#include <utility>
#include "GameElement.hpp"
#include "PowerUp.hpp"

class Car : public GameElement
{
    static const float _maxSpeed;
    static const float _fps;
    static const float _inertia;

    enum EState
    {
        NORMAL,
        BANANA,
        WALL,
        SHOOT
    };
    std::pair<int, int>     _posMap;
    std::pair<float, float> _pos;
    float                   _speed;
    std::pair<float, float> _dir;
    float                   _angle;
    PowerUp                 _pu;
    EState                  _state;
public:
    Car() {};
    Car(std::pair<int, int> posMap) : _posMap(posMap), _pos(50.0f, 50.0f), _speed(0.0f), _dir(1.0f, 0.0f), _angle(0.0f) {};
    ~Car() {}
    void                            accelerate();
    void                            deccelerate();
    void                            move();
    void                            turnLeft();
    void                            turnRight();
    const std::pair<float, float>   getPos()
    {
        return (this->_pos);
    };
    const std::pair<int, int>       getPosMap()
    {
        return (this->_posMap);
    };
};
