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

## 并发与多线程程序设计

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](mailto:yangyibiao@nju.edu.cn)


<!-- slide data-notes="" -->

##### 本讲提纲

---

<div class="cols">

<div class="col">

**线程基础**

- 并发 vs 并行
- 进程 vs 线程
- `std::thread`、`join` / `detach`
- 数据竞争与互斥量

</div>

<div class="col">

**同步与任务**

- 条件变量与生产者-消费者
- 原子操作
- `std::async` / `future`
- 并行算法与线程池

</div>

</div>

<div class="keypoint">
<span class="label">本讲目标</span>
能够写出线程安全的任务执行代码，识别数据竞争与死锁，并知道何时该加锁、何时不该共享。
</div>

---


<!-- slide data-notes="" -->

##### 为什么需要并发？

---

<div class="cols">

<div class="col">

**硬件趋势**

- 单核主频增长停滞（功耗墙、散热墙）
- 多核成为常态：4 核、8 核、16 核
- GPU、众核、集群提供更强并行能力
- 程序若不并行，就无法利用这些核心

</div>

<div class="col">

**软件需求**

- 响应式界面：主线程不能被耗时任务阻塞
- 服务器：同时处理大量连接
- 数据处理：分块计算、流水线
- 任务调度：多个独立任务并行执行

</div>

</div>

<div class="motto mt1">
并发不是为了“显得高级”，而是为了<strong>充分利用硬件、保持程序响应、提高吞吐量</strong>。
</div>

---


<!-- slide data-notes="" -->

##### 并发 vs 并行

---

<div class="cols">

<div class="col">

**并发（concurrency）**

- 同一时间段内交替处理多个任务
- 关注程序结构：任务如何分解、如何通信
- 单核上通过时间片轮转也能并发

<div class="timeline mt1">
<div class="tl-row"><span class="tl-label">CPU</span><div class="tl-track"><div class="tl-bar b1" style="left:0;width:30%;">A</div><div class="tl-bar b2" style="left:32%;width:28%;">B</div><div class="tl-bar b1" style="left:62%;width:28%;">A</div></div></div>
</div>

</div>

<div class="col">

**并行（parallelism）**

- 同一时刻内同时处理多个任务
- 关注硬件执行：多个核心真正同时工作
- 需要多核/多机支持

<div class="timeline mt1">
<div class="tl-row"><span class="tl-label">核 1</span><div class="tl-track"><div class="tl-bar b1" style="left:0;width:85%;">A</div></div></div>
<div class="tl-row"><span class="tl-label">核 2</span><div class="tl-track"><div class="tl-bar b2" style="left:0;width:85%;">B</div></div></div>
</div>

</div>

</div>

<div class="small muted center">
并发是“同时处理”的结构，并行是“同时执行”的事实；并发程序在多核上才可能真正并行。
</div>

---


<!-- slide data-notes="" -->

##### 进程与线程

---

<div class="table-sm">

| 维度 | 进程 | 线程 |
| :-- | :-- | :-- |
| 资源 | 独立地址空间、文件描述符 | 共享进程的堆、全局数据、代码 |
| 私有 | 代码、数据、堆、栈 | 栈、寄存器、程序计数器 |
| 创建开销 | 较大 | 较小 |
| 通信 | 进程间通信（管道、共享内存） | 直接读写共享变量 |
| 崩溃影响 | 通常隔离 | 一个线程崩溃可能拖垮整个进程 |

</div>

<div class="keypoint mt1">
<span class="label">关键</span>
线程共享地址空间，带来高效通信，也带来<strong>数据竞争</strong>。本讲大部分复杂问题都源于“共享 + 并发修改”。
</div>

---


<!-- slide data-notes="" -->

##### `std::thread`：创建第一个线程

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
#include <iostream>
#include <thread>

void hello() {
    std::cout << "hello from thread\n";
}

int main() {
    std::thread t(hello);   // 线程立即开始运行
    std::cout << "hello from main\n";
    t.join();               // 等待 t 结束
}
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">要点</div>

- `std::thread` 对象创建即启动线程
- 构造函数接收可调用对象 + 参数
- 主线程必须 `join` 或 `detach`
- `join`：阻塞等待线程结束
- `detach`：让线程在后台运行

</div>

<div class="pitfall">
<span class="label">析构陷阱</span>
如果 <code>std::thread</code> 对象析构时仍处于 joinable 状态（既没 join 也没 detach），程序会调用 <code>std::terminate</code>。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### Lambda 与带参线程

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
std::thread t1([] {
    std::cout << "lambda thread\n";
});

