//
// main.cpp for main.cpp in /home/tvigier/test
// 
// Made by thomas vigier
// Login   <thomas.vigier@epitech.eu>
// 
// Started on  Wed May 10 11:05:32 2017 thomas vigier
// Last update Tue May 23 13:56:46 2017 DaZe
//

#define COL 50

#include "test.hpp"
#include "ManageGame.hpp"

int	main()
{
  std::array<irr::EKEY_CODE, 5> arr;

    arr[0] = irr::EKEY_CODE::KEY_UP;
    arr[1] = irr::EKEY_CODE::KEY_DOWN;
    arr[2] = irr::EKEY_CODE::KEY_LEFT;
    arr[3] = irr::EKEY_CODE::KEY_RIGHT;
    arr[4] = irr::EKEY_CODE::KEY_SPACE;

    std::vector<std::array<irr::EKEY_CODE, 5>>    test;

    test.push_back(arr);

    ManageGame game(1, test);

    game.controlDriver(irr::EKEY_CODE::KEY_UP);
    // ManageGame game;

    // game.loadMap();
    // //    game.printMap();

    // while (true)
    //   game.updateMap();
}
