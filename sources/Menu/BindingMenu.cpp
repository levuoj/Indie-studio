//
// BindingMenu.cpp for BindingMenu in /home/pashervz/Epitech/C++/Indie/Indie_studio/sources
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Mon May 22 17:15:55 2017 Pashervz
// Last update Sat Jun  3 19:36:41 2017 Pashervz
//

#include <sstream>
#include "Bind.hpp"
#include "Button.hpp"
#include "BindingMenu.hpp"

BindingMenu::BindingMenu(std::string const & player) : AMenu("Bindings", BINDINGS),
						       _player(player)
{
  this->_type = DType::BINDINGS;
  this->_map.push_back(std::shared_ptr<Bind>(new Bind(L"n", "assets/deathStar.jpg", Button::BType::BIND)));
  this->_map.push_back(std::shared_ptr<Bind>(new Bind(L"n", "assets/deathStar.jpg", Button::BType::BIND)));
  this->_map.push_back(std::shared_ptr<Bind>(new Bind(L"n", "assets/deathStar.jpg", Button::BType::BIND)));
  this->_map.push_back(std::shared_ptr<Bind>(new Bind(L"n", "assets/deathStar.jpg", Button::BType::BIND)));
  this->_map.push_back(std::shared_ptr<Bind>(new Bind(L"n", "assets/deathStar.jpg", Button::BType::BIND)));
  this->openBindingConf();
  this->assignContent();
  static_cast<Button *>(this->_map[0].get())->setIsSelected(true);
}

void			BindingMenu::keyToString()
{
  _bindingsStrings.clear();
  for (const auto it : _bindings)
    {
      for (const auto it2 : _corresMap)
	{
	  if (it == it2.second)
	    _bindingsStrings.push_back(it2.first);
	}
    }
}

void			BindingMenu::assignContent()
{
  int			idx = 0;
  
  for (auto it = _map.begin() ; it != _map.end() ; ++it)
    {
      static_cast<Button *>(it->get())->setContent(_bindingsStrings[idx]);
      ++idx;
    }
}

void			BindingMenu::getBinds()
{
  _bindings.clear();
  for (auto it = _map.begin() ; it != _map.end() ; ++it)
    {
      _bindings.push_back(static_cast<Bind *>(it->get())->getKey());
    }
}

void			BindingMenu::assignBinds()
{
  int			idx = 0;

  for (auto it = _map.begin() ; it != _map.end() ; ++it)
    {
      static_cast<Bind *>(it->get())->setKey(_bindings[idx]);
      ++idx;
    }
}

std::wstring const	BindingMenu::stringToWstring(std::string const & str) const
{
  std::wstring		tmp(str.begin(), str.end());

  return (tmp);
}

bool			BindingMenu::stringsToKey()
{
  for (const auto it : _bindingsStrings)
    {
      for (const auto it2 : _corresMap)
	{
	  if (it == it2.first)
	    {
	      this->_bindings.push_back(it2.second);
	    }
	}
    }
  if (this->_bindings.size() != 5)
    return (false);
  this->assignBinds();
  return (true);
}

bool			BindingMenu::fillBindingMap(std::string const & line)
{
  std::istringstream		iss(line);
  std::string			tmp;

  while (std::getline(iss, tmp, ' '))
    {
      this->_bindingsStrings.push_back(this->stringToWstring(tmp));
    }
  if (this->_bindingsStrings.size() != 6)
    return (false);
  this->_bindingsStrings.erase(this->_bindingsStrings.begin());
  this->_bindingsStrings.resize(5);
  if (this->stringsToKey() == false)
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
	  if (this->fillBindingMap(tmp) == false)
	    return (false);
	  return (true);
	}
    }
  return (false);  
}

void			BindingMenu::openBindingConf()
{
  try
    {
      ManageFile		manageFile("./Config/"
					   +  this->_player
					   + ".conf");
      std::string		file;

      file = manageFile.readFile();
      if (this->getPlayerInfo(file) == false)
	this->defaultFill(this->_player);
    }
  catch (std::exception const &)
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
  this->_bindings.push_back(irr::KEY_LSHIFT);
  static_cast<Bind *>(this->_map[4].get())->setKey(irr::KEY_LSHIFT);
  this->keyToString();
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
  this->keyToString();
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
  this->_bindings.push_back(irr::KEY_LMENU);
  static_cast<Bind *>(this->_map[4].get())->setKey(irr::KEY_LMENU);
  this->keyToString();
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
  this->_bindings.push_back(irr::KEY_LCONTROL);
  static_cast<Bind *>(this->_map[4].get())->setKey(irr::KEY_LCONTROL);
  this->keyToString();
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
      if (key == irr::KEY_RETURN &&
	  static_cast<Button *>((*it).get())->getIsSelected() == true)
	{
	  if (static_cast<Bind *>((*it).get())->getMode() == false)
	    {
	      static_cast<Bind *>((*it).get())->setMode(true);
	      _bindMode = true;
	    }
	  else if (static_cast<Bind *>((*it).get())->getMode() == true)
	    {
	      static_cast<Bind *>((*it).get())->setMode(false);
	      _bindMode = false;
	    }
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
			  static_cast<Bind *>((*it).get())->setKey(key);
			  break;
			}
		    }
		}
	    }
	}
    }
  this->getBinds();
  this->assignContent();
  this->keyToString();
}

std::string const		BindingMenu::writeChanges()
{
  std::vector<std::string>	config;
  
  for (const auto it :  _bindingsStrings)
    {
      std::string str(it.begin(), it.end());
      config.push_back(str);
    }
  return (this->_player + ": " +
	  config[0]+ " " + config[1] +
	  " " + config[2] + " " + config[3] +
	  " " + config[4] + "\n");
}

void				BindingMenu::saveChanges()
{
  std::ofstream			stream;
  
  stream.open("./Config/" + this->_player + ".conf");
  stream << this->writeChanges();
  stream.close();
}

// static void		printvector(std::vector<std::wstring> vector)
// {
//   for (auto it : vector)
//     std::wcout << it << " ";
//   std::cout << "\n";
// }

DType                   BindingMenu::transferKey(irr::EKEY_CODE key)
{
  if (_bindMode == false)
    {
      switch (key)
	{
	case irr::KEY_RIGHT:
	  this->goDown();
	  break;
	case irr::KEY_LEFT:
	  this->goUp();
	  break;
	case irr::KEY_ESCAPE:
	  this->saveChanges();
	  return (OPTIONS);
	default:
	  this->select(key);
	  break;
	}
    }
  else
    this->select(key);
  //  printvector(this->_bindingsStrings);
  return (BINDINGS);
}
