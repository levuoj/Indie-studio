//
// AObserver.hpp for AObserver in /home/pashervz/Epitech/C++/Indie/Indie_studio/includes
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Mon May  8 18:41:32 2017 Pashervz
// Last update Mon May  8 18:41:36 2017 Pashervz
//

#ifndef AOBSERVER_HPP_
# define AOBSERVER_HPP_

#include "Observable.hpp"

class AObserver
{
public:
  virtual void		actualize(Observable const &) = 0;
  virtual ~AObserver() {}
};
  
#endif // AOBSERVER_HPP_
