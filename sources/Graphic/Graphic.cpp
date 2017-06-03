//
// Graphic.cpp for Entrance of the Gods into Valhalla in /home/anthony/rendu/cpp/indie/Indie_studio
//
// Made by Anthony Jouvel
// Login   <anthony.jouvel@epitech.eu>
//
// Started on  Fri May 12 14:07:46 2017 Anthony Jouvel
// Last update Fri Jun  2 13:23:01 2017 Pashervz
//

#include <iostream>
#include <cmath>
#include "Graphic.hpp"
#include "Button.hpp"
#include "ManageGame.hpp"
#include "GameElement.hpp"

const irr::f32 Graphic::SQUARE_SIZE = 10.f;

#ifdef _MSC_VER
#pragma comment(lib, "Irrlicht.lib")
#endif


Graphic::Graphic(irr::u32 width, irr::u32 height) : _width(width), _height(height)
{
  _device	= irr::createDevice(irr::video::EDT_OPENGL,
				    irr::core::dimension2d<irr::u32>(_width, _height),
				    32);

  _driver	= _device->getVideoDriver();
  _sceneManager = _device->getSceneManager();

  _device->getCursorControl()->setVisible(false);

  _guienv	= _device->getGUIEnvironment();

  _camera.initCamera(_sceneManager,
		     irr::core::vector3df(5035, 806, 4877),
		     irr::core::vector3df(5066, 808, 4824));

  this->initMainMenu();
  this->initOptMenu();
  this->initBindings();
  this->skyDome("assets/moon.png");
  this->ground();
  this->constructMenuArea();
  // this->constructGameArea();
}

Graphic::~Graphic()
{
  _device->drop();
}

void		Graphic::manageDisplay(std::vector<std::shared_ptr<Element>> const& map, DType type)
{
  if (!_device->run())
    return ;

  this->dispThis[type](map);
  _driver->beginScene(true, true,
		      irr::video::SColor(0, 255, 255, 255));
  _sceneManager->drawAll();
  _guienv->drawAll();
  _driver->endScene();
}

// ------------------------------------------------------------ //
// ------------------------ SCENE METHODS --------------------- //
// ------------------------------------------------------------ //

void		Graphic::ground()
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
				     16, 16, 1.f, 2.0f);
}

// ------------------------------------------------------------ //
// ------------------------ MENU METHODS ---------------------- //
// ------------------------------------------------------------ //

void			Graphic::constructMenuArea()
{

}

void						Graphic::initMainMenu()
{
  std::vector<irr::f32>				initPos;
  std::vector<irr::f32>				initTextDim;
  irr::video::SColor				color(255, 255, 255, 0);

  initPos.push_back(5070.f);
  initPos.push_back(830.f);
  initPos.push_back(4820.f);
  initTextDim.push_back(35.f);
  initTextDim.push_back(10.f);
  _buttonMM.push_back(std::unique_ptr<GButton>(new GButton(initPos,
							   initTextDim,
							   L"play",
							   color)));
  initPos.at(1) = 810.f;
  // initTextDim[0] += 15;
  // initTextDim[1] += 5;
  _buttonMM.push_back(std::unique_ptr<GButton>(new GButton(initPos,
							   initTextDim,
							   L"scores",
							   color)));
  initPos.at(1) = 790.f;
  // initTextDim[0] -= 15;
  // initTextDim[1] -= 5;
  _buttonMM.push_back(std::unique_ptr<GButton>(new GButton(initPos,
							   initTextDim,
							   L"options",
							   color)));
  initPos.at(1) = 770.f;
  _buttonMM.push_back(std::unique_ptr<GButton>(new GButton(initPos,
							   initTextDim,
							   L"exit",
							   color)));
  for (auto it = _buttonMM.begin() ; it != _buttonMM.end() ; ++it)
    it->get()->setButton(_sceneManager, _guienv);
}

