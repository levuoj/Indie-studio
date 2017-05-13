//
// Graphic.cpp for Entrance of the Gods into Valhalla in /home/anthony/rendu/cpp/indie/Indie_studio
//
// Made by Anthony Jouvel
// Login   <anthony.jouvel@epitech.eu>
//
// Started on  Fri May 12 14:07:46 2017 Anthony Jouvel
// Last update Sat May 13 16:44:05 2017 Pashervz
//

#include "Graphic.hpp"

Graphic::Graphic(irr::u32 x, irr::u32 y) : _x(x), _y(y)
{
  _device = irr::createDevice(irr::video::EDT_OPENGL,
			      irr::core::dimension2d<irr::u32>(x, y),
			      32);

  _driver = _device->getVideoDriver();
  _sceneManager = _device->getSceneManager();

  _device->getCursorControl()->setVisible(false);

  // CAMERA POUR LE TEMPS DU DEV
  irr::SKeyMap keyMap[4];
  keyMap[0].Action = irr::EKA_MOVE_FORWARD;
  keyMap[0].KeyCode = irr::KEY_KEY_Z;
  keyMap[1].Action = irr::EKA_MOVE_BACKWARD;
  keyMap[1].KeyCode = irr::KEY_KEY_S;
  keyMap[2].Action = irr::EKA_STRAFE_LEFT;
  keyMap[2].KeyCode = irr::KEY_KEY_Q;
  keyMap[3].Action = irr::EKA_STRAFE_RIGHT;
  keyMap[3].KeyCode = irr::KEY_KEY_D;

  _sceneManager->addCameraSceneNodeFPS(0, 100.0f, 0.1f, -1, keyMap, 5);

  irr::scene::IAnimatedMeshSceneNode *naboo_test =
    _sceneManager->addAnimatedMeshSceneNode(_sceneManager->getMesh("NABOO-F.obj"));
  irr::scene::IAnimatedMeshSceneNode *arc =
    _sceneManager->addAnimatedMeshSceneNode(_sceneManager->getMesh("ARC170.obj"));

  naboo_test->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  arc->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  displayLoop();
}

Graphic::Graphic()
{
  _device = irr::createDevice(irr::video::EDT_OPENGL,
			      irr::core::dimension2d<irr::u32>(1000, 1000),
			      32);

  _driver = _device->getVideoDriver();
  _sceneManager = _device->getSceneManager();

  _device->getCursorControl()->setVisible(false);

  // CAMERA POUR LE TEMPS DU DEV
  irr::SKeyMap keyMap[4];
  keyMap[0].Action = irr::EKA_MOVE_FORWARD;
  keyMap[0].KeyCode = irr::KEY_KEY_Z;
  keyMap[1].Action = irr::EKA_MOVE_BACKWARD;
  keyMap[1].KeyCode = irr::KEY_KEY_S;
  keyMap[2].Action = irr::EKA_STRAFE_LEFT;
  keyMap[2].KeyCode = irr::KEY_KEY_Q;
  keyMap[3].Action = irr::EKA_STRAFE_RIGHT;
  keyMap[3].KeyCode = irr::KEY_KEY_D;

  _sceneManager->addCameraSceneNodeFPS(0, 100.0f, 0.1f, -1, keyMap, 5);
  displayLoop();
}

Graphic::~Graphic()
{
  _device->drop();
}

void		Graphic::actualize(Observable const & observable)
{
  (void) observable;
}

void		Graphic::displayLoop()
{
  while (_device->run())
    {
      _driver->beginScene(true, true,
			  irr::video::SColor(0, 255, 255, 255));
      _sceneManager->drawAll();
      _driver->endScene();
    }
}
