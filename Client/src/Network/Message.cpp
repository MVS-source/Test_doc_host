/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Message.cpp
*/

#include "Message.hpp"

namespace network {

    size_t message::size() const
    {
        return (sizeof(m_header) + body.size());
    }

    std::ostream &operator<<(std::ostream &os, const message &msg)
    {
        os << "id: " << static_cast<int>(msg.header.id) << " size: " << msg.header.size;
        return (os);
    }

    std::ostream &operator<<(std::ostream &os, const connect_message &msg)
    {
        os << msg.msg;
        return (os);
    }
}

/*size_t network::message::size() const
{
    return sizeof(header) + body.size();
}

std::ostream &network::operator<<(std::ostream &os, const network::message &msg)
{
    os << "id: " << static_cast<int>(msg.header.id) << " size: " << msg.header.size;
    return os;
}

template<typename DataType>
network::message &network::operator<<(network::message &msg, const DataType &data)
{
    static_assert(std::is_standard_layout<DataType>::value, "Data is too complex");
    size_t size = msg.body.size();
    msg.body.resize(size + sizeof(DataType));
    std::memcpy(msg.body.data() + size, &data, sizeof(DataType));
    msg.header.size = msg.size();
    return msg;
}

template<typename DataType>
network::message &network::operator>>(network::message &msg, DataType &data)
{
    static_assert(std::is_standard_layout<DataType>::value, "Data is too complex");
    size_t size = msg.body.size() - sizeof(DataType);
    msg.body.resize(size + sizeof(DataType));
    std::memcpy(&data, msg.body.data() + size, sizeof(DataType));
    msg.header.size = msg.size();
    return msg;
}*/