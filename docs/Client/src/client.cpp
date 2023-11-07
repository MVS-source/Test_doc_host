/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** client.cpp
*/

#include "../include/Client.hpp"

/**
 * @brief Client constructor using a given io_context
 * @param io_context The I/O context for asynchronous operations
 */
Client::Client(boost::asio::io_context &io_context) : _socket(io_context)
{
    _socket.open(udp::v4());
    udp::resolver resolver(io_context);
    udp::resolver::query query(udp::v4(), std::string("localhost"), std::to_string(PORT));
    udp::resolver::iterator iter = resolver.resolve(query);
    _endpoint = *iter;
    initClient();
    reciever();
}

/**
 * @brief Client destructor
 */
Client::~Client()
{
    _socket.close();
}

/**
 * @brief Initialize the client
 */
void Client::initClient()
{
    std::cout << "Client initialized." << std::endl;
    sendMsg("Hello from client");
    struct data d = {-1, -2, -3};
    sendData(d);
}

/**
 * @brief Send a string message to server
 * @param msg The message to send
 */
void Client::sendMsg(const std::string &msg)
{
    try {
        _socket.send_to(boost::asio::buffer(msg, msg.size()), _endpoint);
    } catch (const boost::system::system_error& e) {
        std::cerr << "Error sending message: " << e.what() << std::endl;
    }
}

/**
 * @brief Send data to server
 * @param d The data to send
 */
void Client::sendData(struct data &d)
{
    _CStreamBuffer.writeData(d);
    _socket.send_to(_CStreamBuffer.getCStreamBuffer().data(), _endpoint);
    _CStreamBuffer.getCStreamBuffer().consume(_CStreamBuffer.getCStreamBuffer().size());
}

/**
 * @brief Receive messages from server (asynchronously)
 */
void Client::reciever()
{
    // _socket.async_receive_from(boost::asio::buffer(_rbuffer), _endpoint,
    //         [this](const boost::system::error_code& error, std::size_t bytes_received) {
    //             if (!error) {
    //                 std::cout << "Message received." << std::endl;
    //                 std::cout << "Server: " << std::string(&_rbuffer[0], bytes_received) << std::endl;
    //                 reciever();
    //             } else {
    //                 std::cerr << "Receive error: " << error.message() << std::endl;
    //             }
    //         });
}
