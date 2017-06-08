//
// Observable.hpp for Observable in /home/pashervz/Epitech/C++/cpp_plazza/include
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Mon Apr 24 14:12:03 2017 Pashervz
// Last update Tue Jun  6 15:08:00 2017 DaZe
//

#ifndef OBSERVABLE_HPP_
# define OBSERVABLE_HPP_

#include <memory>
#include <vector>
#include "Chrono.hpp"
#include "Element.hpp"
#include "Utils.hpp"

class AObserver;

class Observable
{
protected:
  AObserver					*_observer;
  std::vector<std::shared_ptr<Element>>		_map;
  DType						_type;
  Chrono					_chrono;
public:
  Observable();
  Observable(DType type) : _type(type) {}
  virtual ~Observable();
  void						notify();
  void						setObserver(AObserver *observer) {  _observer = observer; }
  std::vector<std::shared_ptr<Element>> const&	getMap() const { return (_map); }
  DType						getDType() const { return (_type); }
  Chrono const &				getChrono() const { return (_chrono); }
};

#endif // OBSERVABLE_HPP_
