/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** ButtonBox.hpp
*/

#pragma once
    #include "IBox.hpp"
    #include "GameObject.hpp"

class ButtonBox : public IBox {
    public:
        ButtonBox() = default;
        ButtonBox(sf::Vector2f pos, sf::Vector2f size, std::string text, std::string path, sf::Font &font);
        void hovered(sf::Vector2i mousePos);
        bool isClicked(sf::Vector2i mousePos);
        void display(sf::RenderWindow &window);
    private:
        GameObject _drawable;
};