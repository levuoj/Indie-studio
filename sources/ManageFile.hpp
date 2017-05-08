//
// ManageFile.hpp for Indie in /home/anthony/rendu/cpp/indie/Indie_studio
//
// Made by Anthony Jouvel
// Login   <anthony.jouvel@epitech.eu>
//
// Started on  Mon May  8 17:39:11 2017 Anthony Jouvel
// Last update Mon May  8 17:39:22 2017 Anthony Jouvel
//

#ifndef MANAGE_FILE_HPP
# define MANAGE_FILE_HPP

#include <iostream>
#include <fstream>

class		ManageFile
{
private:
  std::string	_fileName;
public:
  ManageFile() {};
  ManageFile(std::string const&);
  ~ManageFile();
  std::string		readFile() const;
  void			writeFile(std::string const&) const;
  void			openFile(std::string const&);
  static std::string	stdin();
};

# endif //MANAGE_FILE_HPP
