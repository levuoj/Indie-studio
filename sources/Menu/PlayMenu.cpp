//
// PlayMenu.cpp for PlayMenu in /home/pashervz/Epitech/C++/Indie/Indie_studio/sources/Menu
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Sat Jun  3 16:07:36 2017 Pashervz
// Last update Mon Jun  5 16:11:32 2017 Pashervz
//

#include <sstream>
#include "Button.hpp"
#include "PlayMenu.hpp"
#include "ManageFile.hpp"

PlayMenu::PlayMenu() : AMenu("Play", PLAY)
{
  this->_type = DType::PLAY;
  this->_map.push_back(std::shared_ptr<Button>(new Button(L"n", "assets/deathStar.jpg", Button::BType::SAVE)));
  this->_map.push_back(std::shared_ptr<Button>(new Button(L"n", "assets/deathStar.jpg", Button::BType::SAVE)));
  this->_map.push_back(std::shared_ptr<Button>(new Button(L"n", "assets/deathStar.jpg", Button::BType::SAVE)));
  this->_map.push_back(std::shared_ptr<Button>(new Button(L"1", "assets/deathStar.jpg", Button::BType::NBPLAYER)));
  this->_map.push_back(std::shared_ptr<Button>(new Button(L"2", "assets/deathStar.jpg", Button::BType::NBPLAYER)));
  this->_map.push_back(std::shared_ptr<Button>(new Button(L"3", "assets/deathStar.jpg", Button::BType::NBPLAYER)));
  this->_map.push_back(std::shared_ptr<Button>(new Button(L"4", "assets/deathStar.jpg", Button::BType::NBPLAYER)));
  for (int idx = 1; idx < 4; ++idx)
    {
      std::string	str = "./Saves/Save" + std::to_string(idx) + ".save";
      this->openSave(str);
    }
  this->assignContent();
  static_cast<Button *>(this->_map[0].get())->setIsSelected(true);
}

bool				PlayMenu::getSaveName(std::string const & string)
{
  std::string                   tmp;
  std::istringstream            iss(string);

  while (std::getline(iss, tmp))
    {
      std::wstring		toPush(tmp.begin(), tmp.end());

      std::wcout << toPush << std::endl; 
      _savesName.push_back(toPush);
      return (true);
    }
  return (false);
}

void			PlayMenu::openSave(std::string const & fileName)
{
  try
    {
      ManageFile	manageFile(fileName);
      std::string	file;

      file = manageFile.readFile();
      if (this->getSaveName(file) == false)
	_savesName.push_back(L"empty");
    }
  catch (std::exception const &)
    {
      _savesName.push_back(L"empty");
    }
}

void                    PlayMenu::assignContent() 
{
  for (int idx = 0; idx < 3; ++idx)
    {
      std::wcout << _savesName[idx] << std::endl;
      static_cast<Button *>(_map[idx].get())->setContent(_savesName[idx]);
    }
}

DType			PlayMenu::select()
{
  for (auto it = this->_map.begin() ; it != this->_map.end() ; ++it)
    {
     if (static_cast<Button *>((*it).get())->getIsSelected() == true)
       {
	 if (static_cast<Button *>((*it).get())->getButtonType() == Button::BType::SAVE)
	   {
	     this->_save = static_cast<Button *>((*it).get())->getContent();
	     return (GAME);
	   }
	 else
	   {
	     this->_nbPlayer = std::stoi(static_cast<Button *>((*it).get())->getContent());
	     return (GAME);
	   }
       }
    }
  return (PLAY);
}

DType		        PlayMenu::transferKey(irr::EKEY_CODE key)
{
  switch (key)
    {
    case irr::KEY_RIGHT:
      this->goDown();
      break;
    case irr::KEY_LEFT:
      this->goUp();
      break;
    case irr::KEY_RETURN:
      return (this->select());
      break;
    case irr::KEY_ESCAPE:
      return (MAIN_MENU);
      break;
    default:
      break;
    }
  return (PLAY);
}
