#include "RTypeServer.hpp"
#include <iostream>
#include "ClientManager.hpp"

/**
 * @brief Initialize the server, bind to port, and start receiving messages.
 */
/* RTypeServer::RTypeServer(boost::asio::io_context& io_context, short port)
    : io_context_(io_context),
    socket_(io_context, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), port))
{
    start_receiving();
} */

/**
 * @brief Asynchronously start listening for incoming messages. AND
 */
/* void RTypeServer::start_receiving() {
    socket_.async_receive_from(
        boost::asio::buffer(data_, max_length), remote_endpoint_,
        [this](const boost::system::error_code& ec, std::size_t bytes_transferred) {
            if (!ec) {
                handle_receive(ec, bytes_transferred);
                start_receiving();  // Continue listening
            } else {
                ///> Error during data reception
                std::cout << "Erreur lors de la réception des données: " << ec.message() << std::endl;
                
                if (ec == boost::asio::error::connection_reset ||
                    ec == boost::asio::error::broken_pipe) {
                    std::cout << "Le client " << remote_endpoint_ << " semble s'être déconnecté ou a crashé." << std::endl;
                }
                
                // Possible client removal logic here
                // ...
                
                // Optionally continue listening
                start_receiving();
            }
        });
}
 */
/**
 * @brief Process received data and manage known clients.
 */

/* void RTypeServer::handle_receive(const boost::system::error_code& error, std::size_t )//bytes_transferred
{
    if (!error)
    {
        // Check for known client
        auto it = std::find_if(knownClients.begin(), knownClients.end(),
            [this](const ClientInfo& info) {
                return info.endpoint == remote_endpoint_;
            });

        // If client is new, add to known clients and assign an ID
        if (it == knownClients.end()) {
            knownClients.push_back({remote_endpoint_, clientIdCounter});
            std::cout << "Client " << clientIdCounter << " connected." << std::endl;
            ++clientIdCounter;
        }
        
        // Check if all expected clients are connected
        if (clientIdCounter == 4) {
            std::cout << "All clients connected." << std::endl;
        }
        struct data d = readData();
        // Continue receiving
        start_receiving();
    }
}

struct data RTypeServer::readData()
{
    struct data d = {-1, -1, -1};

    // istream_.read(reinterpret_cast<char*>(&d.id), sizeof(int));
    // istream_.read(reinterpret_cast<char*>(&d.event), sizeof(int));
    // istream_.read(reinterpret_cast<char*>(&d.dir), sizeof(int));
    // std::cout << "id: " << d.id << std::endl;
    // std::cout << "event: " << d.event << std::endl;
    // std::cout << "dir: " << d.dir << std::endl;
    auto buff = CStreamBuffer_.getCStreamBuffer().prepare(1024);
    CStreamBuffer_.readData();
    socket_.async_receive_from(buff, remote_endpoint_,
		std::bind(&RTypeServer::routine, this, std::placeholders::_1, std::placeholders::_2));
    return d;
}

void RTypeServer::routine(const boost::system::error_code &, std::size_t btrs)
{}
 */