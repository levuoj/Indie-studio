//
// Error.hpp for Error in /home/pashervz/Epitech/C++/Indie/Indie_studio/includes
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Wed May 10 13:23:07 2017 Pashervz
// Last update Wed May 10 13:23:09 2017 Pashervz
//

#ifndef ERROR_HPP_
# define ERROR_HPP_

#include <exception>
#include <string>

class Error		: public std::exception
{
  std::string		_errorMessage;
public:
  Error(std::string const&) throw ();
  Error(Error const &);
  virtual ~Error() throw();

  Error& operator=(Error const &);
  virtual const char *what() const throw();
};

#endif /* !ERRROR_HPP_ */
