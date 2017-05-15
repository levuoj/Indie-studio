//
// Graphic.hpp for irrlicht in /home/anthony/rendu/cpp/indie/Indie_studio/includes
//
// Made by Anthony Jouvel
// Login   <anthony.jouvel@epitech.eu>
//
// Started on  Fri May 12 14:02:36 2017 Anthony Jouvel
// Last update Mon May 15 10:39:29 2017 Anthony Jouvel
//

#pragma once

#include <irrlicht.h>

class				Graphic
{
  irr::u32			_x;
  irr::u32			_y;
  irr::IrrlichtDevice		*_device;
  irr::video::IVideoDriver	*_driver;
  irr::scene::ISceneManager	*_sceneManager;
  irr::gui::IGUIEnvironment	*_guienv;
  irr::scene::ICameraSceneNode	*_camera;

  void				displayLoop();
  void				button(irr::f32, irr::f32, irr::f32, const wchar_t *, const irr::io::path&);
  void				mainMenu();
  void				skyDome(const irr::io::path&);
  void				sol();
public:
  Graphic(irr::u32, irr::u32);
  Graphic();
  ~Graphic();
};
