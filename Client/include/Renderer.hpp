/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Renderer.hpp
*/

#pragma once
    #include <SFML/Graphics.hpp>
    #include <SFML/Window.hpp>
    #include <SFML/System.hpp>

#define TITLE "R-Type"
#define TEXTSIZE 24

/**
 * @class Renderer
 * @brief A class for rendering graphical content
 */
class Renderer {
    public:
        /**
         * @brief Constructor
         */
        Renderer();

        /**
         * @brief Destructor
         */
        ~Renderer();

        /**
         * @brief Initializes the rendering window.
         */
        void initRenderer();

        /**
         * @brief Loads a sprite from a file path.
         * @param path The path to the sprite file.
         */
        void loadSprite(const std::string &path);

        /**
         * @brief Draws all loaded sprites to the window.
         */
        void drawSprite();

        /**
         * @brief Draws text on the screen.
         */
        void drawText(std::string text, double x, double y);

        /**
         * @brief Clears the rendering window.
         */
        void clearScreen();

        /**
         * @brief Displays the rendered content on the screen.
         */
        void displayScreen();

    private:
        sf::RenderWindow _window;
        std::vector<sf::Sprite> _sprites;
};
