/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** UDPServer.cpp
*/

#include "UDPServer.hpp"

UPDServer::UPDServer(boost::asio::io_context& io_context, std::shared_ptr<ClientManager> clientManager)
    : _io_context(io_context), _clientManager(clientManager),
    socket_(io_context, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), 54321))
{
    start_receive();
}

void UPDServer::sendToClient(const boost::asio::ip::udp::endpoint& client, const std::string& message) {
    socket_.async_send_to(boost::asio::buffer(message), client,
        [this](const boost::system::error_code& ec, std::size_t size) {
            if (ec)
                std::cerr << "Error: " << ec.message() << std::endl;
        }
    );
}

void UPDServer::start_receive() {
    socket_.async_receive_from(
        boost::asio::buffer(recv_buffer_), remote_endpoint_,
        [this](const boost::system::error_code& ec, std::size_t bytes_transferred) {
            if (!ec && bytes_transferred > 0) {
                handle_receive(ec, bytes_transferred);
            } else {
                std::cerr << "Error: " << ec.message() << std::endl;
            }
            start_receive();
        });
}


void UPDServer::handle_receive(const boost::system::error_code& error, std::size_t bytes_transferred) {
    if (!error) {
        std::cout << "Received: " << std::string(recv_buffer_.data(), bytes_transferred) << std::endl;

        sendToClient(remote_endpoint_, "Hello from udp server!");
    }
}

void UPDServer::handle_send(boost::shared_ptr<std::string> /*message*/)
{}
