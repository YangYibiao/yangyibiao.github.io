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

## 类与对象

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](mailto:yangyibiao@nju.edu.cn)


<!-- slide data-notes="" -->

##### 本讲提纲

---

<div class="cols">

<div class="col">

**定义类**

- 数据成员与成员函数
- 访问控制：`public` / `private` / `protected`
- 类内定义与类外定义

</div>

<div class="col">

**使用对象**

- 栈对象、对象数组、动态对象
- 成员访问与 `this` 指针
- 常量对象与常量成员函数

</div>

</div>

<div class="keypoint">
<span class="label">本讲目标</span>
能够把一个“数据 + 操作”的需求写成边界清晰的类，并解释对象创建、成员访问和 `this` 的来龙去脉。
</div>

---


<!-- slide data-notes="" -->

##### 一个类由什么构成？

---

<div class="cols">

<div class="col-55">

```cpp
class Target {
public:
    // 成员函数：对象能做什么
    void build();
    bool is_built() const;
    void print() const;

private:
    // 数据成员：对象有哪些状态
    int id_;
    std::string name_;
    int priority_;
    bool built_ = false;
};
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">三部分</div>

1. **数据成员**：每个对象各自一份
2. **成员函数**：描述行为，所有对象共享代码
3. **访问控制**：决定谁能看见、谁能使用

</div>

<div class="tip">
<span class="label">顺序无关</span>
数据成员可以写在成员函数后面；类内的名字在整个类定义中都可见。
</div>

</div>

</div>

<div class="small muted center">
类定义末尾的分号不能省：<code>};</code>。这是初学者最常见的编译错误之一。
</div>

---


<!-- slide data-notes="" -->

##### 成员函数：类内定义与类外定义

---

<div class="cols">

<div class="col">

**类内定义**（默认建议内联）

```cpp
class Target {
public:
    bool is_built() const {
        return built_;
    }
private:
    bool built_ = false;
};
```

适合：短小、频繁调用、实现稳定的函数。

</div>

<div class="col">

**类外定义**（声明与实现分离）

```cpp
class Target {
public:
    bool is_built() const;   // 声明
private:
    bool built_ = false;
};

