/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Conncection.hpp
*/

#pragma once
    #include "TQueue.hpp"
    #include "Message.hpp"
    #include <boost/asio.hpp>

namespace network {
    class Connection : public std::enable_shared_from_this<Connection> {
        public:
            Connection(boost::asio::io_context &io_context, TQueue &recvQueue);
            ~Connection();

            bool Connect(std::string ip, std::string port);
            bool SetUdp(std::string ip, std::string port);
            bool Disconnect();
            bool IsConnected() const;
            bool Send(const std::string &msg);
            void TSend();
        private:
            boost::asio::io_context &_io_context;
            boost::asio::ip::udp::socket _usocket;
            boost::asio::ip::tcp::socket _tsocket;
            boost::asio::ip::udp::endpoint _uendpoint;
            TQueue _sendQueue;
            TQueue &_recvQueue;
    };
}