/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** GamoObject.hpp
*/

#pragma once
    #include <SFML/Graphics.hpp>
    #include <string>
    #include <iostream>

class GameObject {
    public:
        GameObject() = default;
        GameObject(std::string path, sf::Vector2f pos = {0, 0});
        sf::Sprite &getSprite();
        sf::Texture &getTexture();
        std::string &getPath();
        void setPos(sf::Vector2f pos);
        void draw(sf::RenderWindow &window);
        sf::Vector2f getPos();
    protected:
        std::string _path;
        sf::Texture _texture;
        sf::Sprite _sprite;
};