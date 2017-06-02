//
// GButton.hpp for GButton in /home/pashervz/Epitech/C++/Indie/Indie_studio/sources/Graphic
//
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
//
// Started on  Tue May 30 17:34:35 2017 Pashervz
// Last update Fri Jun  2 10:39:23 2017 jouvel
//

#pragma once

#include "Graphic.hpp"

class GButton
{
public:
  irr::scene::IBillboardTextSceneNode	*_button;
  std::vector<irr::f32>			_positions;
  std::vector<irr::f32>			_textDim;
  const wchar_t				*_text;
  irr::video::SColor			_color;

  GButton(std::vector<irr::f32> positions,
	  std::vector<irr::f32> textDim,
	  const wchar_t *text,
	  irr::video::SColor color) : _positions(positions),
					  _textDim(textDim),
					  _text(text), _color(color) {}
  ~GButton() {}

  void			setButton(irr::scene::ISceneManager *scene, irr::gui::IGUIEnvironment *guienv)
  {
   _button = scene->addBillboardTextSceneNode(guienv->getFont("assets/font/myfont.xml"),
				     _text, 0,
				     irr::core::dimension2d<irr::f32>(_textDim[0], _textDim[1]),
				     irr::core::vector3df(_positions[0], _positions[1], _positions[2]),
				     -1, _color, _color);
  }
  void			setColor(irr::video::SColor color)
  {
    _color = color;
  }
};
