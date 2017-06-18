//
// Core.cpp for Core in /home/pashervz/Epitech/C++/Indie/Indie_studio/sources
//
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
//
// Started on  Wed May 10 13:12:37 2017 Pashervz
// Last update Sun Jun 18 17:01:23 2017 jouvel
//

#include <iostream>
#include <irrlicht.h>
#include "EventReceiver.hpp"
#include "Core.hpp"
#include "BindingMenu.hpp"
#include "MainMenu.hpp"
#include "OptionMenu.hpp"
#include "PlayMenu.hpp"
#include "PauseMenu.hpp"
#include "Leaderboard.hpp"
#include "EndGame.hpp"

Core::Core()
{
  this->_graphic = std::unique_ptr<Graphic>(new Graphic());
  this->_toLoad = MAIN_MENU;
  this->initBindings();
   // --- TEST --- //
  // this->_toLoad = GAME;
  //this->_game = std::unique_ptr<ManageGame>(new ManageGame(2, molft));
  // this->_game->setObserver(this->_graphic.get());
  // --- TEST --- //
  this->_music = std::unique_ptr<Music>(new Music());

  this->_menu.emplace(MAIN_MENU, std::shared_ptr<AMenu>(new MainMenu(this->_music.get())));
  this->_menu.emplace(LEADERBOARD, std::shared_ptr<AMenu>(new Leaderboard(this->_music.get())));
  this->_menu.emplace(OPTIONS, std::shared_ptr<AMenu>(new OptionMenu(this->_music.get())));
  this->_menu.emplace(PLAY, std::shared_ptr<AMenu>(new PlayMenu(this->_music.get())));
  this->_menu.emplace(PAUSE, std::shared_ptr<AMenu>(new PauseMenu(this->_music.get())));
  this->_menu.emplace(ENDGAME, std::shared_ptr<AMenu>(new EndGame(this->_music.get())));
  this->_menu[this->_toLoad]->setObserver(this->_graphic.get());
}

void			Core::initBindings()
{
  this->_bindings.push_back({irr::KEY_KEY_Z, irr::KEY_KEY_S,
	irr::KEY_KEY_Q, irr::KEY_KEY_D});
  this->_bindings.push_back({irr::KEY_KEY_Y, irr::KEY_KEY_H,
	irr::KEY_KEY_G, irr::KEY_KEY_J});
  this->_bindings.push_back({irr::KEY_KEY_O, irr::KEY_KEY_L,
	irr::KEY_KEY_K, irr::KEY_KEY_M});
  this->_bindings.push_back({irr::KEY_UP, irr::KEY_DOWN,
	irr::KEY_LEFT, irr::KEY_RIGHT});
}

int			Core::launch()
{
  EventReceiver		receiver;
  DType			loaded		= this->_toLoad;
  irr::u32		then		= this->_graphic->getTime();
  irr::f32		lag		= 0.f;
  const irr::f32	MS_PER_UPDATE	= 16.f;

  this->_graphic->setEventReceiver(&receiver);
  receiver.init();
  while (this->_graphic->running())
    {
      const irr::u32	now		= this->_graphic->getTime();
      const irr::f32	elapsed		= (irr::f32)(now - then);
      then = now;
      lag += elapsed;

      while (lag >= MS_PER_UPDATE)
	{
	  receiver.startEventProcess();
	  if (loaded != GAME && loaded != PAUSE)
	    {
	      this->_toLoad = this->_menu[this->_toLoad]->transferKey(receiver.getKey());

	      if (loaded != this->_toLoad && this->_toLoad != GAME)
		{
		  switch (this->_toLoad)
		    {
		    case BINDINGS:
		      this->_menu[BINDINGS] =
			std::make_shared<BindingMenu>
			(static_cast<OptionMenu *>(this->_menu[OPTIONS].get())->getPlayer(), _music.get());
		      break;
		    case EXIT:
		      return (EXIT_SUCCESS);
		    case PLAY:
		      this->_menu[PLAY] = std::make_shared<PlayMenu>(_music.get());
		      break;
		    case OPTIONS:
		      if (loaded == BINDINGS)
			{
			  this->_bindings[std::atoi((static_cast<BindingMenu *>
						     (this->_menu[BINDINGS].get())
						     ->getPlayer()).c_str()) - 1] =
			    static_cast<BindingMenu *>(this->_menu[BINDINGS].get())
			    ->getBindings();
			}
		    default:
		      break;
		    }
		  this->_menu[this->_toLoad]->setObserver(this->_graphic.get());
		}
	      else if (this->_toLoad == GAME)
		{
		  if (static_cast<PlayMenu *>(this->_menu[PLAY].get())->getNewGame()
		      == false)
		    this->_game =
		      std::unique_ptr<ManageGame>
		      (new ManageGame(static_cast<PlayMenu *>
				      (this->_menu[PLAY].get())->getSave(), _bindings, this->_music.get()));
		  else
		    this->_game =
		      std::unique_ptr<ManageGame>
		      (new ManageGame(static_cast<PlayMenu *>
				      (this->_menu[PLAY].get())->getNbPlayer(), _bindings, this->_music.get()));
		  this->_game->setObserver(this->_graphic.get());
		}
	    }
	  else if (loaded == PAUSE)
	    {
	      this->_toLoad = this->_menu[this->_toLoad]->transferKey(receiver.getKey());
	      if (this->_toLoad == GAME)
		this->_game->setObserver(this->_graphic.get());
	      else
		this->_menu[this->_toLoad]->setObserver(this->_graphic.get());
	    }
	  else
	    {
	      this->_toLoad = this->_game->transferKey(receiver);
	      if (this->_toLoad == PAUSE)
		this->_menu[PAUSE] = std::make_shared<PauseMenu>(this->_game.get(), _music.get());
	      if (this->_toLoad != GAME)
		this->_menu[this->_toLoad]->setObserver(this->_graphic.get());
	    }

	  lag -= MS_PER_UPDATE;
	  loaded = this->_toLoad;

	}

      if (this->_toLoad != GAME)
	this->_menu[this->_toLoad]->notify();
      else
	this->_game->notify();
    }
  return (EXIT_SUCCESS);
}
