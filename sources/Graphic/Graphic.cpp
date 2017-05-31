//
// Graphic.cpp for Entrance of the Gods into Valhalla in /home/anthony/rendu/cpp/indie/Indie_studio
//
// Made by Anthony Jouvel
// Login   <anthony.jouvel@epitech.eu>
//
// Started on  Fri May 12 14:07:46 2017 Anthony Jouvel
// Last update Wed May 31 15:35:49 2017 Pashervz
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

  _camera	= _sceneManager->addCameraSceneNode(0,
						    irr::core::vector3df(5033.72f,
									 804.74f,
									 5212.25f),
						    irr::core::vector3df(5033.79f,
									 576.37f,
									 5373.57f));
  _camera->setPosition(irr::core::vector3df(5035.62f, 806.83f, 4877.94f));
  _camera->setTarget(irr::core::vector3df(5066.22f, 808.67f, 4824.34f));
  _camera->setFarValue(42000.0f);
  this->initMainMenu();
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
							   "assets/deathStar.jpg",
							   color)));
  initPos.at(1) = 810.f;
  // initTextDim[0] += 15;
  // initTextDim[1] += 5;
  _buttonMM.push_back(std::unique_ptr<GButton>(new GButton(initPos,
							   initTextDim,
							   L"scores",
							   "assets/deathStar.jpg",
							   color)));
  initPos.at(1) = 790.f;
  // initTextDim[0] -= 15;
  // initTextDim[1] -= 5;
  _buttonMM.push_back(std::unique_ptr<GButton>(new GButton(initPos,
							   initTextDim,
							   L"options",
							   "assets/deathStar.jpg",
							   color)));
  initPos.at(1) = 770.f;
  _buttonMM.push_back(std::unique_ptr<GButton>(new GButton(initPos,
							   initTextDim,
							   L"quit",
							   "assets/deathStar.jpg",
							   color)));
  for (auto it = _buttonMM.begin() ; it != _buttonMM.end() ; ++it)
    it->get()->setButton(_sceneManager, _guienv);
}

void			Graphic::displayMainMenu(std::vector<std::shared_ptr<Element>> const& map)
{
  int			idx = 0;

  for (auto it = map.begin() ; it != map.end() ; ++it)
    {
      if (static_cast<Button *>(it->get())->getIsSelected() == true)
	_buttonMM[idx].get()->_button->setColor(irr::video::SColor(255, 255, 0, 0));
      else
	_buttonMM[idx].get()->_button->setColor(irr::video::SColor(255, 255, 255, 0));
      ++idx;
    }
}

void		Graphic::displayOptions(std::vector<std::shared_ptr<Element>> const&)
{
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
  std::cout << "First pos x = " << x << ", y = " << y << ", z = " << z << std::endl;
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

  // if (first)
  //   this->moveCamera(irr::core::vector3df(5097.f, 860.f, 5175.f),
  //		     irr::core::vector3df(5096.f, 563.f, 5451.f));
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

irr::f32	Graphic::coords(irr::f32 oldPoint,
				irr::f32 newPoint)
{
  if (oldPoint < newPoint)
    return (oldPoint + 1);
  else if (oldPoint > newPoint)
    return (oldPoint - 1);
  return (newPoint);
}

void		Graphic::setEventReceiver(irr::IEventReceiver *receiver)
{
  _device->setEventReceiver(receiver);
}

void		Graphic::moveCamera(irr::core::vector3df pos,
				    irr::core::vector3df targ)
{
  _camera->setPosition(irr::core::vector3df(coords(_camera->getAbsolutePosition().X, pos.X),
					    coords(_camera->getAbsolutePosition().Y, pos.Y),
					    coords(_camera->getAbsolutePosition().Z, pos.Z)));

  _camera->setTarget(irr::core::vector3df(coords(_camera->getTarget().X, targ.X),
					  coords(_camera->getTarget().Y, targ.Y),
					  coords(_camera->getTarget().Z, targ.Z)));
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
