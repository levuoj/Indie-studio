//
// ManageFile.hpp for ManageFile in /home/pashervz/Epitech/C++/Indie/Indie_studio/includes
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Mon May  8 19:43:47 2017 Pashervz
// Last update Mon May  8 19:43:49 2017 Pashervz
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
