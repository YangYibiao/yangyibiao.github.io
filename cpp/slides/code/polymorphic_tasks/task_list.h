#pragma once

#include "task.h"

#include <cstddef>
#include <memory>
#include <vector>

// TaskList 独占拥有任务；外部只能通过指针借用。
class TaskList {
public:
    void add(std::unique_ptr<Task> task);
    void run_all() const;
    std::vector<const Task*> sorted_by_priority() const;
    std::size_t size() const;

private:
    std::vector<std::unique_ptr<Task>> tasks_;
};
