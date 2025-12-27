#pragma once
#include "Task.h"
#include <queue>
#include <mutex>
#include <condition_variable>

class SchedulerQueue {
public:
    void push(const Task& task);
    Task pop();

private:
    struct TaskCompare {
        bool operator()(const Task& a, const Task& b) {
            return a.estimated_cost > b.estimated_cost;
        }
    };

    std::priority_queue<Task, std::vector<Task>, TaskCompare> queue;
    std::mutex mtx;
    std::condition_variable cv;
};
