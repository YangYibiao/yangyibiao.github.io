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

## 构造与析构：对象的生与死

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](mailto:yangyibiao@nju.edu.cn)


<!-- slide data-notes="" -->

##### 本讲提纲

---

<div class="cols">

<div class="col">

**对象的生**

- 构造函数的作用与规则
- 默认构造函数与重载
- 成员初始化列表
- 就地初始化与委托构造

</div>

<div class="col">

**对象的死**

- 析构函数的调用时机
- 成员对象与基类的构造/析构顺序
- RAII：把资源交给对象管理
- 构造/析构中的异常

</div>

</div>

<div class="keypoint">
<span class="label">本讲目标</span>
能够为一个带资源的类写出正确的构造/析构函数，并解释“对象什么时候生、什么时候死、资源什么时候释放”。
</div>

---


<!-- slide data-notes="" -->

##### 为什么需要构造函数？

---

<div class="cols">

<div class="col">

**没有构造函数的世界**

```cpp
class Task {
public:
    int id;
    std::string title;
    int priority;
    bool done;
};

Task t;              // 数据成员是什么？
t.id = 1;
t.title = "写作业";
t.priority = 2;
t.done = false;      // 很容易漏掉
```

<div class="pitfall">
<span class="label">问题</span>
对象创建后可能处于<strong>非法状态</strong>：编号未设置、优先级越界、标志位随机。使用者必须记住“先调用某个 init 函数”。
</div>

</div>

<div class="col">

**构造函数的目标**

<div class="flow" style="flex-direction:column;width:100%;margin:0.2rem 0;">
<div class="flow-step"><strong>分配空间</strong>对象获得内存</div>
<div class="flow-step"><strong>建立不变量</strong>所有成员进入合法状态</div>
<div class="flow-step"><strong>可以使用</strong>调用方拿到对象即可工作</div>
</div>

<div class="keypoint">
<span class="label">核心承诺</span>
构造函数返回时，对象必须满足类的不变量。之后任何 <code>public</code> 操作都可以安全调用。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 构造函数的规则

---

<div class="cols">

<div class="col">

```cpp
class Task {
public:
    Task() {                 // 默认构造函数
        id_ = 0;
        priority_ = 1;
    }

    Task(int id, std::string title, int priority)
        : id_(id), title_(std::move(title)),
          priority_(priority) {}

private:
    int id_ = 0;
    std::string title_;
    int priority_ = 1;
    bool done_ = false;
};
```

</div>

<div class="col">

<div class="card">

<div class="card-title">四条规则</div>

1. 函数名与类名相同
2. 没有返回类型（连 `void` 也不写）
3. 创建对象时自动调用
4. 可以重载，参数不同

</div>

<div class="tip">
<span class="label">默认构造函数</span>
不带参数，或所有参数都有默认值的构造函数。`Task() = default;` 让编译器生成一个。
</div>

</div>

</div>

<div class="question">
<span class="label">思考</span>
`Task t;` 与 `Task t();` 有什么区别？后者为什么没有创建对象？
</div>

---


<!-- slide data-notes="" -->

##### 默认构造函数：什么时候会被自动生成？

---

<div class="cols">

<div class="col">

**编译器生成默认构造的条件**

- 类中没有声明任何构造函数
- 没有用户声明的拷贝/移动构造函数（某些情况下）

```cpp
class A {
    int x_;          // 默认构造：x_ 未初始化！
};

class B {
    int x_ = 0;      // 默认构造：x_ 初始化为 0
};
```

</div>

<div class="col">

**显式要求或禁止**

```cpp
class Task {
public:
    Task() = default;              // 要求生成
    Task(int id) : id_(id) {}
private:
    int id_ = 0;
};

class NoDefault {
public:
    NoDefault() = delete;          // 禁止默认构造
    NoDefault(int x) : x_(x) {}
private:
    int x_;
};
```

</div>

</div>

