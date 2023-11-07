/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** TQueue.cpp
*/

#include "TQueue.hpp"

namespace network {
        message &TQueue::front()
        {
            std::scoped_lock<std::mutex> lock(_mutex);
            return _queue.front();
        }

        void TQueue::push_back(const message &msg)
        {
            std::scoped_lock<std::mutex> lock(_mutex);
            _queue.emplace_back(std::move(msg));
        }

        size_t TQueue::size()
        {
            std::scoped_lock lock(_mutex);
            return _queue.size();
        }
    
        bool TQueue::empty()
        {
            std::scoped_lock lock(_mutex);
            return _queue.empty();
        }

        void TQueue::clear()
        {
            std::scoped_lock<std::mutex> lock(_mutex);
            _queue.clear();
        }

        message TQueue::pop_front()
        {
            std::scoped_lock lock(_mutex);
            auto msg = std::move(_queue.front());
            _queue.pop_front();
            return msg;
        }

        message TQueue::pop_back()
        {
            std::scoped_lock lock(_mutex);
            auto msg = std::move(_queue.back());
            _queue.pop_back();
            return msg;
        }
}