bool Target::is_built() const {  // 定义
    return built_;
}
```

`Target::` 限定表明它是 `Target` 的成员，不是全局函数。

</div>

</div>

<div class="keypoint">
<span class="label">选择</span>
接口放类内，实现放类外，可以让头文件更稳定、编译依赖更小。是否内联由编译器决定，<code>inline</code> 只是建议。
</div>

---


<!-- slide data-notes="" -->

##### 访问控制：谁能看见，谁能使用

---

<div class="xsmall-table">

| 访问控制 | 本类成员函数 | 派生类 | 类外代码 | 典型用途 |
| :-- | :--: | :--: | :--: | :-- |
| `public` | ✓ | ✓ | ✓ | 对外接口 |
| `protected` | ✓ | ✓ | ✗ | 供派生类使用 |
| `private` | ✓ | ✗ | ✗ | 实现细节、数据 |

</div>

<div class="cols mt1">

<div class="col">

```cpp
class Target {
public:
    void build();          // 任何人可调用
protected:
    void log_change();        // 派生类可用
private:
    int id_;                  // 仅本类可用
    std::string name_;
};
```

</div>

<div class="col">

<div class="card">

<div class="card-title">默认访问控制</div>

- `class` 的默认是 `private`
- `struct` 的默认是 `public`
- 可以多次出现 `public:` / `private:`
- 访问控制只影响**名字的使用**，不影响对象布局

</div>

</div>

</div>

<div class="pitfall">
<span class="label">常见误解</span>
`private` 不是“对象里看不见”，而是“编译器禁止在类外通过名字访问”。对象内存中仍然有这些成员。
</div>

---


<!-- slide data-notes="" -->

##### 接口设计：什么该公开，什么该隐藏

---

<div class="cols">

<div class="col">

**应该公开**

- 构造对象所需的操作
- 业务语义明确的动作：`build()`、`rename()`
- 查询状态且不修改对象的函数：`is_built() const`
- 稳定的、调用方真正需要的接口

</div>

<div class="col">

**应该隐藏**

- 数据成员的表示方式
- 维护不变量所需的辅助函数
- 可能变化的具体算法
- 调用方不需要知道的缓存、索引、句柄

</div>

</div>

<div class="motto">
接口是承诺，数据是自由。接口越稳定，实现越自由。
</div>

<div class="question">
<span class="label">判断</span>
`Target` 的 `id_` 应不应该提供 `set_id(int)`？如果目标编号在创建后不应改变，这个 setter 会带来什么风险？
</div>

---


<!-- slide data-notes="" -->

##### 对象的三种创建方式

---

<div class="cols">

<div class="col">

**1. 栈对象（自动对象）**

```cpp
Target t(1, "main.o", 2);
t.build();
// 离开作用域自动销毁
```

**2. 对象数组**

```cpp
Target tasks[3] = {
    Target(1, "A", 1),
    Target(2, "B", 2),
    Target(3, "C", 3)
};
```

</div>

<div class="col">

**3. 动态对象（堆对象）**

```cpp
Target* p = new Target(1, "main.o", 2);
p->build();
delete p;          // 必须配对
```

动态对象数组：

```cpp
Target* q = new Target[3];  // 需要默认构造函数
// ...
delete[] q;             // 不能写成 delete q
```

</div>

</div>

<div class="pitfall">
<span class="label">配对规则</span>
<code>new</code> ↔ <code>delete</code>，<code>new[]</code> ↔ <code>delete[]</code>。混用是未定义行为，可能只调用部分析构函数。
</div>

---


<!-- slide data-notes="" -->

##### 栈对象与堆对象：生命周期不同

---

<div class="cols">

<div class="col-55">

```cpp
void demo() {
    Target stack_target(1, "栈对象", 2);
    Target* heap_target = new Target(2, "堆对象", 3);

    stack_target.build();
    heap_target->build();

    // 函数结束：
    // stack_target 自动销毁
    // heap_target 仍然存在，但指针丢失 -> 泄漏
}
```

</div>

<div class="col-45">

<div class="timeline">
<div class="tl-row"><span class="tl-label">栈</span><div class="tl-track"><div class="tl-bar b1" style="left:0;width:58%;">stack_target 生存</div></div></div>
<div class="tl-row"><span class="tl-label">堆</span><div class="tl-track"><div class="tl-bar b2" style="left:8%;width:88%;">heap_target 指向的对象</div></div></div>
<div class="tl-row"><span class="tl-label">指针</span><div class="tl-track"><div class="tl-bar b3" style="left:8%;width:50%;">heap_target 变量</div></div></div>
</div>

<div class="small muted">
栈对象随作用域结束自动销毁；堆对象只随 <code>delete</code> 销毁。
</div>

</div>

</div>

<div class="keypoint">
<span class="label">核心区别</span>
“对象在哪里”决定“谁负责销毁”。栈对象由作用域负责，堆对象由程序员负责——这也是后面 RAII 与智能指针要解决的问题。
</div>

---


<!-- slide data-notes="" -->

##### 对象指针与成员访问

---

<div class="cols">

<div class="col">

```cpp
Target t(1, "main.o", 2);
Target* p = &t;

p->build();      // 通过指针调用
(*p).print();       // 等价写法

Target& r = t;        // 引用是对象的别名
r.build();       // 像对象一样使用
```

</div>

<div class="col">

<div class="card">

<div class="card-title">三种访问形式</div>

- `t.member`：对象直接访问
- `p->member`：指针访问，等价于 `(*p).member`
- `r.member`：引用访问，`r` 就是对象本身

</div>

<div class="tip">
<span class="label">选择</span>
需要“可空、可改指向”用指针；需要“必不为空、像对象一样用”用引用；不需要间接时直接用对象。
</div>

</div>

</div>

<div class="question">
<span class="label">思考</span>
`Target* p = new Target(...); p->print();` 中，`print()` 怎么知道操作的是 `p` 指向的对象，而不是别的对象？
</div>

---


<!-- slide data-notes="" -->

##### `this` 指针：成员函数的隐藏参数

---

<div class="cols">

<div class="col-55 code-xs">

**你写的代码**

```cpp
class Target {
public:
    void set_priority(int p) {
        priority_ = p;
    }
private:
    int priority_ = 0;
};

