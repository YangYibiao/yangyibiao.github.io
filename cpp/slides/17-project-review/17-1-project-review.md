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

## 课程项目与总复习

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](mailto:yangyibiao@nju.edu.cn)


<!-- slide data-notes="" -->

##### 本讲提纲

---

<div class="cols">

<div class="col">

**课程项目**

- 需求与模块划分
- 接口设计与迭代计划
- 测试、调试与代码规范
- 评分标准与答辩要求

</div>

<div class="col">

**总复习**

- 对象生命周期与资源管理
- 继承与多态
- STL 与泛型
- 并发与常见错误

</div>

</div>

<div class="keypoint">
<span class="label">目标</span>
把一学期学到的“语言机制”组织成一次完整的软件设计：需求 → 抽象 → 实现 → 测试 → 讲解。
</div>

---


<!-- slide data-notes="" -->

##### 课程知识地图

---

<div class="flow">
<div class="flow-step"><strong>抽象</strong>类与对象<br>封装 / 接口</div>
<div class="flow-arrow">→</div>
<div class="flow-step"><strong>生命周期</strong>构造 / 析构<br>拷贝 / 移动 / RAII</div>
<div class="flow-arrow">→</div>
<div class="flow-step"><strong>复用</strong>继承 / 组合<br>多态 / 接口</div>
<div class="flow-arrow">→</div>
<div class="flow-step"><strong>泛型</strong>模板 / STL<br>算法 / Lambda</div>
<div class="flow-arrow">→</div>
<div class="flow-step"><strong>工程</strong>异常 / 内存安全<br>并发 / 声明式</div>
</div>

<div class="cols mt1">

<div class="col">

**三条主线**

- 数据的所有权：谁创建、谁释放
- 类型的边界：接口、继承、多态
- 变化的隔离：封装、泛型、事件

</div>

<div class="col">

**三种能力**

- 写出正确、可编译的代码
- 解释程序为什么这样运行
- 在设计取舍中说明理由

</div>

</div>

<div class="small muted center">
期末考试与项目答辩都围绕这三条主线：不只是“会不会写”，而是“是否理解为什么这样写”。
</div>

---


<!-- slide data-notes="" -->

##### 现代 C++ 工具速览

---

<div class="cols">

<div class="col code-sm">

**结构化绑定** <span class="std cxx17">C++17</span>

```cpp
std::map<int, Task> by_id;

for (const auto& [id, task] : by_id) {
    std::cout << id << ": " << task << "\n";
}

auto [it, inserted] =
    by_id.emplace(3, Task(3, "新任务", 2));
```

**`std::optional`** <span class="std cxx17">C++17</span>

```cpp
std::optional<Task> find_task(int id);

if (auto t = find_task(1)) {
    t->print();
} else {
    std::cout << "not found\n";
}
```

</div>

<div class="col code-sm">

**`std::filesystem`** <span class="std cxx17">C++17</span>

```cpp
namespace fs = std::filesystem;

if (!fs::exists("tasks.txt")) {
    std::cout << "no data file\n";
}

for (const auto& entry :
     fs::directory_iterator(".")) {
    std::cout << entry.path() << "\n";
}
```

**`std::string_view`** <span class="std cxx17">C++17</span>

```cpp
void print_name(std::string_view name) {
    std::cout << name << "\n";
}

print_name("TaskFlow");
```

</div>

</div>

<div class="tip">
<span class="label">使用边界</span>
这些工具适合简化“可选值、文件路径、只读字符串、键值遍历”等常见场景；不要为了用新特性而改变清晰的接口。<code>string_view</code> 不拥有字符数据，不能返回指向局部字符串的 view。
</div>

---

<!-- slide data-notes="" -->

##### 项目：TaskFlow 任务管理器

---

<div class="cols">

<div class="col-55">

**功能需求**

1. 添加/删除/完成/查询任务
2. 支持普通、截止日期、周期任务
3. 按优先级调度执行
4. 保存到文件、启动时恢复
5. 多线程执行任务
6. 记录事件日志
7. 命令行交互

**非功能需求**

- 无内存泄漏、无数据竞争
- 模块清晰、可测试
- 代码可读、可维护

</div>

<div class="col-45">

<div class="card">

<div class="card-title">交付物</div>

- 源代码（可编译、可运行）
- `README.md`：构建与使用说明
- 设计文档：模块图、类图、关键取舍
- 测试：单元测试 + 手工测试记录
- 演示：现场运行 + 代码讲解

