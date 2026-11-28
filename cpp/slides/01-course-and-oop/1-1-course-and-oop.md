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

## 课程概述与面向对象全景

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](mailto:yangyibiao@nju.edu.cn)


<!-- slide data-notes="" -->

##### 本讲提纲

---

<div class="cols">

<div class="col">

**课程**

- 课程定位与知识地图
- 工具链与代码规范
- 主线案例：TaskFlow 任务管理器

</div>

<div class="col">

**从 C 到 C++**

- 过程抽象与数据抽象
- 封装、类与对象
- 面向对象四大特征

</div>

</div>

<div class="keypoint">
<span class="label">本讲目标</span>
能够说清楚“为什么需要类”，并写出第一个带封装的任务类。
</div>

---


<!-- slide data-notes="" -->

##### 这门课解决什么问题？

---

<div class="cols">

<div class="col-55">

在前置课程中，我们已经能写出**能运行**的程序：

- 变量、表达式、分支、循环
- 函数、数组、指针、结构体
- 递归、链表、文件操作

但一旦程序规模变大，新的问题出现了：

- 数据和对数据的操作**分散**在程序各处
- 修改一个结构体，要改动许多函数
- 多人协作时，**边界**不清晰
- 动态资源该由谁释放，说不清楚

</div>

<div class="col-45">

<div class="card">

<div class="card-title">从“写代码”到“设计程序”</div>

<div class="flow" style="flex-direction:column;width:100%;margin:0;">

<div class="flow-step"><strong>会写语句</strong>语法与流程控制</div>
<div class="flow-step"><strong>会组织代码</strong>函数、结构、模块</div>
<div class="flow-step"><strong>会设计抽象</strong>类、接口、对象协作</div>

</div>

</div>

</div>

</div>

<div class="keypoint">
<span class="label">课程定位</span>
不是“再学一门语法”，而是学习<strong>组织复杂程序</strong>的方法：抽象、封装、复用、资源安全与并发。
</div>

---


<!-- slide data-notes="" -->

##### 课程知识地图：四条主线

---

<div class="flow">
<div class="flow-step"><strong>面向对象</strong>抽象与封装<br>类 / 对象<br>继承 / 多态</div>
<div class="flow-arrow">→</div>
<div class="flow-step"><strong>泛型与 STL</strong>函数模板<br>类模板<br>容器 / 算法</div>
<div class="flow-arrow">→</div>
<div class="flow-step"><strong>资源与安全</strong>对象生命周期<br>RAII / 智能指针<br>内存安全</div>
<div class="flow-arrow">→</div>
<div class="flow-step"><strong>并发与范式</strong>线程 / 同步<br>声明式编程<br>工程实践</div>
</div>

<div class="cols mt1">

<div class="col">

<div class="card">

<div class="card-title">基础层</div>

- 类与对象、构造与析构
- 拷贝、赋值、移动
- 继承、多态、接口

</div>

</div>

<div class="col">

<div class="card">

<div class="card-title">进阶层</div>

- 模板、STL、Lambda
- 异常、断言、调试
- 智能指针、内存安全

</div>

</div>

<div class="col">

<div class="card">

<div class="card-title">综合层</div>

- 多线程与同步
- 声明式与函数式
- 课程项目

</div>

</div>

</div>

<div class="tip">
<span class="label">学习方式</span>
每章围绕一个<strong>设计问题</strong>展开：先看传统写法哪里痛，再看 C++ 机制如何解决，最后落到可运行的代码。
</div>

---


<!-- slide data-notes="" -->

##### 先修知识自检

---

<div class="cols">

<div class="col">

**应该已经掌握**

- 基本类型、运算符、表达式
- `if` / `switch` / `for` / `while`
- 函数定义、声明、参数传递
- 数组、指针、引用
- `struct`、枚举、`typedef`
- 动态内存 `malloc/free`
- 多文件编译与头文件

</div>

<div class="col">

**本课程会反复用到**

```cpp
struct Point { int x, y; };

void move(Point& p, int dx, int dy) {
    p.x += dx;
    p.y += dy;
}

int main() {
    Point p{1, 2};
    move(p, 3, 4);
    std::cout << p.x << "," << p.y << "\n";
}
```

<div class="xsmall muted mt1">
若对“引用参数”“指针与数组”“结构体”不熟，先复习前置课程对应章节。
</div>

</div>

</div>

<div class="question">
<span class="label">自检</span>
`Point& p` 与 `Point p` 作为参数，调用时分别发生了什么？为什么修改 `p.x` 能影响实参？
</div>

---


<!-- slide data-notes="" -->

