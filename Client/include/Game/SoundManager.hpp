/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** SoundManager.hpp
*/

#pragma once
    #include <SFML/Audio.hpp>
    #include "../Utils.hpp"

class SoundManager {
    public:
        SoundManager() = default;
        ~SoundManager();

        void loadSound(const std::string &path, const std::string &id);
        void playSound(const std::string &id);
        void stopSound(const std::string &id);
        void setVolume(const std::string &id, const float &volume);
        void setLoop(const std::string &id, const bool &loop);
        void stopAllSounds();
        void muteMode(bool mute);
    private:
        std::map<std::string, sf::SoundBuffer> _soundBuffers;
        std::map<std::string, sf::Sound> _sounds;
};
