#pragma once

#include <iosfwd>
#include <string>

// 值与所有权示例：Task 自己管理 std::string，不需要手写析构。
// 这里的静态计数器用于演示 static 成员；拷贝构造也必须计数。
class Task {
public:
    Task(int id, std::string title, int priority);
    ~Task();

    Task(const Task& other);
    Task& operator=(const Task& other);

    void complete();
    void postpone();
    bool is_done() const;
    bool is_high_priority() const;

    int id() const;
    int priority() const;
    const std::string& title() const;

    void print() const;

    static int count();

    friend std::ostream& operator<<(std::ostream& os, const Task& t);

private:
    int id_;
    std::string title_;
    int priority_;
    bool done_ = false;
    static int count_;
};
