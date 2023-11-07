/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** ICStreamBuffer.cpp
*/

#include "CStreamBuffer.hpp"

CStreamBuffer::CStreamBuffer()
    : _istream(&_streambuf), _ostream(&_streambuf)
{}

void CStreamBuffer::writen(int n)
{
    _ostream.write(reinterpret_cast<const char *>(&n), sizeof(int));
}

boost::asio::streambuf &CStreamBuffer::getCStreamBuffer()
{
    return _streambuf;
}

void CStreamBuffer::writeData(struct data &d)
{
    writen(d.id);
    writen(d.event);
    writen(d.dir);
}

struct data CStreamBuffer::readData()
{
    struct data d = {-1, -1, -1};

    _istream.read(reinterpret_cast<char *>(&d.id), sizeof(int));
    _istream.read(reinterpret_cast<char *>(&d.event), sizeof(int));
    _istream.read(reinterpret_cast<char *>(&d.dir), sizeof(int));
    return (d);
}