##### 工具链：本课程使用的 C++ 标准与环境

---

<div class="cols">

<div class="col-55">

**编译器**

```bash
g++ --version          # GCC 11+ 或 Clang 14+
g++ -std=c++17 -Wall -Wextra -O2 main.cpp -o main
```

**推荐标准**

| 标准 | 关键能力 | 本课程使用 |
| :-- | :-- | :-- |
| C++11 | 移动语义、Lambda、`auto`、智能指针 | 大量 |
| C++14 | 泛型 Lambda、变量模板 | 少量 |
| C++17 | 结构化绑定、`optional`、`filesystem` | 常用 |
| C++20 | Ranges、概念、协程 | 选讲 |

</div>

<div class="col-45">

**开发环境**

- 编辑器：VS Code + C/C++ 插件
- 构建：命令行 `g++`，后续可用 CMake
- 调试：`gdb` / `lldb`，VS Code 断点
- 检查：`-fsanitize=address,undefined`

```bash
g++ -std=c++17 -g \
  -fsanitize=address,undefined \
  main.cpp -o main
```

<div class="tip">
<span class="label">约定</span>
课件中的 <span class="std cxx11">C++11</span> 等标记表示该特性首次可用的标准；未标记的代码默认按 C++17 编译。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 第一个 C++ 程序：从 `printf` 到 `iostream`

---

<div class="cols">

<div class="col code-sm">

**C 风格**

```c
#include <stdio.h>

int main(void) {
    int age = 19;
    printf("age = %d\n", age);
    return 0;
}
```

<div class="xsmall muted">
格式串与参数类型分离，类型不匹配时编译器无法检查。
</div>

</div>

<div class="col code-sm">

**C++ 风格** <span class="std cxx98">C++98</span>

```cpp
#include <iostream>

int main() {
    int age = 19;
    std::cout << "age = " << age << '\n';
    return 0;
}
```

<div class="xsmall muted">
`<<` 根据实参类型选择输出方式，类型安全、可扩展。
</div>

</div>

</div>

<div class="keypoint">
<span class="label">关键差异</span>
`std::cout` 是<strong>对象</strong>，`<<` 是<strong>被重载的运算符</strong>。I/O 在 C++ 中以对象和运算符的形式提供，这正是“用类型系统表达意图”的第一个例子。
</div>

<div class="question">
<span class="label">思考</span>
为什么 C++ 不直接沿用 `printf`？如何输出一个自定义的 `Task` 对象？
</div>

---


<!-- slide data-notes="" -->

##### C++ 不只是“带类的 C”

---

<div class="cols">

<div class="col">

<div class="card">

<div class="card-title">四个核心能力</div>

- **抽象**：只暴露“做什么”
- **封装**：隐藏“怎么做”，保护数据
- **继承**：复用已有类型，建立 is-a 关系
- **多态**：同一接口，不同实现

</div>

</div>

<div class="col">

<div class="card">

<div class="card-title">两类工程能力</div>

- **泛型**：一套代码适配多种类型
- **资源管理**：对象生命周期与资源绑定
- **异常安全**：出错时也不泄漏
- **并发**：把任务交给多个线程

</div>

</div>

</div>

<div class="motto">
“C++ 的设计目标：你不需要为你没有使用的东西付出代价。”
</div>

<div class="small muted center">
本课程不会罗列所有语法；每引入一个机制，都先回答三个问题：<br>
它解决什么问题？代价是什么？什么时候不该用？
</div>

---


<!-- slide data-notes="" -->

##### 主线案例：TaskFlow 任务管理器

---

<div class="cols">

<div class="col-55">

**需求（逐步扩展）**

1. 表示一个任务：编号、标题、优先级、是否完成
2. 管理一组任务：添加、删除、查找、统计
3. 支持不同类型的任务：普通任务、截止日期任务、周期任务
4. 按优先级调度执行
5. 把任务保存到文件、从文件恢复
6. 多线程并行执行任务
7. 用声明式风格筛选、排序、统计

</div>

<div class="col-45">

<div class="card">

<div class="card-title">为什么选这个案例</div>

- 贴近学生日常：作业、DDL、复习计划
- 能自然长成继承体系与接口
- 能承载 STL、智能指针、并发
- 规模可控，不需要图形界面

</div>

<div class="tip">
<span class="label">使用方式</span>
每章只扩展一小步。案例不是“一次性大作业”，而是贯穿知识点的<strong>连续实验对象</strong>。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 第一版：用 C 的结构体与函数管理任务

---

<div class="code-pane code-xs">
<div class="code-label"><span>C 风格 · 数据与操作分离</span><span class="tag">task.c</span></div>

