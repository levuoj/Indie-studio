//
// main.cpp for main.cpp in /home/tvigier/test
// 
// Made by thomas vigier
// Login   <thomas.vigier@epitech.eu>
// 
// Started on  Wed May 10 11:05:32 2017 thomas vigier
// Last update Wed May 10 11:34:42 2017 thomas vigier
//

#include "ManageFile.hpp"

int	main()
{
  ManageFile	file("LOL");

  std::cout << file.readFile() << std::endl;
  file.writeFile("MA GORSSE BITE EN BARME\n");
  std::cout << file.readFile() << std::endl;
  file.writeFile("PTDRRRRRRRRRRRRRRRRRRRRRRRRRRR\n");
  std::cout << file.readFile() << std::endl;
}