void						Graphic::initOptMenu()
{
  std::vector<irr::f32>				initPos;
  std::vector<irr::f32>				initTextDim;
  irr::video::SColor				color(255, 255, 255, 0);


  initPos.push_back(4960);
  initPos.push_back(823);
  initPos.push_back(4828);
  initTextDim.push_back(10.f);
  initTextDim.push_back(10.f);
  _buttonOpt.push_back(std::unique_ptr<GButton>(new GButton(initPos,
							    initTextDim,
							    L"p1",
							    color)));
  initPos[0] = 4950;
  initPos[2] = 4840;
  _buttonOpt.push_back(std::unique_ptr<GButton>(new GButton(initPos,
							    initTextDim,
							    L"p2",
							    color)));
  initPos[0] = 4940;
  initPos[2] = 4852;
  _buttonOpt.push_back(std::unique_ptr<GButton>(new GButton(initPos,
							    initTextDim,
							    L"p3",
							    color)));
  initPos[0] = 4930;
  initPos[2] = 4864;
  _buttonOpt.push_back(std::unique_ptr<GButton>(new GButton(initPos,
							    initTextDim,
							    L"p4",
							    color)));
  initPos[0] = 4960;
  initPos[1] = 804;
  initPos[2] = 4828;
  _buttonOpt.push_back(std::unique_ptr<GButton>(new GButton(initPos,
							    initTextDim,
							    L"on",
							    color)));
  initPos[1] = 783;
  _buttonOpt.push_back(std::unique_ptr<GButton>(new GButton(initPos,
							    initTextDim,
							    L"off",
							    color)));
  
  for (auto it = _buttonOpt.begin() ; it != _buttonOpt.end() ; ++it)
    it->get()->setButton(_sceneManager, _guienv);
  initTextDim[0] = 25;
  initTextDim[1] = 10;
  _sceneManager->addBillboardTextSceneNode(_guienv->getFont("assets/font/myfont.xml"),
				     L"options", 0,
				     irr::core::dimension2d<irr::f32>(50, 20),
				   irr::core::vector3df(4940, 855, 4820),
				   -1, color, color);
  _sceneManager->addBillboardTextSceneNode(_guienv->getFont("assets/font/myfont.xml"),
				     L"bindings", 0,
				     irr::core::dimension2d<irr::f32>(initTextDim[0], initTextDim[1]),
				   irr::core::vector3df(4985, 822.5f, 4806),
				     -1, color, color);
  _sceneManager->addBillboardTextSceneNode(_guienv->getFont("assets/font/myfont.xml"),
				     L"music", 0,
				     irr::core::dimension2d<irr::f32>(initTextDim[0], initTextDim[1]),
				   irr::core::vector3df(4985, 805, 4806),
				     -1, color, color);
  _sceneManager->addBillboardTextSceneNode(_guienv->getFont("assets/font/myfont.xml"),
				     L"audio", 0,
				     irr::core::dimension2d<irr::f32>(initTextDim[0], initTextDim[1]),
				   irr::core::vector3df(4985, 785, 4806),
				     -1, color, color);
}

