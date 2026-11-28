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

## 异常处理与程序健壮性

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](mailto:yangyibiao@nju.edu.cn)


<!-- slide data-notes="" -->

##### 本讲提纲

---

<div class="cols">

<div class="col">

**异常机制**

- 为什么需要异常
- `throw` / `try` / `catch`
- 栈展开与捕获规则
- 标准异常与自定义异常

</div>

<div class="col">

**健壮性**

- 异常安全保证
- RAII 与 `noexcept`
- 断言与调试
- Sanitizer 工具

</div>

</div>

<div class="keypoint">
<span class="label">本讲目标</span>
能够区分“可恢复错误”与“程序缺陷”，用异常表达前者、用断言捕获后者，并写出异常安全的资源管理代码。
</div>

---


<!-- slide data-notes="" -->

##### 错误从哪里来？

---

<div class="table-sm">

| 类型 | 例子 | 发现时机 | 处理方式 |
| :-- | :-- | :-- | :-- |
| 语法错误 | 漏分号、括号不匹配 | 编译期 | 编译器报错 |
| 逻辑错误 | 排序写错、边界算错 | 测试/调试 | 断言、测试、调试器 |
| 运行时错误 | 文件不存在、除零、内存不足 | 运行期 | 异常、返回值、错误码 |

</div>

<div class="cols mt1">

<div class="col">

**可以预料但无法避免**

- 用户输入非法
- 文件打不开
- 网络断开
- 磁盘写满

</div>

<div class="col">

**程序缺陷**

- 数组越界
- 空指针解引用
- 忘记释放资源
- 逻辑条件写反

</div>

</div>

<div class="keypoint">
<span class="label">区分</span>
运行时错误用<strong>异常</strong>表达并处理；程序缺陷用<strong>断言/测试/工具</strong>尽早暴露，不应靠异常“兜底”。
</div>

---


<!-- slide data-notes="" -->

##### 没有异常时：返回码的困境

---

<div class="cols">

<div class="col-55">

```cpp
int divide(int a, int b, int& result) {
    if (b == 0) return -1;   // 用返回值表示错误
    result = a / b;
    return 0;
}

int main() {
    int r;
    if (divide(10, 0, r) != 0) {
        // 处理错误
    }
    // 如果调用链有 5 层，每层都要检查并传递错误码
}
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">问题</div>

- 正常返回值与错误码混在一起
- 每层调用都要检查，容易漏
- 错误处理代码与业务代码交织
- 构造函数无法返回错误码
- 运算符重载无法增加错误参数

</div>

<div class="tip">
<span class="label">异常的优势</span>
错误可以跨越多层函数，直接交给有能力处理的调用方；中间层不需要写任何检查代码。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### `throw` / `try` / `catch`

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
#include <iostream>
#include <stdexcept>

double divide(int a, int b) {
    if (b == 0) {
        throw std::invalid_argument("divide by zero");
    }
    return static_cast<double>(a) / b;
}

int main() {
    try {
        double x = divide(10, 0);
        std::cout << x;
    } catch (const std::invalid_argument& e) {
        std::cerr << "error: " << e.what() << "\n";
    }
}
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">三个关键字</div>

- `throw`：抛出异常对象，当前函数立即停止
- `try`：标记可能抛异常的代码块
- `catch`：按类型捕获并处理

</div>

<div class="small muted mt1">
<code>catch</code> 按<strong>类型匹配</strong>，不是按值相等；可以捕获基类来统一处理派生异常。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 栈展开：异常如何跨函数传播

---

<div class="cols">

<div class="col-55">

```cpp
void h() { throw std::runtime_error("boom"); }

void g() {
    Buffer b(100);   // 局部对象
    h();             // 异常从这里向外传播
}

void f() {
    try {
        g();
    } catch (const std::exception& e) {
        std::cout << e.what();
    }
}
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">过程</div>

1. `h` 抛出异常，`h` 的局部对象析构
2. 沿调用链查找匹配的 `catch`
3. 经过 `g` 时，`b` 析构（RAII 生效）
4. 在 `f` 中找到 `catch`，转入处理

</div>

<div class="keypoint">
<span class="label">关键</span>
栈展开会销毁沿途所有已构造的局部对象；这就是 RAII 能保证异常安全的原因。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 捕获规则：按引用、从具体到一般

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
try {
    might_throw();
}
catch (const std::invalid_argument& e) {
    // 最具体的类型放前面
}
catch (const std::runtime_error& e) {
    // ...
}
catch (const std::exception& e) {
    // 所有标准异常的基类
}
catch (...) {
    // 兜底：未知异常
}
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">规则</div>

