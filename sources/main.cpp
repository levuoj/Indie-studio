//
// main.cpp for indie in /home/zgore/Projects/cpp_2017/Indie_studio
// 
// Made by Pierre Zawadil
// Login   <pierre.zawadil@epitech.eu>
// 
// Started on  Wed May 10 18:03:11 2017 Pierre Zawadil
// Last update Wed May 10 18:03:12 2017 Pierre Zawadil
//

#include <irrlicht.h>

int	main()
{
  irr::IrrlichtDevice *device = irr::createDevice( // creation device
						  irr::video::EDT_OPENGL,                      // l'API est OpenGL
						  irr::core::dimension2d<irr::u32>(800,600),   // taille de la fenetre 800x600
						  32, false, true, false, 0);

  irr::video::IVideoDriver* driver =
    device->getVideoDriver();                    // creation driver
  irr::scene::ISceneManager *sceneManager =
    device->getSceneManager ();                  // creation scene manager

  sceneManager->addCameraSceneNode (0,             // ajout camera fixe
				    irr::core::vector3df (0,0,0),
				    irr::core::vector3df (5,0,0));

  while (device->run()) {                          // la boucle de rendu
    driver->beginScene(                          // demarre le rendu
		       true,                                    // clear back-buffer
		       true,                                    // clear z-buffer
		       irr::video::SColor(255,255,255,255));    // fond blanc
    sceneManager->drawAll ();                    // calcule le rendu
    driver->endScene ();                         // affiche le rendu
  }

  device->drop ();                                 // liberation de la memoire
  return 0;
}