Target a, b;
a.set_priority(1);
b.set_priority(2);
```

**编译器看到的世界（简化）**

```cpp
void Target::set_priority(Target* const this, int p) {
    this->priority_ = p;
}

Target::set_priority(&a, 1);
Target::set_priority(&b, 2);
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">要点</div>

- 每个非静态成员函数都有一个隐藏的 `this`
- `this` 的类型是 `Target* const`（指针本身不可改指向）
- `this` 指向“当前被调用的那个对象”
- 静态成员函数没有 `this`

</div>

<div class="keypoint">
<span class="label">理解</span>
成员函数只有一份代码，`this` 让同一份代码能操作不同对象的数据。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### `this` 的用途（一）：区分名字与返回自身

---

<div class="cols">

<div class="col code-xs">

**1. 区分同名参数与成员**

```cpp
class Target {
public:
    Target(int id, std::string name)
        : id_(id), name_(std::move(name)) {}

    void rename(const std::string& name) {
        this->name_ = name;
    }
private:
    int id_;
    std::string name_;
};
```

</div>

<div class="col code-xs">

**2. 返回对象自身，支持链式调用**

```cpp
class Counter {
public:
    Counter& add(int n) {
        value_ += n;
        return *this;
    }
    Counter& sub(int n) {
        value_ -= n;
        return *this;
    }
private:
    int value_ = 0;
};

Counter c;
c.add(5).sub(2).add(10);
```

</div>

</div>

---


<!-- slide data-notes="" -->

##### `this` 的用途（二）：把自身传出去

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
void log_target(const Target* t);

void Target::report() const {
    log_target(this);   // 把“我自己”传出去
}
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">使用场景</div>

- 需要把当前对象注册到观察者列表
- 需要把自身传给回调函数
- 需要在成员函数中与另一个同类对象比较地址

</div>

</div>

</div>

<div class="pitfall">
<span class="label">注意 const</span>
在 <code>const</code> 成员函数中，<code>this</code> 的类型是 <code>const Target*</code>，不能通过它修改成员；把 <code>this</code> 传给接收 <code>Target*</code> 的函数会编译失败。
</div>

---
<!-- slide data-notes="" -->

##### 常量成员函数：承诺不修改对象

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
class Target {
public:
    bool is_built() const { return built_; }
    int priority() const { return priority_; }

    void build() { built_ = true; }  // 非 const
private:
    int priority_ = 0;
    bool built_ = false;
};
```

```cpp
void print(const Target& t) {
    t.is_built();        // OK
    t.build();       // 编译错误
}
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">规则</div>

- `const` 写在参数表后面：`bool f() const;`
- 常量对象只能调用常量成员函数
- 常量成员函数内不能修改非 `mutable` 数据成员
- 常量引用参数是“只读借用”，不拷贝对象

</div>

<div class="tip">
<span class="label">设计习惯</span>
不修改对象的成员函数一律加 <code>const</code>。否则常量对象、常量引用都无法调用它。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 常量成员函数的重载

---

<div class="cols">

<div class="col-55 code-sm">

同一个函数名可以有两个版本，按对象的常量性选择：

```cpp
class TargetList {
public:
    Target& at(int i) {          // 非 const
        return targets_[i];
    }

    const Target& at(int i) const { // const
        return targets_[i];
    }
private:
    std::vector<Target> targets_;
};
```

