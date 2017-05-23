//
// Chrono.cpp for Chrono in /home/pashervz/Epitech/C++/Indie/Indie_studio/sources
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Wed May 10 14:02:13 2017 Pashervz
// Last update Wed May 10 14:22:12 2017 Pashervz
//

#include <iostream>
#include <chrono>
#include "Chrono.hpp"

void					Chrono::start()
{
  std::chrono::duration<double>		diff;
  auto					start  = std::chrono::high_resolution_clock::now();
  auto					end = start;
  
  while (diff.count() < _endingValue)
    {
      end = std::chrono::high_resolution_clock::now();
      diff = end - start;
      std::cout << diff.count() << std::endl;
    }
}

void			Chrono::stop()
{
}
