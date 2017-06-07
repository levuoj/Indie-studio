//
// Error.cpp for nanotekspice in /home/zawadi_p/rendu/CPP/cpp_nanotekspice/sources
// 
// Made by Pierre Zawadil
// Login   <pierre.zawadil@epitech.eu>
// 
// Started on  Thu Feb 16 13:58:09 2017 Pierre Zawadil
// Last update Fri Mar  3 19:52:39 2017 Pierre Zawadil
//

#include "Error.hpp"

Error::Error(std::string const& errorMessage) throw() : _errorMessage(errorMessage) {}

Error::~Error() throw() {}

Error::Error(Error const & other) :  _errorMessage(other._errorMessage) {}

Error&			Error::operator=(Error const & other)
{
  if (this != &other)
    {
      this->_errorMessage = other._errorMessage;
    }
  return (*this);
}

const char		*Error::what() const throw()
{
  return (this->_errorMessage.c_str());
}
