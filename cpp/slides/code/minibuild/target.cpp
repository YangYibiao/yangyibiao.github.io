#include "target.h"

#include <iostream>
#include <utility>

int Target::count_ = 0;

Target::Target(int id, std::string name, int priority)
    : id_(id), name_(std::move(name)), priority_(priority) {
    ++count_;
}

Target::~Target() {
    --count_;
}

Target::Target(const Target& other)
    : id_(other.id_),
      name_(other.name_),
      priority_(other.priority_),
      built_(other.built_) {
    ++count_;
}

Target& Target::operator=(const Target& other) {
    if (this != &other) {
        id_ = other.id_;
        name_ = other.name_;
        priority_ = other.priority_;
        built_ = other.built_;
    }
    return *this;
}

void Target::build() {
    built_ = true;
}

bool Target::is_built() const {
    return built_;
}

int Target::id() const {
    return id_;
}

int Target::priority() const {
    return priority_;
}

const std::string& Target::name() const {
    return name_;
}

void Target::print() const {
    std::cout << "[" << id_ << "] " << name_ << " p=" << priority_ << " "
              << (built_ ? "built" : "todo") << "\n";
}

int Target::count() {
    return count_;
}

std::ostream& operator<<(std::ostream& os, const Target& t) {
    return os << "[" << t.id_ << "] " << t.name_ << " p=" << t.priority_
              << " " << (t.built_ ? "built" : "todo");
}
