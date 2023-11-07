/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** CStreamBuffer.hpp
*/


#pragma once
    #include <boost/asio.hpp>

/**
 * @struct data
 * @brief Data structure used for communication.
 */
struct data {
    int id;
    int event;
    int dir;
};

/**
 * @class CStreamBuffer
 * @brief Class to manage data streams.
 */
class CStreamBuffer {
    public:

        /**
         * @brief constructor
         */
        CStreamBuffer();

        /**
         * @brief Virtual destructor
         */
        virtual ~CStreamBuffer() = default;

        /**
         * @brief Write an integer to the data stream.
         * @param n int
         */
        void writen(int n);

        /**
         * @brief Get the custom stream buffer.
         */
        boost::asio::streambuf &getCStreamBuffer();

        /**
         * @brief Write data structure to the stream.
         * @param d The data structure to write.
         */
        void writeData(struct data &d);

        /**
         * @brief Read data structure from the stream.
         */
        struct data readData();

    private:
        boost::asio::streambuf _streambuf;
        std::istream _istream;
        std::ostream _ostream;
};