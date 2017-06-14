//
// Music.hpp for  in /home/anthony/rendu/cpp/indie_studio/Indie_studio
//
// Made by jouvel
// Login   <anthony.jouvel@epitech.eu>
//
// Started on  Tue Jun 13 12:16:01 2017 jouvel
// Last update Tue Jun 13 13:21:47 2017 jouvel
//

# pragma once

#include <irrKlang.h>
#include <string>
#include "Error.hpp"

class				Music
{
  irrklang::ISoundEngine	*_engine;
  bool				_music;
  bool				_sound;
public:
  Music();
  ~Music();
  void				setMusic(bool);
  void				setSound(bool);
  void				playMusic(const std::string&);
  void				playSound(const std::string&);
};
