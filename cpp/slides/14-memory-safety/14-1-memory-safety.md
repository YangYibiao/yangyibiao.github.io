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

## 内存安全与智能指针

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](mailto:yangyibiao@nju.edu.cn)


<!-- slide data-notes="" -->

##### 本讲提纲

---

<div class="cols">

<div class="col">

**内存安全**

- 栈、堆、静态区
- 空间类问题：越界、空指针
- 时间类问题：UAF、double free、泄漏
- 未定义行为与检测工具

</div>

<div class="col">

**智能指针**

- 所有权模型
- `unique_ptr`：独占
- `shared_ptr`：共享
- `weak_ptr`：观察
- 循环引用与修复

</div>

</div>

<div class="keypoint">
<span class="label">本讲目标</span>
能够识别常见内存安全错误，并用 RAII + 智能指针把“谁负责释放”变成类型系统的一部分。
</div>

---


<!-- slide data-notes="" -->

##### 进程的内存分区

---

<div class="cols">

<div class="col-55">

<div class="mem">
<div class="mem-head">进程地址空间（示意，从高到低）</div>
<div class="mem-row"><span class="addr">高地址</span><span class="val">栈 stack：局部变量、函数调用帧，自动增长/收缩</span></div>
<div class="mem-row"><span class="addr">↓</span><span class="val">（空闲空间）</span></div>
<div class="mem-row"><span class="addr">↑</span><span class="val">堆 heap：new / malloc 动态分配，手动管理</span></div>
<div class="mem-row"><span class="addr">—</span><span class="val">全局/静态区：全局变量、静态成员</span></div>
<div class="mem-row"><span class="addr">—</span><span class="val">常量区：字符串字面量、const 全局</span></div>
<div class="mem-row"><span class="addr">低地址</span><span class="val">代码区：机器指令</span></div>
</div>

</div>

<div class="col-45">

<div class="card">

<div class="card-title">生命周期</div>

- 栈对象：作用域结束自动销毁
- 堆对象：`delete` 才销毁
- 全局/静态：程序开始到结束
- 字符串字面量：静态存储，只读

</div>

<div class="pitfall">
<span class="label">关键</span>
“指针存在”不等于“对象还活着”。内存安全问题的核心，是<strong>访问了不该访问或已经失效的内存</strong>。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 内存安全的定义

---

<div class="cols">

<div class="col">

<div class="card">

<div class="card-title">空间安全（spatial）</div>

对象还活着，但访问范围错了：

- 数组越界读/写
- 解引用空指针
- 访问未初始化内存
- 类型混淆

</div>

</div>

<div class="col">

<div class="card">

<div class="card-title">时间安全（temporal）</div>

对象已经失效，程序还在使用：

- 释放后使用（UAF）
- 重复释放（double free）
- 悬空指针/引用
- 内存泄漏

</div>

</div>

</div>

<div class="motto mt1">
内存安全 = 程序只能访问<strong>它拥有的、仍然有效的、在边界内的</strong>内存。
</div>

<div class="small muted center">
这两类问题经常组合出现：越界写破坏堆管理信息，随后导致释放时崩溃。
</div>

---


<!-- slide data-notes="" -->

##### 真实世界：内存错误的代价

---

<div class="cols">

<div class="col">

**CrowdStrike 事件（2024）**

- 一次配置更新导致约 850 万台 Windows 设备蓝屏
- 影响航空、银行、医院、酒店
- 预计损失数十亿美元

**OpenSSL Heartbleed（2014）**

- 心跳扩展缺少边界检查
- 攻击者可读取服务器进程内存
- 影响数百万 HTTPS 服务器

</div>

<div class="col">

<div class="card">

<div class="card-title">统计</div>

- 微软 MSRC：约 70% 的安全补丁针对内存安全问题
- Chrome：高/严重漏洞中约 70% 与内存管理有关
- C/C++ 赋予程序员直接控制内存的能力，也把责任交给了程序员

</div>

<div class="tip">
<span class="label">本讲的意义</span>
内存安全不是“考试里的偏题”，而是工业界最昂贵的一类缺陷。现代 C++ 的方向是：<strong>让正确做法成为默认做法</strong>。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 空间类问题一：数组越界

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
int a[3] = {1, 2, 3};

