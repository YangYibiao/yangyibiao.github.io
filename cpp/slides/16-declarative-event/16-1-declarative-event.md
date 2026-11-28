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

## 声明式与事件驱动程序设计

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](mailto:yangyibiao@nju.edu.cn)


<!-- slide data-notes="" -->

##### 本讲提纲

---

<div class="cols">

<div class="col">

**声明式**

- 命令式 vs 声明式
- 纯函数、无副作用
- filter / map / reduce
- 偏函数应用与柯里化

</div>

<div class="col">

**事件驱动**

- 事件循环与回调
- 观察者模式
- `std::function` 注册处理函数
- 生命周期与响应性

</div>

</div>

<div class="keypoint">
<span class="label">本讲目标</span>
能够把“怎么做”的循环改写成“做什么”的管道，并用回调/事件循环组织交互式程序。
</div>

---


<!-- slide data-notes="" -->

##### 两种编程范式

---

<div class="cols">

<div class="col">

**命令式（imperative）**

- 描述“怎么做”：步骤、状态变化
- 循环、赋值、分支
- 与冯·诺依曼结构一致
- 代表：过程式、面向对象

```cpp
int sum = 0;
for (int i = 1; i <= 3; ++i) {
    sum += i;
}
```

</div>

<div class="col">

**声明式（declarative）**

- 描述“做什么”：结果、关系
- 不显式管理循环与状态
- 更精炼，潜在并行性更强
- 代表：函数式、逻辑式、SQL、Ranges

```cpp
auto result = views::iota(1, 4)
            | views::filter(...)
            | views::transform(...);
```

</div>

</div>

<div class="small muted center mt1">
两者不是互斥的：现代 C++ 在多范式之间切换，底层实现仍然是命令式，但接口可以是声明式。
</div>

---


<!-- slide data-notes="" -->

##### 函数式的五个特征

---

<div class="cols">

<div class="col">

**纯函数**

- 相同输入 → 相同输出
- 不修改外部状态（无副作用）
- 引用透明，便于推理与测试

**无状态**

- 变量绑定后不再改变
- 计算产生新数据，而不是修改旧数据

</div>

<div class="col">

**函数是值**

- 函数可以作为参数、返回值
- 高阶函数：接受/返回函数

**递归**

- 用递归替代循环
- 尾递归可被优化为迭代

**惰性求值**

- 需要结果时才计算
- 可避免不必要的中间数据

</div>

</div>

<div class="keypoint">
<span class="label">工程价值</span>
纯函数 + 不可变数据让并发更安全：没有共享可变状态，就不需要复杂的锁。
</div>

---


<!-- slide data-notes="" -->

##### 递归与尾递归

---

<div class="cols">

<div class="col-55">

**普通递归**

```cpp
int fib(int n) {
    if (n <= 2) return 1;
    return fib(n - 1) + fib(n - 2);
}
```

会重复计算，指数级时间；深递归可能栈溢出。

**尾递归**

```cpp
int fib(int n, int a = 1, int b = 1) {
    if (n <= 2) return b;
    return fib(n - 1, b, a + b);
}
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">尾调用优化</div>

递归调用是函数的**最后一步**，且结果不再参与其他运算；编译器可以复用当前栈帧，把递归转成循环。

<div class="small muted mt1">
C++ 标准不强制尾调用优化；GCC/Clang 在 <code>-O2</code> 下通常能优化简单的尾递归。不要把“依赖 TCO”当作可移植保证。
</div>

</div>

<div class="tip">
<span class="label">写法</span>
把中间结果作为参数传入（累加器），让递归调用成为最后一步。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### filter / map / reduce：数据处理三板斧

---

<div class="cols">

<div class="col code-xs">

**filter：筛选**

保留满足条件的元素。

```cpp
std::vector<int> evens;
std::copy_if(nums.begin(), nums.end(),
             std::back_inserter(evens),
             [](int x) { return x % 2 == 0; });
```

</div>

<div class="col code-xs">

**map：变换**

对每个元素应用函数，产生新元素。

```cpp
std::vector<int> doubled;
std::transform(evens.begin(), evens.end(),
               std::back_inserter(doubled),
               [](int x) { return x * 2; });
```

</div>

<div class="col code-xs">

**reduce：归约**

把集合折叠成一个值。

```cpp
int sum = std::accumulate(
    doubled.begin(), doubled.end(), 0);
