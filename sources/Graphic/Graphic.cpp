//
// Graphic.cpp for Entrance of the Gods into Valhalla in /home/anthony/rendu/cpp/indie/Indie_studio
//
// Made by Anthony Jouvel
// Login   <anthony.jouvel@epitech.eu>
//
// Started on  Fri May 12 14:07:46 2017 Anthony Jouvel
// Last update Sun Jun 18 13:30:01 2017 Pashervz
//

#include <sstream>
#include <iostream>
#include <cmath>
#include <string>
#include <random>
#include <stdexcept>
#include "Error.hpp"
#include "Graphic.hpp"
#include "Button.hpp"
#include "ManageGame.hpp"
#include "GameElement.hpp"
#include "ManageFile.hpp"

#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(lib, "irrKlang.lib")
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif

const irr::f32		Graphic::_squareSize = 10.f;

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

  _skin = _guienv->getSkin();
  _font = _guienv->getFont("assets/font/myfont.xml");
  _skin->setFont(_font);

   _camera.initCamera(_sceneManager, irr::core::vector3df(5100, 856, 4759),
		     irr::core::vector3df(5109, 872, 4747));
  // _camera.initCamera(_sceneManager,
  //		     irr::core::vector3df(5035, 806, 4877),
  //		     irr::core::vector3df(5066, 808, 4824));
  // _camera.initCamera(_sceneManager, irr::core::vector3df(5033.f, 838.f, 5126.f),
  //		     irr::core::vector3df(5033.f, 770.f, 5172.f));
  this->loadIntro();
  _music.playMusic("assets/music/star-wars-cantina-song.ogg");
  _music.setVol(0.3f);
  this->initMainMenu();
  this->skyDome("assets/skydome.jpg");
  this->ground();
  _device->setWindowCaption(L"STAR WARS - PodRacer");
  // POUR LE LOGO - TITRE DU JEU
}

Graphic::~Graphic()
{
  _device->drop();
}

void				Graphic::loadIntro()
{
}

void		Graphic::manageDisplay(std::vector<std::shared_ptr<Element>> const& map, DType type)
{
  if (!_device->run())
    return ;
  this->dispThis[type](map);
  _driver->beginScene(true, true,
		      irr::video::SColor(0, 255, 255, 255));
  _sceneManager->drawAll();
  _device->getGUIEnvironment()->drawAll();
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

  if (!terrain)
    throw (Error("Terrain asset not found"));

  //_sceneManager->getMeshManipulator()->makePlanarTextureMapping(terrain->getMesh(), 0.04f);
  terrain->setMaterialTexture(0, _driver->getTexture("assets/snow.jpg"));
  terrain->getMaterial(0).getTextureMatrix(0).setTextureScale(14, 14);

  // terrain->setMaterialTexture(0, _driver->getTexture("assets/snow.jpg"));
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
  std::vector<irr::f32>				initPos = {5070.f, 830.f, 4820.f};
  std::vector<irr::f32>				initTextDim = {35.f, 10.f};
  irr::video::SColor				color(255, 255, 255, 0);
  irr::video::SColor				title(255, 121, 248, 248);
  std::vector<const wchar_t *>			NameMainMenu = {L"play",
								L"scores",
								L"options",
								L"exit"};

  _sceneManager->addBillboardTextSceneNode(_guienv->getFont("assets/font/title/myfont.xml"),
					   L"star wars : hoth pursuit", 0,
					   irr::core::dimension2d<irr::f32>(120, 15),
					   irr::core::vector3df(5070, 850, 4820),
					   -1, title, title);
  for (auto const c : NameMainMenu)
    {
      _buttonMM.push_back(std::unique_ptr<GButton>(new GButton(initPos,
							       initTextDim,
							       c,
							       color)));
      initPos.at(1) -= 20.f;
    }
  for (auto it = _buttonMM.begin() ; it != _buttonMM.end() ; ++it)
    it->get()->setButton(_sceneManager, _guienv);
  this->initOptMenu();
  this->initBindings();
  this->initPlayMenu();
  this->initLeaderboard();
  clearPlayMenu();
}

