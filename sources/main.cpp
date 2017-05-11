//
// main.cpp for main.cpp in /home/tvigier/test
// 
// Made by thomas vigier
// Login   <thomas.vigier@epitech.eu>
// 
// Started on  Wed May 10 11:05:32 2017 thomas vigier
// Last update Wed May 10 11:34:42 2017 thomas vigier
//

#define COL 50

#include "ManageGame.hpp"

int	main()
{
    ManageGame game;

    game.loadMap();

    std::vector<Element>    map(game.getMap());
    int                         pos(0);
    int                         x(0);
    int                         y(0);

    for (const auto it : map)
    {
        std::cout << it.getPath() << std::endl;
        if (it.getPath() == ">")
        {
            x = pos % COL;
            y = (pos - x) / COL;
        }
        pos++;
    }
    std::pair<int, int>     pair(x, y);
    Car     bmw(pair);

    for (int i(0); i < 60; i++)
    {
        bmw.turnLeft();
    }
    for (int i = 0; i < 3000; ++i)
    {
        bmw.accelerate();
        bmw.move();
        std::cout << "position relative :\n x = " << bmw.getPos().first << " y = " << bmw.getPos().second << "\nPosition Map = \n x = " << bmw.getPosMap().first << " y = " << bmw.getPosMap().second << " angle = " << bmw.getAngle() << std::endl << std::endl;
    }

}