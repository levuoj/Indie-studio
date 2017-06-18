//
// Camera.hpp for big brother is watching you in Indie_studio
//
// Made by jouvel
// Login   <anthony.jouvel@epitech.eu>
//
// Started on  Wed May 31 18:34:01 2017 jouvel
// Last update Sun Jun 18 18:49:52 2017 Lebrun Kilian
//

#pragma once

#include <irrlicht.h>

class				Gcamera
{
  irr::scene::ICameraSceneNode	*_camera;

public:
  Gcamera(){}
  ~Gcamera() = default;

  void				initCamera(irr::scene::ISceneManager*,
					   irr::core::vector3df,
					   irr::core::vector3df);
  void				moveCamera(irr::core::vector3df, irr::core::vector3df);
  irr::f32			coords(irr::f32, irr::f32) const;
};