</div>

<div class="pitfall">
<span class="label">范围控制</span>
不要做图形界面、不要接数据库、不要引入大型框架。把核心功能做扎实，比堆功能更重要。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 模块划分：按职责，不按“文件数量”

---

<div class="cols">

<div class="col">

<div class="card">

<div class="card-title">领域模型</div>

- `Task`：抽象任务接口
- `PrintTask` / `DeadlineTask` / `RecurringTask`
- `TaskList`：任务集合

</div>

<div class="card mt1">

<div class="card-title">服务</div>

- `Scheduler`：按优先级执行
- `TaskRepository`：持久化
- `EventLoop`：事件分发

</div>

</div>

<div class="col">

<div class="fig">
<svg viewBox="0 0 460 280" width="500">
  <rect x="150" y="10" width="160" height="40" rx="7" fill="#fdf6e3" stroke="#268bd2"/>
  <text x="230" y="35" font-size="14" text-anchor="middle" fill="#268bd2">Scheduler</text>
  <rect x="20" y="95" width="140" height="40" rx="7" fill="#fdf6e3" stroke="#859900"/>
  <text x="90" y="120" font-size="14" text-anchor="middle" fill="#859900">TaskList</text>
  <rect x="300" y="95" width="140" height="40" rx="7" fill="#fdf6e3" stroke="#b58900"/>
  <text x="370" y="120" font-size="14" text-anchor="middle" fill="#b58900">Repository</text>
  <rect x="20" y="190" width="140" height="40" rx="7" fill="#fdf6e3" stroke="#dc322f"/>
  <text x="90" y="215" font-size="14" text-anchor="middle" fill="#dc322f">Task 接口</text>
  <rect x="300" y="190" width="140" height="40" rx="7" fill="#fdf6e3" stroke="#6c71c4"/>
  <text x="370" y="215" font-size="14" text-anchor="middle" fill="#6c71c4">EventLoop</text>
  <line x1="200" y1="50" x2="120" y2="95" stroke="#93a1a1"/>
  <line x1="260" y1="50" x2="340" y2="95" stroke="#93a1a1"/>
  <line x1="90" y1="135" x2="90" y2="190" stroke="#93a1a1"/>
  <line x1="230" y1="50" x2="370" y2="190" stroke="#93a1a1" stroke-dasharray="4 3"/>
</svg>
</div>

<div class="small muted center">
`Scheduler` 依赖 `TaskList` 与 `Task` 接口；`Repository` 负责存取；`EventLoop` 负责通知。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 接口设计：先定契约，再写实现

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
class Task {
public:
    virtual ~Task() = default;
    virtual void run() = 0;
    virtual std::string describe() const = 0;
    virtual int id() const = 0;
    virtual int priority() const = 0;
};

class TaskList {
public:
    void add(std::unique_ptr<Task> t);
    bool remove(int id);
    Task* find(int id);
    std::size_t size() const;
private:
    std::vector<std::unique_ptr<Task>> tasks_;
};

class TaskRepository {
public:
    explicit TaskRepository(std::string path);
    std::vector<std::unique_ptr<Task>> load() const;
    void save(const TaskList& list) const;
private:
    std::string path_;
};
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">设计检查</div>

- 谁拥有任务？`TaskList` 通过 `unique_ptr` 独占
- 外部如何“借用”？返回 `Task*`，不转移所有权
- 持久化如何知道类型？文件中记录类型标签
- 扩展新任务类型要改哪里？只改工厂/加载逻辑

</div>

<div class="tip">
<span class="label">接口先行</span>
先把类图画出来、把函数签名定下来，再写实现。接口稳定后，模块可以并行开发与测试。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 迭代计划：四个里程碑

---

<div class="cols">

<div class="col">

<div class="card">

<div class="card-title">里程碑 1：可运行骨架</div>

- `Task` / `TaskList`
- 命令行菜单
- 添加、列出、完成任务
- 内存中使用，不持久化

</div>

<div class="card mt1">

<div class="card-title">里程碑 2：类型与调度</div>

- 抽象基类 + 三种任务
- 优先级排序
- `Scheduler` 统一执行

</div>

</div>

<div class="col">

<div class="card">

<div class="card-title">里程碑 3：持久化与健壮性</div>

- 文件保存/加载
- 异常处理与错误提示
- 单元测试覆盖核心逻辑

