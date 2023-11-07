/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** ButtonBox.cpp
*/

#include "ButtonBox.hpp"

ButtonBox::ButtonBox(sf::Vector2f pos, sf::Vector2f size, std::string text, std::string path, sf::Font &font) :
_drawable(path, pos)
{
    _box.setPosition(pos);
    _box.setSize(size);
    _box.setFillColor(sf::Color::Blue);
    _text.setFont(font);
    _text.setString(text);
    _text.setCharacterSize(TEXT_SIZE);
    _text.setFillColor(sf::Color::Black);
    _text.setPosition(pos.x + 65, pos.y + 30);
}

void ButtonBox::hovered(sf::Vector2i mousePos)
{
    if (_box.getGlobalBounds().contains(mousePos.x, mousePos.y))
        _box.setFillColor(sf::Color::Green);
    else
        _box.setFillColor(sf::Color::Blue);
}

bool ButtonBox::isClicked(sf::Vector2i mousePos)
{
    if (_box.getGlobalBounds().contains(mousePos.x, mousePos.y))
        return true;
    return false;
}

void ButtonBox::display(sf::RenderWindow &window)
{
    window.draw(_box);
    _drawable.draw(window);
}