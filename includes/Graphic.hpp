//
// Graphic.hpp for irrlicht in /home/anthony/rendu/cpp/indie/Indie_studio/includes
//
// Made by Anthony Jouvel
// Login   <anthony.jouvel@epitech.eu>
//
// Started on  Fri May 12 14:02:36 2017 Anthony Jouvel
// Last update Sat May 13 16:37:12 2017 Pashervz
//

#pragma once

#include <irrlicht.h>
#include "AObserver.hpp"

class	Graphic : public AObserver
{
  irr::u32			_x;
  irr::u32			_y;
  irr::IrrlichtDevice		*_device;
  irr::video::IVideoDriver	*_driver;
  irr::scene::ISceneManager	*_sceneManager;

  void				displayLoop();
  void				actualize(Observable const &);
public:
  Graphic(irr::u32, irr::u32);
  Graphic();
  ~Graphic();

};
