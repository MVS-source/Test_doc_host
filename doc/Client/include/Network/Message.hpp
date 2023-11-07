/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Message.hpp
*/

#pragma once
    #include <iostream>
    #include <string>
    #include <vector>
    #include <cstring>
    #include <memory>

namespace network {
    class Connection;

    enum class request : u_int32_t {
        HI,
        MOOVE,
        SHOOTING
    };

    struct m_header {
        request id{};
        u_int32_t size = 0;
    };

    struct message {
        m_header header{};
        std::vector<u_int8_t> body{};

        size_t size() const;
        friend std::ostream &operator<<(std::ostream &os, const message &msg);
        template<typename DataType>
        friend message &operator<<(message &msg, const DataType &data) {
            static_assert(std::is_standard_layout<DataType>::value, "Data is too complex");
            size_t size = msg.body.size();
            msg.body.resize(size + sizeof(DataType));
            std::memcpy(msg.body.data() + size, &data, sizeof(DataType));
            msg.header.size = msg.size();
            return (msg);
        }
        template<typename DataType>
        friend message &operator>>(message &msg, DataType &data) {
            static_assert(std::is_standard_layout<DataType>::value, "Data is too complex");
            size_t size = msg.body.size() - sizeof(DataType);
            std::memcpy(&data, msg.body.data() + size, sizeof(DataType));
            msg.body.resize(size);
            msg.header.size = msg.size();
            return (msg);
        }
    };

    struct connect_message {
        std::shared_ptr<Connection> connection = nullptr;
        message msg{};

        friend std::ostream &operator<<(std::ostream &os, const connect_message &msg);
    };
}