a[3] = 42;        // 越界写：未定义行为
int x = a[10];    // 越界读：未定义行为

char buf[8];
std::strcpy(buf, "this is too long");  // 溢出
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">后果</div>

- 覆盖相邻变量
- 破坏堆管理元数据
- 读到敏感数据
- 程序崩溃或“看起来正常”

</div>

<div class="pitfall">
<span class="label">为什么危险</span>
越界写可能不会立刻崩溃，而是悄悄破坏别的数据；问题在很久之后才暴露，极难定位。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 空间类问题二：空指针与未初始化

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
int* p = nullptr;
*p = 42;              // 空指针解引用

int* q;               // 未初始化（野指针）
*q = 42;              // 指向随机地址

int x;                // 未初始化
if (x > 0) { ... }    // 读取未定义值
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">防御</div>

- 指针定义时初始化为 `nullptr`
- 使用前检查非空
- 变量定义时初始化
- 用引用表达“必不为空”
- 开启编译警告 `-Wuninitialized`

</div>

<div class="tip">
<span class="label">现代 C++</span>
<code>nullptr</code> 代替 <code>NULL</code> / <code>0</code>，避免与整数重载混淆；<code>std::optional</code> 表达“可能没有值”。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 时间类问题一：释放后使用（UAF）

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
int* p = new int(42);
delete p;

std::cout << *p;   // UAF：读取已释放内存
*p = 7;            // UAF：写入已释放内存
```

更隐蔽的版本：

```cpp
Task* t = new Task(1, "A", 2);
delete t;
t->print();        // 对象已销毁，虚表指针可能已失效
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">为什么难发现</div>

- 释放后的内存可能还没被复用，读到的仍是旧值
- 程序可能“正常运行”很久
- 在多线程下时序变化，偶发崩溃

</div>

<div class="pitfall">
<span class="label">CWE-416</span>
Use After Free 是浏览器、内核、字体解析器等的高危漏洞来源。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 时间类问题二：重复释放与悬空指针

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
int* p = new int(1);
delete p;
delete p;          // double free：未定义行为
```

```cpp
int* p = new int(2);
int* q = p;
delete p;
*p = 3;            // p 悬空
*q = 4;            // q 也悬空
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">悬空指针的来源</div>

- `delete` 后未置空
- 指向局部变量的指针逃逸出作用域
- 容器扩容后旧迭代器/指针失效
- 对象被移动后源对象被继续使用

</div>

<div class="tip">
<span class="label">习惯</span>
<code>delete p;</code> 后立即 <code>p = nullptr;</code> 只能防止“再次 delete”，不能防止其他别名指针悬空；根本方案是明确所有权。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 时间类问题三：内存泄漏

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
void leak() {
    int* p = new int(10);
    // 忘记 delete
}

void early_return(bool bad) {
    Task* t = new Task(1, "A", 1);
    if (bad) return;   // 提前返回，泄漏
    delete t;
}

void exception_path() {
    Task* t = new Task(1, "A", 1);
    may_throw();       // 抛异常，delete 执行不到
    delete t;
}
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">泄漏的代价</div>

- 长时间运行的服务内存持续增长
- 最终 OOM 或被系统杀死
- 嵌入式/移动设备资源有限

</div>

<div class="pitfall">
<span class="label">最容易漏的路径</span>
提前 <code>return</code>、异常、循环中的 <code>continue</code> / <code>break</code>。手动管理资源的代码，每条路径都要记得释放。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 悬空指针：返回局部变量的地址

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
int* bad() {
    int x = 5;
    return &x;     // 函数返回后 x 已销毁
}

int& bad_ref() {
    int x = 5;
    return x;      // 悬空引用
}

int main() {
    int* p = bad();
    std::cout << *p;   // 未定义行为
}
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">正确做法</div>

- 返回值（拷贝/移动）
- 返回 `std::unique_ptr` / `std::shared_ptr`
- 由调用方传入输出参数
- 确保对象生命周期长于指针

</div>