```c
#include <stdio.h>
#include <string.h>

struct Task {
    int id;
    char title[32];
    int priority;
    int done;
};

void task_add(struct Task tasks[], int *n, int id,
              const char *title, int priority) {
    tasks[*n].id = id;
    strncpy(tasks[*n].title, title, 31);
    tasks[*n].title[31] = '\0';
    tasks[*n].priority = priority;
    tasks[*n].done = 0;
    (*n)++;
}

void task_complete(struct Task *t) { t->done = 1; }

void task_print(const struct Task *t) {
    printf("[%d] %s (p=%d) %s\n",
           t->id, t->title, t->priority,
           t->done ? "done" : "todo");
}
```

</div>

---


<!-- slide data-notes="" -->

##### 问题暴露：谁都可以改，谁都不负责

---

<div class="cols">

<div class="col">

**调用方可以随意破坏不变量**

```c
struct Task t;
t.id = 1;
strcpy(t.title, "写作业");
t.priority = 2;
t.done = 0;

/* 忘记初始化？ */
struct Task u;
task_print(&u);      /* 未定义行为 */

/* 误操作？ */
t.id = -1;
t.priority = 999;
t.done = 7;          /* 语义上只应是 0/1 */
```

</div>

<div class="col">

<div class="card">

<div class="card-title">四个具体问题</div>

1. **表示暴露**：字段可被任意读写
2. **不变量失守**：`id > 0`、`priority ∈ [1,5]` 无人保证
3. **操作分散**：新增一种任务要改多处
4. **复用困难**：换一种存储结构，所有调用方都要改

</div>

</div>

</div>

<div class="pitfall">
<span class="label">本质</span>
数据与操作分离，导致“数据的所有者”缺位。程序规模越大，维护者越难知道<strong>哪些代码有资格修改这个数据</strong>。
</div>

---


<!-- slide data-notes="" -->

##### 过程抽象：先给操作一个名字

---

<div class="cols">

<div class="col-55 code-sm">

**用函数封装“怎么做”**

```c
void task_add(struct Task tasks[], int *n, ...);
void task_complete(struct Task *t);
void task_print(const struct Task *t);
int  task_count_done(const struct Task tasks[], int n);
```

调用方只需要知道**函数名、参数、返回值**，不需要知道内部如何实现。

```c
struct Task tasks[100];
int n = 0;
task_add(tasks, &n, 1, "写作业", 2);
task_complete(&tasks[0]);
task_print(&tasks[0]);
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">过程抽象解决了什么</div>

- 操作有了名字，意图更清晰
- 实现可以修改，调用方不变
- 消除了重复代码

</div>

<div class="card mt1">

<div class="card-title">还没有解决什么</div>

- 数据仍然是公开的：`tasks[0].id = -1` 仍合法
- 数据与操作仍是两套东西，无法保证添加时一定走 `task_add`

</div>

</div>

</div>

<div class="question">
<span class="label">追问</span>
如果数据表示从数组换成链表，`task_add` 的签名还能保持不变吗？调用方需要知道 `struct Task` 的内部布局吗？
</div>

---


<!-- slide data-notes="" -->

##### 数据抽象：只描述“能做什么”

---

<div class="cols">

<div class="col">

**栈的抽象视图**

- `push(x)`：把 `x` 放到栈顶
- `pop()`：取出栈顶元素
- `empty()`：栈是否为空

满足：`push(a); ...; pop() == a`（后进先出）

使用者**不需要知道**：

- 用数组还是链表
- 容量多大
- 栈顶指针叫什么

</div>

<div class="col">

<div class="card">

<div class="card-title">数据抽象的核心</div>

把“数据表示”和“可实施的操作”分开描述：

- 对外：操作的名字与语义
- 对内：数据如何存储、算法如何实现

<div class="mt1 small">
数据抽象是<strong>看问题的角度</strong>；封装是<strong>落实这个角度的机制</strong>。
</div>

</div>

</div>

</div>

<div class="motto">
使用者只看见“栈能做什么”，看不见“栈是怎么做的”。
</div>

---


<!-- slide data-notes="" -->

##### 封装的第一次尝试：`struct` + 函数仍然不够

---

<div class="cols">

<div class="col">

**数组版**

```c
struct Stack {
    int top;
    int buffer[100];
};

void push(struct Stack *s, int x);
int  pop(struct Stack *s);
```

```c
struct Stack s;
s.top = -1;
push(&s, 12);
s.top--;        /* 误操作，编译器不报错 */
```

</div>

<div class="col">

**链表版**

```c
struct Stack {
    struct Node *top;
};

