#pragma once
#include <functional>

enum class TaskType {
    CPU_BOUND,
    GPU_BOUND
};

struct Task {
    int id;
    TaskType type;
    int estimated_cost;      // Used for scheduling
    std::function<void()> work;
};