<div class="tip">
<span class="label">编译器警告</span>
<code>-Wreturn-local-addr</code> 能发现直接返回局部变量地址；但通过指针间接逃逸的情况仍需人工审查。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 未定义行为：编译器可以做任何事

---

<div class="cols">

<div class="col">

**UB 不是“结果随机”**

```cpp
int a[3];
a[3] = 1;          // UB

int x;
if (x > 0) ...     // UB

int* p = nullptr;
*p = 1;            // UB
```

编译器可以假设 UB 不会发生，从而做出激进的优化。

</div>

<div class="col">

<div class="card">

<div class="card-title">常见后果</div>

- 删除整段“不可能执行”的代码
- 循环被优化成死循环
- 变量被寄存器缓存，读写顺序改变
- 在不同编译器/优化级别下表现不同

</div>

<div class="pitfall">
<span class="label">重要</span>
“在我的机器上能跑”不能证明程序正确。UB 的代码没有可依赖的语义。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 防御体系：不要只靠“小心”

---

<div class="table-sm">

| 层次 | 手段 | 作用 |
| :-- | :-- | :-- |
| 编码规范 | 初始化、RAII、避免裸 `new` | 从源头减少错误 |
| 静态分析 | 编译器警告、clang-tidy、Coverity | 编译期发现问题 |
| 动态检测 | ASan、UBSan、Valgrind | 运行时捕获越界/UAF/泄漏 |
| 语言机制 | 智能指针、容器、`std::span` | 让正确做法更容易 |
| 运行环境 | 沙箱、ASLR、硬件标签 | 限制漏洞影响 |

</div>

<div class="keypoint mt1">
<span class="label">组合使用</span>
没有任何单一手段能解决所有内存安全问题；工程上采用“预防 + 检测 + 隔离”的分层防御。
</div>

---


<!-- slide data-notes="" -->

##### AddressSanitizer：让错误现场暴露

---

<div class="cols">

<div class="col-55">

```bash
g++ -std=c++17 -g \
  -fsanitize=address,undefined \
  main.cpp -o main
./main
```

```text
==12345==ERROR: AddressSanitizer:
heap-use-after-free on address 0x602000...
READ of size 4 at 0x602000...
    #0 main main.cpp:5
freed by thread T0 here:
    #0 operator delete
    #1 main main.cpp:4
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">能发现什么</div>

- 堆/栈/全局越界
- use-after-free
- double-free
- 内存泄漏（LeakSanitizer）
- 未定义行为（UBSan）

</div>

<div class="tip">
<span class="label">使用建议</span>
开发与测试阶段默认开启；性能测试和发布版本关闭。Sanitizer 报告要当作真实缺陷处理，不能忽略。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 所有权：谁负责 delete？

---

<div class="cols">

<div class="col">

**裸指针的问题**

```cpp
Task* create();
void use(Task* t);
void destroy(Task* t);
```

仅看类型，无法知道：

- 谁拥有对象？
- 调用 `use` 后对象是否还有效？
- 谁应该调用 `destroy`？
- 能否复制这个指针？

</div>

<div class="col">

<div class="card">

<div class="card-title">所有权模型</div>

- **独占**：同一时刻只有一个所有者 → `unique_ptr`
- **共享**：多个所有者共同延长生命周期 → `shared_ptr`
- **观察**：不拥有，只观察是否还活着 → `weak_ptr` / 裸指针 / 引用

</div>

<div class="keypoint">
<span class="label">目标</span>
把“谁负责释放”从注释和口头约定，变成<strong>类型系统的一部分</strong>。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### `unique_ptr`：独占所有权

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
#include <memory>

auto p = std::make_unique<Task>(1, "写作业", 2);
p->complete();
p->print();

// p 离开作用域时自动 delete
```

```cpp
std::unique_ptr<Task> q(new Task(2, "复习", 3));
// 不推荐直接 new；make_unique 更安全
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">特点</div>

- 同一时刻只有一个 `unique_ptr` 拥有对象
- 不能拷贝，只能移动
- 大小通常与裸指针相同
- 析构时自动 `delete`
- 支持多态：`unique_ptr<Task>` 可持有派生类对象

</div>

<div class="tip">
<span class="label">make_unique</span>
<code>std::make_unique&lt;T&gt;(args...)</code> 把分配与构造放在一个表达式里，避免裸指针短暂暴露。C++14 起可用。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 移动所有权

---

<div class="cols">

<div class="col-55">

```cpp
auto p = std::make_unique<Task>(1, "A", 1);

