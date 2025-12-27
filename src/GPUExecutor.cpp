#include "GPUExecutor.h"
#include <iostream>
#include <chrono>

GPUExecutor::GPUExecutor(SchedulerQueue& queue)
    : schedulerQueue(queue), running(true) {
    std::cout << "[GPU] Initializing simulated GPU executor\n";
    gpuThread = std::thread(&GPUExecutor::gpuWorker, this);
}

void GPUExecutor::gpuWorker() {
    while (running) {
        Task task = schedulerQueue.pop();
        if (task.type != TaskType::GPU_BOUND) continue;

        std::cout << "[GPU] Executing Task "<< task.id << " Cost=" << task.estimated_cost << "\n";

        // Simulated GPU execution
        std::this_thread::sleep_for(std::chrono::milliseconds(task.estimated_cost * 5));
    }
}

GPUExecutor::~GPUExecutor() {
    running = false;
    if (gpuThread.joinable())
        gpuThread.join();
}
