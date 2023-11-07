/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Unit.cpp
*/

#include "Unit.hpp"

Unit::Unit(const std::string &path, const DrawableParams &dParams, const RigidBodyParams &rbParams)
    : _drawable(path, dParams),
      _rigidBody(rbParams.pos, rbParams.velocity, rbParams.hitbox)
{
    _drawable.setParams(dParams.pos, dParams.scale, dParams.rotation);
}

void Unit::setPosition(sf::Vector2f pos)
{
    _rigidBody.setPosition(pos);
    _drawable.setParams(pos, _drawable.getSprite().getScale(), _drawable.getSprite().getRotation());
}

void Unit::setScale(sf::Vector2f scale)
{
    _drawable.setParams(_drawable.getSprite().getPosition(), scale, _drawable.getSprite().getRotation());
}

void Unit::setRotation(float rotation)
{
    _drawable.setParams(_drawable.getSprite().getPosition(), _drawable.getSprite().getScale(), rotation);
}

void Unit::setAnimation(Animation *animation)
{
    _drawable.setAnimation(animation);
}

void Unit::update(float dt)
{
    _drawable.update(dt);
}

void Unit::draw(sf::RenderWindow &window)
{
    _drawable.draw(window);
}