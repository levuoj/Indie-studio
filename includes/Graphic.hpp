 //
// Graphic.hpp for irrlicht in /home/anthony/rendu/cpp/indie/Indie_studio/includes
//
// Made by Anthony Jouvel
// Login   <anthony.jouvel@epitech.eu>
//
// Started on  Fri May 12 14:02:36 2017 Anthony Jouvel
// Last update Thu May 25 14:43:42 2017 Pierre Zawadil
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
  static const irr::f32	SQUARE_SIZE;

  irr::u32			_width;
  irr::u32			_height;
  irr::IrrlichtDevice		*_device;
  irr::video::IVideoDriver	*_driver;
  irr::scene::ISceneManager	*_sceneManager;
  irr::gui::IGUIEnvironment	*_guienv;
  irr::scene::ICameraSceneNode	*_camera;
  std::unordered_map<char, irr::scene::IAnimatedMeshSceneNode *> pods;

  void				manageDisplay(std::vector<std::shared_ptr<Element>> const&, DType);
  void				displayMainMenu(std::vector<std::shared_ptr<Element>> const&);
  void				displayOptions(std::vector<std::shared_ptr<Element>> const&);
  void				displayLeaderBoard(std::vector<std::shared_ptr<Element>> const&);
  void				displayExit(std::vector<std::shared_ptr<Element>> const&);
  void				initMap(std::shared_ptr<Element> const& elem,
					irr::f32 x, irr::f32 y, irr::f32 z);
  void				setCar(char c, irr::f32 x, irr::f32 y, irr::f32 z);
  void				displayCar(std::vector<std::shared_ptr<Element>> const&);
  void				displayGame(std::vector<std::shared_ptr<Element>> const&);
  void				button(irr::f32, irr::f32, irr::f32,
				       irr::f32, irr::f32, irr::f32,
				       const wchar_t *,
				       const irr::io::path&,
				       bool const&);
  void				skyDome(const irr::io::path&);
  void				ground();
  void				moveCamera(irr::core::vector3df, irr::core::vector3df);
  irr::f32			coords(irr::f32, irr::f32);
  void				writeText(irr::f32, irr::f32, irr::f32,
					  const wchar_t *);
  void				writeText(irr::scene::IMeshSceneNode *,
					  const wchar_t *);
  void				writeText(irr::s32, irr::s32, irr::s32, irr::s32,
					  const wchar_t *);

public:
  Graphic(irr::u32, irr::u32);
  Graphic();
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
    {DType::EXIT, std::bind(&Graphic::displayExit, this, std::placeholders::_1)},
    {DType::NOTHING, NULL}
  };
};