std::thread t2([](int x, int y) {
    std::cout << x + y << "\n";
}, 3, 4);

int value = 10;
std::thread t3([value] {
    std::cout << value << "\n";   // 按值捕获副本
});

t1.join();
t2.join();
t3.join();
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">参数传递</div>

- 参数默认按值复制到线程存储
- 需要引用时用 `std::ref(x)` / `std::cref(x)`
- 引用参数必须保证对象活得比线程长
- Lambda 捕获按值更安全，按引用要小心生命周期

</div>

<div class="pitfall">
<span class="label">悬空引用</span>
<code>std::thread t(f, std::ref(local)); t.detach();</code>：<code>local</code> 离开作用域后，线程仍在访问它——未定义行为。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### `join` vs `detach`

---

<div class="cols">

<div class="col">

**`join`：等待并回收**

```cpp
std::thread t(work);
t.join();
// 此处 t 已结束，资源已回收
```

- 主线程阻塞，直到子线程结束
- 可以安全读取子线程写入的数据
- 推荐默认使用

</div>

<div class="col">

**`detach`：放养**

```cpp
std::thread t(work);
t.detach();
// t 在后台运行，主线程继续
```

- 主线程失去控制
- 主线程结束时，进程退出，后台线程被终止
- 后台线程不能访问已销毁的对象

</div>

</div>

<div class="pitfall">
<span class="label">工程建议</span>
初学者应始终 <code>join</code>。只有明确知道线程会活多久、访问哪些对象时，才考虑 <code>detach</code>。
</div>

---


<!-- slide data-notes="" -->

##### 线程标识与休眠

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
#include <chrono>
#include <thread>

void work(int id) {
    std::cout << "thread " << id
              << " id=" << std::this_thread::get_id()
              << "\n";
    std::this_thread::sleep_for(
        std::chrono::milliseconds(100));
}

std::thread t1(work, 1);
std::thread t2(work, 2);
t1.join();
t2.join();
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">常用 API</div>

- `std::this_thread::get_id()`
- `std::this_thread::sleep_for(duration)`
- `std::this_thread::sleep_until(time_point)`
- `std::this_thread::yield()`

</div>

<div class="tip">
<span class="label">调试</span>
多线程输出会交错；调试时先打印线程 ID，或让每个线程输出到独立缓冲区，最后统一输出。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 数据竞争：一行代码不是原子操作

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
long long sum = 0;

void add(int n) {
    for (int i = 0; i < n; ++i) {
        sum += i;        // 读-改-写，非原子
    }
}

std::thread t1(add, 100000);
std::thread t2(add, 100000);
t1.join();
t2.join();
std::cout << sum;        // 结果不确定
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">`sum += i` 的三步</div>

1. 从内存读取 `sum` 到寄存器
2. 寄存器加上 `i`
3. 写回内存

两个线程可能同时读到旧值，各自加完后写回，后写的覆盖先写的——更新丢失。

</div>

<div class="pitfall">
<span class="label">数据竞争</span>
多个线程同时访问同一内存，至少一个线程在写，且没有同步——这就是 data race，属于未定义行为。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 互斥量：给临界区加锁

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
#include <mutex>

std::mutex m;
long long sum = 0;

void add(int n) {
    long long local = 0;
    for (int i = 0; i < n; ++i) {
        local += i;             // 局部累加，无竞争
    }
    std::lock_guard<std::mutex> lock(m);
    sum += local;               // 只保护共享写入
}
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">锁的规则</div>

- 访问共享数据前 `lock`
- 访问完成后 `unlock`
- 同一时刻只有一个线程持有互斥量
- 用 `lock_guard` / `unique_lock` 自动释放

</div>

<div class="keypoint">
<span class="label">性能</span>
锁的粒度要小：把能局部计算的部分放在锁外，只保护真正的共享写入。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 锁粒度：从 74 秒到 451 毫秒

---

<div class="cols">

<div class="col">

**错误：锁在循环内**

```cpp
for (int i = 0; i < n; ++i) {
    std::lock_guard<std::mutex> lock(m);
    sum += std::sqrt(i);
}
```

- 1 亿次循环抢同一把锁
- 大量时间花在等待与上下文切换
- 可能比单线程还慢

</div>

<div class="col">

**正确：局部累加，最后合并**

```cpp
long long local = 0;
for (int i = 0; i < n; ++i) {
    local += std::sqrt(i);
}
{
    std::lock_guard<std::mutex> lock(m);
    sum += local;
}
```

