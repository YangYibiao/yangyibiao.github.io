#include "queue.hpp"

Queue::Queue() : data_{}, head_(0), tail_(0), count_(0) {}

bool Queue::empty() const {
    return count_ == 0;
}

bool Queue::full() const {
    return count_ == CAPACITY;
}

int Queue::size() const {
    return count_;
}

bool Queue::push(int x) {
    // TODO: Problem 2
    return false;
}

bool Queue::pop(int &out) {
    // TODO: Problem 2
    return false;
}

bool Queue::front(int &out) const {
    // TODO: Problem 2
    return false;
}

std::optional<int> Queue::try_pop() {
    // TODO: Problem 4
    return std::nullopt;
}
