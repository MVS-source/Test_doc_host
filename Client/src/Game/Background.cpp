/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Background.cpp
*/

#include "Background.hpp"

Background::Background() :
_background1(GBACKGROUND, {0, 0}), _background2(GBACKGROUND, {1300, 0}),
_parallax_close(PARALLAX_CLOSE, {300, 300}),
_parallax_far(PARALLAX_FAR, {600, 200}), _clock(sf::Clock())
{}

void Background::draw(sf::RenderWindow &window)
{
    _background1.draw(window);
    _background2.draw(window);
    _parallax_close.draw(window);
    _parallax_far.draw(window);
}

void Background::parallax()
{
    sf::Time time = _clock.getElapsedTime();
    if (time > sf::milliseconds(10)) {
        _background1.getSprite().move(-0.5, 0);
        _background2.getSprite().move(-0.5, 0);
        _parallax_close.getSprite().move(-0.4, 0);
        _parallax_far.getSprite().move(-0.3, 0);
        if (_parallax_close.getSprite().getPosition().x < -200)
            _parallax_close.getSprite().setPosition(1300, 300);
        if (_parallax_far.getSprite().getPosition().x < -300)
            _parallax_far.getSprite().setPosition(1300, 200);
        if (_background1.getSprite().getPosition().x < -1300)
            _background1.getSprite().setPosition(1300, 0);
        if (_background2.getSprite().getPosition().x < -1300)
            _background2.getSprite().setPosition(1300, 0);
        _clock.restart();
    }
}