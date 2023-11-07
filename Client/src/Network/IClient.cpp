/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** IClient.cpp
*/

#include "IClient.hpp"

namespace network {
    IClient::IClient(std::string ip, std::string port, std::string id): _io_context(),
    _usocket(_io_context), _tsocket(_io_context), _work(_io_context),
    _ip(ip), _port(port), _id(id)
    {
        // _connection = std::make_unique<Connection>(_io_context, _recvQueue);
        if (!Connect())
            std::cerr << "Failed to connect" << std::endl;
        if (!_connection->SetUdp(IP, UPORT))
            std::cerr << "Failed to set UDP" << std::endl;
    }

    IClient::~IClient()
    {
        Disconnect();
    }

    bool IClient::Connect()
    {
        try {
            _connection = std::make_unique<Connection>(_io_context, _recvQueue);
            _connection->Connect(_ip, _port);
            _context_thread = std::thread([&]() {_io_context.run();});
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
            return (false);
        }
        return (true);
    }

    void IClient::Disconnect()
    {
        if (_connection) {
            _connection->Disconnect();
        }
        _io_context.stop();
        if (_context_thread.joinable())
            _context_thread.join();
        _connection.release();
    }

    bool IClient::isConnected() const
    {
        if (_connection)
            return (_connection->IsConnected());
        return (false);
    }

    TQueue &IClient::getRecvQueue()
    {
        return (_recvQueue);
    }
}