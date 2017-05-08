//
// ManageFile.cpp for Indie in /home/anthony/rendu/cpp/indie/Indie_studio
//
// Made by Anthony Jouvel
// Login   <anthony.jouvel@epitech.eu>
//
// Started on  Mon May  8 17:38:56 2017 Anthony Jouvel
// Last update Mon May  8 17:39:47 2017 Anthony Jouvel
//

#include <stdexcept>
#include "ManageFile.hpp"

ManageFile::ManageFile(std::string const& file) : _fileName(file)
{}

ManageFile::~ManageFile()
{}

std::string		ManageFile::readFile() const
{
  std::ifstream		f(_fileName.c_str());
  std::string		buffer;

  if (!f.is_open())
    throw std::runtime_error("Couldn't open file " + _fileName);
  f.seekg(0, std::ios::end);
  buffer.resize(f.tellg());
  f.seekg(0);
  f.read((char *)buffer.data(), buffer.size());
  f.close();
  return (buffer);
}

std::string		ManageFile::stdin()
{
  std::string		buffer;

  std::getline(std::cin, buffer);
  if (std::cin.eof())
    throw std::runtime_error("");
  if (buffer == "")
    return (" ");
  return (buffer);
}

void		ManageFile::writeFile(std::string const& buffer) const
{
  std::ofstream f(_fileName.c_str());

  if (f.is_open())
    {
      f.write(buffer.data(), buffer.size());
      f.close();
    }
}

void		ManageFile::openFile(std::string const& file)
{
  _fileName = file;
}