// auto q = p;              // 错误：不能拷贝
auto q = std::move(p);      // 所有权转移

if (!p) {
    std::cout << "p is empty\n";
}
```

```cpp
std::unique_ptr<Task> make_task() {
    return std::make_unique<Task>(1, "A", 1);
}

auto t = make_task();   // 移动（或省略）
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">规则</div>

- 移动后源指针变为 `nullptr`
- 不要继续解引用源指针
- 函数返回 `unique_ptr` 表示“把所有权交给调用方”
- 函数参数 `unique_ptr<T>` 表示“接管所有权”
- 参数 `T*` / `T&` 表示“只借用，不拥有”

</div>

<div class="pitfall">
<span class="label">接口语义</span>
看到 <code>unique_ptr&lt;T&gt;</code> 参数，调用方必须 <code>std::move</code>，这明确表达了“我把对象交给你了”。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### `unique_ptr` 与容器、多态

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
std::vector<std::unique_ptr<Task>> tasks;

tasks.push_back(
    std::make_unique<PrintTask>("hello"));
tasks.push_back(
    std::make_unique<RecurringTask>("背单词", 3));

for (const auto& t : tasks) {
    t->run();          // 动态绑定
}
// 容器销毁时，每个 unique_ptr 自动 delete
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">为什么好用</div>

- 容器拥有元素，元素生命周期明确
- 多态对象通过基类指针统一管理
- 不需要手写析构循环
- 不会误拷贝导致双重释放

</div>

<div class="pitfall">
<span class="label">前提</span>
基类必须有<strong>虚析构函数</strong>，否则通过 <code>unique_ptr&lt;Task&gt;</code> 删除派生对象时，派生类析构不会执行。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### `shared_ptr`：共享所有权

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
auto a = std::make_shared<Task>(1, "A", 1);
auto b = a;              // 引用计数 2
auto c = b;              // 引用计数 3

std::cout << a.use_count();   // 3

b.reset();               // 引用计数 2
c.reset();               // 引用计数 1
// a 离开作用域 -> 计数 0 -> delete
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">引用计数</div>

- 每个对象关联一个控制块，记录 `shared_ptr` 数量
- 拷贝 +1，析构/重置 -1
- 计数归零时销毁对象
- 多个线程各自持有/拷贝**不同的** `shared_ptr` 实例（共享同一控制块）是安全的；并发读写**同一个** `shared_ptr` 对象仍需同步

</div>

<div class="tip">
<span class="label">make_shared</span>
<code>std::make_shared&lt;T&gt;(...)</code> 一次分配对象 + 控制块，通常比 <code>shared_ptr&lt;T&gt;(new T)</code> 更高效。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### `shared_ptr` 的经典错误

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
int* raw = new int(5);

std::shared_ptr<int> a(raw);   // 计数 1
{
    std::shared_ptr<int> b(raw); // 另一个计数 1！
}                               // b 析构 -> delete raw

std::cout << *a;   // UAF
// a 析构 -> 再次 delete -> double free
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">规则</div>

- 不要用同一个裸指针构造多个 `shared_ptr`
- 需要共享时，拷贝已有的 `shared_ptr`
- 从函数返回 `shared_ptr`，而不是返回裸指针再包装
- 优先 `make_shared`

</div>

<div class="pitfall">
<span class="label">本质</span>
每个 <code>shared_ptr</code> 独立维护控制块；两个控制块都以为自己拥有对象，最终各自 delete 一次。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 循环引用：引用计数不是万能 GC

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
struct Node {
    std::shared_ptr<Node> next;
    std::shared_ptr<Node> prev;   // 循环！
};

auto a = std::make_shared<Node>();
auto b = std::make_shared<Node>();
a->next = b;    // b 计数 2
b->prev = a;    // a 计数 2

