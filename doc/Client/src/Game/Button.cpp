/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Button.cpp
*/

#include "Button.hpp"

Button::Button(const std::string &path, DrawableParams &&dparams, RigidBodyParams &&rparams, std::function<void()> callback)
: Unit(path, dparams, rparams),
  _callback(callback)
{}

void Button::hovered(sf::Vector2i mousePos)
{
    if (isClicked(mousePos))
        _drawable.setBrightness(1.5);
    else
        _drawable.setBrightness(1);
}

bool Button::isClicked(sf::Vector2i mousePos)
{
    if (_rigidBody.contains(sf::Vector2f(mousePos.x, mousePos.y)))
        return (true);
    return (false);
}

void Button::checkClick(sf::Vector2i mousePos)
{
    if (_rigidBody.contains(sf::Vector2f(mousePos.x, mousePos.y)))
        if (_callback)
            _callback();
}