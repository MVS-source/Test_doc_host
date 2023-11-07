/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Background.hpp
*/

#pragma once
    #include "GameObject.hpp"
    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>
    #include "Utils.hpp"

class Background {
    public:
        Background();
        ~Background() = default;
        void draw(sf::RenderWindow &window);
        void parallax();
    private:
        GameObject _background1;
        GameObject _background2;
        GameObject _parallax_close;
        GameObject _parallax_far;
        sf::Clock _clock;
};