void		Graphic::initBindings()
{
  std::vector<irr::f32>				initPos;
  std::vector<irr::f32>				initTextDim;
  irr::video::SColor				color(255, 255, 255, 0);


  initPos.push_back(4970);
  initPos.push_back(1025);
  initPos.push_back(4810);
  initTextDim.push_back(10.f);
  initTextDim.push_back(10.f);
  _buttonB.push_back(std::unique_ptr<GButton>(new GButton(initPos,
							    initTextDim,
							    L"z",
							    color)));
  initPos[0] = 4900;
  initPos[2] = 4880;
  _buttonB.push_back(std::unique_ptr<GButton>(new GButton(initPos,
							    initTextDim,
							    L"q",
							    color)));
  initPos[0] = 4970;
  initPos[1] = 1004;
  initPos[2] = 4810;
  _buttonB.push_back(std::unique_ptr<GButton>(new GButton(initPos,
							    initTextDim,
							    L"s",
							    color)));
    
  initPos[0] = 4900;
  initPos[1] = 1003;
  initPos[2] = 4880;
  _buttonB.push_back(std::unique_ptr<GButton>(new GButton(initPos,
							    initTextDim,
							    L"d",
							    color)));
  initPos[0] = 4940;
  initPos[1] = 970;
  initPos[2] = 4820;
  _buttonB.push_back(std::unique_ptr<GButton>(new GButton(initPos,
							    initTextDim,
							    L"e",
							    color)));
  
  for (auto it = _buttonB.begin() ; it != _buttonB.end() ; ++it)
    it->get()->setButton(_sceneManager, _guienv);
  initTextDim[0] = 25;
  initTextDim[1] = 10;
  _sceneManager->addBillboardTextSceneNode(_guienv->getFont("assets/font/myfont.xml"),
					   L"bindings", 0,
					   irr::core::dimension2d<irr::f32>(50, 20),
					   irr::core::vector3df(4940, 1055, 4820),
					   -1, color, color);
  _sceneManager->addBillboardTextSceneNode(_guienv->getFont("assets/font/myfont.xml"),
					   L"forward", 0,
					   irr::core::dimension2d<irr::f32>(initTextDim[0], initTextDim[1]),
					   irr::core::vector3df(4990, 1022.5f, 4806),
					   -1, color, color);
  _sceneManager->addBillboardTextSceneNode(_guienv->getFont("assets/font/myfont.xml"),
					   L"left", 0,
					   irr::core::dimension2d<irr::f32>(initTextDim[0], initTextDim[1]),
					   irr::core::vector3df(4990, 1005, 4806),
					   -1, color, color);
  _sceneManager->addBillboardTextSceneNode(_guienv->getFont("assets/font/myfont.xml"),
					   L"backward", 0,
					   irr::core::dimension2d<irr::f32>(initTextDim[0], initTextDim[1]),
					   irr::core::vector3df(4940, 1021, 4864),
					   -1, color, color);
  _sceneManager->addBillboardTextSceneNode(_guienv->getFont("assets/font/myfont.xml"),
					   L"right", 0,
					   irr::core::dimension2d<irr::f32>(initTextDim[0], initTextDim[1]),
					   irr::core::vector3df(4940, 1005, 4864),
					   -1, color, color);
  _sceneManager->addBillboardTextSceneNode(_guienv->getFont("assets/font/myfont.xml"),
					   L"object", 0,
					   irr::core::dimension2d<irr::f32>(50, 20),
					   irr::core::vector3df(4940, 985, 4820),
					   -1, color, color);
}

void			Graphic::displayMainMenu(std::vector<std::shared_ptr<Element>> const& map)
{
  int			idx = 0;

  _camera.moveCamera(irr::core::vector3df(5035, 806, 4877),
		     irr::core::vector3df(5066, 808, 4824));
  for (auto it = map.begin() ; it != map.end() ; ++it)
    {
      if (static_cast<Button *>(it->get())->getIsSelected() == true)
	{
	  _buttonMM[idx].get()->_button->setText(static_cast<Button *>
						 (it->get())->getContent().c_str());
	  _buttonMM[idx].get()->_button->setColor(irr::video::SColor(255, 255, 0, 0));
	}
      else
	{
	  _buttonMM[idx].get()->_button->setText(static_cast<Button *>
						 (it->get())->getContent().c_str());
	  _buttonMM[idx].get()->_button->setColor(irr::video::SColor(255, 255, 255, 0));
	}
      ++idx;
    }
}

void		Graphic::displayOptions(std::vector<std::shared_ptr<Element>> const& map)
{
  int			idx = 0;

  _camera.moveCamera(irr::core::vector3df(4998, 807, 4873),
		     irr::core::vector3df(4985, 808, 4861));
  for (auto it = map.begin() ; it != map.end() ; ++it)
    {
      if (static_cast<Button *>(it->get())->getIsSelected() == true)
	{
	  _buttonOpt[idx].get()->_button->setText(static_cast<Button *>(it->get())->getContent().c_str());
	  _buttonOpt[idx].get()->_button->setColor(irr::video::SColor(255, 0, 255, 0));
	}
      else
	{
	  _buttonOpt[idx].get()->_button->setText(static_cast<Button *>
						  (it->get())->getContent().c_str());
	  _buttonOpt[idx].get()->_button->setColor(irr::video::SColor(255, 255, 255, 0));
	}
      ++idx;
    }
}

