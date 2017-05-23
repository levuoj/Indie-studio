//
// main.cpp for main.cpp in /home/tvigier/test
// 
// Made by thomas vigier
// Login   <thomas.vigier@epitech.eu>
// 
// Started on  Wed May 10 11:05:32 2017 thomas vigier
// Last update Tue May 23 14:46:45 2017 DaZe
//

#define COL 50

#include "test.hpp"
#include "ManageGame.hpp"
#include "Graphic.hpp"

int			main()
{
  std::array<irr::EKEY_CODE, 5> arr;

    arr[0] = irr::EKEY_CODE::KEY_UP;
    arr[1] = irr::EKEY_CODE::KEY_DOWN;
    arr[2] = irr::EKEY_CODE::KEY_LEFT;
    arr[3] = irr::EKEY_CODE::KEY_RIGHT;
    arr[4] = irr::EKEY_CODE::KEY_SPACE;

    std::vector<std::array<irr::EKEY_CODE, 5>>    test;

    test.push_back(arr);

    ManageGame game(1, test);

    game.controlDriver(irr::EKEY_CODE::KEY_UP);
    // ManageGame game;

    // game.loadMap();
    // //    game.printMap();

    // while (true)
    //   game.updateMap();
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
