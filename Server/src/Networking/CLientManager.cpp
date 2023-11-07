/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** CLientManager.cpp
*/

#include "ClientManager.hpp"

ClientManager::ClientManager(boost::asio::io_context& io_context)
{
    _clients.reserve(_maxClients);
}

ClientManager::~ClientManager()
{
    for (auto &client : _clients) {
        client->tcpsocket.close();
        client->udpSocket.close();
    }
}

size_t ClientManager::addClient(boost::asio::ip::tcp::socket& socket, boost::asio::ip::tcp::endpoint& endpoint, boost::asio::io_context& io_context)
{
    if (_clients.size() >= _maxClients)
        return (0);
    _clients.emplace_back(std::make_unique<ClientInfo>(io_context));
    _clients.back()->tcpsocket = std::move(socket);
    _clients.back()->tcpEndpoint = endpoint;
    _clients.back()->clientId = _clients.size();
    return (_clients.back()->clientId);
}

bool ClientManager::addUdp(boost::asio::ip::udp::socket& socket, boost::asio::ip::udp::endpoint& endpoint, size_t id)
{
    if (id >= _clients.size())
        return false;
    _clients[id]->udpSocket = std::move(socket);
    _clients[id]->udpEndpoint = endpoint;
    return true;
}