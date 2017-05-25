//
// ManageFile.hpp for ManageFile in /home/pashervz/Epitech/C++/Indie/Indie_studio/includes
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Mon May  8 19:43:47 2017 Pashervz
// Last update Tue May 23 14:02:57 2017 Pashervz
//

#pragma once

#include <string>
#include <iostream>
#include <fstream>

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
    _ofFile.open(_fileName, std::ofstream::app);
    if (!_ofFile.is_open())
      throw std::runtime_error("Couldn't open file " + _fileName);
    _ofFile << str;
    _ofFile.close();
  }

  ManageFile(std::string const& filename) : _fileName(filename)
  {
    _ifFile.open(_fileName, std::fstream::in);
    if (!_ifFile.is_open())
      throw std::runtime_error("Couldn't open file " + _fileName);
  }
  
  ~ManageFile()
  {
    _ifFile.close();
  }
};
