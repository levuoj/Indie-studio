//
// Music.cpp for  in /home/anthony/rendu/cpp/indie_studio/Indie_studio/sources
//
// Made by jouvel
// Login   <anthony.jouvel@epitech.eu>
//
// Started on  Tue Jun 13 12:24:39 2017 jouvel
// Last update Fri Jun 16 02:28:50 2017 Pashervz
//

#include "Music.hpp"

Music::Music()
{
  _engine = irrklang::createIrrKlangDevice();
  _music = true;
  _sound = true;
  if (!_engine)
    throw Error("irrklang can't be launched");
}

Music::~Music()
{
  _engine->drop();
}

#include <iostream>

void			Music::playMusic(const std::string& music)
{
  if (_music == true)
    {
      _engine->stopAllSounds();
      _engine->play2D(music.c_str(), true);
    }
}

void			Music::playSound(const std::string& sound)
{
  if (_sound == true)
    {
      _engine->play2D(sound.c_str(), false);
      if (!_engine)
	throw (Error("Sound asset not found"));
    }
}

void			Music::setMusic(bool state)
{
  _music = state;
  if (state == false)
    _engine->stopAllSounds();
}

void			Music::setSound(bool state)
{
  _sound = state;
}
