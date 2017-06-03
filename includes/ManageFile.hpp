//
// ManageFile.hpp for ManageFile in /home/pashervz/Epitech/C++/Indie/Indie_studio/includes
//
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
//
// Started on  Mon May  8 19:43:47 2017 Pashervz
// Last update Sat Jun  3 12:36:17 2017 Pashervz
//

#pragma once

#include <string>
#include <iostream>
#include <fstream>
//#include <windows.h>
#include "Error.hpp"

class		ManageFile
{
private:
  std::string	_fileName;
  std::ifstream _ifFile;
  std::ofstream	_ofFile;
public:
  std::string const	readFile()
  {
    std::string		tmp;
    std::string		line;

    while (getline(_ifFile, tmp))
      line += tmp + '\n';
    return (line);
  }

  void			writeFile(std::string const& str)
  {
    _ofFile.open(_fileName);
    _ofFile << str;
    _ofFile.close();
  }

  ManageFile(std::string const& filename) : _fileName(filename)
  {
    _ifFile.open(_fileName, std::fstream::in);
    if (!_ifFile.is_open())
      throw Error("Can't open file");
  }

  ~ManageFile()
  {
    _ifFile.close();
  }
};
