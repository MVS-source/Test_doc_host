/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Connection.cpp
*/

#include "Connection.hpp"

namespace network {
    Connection::Connection(boost::asio::io_context &io_context, TQueue &recvqueue) :
    _io_context(io_context), _usocket(_io_context), _tsocket(_io_context), _sendQueue(),
     _recvQueue(recvqueue)
    {}

    Connection::~Connection()
    {
        Disconnect();
    }

    bool Connection::Connect(std::string ip, std::string port)
    {
        try {
            _tsocket.open(boost::asio::ip::tcp::v4());
            boost::asio::ip::tcp::resolver resolver(_io_context);
            boost::asio::ip::tcp::resolver::query query(boost::asio::ip::tcp::v4(), ip, port);
            boost::asio::ip::tcp::resolver::iterator iter = resolver.resolve(query);
            boost::asio::ip::tcp::resolver::results_type endpoints = resolver.resolve(ip, port);
            boost::asio::connect(_tsocket, endpoints);
            std::cout << "Connected to server" << std::endl;
            return (true);
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
        return (false);
    }

    bool Connection::SetUdp(std::string ip, std::string port)
    {
        try {
            _usocket.open(boost::asio::ip::udp::v4());
            boost::asio::ip::udp::resolver resolver(_io_context);
            boost::asio::ip::udp::resolver::query query(boost::asio::ip::udp::v4(), ip, port);
            boost::asio::ip::udp::resolver::iterator iter = resolver.resolve(query);
            _uendpoint = *iter;
            if (!Send("Hello from client"))
                return (false);
            return (true);
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
        return (false);
    }

    bool Connection::Disconnect()
    {
        if (_tsocket.is_open()) {
            _tsocket.close();
            return (true);
        }
        return (false);
    }

    bool Connection::IsConnected() const
    {
        return (_tsocket.is_open());
    }

    bool Connection::Send(const std::string &msg)
    {
        try {
            _usocket.send_to(boost::asio::buffer(msg, msg.size()), _uendpoint);
        } catch (const boost::system::system_error& e) {
            std::cerr << "Error sending message: " << e.what() << std::endl;
            return (false);
        }
        return (true);
    }

    void Connection::TSend()
    {
        // if (_sendQueue.empty())
        //     return;
        // message msg = _sendQueue.pop();
        // try {
        //     boost::asio::write(_usocket, boost::asio::buffer(msg.data(), msg.length()));
        // } catch (std::exception &e) {
        //     std::cerr << e.what() << std::endl;
        // }
    }
}

// void Client::sendMsg(const std::string &msg)
// {
//     try {
//         _socket.send_to(boost::asio::buffer(msg, msg.size()), _endpoint);
//     } catch (const boost::system::system_error& e) {
//         std::cerr << "Error sending message: " << e.what() << std::endl;
//     }
// }