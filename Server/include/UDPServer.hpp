/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** UDPServer.hpp
*/

#pragma once
    #include <boost/asio.hpp>
    #include <boost/bind/bind.hpp>
    #include <iostream>
    #include "ClientManager.hpp"

class UPDServer {
    public:
        UPDServer(boost::asio::io_context& io_context, std::shared_ptr<ClientManager> clientManager);

        void sendToClient(const boost::asio::ip::udp::endpoint& client, const std::string& message);
    private:
        void start_receive();
        void handle_receive(const boost::system::error_code& error, std::size_t bytes_transferred);

        void handle_send(boost::shared_ptr<std::string> /*message*/);

        boost::asio::io_context& _io_context;
        std::shared_ptr<ClientManager> _clientManager;
        boost::asio::ip::udp::socket socket_;
        boost::asio::ip::udp::endpoint remote_endpoint_;
        std::array<char, 1024> recv_buffer_;
};