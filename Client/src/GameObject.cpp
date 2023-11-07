/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** GameObject.cpp
*/

#include "GameObject.hpp"

GameObject::GameObject(std::string path, sf::Vector2f pos) : _path(path), _sprite(sf::Sprite())
{
    if (!_texture.loadFromFile(path)) {
        std::cerr << "Error: could not load texture" << std::endl;
        exit(84);
    }
    _sprite.setTexture(_texture);
    _sprite.setPosition(pos);
}

sf::Sprite &GameObject::getSprite()
{
    return _sprite;
}

sf::Texture &GameObject::getTexture()
{
    return _texture;
}

std::string &GameObject::getPath()
{
    return _path;
}

void GameObject::setPos(sf::Vector2f pos)
{
    _sprite.setPosition(pos);
}

void GameObject::draw(sf::RenderWindow &window)
{
    window.draw(_sprite);
}

sf::Vector2f GameObject::getPos()
{
    return _sprite.getPosition();
}