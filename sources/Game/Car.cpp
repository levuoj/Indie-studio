//
// Created by Kilian on 09/05/17.
//

#include <math.h>
#include "Car.hpp"

const float Car::_maxSpeed = 7;
const float Car::_fps = 60;
const float Car::_inertia = Car::_maxSpeed / Car::_fps;

void            Car::accelerate()
{
    this->_speed += this->_inertia;
}

void            Car::deccelerate()
{
    this->_speed -= this->_inertia;
}

void            Car::move()
{
    this->_pos.first = this->_pos.first + (this->_speed / this->_fps) * this->_dir.first;
    if (this->_pos.first > 100)
    {
        this->_posMap.first += 1;
        this->_pos.first -= 100.0f;
    }
    else if (this->_pos.first < 0)
    {
        this->_posMap.first -= 1;
        this->_pos.first += 100.0f;
    }
    this->_pos.second = this->_pos.second + (this->_speed / this->_fps) * this->_dir.second;
    if (this->_pos.second > 100)
    {
        this->_posMap.second += 1;
        this->_pos.second -= 100.0f;
    }
    else if (this->_pos.second < 0)
    {
        this->_posMap.second -= 1;
        this->_pos.second += 100.0f;
    }
 }

void            Car::turnLeft()
{
    this->_angle += 2.0f;

   this->_dir.first = cos(this->_angle * M_PI / 180.0f);
   this->_dir.second = sin(this->_angle * M_PI / 180.0f);
}

void            Car::turnRight()
{
   this->_angle -= 2.0f;

   this->_dir.first = cos(this->_angle * M_PI / 180.0f);
   this->_dir.second = sin(this->_angle * M_PI / 180.0f);
}
