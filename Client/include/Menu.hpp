/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Menu.hpp
*/

#pragma once
    #include <iostream>
    #include <string>
    #include <SFML/Graphics.hpp>
    #include <SFML/Audio.hpp>
    #include "../Box/PromptBox.hpp"
    #include "GameObject.hpp"
    #include "Music.hpp"
    #include <regex>
    #include "Button.hpp"
    #include <functional>


class Menu {
    public:
        Menu(sf::VideoMode videoMode);
        void run();
        bool checkConnection();
    private:
        void drawMenu();
        void menuEvents();

        sf::RenderWindow _window;
        Music _music;
        GameObject _background;
        GameObject _title;
        bool _connect;
        Button _play;
        sf::Font _font;
        sf::Font loadFont();
        PromptBox _userName;
        std::string formatIP();
};