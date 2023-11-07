/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Unit.hpp
*/

#pragma once
    #include "Drawable.hpp"

class Unit {
    public:
        Unit(const std::string &path, const DrawableParams &params, const RigidBodyParams &rigidBodyParams);

        void setPosition(sf::Vector2f pos);
        void setScale(sf::Vector2f scale);
        void setRotation(float rotation);
        void setAnimation(Animation *animation);

        void update(float dt);
        void draw(sf::RenderWindow &window);
    protected:
        Drawable _drawable;
        RigidBody _rigidBody;
};