```cpp
TargetList list;
list.at(0).build();        // 调用非 const 版本

const TargetList& clist = list;
clist.at(0).build();       // 错误：返回 const Target&
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">为什么需要两个版本</div>

- 非 const 对象：允许通过 `at` 修改元素
- const 对象：只允许读，返回 `const` 引用
- 只提供一个版本会损失能力或破坏常量性

</div>

<div class="small muted mt1">
<code>mutable</code> 用于“逻辑上不改变对象状态”的缓存、计数等成员；初学阶段尽量少用。
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
class Target {
public:
    bool is_built() const {
        ++query_count_;       // 允许：mutable
        return built_;
    }
    int query_count() const { return query_count_; }
private:
    bool built_ = false;
    mutable int query_count_ = 0;
};
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">语义</div>

- 对象对外表现为“没有改变”
- 内部允许修改缓存、计数器、互斥量等
- 不是为了绕过 `const`，而是表达“逻辑常量”

</div>

<div class="pitfall">
<span class="label">警告</span>
把业务字段声明为 <code>mutable</code> 来绕过 <code>const</code> 检查，会破坏接口承诺。先用设计解决问题，再考虑 <code>mutable</code>。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 成员对象：一个对象包含另一个对象

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
class FileStamp {
public:
    explicit FileStamp(long mtime) : mtime_(mtime) {}
    long mtime() const { return mtime_; }
private:
    long mtime_;
};

class FileTarget {
public:
    FileTarget(int id, const std::string& name, FileStamp stamp)
        : id_(id), name_(name), stamp_(stamp) {}
private:
    int id_;
    std::string name_;
    FileStamp stamp_;        // 成员对象
};
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">构造与析构</div>

- 创建 `FileTarget` 时，先构造成员对象 `stamp_`，再执行自身构造函数体
- 销毁时顺序相反：先执行自身析构函数体，再析构成员对象
- 成员对象的构造顺序按**声明顺序**，与初始化列表书写顺序无关

</div>

<div class="tip">
<span class="label">这是“组合”</span>
<code>FileTarget</code> <strong>有一个</strong> <code>FileStamp</code>，不是“是一种” <code>FileStamp</code>。这是组合关系，不是继承。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 对象作为参数与返回值

---

<div class="table-sm">

| 形式 | 写法 | 是否拷贝 | 能否修改实参 | 适用场景 |
| :-- | :-- | :--: | :--: | :-- |
| 传值 | `void f(Target t)` | 是 | 否（改的是副本） | 小对象、需要独立副本 |
| 传引用 | `void f(Target& t)` | 否 | 是 | 需要修改调用方对象 |
| 传常量引用 | `void f(const Target& t)` | 否 | 否 | 只读、大对象 |
| 传指针 | `void f(Target* t)` | 否 | 可 | 可空、需要改指向 |

</div>

<div class="cols mt1">

<div class="col">

```cpp
void build_all(std::vector<Target>& tasks) {
    for (Target& t : tasks) {
        t.build();          // 修改原对象
    }
}
```

</div>

<div class="col">

```cpp
void print_all(const std::vector<Target>& tasks) {
    for (const Target& t : tasks) {
        t.print();             // 只读，不拷贝
    }
}
```

</div>

</div>

<div class="keypoint">
<span class="label">默认选择</span>
只读参数用 <code>const T&amp;</code>；需要修改用 <code>T&amp;</code>；确实需要副本或对象很小才传值。
</div>

---


<!-- slide data-notes="" -->

##### 类的作用域与名字查找

---

<div class="cols">

<div class="col-55">

```cpp
class A {
public:
    void f() {
        g();          // OK：g 在类作用域中，后声明也可用
        x_ = 1;
    }
    void g() { }
private:
    int x_ = 0;
};

void h() {
    A a;
    a.f();            // OK
    a.g();            // OK
    // a.x_ = 1;      // 错误：private
}
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">三条规则</div>

1. 类内声明的名字在整个类作用域内可见
2. 类外访问成员必须通过对象、指针或引用
3. 派生类可以隐藏基类同名成员（继承章节展开）

</div>

<div class="small muted mt1">
成员函数体虽然写在类外，仍然属于类的作用域，可以直接访问私有成员。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 从类定义到多文件：先看一个最小拆分

---

<div class="cols">

<div class="col code-xs">

**target.h**

```cpp
#pragma once
#include <string>

class Target {
public:
    Target(int id, std::string name, int priority);
    void build();
    void print() const;
private:
    int id_;
    std::string name_;
    int priority_;
    bool built_ = false;
};
```

</div>

<div class="col code-xs">

**target.cpp**

```cpp
#include "target.h"
#include <iostream>
#include <utility>

Target::Target(int id, std::string name, int priority)
    : id_(id), name_(std::move(name)),
      priority_(priority) {}

void Target::build() { built_ = true; }

void Target::print() const {
    std::cout << "[" << id_ << "] " << name_ << " "
              << (built_ ? "built" : "todo") << "\n";
}
```