</div>

<div class="card mt1">

<div class="card-title">里程碑 4：并发与完善</div>

- 多线程执行
- 事件日志
- 性能与内存检查
- 文档与演示

</div>

</div>

</div>

<div class="small muted center mt1">
每个里程碑都要“可编译、可运行、可演示”；不要等到最后一次性集成。
</div>

---


<!-- slide data-notes="" -->

##### 测试策略：从函数到系统

---

<div class="table-sm">

| 层次 | 测什么 | 工具/方法 |
| :-- | :-- | :-- |
| 单元测试 | `Task`、`TaskList`、`parse` | 断言、测试框架、`assert` |
| 边界测试 | 空列表、满优先级、非法输入 | 手工用例 + 参数化 |
| 异常测试 | 文件不存在、格式错误 | 构造坏文件、捕获异常 |
| 集成测试 | 添加→保存→加载→执行 | 端到端脚本 |
| 内存/并发 | 泄漏、越界、数据竞争 | ASan、UBSan、TSan |

</div>

<div class="cols mt1">

<div class="col">

**好测试的特征**

- 可重复：不依赖随机/时间
- 独立：不依赖执行顺序
- 快速：核心逻辑毫秒级
- 明确：失败信息能定位问题

</div>

<div class="col">

**至少覆盖**

- 添加/删除/查找
- 空容器操作
- 文件不存在
- 非法优先级
- 多线程执行结果一致

</div>

</div>

---


<!-- slide data-notes="" -->

##### 调试与质量检查

---

<div class="cols">

<div class="col">

**编译阶段**

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic \
    -fsanitize=address,undefined \
    -g main.cpp task.cpp -o app
```

- 警告全部处理
- 不依赖“能跑就行”

</div>

<div class="col">

**运行阶段**

```bash
./app
valgrind --leak-check=full ./app
```

- ASan/UBSan 检查内存与 UB
- TSan 检查数据竞争
- 日志记录关键状态变化

</div>

</div>

<div class="keypoint">
<span class="label">顺序</span>
先保证正确性，再谈性能。用 Sanitizer 跑通所有测试，再做基准测试；不要用“优化”掩盖内存错误。
</div>

---


<!-- slide data-notes="" -->

##### 代码规范与版本管理

---

<div class="cols">

<div class="col">

**代码规范**

- 类型大驼峰，函数/变量小写下划线
- 成员变量尾部 `_`
- 常量 `k` 前缀
- 一个函数只做一件事
- 头文件 `#pragma once`
- 不写 `using namespace std;` 到头文件

</div>

<div class="col">

**Git 使用**

```bash
git init
git add .
git commit -m "feat: add TaskList"
git log --oneline
```

- 小步提交，信息明确
- 每个里程碑打 tag
- 不提交编译产物、密钥、大数据
- 提交前先编译、跑测试

</div>

</div>

<div class="tip">
<span class="label">可维护性</span>
代码是写给人看的，顺便给机器执行。命名、注释、提交信息，都是设计的一部分。
</div>

---


<!-- slide data-notes="" -->

##### AI 辅助的边界

---

<div class="cols">

<div class="col">

**可以用 AI**

- 解释编译错误、概念差异
- 生成测试用例与边界数据
- 审查代码、提出重构建议
- 帮助理解标准库文档

</div>

<div class="col">

**不可以**

- 提交自己讲不清的代码
- 用 AI 生成整个项目后不做设计
- 把未经验证的代码直接放进答辩版本
- 隐瞒 AI 使用情况（如课程要求披露）

</div>

</div>

<div class="pitfall">
<span class="label">答辩标准</span>
评委可以问：“为什么这里用 <code>unique_ptr</code> 而不是 <code>shared_ptr</code>？”“这个类的不变量是什么？”——答不上来，说明代码不是你的设计。
</div>

---


<!-- slide data-notes="" -->

##### 常见设计错误

---

<div class="cols">

<div class="col">

**类设计**

- 上帝类：一个类做所有事
- 数据公开，靠注释维持不变量
- 为了复用而继承
- 深继承层次
- 接口返回内部可变引用

</div>

<div class="col">

**资源与并发**

- 裸 `new` / `delete` 散落各处
- 析构函数不释放资源
- 基类析构非虚
- 多线程共享数据不加锁
- 持锁执行耗时操作
- 用 `detach` 后访问局部变量

</div>

</div>

