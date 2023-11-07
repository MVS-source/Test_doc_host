/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Queue.hpp
*/

#pragma once
    #include <vector>
    #include <string>
    #include <queue>
    #include <mutex>
    #include <optional>

struct Data {
    std::string _cmd;
    std::vector<int> _args;
};

class CmdQueue {
    public:
    std::queue<Data> q;
    std::mutex mtx;
public:
    void push(Data m) {
        std::lock_guard<std::mutex> lock(mtx);
        q.push(m);
    }
    std::optional<Data> pop() {
        std::lock_guard<std::mutex> lock(mtx);
        if(q.empty())
            return std::nullopt;
        Data m = q.front();
        q.pop();
        return m;
    }
};