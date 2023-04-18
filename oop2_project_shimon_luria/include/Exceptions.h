#pragma once
#include <exception>
#include <string>
#include <SFML/Graphics.hpp>

struct UnknownCollision : public std::runtime_error
{
    UnknownCollision(Object& a, Object& b)
        : std::runtime_error(std::string("Unknown collision of ") + typeid(a).name() + " and " + typeid(b).name())
    {
    }
};

struct UnknownTypeCollision : public std::runtime_error
{
    UnknownTypeCollision(std::string type)
        : std::runtime_error(std::string (type + (" is invaide in this game. read readme to understunde the file format \n")))
    {
    }
};

struct missPosition : public std::runtime_error
{
    missPosition(int r, int c , sf::Vector2i sizeBoard )
        : std::runtime_error(std::string(("row ")  + std::to_string(r) + " and colum " + std::to_string(c)
            + ("is not exist size of board is") + std::to_string(sizeBoard.y) + "rows X " +
            std::to_string(sizeBoard.x) +( "colums\n"))) {}
};