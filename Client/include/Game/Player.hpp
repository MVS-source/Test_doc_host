/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Player.hpp
*/

#pragma once
    #include "Music.hpp"
    #include "Bullet.hpp"

class Player : public Unit {
    public:
        Player(const std::string &path, DrawableParams &&params, RigidBodyParams &&rigidBodyParams);
        ~Player();
        void update(sf::Vector2f position, float dt);
        void shoot();
        void draw(sf::RenderWindow &window);
    private:
        void move(sf::Vector2f position, float dt);
        Bullet *_bullet = nullptr;
        std::vector<Bullet> _bullets;
};