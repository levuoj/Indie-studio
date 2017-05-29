//
// BindingMenu.cpp for BindingMenu in /home/pashervz/Epitech/C++/Indie/Indie_studio/sources
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Mon May 22 17:15:55 2017 Pashervz
// Last update Thu May 25 15:22:50 2017 Pashervz
//

#include <memory>
#include <sstream>
#include "Bind.hpp"
#include "Button.hpp"
#include "ManageFile.hpp"
#include "BindingMenu.hpp"

BindingMenu::BindingMenu(std::string const & player) : AMenu("Bindings", BINDINGS), _player(player)
{
  this->_type = DType::BINDINGS;
  this->openBindingConf();
  this->_map.push_back(std::shared_ptr<Bind>(new Bind(this->stringToWstring(_bindingsStrings[0]),
						      "assets/deathStar.jpg", Button::BType::BIND)));
  this->_map.push_back(std::shared_ptr<Bind>(new Bind(this->stringToWstring(_bindingsStrings[1]),
						      "assets/deathStar.jpg", Button::BType::BIND)));
  this->_map.push_back(std::shared_ptr<Bind>(new Bind(this->stringToWstring(_bindingsStrings[2]),
						      "assets/deathStar.jpg", Button::BType::BIND)));
  this->_map.push_back(std::shared_ptr<Bind>(new Bind(this->stringToWstring(_bindingsStrings[3]),
						      "assets/deathStar.jpg", Button::BType::BIND)));
  this->_map.push_back(std::shared_ptr<Bind>(new Bind(this->stringToWstring(_bindingsStrings[4]),
						      "assets/deathStar.jpg", Button::BType::BIND)));
  static_cast<Button *>(this->_map[0].get())->setIsSelected(true);
}

std::wstring const	BindingMenu::stringToWstring(std::string const & str) const
{
  std::wstring		tmp(str.begin(), str.end());

  return (tmp);
}

bool			BindingMenu::stringsToKey(std::vector<std::string> const & strings)
{
  for (const auto it : strings)
    {
      for (const auto it2 : _corresMap)
	{
	  if (it == it2.first)
	    {
	      this->_bindingsStrings.push_back(it);
	      this->_bindings.push_back(it2.second);
	    }
	  else
	    return (false);
	}
    }
  return (true);
}

bool			BindingMenu::fillBindingMap(std::string const & line)
{
  std::istringstream		iss(line);
  std::string			tmp;
  std::vector<std::string>	keyStrings;
  
  while (std::getline(iss, tmp, ' '))
    {
      keyStrings.push_back(tmp);
    }
  this->_bindings.erase(this->_bindings.begin() + 1);
  this->_bindings.resize(5);
  if (this->stringsToKey(keyStrings) == false)
    return (false);
  return (true);
}

bool			BindingMenu::getPlayerInfo(std::string const & file)
{
  std::string			tmp;
  std::istringstream		iss(file);
  
  while (std::getline(iss, tmp))
    {
      std::size_t		pos = tmp.find(":", 0);
      std::string		cmpPlayer;

      cmpPlayer = tmp.substr(0, pos);
      if (cmpPlayer == this->_player)
	{
	  this->fillBindingMap(tmp);
	  return (true);
	}
    }
  return (false);  
}

void			BindingMenu::openBindingConf()
{
  try
    {
      ManageFile		manageFile("bindings.conf");
      std::string		file;

      file = manageFile.readFile();
      if (this->getPlayerInfo(file) == false)
	this->defaultFill(this->_player);
    }
  catch (std::exception const & exep)
    {
      this->defaultFill(this->_player);
    }
}

void			BindingMenu::defaultP1()
{
  this->_bindings.clear();
  this->_bindings.push_back(irr::KEY_KEY_Z);
  static_cast<Bind *>(this->_map[0].get())->setKey(irr::KEY_KEY_Z);
  this->_bindings.push_back(irr::KEY_KEY_S);
  static_cast<Bind *>(this->_map[1].get())->setKey(irr::KEY_KEY_S);
  this->_bindings.push_back(irr::KEY_KEY_Q);
  static_cast<Bind *>(this->_map[2].get())->setKey(irr::KEY_KEY_Q);
  this->_bindings.push_back(irr::KEY_KEY_D);
  static_cast<Bind *>(this->_map[3].get())->setKey(irr::KEY_KEY_D);
  this->_bindings.push_back(irr::KEY_SHIFT);
  static_cast<Bind *>(this->_map[4].get())->setKey(irr::KEY_SHIFT);
}

