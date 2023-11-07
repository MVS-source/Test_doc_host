/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Music.cpp
*/

#include "Music.hpp"

Music::Music(std::string path)
{
   if (!_music.openFromFile(path))
       throw std::runtime_error("Music: Can't open file");
}

void Music::play()
{
    _music.stop();
    _music.play();
}

void Music::stop()
{
    _music.stop();
}

void Music::setVolume(float volume)
{
    _music.setVolume(volume);
}

void Music::repeat(bool repeat)
{
    _music.setLoop(repeat);
}