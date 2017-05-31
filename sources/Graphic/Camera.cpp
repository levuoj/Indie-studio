//
// Camera.cpp for I see what you see in /home/anthony/rendu/cpp/indie_studio/Indie_studio
//
// Made by jouvel
// Login   <anthony.jouvel@epitech.eu>
//
// Started on  Wed May 31 19:17:27 2017 jouvel
// Last update Wed May 31 19:40:01 2017 jouvel
//

#include "Camera.hpp"

Gcamera::Gcamera(irr::scene::ISceneManager *sceneManager,
	       irr::core::vector3df pos, irr::core::vector3df targ)
{
  _camera = sceneManager->addCameraSceneNode(0, pos, targ);
  _camera->setFarValue(42000.f);
}

irr::f32	Gcamera::coords(irr::f32 oldPoint,
				irr::f32 newPoint)
{
  if (oldPoint < newPoint)
    return (oldPoint + 1);
  else if (oldPoint > newPoint)
    return (oldPoint - 1);
  return (newPoint);
}

void		Gcamera::moveCamera(irr::core::vector3df pos,
				    irr::core::vector3df targ)
{
  _camera->setPosition(irr::core::vector3df(coords(_camera->getAbsolutePosition().X, pos.X),
					    coords(_camera->getAbsolutePosition().Y, pos.Y),
					    coords(_camera->getAbsolutePosition().Z, pos.Z)));
  _camera->setTarget(irr::core::vector3df(coords(_camera->getTarget().X, targ.X),
					    coords(_camera->getTarget().Y, targ.Y),
					    coords(_camera->getTarget().Z, targ.Z)));
}
