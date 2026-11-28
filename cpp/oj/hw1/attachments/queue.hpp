#pragma once

#include <optional>

class Queue {
  public:
    static constexpr int CAPACITY = 8;

  private:
    int data_[CAPACITY];
    int head_;
    int tail_;
    int count_;

  public:
    Queue();

    bool empty() const;
    bool full() const;
    int size() const;

    // Problem 2
    bool push(int x);
    bool pop(int &out);
    bool front(int &out) const;

    // Problem 4
    std::optional<int> try_pop();
};
