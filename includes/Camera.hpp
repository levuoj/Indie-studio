//
// Camera.hpp for big brother is watching you in Indie_studio
//
// Made by jouvel
// Login   <anthony.jouvel@epitech.eu>
//
// Started on  Wed May 31 18:34:01 2017 jouvel
// Last update Wed May 31 19:41:35 2017 jouvel
//

#pragma once

#include "Graphic.hpp"

class				Gcamera
{
  irr::scene::ICameraSceneNode	*_camera;

public:
  Gcamera(irr::scene::ISceneManager *, irr::core::vector3df, irr::core::vector3df);
  ~Gcamera() = default;

  void				moveCamera(irr::core::vector3df, irr::core::vector3df);
  irr::f32			coords(irr::f32, irr::f32);
};
