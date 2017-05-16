//
// Observable.hpp for Observable in /home/pashervz/Epitech/C++/cpp_plazza/include
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Mon Apr 24 14:12:03 2017 Pashervz
// Last update Mon May 15 22:16:01 2017 Pashervz
//

#ifndef OBSERVABLE_HPP_
# define OBSERVABLE_HPP_

#include <memory>
#include <vector>
#include "Element.hpp"
#include "Utils.hpp"

class AObserver;

class Observable
{
protected:
  AObserver				*_observer;
  std::vector<Element *>		_map;
  DType					_type;
public:
  Observable();
  Observable(DType type) : _type(type) {}
  virtual ~Observable();
  void						notify();

  void						setObserver(AObserver *observer) {  _observer = observer; }
  std::vector<Element *>			getMap() const { return (_map); }
  DType						getDType() const { return (_type); }
};

#endif // OBSERVABLE_HPP_
