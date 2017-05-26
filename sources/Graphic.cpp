//
// Graphic.cpp for Entrance of the Gods into Valhalla in /home/anthony/rendu/cpp/indie/Indie_studio
//
// Made by Anthony Jouvel
// Login   <anthony.jouvel@epitech.eu>
//
// Started on  Fri May 12 14:07:46 2017 Anthony Jouvel
// Last update Fri May 26 11:19:00 2017 Lebrun Kilian
//

#include <iostream>
#include "Graphic.hpp"
#include "Button.hpp"
#include "ManageGame.hpp"
#include "GameElement.hpp"

const irr::f32 Graphic::SQUARE_SIZE = 10.f;

Graphic::Graphic(irr::u32 width, irr::u32 height) : _width(width), _height(height)
{
  _device = irr::createDevice(irr::video::EDT_OPENGL,
			      irr::core::dimension2d<irr::u32>(width, height),
			      32);

  _driver = _device->getVideoDriver();
  _sceneManager = _device->getSceneManager();

  _device->getCursorControl()->setVisible(false);

  _guienv = _device->getGUIEnvironment();

  _camera = _sceneManager->addCameraSceneNode(0, irr::core::vector3df(5400, 600, 5200), irr::core::vector3df(5350, 590, 5215));

  skyDome("assets/moon.png");
  ground();
}

Graphic::Graphic()
{
  _device = irr::createDevice(irr::video::EDT_OPENGL,
			      irr::core::dimension2d<irr::u32>(1920, 1080),
			      32);

  _driver = _device->getVideoDriver();
  _sceneManager = _device->getSceneManager();

  _device->getCursorControl()->setVisible(false);

  _guienv = _device->getGUIEnvironment();

  _camera = _sceneManager->addCameraSceneNode(0, irr::core::vector3df(5097.f, 860.f, 5175.f),
					      irr::core::vector3df(5096.f, 563.f, 5451.f));

  // skyDome("assets/moon.png");
  ground();
}

Graphic::~Graphic()
{
  _device->drop();
}

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

irr::f32	Graphic::coords(irr::f32 oldPoint, irr::f32 newPoint)
{
  if (oldPoint < newPoint)
    return (oldPoint + 1);
  else if (oldPoint > newPoint)
    return (oldPoint - 1);
  return (newPoint);
}

void		Graphic::moveCamera(irr::core::vector3df pos, irr::core::vector3df targ)
{
  _camera->setPosition(irr::core::vector3df(coords(_camera->getAbsolutePosition().X, pos.X),
					    coords(_camera->getAbsolutePosition().Y, pos.Y),
					    coords(_camera->getAbsolutePosition().Z, pos.Z)));

  _camera->setTarget(irr::core::vector3df(coords(_camera->getTarget().X, targ.X),
					  coords(_camera->getTarget().Y, targ.Y),
					  coords(_camera->getTarget().Z, targ.Z)));
}

void		Graphic::actualize(Observable const& observable)
{
  this->manageDisplay(observable.getMap(), observable.getDType());
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
}

void		Graphic::writeText(irr::scene::IMeshSceneNode *cube,
				   const wchar_t *text)
{
  // ECRIRE SUR UN CUBE
  _sceneManager->addTextSceneNode(_guienv->getFont("assets/font/myfont.xml"),
				  text,
				  irr::video::SColor(255, 255, 255, 0),
				  cube);
}

void		Graphic::writeText(irr::f32 xPos, irr::f32 yPos, irr::f32 zPos,
				   const wchar_t *text)
{
  // ECRIRE A UNE POSITION
  static int	i = 0;
  if (i < 8)
    {
      _sceneManager->addBillboardTextSceneNode(_guienv->getFont("assets/font/myfont.xml"),
					       text, 0,
					       irr::core::dimension2d<irr::f32>(25.f, 10.f),
					       irr::core::vector3df(xPos + 5.7f,
								    yPos + 2,
								    zPos), -1,
					       irr::video::SColor(255,255,255, 0),
					       irr::video::SColor(255,255,255, 0));
    }
  else
    _sceneManager->addBillboardTextSceneNode(_guienv->getFont("assets/font/myfont.xml"),
					     text, 0,
					     irr::core::dimension2d<irr::f32>(25.f, 10.f),
					     irr::core::vector3df(xPos,
								  yPos + 2,
								  zPos - 5.7f), -1,
					     irr::video::SColor(255,255,255, 0),
					     irr::video::SColor(255,255,255, 0));
  ++i;
}

