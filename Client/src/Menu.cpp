/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Menu.cpp
*/

#include "Menu.hpp"
#include "Game.hpp"

Menu::Menu(sf::VideoMode videomode) : _window(videomode, WINDOW_TITLE),
_music(MUSIC),
_background(BACKGROUND, sf::Vector2f(0, 0)),
_title(TITLE, {-100, -100}),
_connect(false),
_play(ENTER, DrawableParams(sf::Vector2f(400, 400), sf::Vector2f(1, 1), 0, PLAYBUTTON_RECT), RigidBodyParams(sf::Vector2f(400, 400), sf::Vector2f(0, 0), sf::FloatRect(PLAYBUTTON_RECT)), [this]() {
    if (checkConnection())
        _connect = true;
})
{
    _font = loadFont();
    _userName = PromptBox(sf::Vector2f(100, 200), sf::Vector2f(300, 70), "USERNAME : ", _font);
    _window.setFramerateLimit(60);
    _music.repeat(true);
    _music.play();
}

void Menu::run()
{
    while (_window.isOpen()) {
        if (!_connect) {
        menuEvents();
        drawMenu();
        /* } else {
            Game game(_window, _userName.getUserInput());
            game.run();
        } */
        }
    }
    _music.stop();
}

bool Menu::checkConnection()
{
    // std::regex ipRegex("^(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.""(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\."
    //                   "(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.""(25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$");
    if (_userName.getUserInput().empty())
        return (false);
    // if (_IpPrompt.getUserInput().size() > 12 || _PortPrompt.getUserInput().size() > 5)
    //     return (false);
    // if (std::stoi(_PortPrompt.getUserInput()) > 9800 || std::stoi(_PortPrompt.getUserInput()) < 0)
    //     return (false);
    // if (!std::regex_match(formatIP(), ipRegex))
    //     return (false);
    return (true);
}

void Menu::drawMenu()
{
    _window.clear();
    _background.draw(_window);
    _title.draw(_window);
    _play.draw(_window);
    _userName.draw(_window);
    _window.display();
}

void Menu::menuEvents()
{
    sf::Event event;

    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape)
                _window.close();
                _userName.prompt(event.key.code, 15);
        }
        if (event.type == sf::Event::Closed)
            _window.close();
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                _userName.switchPrompt(sf::Mouse::getPosition(_window));
                _play.checkClick(sf::Mouse::getPosition(_window));
            }
        }
    }
}

sf::Font Menu::loadFont()
{
    if (!_font.loadFromFile(FONT)) {
        std::cout << "Error: Font not found" << std::endl;
        throw std::runtime_error("Error: Font not found");
    }
    return (_font);
}

std::string Menu::formatIP()
{
    std::string tmp;

    // for (size_t i = 0; i < _IpPrompt.getUserInput().size(); i++) {
    //     tmp += _IpPrompt.getUserInput()[i];
    //     if ((i + 1) % 3 == 0 && (i + 1) != _IpPrompt.getUserInput().size())
    //         tmp += '.';
    // }
    return (tmp.erase(tmp.size() - 1));
}