```

</div>

</div>

<div class="motto mt1">
filter → map → reduce 是最常见的数据流水线；大数据框架的 MapReduce 也源于同一思想。
</div>

---


<!-- slide data-notes="" -->

##### 用 Ranges 写管道 <span class="std cxx20">C++20</span>

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
#include <ranges>

std::vector<int> nums{1, 2, 3, 4, 5, 6};

auto result = nums
    | std::views::filter([](int x) {
          return x % 2 == 0;
      })
    | std::views::transform([](int x) {
          return x * 2;
      });

for (int x : result) {
    std::cout << x << ' ';   // 4 8 12
}
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">特点</div>

- 管道顺序即数据流顺序
- 惰性求值：遍历时才计算
- 不创建中间 `vector`
- 可读性接近需求描述

</div>

<div class="pitfall">
<span class="label">生命周期</span>
<code>result</code> 是视图，引用 <code>nums</code>；<code>nums</code> 销毁后视图悬空。不要返回指向局部容器的视图。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 偏函数应用：固定部分参数

---

<div class="cols">

<div class="col-55">

```cpp
void print(int n, int base);

// 固定 base = 10，生成单参数函数
auto print10 = [](int n) {
    print(n, 10);
};

print10(42);   // 等价于 print(42, 10);
```

更通用的 `std::bind`：

```cpp
using namespace std::placeholders;
auto print10 = std::bind(print, _1, 10);
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">用途</div>

- 为通用函数生成专用版本
- 减少重复传参
- 作为算法谓词
- 适配接口签名

</div>

<div class="tip">
<span class="label">现代写法</span>
优先用 Lambda 而不是 <code>std::bind</code>：可读性更好，编译期优化更充分。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 柯里化：把多参数拆成函数链

---

<div class="cols">

<div class="col-55">

```cpp
int add(int x, int y) { return x + y; }

auto curried_add = [](int x) {
    return [x](int y) { return add(x, y); };
};

auto add5 = curried_add(5);
int a = add5(3);   // 8
int b = add5(10);  // 15
```

调用形式：`curried_add(5)(3)`

</div>

<div class="col-45">

<div class="card">

<div class="card-title">与偏函数应用的区别</div>

- 偏函数应用：固定部分参数，得到参数更少的函数
- 柯里化：把 `f(x,y,z)` 变成 `f(x)(y)(z)`
- 偏函数应用可以任意顺序绑定；柯里化按顺序逐个绑定

</div>

<div class="small muted mt1">
柯里化在纯函数式语言中很常见；C++ 中主要用于函数组合与延迟求值，不要为了“炫技”而过度使用。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 逻辑式程序设计一瞥

---

<div class="cols">

<div class="col-55">

**Prolog 风格**

```prolog
path(a, b).
path(c, d).

path(X, Y) :- path(Y, X).
path(X, Y) :- path(X, Z), path(Z, Y).

?- path(m, n).
```

程序由**事实**和**规则**组成；提问后系统自动匹配、搜索、回溯。

</div>

<div class="col-45">

<div class="card">

<div class="card-title">特点</div>

- 数据（事实/规则）就是程序
- 计算由推理引擎完成
- 适合规则系统、专家系统、查询
- 代表语言：Prolog、Datalog

</div>

<div class="tip">
<span class="label">与函数式对比</span>
函数式描述“如何变换数据”，逻辑式描述“什么关系成立”；两者都属于声明式。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 为什么需要事件驱动？

---

<div class="cols">

<div class="col">

**顺序程序**

```text
输入 → 计算 → 输出 → 结束
```

适合批处理，但无法应对“用户随时可能操作”的交互场景。

</div>

<div class="col">

**事件驱动**

程序长期运行，等待事件：

- 鼠标点击
- 键盘输入
- 定时器到期
- 网络数据到达
- 窗口重绘

事件发生后，调用注册的处理函数。

</div>

</div>

<div class="fig mt1">
<svg viewBox="0 0 760 110" width="720">
  <rect x="10" y="30" width="130" height="50" rx="8" fill="#fdf6e3" stroke="#268bd2"/>
  <text x="75" y="60" font-size="14" text-anchor="middle" fill="#268bd2">事件产生</text>
  <rect x="180" y="30" width="140" height="50" rx="8" fill="#fdf6e3" stroke="#859900"/>
  <text x="250" y="60" font-size="14" text-anchor="middle" fill="#859900">事件队列</text>
  <rect x="360" y="30" width="150" height="50" rx="8" fill="#fdf6e3" stroke="#b58900"/>
  <text x="435" y="60" font-size="14" text-anchor="middle" fill="#b58900">事件循环</text>
  <rect x="550" y="30" width="150" height="50" rx="8" fill="#fdf6e3" stroke="#dc322f"/>
  <text x="625" y="60" font-size="14" text-anchor="middle" fill="#dc322f">回调/处理器</text>
  <line x1="140" y1="55" x2="180" y2="55" stroke="#93a1a1" marker-end="url(#ev)"/>
  <line x1="320" y1="55" x2="360" y2="55" stroke="#93a1a1" marker-end="url(#ev)"/>
  <line x1="510" y1="55" x2="550" y2="55" stroke="#93a1a1" marker-end="url(#ev)"/>
  <defs><marker id="ev" markerWidth="8" markerHeight="8" refX="7" refY="4" orient="auto"><path d="M0,0 L8,4 L0,8 z" fill="#93a1a1"/></marker></defs>