- 每个线程独立计算
- 只在合并时加一次锁

</div>

</div>

<div class="keypoint mt1">
<span class="label">原则</span>
临界区越短越好；能用局部变量/线程私有数据解决的，不要放进共享区。
</div>

---


<!-- slide data-notes="" -->

##### 死锁：两个线程互相等待

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
std::mutex m1, m2;

void f() {
    std::lock_guard<std::mutex> a(m1);
    std::lock_guard<std::mutex> b(m2);   // 等待 m2
}

void g() {
    std::lock_guard<std::mutex> b(m2);
    std::lock_guard<std::mutex> a(m1);   // 等待 m1
}
```

线程 1 持有 `m1` 等 `m2`，线程 2 持有 `m2` 等 `m1` → 永久等待。

</div>

<div class="col-45">

<div class="card">

<div class="card-title">避免死锁</div>

- 所有线程按**相同顺序**加锁
- 用 `std::scoped_lock` 一次锁多个互斥量（C++17）
- 尽量减少同时持有的锁
- 使用超时锁 `try_lock_for`

</div>

```cpp
std::scoped_lock lock(m1, m2);  // 原子地锁住两个
```

<div class="small muted mt1">
死锁也可能由“持锁时调用外部回调”引起；回调里又去拿同一把锁，同样会卡住。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 条件变量：等待某个条件成立

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
#include <condition_variable>

std::mutex m;
std::condition_variable cv;
std::queue<Target> q;
bool done = false;

// 消费者
void consume() {
    std::unique_lock<std::mutex> lock(m);
    cv.wait(lock, [&] {
        return !q.empty() || done;
    });
    if (!q.empty()) {
        Target t = q.front();
        q.pop();
        // ...
    }
}
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">三件套</div>

- 互斥量：保护共享状态
- 条件变量：等待/通知
- 谓词：判断条件是否满足

</div>

<div class="pitfall">
<span class="label">虚假唤醒</span>
<code>wait</code> 可能无通知返回（spurious wakeup）。必须用谓词版本 <code>wait(lock, pred)</code>，醒来后重新检查条件。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 生产者-消费者

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
void producer(int n) {
    for (int i = 0; i < n; ++i) {
        {
            std::lock_guard<std::mutex> lock(m);
            q.push(Target(i, "job", 1));
        }
        cv.notify_one();
    }
    {
        std::lock_guard<std::mutex> lock(m);
        done = true;
    }
    cv.notify_all();
}

void consumer() {
    while (true) {
        std::unique_lock<std::mutex> lock(m);
        cv.wait(lock, [&] {
            return !q.empty() || done;
        });
        if (q.empty() && done) break;
        Target t = q.front();
        q.pop();
        lock.unlock();
        t.run();       // 耗时操作放在锁外
    }
}
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">要点</div>

- 生产者在锁内修改队列，锁外通知
- 消费者用 `unique_lock` 配合 `wait`
- 取出任务后解锁，再执行耗时操作
- `done` 用同一把锁保护
- 结束条件要能让所有消费者退出

</div>

<div class="small muted mt1">
条件变量必须与互斥量配合使用；单独一个 <code>condition_variable</code> 无法保护共享状态。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 原子操作：最小的同步单元

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
#include <atomic>

std::atomic<int> counter{0};

void increment(int n) {
    for (int i = 0; i < n; ++i) {
        counter.fetch_add(1, std::memory_order_relaxed);
    }
}

std::thread t1(increment, 100000);
std::thread t2(increment, 100000);
t1.join(); t2.join();
std::cout << counter;   // 200000
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">适用场景</div>

- 单个变量的读/写/加减
- 标志位、计数器、引用计数
- 不需要保护多个变量之间的不变量

</div>

<div class="pitfall">
<span class="label">不是万能</span>
<code>atomic</code> 只保证单个操作的原子性；多个变量之间的复合条件仍需要互斥量。默认先用 <code>mutex</code>，性能确实需要时再考虑原子操作。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### `std::async` 与 `future`

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
#include <future>
#include <iostream>

int compute(int x) {
    std::this_thread::sleep_for(
        std::chrono::seconds(1));
    return x * x;
}

int main() {
    auto f = std::async(std::launch::async,
                        compute, 12);
    // 主线程可以继续做别的事
    int result = f.get();   // 等待并取结果
    std::cout << result;    // 144
}
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">特点</div>

- 把“启动任务”和“取结果”分离
- `get()` 阻塞直到任务完成
- 异常会通过 `future` 传播到 `get()`
- 适合“一次性异步计算”，不适合长期线程池

</div>

<div class="tip">
<span class="label">launch 策略</span>
<code>std::launch::async</code> 强制新线程；<code>std::launch::deferred</code> 延迟到 <code>get()</code> 时才执行；不指定则由实现决定。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 并行算法 <span class="std cxx17">C++17</span>

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
#include <algorithm>
#include <execution>
#include <vector>

std::vector<int> v = make_data();

std::sort(std::execution::par,
          v.begin(), v.end());

std::for_each(std::execution::par_unseq,
              v.begin(), v.end(),
              [](int& x) { x *= 2; });
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">执行策略</div>

- `seq`：顺序
- `par`：并行
- `par_unseq`：并行 + 向量化
- `unseq`：向量化（C++20）

</div>

<div class="pitfall">
<span class="label">要求</span>
传给并行算法的操作不能有数据竞争；不能依赖执行顺序。实现支持程度取决于标准库（GCC 需要 TBB 等）。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 线程池：复用线程，控制并发度

---

<div class="cols">

<div class="col-55">

**为什么需要线程池**

- 每个任务创建一个线程，开销大
- 线程数量不受控，可能耗尽资源
- 需要统一的任务队列与关闭机制

**基本结构**

<div class="flow" style="flex-direction:column;width:100%;margin:0.2rem 0;">
<div class="flow-step"><strong>任务队列</strong>存放待执行任务</div>
<div class="flow-step"><strong>工作线程</strong>循环取任务执行</div>
<div class="flow-step"><strong>同步机制</strong>mutex + condition_variable</div>
<div class="flow-step"><strong>关闭</strong>设置停止标志并唤醒所有线程</div>
</div>

</div>

<div class="col-45">

<div class="card">

<div class="card-title">任务表示</div>

```cpp
using Job = std::function<void()>;