<div class="pitfall">
<span class="label">陷阱</span>
一旦声明了任何构造函数，编译器就不再生成默认构造函数。<code>Task t;</code> 会编译失败，除非你显式写 <code>Task() = default;</code>。
</div>

---


<!-- slide data-notes="" -->

##### 成员初始化列表：真正“初始化”的地方

---

<div class="cols">

<div class="col-55">

```cpp
class Task {
public:
    Task(int id, std::string title, int priority)
        : id_(id), title_(std::move(title)),
          priority_(priority) {}
private:
    int id_;
    std::string title_;
    int priority_;
    bool done_ = false;
};
```

<div class="small muted mt1">
冒号后面、函数体之前的部分叫<strong>成员初始化列表</strong>。
</div>

</div>

<div class="col-45">

<div class="card">

<div class="card-title">初始化列表 vs 函数体赋值</div>

```cpp
// 初始化：直接构造成员
Task(...) : id_(id) {}

// 赋值：先默认构造，再赋值
Task(...) { id_ = id; }
```

对于 `int` 差别不大；对于 `std::string`、成员对象，函数体赋值会多一次默认构造 + 赋值。

</div>

</div>

</div>

<div class="keypoint">
<span class="label">优先使用初始化列表</span>
它表达“成员在出生时就具有这个值”，而不是“先出生，再被改写”。
</div>

---


<!-- slide data-notes="" -->

##### 必须使用初始化列表的三种成员

---

<div class="cols">

<div class="col">

```cpp
class Config {
public:
    Config(int id)
        : id_(id), name_("task"), ref_(id_) {}
private:
    int id_;
    const std::string name_;  // 常量成员
    int& ref_;                // 引用成员
};
```

</div>

<div class="col">

<div class="card">

<div class="card-title">为什么必须</div>

- `const` 成员：只能在初始化时给定值
- 引用成员：必须在初始化时绑定对象
- 没有默认构造函数的成员对象：必须显式调用其构造函数

</div>

<div class="tip">
<span class="label">写法</span>
<code>ref_(id_)</code> 把引用绑定到 <code>id_</code>；之后 <code>ref_</code> 始终是 <code>id_</code> 的别名，不能改绑。
</div>

</div>

</div>

<div class="pitfall">
<span class="label">顺序陷阱</span>
成员按<strong>声明顺序</strong>初始化，与初始化列表的书写顺序无关。上面的 <code>ref_(id_)</code> 能工作，是因为 <code>id_</code> 声明在 <code>ref_</code> 之前。
</div>

---


<!-- slide data-notes="" -->

##### 初始化顺序：按声明，不按书写

---

<div class="cols">

<div class="col-55">

```cpp
class Bad {
public:
    Bad() : b_(1), a_(b_ + 1) {}  // 书写顺序：b_ 再 a_
private:
    int a_;   // 实际先初始化 a_
    int b_;   // 再初始化 b_
};
```

实际执行：

1. `a_` 用 `b_ + 1` 初始化，但 `b_` 还没初始化 → 未定义行为
2. `b_` 初始化为 1

</div>

<div class="col-45">

<div class="card">

<div class="card-title">规则</div>

- 基类先于成员
- 成员按类中**声明顺序**初始化
- 初始化列表顺序不影响执行顺序
- 析构顺序严格相反

</div>

<div class="tip">
<span class="label">建议</span>
初始化列表的书写顺序与声明顺序保持一致，并开启 <code>-Wreorder</code> 警告。
</div>

</div>

</div>

<div class="out">g++ -Wall -Wextra 可能提示：
warning: 'Bad::a_' will be initialized after 'Bad::b_'</div>

---


<!-- slide data-notes="" -->

##### 就地初始化与委托构造

---

<div class="cols">

<div class="col">

**就地初始化** <span class="std cxx11">C++11</span>

```cpp
class Task {
private:
    int id_ = 0;
    std::string title_ = "untitled";
    int priority_ = 1;
    bool done_ = false;
};
```

