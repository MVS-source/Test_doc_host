/* 
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Game.cpp
*/
/*
#include "Game.hpp"
#include "Client.hpp"
#include "IClient.hpp"
#include "Message.hpp"


Game::Game(sf::RenderWindow &window, std::string name)
    : _window(window), _name(name),
    _background(),
    _player(PLAYER, DrawableParams(sf::Vector2f{0, 0}, sf::Vector2f{2, 2}, 0.0f, PLAYER_RECT), RigidBodyParams(sf::Vector2f{0, 0}, sf::Vector2f{0, 0}, sf::FloatRect(0, 16, 33.5, 16))),
    _ennemy1(ENNEMY, DrawableParams(sf::Vector2f{0, 0}, sf::Vector2f{1, 1}, 0.0f, PLAYER_RECT), RigidBodyParams(sf::Vector2f{0, 0}, sf::Vector2f{0, 0}, sf::FloatRect(0, 16, 33.5, 16))),
    _ennemy2(ENNEMY, DrawableParams(sf::Vector2f{0, 0}, sf::Vector2f{1, 1}, 0.0f, PLAYER_RECT), RigidBodyParams(sf::Vector2f{0, 0}, sf::Vector2f{0, 0}, sf::FloatRect(0, 16, 33.5, 16))),
    _clock(sf::Clock()), _soundManager()
{
    _client = std::make_unique<Client>(IP, PORT, _name);
    _soundManager.loadSound(PSSOUND, "PlayerShoot");
}

void Game::run()
{
    const float refresh_rate = 1.0f / 60.0f;
    float deltatime;
    while (_window.isOpen()) {
        deltatime = _clock.getElapsedTime().asSeconds();
        _background.parallax();
        events();
        display();
        nextFrame();
        if (deltatime >= refresh_rate) {
            update(refresh_rate);
            deltatime -= refresh_rate;
        }
    }
}

void Game::events()
{
    sf::Event event;

    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            _window.close();
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape)
                _window.close();
        }
    }
    handleInput(event);
}

void Game::handleInput(sf::Event &event)
{
    int moveAmount = 10;
    if (event.key.code == sf::Keyboard::Up) {
        _dir.y -= moveAmount;
    } else if (event.key.code == sf::Keyboard::Down) {
        _dir.y += moveAmount;
    } else if (event.key.code == sf::Keyboard::Left) {
        _dir.x -= moveAmount;
    } else if (event.key.code == sf::Keyboard::Right) {
        _dir.x += moveAmount;
    } else if (event.key.code == sf::Keyboard::Space) {
        _player.shoot();
        _soundManager.playSound("PlayerShoot");
    }

    if (event.type == sf::Event::KeyReleased) {
        switch (event.key.code) {
            case sf::Keyboard::Up:
            case sf::Keyboard::Down:
                _dir.y = 0;
                break;
            case sf::Keyboard::Left:
            case sf::Keyboard::Right:
                _dir.x = 0;
                break;
            default:
                break;
        }
    }
}

void Game::display()
{
    _window.clear();
    _background.draw(_window);
    _player.draw(_window);
    _window.display();
}

void Game::transfer()
{
    while (!_client->getRecvQueue().empty()) {
        network::message msg = _client->getRecvQueue().pop_front();
        _toProcess.push_back(msg);
    }
}

void Game::nextFrame()
{
    while (!_toProcess.empty()) {
        network::message msg = _toProcess.pop_front();
        interpret(msg);
    }
}

void Game::update(float deltatime)
{
    _player.update(_dir, deltatime);
}

void Game::sendCmd(network::message &msg)
{}

void Game::interpret(network::message &msg)
{} */