std::queue<Job> jobs;
std::mutex m;
std::condition_variable cv;
bool stop = false;
```

<div class="small muted mt1">
<code>std::function</code> 可以存放 Lambda、函数指针、函数对象；任务参数通过 Lambda 捕获。
</div>

</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 主线案例：`Scheduler` 的接口

---

<div class="cols">

<div class="col-55 code-xs">

```cpp{.line-numbers}
class Scheduler {
public:
    void submit(std::function<void()> job) {
        {
            std::lock_guard<std::mutex> lock(m_);
            jobs_.push(std::move(job));
        }
        cv_.notify_one();
    }

    void start(int n) {
        for (int i = 0; i < n; ++i) {
            workers_.emplace_back(
                [this] { worker(); });
        }
    }

    void stop() {
        {
            std::lock_guard<std::mutex> lock(m_);
            stop_ = true;
        }
        cv_.notify_all();
        for (auto& t : workers_) t.join();
    }

private:
    void worker();

    std::queue<std::function<void()>> jobs_;
    std::mutex m_;
    std::condition_variable cv_;
    bool stop_ = false;
    std::vector<std::thread> workers_;
};
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">接口语义</div>

- `submit`：把任务放入队列，唤醒一个工作线程
- `start`：创建工作线程
- `stop`：设置停止标志，唤醒所有线程并 `join`
- 共享状态由 `m_` 保护

</div>

<div class="tip">
<span class="label">为什么 stop 要 notify_all</span>
所有工作线程都可能在 `cv_` 上等待；只唤醒一个，其他线程会永远睡下去，<code>join</code> 就会卡住。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 主线案例：`Scheduler` 的工作线程

---

<div class="cols">

<div class="col-55 code-sm">

