//
// Graphic.cpp for Entrance of the Gods into Valhalla in /home/anthony/rendu/cpp/indie/Indie_studio
//
// Made by Anthony Jouvel
// Login   <anthony.jouvel@epitech.eu>
//
// Started on  Fri May 12 14:07:46 2017 Anthony Jouvel
// Last update Mon May 15 13:36:32 2017 Anthony Jouvel
//

#include <iostream>
#include "Graphic.hpp"

Graphic::Graphic(irr::u32 width, irr::u32 height) : _width(width), _height(height)
{
  _device = irr::createDevice(irr::video::EDT_OPENGL,
			      irr::core::dimension2d<irr::u32>(width, height),
			      32);
  _driver = _device->getVideoDriver();
  _sceneManager = _device->getSceneManager();
  _device->getCursorControl()->setVisible(false);

  _device->getCursorControl()->setVisible(true); // A mettre a false lorsqu'on est plus dans le menu

  _guienv = _device->getGUIEnvironment();

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

  _camera = _sceneManager->addCameraSceneNodeFPS(0, 100.0f, 1.f, -1, keyMap, 5);
  _camera->setPosition(irr::core::vector3df(2700 * 2, 255 * 2, 2600 * 2));
  _camera->setTarget(irr::core::vector3df(2397 * 2, 343 * 2, 2700 * 2));
  _camera->setFarValue(42000.0f);

  mainMenu();
  displayLoop();
  // naboo_test->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  // arc->setMaterialFlag(irr::video::EMF_LIGHTING, false);
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
  mainMenu();
  displayLoop();
}

Graphic::~Graphic()
{
  _device->drop();
}

void		Graphic::mainMenu()
{
  button(5330.f, 560.f, 5225.0f, L"PLAY", "assets/deathStar.jpg");
  button(5330.f, 540.f, 5225.0f, L"LEADERBOARD", "assets/deathStar.jpg");
  button(5330.f, 520.f, 5225.0f, L"OPTIONS", "assets/deathStar.jpg");
  button(5330.f, 500.f, 5225.0f, L"QUIT", "assets/deathStar.jpg");
  skyDome("assets/skydome1.jpg");
  sol();

  // irr::scene::IAnimatedMeshSceneNode *jawa =
  //   _sceneManager->addAnimatedMeshSceneNode(_sceneManager->getMesh("./assets/JAWA/Star_wars_JAWA.obj"));
  // jawa->setMaterialFlag(irr::video::EMF_LIGHTING, false);
}

void		Graphic::sol()
{
  irr::scene::ITerrainSceneNode	*terrain =
    _sceneManager->addTerrainSceneNode("assets/terrain-heightmap.bmp",
				       0, -1,
				       irr::core::vector3df(0.f, 0.f, 0.f),
				       irr::core::vector3df(0.f, 0.f, 0.f),
				       irr::core::vector3df(40.f, 4.4f, 40.f),
				       irr::video::SColor(255, 255, 255, 255),
				       5, irr::scene::ETPS_17, 4);

  terrain->setMaterialTexture(0, _driver->getTexture("assets/sand.jpg"));
  terrain->setMaterialTexture(1, _driver->getTexture("assets/detailmap3.jpg"));
  terrain->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  terrain->setMaterialType(irr::video::EMT_SOLID);
  terrain->scaleTexture(1.0f, 20.0f);
}

void		Graphic::skyDome(const irr::io::path& image)
{
  _sceneManager->addSkyDomeSceneNode(_driver->getTexture(image),
				     16, 16, 0.5f, 2.0f);
}

void		Graphic::button(irr::f32 x, irr::f32 y, irr::f32 z,
				const wchar_t *text,
				const irr::io::path& filename)
{
  irr::scene::IMeshSceneNode	*cube =
    _sceneManager->addCubeSceneNode(10.0f, 0, -1,
				    irr::core::vector3df(x, y, z),
				    irr::core::vector3df(0.f, 105.f, 0.f));
  cube->setScale(irr::core::vector3df(5.0f, 1.0f, 1.0f));

  cube->setMaterialTexture(0, _driver->getTexture(filename));
  cube->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  cube->setMaterialType(irr::video::EMT_SOLID);


  _sceneManager->addTextSceneNode(_guienv->getFont("assets/fontcourier.bmp"),
				  text,
				  irr::video::SColor(255, 255, 255, 0),
				  cube);
}

void		Graphic::displayLoop()
{
  while (_device->run())
    {
      _driver->beginScene(true, true,
			  irr::video::SColor(255, 255, 255, 255));
      _sceneManager->drawAll();
      _guienv->drawAll();
      _driver->endScene();

      irr::core::stringw str = L"X = ";
      str += _camera->getAbsolutePosition().X;
      str += L" Y = ";
      str += _camera->getAbsolutePosition().Y;
      str += L" Z = ";
      str += _camera->getAbsolutePosition().Z;
      _device->setWindowCaption(str.c_str());
    }
}

void		Graphic::actualize(Observable const& observable)
{
  this->manageDisplay(observable.getMap(), observable.getType());
}

void		Graphic::manageDisplay(std::vector<Element> const& map, DType type)
{
  (void)map;
  (void)type;
  if (_device->run())
    return ;
  _driver->beginScene(true, true,
		      irr::video::SColor(0, 255, 255, 255));
  _sceneManager->drawAll();
  _driver->endScene();
}

void		Graphic::displayMainMenu(std::vector<Element> const&)
{
  std::cout << "J'affiche le menu <3" << std::endl;
}

void		Graphic::displayOptions(std::vector<Element> const&)
{
}

void		Graphic::displayLeaderBoard(std::vector<Element> const&)
{
}

void		Graphic::displayExit(std::vector<Element> const&)
{
}
