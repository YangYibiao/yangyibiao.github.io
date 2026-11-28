---
presentation:
  width: 1280
  height: 720
  margin: 0
  center: false
  transition: "convex"
  enableSpeakerNotes: true
  slideNumber: "c/t"
  navigationMode: "linear"
---

@import "../../css/font-awesome-4.7.0/css/font-awesome.css"
@import "../../css/theme/solarized.css"
@import "../../css/logo.css"
@import "../../css/font.css"
@import "../../css/color.css"
@import "../../css/margin.css"
@import "../../css/table.css"
@import "../../css/main.css"
@import "../css/cpp.css"
@import "../../plugin/zoom/zoom.js"
@import "../../plugin/customcontrols/plugin.js"
@import "../../plugin/customcontrols/style.css"
@import "../../plugin/chalkboard/plugin.js"
@import "../../plugin/chalkboard/style.css"
@import "../../plugin/menu/menu.js"


<!-- slide data-notes="" -->

<div class="bottom20"></div>

# 高级程序设计（C++）

<hr class="width50 center">

## const、static、友元与类作为模块

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](mailto:yangyibiao@nju.edu.cn)


<!-- slide data-notes="" -->

##### 本讲提纲

---

<div class="cols">

<div class="col">

**类内的约束**

- `const` 成员函数与常量对象
- `mutable` 与逻辑常量性
- `static` 数据成员与成员函数

</div>

<div class="col">

**类外的协作**

- 友元函数、友元类
- 类作为模块：`.h` 与 `.cpp`
- 前置声明、命名空间、ODR

</div>

</div>

<div class="keypoint">
<span class="label">本讲目标</span>
能够为一个类建立“只读接口 + 类级状态 + 模块边界”，并解释头文件为什么这样写。
</div>

---


<!-- slide data-notes="" -->

##### `const` 成员函数：接口的只读承诺

---

<div class="cols">

<div class="col-55">

```cpp
class Task {
public:
    bool is_done() const { return done_; }
    int priority() const { return priority_; }

    void complete() { done_ = true; }
private:
    int priority_ = 0;
    bool done_ = false;
};
```

```cpp
void print(const Task& t) {
    t.is_done();      // OK
    t.complete();     // 编译错误
}
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">两个作用</div>

1. 编译器禁止在函数内修改数据成员
2. 常量对象/常量引用只能调用 `const` 成员函数

</div>

<div class="tip">
<span class="label">习惯</span>
凡是“查询”而非“修改”的成员函数，一律加 <code>const</code>。这是接口契约的一部分。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### `const` 只约束“成员本身”

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
class A {
public:
    void f() const {
        x_ = 10;              // 错误：修改 int 成员
        p_ = new char[20];    // 错误：修改指针本身
        std::strcpy(p_, "AB"); // 编译通过！
    }
private:
    int x_ = 0;
    char* p_ = nullptr;
};
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">为什么第三行能通过</div>

`const` 成员函数保证：

- 不修改对象的**直接成员**
- 不改变指针的**指向**

但它不保证“指针指向的内容”不变。这是 `const` 的浅层语义。

</div>

<div class="pitfall">
<span class="label">设计建议</span>
如果成员是指针，且逻辑上不应修改其指向内容，应在接口层避免暴露可写路径；必要时用 <code>const char*</code> 或封装成只读视图。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 常量成员函数的重载

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
class TaskList {
public:
    Task& at(int i) {
        return tasks_[i];
    }

    const Task& at(int i) const {
        return tasks_[i];
    }
private:
    std::vector<Task> tasks_;
};
```

```cpp
TaskList list;
list.at(0).complete();       // 非 const 版本

const TaskList& clist = list;
clist.at(0).complete();      // 错误：const 版本
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">选择规则</div>

- 非 const 对象优先调用非 const 版本
- const 对象只能调用 const 版本
- 两个版本通常返回引用，避免拷贝

</div>

<div class="small muted mt1">
标准库容器也采用这种设计：<code>begin()</code> / <code>cbegin()</code>、<code>operator[]</code> 的 const 重载。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### `mutable`：逻辑常量性

---

<div class="cols">

<div class="col-55">

```cpp
class Task {
public:
    bool is_done() const {
        ++query_count_;       // 允许修改 mutable
        return done_;
    }
    int query_count() const { return query_count_; }
private:
    bool done_ = false;
    mutable int query_count_ = 0;
};
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">适用场景</div>

