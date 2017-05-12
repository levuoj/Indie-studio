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

ManageGame::ManageGame()//int nbPlayers, std::vector<std::array<EKey, 5>> keys)
{
/*    for (int i = 0; i < 4 - nbPlayers; ++i)
        _AIs.push_back(AI());
    for (int i = 0; i < nbPlayers; ++i)
        _players.push_back(Player());

    int i = 0;
    for (auto it : _players)
    {
        it.setKeys(keys.at(i));
        ++i;
    }
*/
}

GameElement             ManageGame::ElementFromChar(char c)
{
    std::string             path;
    Element::EType          type;
    std::pair<float, float> pos(50.0, 50.0);

    switch (c)
    {
        case 'X':
            path = "X";
            type = Element::EType::BLOCK;
            break;
        case ' ':
            path = " ";
            type = Element::EType::ROAD;
            break;
        case 'c':
            path = "c";
            type = Element::EType::ENDLINE;
            break;
        case 'o':
            path = "o";
            type = Element::EType::ENDLINE;
            break;
        case '>':
            path = ">";
            type = Element::EType::CAR;
            break;
        default:
            path = "";
            type = Element::EType::DEFAULT;
    }
    GameElement gameElement(path, type, pos);
    return (gameElement);
}

void				ManageGame::loadMap()
{
    ManageFile      file("./assets/circuit/circuit1.txt");
    std::string     map;

    map = file.readFile();

    for (const auto c : map)
    {
        if (c != '\n')
            this->_map.push_back(ElementFromChar(c));
    }
}

std::vector<Element> const&	ManageGame::getMap() const
{
    return (this->_map);
}

void                        ManageGame::printMap()
{
    for (const auto it : this->_map)
    {
        std::cout << it.getPath() << std::endl;
    }
}