void		Graphic::displayBindings(std::vector<std::shared_ptr<Element>> const& map)
{
  int			idx = 0;

  _camera.moveCamera(irr::core::vector3df(4998, 1007, 4873),
		     irr::core::vector3df(4985, 1008, 4861));
  for (auto it = map.begin() ; it != map.end() ; ++it)
    {
      if (static_cast<Button *>(it->get())->getIsSelected() == true)
	{
	  _buttonB[idx].get()->_button->setText(static_cast<Button *>(it->get())->getContent().c_str());
	  _buttonB[idx].get()->_button->setColor(irr::video::SColor(255, 0, 0, 255));
	}
      else
	{
	  _buttonB[idx].get()->_button->setText(static_cast<Button *>
						  (it->get())->getContent().c_str());
	  _buttonB[idx].get()->_button->setColor(irr::video::SColor(255, 255, 255, 0));
	}
      ++idx;
    }
}

void		Graphic::displayLeaderBoard(std::vector<std::shared_ptr<Element>> const&)
{
}

void		Graphic::displayExit(std::vector<std::shared_ptr<Element>> const&)
{
  // Utiliser __guienv pour afficher une fenetre avec les boutons YES et NO http://irrlicht.sourceforge.net/docu/example005.html
}

// ------------------------------------------------------------ //
// ------------------------ GAME METHODS ---------------------- //
// ------------------------------------------------------------ //

void		Graphic::displayCar(std::vector<std::shared_ptr<Element>> const&)
{

}

void		Graphic::setCar(Element::EType type,
				irr::io::path path,
				irr::f32 x,
				irr::f32 y,
				irr::f32 z)
{
  pods[type] = _sceneManager->addAnimatedMeshSceneNode(_sceneManager->getMesh(path),
						       0, -1, irr::core::vector3df(x, y, z), // POSITION
						       irr::core::vector3df(0.f, 270.f, 0.f), // DIRECTION
						       irr::core::vector3df(.010f, .010f, .010f)); // ECHELLE
  pods[type]->setMaterialFlag(irr::video::EMF_LIGHTING, false);
}

void		Graphic::initMap(std::shared_ptr<Element> const& elem,
				 irr::f32 x, irr::f32 y, irr::f32 z)
{
  irr::scene::IMeshSceneNode        *cube =
    _sceneManager->addCubeSceneNode(10.0f, 0, -1,
				    irr::core::vector3df(x, y, z),
				    irr::core::vector3df(0.f, 0.f, 0.f));
  irr::scene::IMeshSceneNode        *wall;

  //  std::cout << ">> In initMap" << std::endl;
  switch (elem->getType())
    {
    case Element::EType::BLOCK :
      cube->setMaterialTexture(0, _driver->getTexture("assets/wall.jpg"));
      wall = _sceneManager->addCubeSceneNode(10.0f, 0, -1,
					     irr::core::vector3df(x, y + 10.f, z),
					     irr::core::vector3df(0.f, 0.f, 0.f));
      wall->setMaterialTexture(0, _driver->getTexture("assets/wall.jpg"));
      wall->setMaterialFlag(irr::video::EMF_LIGHTING, false);
      wall->setMaterialType(irr::video::EMT_SOLID);
      break ;
    case Element::EType::ROAD :
      cube->setMaterialTexture(0, _driver->getTexture("assets/road.jpg"));
      break ;
    case Element::EType::ENDLINE :
      cube->setMaterialTexture(0, _driver->getTexture("assets/start.jpg"));
      break ;
    case Element::EType::POD1 :
      cube->setMaterialTexture(0, _driver->getTexture("assets/road.JPG"));
      this->setCar(elem->getType(), elem->getPath(), x, y, z);
      break ;
    case Element::EType::POD2 :
      cube->setMaterialTexture(0, _driver->getTexture("assets/road.JPG"));
      this->setCar(elem->getType(), elem->getPath(), x, y, z);
      break ;
    case Element::EType::POD3 :
      cube->setMaterialTexture(0, _driver->getTexture("assets/road.JPG"));
      this->setCar(elem->getType(), elem->getPath(), x, y, z);
      break ;
    case Element::EType::POD4 :
      cube->setMaterialTexture(0, _driver->getTexture("assets/road.JPG"));
      this->setCar(elem->getType(), elem->getPath(), x, y, z);
      break ;
    default :
      break ;
    }
  cube->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  cube->setMaterialType(irr::video::EMT_SOLID);
}