</svg>
</div>

<div class="small muted center">
控制反转：不是主程序调用系统，而是系统在事件发生时调用你注册的函数。
</div>

---


<!-- slide data-notes="" -->

##### 事件循环与回调

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
using Handler = std::function<void(const Event&)>;

class EventLoop {
public:
    void on(EventType type, Handler handler) {
        handlers_[type].push_back(std::move(handler));
    }

    void dispatch(const Event& e) {
        auto it = handlers_.find(e.type);
        if (it != handlers_.end()) {
            for (auto& h : it->second) {
                h(e);
            }
        }
    }
private:
    std::map<EventType, std::vector<Handler>> handlers_;
};
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">组成</div>

- 事件类型：标识“发生了什么”
- 处理器表：每种事件对应一组回调
- 分发：事件到达时依次调用
- 事件循环：不断取事件、分发、等待

</div>

<div class="pitfall">
<span class="label">响应性</span>
单个处理器不能执行太久，否则事件循环被阻塞，程序“假死”。耗时任务应交给工作线程或拆成小步骤。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 观察者模式：对象之间的订阅

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
class Subject {
public:
    void subscribe(std::function<void(int)> f) {
        observers_.push_back(std::move(f));
    }

    void notify(int value) {
        for (auto& f : observers_) {
            f(value);
        }
    }
private:
    std::vector<std::function<void(int)>> observers_;
};

Subject s;
s.subscribe([](int x) {
    std::cout << "observer: " << x << "\n";
});
s.notify(42);
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">模型</div>

- Subject：状态变化时通知观察者
- Observer：注册回调，被动接收通知
- 一对多、松耦合
- GUI、事件总线、消息队列的基础

</div>

<div class="pitfall">
<span class="label">生命周期</span>
观察者对象销毁前必须取消订阅，否则 Subject 持有悬空的回调（尤其是按引用捕获时）。用 <code>weak_ptr</code> 或显式 <code>unsubscribe</code>。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 事件驱动 vs 顺序程序

---

<div class="table-sm">

| 维度 | 顺序程序 | 事件驱动 |
| :-- | :-- | :-- |
| 控制流 | 代码顺序决定 | 事件发生决定 |
| 主结构 | 循环、函数调用 | 事件循环 + 回调 |
| 适用 | 批处理、计算密集型 | GUI、服务器、交互式 |
| 难点 | 算法与数据结构 | 状态管理、回调生命周期 |
| 响应性 | 长时间计算会阻塞 | 处理器短小、异步任务 |

</div>

<div class="keypoint mt1">
<span class="label">本质</span>
事件驱动把“什么时候执行”从代码顺序中解耦出来；代价是控制流分散，调试与状态追踪更困难。
</div>

---


<!-- slide data-notes="" -->

##### 主线案例：MiniBuild 的事件调度

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
enum class EventType { Started, Finished, Failed };

struct Event {
    EventType type;
    int target_id;
};

EventLoop loop;

loop.on(EventType::Started, [](const Event& e) {
    std::cout << "target started: " << e.target_id << "\n";
});

loop.on(EventType::Finished, [](const Event& e) {
    std::cout << "target finished: " << e.target_id << "\n";
});

loop.dispatch({EventType::Started, 1});
loop.dispatch({EventType::Finished, 1});
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">设计点</div>

- 事件只携带必要数据（类型 + ID）
- 处理器通过注册加入，不修改分发逻辑
- 新增事件类型 → 新增枚举值与处理器
- 分发循环保持稳定

</div>

<div class="tip">
<span class="label">与多态对比</span>
多态用“对象类型”分派，事件驱动用“事件类型”分派；两者都能实现开闭原则，适用场景不同。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 课堂任务 16：声明式任务统计

---

<div class="cols">

<div class="col-55">

<div class="card">

<div class="card-title">任务</div>

给定 `std::vector<Target> targets`，用声明式风格完成：

