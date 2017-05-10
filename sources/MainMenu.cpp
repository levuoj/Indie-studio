//
// MainMenu.cpp for MainMenu in /home/pashervz/Epitech/C++/Indie/Indie_studio/sources
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Tue May  9 15:18:43 2017 Pashervz
// Last update Wed May 10 11:57:58 2017 Pashervz
//

#include "Button.hpp"
#include "MainMenu.hpp"

MainMenu::MainMenu() : Menu("Main Menu")
{
  this->_map.push_back(Button("Play"));
  this->_map.push_back(Button("Leaderboard"));
  this->_map.push_back(Button("Options"));
  this->_map.push_back(Button("Exit"));
}

