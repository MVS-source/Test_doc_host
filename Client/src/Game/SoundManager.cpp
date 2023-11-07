/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** SoundLanager.cpp
*/

#include "SoundManager.hpp"

SoundManager::~SoundManager()
{
    stopAllSounds();
}

void SoundManager::loadSound(const std::string &path, const std::string &id)
{
    if (_soundBuffers.find(id) != _soundBuffers.end())
        return;
    if (!_soundBuffers[id].loadFromFile(path))
        throw std::runtime_error("Cannot load sound: " + path);
    _sounds[id].setBuffer(_soundBuffers[id]);
}

void SoundManager::playSound(const std::string &id)
{
    _sounds[id].play();
}

void SoundManager::stopSound(const std::string &id)
{
    _sounds[id].stop();
}

void SoundManager::setVolume(const std::string &id, const float &volume)
{
    _sounds[id].setVolume(volume);
}

void SoundManager::setLoop(const std::string &id, const bool &loop)
{
    _sounds[id].setLoop(loop);
}

void SoundManager::stopAllSounds()
{
    for (auto &sound : _sounds) {
        sound.second.stop();
    }
}

void SoundManager::muteMode(bool mute)
{
    for (auto &sound : _sounds) {
        sound.second.setVolume(mute ? 0 : 50);
    }
}