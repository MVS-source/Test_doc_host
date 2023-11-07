/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Transform.cpp
*/

#include "Transform.hpp"

Transform::Transform(sf::Vector2f pos, sf::Vector2f scale, float rotation)
: _pos(pos), _scale(scale), _rotation(rotation)
{}

void Transform::setPosition(sf::Vector2f pos)
{
    _pos = pos;
}

void Transform::setScale(sf::Vector2f scale)
{
    _scale = scale;
}

void Transform::setRotation(float rotation)
{
    _rotation = rotation;
}

sf::Vector2f Transform::getPos()
{
    return (_pos);
}

sf::Vector2f Transform::getScale()
{
    return (_scale);
}

float Transform::getRotation()
{
    return (_rotation);
}