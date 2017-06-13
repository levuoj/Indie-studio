//
// PauseMenu.cpp for PauseMenu in /home/pashervz/Epitech/C++/Indie/Indie_studio/sources/Menu
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Wed Jun  7 11:10:46 2017 Pashervz
// Last update Tue Jun 13 12:34:40 2017 Pashervz
//

#include <sstream>
#include "Button.hpp"
#include "SaveButton.hpp"
#include "PauseMenu.hpp"

PauseMenu::PauseMenu(ManageGame *game) : AMenu("Pause", PAUSE), _game(game)
{
  this->_type = DType::PAUSE;
  this->_map.push_back(std::shared_ptr<Button>(new Button(L"back to game", "assets/deathStar.jpg", Button::BType::RESUME)));
  this->_map.push_back(std::shared_ptr<Button>(new Button(L"back to menu", "assets/deathStar.jpg", Button::BType::EXIT)));
  this->_map.push_back(std::shared_ptr<SaveButton>(new SaveButton(L"n", "assets/deathStar.jpg", Button::BType::SAVE, 1)));
  this->_map.push_back(std::shared_ptr<SaveButton>(new SaveButton(L"n", "assets/deathStar.jpg", Button::BType::SAVE, 2)));
  this->_map.push_back(std::shared_ptr<SaveButton>(new SaveButton(L"n", "assets/deathStar.jpg", Button::BType::SAVE, 3)));
  for (int idx = 1; idx < 4; ++idx)
    {
      std::string	str = "./Saves/Save" + std::to_string(idx) + ".save";
      this->openSave(str);
    }
  this->assignContent();
  static_cast<Button *>(this->_map[0].get())->setIsSelected(true);
}

bool				PauseMenu::getSaveName(std::string const & string)
{
  std::string                   tmp;
  std::istringstream            iss(string);

  while (std::getline(iss, tmp))
    {
      std::wstring		toPush(tmp.begin(), tmp.end());

      _savesName.push_back(toPush);
      return (true);
    }
  return (false);
}

void			PauseMenu::openSave(std::string const & fileName)
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

void                    PauseMenu::assignContent()
{
  for (int idx = 0; idx < 3; ++idx)
    {
      static_cast<Button *>(_map[idx + 2].get())->setContent(_savesName[idx]);
    }
}

DType			PauseMenu::select()
{
  for (auto it = this->_map.begin() ; it != this->_map.end() ; ++it)
    {
     if (static_cast<Button *>((*it).get())->getIsSelected() == true)
       {
	 if (static_cast<Button *>((*it).get())->getButtonType()
	     == Button::BType::RESUME)
	   {
	     return (GAME);
	   }
	 else if (static_cast<Button *>((*it).get())->getButtonType()
		  == Button::BType::SAVE)
	   {
	     this->_game->makeSave(static_cast<SaveButton *>((*it).get())->getNumber());
	     return (MAIN_MENU);
	   }
	 else
	   return (MAIN_MENU);
       }
    }
  return (PAUSE);
}

DType		        PauseMenu::transferKey(irr::EKEY_CODE key)
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
      return (GAME);
      break;
    default:
      break;
    }
  return (PAUSE);
}