a.reset();      // a 计数 1
b.reset();      // b 计数 1
// 两个对象互相引用，计数永远不为 0
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">问题</div>

- 对象已经不可达，但引用计数仍大于 0
- 内存永远不释放
- 链表、树、图、观察者模式中常见

</div>

<div class="keypoint">
<span class="label">修复</span>
把其中一个方向改为 <code>std::weak_ptr</code>：观察者不增加引用计数，打破循环。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### `weak_ptr`：只观察，不拥有

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
struct Node {
    std::shared_ptr<Node> next;
    std::weak_ptr<Node> prev;   // 不增加计数
};

auto a = std::make_shared<Node>();
auto b = std::make_shared<Node>();
a->next = b;
b->prev = a;     // weak，不增加 a 的计数

std::weak_ptr<Node> w = a;
if (auto s = w.lock()) {   // 升级为 shared_ptr
    // 对象仍然存活
} else {
    // 对象已销毁
}
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">API</div>

- `lock()`：返回 `shared_ptr`，失败返回空
- `expired()`：对象是否已销毁
- `use_count()`：当前共享计数
- `reset()`：放弃观察

</div>

<div class="tip">
<span class="label">所有权表达</span>
<code>shared_ptr</code> 表示“我拥有”，<code>weak_ptr</code> 表示“我观察但不延长生命周期”。观察者模式、缓存、父子引用常用。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 自定义删除器与数组

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
// 文件指针：需要 fclose 而不是 delete
auto deleter = [](std::FILE* f) {
    if (f) std::fclose(f);
};
std::unique_ptr<std::FILE, decltype(deleter)>
    file(std::fopen("data.txt", "r"), deleter);

// 动态数组
std::unique_ptr<int[]> arr(new int[10]);
arr[0] = 42;
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">要点</div>

- `unique_ptr<T, Deleter>` 可以管理任意资源
- 删除器是类型的一部分
- 数组用 `unique_ptr<T[]>`，自动 `delete[]`
- `shared_ptr` 也支持自定义删除器

</div>

<div class="small muted mt1">
大多数情况下不需要自定义删除器：文件用 <code>std::fstream</code>，锁用 <code>std::lock_guard</code>，容器用标准容器。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 主线案例：用 `unique_ptr` 管理任务

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
class TaskList {
public:
    void add(std::unique_ptr<Task> task) {
        tasks_.push_back(std::move(task));
    }

    void run_all() const {
        for (const auto& t : tasks_) {
            t->run();
        }
    }

    std::size_t size() const { return tasks_.size(); }

private:
    std::vector<std::unique_ptr<Task>> tasks_;
};

TaskList list;
list.add(std::make_unique<PrintTask>("hello"));
list.add(std::make_unique<RecurringTask>("背单词", 3));
list.run_all();
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">所有权链</div>

`TaskList` → `vector` → `unique_ptr<Task>` → 具体任务对象

- `TaskList` 拥有任务
- 容器析构时逐个 `delete`
- 任务对象通过虚析构正确销毁
- 调用方通过 `std::move` 明确移交所有权

</div>

<div class="tip">
<span class="label">对比裸指针版</span>
不需要写 <code>~TaskList() { for (...) delete p; }</code>；不会因为提前 <code>return</code> 或异常而泄漏。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 课堂任务 14：把泄漏的程序改成智能指针

---

<div class="cols">

<div class="col-55">

<div class="card">

<div class="card-title">任务</div>

下面这段代码存在泄漏与潜在 UAF：

```cpp
class TaskList {
public:
    void add(Task* t) { tasks_.push_back(t); }
    ~TaskList() { /* 没有 delete */ }
private:
    std::vector<Task*> tasks_;
};
```

改造为：

1. `std::vector<std::unique_ptr<Task>>`
2. `add(std::unique_ptr<Task>)`，用 `std::move` 放入
3. 删除手写析构函数
4. 增加 `run_all()`，通过基类指针调用 `run()`
5. 用 ASan 验证无泄漏、无 UAF

</div>

</div>

<div class="col-45">

<div class="card">

<div class="card-title">验收标准</div>

