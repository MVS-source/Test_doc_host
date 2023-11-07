/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** RTypeServer.hpp
*/
#pragma once
    #include <boost/asio.hpp>
    #include <string>
    #include <vector>
    #include "../../Client/include/Network/CStreamBuffer.hpp"

/**
 * @brief Represents the main server for RType game
 */
class RTypeServer
{
    public:
        /**
         * @brief Construct a new RType Server object
         */
        RTypeServer(boost::asio::io_context& io_context, short port);

private:
    void handle_receive(const boost::system::error_code& error, std::size_t /*bytes_transferred*/);
    struct data readData();
    void sendData(struct data &d);
    void routine(const boost::system::error_code &, std::size_t);

    private:
        /**
         * @brief Handle received data
         * @param error
         * @param bytes_transferred Amount of bytes received
         */
        //void handle_receive(const boost::system::error_code& error, std::size_t);

    boost::asio::io_context& io_context_;
    boost::asio::ip::udp::socket socket_;
    boost::asio::ip::udp::endpoint remote_endpoint_;
    CStreamBuffer CStreamBuffer_;
    enum { max_length = 1024 };
    char data_[max_length];

        //boost::asio::io_context& io_context_;       ///< I/O context
        //boost::asio::ip::udp::socket socket_;       ///< UDP socket
        //boost::asio::ip::udp::endpoint remote_endpoint_; ///< Endpoint of the remote client
        //enum { max_length = 1024 };
        //char data_[max_length];                 ///< Buffer for incoming data

        //std::vector<ClientInfo> knownClients;       ///< List of known clients
        //int clientIdCounter = 0;                 ///< Counter for generating client IDs
};
