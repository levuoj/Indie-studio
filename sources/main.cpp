//
// main.cpp for indie_studio in /home/zgore/Projects/cpp_2017/Indie_studio
// 
// Made by Pierre Zawadil
// Login   <pierre.zawadil@epitech.eu>
// Started on  Mon May  8 11:13:42 2017 Pierre Zawadil
// Last update Tue May 23 15:02:01 2017 DaZe
//

#include <iostream>
#include "Core.hpp"

int		main(int ac, char **av)
{
  if (ac != 1)
    {
      std::cerr << "Error : " << av[0] << " does not take any argument !" << std::endl;
    }
  try
    {
      Core	core;

      core.launch();
    }
  catch(std::exception const &msg)
    {
      std::cerr << msg.what() << std::endl;
      return (EXIT_ERROR);
    }
  return (EXIT_SUCCESS);
}
