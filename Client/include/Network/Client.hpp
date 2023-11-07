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
    #include "IClient.hpp"


// #define PORT    12345
// #define MAXLINE 1024

// using boost::asio::ip::udp;

// class Client {
//     public:
//     boost::asio::io_service io_service;
//         Client(boost::asio::io_context &io_context, std::string ip);
//         ~Client();
//         void initClient();
//         void sendMsg(const std::string &msg);
//         void sendData(struct data &d);
//         void reciever();
//     private:
//         std::size_t _sbufferSize;
//         udp::socket _socket;
//         udp::endpoint _endpoint;
//         std::array<char, MAXLINE> _rbuffer;
//         std::string _ip;
//         std::string _port;
//         std::string _id;
// };

class Client : public network::IClient {
    public:
        Client(std::string ip, std::string port, std::string id): network::IClient(ip, port, id) {};
        void run();
        // bool fire(float x, float y);
        // void sendHi();
    private:
};