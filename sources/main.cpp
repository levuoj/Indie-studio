//
// main.cpp for indie_studio in /home/zgore/Projects/cpp_2017/Indie_studio
//
// Made by Pierre Zawadil
// Login   <pierre.zawadil@epitech.eu>
// Started on  Mon May  8 11:13:42 2017 Pierre Zawadil
// Last update Sat Jun 17 20:53:42 2017 Pierre Zawadil
//

#include <iostream>
#include "Core.hpp"

int		main(int ac, char **av)
{
  if (getenv("DISPLAY") == NULL)
    {
      std::cerr << "Error : Some environement variable are missing." << std::endl;
      return (EXIT_ERROR);
    }
  if (ac != 1)
    {
      std::cerr << "Error : " << av[0] << " does not take any argument !" << std::endl;
      return (EXIT_ERROR);
    }
  try
    {
      Core	core;

      if (core.launch() == EXIT_SUCCESS)
	return (EXIT_SUCCESS);
    }
  catch(std::exception const &msg)
    {
      std::cerr << msg.what() << std::endl;
      return (EXIT_ERROR);
    }
  return (EXIT_SUCCESS);
}
