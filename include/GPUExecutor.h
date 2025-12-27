#pragma once
#include "SchedulerQueue.h"
#include <thread>
#include <atomic>

class GPUExecutor {
public:
    GPUExecutor(SchedulerQueue& queue);
    ~GPUExecutor();

private:
    void gpuWorker();

    SchedulerQueue& schedulerQueue;
    std::thread gpuThread;
    std::atomic<bool> running;
};
