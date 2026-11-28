#include "task.h"

#include <iostream>
#include <utility>

PrintTask::PrintTask(int id, std::string text)
    : id_(id), text_(std::move(text)) {}

void PrintTask::run() const {
    std::cout << text_ << "\n";
}

std::string PrintTask::describe() const {
    return "print: " + text_;
}

int PrintTask::id() const {
    return id_;
}

int PrintTask::priority() const {
    return 1;
}

RecurringTask::RecurringTask(int id, std::string title, int interval_days)
    : id_(id), title_(std::move(title)), interval_days_(interval_days) {}

void RecurringTask::run() const {
    std::cout << "run " << title_ << "\n";
}

std::string RecurringTask::describe() const {
    return "recurring every " + std::to_string(interval_days_) + " days";
}

int RecurringTask::id() const {
    return id_;
}

int RecurringTask::priority() const {
    return 3;
}
