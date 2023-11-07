/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** ClientManager.hpp
*/

#pragma once
    #include <boost/asio.hpp>

struct ClientInfo {
    ClientInfo(boost::asio::io_context& io) 
        : tcpsocket(io), udpSocket(io) {}
    boost::asio::ip::tcp::socket tcpsocket;
    boost::asio::ip::udp::socket udpSocket;
    boost::asio::ip::udp::endpoint udpEndpoint;
    boost::asio::ip::tcp::endpoint tcpEndpoint;
    std::size_t clientId = 0;
};

class ClientManager {
    public:
        ClientManager(boost::asio::io_context& io_context);
        ~ClientManager();
        size_t addClient(boost::asio::ip::tcp::socket& socket, boost::asio::ip::tcp::endpoint& endpoint, boost::asio::io_context& io_context);
        bool addUdp(boost::asio::ip::udp::socket& socket, boost::asio::ip::udp::endpoint& endpoint, size_t id);
    private:
        std::vector<std::unique_ptr<ClientInfo>> _clients;
        const size_t _maxClients = 4;
};