void push(struct Stack *s, int x);
int  pop(struct Stack *s);
```

```c
struct Stack s;
s.top = NULL;
push(&s, 12);
s.top = NULL;   /* 直接清空，泄漏所有结点 */
```

</div>

</div>

<div class="pitfall">
<span class="label">问题</span>
两种实现都把 `top` 暴露在结构体外。函数封装了操作，却<strong>没有封装数据</strong>；使用者仍能绕过函数直接改状态。
</div>

---


<!-- slide data-notes="" -->

##### 用类把数据和操作装在一起

---

<div class="cols">

<div class="col-55 code-xs">

```cpp
class Stack {
public:
    Stack() = default;

    void push(int x) {
        if (top_ == kCapacity) return;   // 简化：满则忽略
        data_[top_++] = x;
    }

    int pop() {
        if (top_ == 0) return -1;        // 简化：空返回 -1
        return data_[--top_];
    }

    bool empty() const { return top_ == 0; }

private:
    static constexpr int kCapacity = 100;
    int data_[kCapacity]{};
    int top_ = 0;
};
```

</div>

<div class="col-45">

**使用者只能通过接口操作**

```cpp
Stack s;
s.push(12);
s.push(34);
int x = s.pop();     // 34
bool e = s.empty();  // false

// s.top_ = -1;      // 编译错误
// s.data_[0] = 9;   // 编译错误
```

<div class="keypoint">
<span class="label">封装</span>
`public` 构成<strong>接口</strong>，`private` 构成<strong>实现</strong>。编译器强制调用方走接口，不变量才有机会被守住。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 封装的价值：换实现，调用方不变

---

<div class="cols">

<div class="col code-sm">

**数组实现**

```cpp
class Stack {
public:
    void push(int x);
    int pop();
    bool empty() const;
private:
    int data_[100]{};
    int top_ = 0;
};
```

```cpp
Stack s;
s.push(1);
s.push(2);
int x = s.pop();
```

</div>

<div class="col code-sm">

**链表实现**

```cpp
class Stack {
public:
    void push(int x);
    int pop();
    bool empty() const;
private:
    struct Node { int value; Node* next; };
    Node* top_ = nullptr;
};
```

```cpp
Stack s;
s.push(1);
s.push(2);
int x = s.pop();
```

</div>

</div>

<div class="keypoint">
<span class="label">结果</span>
数据表示完全改变，<strong>调用方一行都不用改</strong>。这就是封装带来的可维护性与可替换性。
</div>

<div class="xsmall muted center">
代价：多了一层间接；接口设计不好时，反而会限制实现。封装不是“把所有东西都藏起来”，而是“只暴露稳定的部分”。
</div>

---


<!-- slide data-notes="" -->

##### 类与对象：静态的规则，动态的实体

---

<div class="cols">

<div class="col-50">

**类（class）**

- 属于**类型**范畴
- 存在于编译时刻
- 描述对象有哪些数据、能做什么
- 是创建对象的“模具”

```cpp
class Task {
    // 数据成员 + 成员函数
};
```

</div>

<div class="col-50">

**对象（object）**

- 属于**值**范畴
- 存在于运行时刻
- 拥有独立的状态
- 通过类来创建

```cpp
Task t1(1, "写作业", 2);
Task t2(2, "复习", 3);
// t1 与 t2 是两块独立的内存
```

</div>

</div>

<div class="mem mt1" style="width:60%;margin-left:auto;margin-right:auto;">
<div class="mem-head">两个 Task 对象（示意）</div>
<div class="mem-row"><span class="addr">t1</span><span class="val">id=1 &nbsp; title="写作业" &nbsp; priority=2 &nbsp; done=false</span></div>
<div class="mem-row"><span class="addr">t2</span><span class="val">id=2 &nbsp; title="复习" &nbsp; &nbsp; priority=3 &nbsp; done=false</span></div>
</div>

<div class="small muted center mt1">
类只有一份定义；对象可以有很多个，各自持有自己的数据。
</div>

---


<!-- slide data-notes="" -->

##### 对象 = 状态 + 行为 + 标识

---

<div class="cds">

<div class="cls blue">
<div class="cls-title">Task</div>
<div class="cls-body">
<div><span class="fn">- id_ : int</span></div>
<div><span class="fn">- title_ : string</span></div>
<div><span class="fn">- priority_ : int</span></div>
<div><span class="fn">- done_ : bool</span></div>
<div class="sep"></div>
<div><span class="fn">+ complete() : void</span></div>
<div><span class="fn">+ print() const : void</span></div>
<div><span class="fn">+ is_done() const : bool</span></div>
</div>
</div>

<div class="cls green">
<div class="cls-title">对象 t1</div>
<div class="cls-body">
<div>id_ = 1</div>
<div>title_ = "写作业"</div>
<div>priority_ = 2</div>
<div>done_ = false</div>
<div class="sep"></div>
<div class="fn">行为由类共享</div>
</div>
</div>

<div class="cls orange">
<div class="cls-title">对象 t2</div>
<div class="cls-body">
<div>id_ = 2</div>
<div>title_ = "复习"</div>
<div>priority_ = 3</div>
<div>done_ = true</div>
<div class="sep"></div>
<div class="fn">行为由类共享</div>
</div>
</div>

</div>

<div class="cols mt1">

<div class="col">

**状态**：每个对象各自的数据（`id_`、`done_` ...）

</div>

<div class="col">

**行为**：类中定义的成员函数（`complete()`、`print()` ...）

</div>

<div class="col">

**标识**：每个对象有独立地址，可被指针/引用区分

</div>

</div>

---


<!-- slide data-notes="" -->

##### 消息传递：`t.complete()` 到底发生了什么？

---

<div class="cols">

<div class="col-55">

**表面写法**

```cpp
Task t(1, "写作业", 2);
t.complete();     // 向对象 t 发送消息
t.print();
```

**概念模型**

- 对象是接收消息的实体
- 消息是“调用哪个成员函数 + 实参”
- 对象用自己的状态响应该消息

</div>

<div class="col-45">

<div class="card">

<div class="card-title">编译器的视角（简化）</div>

成员函数只有一份代码，被所有对象共享。为了知道“操作的是哪个对象”，编译器会隐式传入对象地址：

```cpp
// 你写的
t.complete();