- 缓存计算结果
- 统计查询次数
- 互斥量（`mutable std::mutex`）

</div>

<div class="pitfall">
<span class="label">边界</span>
<code>mutable</code> 表达“逻辑上不改变对象”，不是“绕过 <code>const</code> 检查”。把业务字段设为 <code>mutable</code> 会破坏接口承诺。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### `static` 数据成员：属于类，不属于对象

---

<div class="cols">

<div class="col-55">

```cpp
class Task {
public:
    Task() { ++count_; }
    Task(const Task&) { ++count_; }
    ~Task() { --count_; }

    static int count() { return count_; }
private:
    static int count_;   // 声明
};

int Task::count_ = 0;    // 定义（C++17 之前）
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">要点</div>

- 所有对象共享同一份 `count_`
- 必须在类外定义并初始化（C++17 之前）
- 生命周期从程序开始到结束
- 可通过 `Task::count()` 访问，不需要对象

</div>

<div class="tip">
<span class="label">C++17</span>
可以写 <code>inline static int count_ = 0;</code>，直接在类内定义，不需要类外定义。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 静态成员函数：没有 `this`

---

<div class="cols">

<div class="col-55">

```cpp
class Task {
public:
    static int count() {
        return count_;
        // return id_;   // 错误：没有 this
    }
private:
    int id_ = 0;
    static int count_;
};
```

```cpp
int n = Task::count();   // 不需要对象
Task t;
int m = t.count();       // 也可以通过对象调用
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">能做什么</div>

- 访问静态数据成员
- 调用其他静态成员函数
- 作为类级工具函数

</div>

<div class="card mt1">

<div class="card-title">不能做什么</div>

- 访问非静态数据成员
- 使用 `this`
- 声明为 `const`（没有对象可 const）

</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 友元：有控制的“例外通道”

---

<div class="cols">

<div class="col-55">

```cpp
class Task {
    friend std::ostream& operator<<(std::ostream& os,
                                    const Task& t);
    friend class TaskList;
    friend void Scheduler::dispatch(const Task&);

private:
    int id_;
    std::string title_;
};
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">三种友元</div>

1. 全局函数
2. 另一个类（其所有成员函数）
3. 另一个类的某个成员函数

</div>

<div class="keypoint">
<span class="label">定位</span>
友元是<strong>封装与效率之间的折中</strong>：不是成员，但被授权访问非 public 成员。应尽量少用，优先通过 public 接口完成。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 友元的两个性质

---

<div class="cols">

<div class="col">

**不对称**

```cpp
class A {
    friend class B;   // B 可以访问 A
};

class B {
    // 没有 friend class A;
};
```

`B` 是 `A` 的友元，不代表 `A` 是 `B` 的友元。

</div>

<div class="col">

**不传递**

```cpp
class A {
    friend class B;
};
class B {
    friend class C;
};
```

`C` 不是 `A` 的友元；友元关系不会沿链传播。

</div>

</div>

<div class="keypoint mt1">
<span class="label">记住</span>
友元关系是<strong>单向、非传递</strong>的授权，必须显式声明。它也不是“类的成员”，不受继承影响。
</div>

---


<!-- slide data-notes="" -->

##### 典型用法：重载 `<<`

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
class Task {
public:
    Task(int id, std::string title)
        : id_(id), title_(std::move(title)) {}

    friend std::ostream& operator<<(std::ostream& os,
                                    const Task& t);
private:
    int id_;
    std::string title_;
};

std::ostream& operator<<(std::ostream& os, const Task& t) {
    return os << "[" << t.id_ << "] " << t.title_;
}
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">为什么用友元</div>

- `<<` 的左操作数是 `std::ostream`，不能写成成员函数
- 需要访问 `Task` 的私有数据
- 返回 `ostream&` 支持链式输出

</div>

<div class="small muted mt1">
也可以提供 public 的 <code>print(os)</code> 成员函数，让 <code>operator&lt;&lt;</code> 调用它，从而避免友元。两种设计都常见。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 类作为模块：接口与实现

---

<div class="cols">

<div class="col">

<div class="card">

<div class="card-title">模块</div>

从物理上对程序实体分组，可独立编写、编译、测试。

- 接口：供其他模块使用的声明
- 实现：具体的定义与算法

</div>

<div class="card mt1">

<div class="card-title">C++ 的类模块</div>

- `Task.h`：类定义、函数声明、常量
- `Task.cpp`：成员函数定义、静态成员定义
- `main.cpp`：`#include "Task.h"`

