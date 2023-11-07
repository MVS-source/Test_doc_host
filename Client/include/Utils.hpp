/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Utils.hpp
*/

#pragma once
    #include <SFML/Graphics.hpp>
    #include <cmath>
    #include <memory>
    #include <functional>
    #include "Transform.hpp"
    #include "RigidBody.hpp"
    #include "Animation.hpp"

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define WINDOW_TITLE "R-Type"

///> STRUCTS
struct DrawableParams{
    sf::Vector2f pos = {0, 0};
    sf::Vector2f scale = {1, 1};
    float rotation = 0.0;
    sf::IntRect rect = {0, 0, 0, 0};

    DrawableParams() = default;
    DrawableParams(sf::Vector2f p, sf::Vector2f s, float r, sf::IntRect irect)
        : pos(p), scale(s), rotation(r), rect(irect) {}
};

struct RigidBodyParams{
    sf::Vector2f pos = {0, 0};
    sf::Vector2f velocity = {0, 0};
    sf::FloatRect hitbox = {0, 0, 0, 0};

    RigidBodyParams() = default;
    RigidBodyParams(sf::Vector2f p, sf::Vector2f v, sf::FloatRect h)
        : pos(p), velocity(v), hitbox(h) {}
};


///> RECTS
#define PLAYER_RECT sf::IntRect(0, 0, 33.2, 17.2)
#define SHOOT_RECT sf::IntRect(0, 0, 32.75, 32)
#define PLAYBUTTON_RECT sf::IntRect(0, 0, 400, 300)

///> SIZES
#define PLAYBUTTON_SIZE sf::Vector2f(200, 100)

///> SPRITES
#define BACKGROUND "../../Client/assets/sprites/backgrounds/background.jpg"
#define PLAYER "../../Client/assets/sprites/player/players.png"
#define ENNEMY "../../Client/assets/sprites/r-typesheet22.gif"
#define SHOOT "../../Client/assets/sprites/backgrounds/shoot.png"

///> BUTTONS
#define QUIT "../../Client/assets/sprites/backgrounds/newgameImg.png"
#define ENTER "../../Client/assets/sprites/backgrounds/ready_button.png"
#define TITLE "../../Client/assets/sprites/backgrounds/logo_r-type.png"

///> FONT
#define FONT "../../Client/assets/fonts/OpenSans-Bold.ttf"

///> SOUNDS
#define ESSOUND "../../Client/assets/audio/tie_fighter_shoot.ogg"
#define PSSOUND "../../Client/assets/audio/xwing_shoot.ogg"
#define MUSIC "../../Client/assets/audio/YLAD_OST.ogg"

///> PARALLAX
#define GBACKGROUND "../../Client/assets/sprites/backgrounds/game_background.png"
#define PARALLAX_CLOSE "../../Client/assets/sprites/backgrounds/parallax-space-big-planet.png"
#define PARALLAX_FAR "../../Client/assets/sprites/backgrounds/parallax-space-far-planets.png"