// 概念上等价于
Task::complete(&t);
```

这个隐式参数就是 `this` 指针，下一章会详细展开。

</div>

</div>

</div>

<div class="keypoint">
<span class="label">重要</span>
面向对象程序的执行，可以看作一系列<strong>对象间的消息传递</strong>：一个对象处理消息时，又向其他对象发送消息。
</div>

---


<!-- slide data-notes="" -->

##### 面向对象四大特征

---

<div class="cols stretch">

<div class="col">

<div class="card">

<div class="card-title">1. 抽象</div>

只描述对象“做什么”，隐藏“怎么做”。

`Stack` 只暴露 `push/pop`，不暴露数组或链表。

</div>

</div>

<div class="col">

<div class="card">

<div class="card-title">2. 封装</div>

把数据和操作装在一起，并限制访问。

`private` 保护不变量，`public` 提供接口。

</div>

</div>

<div class="col">

<div class="card">

<div class="card-title">3. 继承</div>

在已有类的基础上定义新类，复用共同特征。

`DeadlineTask` 是一种 `Task`。

</div>

</div>

<div class="col">

<div class="card">

<div class="card-title">4. 多态</div>

同一消息发送给不同对象，得到不同响应。

`t->run()` 可能执行普通任务或周期任务。

</div>

</div>

</div>

<div class="motto mt1">
抽象是<strong>看问题的方式</strong>，封装是<strong>落实抽象的机制</strong>，继承是<strong>复用与分类的手段</strong>，多态是<strong>统一接口下允许差异</strong>。
</div>

---


<!-- slide data-notes="" -->

##### 继承一瞥：is-a 关系

---

<div class="cols">

<div class="col-55">

```cpp
class Task {
public:
    void complete() { done_ = true; }
    bool is_done() const { return done_; }
protected:
    std::string title_;
    bool done_ = false;
};

class DeadlineTask : public Task {
public:
    void set_deadline(Date d) { deadline_ = d; }
private:
    Date deadline_;
};
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">语义</div>

`DeadlineTask` **是一种** `Task`：

- 拥有 `Task` 的全部成员
- 可以增加新的成员
- 可以重定义基类的行为

```cpp
DeadlineTask d;
d.complete();       // 继承自 Task
d.set_deadline(...); // 自己新增
```

</div>

<div class="tip">
<span class="label">注意</span>
继承表达的是 <strong>is-a</strong>。不是“有”的关系，也不是“为了复用代码”就可以继承。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 多态一瞥：同一消息，不同响应

---

<div class="cols">

<div class="col-55">

```cpp
class Task {
public:
    virtual void run() {
        std::cout << "执行普通任务\n";
    }
    virtual ~Task() = default;
};

class RecurringTask : public Task {
public:
    void run() override {
        std::cout << "执行周期任务\n";
    }
};
```