- 按 `const T&` 捕获，避免拷贝和切片
- 派生类异常要放在基类前面
- `catch (...)` 只能放在最后
- 捕获后可以重新 `throw;` 交给外层

</div>

<div class="pitfall">
<span class="label">不要按值捕获</span>
<code>catch (std::exception e)</code> 会把派生异常切片成基类对象，丢失 <code>what()</code> 的具体信息。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 标准异常体系

---

<div class="cols">

<div class="col-55">

<div class="fig">
<svg viewBox="0 0 500 210" width="460">
  <rect x="170" y="10" width="160" height="38" rx="6" fill="#fdf6e3" stroke="#586e75"/>
  <text x="250" y="34" font-size="14" text-anchor="middle" fill="#586e75">std::exception</text>
  <rect x="25" y="85" width="130" height="34" rx="6" fill="#fdf6e3" stroke="#dc322f"/>
  <text x="90" y="107" font-size="13" text-anchor="middle" fill="#dc322f">logic_error</text>
  <rect x="175" y="85" width="150" height="34" rx="6" fill="#fdf6e3" stroke="#b58900"/>
  <text x="250" y="107" font-size="13" text-anchor="middle" fill="#b58900">runtime_error</text>
  <rect x="345" y="85" width="130" height="34" rx="6" fill="#fdf6e3" stroke="#859900"/>
  <text x="410" y="107" font-size="13" text-anchor="middle" fill="#859900">bad_alloc</text>
  <rect x="25" y="155" width="130" height="34" rx="6" fill="#fdf6e3" stroke="#93a1a1"/>
  <text x="90" y="177" font-size="12" text-anchor="middle" fill="#657b83">invalid_argument</text>
  <rect x="175" y="155" width="150" height="34" rx="6" fill="#fdf6e3" stroke="#93a1a1"/>
  <text x="250" y="177" font-size="12" text-anchor="middle" fill="#657b83">out_of_range</text>
  <line x1="230" y1="48" x2="90" y2="85" stroke="#93a1a1"/>
  <line x1="250" y1="48" x2="250" y2="85" stroke="#93a1a1"/>
  <line x1="270" y1="48" x2="410" y2="85" stroke="#93a1a1"/>
</svg>
</div>

</div>

<div class="col-45">

<div class="card">

<div class="card-title">常用类型</div>

- `std::invalid_argument`
- `std::out_of_range`
- `std::runtime_error`
- `std::bad_alloc`
- `std::logic_error`

</div>

<div class="small muted mt1">
<code>what()</code> 返回错误描述；自定义异常通常继承 <code>std::runtime_error</code> 或 <code>std::logic_error</code>。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 自定义异常

---

<div class="cols">

<div class="col-55">

```cpp
class BuildError : public std::runtime_error {
public:
    explicit BuildError(const std::string& message)
        : std::runtime_error(message) {}
};

class TargetNotFound : public BuildError {
public:
    explicit TargetNotFound(int id)
        : BuildError("target not found: " +
                    std::to_string(id)) {}
};

void find_target(int id) {
    if (!exists(id)) throw TargetNotFound(id);
}
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">设计建议</div>

- 继承标准异常，复用 `what()`
- 异常类只保存描述错误所需的信息
- 按业务层次建立异常类型
- 不要抛裸指针/裸字符串

</div>

<div class="tip">
<span class="label">捕获</span>
调用方可以捕获 <code>TargetNotFound</code> 做精确处理，也可以捕获 <code>BuildError</code> 或 <code>std::exception</code> 统一处理。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 异常安全：三种保证

---

<div class="table-sm">

| 保证 | 含义 | 例子 |
| :-- | :-- | :-- |
| 基本保证 | 不泄漏资源，对象仍可析构/继续使用 | 大多数函数的最低要求 |
| 强保证 | 操作要么成功，要么回到调用前状态 | 拷贝并交换 |
| 不抛保证 | 承诺不抛异常 | 析构、`swap`、移动构造 |

</div>

<div class="cols mt1">

<div class="col">

```cpp
// 强保证：先分配，再修改
char* p = new char[n];
delete[] data_;
data_ = p;     // 分配失败时旧对象不变
```

</div>

<div class="col">

```cpp
// 不抛保证
void swap(String& other) noexcept;
~String() noexcept;
Buffer(Buffer&&) noexcept;
```

</div>

</div>

<div class="keypoint">
<span class="label">选择</span>
资源管理类通常追求“基本保证 + 析构不抛”；修改对象的操作可以根据需要提供强保证；移动/交换/析构提供不抛保证。
</div>

---


<!-- slide data-notes="" -->

##### RAII 是异常安全的基石

---

<div class="cols">

<div class="col-55">

```cpp
void process() {
    Buffer a(100);
    FileHandle f("data.txt");
    LockGuard guard(mutex);

    may_throw();   // 异常在这里抛出

    // 正常路径：guard -> f -> a 逆序析构
}
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">为什么有效</div>

