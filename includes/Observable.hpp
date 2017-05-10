//
// Observable.hpp for Observable in /home/pashervz/Epitech/C++/cpp_plazza/include
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Mon Apr 24 14:12:03 2017 Pashervz
// Last update Tue May  9 13:35:34 2017 Pashervz
//

#ifndef OBSERVABLE_HPP_
# define OBSERVABLE_HPP_

#include "Element.hpp"
#include <vector>

class AObserver;

class Observable
{
protected:
  AObserver			*_observer;
  std::vector<Element>		_map;
  
public:
  Observable();
  virtual ~Observable();
  void				notify();
  void				setObserver(AObserver *);
  std::vector<Element>		getMap() const;
};

#endif // OBSERVABLE_HPP_
