#include "SchedulerQueue.h"

void SchedulerQueue::push(const Task& task) {
    {
        std::lock_guard<std::mutex> lock(mtx);
        queue.push(task);
    }
    cv.notify_one();
}

Task SchedulerQueue::pop() {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [&]() { return !queue.empty(); });

    Task task = queue.top();
    queue.pop();
    return task;
}