- 资源在构造函数中获取
- 析构函数在栈展开时自动调用
- 不需要为每条 `return` / `throw` 路径写清理代码
- 清理逻辑集中在一处

</div>

<div class="pitfall">
<span class="label">反例</span>
手动 <code>new</code>、手动 <code>lock</code>、手动 <code>fopen</code> 的代码，一旦中途抛异常，清理代码可能永远执行不到。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### `noexcept`：承诺不抛异常

---

<div class="cols">

<div class="col-55">

```cpp
class Buffer {
public:
    Buffer(Buffer&& other) noexcept;
    ~Buffer() noexcept;
    void swap(Buffer& other) noexcept;
};

void f() noexcept;   // 如果 f 抛异常 -> std::terminate
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">为什么重要</div>

- `std::vector` 扩容时优先使用 `noexcept` 的移动构造
- 析构函数默认 `noexcept`，抛异常会 terminate
- `swap` 不抛是拷贝并交换提供强保证的前提

</div>

<div class="pitfall">
<span class="label">不要滥用</span>
只有确实不会抛出（或能处理所有异常）的函数才标记 <code>noexcept</code>；错误承诺会直接终止程序。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 断言：捕获“不应该发生”的事

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
#include <cassert>
#include <iostream>

int divide(int a, int b) {
    assert(b != 0);   // 程序缺陷，不是用户输入错误
    return a / b;
}

int main() {
    int x;
    std::cin >> x;
    assert(x > 0 && "x must be positive");
}
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">assert 的行为</div>

- 表达式为真：继续执行
- 表达式为假：打印文件、行号、表达式，调用 `abort`
- 定义 `NDEBUG` 后失效（发布版本）

</div>

<div class="tip">
<span class="label">适用边界</span>
断言用于“程序员认为不可能发生”的内部条件；用户输入错误、文件不存在等可恢复错误用异常或返回值。
</div>

</div>

</div>

<div class="small muted center">
编译时定义：<code>g++ -DNDEBUG ...</code>；断言不应有副作用（如 <code>assert(i++)</code>），因为发布版本会把它删掉。
</div>

---


<!-- slide data-notes="" -->

##### 调试工具：让错误自己暴露

---

<div class="cols">

<div class="col">

**Sanitizer**

```bash
g++ -std=c++17 -g \
  -fsanitize=address,undefined \
  main.cpp -o main
./main
```

- AddressSanitizer：越界、UAF、泄漏
- UndefinedBehaviorSanitizer：溢出、空指针、对齐
- 运行开销较大，适合开发/测试

</div>

<div class="col">

**调试器**

```bash
g++ -std=c++17 -g main.cpp -o main
lldb ./main
# 或 gdb ./main
```

- 断点、单步、查看变量
- 观察调用栈
- 条件断点定位偶发问题

</div>

</div>

<div class="keypoint">
<span class="label">组合</span>
先用编译警告发现明显问题，再用断言检查内部不变量，最后用 Sanitizer/调试器定位运行时错误。
</div>

---


<!-- slide data-notes="" -->

##### 主线案例：`TargetRepository` 的错误处理

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
class BuildError : public std::runtime_error {
public:
    explicit BuildError(const std::string& msg)
        : std::runtime_error(msg) {}
};

class TargetRepository {
public:
    explicit TargetRepository(std::string path)
        : path_(std::move(path)) {}

    std::vector<Target> load() const {
        std::ifstream in(path_);
        if (!in) {
            throw BuildError("cannot open: " + path_);
        }
        // ... 解析，格式错误抛 BuildError
    }
private:
    std::string path_;
};
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">设计选择</div>

- 文件打不开：异常（调用方可能换路径重试）
- 单行格式错误：跳过并记录，或抛异常
- 保存失败：抛异常或返回 `bool`
- 异常类型携带上下文（路径、行号）

</div>

<div class="tip">
<span class="label">一致性</span>
同一个模块内统一策略：要么全部用异常，要么全部用返回码。不要一半异常一半错误码。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 课堂任务 11：安全的整数解析

---

<div class="cols">

<div class="col-55">

<div class="card">

<div class="card-title">任务</div>

实现 `int parse_priority(const std::string& s)`：

- 合法范围：`1..5`
- 非数字：抛 `std::invalid_argument`
- 超出范围：抛 `std::out_of_range`
- 成功返回整数
- 在 `main` 中读取多行输入，逐行解析；捕获异常并输出错误信息，程序不终止

</div>

</div>

<div class="col-45">

<div class="card">

<div class="card-title">验收标准</div>

- `"3"` → 3
- `"abc"` → `invalid_argument`
- `"0"`、`"6"` → `out_of_range`
- 捕获时使用 `const std::exception&`
- 一条输入出错后，后续输入仍能继续处理

</div>

<div class="tip">
<span class="label">提示</span>
<code>std::stoi</code> 会抛 <code>invalid_argument</code> / <code>out_of_range</code>；但它的 <code>out_of_range</code> 表示超出 <code>int</code> 范围，不是 1..5。业务范围需要自己检查并抛出。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 任务 11 参考实现

---

<div class="cols">

<div class="col-55 code-sm">

```cpp{.line-numbers}
#include <iostream>
#include <stdexcept>
#include <string>