</div>

</div>

<div class="tip">
<span class="label">说明</span>
头文件放声明，源文件放定义；<code>#pragma once</code> 防止重复包含。模块化、前置声明、编译链接的细节在第 6 单元展开。
</div>

---


<!-- slide data-notes="" -->

##### 主线案例：`Target` 的接口（target.h）

---

<div class="cols">

<div class="col-55 code-xs">

```cpp{.line-numbers}
// target.h
#pragma once
#include <string>

class Target {
public:
    Target(int id, std::string name, int priority);

    void build();
    void rename(const std::string& name);
    bool is_built() const;
    int priority() const;
    void print() const;

private:
    int id_;
    std::string name_;
    int priority_;
    bool built_ = false;
};
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">接口设计要点</div>

- 构造函数建立合法状态
- `build` / `rename` 是修改操作
- `is_built` / `priority` / `print` 是只读操作，全部 `const`
- 数据成员私有，表示方式可替换

</div>

<div class="tip">
<span class="label">头文件职责</span>
只放声明和必要的类型定义；实现细节放在 <code>target.cpp</code>，减少编译依赖。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 主线案例：`Target` 的实现（target.cpp）

---

<div class="cols">

<div class="col-60 code-xs">

```cpp{.line-numbers}
// target.cpp
#include "target.h"
#include <iostream>
#include <utility>

Target::Target(int id, std::string name, int priority)
    : id_(id), name_(std::move(name)),
      priority_(priority) {}

void Target::build() { built_ = true; }

void Target::rename(const std::string& name) {
    if (!name.empty()) name_ = name;
}

bool Target::is_built() const { return built_; }
int Target::priority() const { return priority_; }

void Target::print() const {
    std::cout << "[" << id_ << "] " << name_
              << " (p=" << priority_ << ") "
              << (built_ ? "built" : "todo") << "\n";
}
```

</div>

<div class="col-40">

<div class="card">

<div class="card-title">实现要点</div>

- `std::move` 避免一次字符串拷贝
- `rename` 拒绝空名称，维护不变量
- 只读函数不修改状态
- 输出格式集中在一个函数中

</div>

<div class="out mt1">[1] main.o (p=2) todo
[2] util.o (p=3) built</div>

<div class="small muted mt1">
完整可编译版本见本章 <code>code/</code> 目录。
</div>

</div>

</div>

---
<!-- slide data-notes="" -->

##### 课堂任务 2：给 `Target` 增加状态查询

---

<div class="cols">

<div class="col-55">

<div class="card">

<div class="card-title">任务</div>

在上一讲的 `Target` 类基础上增加：

1. `int id() const`：返回目标编号
2. `bool is_high_priority() const`：优先级 ≥ 4 返回 `true`
3. `void raise_priority()`：把优先级加 1，最高为 5
4. `void print() const` 输出格式：
   `[1] main.o p=2 todo`

在 `main` 中创建 3 个目标，调用 `raise_priority()` 与 `build()`，打印全部目标。

</div>

</div>

<div class="col-45">

<div class="card">

<div class="card-title">验收标准</div>

- 所有不修改对象的函数都加 `const`
- 数据成员保持 `private`
- `raise_priority()` 不能把优先级加到 6
- 编译无警告：`-Wall -Wextra`
- 不使用全局变量

</div>

<div class="tip">
<span class="label">提示</span>
先写接口，再写实现；<code>raise_priority()</code> 可以在类内定义，短小函数更适合放头文件。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 课堂任务 2 参考实现（一）：类定义

---

<div class="cols">

<div class="col-55 code-sm">

```cpp{.line-numbers}
#include <iostream>
#include <string>
#include <utility>

class Target {
public:
    Target(int id, std::string name, int priority)
        : id_(id), name_(std::move(name)),
          priority_(priority) {}

    int id() const { return id_; }
    bool is_built() const { return built_; }
    bool is_high_priority() const { return priority_ >= 4; }

    void build() { built_ = true; }

    void raise_priority() {
        if (priority_ < 5) ++priority_;
    }

