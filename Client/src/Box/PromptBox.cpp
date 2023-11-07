/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** PromptBox.cpp
*/

#include "PromptBox.hpp"
#include <iostream>

PromptBox::PromptBox(sf::Vector2f pos, sf::Vector2f size, std::string prompt, sf::Font &font)
: _basePrompt(prompt), _userInput(prompt), _promptState(false)
{
    _box.setPosition(pos);
    _box.setSize(size);
    _box.setFillColor(sf::Color::Blue);
    _text.setFont(font);
    _text.setString(prompt);
    _text.setCharacterSize(20);
    _text.setFillColor(sf::Color::White);
    _text.setPosition(pos.x + 10, pos.y + 20);
}

PromptBox::PromptBox(const PromptBox& other)
    : _basePrompt(other._basePrompt), _userInput(other._userInput), _promptState(other._promptState) {
    _box = other._box;
    _text = other._text;
}

PromptBox PromptBox::operator=(const PromptBox& other) {
    _basePrompt = other._basePrompt;
    _userInput = other._userInput;
    _promptState = other._promptState;
    _box = other._box;
    _text = other._text;
    return *this;
}

void PromptBox::prompt(sf::Keyboard::Key key, int limit)
{
    if (_promptState == false)
        return;
    if (key == sf::Keyboard::BackSpace)
        if (_text.getString().getSize() > _basePrompt.size()) {
            _userInput.erase(_userInput.getSize() - 1);
            _text.setString(_userInput);
            return;
        }
    if (_userInput.getSize() < _basePrompt.size() + limit) {
        key == 51 ? _userInput += "4" : "";// for some reason 4 and 6 are in a different range
        key == 56 ? _userInput += "6" : "";
        if (key >= sf::Keyboard::Num0 && key <= sf::Keyboard::Num9) {
            char c = '0' + (key - sf::Keyboard::Num0);
            _userInput += c;
        }
        if (limit > 12 && key >= sf::Keyboard::A && key <= sf::Keyboard::Z) {
            char c = 'a' + (key - sf::Keyboard::A);
            _userInput += c;
        }
    }
    _text.setString(_userInput);
}

void PromptBox::switchPrompt(sf::Vector2i mousePos)
{
    if (_box.getGlobalBounds().contains(mousePos.x, mousePos.y))
        _promptState = true;
    else
        _promptState = false;
}

std::string PromptBox::getUserInput()
{
    std::string tmp = _userInput;
    tmp.erase(0, _basePrompt.size());
    return (tmp);
}