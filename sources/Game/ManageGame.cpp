//
// ManageGame.cpp for ManageGame.cpp in /home/tvigier/Indie_studio/sources
// 
// Made by thomas vigier
// Login   <thomas.vigier@epitech.eu>
// 
// Started on  Tue May  9 17:32:16 2017 thomas vigier
// Last update Wed May 10 11:24:36 2017 Lebrun Kilian
//

#include "ManageGame.hpp"
#include "Element.hpp"

ManageGame::ManageGame()//int nbPlayers, std::vector<std::array<EKey, 5>> keys)
{
//    for (int i = 0; i < 4 - nbPlayers; ++i)
//       _AIs.push_back(AI());
//    for (int i = 0; i < nbPlayers; ++i)
//        _players.push_back(Player());
//
//    int i = 0;
//    for (auto it : _players)
//    {
//        it.setKeys(keys.at(i));
//        ++i;
//    }
}

std::vector<Element> const&	ManageGame::getMap() const
{
    return (_map);
}

Element             ManageGame::ElementFromChar(char c)
{
    std::string     path;
    Element::EType  type;

    switch (c)
    {
        case 'X':
            path = "";
            type = Element::EType::BLOCK;
            break;
        case ' ':
            path = "";
            type = Element::EType::DEFAULT;
            break;
        case 'c':
            path = "";
            type = Element::EType::DEFAULT;
            break;
        case 'o':
            path = "";
            type = Element::EType::DEFAULT;
            break;
        case '>':
            path = "";
            type = Element::EType::CAR;
    }
    Element element(path, type);
    return (element);
}

void				ManageGame::loadMap()
{
    ManageFile      file("./assets/circuit/circuit1.txt");
    std::string     map;

    map = file.readFile();

    int             x(0);

    for (const auto c : map)
    {
        if (c != '\n')
            this->_map.push_back(ElementFromChar(c));
        x++;
    }
}
