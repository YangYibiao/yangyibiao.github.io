#undef NDEBUG
#include <cassert>
#include <iostream>
#include <string>

#include "queue.hpp"

namespace {

void test_p2() {
    Queue q;
    int out = 777;

    // 1. Initial empty queue boundary: pop / front returns false and does not
    // modify out
    assert(q.empty() && !q.full() && q.size() == 0);
    assert(!q.pop(out) && out == 777);
    assert(!q.front(out) && out == 777);

    // 2. Basic FIFO (First In First Out) order and front read-only semantics
    assert(q.push(10) && q.push(20) && q.push(30));
    assert(q.size() == 3);
    assert(q.front(out) && out == 10 && q.size() == 3);
    assert(q.pop(out) && out == 10);
    assert(q.pop(out) && out == 20);
    assert(q.pop(out) && out == 30);
    assert(q.empty() && !q.pop(out));

    // 3. Capacity upper limit boundary: refuse to continue enqueuing after
    // filling CAPACITY elements, and do not overwrite existing queue head
    for (int i = 0; i < Queue::CAPACITY; ++i) {
        assert(q.push(i * 10));
    }
    assert(q.full() && q.size() == Queue::CAPACITY);
    assert(!q.push(999));
    assert(q.front(out) && out == 0);

    // 4. Index circular wrap-around: dequeue 5 elements first, then enqueue 5
    // elements crossing the array end
    for (int i = 0; i < 5; ++i) {
        assert(q.pop(out) && out == i * 10);
    }
    for (int i = 0; i < 5; ++i) {
        assert(q.push(100 + i));
    }
    assert(q.full());

    const int expected[Queue::CAPACITY] = {50, 60, 70, 100, 101, 102, 103, 104};
    for (int exp : expected) {
        assert(q.pop(out) && out == exp);
    }
    assert(q.empty());

    // 5. Multiple object state isolation: each instance maintains its own
    // private data
    Queue q1, q2;
    assert(q1.push(1) && q2.push(2));
    assert(q1.pop(out) && out == 1);
    assert(q2.front(out) && out == 2);

    std::cout << "[PASS] p2_queue passed all boundary checks.\n";
}

void test_p4() {
    Queue q;
    assert(!q.try_pop().has_value());

    // Store -1 and 0, verify that there is no value domain conflict with the
    // empty queue state
    assert(q.push(-1) && q.push(0) && q.push(42));

    auto v1 = q.try_pop();
    assert(v1.has_value() && *v1 == -1);

    if (auto v2 = q.try_pop()) {
        assert(*v2 == 0);
    } else {
        assert(false);
    }

    auto v3 = q.try_pop();
    assert(v3.has_value() && v3.value() == 42);
    assert(!q.try_pop().has_value());

    std::cout << "[PASS] p4_optional passed all boundary checks.\n";
}

} // namespace

int main(int argc, char *argv[]) {
    std::string mode = (argc >= 2) ? argv[1] : "all";
    if (mode == "p2") {
        test_p2();
    } else if (mode == "p4") {
        test_p4();
    } else {
        test_p2();
        test_p4();
    }
    return 0;
}
