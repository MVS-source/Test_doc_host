/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** main.cpp
*/

#include "Client.hpp"
#include "Menu.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>


/// @brief Main Client
int main(int ac, char **av) {
    Menu menu(sf::VideoMode(1280, 720)); ///< Set video mode
    menu.run(); //< Run Game client side
    return (0);
}

    // char *msg;
    // boost::asio::io_context io_context;
    // sf::RenderWindow window(sf::VideoMode(1280, 720), "rtype");
    // try {
    //     Client client(io_context, std::string(av[1]));
    //     io_context.run();
    // } catch (const boost::system::system_error& e) {
    //     std::cerr << "Error receiving message: " << e.what() << std::endl;
    //     exit(EXIT_FAILURE);
    // }