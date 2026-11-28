#include "task.h"

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<Task> tasks;
    tasks.emplace_back(1, "写作业", 2);
    tasks.emplace_back(2, "复习", 4);
    tasks.emplace_back(3, "锻炼", 5);

    tasks[0].postpone();
    tasks[1].complete();

    std::sort(tasks.begin(), tasks.end(),
              [](const Task& a, const Task& b) {
                  return a.priority() > b.priority();
              });

    for (const Task& t : tasks) {
        std::cout << t << "\n";
    }

    std::cout << "live tasks: " << Task::count() << "\n";
    return 0;
}