- 在声明处给默认值
- 所有构造函数共享
- 初始化列表可以覆盖它

</div>

<div class="col">

**委托构造** <span class="std cxx11">C++11</span>

```cpp
class Task {
public:
    Task() : Task(0, "untitled", 1) {}

    Task(int id, std::string title, int priority)
        : id_(id), title_(std::move(title)),
          priority_(priority) {}
private:
    int id_;
    std::string title_;
    int priority_;
    bool done_ = false;
};
```

一个构造函数委托另一个完成初始化，避免重复代码。

</div>

</div>

<div class="keypoint">
<span class="label">执行顺序</span>
就地初始化 → 初始化列表 → 构造函数体。初始化列表的显式值会覆盖就地初始化的默认值。
</div>

---


<!-- slide data-notes="" -->

##### 析构函数：对象消亡前的最后一步

---

<div class="cols">

<div class="col-55">

```cpp
class Task {
public:
    ~Task() {
        // 释放对象持有的资源
        // 例如：关闭文件、delete 动态内存
    }
};
```

<div class="card mt1">

<div class="card-title">调用时机</div>

- 栈对象离开作用域
- `delete` 动态对象
- 临时对象表达式结束
- 程序结束时全局/静态对象销毁

</div>

</div>

<div class="col-45">

<div class="card">

<div class="card-title">规则</div>

- 名字：`~类名`
- 没有参数、没有返回值
- 不能重载
- 一个类只能有一个析构函数
- 不写时编译器生成一个（逐成员析构）

</div>

<div class="tip">
<span class="label">默认就够了？</span>
如果对象只包含 <code>int</code>、<code>std::string</code>、<code>std::vector</code> 等自己会管理资源的成员，默认析构通常足够。只有持有<strong>裸资源</strong>时才需要自定义。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 对象生命周期：栈、堆与临时对象

---

<div class="cols code-sm">

<div class="col">

```cpp
void demo() {
    Task a(1, "栈", 1);        // 构造
    Task* p = new Task(2, "堆", 2); // 构造
    Task b = Task(3, "临时", 3);    // 构造（可能被优化）

    // ...
}   // a、b 析构；p 指向的对象仍在 -> 泄漏
```

</div>

<div class="col">

<div class="timeline">
<div class="tl-row"><span class="tl-label">a</span><div class="tl-track"><div class="tl-bar b1" style="left:0;width:80%;">构造 → 作用域结束析构</div></div></div>
<div class="tl-row"><span class="tl-label">p</span><div class="tl-track"><div class="tl-bar b3" style="left:0;width:45%;">指针变量</div></div></div>
<div class="tl-row"><span class="tl-label">*p</span><div class="tl-track"><div class="tl-bar bad" style="left:0;width:95%;">对象一直存活（未 delete）</div></div></div>
</div>

<div class="small muted">
堆对象的生命周期与指针变量无关；指针销毁不代表对象销毁。
</div>

</div>

</div>

<div class="pitfall">
<span class="label">结论</span>
“谁创建，谁销毁”必须明确。栈对象由作用域负责，堆对象必须由某个所有者负责——这就是 RAII 要解决的问题。
</div>

---


<!-- slide data-notes="" -->

##### 成员对象的构造与析构顺序

---

<div class="cols">

<div class="col-55">

```cpp
class A {
public:
    A() { std::cout << "A "; }
    ~A() { std::cout << "~A "; }
};

class B {
public:
    B() { std::cout << "B "; }
    ~B() { std::cout << "~B "; }
private:
    A a_;      // 成员对象
};

int main() {
    B b;
    return 0;
}
```

</div>

<div class="col-45">

**输出**

<div class="out">A B ~B ~A</div>

<div class="card mt1">

<div class="card-title">顺序</div>

- 构造：成员对象 → 自身构造函数体
- 析构：自身析构函数体 → 成员对象
- 多个成员按声明顺序构造，逆序析构

</div>

