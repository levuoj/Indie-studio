//
// Graphic.hpp for irrlicht in /home/anthony/rendu/cpp/indie/Indie_studio/includes
//
// Made by Anthony Jouvel
// Login   <anthony.jouvel@epitech.eu>
//
// Last update Sun Jun 18 20:00:37 2017 Lebrun Kilian
// Last update Tue Jun  6 15:10:45 2017 DaZe
//

#pragma once

#include <irrlicht.h>
#include <unordered_map>
#include <functional>
#include "AObserver.hpp"
#include "Utils.hpp"
#include "Music.hpp"
#include "GButton.hpp"
#include "Camera.hpp"

class						Graphic : public AObserver
{
private:
  Music							_music;
  static const irr::f32					_squareSize;
  irr::u32						_width;
  irr::u32						_height;
  irr::IrrlichtDevice					*_device;
  irr::video::IVideoDriver				*_driver;
  irr::scene::ISceneManager				*_sceneManager;
  irr::gui::IGUIEnvironment				*_guienv;
  Gcamera						_camera;
  double						_time;
  irr::gui::IGUIStaticText				*_textChrono;
  std::vector<irr::scene::IBillboardTextSceneNode *>	_pauseText;
  std::vector<irr::scene::IBillboardTextSceneNode *>	_playText;
  std::vector<irr::scene::IBillboardTextSceneNode *>	_leaderboardText;
  std::vector<irr::scene::IBillboardTextSceneNode *>	_optText;
  bool							_initPause = true;
  bool							_isStarted;
  bool							_finish = false;
  bool							_uniqueD = false;
  bool							_backMenu = false;
  bool							_launch = false;
  bool							_launchEG = false;
  irr::gui::IGUISkin					*_skin;
  irr::gui::IGUIFont					*_font;

  std::vector<std::unique_ptr<GButton> >		_buttonMM;
  std::vector<std::unique_ptr<GButton> >		_buttonOpt;
  std::vector<std::unique_ptr<GButton> >		_buttonB;
  std::vector<std::unique_ptr<GButton> >		_buttonP;
  std::vector<std::unique_ptr<GButton> >		_buttonPause;

  std::vector<std::wstring>				_leaderboard;
  std::vector<std::wstring>				_endgame;
  std::vector<irr::gui::IGUIStaticText *>		_textEndGame;
  std::vector<irr::gui::IGUIStaticText *>		_textLeaderboard;

  std::unordered_map<Element::EType, irr::scene::IAnimatedMeshSceneNode *> pods;

  void				manageDisplay(std::vector<std::shared_ptr<Element>> const&, DType);
  void				displayMainMenu(std::vector<std::shared_ptr<Element>> const&);
  void				displayOptions(std::vector<std::shared_ptr<Element>> const&);
  void				displayLeaderboard(std::vector<std::shared_ptr<Element>> const&);
  void				displayPlayMenu(std::vector<std::shared_ptr<Element>> const&);
  void				displayPause(std::vector<std::shared_ptr<Element>> const&);
  void				initMap(std::shared_ptr<Element> const& elem,
					irr::f32 x, irr::f32 y, irr::f32 z);
  void				borderDisp(char type, irr::f32 x, irr::f32 y, irr::f32 z);
  void				setCar(Element::EType, irr::io::path, irr::f32, irr::f32, irr::f32);
  void				displayGame(std::vector<std::shared_ptr<Element>> const&);
  void				displayBindings(std::vector<std::shared_ptr<Element>> const&);
  void				displayEndGame(std::vector<std::shared_ptr<Element>> const&);
  void				finish(std::vector<std::shared_ptr<Element>> const&);
  void				loadIntro();
  void				skyDome(const irr::io::path&);
  void				ground();
  void				moveCamera(irr::core::vector3df, irr::core::vector3df);
  irr::f32			coords(irr::f32, irr::f32);
  void				initMainMenu();
  void				initOptMenu();
  void				initBindings();
  void				initPlayMenu();
  void				initPauseMenu();
  void				initLeaderboard();
  void				displayChrono(bool);
  void				clearPauseMenu();
  void				clearPlayMenu();
  void				clearOptMenu();
  void				clearText();
  void				openFile(std::vector<std::wstring> &, std::string const &);

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
      {DType::MAIN_MENU, [this](std::vector<std::shared_ptr<Element>> const& vec){this->displayMainMenu(vec);}},
      {DType::OPTIONS, [this](std::vector<std::shared_ptr<Element>> const& vec){this->displayOptions(vec);}},
      {DType::LEADERBOARD, [this](std::vector<std::shared_ptr<Element>> const& vec){this->displayLeaderboard(vec);}},
      {DType::BINDINGS, [this](std::vector<std::shared_ptr<Element>> const& vec){this->displayBindings(vec);}},
      {DType::PLAY, [this](std::vector<std::shared_ptr<Element>> const& vec){this->displayPlayMenu(vec);}},
      {DType::GAME, [this](std::vector<std::shared_ptr<Element>> const& vec){this->displayGame(vec);}},
      {DType::PAUSE, [this](std::vector<std::shared_ptr<Element>> const& vec){this->displayPause(vec);}},
      {DType::GAME_CHRONO, [this](std::vector<std::shared_ptr<Element>> const& vec){this->displayGame(vec);}},
      {DType::ENDGAME, [this](std::vector<std::shared_ptr<Element>> const& vec){this->displayEndGame(vec);}},
      {DType::NOTHING, NULL}
  };
};