int parse_priority(const std::string& s) {
    int value = std::stoi(s);   // 可能抛异常
    if (value < 1 || value > 5) {
        throw std::out_of_range(
            "priority must be in [1,5]: " + s);
    }
    return value;
}

int main() {
    std::string line;
    while (std::getline(std::cin, line)) {
        try {
            int p = parse_priority(line);
            std::cout << "ok: " << p << "\n";
        } catch (const std::exception& e) {
            std::cout << "error: " << e.what() << "\n";
        }
    }
}
```

</div>

<div class="col-45">

**输入/输出**

<div class="out">3
ok: 3
abc
error: stoi
0
error: priority must be in [1,5]: 0
5
ok: 5</div>

<div class="small mt1">

**要点**

- `stoi` 负责语法转换
- 业务范围由 `parse_priority` 检查
- 按 `const std::exception&` 捕获
- 循环继续，程序不终止
- 异常信息包含原始输入

</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 常见陷阱

---

<div class="cols">

<div class="col">

**抛出/捕获**

- 抛裸指针、裸字符串
- 按值捕获导致切片
- 捕获顺序错误（基类在前）
- 析构函数中抛异常
- 异常穿过 C 接口

</div>

<div class="col">

**使用方式**

- 用异常处理正常控制流
- 忘记 `catch` 导致程序终止
- 捕获后吞掉异常，不记录
- 在 `noexcept` 函数中抛异常
- 资源未 RAII 化，异常路径泄漏

</div>

</div>

<div class="pitfall">
<span class="label">原则</span>
异常用于<strong>异常情况</strong>，不是 `if` 的替代品；每个异常都应有人处理，或者明确让程序终止。
</div>

---


<!-- slide data-notes="" -->

##### 课堂小测

---

1. 异常从抛出到被捕获，中间函数的局部对象会怎样？这与 RAII 有什么关系？

2. 为什么 `catch` 应该按 `const T&` 捕获，并且派生类异常要放在基类前面？

3. 异常安全的三种保证分别是什么？`std::vector` 扩容为什么偏好 `noexcept` 的移动构造？

4. `assert` 与异常分别适合处理什么类型的错误？定义 `NDEBUG` 后 `assert` 会怎样？

---


<!-- slide data-notes="" -->

##### 小结：让错误有秩序地传播

---

<div class="cols">

<div class="col">

<div class="card">

<div class="card-title">异常</div>

- `throw` 表达错误
- 栈展开自动清理
- 按引用捕获
- 自定义异常携带上下文

</div>

</div>

<div class="col">

<div class="card">

<div class="card-title">安全</div>

- RAII 保证资源释放
- 基本/强/不抛三种保证
- `noexcept` 是承诺
- 析构不抛异常

</div>

</div>

<div class="col">

<div class="card">

<div class="card-title">健壮性</div>

- 断言捕获程序缺陷
- Sanitizer 发现未定义行为
- 调试器定位偶发问题
- I/O 必须检查失败

</div>

</div>

</div>

<div class="motto mt1">
好的错误处理不是“让程序不崩溃”，而是<strong>让错误在正确的地方被表达、被传播、被处理</strong>。
</div>

---


<!-- slide data-notes="" -->

#####

---

<div class="bottom20"></div>

<hr class="width50 center">

## 未完待续

---
