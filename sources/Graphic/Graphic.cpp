//
// Graphic.cpp for Entrance of the Gods into Valhalla in /home/anthony/rendu/cpp/indie/Indie_studio
//
// Made by Anthony Jouvel
// Login   <anthony.jouvel@epitech.eu>
//
// Started on  Fri May 12 14:07:46 2017 Anthony Jouvel
// Last update Thu Jun  1 17:31:56 2017 Pierre Zawadil
//

#include <iostream>
#include <cmath>
#include "Error.hpp"
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
  //_sceneManager->addExternalMeshLoader(new IrrAssimpImport(_sceneManager));

  _device->getCursorControl()->setVisible(false);

  _guienv	= _device->getGUIEnvironment();

  _camera.initCamera(_sceneManager,
		     irr::core::vector3df(5035, 806, 4877),
		     irr::core::vector3df(5066, 808, 4824));

  this->initMainMenu();
  this->initOptMenu();
  this->skyDome("assets/moon.png");
  this->ground();
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

void		Graphic::displayLeaderBoard(std::vector<std::shared_ptr<Element>> const&)
{

}

// ------------------------------------------------------------ //
// ------------------------ GAME METHODS ---------------------- //
// ------------------------------------------------------------ //

void		Graphic::displayCar(std::vector<std::shared_ptr<Element>> const&)
{

}

void		Graphic::setCar(Element::EType type,
				irr::io::path,
				irr::f32 x,
				irr::f32 y,
				irr::f32 z)
{
  pods[type] = _sceneManager->addAnimatedMeshSceneNode(_sceneManager->getMesh("./assets/Anakin_podracer/AnakinsPodRacer.obj"),
						       0, -1, irr::core::vector3df(x, y, z),
						       irr::core::vector3df(0.f, 270.f, 0.f),
						       irr::core::vector3df(0.01f, 0.01f, 0.01f));
  if (pods[type] != NULL)
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
      if (i % 60 == 0)
	{
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
  first = false;
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
