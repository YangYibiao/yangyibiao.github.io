#pragma once

#include <string>

// 抽象接口：高层代码只依赖 Task，不依赖具体任务类型。
class Task {
public:
    virtual ~Task() = default;

    virtual void run() const = 0;
    virtual std::string describe() const = 0;
    virtual int id() const = 0;
    virtual int priority() const = 0;
};

class PrintTask : public Task {
public:
    PrintTask(int id, std::string text);
    void run() const override;
    std::string describe() const override;
    int id() const override;
    int priority() const override;

private:
    int id_;
    std::string text_;
};

class RecurringTask : public Task {
public:
    RecurringTask(int id, std::string title, int interval_days);
    void run() const override;
    std::string describe() const override;
    int id() const override;
    int priority() const override;

private:
    int id_;
    std::string title_;
    int interval_days_;
};
