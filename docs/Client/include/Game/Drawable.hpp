/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Drawable.hpp
*/

#pragma once
    #include "Utils.hpp"

class Animation;

class Drawable {
    public:
        Drawable() = default;
        Drawable(std::string path, const DrawableParams &params);
        void draw(sf::RenderWindow &window);

        void setParams(sf::Vector2f pos, sf::Vector2f scale, float rotation);
        void setAnimation(Animation *animation);
        void setBrightness(float brightness);

        const sf::Sprite &getSprite();
        sf::Vector2f getPosition();

        void update(float dt);
    private:
        sf::Texture _texture;
        sf::Sprite _sprite;
        Transform _transform;
        Animation *_animation = nullptr;
};