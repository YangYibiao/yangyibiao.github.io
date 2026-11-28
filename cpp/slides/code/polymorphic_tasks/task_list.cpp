#include "task_list.h"

#include <algorithm>
#include <utility>

void TaskList::add(std::unique_ptr<Task> task) {
    tasks_.push_back(std::move(task));
}

void TaskList::run_all() const {
    for (const auto& task : tasks_) {
        task->run();
    }
}

std::vector<const Task*> TaskList::sorted_by_priority() const {
    std::vector<const Task*> result;
    result.reserve(tasks_.size());
    for (const auto& task : tasks_) {
        result.push_back(task.get());
    }
    std::sort(result.begin(), result.end(),
              [](const Task* a, const Task* b) {
                  return a->priority() > b->priority();
              });
    return result;
}

std::size_t TaskList::size() const {
    return tasks_.size();
}
