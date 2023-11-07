/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** PromptBox.hpp
*/

#pragma once
    #include "IBox.hpp"

class PromptBox : public IBox {
    public:
        PromptBox() = default;
        PromptBox(sf::Vector2f pos, sf::Vector2f size, std::string prompt, sf::Font &font);
        PromptBox(const PromptBox &other);

        PromptBox operator=(const PromptBox &other);
        void prompt(sf::Keyboard::Key key, int limit);
        void switchPrompt(sf::Vector2i mousePos);
        std::string getUserInput();
    private:
        std::string _basePrompt;
        bool _promptState;
        sf::String _userInput;
};