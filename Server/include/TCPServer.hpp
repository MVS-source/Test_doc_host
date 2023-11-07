/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** TCPServer.hpp
*/

#pragma once
    #include <boost/asio.hpp>
    #include <boost/bind/bind.hpp>
    #include <boost/shared_ptr.hpp>
    #include <boost/enable_shared_from_this.hpp>
    #include <string>
    #include <ctime>
    #include <iostream>
    #include "ClientManager.hpp"

class TCPConnection : public boost::enable_shared_from_this<TCPConnection> {
    public:
        typedef boost::shared_ptr<TCPConnection> pointer;

        static pointer create(boost::asio::io_context& io_context);
        boost::asio::ip::tcp::socket& socket();

    void start();

    private:
        TCPConnection(boost::asio::io_context& io_context);
        void start_read();

        void handle_write();
        void handle_read(const boost::system::error_code& error, size_t bytes_transferred);

        boost::asio::ip::tcp::socket _socket;
        std::string _message;
        char _data[1024];
};

class TCPServer {
    public:
        TCPServer(boost::asio::io_context& io_context, std::shared_ptr<ClientManager> clientManager);

        void sendToClient(const TCPConnection::pointer& client, const std::string& message);
    private:
        void start_accept();

        void handle_accept(TCPConnection::pointer new_connection, const boost::system::error_code& error);

        boost::asio::io_context& _io_context;
        std::shared_ptr<ClientManager> _clientManager;
        boost::asio::ip::tcp::acceptor _acceptor;
};
