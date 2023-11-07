/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** IBox.hpp
*/

#pragma once
    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>

#define TEXT_SIZE 24

class IBox {
    public:
        IBox() = default;
        inline sf::RectangleShape &getBox();
        inline sf::Text &getText();
        bool clicked(sf::Vector2i mousePos);
        void draw(sf::RenderWindow &window);
    protected:
        sf::RectangleShape _box;
        sf::Text _text;
};