</div>

</div>

<div class="col">

<div class="fig">
<svg viewBox="0 0 420 220" width="400">
  <rect x="20" y="20" width="150" height="70" rx="8" fill="#fdf6e3" stroke="#268bd2"/>
  <text x="95" y="48" font-size="15" text-anchor="middle" fill="#268bd2">Task.h</text>
  <text x="95" y="68" font-size="12" text-anchor="middle" fill="#657b83">接口：声明</text>
  <rect x="250" y="20" width="150" height="70" rx="8" fill="#fdf6e3" stroke="#859900"/>
  <text x="325" y="48" font-size="15" text-anchor="middle" fill="#859900">Task.cpp</text>
  <text x="325" y="68" font-size="12" text-anchor="middle" fill="#657b83">实现：定义</text>
  <rect x="135" y="140" width="150" height="60" rx="8" fill="#fdf6e3" stroke="#b58900"/>
  <text x="210" y="168" font-size="15" text-anchor="middle" fill="#b58900">main.cpp</text>
  <text x="210" y="186" font-size="12" text-anchor="middle" fill="#657b83">使用接口</text>
  <line x1="170" y1="90" x2="170" y2="140" stroke="#93a1a1" marker-end="url(#a)"/>
  <line x1="250" y1="55" x2="170" y2="55" stroke="#93a1a1" stroke-dasharray="4 3"/>
  <text x="210" y="48" font-size="11" text-anchor="middle" fill="#93a1a1">#include</text>
  <defs><marker id="a" markerWidth="8" markerHeight="8" refX="4" refY="4" orient="auto"><path d="M0,0 L8,4 L0,8 z" fill="#93a1a1"/></marker></defs>
</svg>
</div>

<div class="small muted center">
修改实现不需要重新编译 `main.cpp`（只重新链接），前提是接口不变。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 头文件保护与 `#pragma once`

---

<div class="cols">

<div class="col">

**传统写法：include guard**

```cpp
#ifndef TASK_H
#define TASK_H

class Task {
    // ...
};

#endif
```

- 第一次包含时定义宏
- 再次包含时整段被跳过

</div>

<div class="col">

**现代写法：`#pragma once`**

```cpp
#pragma once

class Task {
    // ...
};
```

- 编译器保证同一文件只包含一次
- 几乎所有主流编译器都支持
- 不是 ISO 标准，但事实标准

</div>

</div>

<div class="pitfall">
<span class="label">注意</span>
头文件保护解决的是“同一翻译单元重复包含”，不是“多个源文件各包含一次”。后者是正常的，声明可以重复，定义不行。
</div>

---


<!-- slide data-notes="" -->

##### 前置声明：减少依赖，打破循环

---

<div class="cols">

<div class="col-55">

```cpp
// Teacher.h
#pragma once

class Student;   // 前向声明：只知道“有这样一个类”

class Teacher {
public:
    void set_student(Student* s) { student_ = s; }
private:
    Student* student_;   // 指针：不需要完整定义
};
```

```cpp
// Teacher.cpp
#include "Teacher.h"
#include "Student.h"   // 真正使用 Student 的成员时才包含
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">能用前置声明的场景</div>

- 成员是指针或引用
- 函数参数/返回值是指针或引用
- 不需要知道对象大小和成员

</div>

<div class="card mt1">

<div class="card-title">不能用</div>

- 成员是对象本身（需要完整类型计算大小）
- 继承基类（需要完整定义）
- 调用成员函数/访问成员（需要声明）

</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 命名空间：给名字划边界

---

<div class="cols">

<div class="col-55">

```cpp
// task.h
namespace taskflow {

class Task {
    // ...
};

void print(const Task& t);

}  // namespace taskflow
```

```cpp
// main.cpp
#include "task.h"

int main() {
    taskflow::Task t(1, "写作业", 2);
    taskflow::print(t);
}
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">规则</div>

