/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Music.hpp
*/

#pragma once
    #include <SFML/Audio.hpp>

class Music {
    public:
        Music() = default;
        Music(std::string path);
        void play();
        void stop();
        void setVolume(float volume);
        void repeat(bool repeat);
    protected:
        sf::Music _music;
};