void		Graphic::writeText(irr::s32 x, irr::s32 y,
				   irr::s32 xBord, irr::s32 yBord,
				   const wchar_t *text)
{
  // ECRIRE SUR LA FENETRE (STATIC)
  irr::gui::IGUISkin* skin = _guienv->getSkin();
  irr::gui::IGUIFont* font = _guienv->getFont("assets/font/myfont.xml");
  skin->setFont(font);
  skin->setColor(irr::gui::EGDC_BUTTON_TEXT, irr::video::SColor(255,255,255, 0));
  // LIGNE D'EXEMPLE
  //  _guienv->addStaticText(text, irr::core::rect<irr::s32>(10, 10, 1000, 1000), false);
  _guienv->addStaticText(text, irr::core::rect<irr::s32>(x, y, xBord, yBord), false);
}

void		Graphic::button(irr::f32 xPos, irr::f32 yPos, irr::f32 zPos,
				irr::f32 xRot, irr::f32 yRot, irr::f32 zRot,
				const wchar_t *text,
				const irr::io::path& filename,
				bool const& selected)
{
  irr::scene::IMeshSceneNode	*cube =
    _sceneManager->addCubeSceneNode(10.0f, 0, -1,
				    irr::core::vector3df(xPos, yPos, zPos),
				    irr::core::vector3df(xRot, yRot, zRot));

  cube->setScale(irr::core::vector3df(5.0f, 1.0f, 1.0f));

  cube->setMaterialTexture(0, _driver->getTexture(filename));
  if (selected)
    {
      // FAIRE la selection
    }
  cube->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  cube->setMaterialType(irr::video::EMT_SOLID);

  writeText(xPos, yPos, zPos, text);
}

void		Graphic::displayMainMenu(std::vector<std::shared_ptr<Element>> const& map)
{
  irr::f32	y = 620.f;
  //tmp pour test mouvement
  irr::f32	yBis = 720.f;

  // irr::core::vector3df(5400, 600, 5200)
  // irr::core::vector3df(5350, 590, 5215)
  for (auto it = map.begin(); it != map.end(); ++it)
    {
      button(5330.f, y, 5225.0f, 0.f, 107.f, 0.f,
	     static_cast<Button *>(it->get())->getContent().c_str(),
	     (it->get())->getPath(), static_cast<Button *>(it->get())->getIsSelected());

      //tmp pour test mouvement
      button(5600.f, yBis, 5455.0f, 0.f, 0.f, 0.f,
	     static_cast<Button *>(it->get())->getContent().c_str(),
	     (it->get())->getPath(), static_cast<Button *>(it->get())->getIsSelected());

      y -= 20.f;
      //tmp pour test mouvement
      yBis -= 20.f;
    }
}

void		Graphic::displayOptions(std::vector<std::shared_ptr<Element>> const& map)
{
  irr::f32	y = 660.f;

  // irr::core::vector3df(5800, 700, 5600)
  // irr::core::vector3df(5850, 690, 5815)
  for (auto it = map.begin(); it != map.end(); ++it)
    {
      button(5850.f, y, 5815.0f, 0.f, 0.f, 0.f,
	     static_cast<Button *>(it->get())->getContent().c_str(),
	     (it->get())->getPath(), static_cast<Button *>(it->get())->getIsSelected());
      y += 20.f;
    }
}

void		Graphic::displayLeaderBoard(std::vector<std::shared_ptr<Element>> const&)
{

}

void		Graphic::displayExit(std::vector<std::shared_ptr<Element>> const&)
{
  // Utiliser __guienv pour afficher une fenetre avec les boutons YES et NO http://irrlicht.sourceforge.net/docu/example005.html
}

