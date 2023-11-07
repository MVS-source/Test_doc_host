/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** TCPServer.cpp
*/

#include "TCPServer.hpp"

TCPConnection::pointer TCPConnection::create(boost::asio::io_context& io_context)
{
    return pointer(new TCPConnection(io_context));
}

boost::asio::ip::tcp::socket& TCPConnection::socket()
{
    return _socket;
}

void TCPConnection::start()
{
    start_read();
}

TCPConnection::TCPConnection(boost::asio::io_context& io_context)
    : _socket(io_context)
{}

void TCPConnection::start_read()
{
    _socket.async_read_some(boost::asio::buffer(_data),
        boost::bind(&TCPConnection::handle_read, shared_from_this(),
        boost::asio::placeholders::error,
        boost::asio::placeholders::bytes_transferred));
}

void TCPConnection::handle_write()
{}

void TCPConnection::handle_read(const boost::system::error_code& error, size_t bytes_transferred)
{
    if (!error) {
        std::cout << "Message from client: " << std::string(_data, bytes_transferred) << std::endl;
        _message = "Hello from server!\n";
        boost::asio::async_write(_socket, boost::asio::buffer(_message),
            boost::bind(&TCPConnection::handle_write, shared_from_this()));
    }
}

TCPServer::TCPServer(boost::asio::io_context& io_context, std::shared_ptr<ClientManager> clientManager)
    : _io_context(io_context), _clientManager(clientManager),
    _acceptor(io_context, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), 12345))
{
    start_accept();
}

void TCPServer::sendToClient(const TCPConnection::pointer& connection, const std::string& message) {
    boost::asio::async_write(connection->socket(), boost::asio::buffer(message),
        [this](const boost::system::error_code& ec, std::size_t size) {
            if (ec)
                std::cerr << "Error: " << ec.message() << std::endl;
        }
    );
}

void TCPServer::start_accept()
{
    TCPConnection::pointer new_connection = TCPConnection::create(_io_context);
    _acceptor.async_accept(new_connection->socket(), boost::bind(&TCPServer::handle_accept, this, new_connection,
    boost::asio::placeholders::error));
}


void TCPServer::handle_accept(TCPConnection::pointer new_connection, const boost::system::error_code& error)
{
    if (!error)
        new_connection->start();
    start_accept();
}