- `TaskList` 析构后 ASan 无泄漏报告
- 不能从 `TaskList` 外部删除任务
- 新增任务类型不需要修改 `TaskList`
- 基类 `Task` 有虚析构函数
- 不使用裸 `new` / `delete`

</div>

<div class="tip">
<span class="label">提示</span>
<code>add</code> 的签名改为 <code>void add(std::unique_ptr&lt;Task&gt; task)</code>；调用方用 <code>std::make_unique</code> 构造，<code>std::move</code> 传入。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 任务 14 参考实现

---

<div class="cols">

<div class="col-55 code-sm">

```cpp{.line-numbers}
#include <memory>
#include <utility>
#include <vector>
// 假设 Task/PrintTask/RecurringTask 已定义

class TaskList {
public:
    void add(std::unique_ptr<Task> task) {
        tasks_.push_back(std::move(task));
    }

    void run_all() const {
        for (const auto& t : tasks_) {
            t->run();
        }
    }

    std::size_t size() const {
        return tasks_.size();
    }

private:
    std::vector<std::unique_ptr<Task>> tasks_;
};

int main() {
    TaskList list;
    list.add(std::make_unique<PrintTask>("hello"));
    list.add(std::make_unique<RecurringTask>("背单词", 3));
    list.run_all();
}
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">要点</div>

- `unique_ptr` 独占所有权
- `std::move` 明确移交
- `vector` 析构自动释放所有任务
- `Task` 的虚析构保证派生类析构执行
- ASan 验证：`g++ -fsanitize=address`

</div>

<div class="pitfall">
<span class="label">不要</span>
在 <code>TaskList</code> 外部保存任务的裸指针并继续使用；对象生命周期由 <code>TaskList</code> 拥有，外部只能“借用”。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 常见陷阱

---

<div class="cols">

<div class="col">

**裸指针/资源**

- `delete` 后继续使用
- 同一指针 delete 两次
- 返回局部变量地址/引用
- 异常路径忘记释放
- 数组与标量 delete 混用

</div>

<div class="col">

**智能指针**

- 用同一裸指针构造多个 `shared_ptr`
- `shared_ptr` 循环引用
- `unique_ptr` 拷贝（编译错误）
- `std::move` 后继续使用源指针
- 基类析构非虚，`unique_ptr<Base>` 删除派生对象
- 过度使用 `shared_ptr`（所有权不清晰）

</div>

</div>

<div class="pitfall">
<span class="label">选择顺序</span>
栈对象/值语义 → <code>unique_ptr</code> → <code>shared_ptr</code> → 裸指针（仅借用）。<code>shared_ptr</code> 不是默认选择。
</div>

---


<!-- slide data-notes="" -->

##### 课堂小测

---

1. 空间类与时间类内存安全问题各举两个例子。为什么“程序没崩溃”不能证明没有内存错误？

2. `unique_ptr` 为什么不能拷贝？如何转移所有权？

3. `shared_ptr` 的引用计数如何变化？什么情况下会导致循环引用？

4. `weak_ptr` 的 `lock()` 做了什么？为什么它能打破循环引用？

---


<!-- slide data-notes="" -->

##### 小结：让所有权可见

---

<div class="cols">

<div class="col">

<div class="card">

<div class="card-title">问题</div>

- 越界、空指针、未初始化
- UAF、double free、悬空、泄漏
- UB 让错误难以预测

</div>

</div>

<div class="col">

<div class="card">

<div class="card-title">工具</div>

- 编译警告 + 静态分析
- ASan / UBSan / Valgrind
- RAII + 容器 + 智能指针

</div>

</div>

<div class="col">

<div class="card">

<div class="card-title">所有权</div>

- `unique_ptr`：独占
- `shared_ptr`：共享
- `weak_ptr`：观察
- 裸指针/引用：借用

</div>

</div>

</div>

<div class="motto mt1">
内存安全的核心不是“记得 delete”，而是<strong>让每个对象都有明确的所有者，并让类型系统替你检查</strong>。
</div>

---


<!-- slide data-notes="" -->

#####

---

<div class="bottom20"></div>

<hr class="width50 center">

## 未完待续

---