void		Graphic::displayCar(std::vector<std::shared_ptr<Element>> const&)
{
  // Les methodes utiles pour connaitre l'orientation de la voiture sont dans GameElement et Car (getAbsoluteAngle)
}

void		Graphic::setCar(char c, irr::f32 x, irr::f32 y, irr::f32 z)
{
  pods[c] = _sceneManager->addAnimatedMeshSceneNode(_sceneManager->getMesh("assets/Anakin_podracer/AnakinsPodRacer.obj"), // Faire un getPath ici
						    0, -1, irr::core::vector3df(x, y, z), // POSITION
						    irr::core::vector3df(0.f, -90.f, 0.f), // DIRECTION
						    irr::core::vector3df(.010f, .010f, .010f)); // ECHELLE
  pods[c]->setMaterialFlag(irr::video::EMF_LIGHTING, false);
}

void		Graphic::initMap(std::shared_ptr<Element> const& elem,
				 irr::f32 x, irr::f32 y, irr::f32 z)
{
  irr::scene::IMeshSceneNode        *cube =
    _sceneManager->addCubeSceneNode(10.0f, 0, -1,
				    irr::core::vector3df(x, y, z),
				    irr::core::vector3df(0.f, 0.f, 0.f));
  irr::scene::IMeshSceneNode        *wall;

  std::cout << ">> In initMap" << std::endl;
  switch (elem->getPath()[0])
    {
    case 'X' :
      cube->setMaterialTexture(0, _driver->getTexture("assets/wall.jpg"));
      wall = _sceneManager->addCubeSceneNode(10.0f, 0, -1,
					     irr::core::vector3df(x, y + 10.f, z),
					     irr::core::vector3df(0.f, 0.f, 0.f));
      wall->setMaterialTexture(0, _driver->getTexture("assets/wall.jpg"));
      wall->setMaterialFlag(irr::video::EMF_LIGHTING, false);
      wall->setMaterialType(irr::video::EMT_SOLID);
      break ;
    case ' ' :
      cube->setMaterialTexture(0, _driver->getTexture("assets/road.jpg"));
      break ;
    case 'c' :
      cube->setMaterialTexture(0, _driver->getTexture("assets/start.jpg"));
      break ;
    case 'o' :
      cube->setMaterialTexture(0, _driver->getTexture("assets/start.jpg"));
      break ;
    case '>' :
      cube->setMaterialTexture(0, _driver->getTexture("assets/road.JPG"));
      this->setCar('>', x, y, z);
      break ;
    case 'p' :
      cube->setMaterialTexture(0, _driver->getTexture("assets/road.JPG"));
      this->setCar('p', x, y, z);
      break ;
    case 's' :
      cube->setMaterialTexture(0, _driver->getTexture("assets/road.JPG"));
      this->setCar('s', x, y, z);
      break ;
    case 'g' :
      cube->setMaterialTexture(0, _driver->getTexture("assets/road.JPG"));
      this->setCar('g', x, y, z);
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

  if (first)
    this->moveCamera(irr::core::vector3df(5097.f, 860.f, 5175.f),
		     irr::core::vector3df(5096.f, 563.f, 5451.f));
  for (auto const& elem : map)
    {
      if (i % 50 == 0)
	{
	  x = 5330.f;
	  z += SQUARE_SIZE;
	}
      if (first)
	this->initMap(elem, x, y, z);
      if (elem->getType() == Element::EType::CAR)
	{
	  //	  std::cout << "Car = " << elem->getPath()[0] << std::endl;
	  irr::core::vector3df newPos = this->pods[elem->getPath()[0]]->getPosition();
	  newPos.X = x - 10.f * static_cast<GameElement *>(elem.get())->getPos().first / 100;
	  newPos.Z = z + 10.f * static_cast<GameElement *>(elem.get())->getPos().second / 100;
	  this->pods[elem->getPath()[0]]->setPosition(newPos);
	}
      x -= 10.f;
      ++i;
    }
  first = false;
  std::cout << "QUIT DISPLAY" << std::endl;
}

bool		Graphic::running(void)
{
  return (this->_device->run());
}

void		Graphic::setEventReceiver(irr::IEventReceiver *receiver)
{
  this->_device->setEventReceiver(receiver);
}