<div class="small muted mt1">
成员对象是“组合”关系：它随包含它的对象一起生、一起死。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 继承中的构造与析构顺序（预告）

---

<div class="cols">

<div class="col-55">

```cpp
class Base {
public:
    Base() { std::cout << "Base "; }
    ~Base() { std::cout << "~Base "; }
};

class Derived : public Base {
public:
    Derived() { std::cout << "Derived "; }
    ~Derived() { std::cout << "~Derived "; }
};

int main() {
    Derived d;
}
```

</div>

<div class="col-45">

**输出**

<div class="out">Base Derived ~Derived ~Base</div>

<div class="card mt1">

<div class="card-title">规则</div>

- 构造：基类 → 成员对象 → 派生类
- 析构：派生类 → 成员对象 → 基类
- 基类子对象必须先于派生类成员构造完成

</div>

<div class="tip">
<span class="label">下一单元</span>
为什么基类析构函数常要写成 <code>virtual</code>？继承与多态章节会给出完整解释。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 资源由谁释放？从 `String` 说起

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
class String {
public:
    explicit String(const char* s)
        : len_(std::strlen(s)),
          data_(new char[len_ + 1]) {
        std::strcpy(data_, s);
    }

    ~String() {
        delete[] data_;
    }
private:
    std::size_t len_;
    char* data_;
};
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">对象拥有的资源</div>

- 对象本身只包含 `len_` 和指针 `data_`
- `data_` 指向的字符数组是**额外申请**的资源
- 对象销毁时必须归还，否则泄漏

</div>

<div class="pitfall">
<span class="label">危险</span>
编译器生成的默认析构不会 <code>delete[] data_</code>；默认拷贝构造又会让两个对象指向同一块内存。拷贝语义下一单元展开。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### RAII：让对象管理资源

---

<div class="cols">

<div class="col-55">

```cpp
class FileHandle {
public:
    explicit FileHandle(const char* path)
        : fp_(std::fopen(path, "r")) {}

    ~FileHandle() {
        if (fp_) std::fclose(fp_);
    }

    FileHandle(const FileHandle&) = delete;
    FileHandle& operator=(const FileHandle&) = delete;

    std::FILE* get() const { return fp_; }
private:
    std::FILE* fp_;
};
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">RAII 三步</div>

1. 构造函数获取资源
2. 析构函数释放资源
3. 禁止或正确实现拷贝，避免重复释放

</div>

<div class="keypoint">
<span class="label">价值</span>
无论函数正常返回、提前 <code>return</code>，还是抛出异常，栈对象都会析构，资源都会释放。
</div>

<div class="small muted mt1">
<code>std::fopen</code> 失败时 <code>fp_</code> 为 <code>nullptr</code>，析构函数用 <code>if (fp_)</code> 保护。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 对象数组的构造与析构

---

<div class="cols">

<div class="col-55">

```cpp
Task tasks[3] = {
    Task(1, "A", 1),
    Task(2, "B", 2),
    Task(3, "C", 3)
};
```

- 依次构造 `tasks[0]`、`tasks[1]`、`tasks[2]`
- 数组离开作用域时，按**逆序**析构

```cpp
Task* p = new Task[3];  // 需要默认构造函数
// ...
delete[] p;             // 依次析构每个元素
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">注意</div>

- `new T[n]` 要求 `T` 有可访问的默认构造函数（C++11 起）
- `delete[]` 会调用每个元素的析构函数
- `delete p` 与 `delete[] p` 混用是未定义行为

</div>

<div class="tip">
<span class="label">现代写法</span>
优先使用 <code>std::vector&lt;T&gt;</code>，由容器管理内存与析构，避免手动 <code>new[]</code>。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 临时对象：来去匆匆

---

<div class="cols code-sm">

<div class="col-55">

