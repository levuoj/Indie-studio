//
// Graphic.hpp for irrlicht in /home/anthony/rendu/cpp/indie/Indie_studio/includes
//
// Made by Anthony Jouvel
// Login   <anthony.jouvel@epitech.eu>
//
// Started on  Fri May 12 14:02:36 2017 Anthony Jouvel
// Last update Mon May 15 21:53:48 2017 Pashervz
//

#pragma once

#include <irrlicht.h>
#include <unordered_map>
#include <functional>
#include "AObserver.hpp"
#include "Utils.hpp"

class	Graphic : public AObserver
{
  
public:
  irr::u32			_width;
  irr::u32			_height;
  irr::IrrlichtDevice		*_device;
  irr::video::IVideoDriver	*_driver;
  irr::scene::ISceneManager	*_sceneManager;

  void				actualize(Observable const &);
  
public:
  Graphic(irr::u32, irr::u32);
  Graphic();
  ~Graphic();

  void				manageDisplay(std::vector<Element *> const&, DType);
  void				displayMainMenu(std::vector<Element *> const&);
  void				displayOptions(std::vector<Element *> const&);
  void				displayLeaderBoard(std::vector<Element *> const&);
  void				displayExit(std::vector<Element *> const&);
  
  std::unordered_map<DType,
		     std::function<void(std::vector<Element *> const&)>>		dispThis =
    {
      {DType::MAIN_MENU, std::bind(&Graphic::displayMainMenu, this, std::placeholders::_1)},
      {DType::OPTIONS, std::bind(&Graphic::displayOptions, this, std::placeholders::_1)},
      {DType::LEADERBOARD, std::bind(&Graphic::displayLeaderBoard, this, std::placeholders::_1)},
      {DType::EXIT, std::bind(&Graphic::displayExit, this, std::placeholders::_1)},
      {DType::NOTHING, NULL}
    };
};
