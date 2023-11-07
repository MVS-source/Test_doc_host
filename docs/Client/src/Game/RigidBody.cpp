/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** RigidBody.cpp
*/

#include "RigidBody.hpp"

RigidBody::RigidBody(sf::Vector2f pos, sf::Vector2f vel, sf::FloatRect collider)
: _vel(vel), _collider(collider)
{
    _collider.left = pos.x;
    _collider.top = pos.y;
}

sf::Vector2f RigidBody::getPosition()
{
    return (sf::Vector2f{_collider.left, _collider.top});
}

void RigidBody::setPosition(sf::Vector2f pos)
{
    _collider.left = pos.x;
    _collider.top = pos.y;
}

void RigidBody::setVelocity(sf::Vector2f vel)
{
    _vel = vel;
}

void RigidBody::setCollider(sf::FloatRect collider)
{
    _collider = collider;
}

bool RigidBody::isColliding(const RigidBody &other)
{
    return (_collider.intersects(other._collider));
}

bool RigidBody::contains(sf::Vector2f pos)
{
    return (_collider.contains(pos));
}