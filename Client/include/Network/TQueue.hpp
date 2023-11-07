/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** TQueue.hpp
*/

#pragma once
    #include <queue>
    #include <mutex>
    #include <condition_variable>
    #include "Message.hpp"

namespace network {
    class TQueue {
        public:
            TQueue() = default;
            virtual ~TQueue() {clear();};
            TQueue(const TQueue &) = delete;

            message &front();
            void push_back(const message &msg);
            size_t size();
            bool empty();
            void clear();
            message pop_front();
            message pop_back();
        private:
            std::mutex _mutex;
            std::deque<message> _queue;
    };
}