- 头文件中**不要**写 `using namespace std;`
- 源文件中可以有限使用，但更推荐显式限定
- 匿名命名空间用于文件内私有实体
- C++17 支持嵌套命名空间简写 `namespace a::b { }`

</div>

<div class="pitfall">
<span class="label">头文件污染</span>
在头文件写 <code>using namespace std;</code> 会污染所有包含它的源文件，可能引发名字冲突。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 编译与链接：ODR 与 `inline`

---

<div class="cols">

<div class="col">

**单独编译，统一链接**

```bash
g++ -std=c++17 -c task.cpp -o task.o
g++ -std=c++17 -c main.cpp -o main.o
g++ task.o main.o -o app
```

- 每个 `.cpp` 是一个翻译单元
- 头文件被复制进每个包含它的 `.cpp`
- 链接器负责合并符号

</div>

<div class="col">

**ODR（单一定义规则）**

- 同一个函数/变量在程序中只能有一个定义
- 头文件中定义非 `inline` 函数 → 多个 `.o` 都有一份 → 链接错误
- `inline` 函数/变量允许在多个翻译单元中定义（定义必须相同）
- 类定义、模板、`constexpr` 函数通常放在头文件

</div>

</div>

<div class="pitfall">
<span class="label">典型错误</span>
<code>undefined reference to Task::Task(...)</code>：声明了但没链接实现；<br>
<code>multiple definition of ...</code>：头文件里写了非 inline 的函数定义。
</div>

---


<!-- slide data-notes="" -->

##### 主线案例：把 `Task` 拆成模块

---

<div class="cols">

<div class="col-55 code-xs">

```cpp{.line-numbers}
// task.h
#pragma once
#include <iosfwd>
#include <string>

class Task {
public:
    Task(int id, std::string title, int priority);
    ~Task();

    void complete();
    bool is_done() const;
    int id() const;

    static int count();

    friend std::ostream& operator<<(std::ostream& os,
                                    const Task& t);
private:
    int id_;
    std::string title_;
    int priority_;
    bool done_ = false;
    static int count_;
};
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">设计点</div>

- `#pragma once` 防止重复包含
- `<iosfwd>` 只前置声明 `ostream`，减少依赖
- 静态成员 `count_` 在类内声明
- `operator<<` 作为友元
- 析构函数负责计数减一

</div>

<div class="small muted mt1">
`<iosfwd>` 适合只需要引用 `std::ostream&` 的头文件；真正实现输出时在 `.cpp` 中包含 `<ostream>`。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 主线案例：`task.cpp`

---

<div class="cols">

<div class="col-60 code-xs">

```cpp{.line-numbers}
// task.cpp
#include "task.h"
#include <iostream>
#include <utility>

int Task::count_ = 0;

Task::Task(int id, std::string title, int priority)
    : id_(id), title_(std::move(title)),
      priority_(priority) {
    ++count_;
}

Task::~Task() { --count_; }

void Task::complete() { done_ = true; }
bool Task::is_done() const { return done_; }
int Task::id() const { return id_; }
int Task::count() { return count_; }

std::ostream& operator<<(std::ostream& os, const Task& t) {
    return os << "[" << t.id_ << "] " << t.title_
              << (t.done_ ? " done" : " todo");
}
```

</div>

<div class="col-40">

<div class="card">

<div class="card-title">要点</div>

- 静态成员在 `.cpp` 中定义
- 构造函数/析构函数维护 `count_`
- 友元函数可以访问 `id_`、`title_`、`done_`
- `operator<<` 返回 `os` 支持链式输出

</div>

<div class="tip">
<span class="label">C++17</span>
也可以写 <code>inline static int count_ = 0;</code>，省去类外定义。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 课堂任务 6：模块化 `Task`

---

<div class="cols">

<div class="col-55">

<div class="card">

<div class="card-title">任务</div>

把 `Task` 拆成三个文件：

- `task.h`：类定义、`static int count()`、友元 `operator<<`
- `task.cpp`：构造函数、析构函数、成员函数、静态成员定义
- `main.cpp`：创建 3 个 `Task`，打印 `Task::count()`，输出每个任务

要求：