void			BindingMenu::defaultP2()
{
  this->_bindings.clear();
  this->_bindings.push_back(irr::KEY_KEY_Y);
  static_cast<Bind *>(this->_map[0].get())->setKey(irr::KEY_KEY_Y);
  this->_bindings.push_back(irr::KEY_KEY_H);
  static_cast<Bind *>(this->_map[1].get())->setKey(irr::KEY_KEY_H);
  this->_bindings.push_back(irr::KEY_KEY_G);
  static_cast<Bind *>(this->_map[2].get())->setKey(irr::KEY_KEY_G);
  this->_bindings.push_back(irr::KEY_KEY_J);
  static_cast<Bind *>(this->_map[3].get())->setKey(irr::KEY_KEY_J);
  this->_bindings.push_back(irr::KEY_SPACE);
  static_cast<Bind *>(this->_map[4].get())->setKey(irr::KEY_SPACE);
}

void			BindingMenu::defaultP3()
{
  this->_bindings.clear();
  this->_bindings.push_back(irr::KEY_KEY_O);
  static_cast<Bind *>(this->_map[0].get())->setKey(irr::KEY_KEY_O);
  this->_bindings.push_back(irr::KEY_KEY_L);
  static_cast<Bind *>(this->_map[1].get())->setKey(irr::KEY_KEY_L);
  this->_bindings.push_back(irr::KEY_KEY_K);
  static_cast<Bind *>(this->_map[2].get())->setKey(irr::KEY_KEY_K);
  this->_bindings.push_back(irr::KEY_KEY_M);
  static_cast<Bind *>(this->_map[3].get())->setKey(irr::KEY_KEY_M);
  this->_bindings.push_back(irr::KEY_MENU);
  static_cast<Bind *>(this->_map[4].get())->setKey(irr::KEY_MENU);
}

void			BindingMenu::defaultP4()
{
  this->_bindings.clear();
  this->_bindings.push_back(irr::KEY_UP);
  static_cast<Bind *>(this->_map[0].get())->setKey(irr::KEY_UP);
  this->_bindings.push_back(irr::KEY_DOWN);
  static_cast<Bind *>(this->_map[1].get())->setKey(irr::KEY_DOWN);
  this->_bindings.push_back(irr::KEY_LEFT);
  static_cast<Bind *>(this->_map[2].get())->setKey(irr::KEY_LEFT);
  this->_bindings.push_back(irr::KEY_RIGHT);
  static_cast<Bind *>(this->_map[3].get())->setKey(irr::KEY_RIGHT);
  this->_bindings.push_back(irr::KEY_CONTROL);
  static_cast<Bind *>(this->_map[4].get())->setKey(irr::KEY_CONTROL);
}

void			BindingMenu::defaultFill(std::string const & player)
{
  this->_defaultMap[player]();
}

bool			BindingMenu::checkKey(irr::EKEY_CODE key)
{
  for (const auto it : this->_corresMap)
    {
      if (it.second == key)
	return (true);
    }
  return (false);
}

void			BindingMenu::select(irr::EKEY_CODE key)
{
  for (auto it = this->_map.begin() ; it != this->_map.end() ; ++it)
    {
      if (key == irr::KEY_RETURN)
	{
	  if (static_cast<Button *>((*it).get())->getIsSelected() == true)
	    static_cast<Bind *>((*it).get())->setMode(true);
	  else if (static_cast<Bind *>((*it).get())->getMode() == true)
	    static_cast<Bind *>((*it).get())->setMode(false);
	  break;
	}
      else
	{
	  if (static_cast<Bind *>((*it).get())->getMode() == true)
	    {
	      if (this->checkKey(key) == true)
		{
		  for (auto it3 : _corresMap)
		    {
		      if (key == it3.second)
			{
			  static_cast<Button *>((*it).get())
			    ->setContent(this->stringToWstring(it3.first));
			  static_cast<Bind *>((*it).get())->setKey(key);
			  break;
			}
		    }
		}
	    }
	}
    }
}

void			BindingMenu::saveChanges()
{
  this->_bindings.clear();
  this->_bindingsStrings.clear();
  for (auto it = this->_map.begin() ; it != this->_map.end() ; ++it)
    {
      this->_bindings.push_back(static_cast<Bind *>((*it).get())->getKey());
      for (auto it2 : _corresMap)
	{
	  if (static_cast<Bind *>((*it).get())->getKey() == it2.second)
	    this->_bindingsStrings.push_back(it2.first);
	  break;
	}
    }
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
    case irr::KEY_ESCAPE:
      this->saveChanges();
      return (OPTIONS);
    default:
      this->select(key);
      break;
    }
  return (BINDINGS);
}
