//
// Core.cpp for Core in /home/pashervz/Epitech/C++/Indie/Indie_studio/sources
//
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
//
// Started on  Wed May 10 13:12:37 2017 Pashervz
// Last update Wed Jun  7 15:33:55 2017 Pashervz
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

Core::Core()
{
  this->_graphic = std::unique_ptr<Graphic>(new Graphic());
  this->_toLoad = MAIN_MENU;
   // --- TEST --- //
  // this->_toLoad = GAME;
  //this->_game = std::unique_ptr<ManageGame>(new ManageGame(2, molft));
  // this->_game->setObserver(this->_graphic.get());
  // --- TEST --- //
  this->_menu.emplace(MAIN_MENU, std::shared_ptr<AMenu>(new MainMenu));
  this->_menu.emplace(OPTIONS, std::shared_ptr<AMenu>(new OptionMenu));
  this->_menu.emplace(PLAY, std::shared_ptr<AMenu>(new PlayMenu));
  this->_menu.emplace(PAUSE, std::shared_ptr<AMenu>(new PauseMenu));
  this->_menu[this->_toLoad]->setObserver(this->_graphic.get());
}

int			Core::launch()
{
  EventReceiver		receiver;
  DType			loaded		= this->_toLoad;
  irr::u32		then		= this->_graphic->getTime();
  irr::f32		lag		= 0.f;
  const irr::f32	MS_PER_UPDATE	= 16.f;
  std::vector<std::array<irr::EKEY_CODE, 5>>  molft;
  
  molft.push_back({
      irr::KEY_UP,
	irr::KEY_DOWN,
	irr::KEY_LEFT,
	irr::KEY_RIGHT,
	irr::KEY_SPACE});
  molft.push_back({
      irr::KEY_KEY_Z,
	irr::KEY_KEY_S,
	irr::KEY_KEY_Q,
	irr::KEY_KEY_D,
	irr::KEY_KEY_W});
  
  this->_graphic->setEventReceiver(&receiver);
  while (this->_graphic->running())
    {
      const irr::u32	now		= this->_graphic->getTime();
      const irr::f32	elapsed		= (irr::f32)(now - then);
      then = now;
      lag += elapsed;

      while (lag >= MS_PER_UPDATE)
	{
	  if (loaded != GAME && loaded != PAUSE)
	    {
	      this->_toLoad = this->_menu[this->_toLoad]->transferKey(receiver.getKey());
	      if (loaded != this->_toLoad && this->_toLoad != GAME)
		{
		  if (this->_toLoad == BINDINGS)
		    {
		      this->_menu[BINDINGS] =
			std::make_shared<BindingMenu>
			(static_cast<OptionMenu *>(this->_menu[OPTIONS].get())->getPlayer());
		      this->_menu[BINDINGS]->setObserver(this->_graphic.get());
		    }
		  else if (this->_toLoad == EXIT)
		    return (EXIT_SUCCESS);
		  else
		    this->_menu[this->_toLoad]->setObserver(this->_graphic.get());
		}
	      else if (this->_toLoad == GAME)
		{
		  if (static_cast<PlayMenu *>(this->_menu[PLAY].get())->getNewGame()
		      == false)
		    this->_game =
		      std::unique_ptr<ManageGame>
		      (new ManageGame(static_cast<PlayMenu *>
				      (this->_menu[PLAY].get())->getSave(), molft));
		  else
		    this->_game = 
		      std::unique_ptr<ManageGame>
		      (new ManageGame(static_cast<PlayMenu *>
				      (this->_menu[PLAY].get())->getNbPlayer(), molft));
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
	      this->_toLoad = this->_game->transferKey(receiver.getKey());
	      if (this->_toLoad == PAUSE)
		std::cout << "PAUSE !" << std::endl;
	      if (this->_toLoad != GAME)
		this->_menu[this->_toLoad]->setObserver(this->_graphic.get());
	    }
	  lag -= MS_PER_UPDATE;
	  receiver.setKey(irr::KEY_OEM_8);
	  loaded = this->_toLoad;
	}
      if (this->_toLoad != GAME)
	this->_menu[this->_toLoad]->notify();
      else
	this->_game->notify();
    }
  return (EXIT_SUCCESS);
}
