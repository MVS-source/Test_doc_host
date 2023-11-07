/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** IBox.cpp
*/

#include "IBox.hpp"

sf::RectangleShape &IBox::getBox()
{
    return _box;
}

sf::Text &IBox::getText()
{
    return _text;
}

void IBox::draw(sf::RenderWindow &window)
{
    window.draw(_box);
    window.draw(_text);
}

bool IBox::clicked(sf::Vector2i mousePos)
{
    if (_box.getGlobalBounds().contains(mousePos.x, mousePos.y))
        return (true);
    else
        return (false);
}