/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** client.hpp
*/

#pragma once
    #include <iostream>
    #include <unistd.h>
    #include <string>
    #include <boost/asio/ip/udp.hpp>
    #include <boost/bind/bind.hpp>
    #include <vector>
    #include "CStreamBuffer.hpp"

#define PORT    4091
#define MAXLINE 1024

using boost::asio::ip::udp;

/**
 * @class Client
 * @brief Networking client
 */
class Client {
    public:
        boost::asio::io_service io_service;  ///< IO service

        /**
         * @brief Constructor
         * @param io_context IO context
         */
        Client(boost::asio::io_context &io_context);

        ~Client();  ///< Destructor

        void initClient();                  ///< Initialize
        void sendMsg(const std::string &msg);  ///< Send message
        void sendData(struct data &d);        ///< Send data
        void reciever();                      ///< Receive data

    private:
        std::size_t _sbufferSize;          ///< Buffer size
        udp::socket _socket;               ///< Socket
        udp::endpoint _endpoint;           ///< Endpoint
        CStreamBuffer _CStreamBuffer;      ///< Stream buffer
};