void		Graphic::displayGame(std::vector<std::shared_ptr<Element>> const& map)
{
  int		i = 0;
  irr::f32	x = 5330.f;
  irr::f32	y = 560.f;
  irr::f32	z = 5225.f;
  static bool	first = true;

  _camera.moveCamera(irr::core::vector3df(5097.f, 860.f, 5175.f),
		     irr::core::vector3df(5096.f, 563.f, 5451.f));
  for (auto const& elem : map)
    {
      // std::cout << elem->getPath()[0];
      if (i % 60 == 0)
	{
	  // std::cout << std::endl;
	  x = 5330.f;
	  z += SQUARE_SIZE;
	}
      if (first)
	this->initMap(elem, x, y, z);
      Element::EType type		= elem->getType();
      if (type == Element::EType::POD1
	  || type == Element::EType::POD2
	  || type == Element::EType::POD3
	  || type == Element::EType::POD4)
	{
	  irr::core::vector3df newPos	= this->pods[type]->getPosition();
	  newPos.X = x - SQUARE_SIZE * static_cast<GameElement *>(elem.get())->getPos().first / 100;
	  newPos.Z = z + SQUARE_SIZE * static_cast<GameElement *>(elem.get())->getPos().second / 100;
	  this->pods[type]->setPosition(newPos);
	  irr::f32 newAng		=  static_cast<Car *>(elem.get())->getAbsoluteAngle();
	  this->pods[type]->setRotation(irr::core::vector3df(0, 360.f - (newAng + 90.f), 0));
	}
      x -= 10.f;
      ++i;
    }
  // std::cout << std::endl;
  first = false;
  std::cout << "QUIT DISPLAY" << std::endl;
}

// ------------------------------------------------------------ //
// ----------------------- UTILS METHODS ---------------------- //
// ------------------------------------------------------------ //

void		Graphic::actualize(Observable const& observable)
{
  this->manageDisplay(observable.getMap(), observable.getDType());
}

bool		Graphic::running(void)
{
  return (_device->run());
}


void		Graphic::setEventReceiver(irr::IEventReceiver *receiver)
{
  _device->setEventReceiver(receiver);
}


// THIS WAS IN MANAGE_DISPLAY
// moveCamera(irr::core::vector3df(5600, 690, 5400),
//	     irr::core::vector3df(5600, 690, 5450));
// moveCamera(irr::core::vector3df(5400, 600, 5200),
//	     irr::core::vector3df(5550, ++y, 5215));

// tmp camera
// static int y = 590;
// _camera->setRotation(irr::core::vector3df(0,--y,0));
// _camera->bindTargetAndRotation(true);
// tmp camera

// if (y == 0)
//   y = 590;
//  irr::core::stringw str = y;
// irr::core::stringw str = L"X = ";
// str += _camera->getAbsolutePosition().X;
// str += L" Y = ";
// str += _camera->getAbsolutePosition().Y;
// str += L" Z = ";
// str += _camera->getAbsolutePosition().Z;
//  _device->setWindowCaption(str.c_str());
