#include "task_list.h"

#include <iostream>
#include <memory>

int main() {
    TaskList list;
    list.add(std::make_unique<PrintTask>(1, "write report"));
    list.add(std::make_unique<RecurringTask>(2, "review notes", 3));
    list.add(std::make_unique<PrintTask>(3, "submit assignment"));

    for (const Task* task : list.sorted_by_priority()) {
        std::cout << task->describe() << "\n";
    }

    list.run_all();
    std::cout << "total tasks: " << list.size() << "\n";
    return 0;
}
