//
// Graphic.hpp for irrlicht in /home/anthony/rendu/cpp/indie/Indie_studio/includes
//
// Made by Anthony Jouvel
// Login   <anthony.jouvel@epitech.eu>
//
// Last update Wed Jun  7 14:29:29 2017 DaZe
// Last update Tue Jun  6 15:10:45 2017 DaZe
//

#pragma once

#include <irrlicht.h>
#include <irrKlang.h>
#include <unordered_map>
#include <functional>
#include "AObserver.hpp"
#include "Utils.hpp"
#include "GButton.hpp"
#include "Camera.hpp"

class						Graphic : public AObserver
{
private:
  static const irr::f32				_squareSize;
  irr::u32					_width;
  irr::u32					_height;
  irr::IrrlichtDevice				*_device;
  irr::video::IVideoDriver			*_driver;
  irr::scene::ISceneManager			*_sceneManager;
  irr::gui::IGUIEnvironment			*_guienv;
  Gcamera					_camera;
  irrklang::ISoundEngine			*_engine;
  double					_time;
  irr::gui::IGUIStaticText			*_text;

  std::vector<std::unique_ptr<GButton>>		_buttonMM;
  std::vector<std::unique_ptr<GButton>>		_buttonOpt;
  std::vector<std::unique_ptr<GButton>>		_buttonB;
  std::vector<std::unique_ptr<GButton>>		_buttonP;
  std::unordered_map<Element::EType, irr::scene::IAnimatedMeshSceneNode *> pods;

  void				manageDisplay(std::vector<std::shared_ptr<Element>> const&, DType);
  void				displayMainMenu(std::vector<std::shared_ptr<Element>> const&);
  void				displayOptions(std::vector<std::shared_ptr<Element>> const&);
  void				displayLeaderBoard(std::vector<std::shared_ptr<Element>> const&);
  void				displayPlayMenu(std::vector<std::shared_ptr<Element>> const&);
  void				initMap(std::shared_ptr<Element> const& elem,
					irr::f32 x, irr::f32 y, irr::f32 z);
  void				setCar(Element::EType, irr::io::path, irr::f32, irr::f32, irr::f32);
  void				displayCar(std::vector<std::shared_ptr<Element>> const&);
  void				displayGame(std::vector<std::shared_ptr<Element>> const&);
  void				displayBindings(std::vector<std::shared_ptr<Element>> const&);
  void				loadIntro();
  void				skyDome(const irr::io::path&);
  void				ground();
  void				moveCamera(irr::core::vector3df, irr::core::vector3df);
  irr::f32			coords(irr::f32, irr::f32);
  void				initMainMenu();
  void				initOptMenu();
  void				initBindings();
  void				initPlayMenu();
  void				displayChrono(bool);

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
    {DType::PLAY, std::bind(&Graphic::displayPlayMenu, this, std::placeholders::_1)},
    {DType::GAME, std::bind(&Graphic::displayGame, this, std::placeholders::_1)},
    {DType::GAME_CHRONO, std::bind(&Graphic::displayGame, this, std::placeholders::_1)},
    {DType::FINISH, NULL},
    {DType::NOTHING, NULL}
  };
};