<div class="motto mt1">
设计错误通常不是“语法不会”，而是“职责不清、所有权不明、边界不定”。
</div>

---


<!-- slide data-notes="" -->

##### 评分标准（示意）

---

<div class="table-sm">

| 维度 | 权重 | 关注点 |
| :-- | :--: | :-- |
| 功能完整性 | 40% | 需求是否实现，边界是否处理 |
| 设计与抽象 | 25% | 类职责、接口、继承/组合选择 |
| 资源与安全 | 15% | RAII、智能指针、异常安全、无泄漏 |
| 测试与调试 | 10% | 测试覆盖、Sanitizer 使用 |
| 答辩与文档 | 10% | 能解释设计取舍、文档清晰 |

</div>

<div class="cols mt1">

<div class="col">

**加分项**

- 合理的并发设计
- 清晰的错误处理
- 可复用的模块
- 优秀的测试

</div>

<div class="col">

**扣分项**

- 编译警告未处理
- 内存泄漏/数据竞争
- 代码无法运行
- 答辩说不清核心逻辑

</div>

</div>

<div class="small muted center">
具体比例与要求以课程网站发布为准；本页用于说明评价维度。
</div>

---


<!-- slide data-notes="" -->

##### 综合案例：从需求到类图

---

<div class="cols">

<div class="col-55">

**需求片段**

> 系统需要支持多种任务；每种任务都能执行并描述自己；任务按优先级调度；任务可以保存到文件并在下次启动时恢复。

**抽象步骤**

1. 找名词：任务、任务列表、调度器、仓库
2. 找动词：执行、描述、添加、删除、保存、加载
3. 定职责：谁拥有任务？谁负责排序？谁负责 I/O？
4. 定接口：`Task::run()`、`Task::describe()`、`TaskList::add()`
5. 定关系：`Scheduler` 组合 `TaskList`；`TaskList` 组合 `unique_ptr<Task>`

</div>

<div class="col-45">

<div class="cds" style="flex-direction:column;gap:10px;align-items:stretch;width:100%;margin:0;">
<div class="cls blue">
<div class="cls-title">Task «interface»</div>
<div class="cls-body">
<div class="fn">+ run() = 0</div>
<div class="fn">+ describe() const = 0</div>
<div class="fn">+ id() const = 0</div>
<div class="fn">+ priority() const = 0</div>
</div>
</div>
<div class="cls green">
<div class="cls-title">TaskList</div>
<div class="cls-body">
<div class="fn">+ add(unique_ptr&lt;Task&gt;)</div>
<div class="fn">+ remove(int)</div>
<div class="fn">+ find(int)</div>
</div>
</div>
<div class="cls orange">
<div class="cls-title">Scheduler</div>
<div class="cls-body">
<div class="fn">+ run_all()</div>
<div class="fn">- TaskList tasks_</div>
</div>
</div>
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 综合案例：核心代码骨架

---

<div class="cols">

<div class="col-55 code-xs">

