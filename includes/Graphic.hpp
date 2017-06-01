 //
// Graphic.hpp for irrlicht in /home/anthony/rendu/cpp/indie/Indie_studio/includes
//
// Made by Anthony Jouvel
// Login   <anthony.jouvel@epitech.eu>
//
// Started on  Fri May 12 14:02:36 2017 Anthony Jouvel
// Last update Thu Jun  1 17:31:50 2017 Pashervz
//

#pragma once

#include <irrlicht.h>
#include <unordered_map>
#include <functional>
#include "AObserver.hpp"
#include "Utils.hpp"
#include "GButton.hpp"
#include "Camera.hpp"

class	Graphic : public AObserver
{
private:
  static const irr::f32	SQUARE_SIZE;

  irr::u32			_width;
  irr::u32			_height;
  irr::IrrlichtDevice		*_device;
  irr::video::IVideoDriver	*_driver;
  irr::scene::ISceneManager	*_sceneManager;
  irr::gui::IGUIEnvironment	*_guienv;
  std::vector<std::unique_ptr<GButton>>		_buttonMM;
  std::vector<std::unique_ptr<GButton>>		_buttonOpt;
  std::vector<std::unique_ptr<GButton>>		_buttonB;
  std::unordered_map<Element::EType, irr::scene::IAnimatedMeshSceneNode *> pods;
  Gcamera			_camera;

  void				manageDisplay(std::vector<std::shared_ptr<Element>> const&, DType);
  void				constructMenuArea();
  void				displayMainMenu(std::vector<std::shared_ptr<Element>> const&);
  void				displayOptions(std::vector<std::shared_ptr<Element>> const&);
  void				displayLeaderBoard(std::vector<std::shared_ptr<Element>> const&);
  void				displayExit(std::vector<std::shared_ptr<Element>> const&);
  void				initMap(std::shared_ptr<Element> const& elem,
					irr::f32 x, irr::f32 y, irr::f32 z);
  void				setCar(Element::EType, irr::io::path, irr::f32, irr::f32, irr::f32);
  void				displayCar(std::vector<std::shared_ptr<Element>> const&);
  void				displayGame(std::vector<std::shared_ptr<Element>> const&);
  void				displayBindings(std::vector<std::shared_ptr<Element>> const&);
  void				skyDome(const irr::io::path&);
  void				ground();
  void				moveCamera(irr::core::vector3df, irr::core::vector3df);
  irr::f32			coords(irr::f32, irr::f32);
  void				initMainMenu();
  void				initOptMenu();
  void				initBindings();
public:
  Graphic(irr::u32 width = 1920, irr::u32 height = 1080);
  ~Graphic();

  void				actualize(Observable const &);
  bool				running(void);
  void				setEventReceiver(irr::IEventReceiver *);
  irr::u32			getTime()
  {
    return this->_device->getTimer()->getTime();
  }

  std::unordered_map<DType,
		     std::function<void(std::vector<std::shared_ptr<Element>> const&)>>		dispThis =
  {
    {DType::MAIN_MENU, std::bind(&Graphic::displayMainMenu, this, std::placeholders::_1)},
    {DType::OPTIONS, std::bind(&Graphic::displayOptions, this, std::placeholders::_1)},
    {DType::LEADERBOARD, std::bind(&Graphic::displayLeaderBoard, this, std::placeholders::_1)},
    {DType::BINDINGS, std::bind(&Graphic::displayBindings, this, std::placeholders::_1)},
    {DType::EXIT, std::bind(&Graphic::displayExit, this, std::placeholders::_1)},
    {DType::GAME, std::bind(&Graphic::displayGame, this, std::placeholders::_1)},
    {DType::NOTHING, NULL}
  };
};