```cpp
void execute(Task& t) {
    t.run();          // 调用哪个版本？
}

Task a;
RecurringTask b;
execute(a);           // 执行普通任务
execute(b);           // 执行周期任务
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">关键点</div>

- `execute` 只依赖基类接口 `Task`
- 运行时根据对象的**动态类型**选择 `run`
- 新增任务类型时，`execute` **不需要修改**

</div>

<div class="keypoint">
<span class="label">这就是多态</span>
高层代码面向接口编程，低层代码可以不断扩展。具体机制（虚函数、虚表）将在后面章节展开。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 过程式 vs 面向对象：模块边界

---

<div class="cols">

<div class="col">

<div class="card">

<div class="card-title">过程式：按功能划分</div>

<div class="fig">
<svg viewBox="0 0 360 180" width="330">
  <rect x="10" y="10" width="100" height="40" rx="6" fill="#eee8d5" stroke="#93a1a1"/>
  <rect x="130" y="10" width="100" height="40" rx="6" fill="#eee8d5" stroke="#93a1a1"/>
  <rect x="250" y="10" width="100" height="40" rx="6" fill="#eee8d5" stroke="#93a1a1"/>
  <text x="60" y="35" font-size="14" text-anchor="middle" fill="#586e75">功能 A</text>
  <text x="180" y="35" font-size="14" text-anchor="middle" fill="#586e75">功能 B</text>
  <text x="300" y="35" font-size="14" text-anchor="middle" fill="#586e75">功能 C</text>
  <rect x="60" y="110" width="240" height="40" rx="6" fill="#fdf6e3" stroke="#268bd2" stroke-dasharray="4 3"/>
  <text x="180" y="135" font-size="14" text-anchor="middle" fill="#268bd2">共享数据（公开）</text>
  <line x1="60" y1="50" x2="120" y2="110" stroke="#93a1a1"/>
  <line x1="180" y1="50" x2="180" y2="110" stroke="#93a1a1"/>
  <line x1="300" y1="50" x2="240" y2="110" stroke="#93a1a1"/>
</svg>
</div>

数据公开，多个功能都可直接改；模块边界模糊。

</div>

</div>

<div class="col">

<div class="card">

<div class="card-title">面向对象：按对象划分</div>

<div class="fig">
<svg viewBox="0 0 360 180" width="330">
  <rect x="30" y="40" width="120" height="90" rx="8" fill="#fdf6e3" stroke="#268bd2"/>
  <text x="90" y="65" font-size="14" text-anchor="middle" fill="#268bd2">Task</text>
  <line x1="45" y1="75" x2="135" y2="75" stroke="#93a1a1"/>
  <text x="90" y="92" font-size="12" text-anchor="middle" fill="#657b83">数据 + 操作</text>
  <text x="90" y="110" font-size="12" text-anchor="middle" fill="#657b83">public 接口</text>
  <rect x="210" y="40" width="120" height="90" rx="8" fill="#fdf6e3" stroke="#859900"/>
  <text x="270" y="65" font-size="14" text-anchor="middle" fill="#859900">TaskList</text>
  <line x1="225" y1="75" x2="315" y2="75" stroke="#93a1a1"/>
  <text x="270" y="92" font-size="12" text-anchor="middle" fill="#657b83">数据 + 操作</text>
  <text x="270" y="110" font-size="12" text-anchor="middle" fill="#657b83">public 接口</text>
  <line x1="150" y1="85" x2="210" y2="85" stroke="#b58900" stroke-width="2"/>
  <text x="180" y="78" font-size="11" text-anchor="middle" fill="#b58900">消息</text>
</svg>
</div>

每个对象守护自己的数据，通过接口协作；模块边界清晰。

</div>

</div>

</div>

<div class="small muted center mt1">
面向对象不是“把函数塞进类里”，而是<strong>让数据的所有者承担维护不变量的责任</strong>。
</div>

---


<!-- slide data-notes="" -->

##### 面向对象的收益与代价

---

<div class="cols">

<div class="col">

**收益**

- 抽象控制复杂度：面对接口，而非细节
- 封装保护不变量：错误尽早暴露
- 模块边界清晰：按类分工协作
- 复用与扩展：继承、组合、多态
- 更贴近问题空间：对象对应业务概念

</div>

<div class="col">

**代价**

- 设计与抽象需要经验，过度设计有害
- 运行时的间接调用有开销（通常可接受）
- 类比函数多：头文件、构造、析构、拷贝……
- 继承层次过深会难以理解
- “为了复用而继承”会制造错误抽象

</div>

</div>

<div class="keypoint">
<span class="label">判断标准</span>
一种设计是否更好，最终看它是否提升<strong>开发效率</strong>与<strong>软件质量</strong>：可理解、可修改、可测试、可复用。
</div>

<div class="question">
<span class="label">讨论</span>
“把所有成员都设为 public，调用更方便”——这句话忽略了什么？什么时候可以适度开放？
</div>

---


<!-- slide data-notes="" -->

##### 三条贯穿课程的设计原则

---

<div class="cols stretch">

<div class="col">

<div class="card">

<div class="card-title">单一职责</div>

一个类只负责一件事。

`Task` 表示任务，`TaskList` 管理集合，`TaskRepository` 负责持久化，不要把三者塞进一个类。

</div>

</div>

<div class="col">

<div class="card">

<div class="card-title">开闭原则</div>

对扩展开放，对修改关闭。

新增任务类型时，尽量新增类，而不是修改 `execute` 中的 `switch`。

</div>

</div>

<div class="col">

<div class="card">

<div class="card-title">组合优于继承</div>

能用“有”表达的关系，不要用“是”表达。

`Scheduler` **有一个** `TaskList`，不必继承 `TaskList`。

</div>

</div>

</div>

<div class="xsmall muted center mt1">
这些原则会在继承、多态、模板、项目章节反复出现；现在只需建立印象，不要求背定义。
</div>

---


<!-- slide data-notes="" -->

##### 现代 C++ 的五个习惯（先建立印象）

---

| 习惯 | 传统写法 | 现代写法 | 解决的问题 |
| :-- | :-- | :-- | :-- |
| 资源管理 | `new` / `delete` 手动配对 | `std::unique_ptr`、RAII | 泄漏、重复释放 |
| 类型推导 | 重复写长类型 | `auto` <span class="std cxx11">C++11</span> | 冗长、易错 |
| 遍历 | 下标循环 | 范围 `for` <span class="std cxx11">C++11</span> | 越界、意图不清 |
| 回调 | 函数指针 + 全局函数 | Lambda <span class="std cxx11">C++11</span> | 代码分散、状态传递 |
| 只读约束 | 靠注释约定 | `const`、`constexpr` | 意外修改、编译期检查 |

<div class="cols mt1">

<div class="col code-xs">

```cpp
// 传统
Task* t = new Task(...);
tasks.push_back(t);
// ... 忘记 delete -> 泄漏

