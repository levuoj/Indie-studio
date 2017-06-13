//
// Leaderboard.hpp for Leaderboard in /home/pashervz/Epitech/C++/Indie/Indie_studio/includes
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Tue Jun 13 12:05:24 2017 Pashervz
// Last update Tue Jun 13 12:50:47 2017 Pashervz
//

#pragma once

#include "AMenu.hpp"

class Leaderboard : public AMenu
{
public:
  Leaderboard() : AMenu ("Leaderboard", LEADERBOARD)
  {
    _type = LEADERBOARD;
  }
  ~Leaderboard() {}
  DType					transferKey(irr::EKEY_CODE);
  //  void				        fillLeaderboard(std::string const & file);
  //void					openLeaderboard();
  //std::vector<std::wstring> const &	getLeaderboard() const
  //{
  //  return (_leaderboard);
  //}
};


// void				Leaderboard::fillLeaderboard(std::string const & file)
// {
//   std::string			tmp;
//   std::istringstream		iss(file);
//   int				idx = 0;

//   while (std::getline(iss, tmp) && idx < 3)
//     {
//       std::size_t		size;

//       std::stod(tmp, &size);
      
//       std::wstring	        score(tmp.begin(), tmp.end());

//       _leaderboard.push_back(score);
//       ++idx;
//     }
// }

// void				Leaderboard::openLeaderboard()
// {
//   try
//     {
//       ManageFile		manageFile("./Config/leaderboard");
//       std::string		file;

//       file = manageFile.readFile();
//       fillLeaderboard(file);
//     }
//   catch (std::exception const &)
//     {
//       _leaderboard.push_back(L"");
//     }
// }