1. 使用 `#pragma once`
2. 静态成员 `count_` 记录存活对象数
3. `operator<<` 输出 `[id] title todo/done`
4. 用 `g++ task.cpp main.cpp -o app` 编译

</div>

</div>

<div class="col-45">

<div class="card">

<div class="card-title">验收标准</div>

- 三个文件可以独立编译、统一链接
- `Task::count()` 在创建/销毁后正确变化
- `std::cout << task` 能输出正确格式
- 头文件中没有函数定义（`inline` 除外）
- 头文件中没有 `using namespace std;`

</div>

<div class="tip">
<span class="label">提示</span>
先在头文件写声明，再在源文件写定义；链接错误通常来自“声明了但没定义”或“头文件里定义了非 inline 函数”。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 任务 6 参考实现（关键片段）

---

<div class="cols">

<div class="col-55 code-xs">

```cpp{.line-numbers}
// task.h
#pragma once
#include <iosfwd>
#include <string>

class Task {
public:
    Task(int id, std::string title, int priority);
    ~Task();

    static int count();
    friend std::ostream& operator<<(std::ostream& os,
                                    const Task& t);
private:
    int id_;
    std::string title_;
    int priority_;
    bool done_ = false;
    static int count_;
};
```

</div>

<div class="col-45 code-xs">

```cpp{.line-numbers}
// task.cpp（节选）
#include "task.h"
#include <ostream>
#include <utility>

int Task::count_ = 0;

Task::Task(int id, std::string title, int priority)
    : id_(id), title_(std::move(title)),
      priority_(priority) {
    ++count_;
}

Task::~Task() { --count_; }
int Task::count() { return count_; }

std::ostream& operator<<(std::ostream& os, const Task& t) {
    return os << "[" << t.id_ << "] " << t.title_;
}
```

</div>

</div>

<div class="small muted center mt1">
完整版本见本章 <code>code/</code> 目录。注意：<code>operator&lt;&lt;</code> 的定义放在 <code>.cpp</code>，头文件只留友元声明。
</div>

---


<!-- slide data-notes="" -->

##### 常见陷阱

---

<div class="cols">

<div class="col">

**const / static**

- 在 `const` 成员函数中修改成员
- 常量对象调用非 `const` 成员函数
- 静态成员只声明未定义 → 链接错误
- 静态成员函数访问非静态成员
- 用 `mutable` 掩盖设计问题

</div>

<div class="col">

**友元 / 模块**

- 以为友元是成员
- 以为友元对称或可传递
- 头文件里写非 inline 函数定义 → 重复定义
- 头文件里 `using namespace std;`
- 前置声明后直接使用对象（需要完整类型）
- 循环包含却没有前置声明

</div>

</div>

<div class="pitfall">
<span class="label">排错顺序</span>
编译错误看“类型/访问/声明”；链接错误看“定义/符号/库”。<code>undefined reference</code> 优先检查是否漏了 <code>.cpp</code> 或静态成员定义。
</div>

---


<!-- slide data-notes="" -->

##### 课堂小测

---

1. `const` 成员函数能修改指针成员指向的内容吗？为什么？

2. 静态数据成员与普通数据成员的生命周期、存储位置、共享方式有什么不同？

3. 友元关系是否对称？是否传递？请各举一个反例。

4. 为什么非 `inline` 函数定义不能放在头文件里？`#pragma once` 能解决这个问题吗？

---


<!-- slide data-notes="" -->

##### 小结：接口稳、类级状态清、模块边界明

---

<div class="cols">

<div class="col">

<div class="card">

<div class="card-title">const</div>

只读承诺；常量对象只能调用 const 成员；`mutable` 仅用于逻辑常量性。

</div>

</div>

<div class="col">

<div class="card">

<div class="card-title">static</div>

类级共享；静态成员函数没有 `this`；C++17 可 `inline static`。

</div>

</div>

<div class="col">

<div class="card">

<div class="card-title">模块</div>

`.h` 放声明，`.cpp` 放定义；`#pragma once`、前置声明、命名空间、ODR。

</div>

</div>

</div>

<div class="motto mt1">
好的类设计：<strong>接口尽可能 const，状态尽可能私有，依赖尽可能少</strong>。
</div>

---


<!-- slide data-notes="" -->

#####

---

<div class="bottom20"></div>

<hr class="width50 center">

## 未完待续

---
