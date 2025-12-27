#pragma once
#include "SchedulerQueue.h"
#include <vector>
#include <thread>
#include <atomic>

class CPUExecutor {
public:
    CPUExecutor(int cores, SchedulerQueue& queue);
    ~CPUExecutor();

private:
    void worker(int id);

    std::vector<std::thread> workers;
    SchedulerQueue& schedulerQueue;
    std::atomic<bool> running;
};
