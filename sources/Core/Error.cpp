//
// Error.cpp for Error in /home/pashervz/Epitech/C++/Indie/Indie_studio/sources
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Wed May 10 13:22:32 2017 Pashervz
// Last update Wed May 10 13:22:33 2017 Pashervz
//

#include "Error.hpp"

Error::Error(std::string const & errorMessage) throw () : _errorMessage(errorMessage) {}

Error::Error(Error const & other) : _errorMessage(other._errorMessage) {}

Error::~Error() throw () {}

Error&		Error::operator=(Error const & other)
{
  if (this != &other)
    this->_errorMessage = other._errorMessage;
  return (*this);
}

const char 	*Error::what() const throw ()
{
  return (this->_errorMessage.c_str());
}
