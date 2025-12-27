#include <iostream>
#include <thread>
#include <cstdlib>
#include "CPUExecutor.h"
#include "GPUExecutor.h"

int main() {
    SchedulerQueue schedulerQueue;

    int cpuCores = std::thread::hardware_concurrency();
    CPUExecutor cpu(cpuCores, schedulerQueue);
    GPUExecutor gpu(schedulerQueue);

    for (int i = 0; i < 15; i++) {
        Task task;
        task.id = i;
        task.estimated_cost = rand() % 100 + 10;

        if (task.estimated_cost > 60) {
            task.type = TaskType::GPU_BOUND;
            task.work = []() {};
        } else {
            task.type = TaskType::CPU_BOUND;
            task.work = []() {
                volatile double x = 0;
                for (int i = 0; i < 1e6; i++) x += i;
            };
        }

        schedulerQueue.push(task);
    }

    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "Scheduler shutdown\n";
    return 0;
}
