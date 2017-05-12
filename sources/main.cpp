//
// main.cpp for indie in /home/zgore/Projects/cpp_2017/Indie_studio
//
// Made by Pierre Zawadil
// Login   <pierre.zawadil@epitech.eu>
//
// Started on  Wed May 10 18:03:11 2017 Pierre Zawadil
// Last update Fri May 12 15:06:36 2017 Anthony Jouvel
//

#include "Graphic.hpp"

int			main()
{
  Graphic		tmp(1000, 1000);
  // irr::IrrlichtDevice*	device = irr::createDevice(irr::video::EDT_OPENGL,
  //						   irr::core::dimension2d<irr::u32>(1000,1000),
  //						   32);
  // irr::video::IVideoDriver*	driver = device->getVideoDriver();
  // irr::scene::ISceneManager*	sceneManager = device->getSceneManager();
  // device->getCursorControl()->setVisible (false);

  // /* MODELE */
  // irr::scene::IAnimatedMeshSceneNode *sydney = sceneManager->addAnimatedMeshSceneNode(
  //					    sceneManager->getMesh("Yoda.3ds"));

  // sydney->setMaterialFlag(irr::video::EMF_LIGHTING, false);

  // sydney->setMaterialTexture(1, driver->getTexture("sclera.bmp"));
  // sydney->setMaterialTexture(2, driver->getTexture("fbrk_t16.jpg"));
  // sydney->setMaterialTexture(0, driver->getTexture("robedif.jpg"));
  // sydney->setMaterialTexture(3, driver->getTexture("iris.bmp"));
  // sydney->setMaterialTexture(3, driver->getTexture("iris2.jpg"));

  // //  sydney->setMD2Animation(irr::scene::EMAT_STAND);


  // /* CAMERA */
  // irr::SKeyMap keyMap[5];                             // re-assigne les commandes
  // keyMap[0].Action = irr::EKA_MOVE_FORWARD;           // avancer
  // keyMap[0].KeyCode = irr::KEY_KEY_Z;                 // w
  // keyMap[1].Action = irr::EKA_MOVE_BACKWARD;          // reculer
  // keyMap[1].KeyCode = irr::KEY_KEY_S;                 // s
  // keyMap[2].Action = irr::EKA_STRAFE_LEFT;            // a gauche
  // keyMap[2].KeyCode = irr::KEY_KEY_Q;                 // a
  // keyMap[3].Action = irr::EKA_STRAFE_RIGHT;           // a droite
  // keyMap[3].KeyCode = irr::KEY_KEY_D;                 // d

  // sceneManager->addCameraSceneNodeFPS(0, 100.0f, 0.1f, -1, keyMap, 5);

  // /* RENDU */
  // while (device->run())
  //   {
  //     driver->beginScene(true, true,                    // demarre le rendu
  //			 irr::video::SColor(0,255,255,255));
  //     sceneManager->drawAll();                         // calcule le rendu
  //     driver->endScene();                              // affiche le rendu
  //   }
  // device->drop();                                    // libere la memoire
  return (0);
}