```cpp
Task make_task() {
    return Task(1, "临时任务", 2);
}

void print_task(const Task& t);  // 常量引用可以绑定临时对象

int main() {
    Task t = make_task();   // 返回值优化，通常不拷贝
    print_task(Task(2, "一次性", 3)); // 临时对象在表达式结束后销毁
}
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">生命周期</div>

- 临时对象在完整表达式结束时销毁
- 绑定到 `const T&` 时，生命周期延长到引用的作用域结束
- 不要返回局部对象的引用

</div>

<div class="pitfall">
<span class="label">常见错误</span>
<code>const Task&amp; r = make_task();</code> 是安全的（生命周期延长）；<br>
<code>const Task&amp; r = *new Task(...);</code> 会泄漏，且引用与对象生命周期脱节。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 构造/析构中的异常

---

<div class="cols code-sm">

<div class="col">

**构造函数抛出异常**

```cpp
class Conn {
public:
    Conn() {
        // 如果这里抛出异常：
        // 1. 已构造完成的成员会被析构
        // 2. 对象本身的析构函数不会执行
        throw std::runtime_error("connect failed");
    }
};
```

<div class="small muted">
构造函数没有“完成”，对象不存在，不能依赖析构函数清理“半个对象”。
</div>

</div>

<div class="col">

**析构函数不应抛出异常**

```cpp
~Conn() {
    try {
        close();
    } catch (...) {
        // 记录日志，但不要向外抛
    }
}
```

<div class="pitfall">
<span class="label">原因</span>
栈展开过程中如果再抛异常，程序会直接 <code>std::terminate</code>。C++11 起析构函数默认 <code>noexcept</code>。
</div>

</div>

</div>

<div class="keypoint">
<span class="label">设计建议</span>
构造函数要么成功返回一个完整对象，要么抛出异常；不要在构造函数里“半初始化 + 设置错误码”。
</div>

---


<!-- slide data-notes="" -->

##### 主线案例：`TaskList` 的资源管理

---

<div class="cols">

<div class="col-55">

```cpp
class TaskList {
public:
    TaskList() = default;

    void add(Task t) {
        tasks_.push_back(std::move(t));
    }

    std::size_t size() const { return tasks_.size(); }

private:
    std::vector<Task> tasks_;
};
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">不需要手写析构</div>

- `std::vector<Task>` 自己管理内存
- `TaskList` 销毁时，`vector` 析构，依次销毁所有 `Task`
- `Task` 的 `std::string` 也会自动释放

</div>

<div class="keypoint">
<span class="label">组合的力量</span>
把资源交给会管理资源的成员，类本身就不需要写析构函数。这是现代 C++ 的首选方式。
</div>

<div class="small muted mt1">
`add(Task t)` 按值接收，再用 `std::move` 放入容器；移动语义下一单元展开。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 课堂任务 3：实现一个 RAII 缓冲区

---

<div class="cols">

<div class="col-55">

<div class="card">

<div class="card-title">任务</div>

实现 `Buffer` 类：

- 构造：`explicit Buffer(std::size_t n)`，申请 `n` 个 `int`，初始化为 0
- 析构：释放数组
- `int& at(std::size_t i)`：返回第 `i` 个元素
- `std::size_t size() const`
- 禁止拷贝构造与拷贝赋值（先禁止，下一单元再实现深拷贝）

在 `main` 中创建 `Buffer buf(5)`，写入 `1..5` 并打印。

</div>

</div>

<div class="col-45">

<div class="card">

<div class="card-title">验收标准</div>

- `valgrind` 或 ASan 无泄漏报告
- 不使用 `std::vector`
- 析构函数只释放一次
- 拷贝操作编译失败（说明 `= delete` 生效）
- 构造后所有元素为 0

</div>

<div class="tip">
<span class="label">提示</span>
<code>new int[n]{}</code> 会把元素值初始化为 0；<code>new int[n]</code> 不会。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 任务 3 参考实现

---

<div class="cols">

<div class="col-55 code-sm">