    void print() const {
        std::cout << "[" << id_ << "] " << name_
                  << " p=" << priority_ << " "
                  << (built_ ? "built" : "todo") << "\n";
    }

private:
    int id_;
    std::string name_;
    int priority_;
    bool built_ = false;
};
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">关键点</div>

- 构造函数建立合法状态
- 查询函数全部 `const`
- `raise_priority()` 把优先级限制在 `1..5`
- 数据保持私有，接口足够表达业务

</div>

<div class="tip">
<span class="label">检查</span>
如果把 <code>priority_</code> 改成 <code>public</code>，<code>raise_priority()</code> 的不变量还有意义吗？
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 课堂任务 2 参考实现（二）：main 与输出

---

<div class="cols">

<div class="col-55 code-sm">

```cpp{.line-numbers}
#include <vector>
// 假设 Target 定义在 target.h 中（见上一页）

int main() {
    std::vector<Target> tasks;
    tasks.emplace_back(1, "main.o", 2);
    tasks.emplace_back(2, "util.o", 4);
    tasks.emplace_back(3, "app", 5);

    tasks[0].raise_priority();
    tasks[1].build();

    for (const Target& t : tasks) {
        t.print();
    }
}
```

</div>

<div class="col-45">

**运行结果**

<div class="out">[1] main.o p=3 todo
[2] util.o p=4 built
[3] app p=5 todo</div>

<div class="small mt1">

**要点**

- `emplace_back` 直接在容器中构造对象
- `const Target&` 遍历，不拷贝、不修改
- `raise_priority()` 与 `build()` 的调用顺序影响输出
- 若 `Target` 没有默认构造函数，`vector<Target> v(n)` 不能编译

</div>

</div>

</div>

---
<!-- slide data-notes="" -->

##### 常见错误清单

---

<div class="cols">

<div class="col code-sm">

**语法类**

- 类定义末尾漏分号：`class A { ... }`
- 类外定义漏 `A::`
- 在 `const` 成员函数中修改成员
- 把 `private` 成员当全局变量访问

**语义类**

- 忘记初始化数据成员
- `new[]` 用 `delete` 释放
- 返回局部对象的引用
- 让 `public` 函数把内部引用/指针泄露出去

</div>

<div class="col code-sm">

```cpp
class A {
public:
    int& value() { return value_; }  // 泄露内部状态
private:
    int value_ = 0;
};

A a;
a.value() = 42;   // 绕过所有检查
```

<div class="pitfall">
<span class="label">封装泄露</span>
返回内部数据的非 <code>const</code> 引用，等于把 <code>private</code> 变成 <code>public</code>。只读场景返回 <code>const&amp;</code> 或值。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 课堂小测

---

1. `class` 与 `struct` 的默认访问控制分别是什么？`private` 成员在对象内存中是否真实存在？

2. 成员函数只有一份代码，为什么 `a.f()` 与 `b.f()` 能操作不同的对象？请用 `this` 解释。

3. 为什么“不修改对象的成员函数”要加 `const`？常量对象调用非 `const` 成员函数会发生什么？

4. 下列代码有什么问题？

```cpp
class A {
public:
    A(int x) : x_(x) {}
    int& get() const { return x_; }
private:
    int x_;
};
```

---


<!-- slide data-notes="" -->

##### 小结：类是一份契约

---

<div class="cols">

<div class="col">

<div class="card">

<div class="card-title">对外</div>

- `public` 接口：对象能做什么
- `const`：哪些操作承诺不修改状态
- 构造函数：对象创建后即合法

</div>

</div>

<div class="col">

<div class="card">

<div class="card-title">对内</div>

- `private` 数据：表示与不变量
- 成员函数共享一份代码，`this` 区分对象
- 成员对象按声明顺序构造、逆序析构

</div>

</div>

<div class="col">

<div class="card">

<div class="card-title">使用</div>

- 栈对象随作用域，堆对象手动管理
- 只读用 `const&`，修改用 `&`
- 不泄露内部数据的可变引用

</div>

</div>

</div>

<div class="motto mt1">
类的价值不在于“把函数放进大括号”，而在于<strong>用接口守住不变量，让调用方无法轻易犯错</strong>。
</div>

---


<!-- slide data-notes="" -->

#####

---

<div class="bottom20"></div>

<hr class="width50 center">

## 未完待续

---
