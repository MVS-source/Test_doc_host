/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Button.hpp
*/

#pragma once
    #include "Unit.hpp"

class Button : public Unit {
    public:
        Button(const std::string &path, DrawableParams &&dparams, RigidBodyParams &&rparams, std::function<void()> callback);
        ~Button() = default;

        void hovered(sf::Vector2i mousePos);
        bool isClicked(sf::Vector2i mousePos);
        void checkClick(sf::Vector2i mousePos);

        void update(float dt);
    private:
        std::function<void()> _callback;
};