// 现代
auto t = std::make_unique<Task>(...);
tasks.push_back(std::move(t));
```

</div>

<div class="col code-xs">

```cpp
// 传统
for (int i = 0; i < v.size(); ++i)
    std::cout << v[i] << "\n";

// 现代
for (const auto& x : v)
    std::cout << x << "\n";
```

</div>

</div>

<div class="tip">
<span class="label">说明</span>
这里只展示“长什么样”。每个习惯背后的原理、代价与适用场景，会在对应章节展开。
</div>

---


<!-- slide data-notes="" -->

##### 本课程代码规范

---

<div class="cols">

<div class="col">

**命名与风格**

- 类型：`Task`、`TaskList`（大驼峰）
- 函数/变量：`add_task`、`task_count`（小写下划线）
- 成员变量：`id_`、`title_`（尾部下划线）
- 常量：`kMaxTasks`、`kCapacity`
- 每行不超过 100 字符

</div>

<div class="col">

**编译与检查**

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic \
    -fsanitize=address,undefined \
    main.cpp -o main
```

- 不忽略警告
- 不写 `using namespace std;` 到头文件
- 动态内存必须配对释放，或交给智能指针
- 头文件使用 include guard 或 `#pragma once`

</div>

</div>

<div class="pitfall">
<span class="label">关于 AI 辅助</span>
可以用 AI 解释概念、生成测试、查找编译错误；但<strong>不能提交自己讲不清楚的代码</strong>。课程项目会进行代码答辩，重点解释设计取舍与执行过程。
</div>

---


<!-- slide data-notes="" -->

##### 课程安排与考核（以课程网站为准）

---

<div class="cols">

<div class="col">

**教学形式**

- 理论课：概念、原理、代码分析
- 实验课：现场编码、调试、OJ
- 课程项目：分阶段迭代，最终答辩

**学习闭环**

<div class="flow" style="flex-direction:column;width:100%;margin:0.3rem 0;">
<div class="flow-step"><strong>读</strong>课件与教材</div>
<div class="flow-step"><strong>写</strong>课堂任务与作业</div>
<div class="flow-step"><strong>调</strong>编译错误与运行错误</div>
<div class="flow-step"><strong>讲</strong>解释设计取舍</div>
</div>

</div>

<div class="col">

<div class="card">

<div class="card-title">考核构成（示意）</div>

