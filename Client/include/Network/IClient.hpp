/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** IClient.hpp
*/

#pragma once
    #include "TQueue.hpp"
    #include "Message.hpp"
    #include "Connection.hpp"

#define PORT "12345"
#define UPORT "54321"
#define IP "127.0.0.1"

namespace network {
    class IClient {
        public:
            IClient(std::string ip = IP, std::string port = PORT, std::string id = "");
            virtual ~IClient();
            bool Connect();
            void Disconnect();
            bool isConnected() const;
            TQueue &getRecvQueue();
        protected:
            boost::asio::io_context _io_context;
            boost::asio::io_context::work _work;
            boost::asio::ip::udp::socket _usocket;
            boost::asio::ip::tcp::socket _tsocket;
            std::thread _context_thread;
            boost::asio::ip::udp::endpoint _uendpoint;
            boost::asio::ip::tcp::endpoint _tendpoint;
            boost::system::error_code _ec;
            // first sets everything up asio related then pass it to connection
            std::unique_ptr<Connection> _connection;
        private:
            TQueue _recvQueue;
            std::string _ip;
            std::string _port;
            std::string _id;
    };
}