```cpp{.line-numbers}
#include <cstddef>
#include <iostream>

class Buffer {
public:
    explicit Buffer(std::size_t n)
        : data_(new int[n]{}), size_(n) {}

    ~Buffer() { delete[] data_; }

    Buffer(const Buffer&) = delete;
    Buffer& operator=(const Buffer&) = delete;

    int& at(std::size_t i) { return data_[i]; }
    const int& at(std::size_t i) const { return data_[i]; }
    std::size_t size() const { return size_; }

private:
    int* data_;
    std::size_t size_;
};

int main() {
    Buffer buf(5);
    for (std::size_t i = 0; i < buf.size(); ++i) {
        buf.at(i) = static_cast<int>(i + 1);
    }
    for (std::size_t i = 0; i < buf.size(); ++i) {
        std::cout << buf.at(i) << ' ';
    }
    std::cout << '\n';
}
```

</div>

<div class="col-45">

**输出**

<div class="out">1 2 3 4 5</div>

<div class="small mt1">

**要点**

- `new int[n]{}` 值初始化
- 析构函数 `delete[]` 与 `new[]` 配对
- `= delete` 让拷贝在编译期失败，避免双重释放
- 提供 `const` 版本的 `at`，常量对象也能读

</div>

<div class="tip">
<span class="label">下一步</span>
如果确实需要拷贝一个 <code>Buffer</code>，应该写深拷贝——这就是下一单元的拷贝构造与赋值。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 常见陷阱

---

<div class="cols">

<div class="col">

**构造相关**

- 忘记初始化成员 → 值不确定
- 初始化列表顺序与声明顺序不一致 → 未定义行为
- 在构造函数体里赋值，而不是初始化
- `Task t();` 声明了函数而非对象
- 构造函数抛异常后仍假设析构函数会执行

</div>

<div class="col">

**析构相关**

- 析构函数抛异常 → `std::terminate`
- `new[]` 配 `delete` → 未定义行为
- 析构函数中访问已销毁的成员对象
- 基类析构非虚，通过基类指针 `delete` → 派生类析构不执行（多态章节展开）
- 手动调用析构函数后又使用对象

</div>

</div>

<div class="pitfall">
<span class="label">经验法则</span>
一个类如果需要写析构函数，通常也需要认真考虑拷贝构造和拷贝赋值——这就是“三法则”，下一单元的主题。
</div>

---


<!-- slide data-notes="" -->

##### 课堂小测

---

1. 构造函数与普通成员函数相比，有哪些特殊规则？`Task t;` 与 `Task t();` 的区别是什么？

2. 为什么 `const` 成员和引用成员必须在初始化列表中初始化？

3. 成员对象的构造顺序由什么决定？下面代码的输出是什么？

```cpp
struct A { A(){std::cout<<"A";} ~A(){std::cout<<"~A";} };
struct B { A a; B(){std::cout<<"B";} ~B(){std::cout<<"~B";} };
int main() { B b; }
```

4. 为什么析构函数不应该抛出异常？构造函数抛出异常时，哪些对象会被析构？

---


<!-- slide data-notes="" -->

##### 小结：对象的一生要有始有终

---

<div class="cols">

<div class="col">

<div class="card">

<div class="card-title">生</div>

- 构造函数建立不变量
- 初始化列表是真正的初始化
- 就地初始化与委托构造减少重复

</div>

</div>

<div class="col">

<div class="card">

<div class="card-title">死</div>

- 析构函数释放对象持有的资源
- 成员/基类按逆序析构
- 默认析构只适合“成员自己会管理资源”的类

</div>

</div>

<div class="col">

<div class="card">

<div class="card-title">RAII</div>

- 资源获取即初始化
- 析构函数自动释放
- 这是智能指针、锁、文件对象的共同基础

</div>

</div>

</div>

<div class="motto mt1">
对象的价值在于<strong>把“资源的生灭”变成“对象的生灭”</strong>，让编译器替我们保证释放。
</div>

---


<!-- slide data-notes="" -->

#####

---

<div class="bottom20"></div>

<hr class="width50 center">

## 未完待续

---
