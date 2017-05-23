//
// main.cpp for main.cpp in /home/tvigier/test
// 
// Made by thomas vigier
// Login   <thomas.vigier@epitech.eu>
// 
// Started on  Wed May 10 11:05:32 2017 thomas vigier
// Last update Sat May 13 15:38:40 2017 thomas vigier
//

#define COL 50

#include "ManageGame.hpp"

int	main()
{
    ManageGame game;

    game.loadMap();
    //    game.printMap();

    while (true)
      game.updateMap();
}