1. 过滤出未构建目标
2. 提取名称
3. 按名称排序
4. 统计名称总长度
5. 输出前 3 条

要求：

- 优先使用 C++20 Ranges 管道
- 如果环境不支持 Ranges，用 `copy_if` / `transform` / `accumulate` 组合
- 不使用手写 `for` 循环完成筛选与变换

</div>

</div>

<div class="col-45">

<div class="card">

<div class="card-title">验收标准</div>

- 管道顺序清晰：filter → transform → sort
- 不产生不必要的中间容器（Ranges 版本）
- 结果与命令式版本一致
- 代码可读性优于手写循环
- 能解释惰性求值的时机

</div>

<div class="tip">
<span class="label">提示</span>
Ranges 的 <code>views::filter</code> / <code>views::transform</code> 是惰性的；<code>sort</code> 需要具体容器，所以先 <code>ranges::to&lt;std::vector&gt;</code>（C++23）或手动收集。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 任务 16 参考实现

---

<div class="cols">

<div class="col-55 code-sm">

```cpp{.line-numbers}
#include <algorithm>
#include <numeric>
#include <ranges>
#include <vector>

auto unbuilt = targets
    | std::views::filter([](const Target& t) {
          return !t.is_built();
      })
    | std::views::transform([](const Target& t) {
          return t.name();
      });

std::vector<std::string> names(
    unbuilt.begin(), unbuilt.end());

std::sort(names.begin(), names.end());

int total_len = std::accumulate(
    names.begin(), names.end(), 0,
    [](int acc, const std::string& s) {
        return acc + static_cast<int>(s.size());
    });

for (std::size_t i = 0;
     i < names.size() && i < 3; ++i) {
    std::cout << names[i] << "\n";
}
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">要点</div>

- `filter` + `transform` 组成惰性管道
- 用迭代器区间构造 `vector`，物化结果
- `sort` 需要随机访问迭代器
- `accumulate` 做归约
- 输出阶段允许索引循环

</div>

<div class="small muted mt1">
C++23 的 <code>std::ranges::to&lt;std::vector&gt;()</code> 可以省去手动构造；当前环境若只支持 C++20，用迭代器构造即可。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 常见陷阱

---

<div class="cols">

<div class="col">

**声明式**

- 返回指向局部容器的视图 → 悬空
- 惰性管道被遍历多次 → 重复计算
- 为了“函数式”而写出难懂的柯里化
- 忽略副作用：Lambda 修改外部变量

</div>

<div class="col">

**事件驱动**

- 回调按引用捕获局部变量，对象先销毁
- 观察者忘记取消订阅
- 处理器执行太久，阻塞事件循环
- 回调中修改订阅列表，导致迭代器失效
- 事件顺序与状态不一致

</div>

</div>

<div class="pitfall">
<span class="label">原则</span>
声明式让“做什么”更清晰，事件驱动让“何时做”更灵活；两者都要求你<strong>明确数据与对象的生命周期</strong>。
</div>

---


<!-- slide data-notes="" -->

##### 课堂小测

---

1. 命令式与声明式的核心区别是什么？Ranges 管道为什么被称为“声明式”？

2. filter / map / reduce 分别对应 STL 的哪些算法？惰性求值是什么意思？

3. 事件驱动程序中，为什么处理器不能执行太久？耗时任务应该放到哪里？

4. 观察者模式中，观察者销毁前为什么必须取消订阅？可以用什么机制避免悬空回调？

---


<!-- slide data-notes="" -->

##### 小结：从“怎么做”到“做什么”，从“顺序”到“事件”

---

<div class="cols">

<div class="col">

<div class="card">

<div class="card-title">声明式</div>

- 纯函数、无副作用
- filter / map / reduce
- Ranges 管道
- 偏函数应用、柯里化
- 逻辑式编程

</div>

</div>

<div class="col">

<div class="card">

<div class="card-title">事件驱动</div>

- 事件循环
- 回调注册与分发
- 观察者模式
- 控制反转
- 响应性与生命周期

</div>

</div>

<div class="col">

<div class="card">

<div class="card-title">共同点</div>

- 把“变化”隔离出来
- 让核心逻辑更稳定
- 都需要明确所有权与生命周期
- 都是组织复杂程序的手段

</div>

</div>

</div>

<div class="motto mt1">
声明式让代码更接近<strong>问题本身</strong>，事件驱动让程序更接近<strong>真实世界的交互</strong>。
</div>

---


<!-- slide data-notes="" -->

#####

---

<div class="bottom20"></div>

<hr class="width50 center">

## 未完待续

---
