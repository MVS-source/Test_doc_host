/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Transform.hpp
*/

#pragma once
    #include <SFML/Graphics.hpp>

class Transform {
    public:
        Transform(sf::Vector2f pos = {0, 0}, sf::Vector2f scale = {1, 1}, float rotation = 0.0);

        void setPosition(sf::Vector2f pos);
        void setScale(sf::Vector2f scale);
        void setRotation(float rotation);

        sf::Vector2f getPos();
        sf::Vector2f getScale();
        float getRotation();
    private:
        sf::Vector2f _pos;
        sf::Vector2f _scale;
        float _rotation;
};