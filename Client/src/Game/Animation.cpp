/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Animation.cpp
*/

#include "Animation.hpp"

Animation::Animation(sf::Texture *texture, sf::Vector2u imageCount, float switchTime) :
_imageCount(imageCount), _switchTime(switchTime), _totalTime(0.0f), _currImage({0, 0})
{
    _irect.width = texture->getSize().x / float(imageCount.x);
    _irect.height = texture->getSize().y / float(imageCount.y);
}

Animation::~Animation()
{}

void Animation::update(int row ,float deltaTime)
{
    _currImage.y = row;
    _totalTime += deltaTime;

    if (_totalTime >= _switchTime) {
        _totalTime -= _switchTime;
        _currImage.x++;
        if (_currImage.x >= _imageCount.x)
            _currImage.x = 0;
    }
    _irect.left = _currImage.x * _irect.width;
    _irect.top = _currImage.y * _irect.height;
}

const sf::IntRect Animation::getRect()
{
    return _irect;
}