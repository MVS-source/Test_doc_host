/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Player.cpp
*/

#include "Player.hpp"
    #include <iostream>

Player::Player(const std::string &path, DrawableParams &&dparams, RigidBodyParams &&rparams)
: Unit(path, dparams, rparams)
{
    DrawableParams dParams = {_drawable.getPosition(), sf::Vector2f{1, 1}, 0.0f, SHOOT_RECT};
    RigidBodyParams rbParams = {_drawable.getPosition(), {10, 0}, {0, 0, 0, 0}};
    _bullet = new Bullet(dParams, rbParams);
}

Player::~Player()
{
    delete (_bullet);
}

void Player::update(sf::Vector2f dir, float dt)
{
    move(dir, dt);
    for (auto &bullet : _bullets)
        bullet.update(dt);
    _bullets.erase(std::remove_if(_bullets.begin(), _bullets.end(), [](Bullet &bullet) {
        return (bullet.getPosition().x > 1300);
    }), _bullets.end());
}

void Player::move(sf::Vector2f direction, float dt)
{
    float magnitude = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    if (magnitude != 0) {
        direction.x /= magnitude;
        direction.y /= magnitude;
    }
    float moveSpeed = 250.0f;
    sf::Vector2f movement = direction * moveSpeed * dt;
    setPosition(_drawable.getPosition() + movement);
}

void Player::shoot()
{
    _bullet->setPosition(sf::Vector2f {_drawable.getPosition().x + 30, _drawable.getPosition().y + 10});
    _bullets.push_back(*_bullet);
}

void Player::draw(sf::RenderWindow &window)
{
    _drawable.draw(window);
    for (auto &bullet : _bullets)
        bullet.draw(window);
}
