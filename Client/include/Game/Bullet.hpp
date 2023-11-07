/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Bullet.hpp
*/

#pragma once
    #include "Unit.hpp"

class Bullet : public Unit {
    public:
        Bullet(const DrawableParams &Drawableparams, const RigidBodyParams &rigidBodyParams, const std::string &path = SHOOT);
        ~Bullet() = default;

        void update(float dt);
        void draw(sf::RenderWindow &window);

        sf::Vector2f getPosition();
    private:
        float _speed = 750.0f;
};