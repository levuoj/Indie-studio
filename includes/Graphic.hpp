//
// Graphic.hpp for irrlicht in /home/anthony/rendu/cpp/indie/Indie_studio/includes
//
// Made by Anthony Jouvel
// Login   <anthony.jouvel@epitech.eu>
//
// Started on  Fri May 12 14:02:36 2017 Anthony Jouvel
// Last update Mon May 22 20:24:27 2017 Anthony Jouvel
//

#pragma once

#include <irrlicht.h>
#include <unordered_map>
#include <functional>
#include "AObserver.hpp"
#include "Utils.hpp"

class	Graphic : public AObserver
{
private:
  irr::u32			_width;
  irr::u32			_height;
  irr::IrrlichtDevice		*_device;
  irr::video::IVideoDriver	*_driver;
  irr::scene::ISceneManager	*_sceneManager;
  irr::gui::IGUIEnvironment	*_guienv;
  irr::scene::ICameraSceneNode	*_camera;

  void				manageDisplay(std::vector<std::unique_ptr<Element>> const&, DType);
  void				displayMainMenu(std::vector<std::unique_ptr<Element>> const&);
  void				displayOptions(std::vector<std::unique_ptr<Element>> const&);
  void				displayLeaderBoard(std::vector<std::unique_ptr<Element>> const&);
  void				displayExit(std::vector<std::unique_ptr<Element>> const&);
  void				displayLoop();
  void				button(irr::f32, irr::f32,
				       irr::f32, const wchar_t *,
				       const irr::io::path&);
  void				skyDome(const irr::io::path&);
  void				ground();
  void				moveCamera(irr::core::vector3df, irr::core::vector3df);
  irr::f32			coords(irr::f32, irr::f32);

public:
  Graphic(irr::u32, irr::u32);
  Graphic();
  ~Graphic();

  void				actualize(Observable const &);
  bool				running(void);
  void				setEventReceiver(irr::IEventReceiver *);

  std::unordered_map<DType,
		     std::function<void(std::vector<std::unique_ptr<Element>> const&)>>		dispThis =
    {
      {DType::MAIN_MENU, std::bind(&Graphic::displayMainMenu, this, std::placeholders::_1)},
      {DType::OPTIONS, std::bind(&Graphic::displayOptions, this, std::placeholders::_1)},
      {DType::LEADERBOARD, std::bind(&Graphic::displayLeaderBoard, this, std::placeholders::_1)},
      {DType::EXIT, std::bind(&Graphic::displayExit, this, std::placeholders::_1)},
      {DType::NOTHING, NULL}
    };
};