```cpp{.line-numbers}
void Scheduler::worker() {
    while (true) {
        std::function<void()> job;
        {
            std::unique_lock<std::mutex> lock(m_);
            cv_.wait(lock, [this] {
                return stop_ || !jobs_.empty();
            });
            if (stop_ && jobs_.empty()) {
                return;
            }
            job = std::move(jobs_.front());
            jobs_.pop();
        }
        job();   // 锁外执行，避免阻塞其他线程
    }
}
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">工作线程循环</div>

1. 加锁，等待“有任务或要停止”
2. 停止且队列为空 → 退出
3. 取出任务
4. 解锁后执行任务
5. 回到 1

</div>

<div class="pitfall">
<span class="label">关键</span>
<code>job()</code> 必须放在锁外；否则一个耗时任务会阻塞所有工作线程，线程池退化成单线程。
</div>

</div>

</div>

---
<!-- slide data-notes="" -->

##### 课堂任务 15：修复并行求和的竞争

---

<div class="cols">

<div class="col-55">

<div class="card">

<div class="card-title">任务</div>

下面代码的结果不正确：

```cpp
long long sum = 0;
void add(int from, int to) {
    for (int i = from; i < to; ++i)
        sum += i;
}
```

要求：

1. 用 `std::thread` 启动 4 个线程，分块计算
2. 消除数据竞争
3. 比较三种方案：
   - 每块局部累加，最后加锁合并
   - 每次累加都加锁
   - `std::atomic<int>`
4. 输出结果并解释性能差异

</div>

</div>

<div class="col-45">

<div class="card">

<div class="card-title">验收标准</div>

- 多次运行结果一致且正确
- ASan 无数据竞争报告（或 TSan）
- 局部累加方案明显快于每次加锁
- 线程全部 `join`
- 不使用全局裸指针

</div>

<div class="tip">
<span class="label">提示</span>
先用 <code>-fsanitize=thread</code> 检测数据竞争；正确性确认后再比较性能。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 任务 15 参考实现（局部累加）

---

<div class="cols">

<div class="col-55 code-sm">

```cpp{.line-numbers}
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

long long sum = 0;
std::mutex m;

void add_range(int from, int to) {
    long long local = 0;
    for (int i = from; i < to; ++i) {
        local += i;
    }
    std::lock_guard<std::mutex> lock(m);
    sum += local;
}

int main() {
    const int n = 1000000;
    const int k = 4;
    std::vector<std::thread> threads;
    for (int i = 0; i < k; ++i) {
        threads.emplace_back(add_range,
                             i * n / k,
                             (i + 1) * n / k);
    }
    for (auto& t : threads) t.join();
    std::cout << sum << "\n";
}
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">比较</div>

- 局部累加 + 一次锁：竞争最少，通常最快
- 每次 `sum += i` 加锁：锁竞争激烈，可能比单线程慢
- `atomic`：正确，但每次累加仍有原子操作开销
- 分块大小影响负载均衡

</div>

<div class="pitfall">
<span class="label">注意</span>
<code>sum</code> 是 <code>long long</code>，避免 32 位溢出；分块边界要覆盖 <code>[0, n)</code> 且不重叠。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 常见陷阱

---

<div class="cols">

<div class="col">

**线程生命周期**

- 忘记 `join` / `detach` → `terminate`
- `detach` 后访问局部变量
- 主线程结束，后台线程被杀死
- 异常路径跳过 `join`

</div>

<div class="col">

**同步**

- 数据竞争（未加锁）
- 锁粒度过大
- 死锁（加锁顺序不一致）
- 条件变量不用谓词 → 虚假唤醒
- 用 `atomic` 保护多个变量的不变量
- 在持锁时执行耗时操作/回调

</div>

</div>

<div class="pitfall">
<span class="label">调试</span>
并发 bug 往往偶发。用 ThreadSanitizer（<code>-fsanitize=thread</code>）检测竞争，用日志记录线程 ID 与关键状态变化。
</div>

---


<!-- slide data-notes="" -->

##### 课堂小测

---

1. 并发与并行的区别是什么？单核 CPU 上能实现并发吗？能实现并行吗？

2. `std::thread` 对象析构时既没有 `join` 也没有 `detach`，会发生什么？

3. `sum += i` 为什么不是原子操作？互斥量如何解决这个问题？

4. 条件变量的 `wait(lock, pred)` 中，谓词的作用是什么？为什么不能只用 `wait(lock)`？

---


<!-- slide data-notes="" -->

##### 小结：共享要有秩序

---

<div class="cols">

<div class="col">

<div class="card">

<div class="card-title">线程</div>

- `std::thread` 创建即运行
- `join` 等待，`detach` 放养
- 参数默认按值复制
- 生命周期必须明确

</div>

</div>

<div class="col">

<div class="card">

<div class="card-title">同步</div>

- 数据竞争 = 未定义行为
- `mutex` + `lock_guard`
- 临界区尽量小
- 条件变量 + 谓词
- 原子操作只适合单变量

</div>

</div>

<div class="col">

<div class="card">

<div class="card-title">任务</div>

- `async` / `future` 取结果
- 并行算法一行加速
- 线程池复用线程
- 先正确，再优化

</div>

</div>

</div>

<div class="motto mt1">
并发编程的第一原则：<strong>能不共享就不共享</strong>；必须共享时，用清晰的同步策略保护它。
</div>

---


<!-- slide data-notes="" -->

#####

---

<div class="bottom20"></div>

<hr class="width50 center">

## 未完待续

---
