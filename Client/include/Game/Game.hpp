/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Game.hpp
*/

#pragma once
    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>
    #include "Music.hpp"
    #include "Player.hpp"
    #include "Client.hpp"
    #include "Background.hpp"
    #include "SoundManager.hpp"
    #include "Message.hpp"
    #include "TQueue.hpp"

class Game {
    public:
    Game(sf::RenderWindow &window, std::string name = "player");
    void run();
    private:
    void events();
    void handleInput(sf::Event &event);
    void display();
    void transfer();
    void nextFrame();
    void update(float deltatime);
    void sendCmd(network::message &msg);
    void interpret(network::message &msg);

    sf::RenderWindow &_window;
    std::string _ip;
    std::string _port;
    std::string _name;
    Background _background;
    std::unique_ptr<Client> _client;
    Player _player;
    Player _ennemy1;
    Player _ennemy2;
    sf::Vector2f _dir;
    network::TQueue _toProcess;
    sf::Clock _clock;
    SoundManager _soundManager;
};