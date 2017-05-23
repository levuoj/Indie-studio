//
// BindingMenu.cpp for BindingMenu in /home/pashervz/Epitech/C++/Indie/Indie_studio/sources
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Mon May 22 17:15:55 2017 Pashervz
// Last update Tue May 23 10:19:38 2017 Pashervz
//

#include <memory>
#include "Button.hpp"
#include "BindingMenu.hpp"

BindingMenu::BindingMenu() : AMenu("Bindings", BINDINGS)
{
  this->_type = DType::BINDINGS;
  this->_map.push_back(std::unique_ptr<Bind>(new Bind(L"Z",
						      "assets/deathStar.jpg")));
  this->_map.push_back(std::unique_ptr<Bind>(new Bind(L"S",
						      "assets/deathStar.jpg")));
  this->_map.push_back(std::unique_ptr<Bind>(new Bind(L"Q",
						      "assets/deathStar.jpg")));
  this->_map.push_back(std::unique_ptr<Bind>(new Bind(L"D",
						      "assets/deathStar.jpg")));
  this->_map.push_back(std::unique_ptr<Bind>(new Bind(L"SPACE",
						      "assets/deathStar.jpg")));
  static_cast<Button *>(this->_map[0].get())->setIsSelected(true);
}

void			BindingMenu::select()
{
  
}

DType                   BindingMenu::transferKey(irr::EKEY_CODE key)
{
  switch (key)
    {
    case irr::KEY_DOWN:
      this->goDown();
      break;
    case irr::KEY_UP:
      this->goUp();
      break;
    case irr::KEY_RETURN:
      return (this->select());
      break;
    case irr::KEY_ESCAPE:
      return (OPTIONS);
      break;
    default:
      break;
    }
  return (BINDINGS);
}
