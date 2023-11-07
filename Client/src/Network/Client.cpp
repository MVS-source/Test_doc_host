/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** client.cpp
*/

#include "Client.hpp"

// Client::Client(boost::asio::io_context &io_context, std::string ip) : _socket(io_context)
// {
//     _socket.open(udp::v4());
//     udp::resolver resolver(io_context);
//     udp::resolver::query query(udp::v4(), std::string(ip), std::to_string(PORT));
//     udp::resolver::iterator iter = resolver.resolve(query);
//     _endpoint = *iter;
//     initClient();
//     reciever();
//     sendMsg("Hello from client");
// }

// Client::~Client()
// {
//     _socket.close();
// }

// void Client::initClient()
// {
//     std::cout << "Client initialized." << std::endl;
//     struct data d = {-1, -2, -3};
//     sendData(d);
//     sendMsg("Hello from client");
// }

// void Client::sendMsg(const std::string &msg)
// {
//     try {
//         _socket.send_to(boost::asio::buffer(msg, msg.size()), _endpoint);
//     } catch (const boost::system::system_error& e) {
//         std::cerr << "Error sending message: " << e.what() << std::endl;
//     }
// }

// void Client::sendData(struct data &d)
// {
//     std::cout << "id :" << d.id << "event :" << d.event << "dir :" << d.dir << std::endl;
//     _CStreamBuffer.writeData(d);
//     _socket.send_to(_CStreamBuffer.getCStreamBuffer().data(), _endpoint);
//     _CStreamBuffer.getCStreamBuffer().consume(_CStreamBuffer.getCStreamBuffer().size());
// }

// void Client::reciever()
// {
//     boost::asio::buffer(_rbuffer);
//     _socket.async_receive_from(boost::asio::buffer(_rbuffer), _endpoint,
//             [this](const boost::system::error_code& error, std::size_t bytes_received) {
//                 if (!error) {
//                     std::cout << "Message received." << std::endl;
//                     std::cout << "Server: " << std::string(&_rbuffer[0], bytes_received) << std::endl;
//                     reciever();
//                 } else {
//                     std::cerr << "Receive error: " << error.message() << std::endl;
//                 }
//             });
// }

// bool Client::fire(float x, float y)
// {
//     network::message msg;
//     msg.header.id = network::request::SHOOT;
//     msg << y << x;
//     return (true);
// }

// void Client::sendHi()
// {
//     network::message msg;
//     msg.header.id = network::request::HI;
//     msg << "Hi";
//     _connection->Send(msg);
// }

/* void Client::run()
{
    while (_connection->IsConnected()) {
        
    }
} */