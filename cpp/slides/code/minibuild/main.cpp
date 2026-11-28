#include "target.h"

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<Target> targets;
    targets.emplace_back(1, "main.o", 2);
    targets.emplace_back(2, "util.o", 4);
    targets.emplace_back(3, "app", 5);

    targets[1].build();

    std::sort(targets.begin(), targets.end(),
              [](const Target& a, const Target& b) {
                  return a.priority() > b.priority();
              });

    for (const Target& t : targets) {
        std::cout << t << "\n";
    }

    std::cout << "live targets: " << Target::count() << "\n";
    return 0;
}