```cpp{.line-numbers}
class Task {
public:
    virtual ~Task() = default;
    virtual void run() = 0;
    virtual std::string describe() const = 0;
    virtual int id() const = 0;
    virtual int priority() const = 0;
};

class TaskList {
public:
    void add(std::unique_ptr<Task> t) {
        tasks_.push_back(std::move(t));
    }

    Task* find(int id) {
        for (auto& t : tasks_) {
            if (t->id() == id) return t.get();
        }
        return nullptr;
    }

    void run_all() {
        for (auto& t : tasks_) t->run();
    }
private:
    std::vector<std::unique_ptr<Task>> tasks_;
};
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">设计点</div>

- `Task` 定义稳定接口
- `TaskList` 独占拥有任务
- `find` 返回借用指针，不转移所有权
- `run_all` 通过虚函数动态分派
- 新增任务类型不需要修改 `TaskList`

</div>

<div class="pitfall">
<span class="label">注意</span>
<code>Task</code> 还需要 <code>id()</code>；示例省略了构造与具体派生类。完整项目应把接口、实现、测试分开。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 复习一：对象生命周期

---

<div class="table-sm">

| 阶段 | 发生什么 | 你要保证 |
| :-- | :-- | :-- |
| 构造 | 分配空间、初始化成员、执行函数体 | 对象返回时满足不变量 |
| 使用 | 调用成员函数 | 不访问已销毁对象 |
| 拷贝 | 拷贝构造 / 赋值 | 深拷贝资源，处理自赋值 |
| 移动 | 移动构造 / 赋值 | 源对象置空、`noexcept` |
| 析构 | 释放资源 | 不抛异常、不重复释放 |

</div>

<div class="cols mt1">

<div class="col">

**三法则 / 五法则**

析构、拷贝构造、拷贝赋值（+ 移动构造、移动赋值）通常要一起考虑。

</div>

<div class="col">

**Rule of Zero**

优先让成员（容器、智能指针）管理资源，类本身不写析构/拷贝/移动。

</div>

</div>

---


<!-- slide data-notes="" -->

##### 复习二：继承与多态

---

<div class="cols">

<div class="col">

**继承**

- `public` 继承表达 is-a
- 构造：基类 → 成员 → 派生
- 析构：派生 → 成员 → 基类
- 名字隐藏、对象切片、菱形继承

</div>

<div class="col">

**多态**

- `virtual` + 指针/引用
- `override` 让编译器检查签名
- 虚析构保证正确释放
- 抽象类定义接口
- 少用 `dynamic_cast`，多用虚函数

</div>

</div>

<div class="pitfall">
<span class="label">高频错误</span>
① 基类析构非虚；② 派生类漏 <code>override</code> / 签名不一致；③ 按值传递导致切片；④ 在构造/析构中调用虚函数。
</div>

---


<!-- slide data-notes="" -->

##### 复习三：资源管理与 STL

---

<div class="cols">

<div class="col">

**资源管理**

- RAII：构造获取、析构释放
- `unique_ptr` 独占，`shared_ptr` 共享，`weak_ptr` 观察
- 不要用同一裸指针构造多个 `shared_ptr`
- 避免循环引用
- 容器/字符串/文件流都是 RAII

</div>

<div class="col">

**STL**

- `vector` 默认；`list` 频繁中间增删；`map` 有序查找
- 算法接迭代器区间 `[first, last)`
- 比较器必须严格弱序
- `erase` + `remove_if`；注意迭代器失效
- Lambda 捕获注意生命周期

</div>

</div>

<div class="keypoint">
<span class="label">共同点</span>
资源管理与 STL 都在回答同一个问题：<strong>谁拥有、谁释放、什么时候失效</strong>。
</div>

---


<!-- slide data-notes="" -->

##### 复习四：并发

---

<div class="cols">

<div class="col">

**线程**

- `std::thread` 创建即运行
- `join` 等待，`detach` 放养
- 参数默认按值复制
- 线程对象析构前必须 `join`/`detach`

</div>

<div class="col">

**同步**

- 数据竞争是未定义行为
- `mutex` + `lock_guard`
- 临界区尽量小
- 条件变量必须带谓词
- 死锁：统一加锁顺序 / `scoped_lock`
- 原子操作只适合单变量

</div>

</div>

<div class="motto mt1">
并发编程的第一原则：<strong>能不共享就不共享</strong>；必须共享时，用清晰的同步策略保护它。
</div>

---


<!-- slide data-notes="" -->

##### 易错点清单

---

<div class="cols">

<div class="col">

**语言机制**

- `const` 成员函数修改成员
- 拷贝构造参数不写引用
- 赋值忘记自赋值检查
- 移动后继续使用源对象
- 返回局部变量引用
- `new[]` 配 `delete`
- 基类析构非虚
- 按值传递导致切片
- `override` 签名不一致

</div>

<div class="col">

**工程实践**

- 头文件定义非 `inline` 函数
- 模板定义放 `.cpp`
- `map[]` 意外插入
- 迭代器失效
- 比较器不满足严格弱序
- 条件变量不用谓词
- 持锁执行耗时操作
- `detach` 后访问局部变量
- 异常路径资源泄漏

</div>

</div>

<div class="small muted center">
考前逐条自查：能说出“为什么错、怎么改、如何避免”，比背结论更有效。
</div>

---


<!-- slide data-notes="" -->

##### 模拟题 1：概念辨析

---

1. 为什么基类的析构函数通常要声明为 `virtual`？不声明时通过基类指针 `delete` 会发生什么？

2. 拷贝构造与拷贝赋值的区别是什么？三法则为什么要求它们一起出现？

3. `unique_ptr` 与 `shared_ptr` 的所有权模型有何不同？各自适合什么场景？

4. 什么是数据竞争？`mutex`、`atomic`、条件变量分别解决什么问题？

---


<!-- slide data-notes="" -->

##### 模拟题 2：代码阅读

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
class Base {
public:
    Base() { f(); }
    virtual void f() { std::cout << "B"; }
    ~Base() { f(); }
};

class Derived : public Base {
public:
    void f() override { std::cout << "D"; }
};

int main() {
    Derived d;
}
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">问题</div>

1. 程序输出什么？
2. 为什么不是 `DD`？
3. 如果把 `~Base` 改为 `virtual`，输出会变吗？
4. 这段代码还有什么潜在问题？

</div>

<div class="tip">
<span class="label">提示</span>
构造/析构期间，对象的动态类型是当前正在构造/析构的层次；虚调用不会分派到尚未构造或已经销毁的派生类部分。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 模拟题 3：设计题

---

<div class="cols">

<div class="col-55">

<div class="card">

<div class="card-title">题目</div>

设计一个 `Shape` 体系：

- 抽象基类 `Shape`，提供 `area()`、`draw()`、虚析构
- `Circle`、`Rectangle`、`Triangle` 派生
- 一个 `ShapeList` 拥有多个图形（使用 `unique_ptr`）
- 提供 `total_area()` 与 `draw_all()`
- 新增图形类型时，`ShapeList` 不需要修改

要求画出类图，说明：

1. 为什么用抽象类而不是 `switch`
2. 为什么用 `unique_ptr` 而不是裸指针
3. 如果图形需要复制，如何设计

</div>

</div>

<div class="col-45">

<div class="card">

<div class="card-title">评分点</div>

- 接口稳定、职责清晰
- 虚析构、`override` 正确
- 所有权明确
- 扩展新类型不改高层代码
- 能解释组合/继承的选择

</div>

<div class="tip">
<span class="label">提示</span>
<code>ShapeList</code> 是“拥有”图形，不是“是一种”图形；用组合 + <code>unique_ptr</code>，不要继承 <code>vector</code>。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 参考答案要点

---

<div class="cols">

<div class="col">

**模拟题 1**

- 虚析构：通过基类指针删除派生对象时，保证派生类析构执行
- 拷贝构造：初始化新对象；拷贝赋值：覆盖已有对象
- 三法则：三者共同定义资源所有权
- `unique_ptr` 独占、零开销；`shared_ptr` 共享、引用计数
- 数据竞争：并发访问共享数据且至少一个写；`mutex` 保护临界区，`atomic` 保护单变量，条件变量等待状态

</div>

<div class="col">

**模拟题 2**

- 输出 `BB`（构造 `Base` 时调用 `Base::f`，析构 `Base` 时也调用 `Base::f`）
- 构造/析构期间不进行派生类分派
- 把析构改为 `virtual` 仍输出 `BB`；虚析构解决的是“删除时调用派生析构”，不改变基类构造/析构中的调用
- 潜在问题：在构造/析构中调用虚函数；基类析构非虚（若通过基类指针删除）

</div>

</div>

<div class="small muted center mt1">
模拟题 3 的答案不唯一，重点看接口、所有权、扩展性与解释是否自洽。
</div>

---


<!-- slide data-notes="" -->

##### 课程总结：从语法到设计

---

<div class="cols">

<div class="col">

<div class="card">

<div class="card-title">学会</div>

- 用类封装不变量
- 用继承表达 is-a，用组合表达 has-a
- 用虚函数实现稳定接口
- 用 RAII/智能指针管理资源
- 用 STL/模板复用算法
- 用同步机制安全并发

</div>

</div>

<div class="col">

<div class="card">

<div class="card-title">理解</div>

- 每种机制解决什么问题
- 代价是什么
- 什么时候不该用
- 对象何时生、何时死、谁拥有
- 错误如何表达与传播

</div>

</div>

<div class="col">

<div class="card">

<div class="card-title">继续</div>

- 读标准库源码与文档
- 学习 CMake、测试框架
- 了解 C++20/23 新特性
- 参与开源项目
- 保持“先正确、再优化”

</div>

</div>

</div>

<div class="motto mt1">
高级程序设计的高级，不在于用了多少语法，而在于<strong>能否用合适的抽象控制复杂度，并对自己的设计负责</strong>。
</div>

---


<!-- slide data-notes="" -->

#####

---

<div class="bottom20"></div>

<hr class="width50 center">

## 课程结束，谢谢大家

<div class="bottom8"></div>

### 保持好奇，持续构建
