//
// Error.hpp for nanotekspice in /home/zawadi_p/rendu/CPP/cpp_nanotekspice/include
// 
// Made by Pierre Zawadil
// Login   <pierre.zawadil@epitech.eu>
// 
// Started on  Thu Feb 16 13:58:49 2017 Pierre Zawadil
// Last update Fri Mar  3 19:53:03 2017 Pierre Zawadil
//

#ifndef ERROR_HPP_
# define ERROR_HPP_

# define ERROR 1

#include <exception>
#include <string>

class Error		: public std::exception
{
  std::string		_errorMessage;
public:
  Error(std::string const& errorMessage) throw();
  Error(Error const & other);
  virtual ~Error() throw();
  
  Error& operator=(Error const &);
  
  virtual const char *what() const throw();
};

#endif /* !ERROR_HPP_ */
