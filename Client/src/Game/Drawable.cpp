/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Drawable.cpp
*/

#include "Drawable.hpp"

Drawable::Drawable(std::string path, const DrawableParams &params)
: _sprite(sf::Sprite()), _transform(Transform(params.pos, params.scale, params.rotation))
{
    if (!_texture.loadFromFile(path))
        throw std::runtime_error("Drawable: Can't open file");
    _sprite.setTexture(_texture);
    _sprite.setTextureRect(params.rect);
}

void Drawable::draw(sf::RenderWindow &window)
{
    _sprite.setPosition(_transform.getPos());
    _sprite.setRotation(_transform.getRotation());
    _sprite.setScale(_transform.getScale());
    window.draw(_sprite);
}

void Drawable::setParams(sf::Vector2f pos, sf::Vector2f scale, float rotation)
{
    _transform.setPosition(pos);
    _transform.setScale(scale);
    _transform.setRotation(rotation);
}

void Drawable::setAnimation(Animation *animation)
{
    _animation = animation;
}

void Drawable::setBrightness(float brightness)
{
    _sprite.setColor(sf::Color(brightness, brightness, brightness));
}

const sf::Sprite &Drawable::getSprite()
{
    return (_sprite);
}

sf::Vector2f Drawable::getPosition()
{
    return (_transform.getPos());
}

void Drawable::update(float dt)
{
    if (_animation) {
        _animation->update(0, dt);
        _sprite.setTextureRect(_animation->getRect());
    }
}