void						Graphic::initLeaderboard()
{
  this->_leaderboard.clear();
  openFile(_leaderboard, "./Saves/leaderboard");
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
  initPos[1] = 794;
  initPos[2] = 4828;
  _buttonOpt.push_back(std::unique_ptr<GButton>(new GButton(initPos,
							    initTextDim,
							    L"on",
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
					   L"bindings :", 0,
					   irr::core::dimension2d<irr::f32>
					   (initTextDim[0], initTextDim[1]),
					   irr::core::vector3df(4985, 822.5f, 4806),
					   -1, color, color);
  _sceneManager->addBillboardTextSceneNode(_guienv->getFont("assets/font/myfont.xml"),
					   L"music :", 0,
					   irr::core::dimension2d<irr::f32>
					   (initTextDim[0], initTextDim[1]),
					   irr::core::vector3df(4985, 795, 4806),
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
							    L"",
							    color)));
  initPos[0] = 4900;
  initPos[2] = 4880;
  _buttonB.push_back(std::unique_ptr<GButton>(new GButton(initPos,
							    initTextDim,
							    L"",
							    color)));
  initPos[0] = 4970;
  initPos[1] = 1004;
  initPos[2] = 4810;
  _buttonB.push_back(std::unique_ptr<GButton>(new GButton(initPos,
							    initTextDim,
							    L"",
							    color)));

  initPos[0] = 4900;
  initPos[1] = 1003;
  initPos[2] = 4880;
  _buttonB.push_back(std::unique_ptr<GButton>(new GButton(initPos,
							    initTextDim,
							    L"",
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
					   L"press enter to change and valid",
					   0,
					   irr::core::dimension2d<irr::f32>
					   (140, 30),
					   irr::core::vector3df(4940, 980, 4820),
					   -1, color, color);
}

void						Graphic::initPlayMenu()
{
  std::vector<irr::f32>				initPos;
  std::vector<irr::f32>				initTextDim;
  irr::video::SColor				color(255, 255, 255, 0);

  this->initPauseMenu();
  initPos.push_back(4980);
  initPos.push_back(820);
  initPos.push_back(4940);
  initTextDim.push_back(40.f);
  initTextDim.push_back(10.f);
  _buttonP.push_back(std::unique_ptr<GButton>(new GButton(initPos,
							  initTextDim,
							  L"empty",
							  color)));
  initPos[0] = 5030;
  _buttonP.push_back(std::unique_ptr<GButton>(new GButton(initPos,
							  initTextDim,
							  L"empty",
							  color)));
  initPos[0] = 5080;
  _buttonP.push_back(std::unique_ptr<GButton>(new GButton(initPos,
							  initTextDim,
							  L"empty",
							  color)));

  initPos[0] = 5020;
  initPos[1] = 781;
  initTextDim[1] = 15;
  initTextDim[0] = 8;
  _buttonP.push_back(std::unique_ptr<GButton>(new GButton(initPos,
							  initTextDim,
							  L"1",
							  color)));
  initPos[0] = 5045;
  initPos[1] = 781.5f;
  _buttonP.push_back(std::unique_ptr<GButton>(new GButton(initPos,
							  initTextDim,
							  L"2",
							  color)));
  initPos[0] = 5070;
  initPos[1] = 782.f;
  _buttonP.push_back(std::unique_ptr<GButton>(new GButton(initPos,
							  initTextDim,
							  L"3",
							  color)));
  initPos[0] = 5093;
  initPos[1] = 782.75f;
  _buttonP.push_back(std::unique_ptr<GButton>(new GButton(initPos,
							  initTextDim,
							  L"4",
							  color)));

  for (auto it = _buttonP.begin() ; it != _buttonP.end() ; ++it)
    it->get()->setButton(_sceneManager, _guienv);
  _playText.push_back(_sceneManager->addBillboardTextSceneNode(_guienv->getFont("assets/font/myfont.xml"),
					   L"load save", 0,
					   irr::core::dimension2d<irr::f32>(40, 15),
					   irr::core::vector3df(4980, 840, 4940),
							       -1, color, color));
  _playText.push_back(_sceneManager->addBillboardTextSceneNode(_guienv->getFont("assets/font/myfont.xml"),
					   L"new game", 0,
					   irr::core::dimension2d<irr::f32>(40, 15),
					   irr::core::vector3df(5030, 800, 4940),
							       -1, color, color));
  _playText.push_back(_sceneManager->addBillboardTextSceneNode(_guienv->getFont("assets/font/myfont.xml"),
							       L"number of players", 0,
							       irr::core::dimension2d<irr::f32>(55, 15),
							       irr::core::vector3df(4980, 780, 4940),
							       -1, color, color));
}

void						Graphic::initPauseMenu()
{
  std::vector<irr::f32>				initPos;
  std::vector<irr::f32>				initTextDim;
  irr::video::SColor				color(255, 255, 255, 0);

  initPos.push_back(4975);
  initPos.push_back(785);
  initPos.push_back(5195);
  initTextDim.push_back(70);
  initTextDim.push_back(16);
  _buttonPause.push_back(std::unique_ptr<GButton>(new GButton(initPos,
							      initTextDim,
							      L"",
							      color)));

  initPos[0] = 5085;
  initPos[1] = 785;
  initPos[2] = 5195;
  _buttonPause.push_back(std::unique_ptr<GButton>(new GButton(initPos,
							      initTextDim,
							      L"",
							      color)));
  initPos[0] = 4965;
  initPos[1] = 750;
  initPos[2] = 5155;
  initTextDim[0] = 50;
  initTextDim[1] = 15;
  _buttonPause.push_back(std::unique_ptr<GButton>(new GButton(initPos,
							      initTextDim,
							      L"",
							      color)));
  initPos[0] = 5032;
  initPos[1] = 750;
  initPos[2] = 5155;
  _buttonPause.push_back(std::unique_ptr<GButton>(new GButton(initPos,
							      initTextDim,
							      L"",
							      color)));
  initPos[0] = 5095;
  initPos[1] = 750;
  initPos[2] = 5155;
  _buttonPause.push_back(std::unique_ptr<GButton>(new GButton(initPos,
							      initTextDim,
							      L"",
							      color)));
  for (auto it = _buttonPause.begin() ; it != _buttonPause.end() ; ++it)
    it->get()->setButton(_sceneManager, _guienv);
  _pauseText.push_back(_sceneManager->addBillboardTextSceneNode
		       (_guienv->getFont("assets/font/myfont.xml"),
			L"", 0,
			irr::core::dimension2d<irr::f32>(30, 10),
			irr::core::vector3df(5032, 818, 5170),
			-1, color, color));
  _pauseText.push_back(_sceneManager->addBillboardTextSceneNode
		       (_guienv->getFont("assets/font/myfont.xml"),
			L"", 0,
			irr::core::dimension2d<irr::f32>(70, 20),
			irr::core::vector3df(5032, 775, 5170),
			-1, color, color));
}

void			Graphic::clearPauseMenu()
{
  _pauseText[0]->setText(L"");
  _pauseText[1]->setText(L"");
  for (auto it = _buttonPause.begin() ; it != _buttonPause.end() ; ++it)
    {
      (it->get())->_button->setText(L"");
    }
}

void			Graphic::clearPlayMenu()
{
  _playText[0]->setText(L"");
  _playText[1]->setText(L"");
  _playText[2]->setText(L"");
  for (auto it = _buttonP.begin() ; it != _buttonP.end() ; ++it)
    {
      (it->get())->_button->setText(L"");
    }
}

void			Graphic::clearText()
{
  for (auto it : _textEndGame)
    it->setText(L"");
  for (auto it2 : _leaderboardText)
    it2->setText(L"");
}

void			Graphic::displayLeaderboard(std::vector<std::shared_ptr<Element>> const&)
{
  irr::video::SColor	title(255, 255, 255, 0);
  irr::video::SColor	gold(255, 255, 215, 0);
  irr::video::SColor	silver(255, 192, 192, 192);
  irr::video::SColor	bronze(255, 205, 127, 50);

  clearPlayMenu();
  _camera.moveCamera(irr::core::vector3df(5035, 806, 4877),
		     irr::core::vector3df(5132, 802, 4904));
  if (_uniqueD == false)
    {
      _leaderboardText.push_back(_sceneManager->addBillboardTextSceneNode
			   (_guienv->getFont("assets/font/myfont.xml"),
			    L"Leaderboard", 0,
			    irr::core::dimension2d<irr::f32>(30, 10),
			    irr::core::vector3df(5065, 824, 4885),
			    -1, title, title));
      _leaderboardText.push_back(_sceneManager->addBillboardTextSceneNode
			   (_guienv->getFont("assets/font/myfont.xml"),
			    (L"1st Place : " + _leaderboard[0]).c_str(), 0,
			    irr::core::dimension2d<irr::f32>(40, 10),
			    irr::core::vector3df(5065, 812, 4885),
			    -1, gold, gold));

      _leaderboardText.push_back(_sceneManager->addBillboardTextSceneNode
			   (_guienv->getFont("assets/font/myfont.xml"),
			    (L"2nd Place : " + _leaderboard[1]).c_str(), 0,
			    irr::core::dimension2d<irr::f32>(40, 10),
			    irr::core::vector3df(5065, 800, 4885),
			    -1, silver, silver));

      _leaderboardText.push_back(_sceneManager->addBillboardTextSceneNode
			   (_guienv->getFont("assets/font/myfont.xml"),
			    (L"3rd Place : " + _leaderboard[2]).c_str(), 0,
			    irr::core::dimension2d<irr::f32>(40, 10),
			    irr::core::vector3df(5065, 788, 4885),
			    -1, bronze, bronze));
      _uniqueD = true;
    }
}

void			Graphic::displayPause(std::vector<std::shared_ptr<Element>> const& map)
{
  int			idx = 0;

  _initPause = false;
  _pauseText[0]->setText(L"pause");
  _pauseText[1]->setText(L"save and exit");
  _textChrono->setText(L"");
  for (auto it = map.begin() ; it != map.end() ; ++it)
    {
      if (static_cast<Button *>(it->get())->getIsSelected() == true)
	{
	  _buttonPause[idx].get()->_button->setText(static_cast<Button *>(it->get())->getContent().c_str());
	  _buttonPause[idx].get()->_button->setColor(irr::video::SColor(255, 255, 0, 0));
	}
      else
	{
	  _buttonPause[idx].get()->_button->setText(static_cast<Button *>(it->get())->getContent().c_str());
	  _buttonPause[idx].get()->_button->setColor(irr::video::SColor(255, 255, 255, 0));
	}
      ++idx;
    }
}

void			Graphic::displayMainMenu(std::vector<std::shared_ptr<Element>> const& map)
{
  int			idx = 0;

  _camera.moveCamera(irr::core::vector3df(5035, 806, 4877),
		     irr::core::vector3df(5066, 808, 4824));
  clearPauseMenu();
  clearText();
  _uniqueD = false;
  _finish = false;
  _launchGame = true;
  if (_backMenu == true)
    {
      _music.playMusic("assets/music/star-wars-cantina-song.ogg");
      _backMenu = false;
    }
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
	  _buttonOpt[idx].get()->_button->
	    setText(static_cast<Button *>(it->get())->getContent().c_str());
	  if (static_cast<Button *>(it->get())->getContent() == L"off")
	    this->_music.setVol(0);
	  else if (static_cast<Button *>(it->get())->getContent() == L"on")
	    this->_music.setVol(0.3f);
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
	  _buttonB[idx].get()->_button->setColor(irr::video::SColor(255, 255, 0, 255));
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

void		Graphic::displayPlayMenu(std::vector<std::shared_ptr<Element>> const& map)
{
   int			idx = 0;


  _camera.moveCamera(irr::core::vector3df(5035, 808, 4877),
		     irr::core::vector3df(5033, 808, 4919));
  _playText[0]->setText(L"load game :");
  _playText[1]->setText(L"new game");
  _playText[2]->setText(L"number of players :");
  for (auto it = map.begin() ; it != map.end() ; ++it)
    {
      if (static_cast<Button *>(it->get())->getIsSelected() == true)
	{
	  _buttonP[idx].get()->_button->setText(static_cast<Button *>(it->get())->getContent().c_str());
	  _buttonP[idx].get()->_button->setColor(irr::video::SColor(255, 0, 255, 255));
	}
      else
	{
	  _buttonP[idx].get()->_button->setText(static_cast<Button *>
						  (it->get())->getContent().c_str());
	  _buttonP[idx].get()->_button->setColor(irr::video::SColor(255, 255, 255, 0));
	}
      ++idx;
    }
}

void		Graphic::displayEndGame(std::vector<std::shared_ptr<Element>> const&)
{
  if (_finish == false)
    {
      _textChrono->setText(L"");
      openFile(_endgame, "./Saves/endgame");
      this->initLeaderboard();
      _textEndGame.push_back(_guienv->addStaticText(L"results",
						    irr::core::rect<irr::s32>
						    (745, 30, 10000, 10000),
						    false));
      _textEndGame.push_back(_guienv->addStaticText((L"1st place : " +
						     _endgame[0]).c_str(),
						    irr::core::rect<irr::s32>
						    (480, 200, 10000, 10000),
						    false));
      _textEndGame.push_back(_guienv->addStaticText((L"2nd place : " +
						     _endgame[1]).c_str(),
						    irr::core::rect<irr::s32>
						    (480, 400, 10000, 10000),
						    false));
      _textEndGame.push_back(_guienv->addStaticText((L"3rd place : " +
						     _endgame[2]).c_str(),
						    irr::core::rect<irr::s32>
						    (480, 600, 10000, 10000),
						    false));
      _textEndGame.push_back(_guienv->addStaticText(L"press esc to quit",
						    irr::core::rect<irr::s32>
						    (500, 800, 10000, 10000),
						    false));
      _textEndGame[0]->setOverrideColor(irr::video::SColor(255, 255, 255, 0));
      _textEndGame[1]->setOverrideColor(irr::video::SColor(255, 255, 215, 0));
      _textEndGame[2]->setOverrideColor(irr::video::SColor(255, 192, 192, 192));
      _textEndGame[3]->setOverrideColor(irr::video::SColor(255, 205, 127, 50));
      _textEndGame[4]->setOverrideColor(irr::video::SColor(255, 255, 255, 0));
      _finish = true;
      _backMenu = true;
    }
}

void			Graphic::openFile(std::vector<std::wstring> & vec,
					  std::string const & path)
{
  try
    {
      ManageFile		manageFile(path);
      std::string		file;

      file = manageFile.readFile();

      std::string		tmp;
      std::istringstream	iss(file);
      int			idx = 0;

      while (std::getline(iss, tmp) && idx < 3)
	{
	  std::stod(tmp);

	  std::wstring		score(tmp.begin(), tmp.end());

	  vec.push_back(score);
	  ++idx;
	}
      if (vec.size() != 3)
	throw Error("Error in the file");
    }
  catch (std::exception const &)
    {
      unsigned int	size = vec.size();

      for (unsigned int idx = 0; idx < (3 - size); ++idx)
	vec.push_back(L"no score");
    }
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
						       0, -1, irr::core::vector3df(x + 6, y + 10, z - 4),
						       irr::core::vector3df(0, 0, 0),
						       irr::core::vector3df(18, 18, 18));
  if (!pods[type])
    throw (Error("Pod mesh not found"));
  pods[type]->setMaterialFlag(irr::video::EMF_LIGHTING, false);
}

void		Graphic::borderDisp(char type, irr::f32 x, irr::f32 y, irr::f32 z)
{
  irr::scene::IMeshSceneNode	*border;

  switch (type)
    {
    case '|':
      border = _sceneManager->addMeshSceneNode(_sceneManager->getMesh("./assets/laser_border.obj"),
					       0, -1,
					       irr::core::vector3df(x, y + 10.f, z),
					       irr::core::vector3df(0.f, 0.f, 0.f),
					       irr::core::vector3df(9.f, 9.f, 9.f));
      break ;
    case '-':
      border = _sceneManager->addMeshSceneNode(_sceneManager->getMesh("./assets/laser_border.obj"),
					       0, -1,
					       irr::core::vector3df(x, y + 10.f, z),
					       irr::core::vector3df(0.f, 90.f, 0.f),
					       irr::core::vector3df(9.f, 9.f, 9.f));
      break;
    case '/':
      border = _sceneManager->addMeshSceneNode(_sceneManager->getMesh("./assets/laser_border.obj"),
					       0, -1,
					       irr::core::vector3df(x, y + 10.f, z),
					       irr::core::vector3df(0.f, 45.f, 0.f),
					       irr::core::vector3df(9.f, 9.f, 9.f));
      break ;
    case '\\':
      border = _sceneManager->addMeshSceneNode(_sceneManager->getMesh("./assets/laser_border.obj"),
					       0, -1,
					       irr::core::vector3df(x, y + 10.f, z),
					       irr::core::vector3df(0.f, -45.f, 0.f),
					       irr::core::vector3df(9.f, 9.f, 9.f));
      break ;
    case 'X':
      border = _sceneManager->addMeshSceneNode(_sceneManager->getMesh("./assets/BlackAndRedFloatingRobot.obj"),
					       0, -1,
					       irr::core::vector3df(x, y + 10.f, z),
					       irr::core::vector3df(90.f, 0.f, 0.f),
					       irr::core::vector3df(5.f, 5.f, 5.f));

      break ;
    default:
      return ;
    }
  if (!border)
    throw (Error("Pod mesh not found"));
  border->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  border->setMaterialType(irr::video::EMT_SOLID);
}

void		Graphic::initMap(std::shared_ptr<Element> const& elem,
				 irr::f32 x, irr::f32 y, irr::f32 z)
{
  if (elem->getType() == Element::EType::ROAD)
    return ;

  irr::scene::IMeshSceneNode	*cube;

  switch (elem->getType())
    {
    case Element::EType::BLOCK :
      this->borderDisp(elem->getPath()[0], x, y, z);
      break ;
    case Element::EType::ENDLINE :
      cube =
	_sceneManager->addCubeSceneNode(10.0f, 0, -1,
					irr::core::vector3df(x, y, z),
					irr::core::vector3df(0.f, 0.f, 0.f));
      cube->setMaterialTexture(0, _driver->getTexture("assets/start.jpg"));
      cube->setMaterialFlag(irr::video::EMF_LIGHTING, false);
      cube->setMaterialType(irr::video::EMT_SOLID);
      break ;
    case Element::EType::POD1 :
      this->setCar(elem->getType(), elem->getPath(), x, y, z);
      break ;
    case Element::EType::POD2 :
      this->setCar(elem->getType(), elem->getPath(), x, y, z);
      break ;
    case Element::EType::POD3 :
      this->setCar(elem->getType(), elem->getPath(), x, y, z);
      break ;
    case Element::EType::POD4 :
      this->setCar(elem->getType(), elem->getPath(), x, y, z);
      break ;
    default :
      break ;
    }
}

void		Graphic::displayChrono(bool first)
{
  std::string time = std::to_string(_time).substr(0, 5);

  std::wstring wide_string = std::wstring(time.begin(), time.end());
  const wchar_t* result = wide_string.c_str();

  if (first == true)
    {
      _skin->setColor(irr::gui::EGDC_BUTTON_TEXT, irr::video::SColor(255, 255, 0, 0));
      _textChrono = _guienv->addStaticText(L"",
				     irr::core::rect<irr::s32>(780, 30, 10000, 10000),
				     false);
    }
  else
    _textChrono->setText(result);
}

void		Graphic::displayGame(std::vector<std::shared_ptr<Element>> const& map)
{
  int		i = 0;
  irr::f32	x = 5330.f;
  irr::f32	y = 560.f;
  irr::f32	z = 5125.f;
  static bool	first = true;

  clearPlayMenu();
  _backMenu = true;
  if (_launchGame == true)
    {
      _music.playMusic("assets/music/duel-of-the-fates.ogg");
      _launchGame = false;
    }
  if (_initPause == false)
    {
      clearPauseMenu();
      _initPause = true;
    }
  _camera.moveCamera(irr::core::vector3df(5033.f, 838.f, 5126.f),
		     irr::core::vector3df(5033.f, 770.f, 5172.f));
  if (first)
    displayChrono(true);
  else if (_isStarted == true)
    displayChrono(false);
  for (auto const& elem : map)
    {
      if (i % 60 == 0)
	{
	  x = 5330.f;
	  z += _squareSize;
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
	  newPos.X = x - _squareSize * static_cast<GameElement *>(elem.get())->getPos().first / 100;
	  newPos.Z = z + _squareSize * static_cast<GameElement *>(elem.get())->getPos().second / 100;
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
  _time = observable.getChrono().getTime();
  _isStarted = observable.getStarted();
}

bool		Graphic::running(void)
{
  return (_device->run());
}

void		Graphic::setEventReceiver(irr::IEventReceiver *receiver)
{
  _device->setEventReceiver(receiver);
}
