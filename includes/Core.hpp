//
// Core.hpp for Core in /home/pashervz/Epitech/C++/Indie/Indie_studio/includes
//
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
//
// Started on  Mon May  8 19:43:34 2017 Pashervz
// Last update Tue Jun 13 15:38:43 2017 Pashervz
//

#pragma once

#include <unordered_map>
#include <memory>
#include "AMenu.hpp"
#include "Graphic.hpp"
#include "ManageGame.hpp"

#define EXIT_ERROR (84)

class Core
{
private:
  std::unique_ptr<Graphic>				_graphic;
  DType							_toLoad;
  std::unordered_map<DType, std::shared_ptr<AMenu>>	_menu;
  std::unique_ptr<ManageGame>				_game;
  std::vector<std::vector<irr::EKEY_CODE>>		_bindings;
  
public:
  Core();
  ~Core() {}
  int		launch();
  void		initBindings();
};
