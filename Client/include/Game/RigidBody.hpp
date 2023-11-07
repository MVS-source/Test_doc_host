/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** RigidBody.hpp
*/

#pragma once
    #include <SFML/Graphics.hpp>

class RigidBody {
    public:
        RigidBody(sf::Vector2f pos = {0, 0}, sf::Vector2f vel = {0, 0}, sf::FloatRect collider = {0, 0, 0, 0});
        ~RigidBody() = default;

        sf::Vector2f getPosition();

        void setPosition(sf::Vector2f pos);
        void setVelocity(sf::Vector2f vel);
        void setCollider(sf::FloatRect collider);

        bool isColliding(const RigidBody &other);
        bool contains(sf::Vector2f pos);
    private:
        sf::Vector2f _vel;
        sf::FloatRect _collider;
};