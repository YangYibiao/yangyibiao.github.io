#pragma once

#include <iosfwd>
#include <string>

// MiniBuild 起始版：一个可构建的目标。
// 第 2-6 周会在这个类上加入依赖、命令、状态和模块拆分。
class Target {
public:
    Target(int id, std::string name, int priority);
    ~Target();

    Target(const Target& other);
    Target& operator=(const Target& other);

    void build();
    bool is_built() const;
    int id() const;
    int priority() const;
    const std::string& name() const;

    void print() const;

    static int count();

    friend std::ostream& operator<<(std::ostream& os, const Target& t);

private:
    int id_;
    std::string name_;
    int priority_;
    bool built_ = false;
    static int count_;
};
