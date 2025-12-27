#include "CPUExecutor.h"
#include <iostream>

CPUExecutor::CPUExecutor(int cores, SchedulerQueue& queue)
    : schedulerQueue(queue), running(true) {
    std::cout << "[CPU] Starting " << cores << " worker threads\n";
    for (int i = 0; i < cores; i++) {
        workers.emplace_back(&CPUExecutor::worker, this, i);
    }
}

void CPUExecutor::worker(int id) {
    while (running) {
        Task task = schedulerQueue.pop();
        if (task.type != TaskType::CPU_BOUND)
            continue;

        std::cout << "[CPU Worker " << id << "] Task "<< task.id << " Cost=" << task.estimated_cost << "\n";

        task.work();
    }
}

CPUExecutor::~CPUExecutor() {
    running = false;
    for (auto& t : workers) if (t.joinable()) t.join();
}
