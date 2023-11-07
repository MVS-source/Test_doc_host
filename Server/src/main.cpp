#include "RTypeServer.hpp"
#include <iostream>
#include "../../GameEngine/src/Timers/test.cpp"

/// @brief The port used for UDP communication.
const int UDP_PORT = 12345;

/// @brief Main Server
int main()
{
    test(); ///< for the Cmake
    /* try
    {
        boost::asio::io_context io_context; ///< context
        RTypeServer server(io_context, 4091); ///< Initialize RTypeServer
        io_context.run(); ///< Run context loop
    }
    catch (std::exception& e) ///< Handle exceptions
    {
        std::cerr << "Exception: " << e.what() << "\n";
    } */
    return 0; ///< Exit the program.
}
