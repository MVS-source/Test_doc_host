/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Renderer.cpp
*/

#include "../include/Renderer.hpp"

/**
 * \brief Default constructor for Renderer class.
 */
Renderer::Renderer()
{}

/**
 * \brief Destructor for Renderer class.
 */
Renderer::~Renderer()
{
    _window.close();
}

/**
 * \brief Initialize the renderer.
 *
 * This function initializes the rendering window with predefined size and title.
 */
void Renderer::initRenderer()
{
    _window.create(sf::VideoMode(1920, 1080), TITLE);
    _window.setFramerateLimit(60);
}

/**
 * \brief Load a sprite from the given file path.
 * 
 * \param path File path to the texture for the sprite.
 */
void Renderer::loadSprite(const std::string &path)
{
    sf::Texture texture;
    sf::Sprite sprite;
    texture.loadFromFile(path);
    sprite.setTexture(texture);
    _sprites.push_back(sprite);
}

/**
 * \brief Draw all loaded sprites to the window.
 */
void Renderer::drawSprite()
{
    for (auto sprite : _sprites)
        _window.draw(sprite);
}

/**
 * \brief Draw text at specified coordinates.
 *
 * \param text The text to draw.
 * \param x The x-coordinate of the text's position.
 * \param y The y-coordinate of the text's position.
 */
void Renderer::drawText(std::string text, double x, double y)
{
    sf::Text textToDraw;
    textToDraw.setString(text);
    textToDraw.setCharacterSize(TEXTSIZE);
    textToDraw.setPosition(x, y);
    _window.draw(textToDraw);
}

/**
 * \brief Clear the screen.
 */
void Renderer::clearScreen()
{
    _window.clear(sf::Color::Black);
}

/**
 * \brief Display the content.
 */
void Renderer::displayScreen()
{
    _window.display();
}
