#include "task.h"

#include <iostream>
#include <utility>

int Task::count_ = 0;

Task::Task(int id, std::string title, int priority)
    : id_(id), title_(std::move(title)), priority_(priority) {
    ++count_;
}

Task::~Task() {
    --count_;
}

Task::Task(const Task& other)
    : id_(other.id_),
      title_(other.title_),
      priority_(other.priority_),
      done_(other.done_) {
    ++count_;
}

Task& Task::operator=(const Task& other) {
    if (this != &other) {
        id_ = other.id_;
        title_ = other.title_;
        priority_ = other.priority_;
        done_ = other.done_;
    }
    return *this;
}

void Task::complete() {
    done_ = true;
}

void Task::postpone() {
    if (priority_ < 5) {
        ++priority_;
    }
}

bool Task::is_done() const {
    return done_;
}

bool Task::is_high_priority() const {
    return priority_ >= 4;
}

int Task::id() const {
    return id_;
}

int Task::priority() const {
    return priority_;
}

const std::string& Task::title() const {
    return title_;
}

void Task::print() const {
    std::cout << "[" << id_ << "] " << title_ << " p=" << priority_ << " "
              << (done_ ? "done" : "todo") << "\n";
}

int Task::count() {
    return count_;
}

std::ostream& operator<<(std::ostream& os, const Task& t) {
    return os << "[" << t.id_ << "] " << t.title_ << " p=" << t.priority_
              << " " << (t.done_ ? "done" : "todo");
}