- 平时作业与课堂任务
- 上机考核（OJ）
- 课程项目（设计 + 实现 + 答辩）
- 期末笔试

<div class="xsmall muted mt1">
具体比例、提交方式与截止时间，以课程网站通知为准。
</div>

</div>

<div class="tip">
<span class="label">建议</span>
每章至少亲手编译、修改、破坏一次课件代码。看懂不等于会写，会写不等于能调试。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 课堂任务 1：把 C 的 Task 改造成类

---

<div class="cols">

<div class="col-55">

<div class="card">

<div class="card-title">任务</div>

把下面的 C 结构改造成 `Task` 类：

- 数据成员私有：`id_`、`title_`、`priority_`、`done_`
- 提供构造函数 `Task(int id, std::string title, int priority)`
- 提供 `complete()`、`is_done()`、`print() const`
- `print()` 输出格式：`[1] 写作业 (p=2) todo`
- 在 `main` 中创建两个任务，完成其中一个并打印

</div>

```cpp
struct Task {
    int id;
    char title[32];
    int priority;
    int done;
};
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">验收标准</div>

- 编译通过：`g++ -std=c++17 -Wall -Wextra`
- 外部代码不能直接访问 `id_` 等成员
- `title` 使用 `std::string`，不再手工管理字符数组
- `print()` 不修改对象，声明为 `const`

</div>

<div class="tip">
<span class="label">提示</span>
先写 `private` 数据，再写 `public` 接口；构造函数用成员初始化列表。暂时不用考虑拷贝、移动与继承。
</div>

</div>

</div>

<div class="xsmall muted center mt1">
完成后思考：如果把 `title` 改成 `std::string`，`print` 的实现需要哪些变化？为什么不再需要 `strncpy`？
</div>

---


<!-- slide data-notes="" -->

##### 任务 1 参考实现

---

<div class="cols">

<div class="col-55 code-xs">

```cpp{.line-numbers}
#include <iostream>
#include <string>
#include <utility>

class Task {
public:
    Task(int id, std::string title, int priority)
        : id_(id), title_(std::move(title)),
          priority_(priority) {}

    void complete() { done_ = true; }
    bool is_done() const { return done_; }

    void print() const {
        std::cout << "[" << id_ << "] " << title_
                  << " (p=" << priority_ << ") "
                  << (done_ ? "done" : "todo") << "\n";
    }

private:
    int id_;
    std::string title_;
    int priority_;
    bool done_ = false;
};

int main() {
    Task t1(1, "写作业", 2);
    Task t2(2, "复习", 3);
    t1.complete();
    t1.print();
    t2.print();
}
```

</div>

<div class="col-45">

<div class="small">

**要点**

- `private` 数据 + `public` 接口，外部无法直接破坏状态
- 构造函数建立对象的不变量：创建完成即处于合法状态
- `std::string` 自己管理内存，不需要 `strncpy` / `'\0'`
- `print() const` 承诺不修改对象，常量对象也能调用
- `std::move` 把临时字符串的资源“搬”进成员，避免一次拷贝

**运行结果**

<div class="out">[1] 写作业 (p=2) done
[2] 复习 (p=3) todo</div>

</div>

</div>

</div>



---


<!-- slide data-notes="" -->

##### 课堂小测

---

1. 过程抽象与数据抽象分别隐藏了什么？封装在两者之间扮演什么角色？

2. 类是编译时刻的还是运行时刻的实体？对象呢？请各举一个例子。

3. 为什么“把所有成员都设为 public”会破坏封装？封装保护的是什么？

4. 继承表达 is-a 关系。`Scheduler` 与 `TaskList` 之间应该是继承还是组合？为什么？

---


<!-- slide data-notes="" -->

##### 小结：三个词，一条主线

---

<div class="cols">

<div class="col">

<div class="card">

<div class="card-title">抽象</div>

只描述“做什么”，隐藏“怎么做”。接口稳定，实现可替换。

</div>

</div>

<div class="col">

<div class="card">

<div class="card-title">封装</div>

数据和操作装在一起，用访问控制守住不变量。

</div>

</div>

<div class="col">

<div class="card">

<div class="card-title">对象</div>

运行时独立的状态实体，通过消息与其它对象协作。

</div>

</div>

</div>

<div class="motto mt1">
面向对象不是“把代码写进 class”，而是<strong>让每个对象守护自己的不变量，并通过稳定的接口协作</strong>。
</div>

<div class="small muted center">
下一讲：类与对象——构造、析构、`this` 指针与成员初始化。
</div>

---


<!-- slide data-notes="" -->

#####

---

<div class="bottom20"></div>

<hr class="width50 center">

## 未完待续

---
