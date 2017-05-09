//
// Observable.hpp for Observable in /home/pashervz/Epitech/C++/cpp_plazza/include
// 
// Made by Pashervz
// Login   <paul.julien@epitech.eu>
// 
// Started on  Mon Apr 24 14:12:03 2017 Pashervz
// Last update Mon May  8 18:44:42 2017 Pashervz
//

#ifndef OBSERVABLE_HPP_
# define OBSERVABLE_HPP_

class AObserver;

class Observable
{
protected:
  AObserver		*_observer;
  
public:
  Observable();
  virtual ~Observable();
  void			notify();
  void			setObserver(AObserver *);
};

#endif // OBSERVABLE_HPP_
