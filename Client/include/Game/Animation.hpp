/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Animation.hpp
*/

#pragma once
    #include <SFML/Graphics.hpp>

class Animation {
    public:
        Animation(sf::Texture *texture, sf::Vector2u imageCount, float switchTime);
        ~Animation();

        void update(int row, float deltaTime);
        const sf::IntRect getRect();
    private:
        bool _state;
        sf::Vector2u _imageCount;
        sf::Vector2u _currImage;
        sf::IntRect _irect;
        float _totalTime;
        float _switchTime;
};