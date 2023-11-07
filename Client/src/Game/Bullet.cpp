/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Bullet.cpp
*/

#include "Bullet.hpp"

Bullet::Bullet(const DrawableParams &Drawableparams, const RigidBodyParams &rigidBodyParams, const std::string &path)
: Unit(path, Drawableparams, rigidBodyParams)
{
    _rigidBody.setPosition(Drawableparams.pos);
}

void Bullet::update(float dt)
{
    sf::Vector2f position = _rigidBody.getPosition();
    position.x += _speed * dt;
    _rigidBody.setPosition(position);
    _drawable.setParams(position, _drawable.getSprite().getScale(), _drawable.getSprite().getRotation());
}

void Bullet::draw(sf::RenderWindow &window)
{
    _drawable.draw(window);
}

sf::Vector2f Bullet::getPosition()
{
    return (_rigidBody.getPosition());
}