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

## 移动语义与 RAII：把资源“搬”过去

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](mailto:yangyibiao@nju.edu.cn)


<!-- slide data-notes="" -->

##### 本讲提纲

---

<div class="cols">

<div class="col">

**移动语义** <span class="std cxx11">C++11</span>

- 左值与右值
- 右值引用与移动构造
- `std::move`
- 五法则与 `noexcept`

</div>

<div class="col">

**RAII**

- 资源生命周期绑定对象
- 异常安全与栈展开
- 锁、文件、内存的统一管理
- 智能指针预告

</div>

</div>

<div class="keypoint">
<span class="label">本讲目标</span>
能够解释“移动为什么比拷贝快”，并为持有资源的类写出正确的移动构造/移动赋值。
</div>

---


<!-- slide data-notes="" -->

##### 拷贝的代价：深拷贝一块大内存

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
class Buffer {
public:
    explicit Buffer(std::size_t n)
        : size_(n), data_(new int[n]{}) {}

    Buffer(const Buffer& other)
        : size_(other.size_),
          data_(new int[other.size_]) {
        std::copy(other.data_,
                  other.data_ + size_, data_);
    }
    // ...
private:
    std::size_t size_;
    int* data_;
};
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">一次拷贝做了什么</div>

1. 分配同样大的新内存
2. 逐个元素复制
3. 原对象保持不变

</div>

<div class="pitfall">
<span class="label">浪费</span>
如果原对象马上就要销毁（临时对象、<code>return</code> 的局部变量），复制数据毫无意义——直接把资源“搬走”即可。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 左值与右值：能不能取地址

---

<div class="cols">

<div class="col-55">

```cpp
int x = 10;

int& r = x;        // 左值引用：绑定到有名字的对象
int&& rr = 10;     // 右值引用：绑定到临时值

// int& bad = 10;  // 错误：普通引用不能绑定临时值
```

- **左值**：有名字、可取地址、生命周期较长
- **右值**：临时值、字面量、表达式结果，通常马上销毁

</div>

<div class="col-45">

<div class="card">

<div class="card-title">直观判断</div>

- 能写在 `&` 后面取地址 → 左值
- 只能出现在等号右边 → 右值
- `x` 是左值；`x + 1` 是右值
- `std::move(x)` 把左值“标记”为右值

</div>

<div class="tip">
<span class="label">C++11 的类型</span>
<code>T&amp;</code> 是左值引用，<code>T&amp;&amp;</code> 是右值引用。右值引用让函数能够识别“临时对象”，从而窃取它的资源。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 移动构造：偷走指针，而不是复制数据

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
Buffer(Buffer&& other) noexcept
    : size_(other.size_),
      data_(other.data_) {
    other.size_ = 0;
    other.data_ = nullptr;
}
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">三步</div>

1. 接管对方的指针
2. 把对方置为空状态
3. 不分配、不复制

</div>

<div class="keypoint">
<span class="label">复杂度</span>
移动构造是 <strong>O(1)</strong>；深拷贝是 <strong>O(n)</strong>。对大对象，差距是数量级的。
</div>

<div class="small muted mt1">
被移动后的对象仍然“有效”，但值未指定；通常只应重新赋值或销毁。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 移动赋值：先释放自己的旧资源

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
Buffer& operator=(Buffer&& other) noexcept {
    if (this != &other) {
        delete[] data_;          // 释放旧资源
        size_ = other.size_;
        data_ = other.data_;     // 接管
        other.size_ = 0;
        other.data_ = nullptr;   // 置空源对象
    }
    return *this;
}
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">与移动构造的区别</div>

- 移动构造：目标对象还没有资源
- 移动赋值：目标对象已有资源，必须先释放
- 自移动检查：`this != &other`
- 仍然返回 `*this` 并标记 `noexcept`

</div>

<div class="pitfall">
<span class="label">自移动</span>
<code>b = std::move(b);</code> 如果不检查，会先 <code>delete[]</code> 自己的数据，再从自己（已悬空）接管。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### `std::move` 只是类型转换

---

<div class="cols">

<div class="col-55">

```cpp
#include <utility>

std::string a = "hello";
std::string b = std::move(a);
```

`std::move(a)` 不移动任何东西，它等价于：

```cpp
static_cast<std::string&&>(a)
```

真正“搬资源”的是随后的**移动构造**。

</div>

<div class="col-45">

<div class="card">

<div class="card-title">常见误解</div>

- ❌ `std::move(a)` 之后 `a` 一定为空
- ✅ `a` 处于“有效但未指定”的状态
- ❌ `std::move` 会调用移动构造
- ✅ 它只是把表达式变成右值，让重载选择移动版本

</div>

<div class="tip">
<span class="label">规则</span>
对<strong>确实不再使用</strong>的对象才 <code>std::move</code>；移动后不要读取它的值。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 被移动后的对象：有效但未指定

---

<div class="cols">

<div class="col">

```cpp
std::string a = "hello";
std::string b = std::move(a);

std::cout << a.size();   // 可能是 0，也可能不是
a = "world";             // OK：重新赋值
std::cout << a;          // OK
```

<div class="card mt1">

<div class="card-title">可以做什么</div>

- 重新赋值
- 销毁
- 调用不依赖具体值的操作（如 `clear()`）

</div>

</div>

<div class="col">

<div class="card">

<div class="card-title">不要做什么</div>

- 假设它一定为空
- 继续读取它的业务数据
- 把它传给需要有效内容的函数
- 对它再次 `std::move` 后期待原值

</div>

<div class="keypoint">
<span class="label">标准保证</span>
移动后的对象满足所属类型的不变量，可以安全析构和赋值；但具体值由实现决定。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 五法则

---

<div class="motto">
需要自定义<strong>析构</strong>、<strong>拷贝构造</strong>、<strong>拷贝赋值</strong>、<strong>移动构造</strong>、<strong>移动赋值</strong>中的任何一个时，通常五个都要考虑。
</div>

<div class="table-sm mt1">

| 函数 | 作用 | 典型实现 |
| :-- | :-- | :-- |
| `~T()` | 释放资源 | `delete[] data_` |
| `T(const T&)` | 深拷贝 | 分配 + 复制 |
| `T& operator=(const T&)` | 拷贝赋值 | 自赋值检查 + 分配 + 释放 |
| `T(T&&) noexcept` | 接管资源 | 复制指针 + 源置空 |
| `T& operator=(T&&) noexcept` | 移动赋值 | 释放旧资源 + 接管 + 源置空 |

</div>

<div class="small muted center mt1">
如果类只包含会自我管理的成员（`std::string`、`std::vector`、`std::unique_ptr`），通常<strong>一个都不需要写</strong>。
</div>

---


<!-- slide data-notes="" -->

##### 移动与 `std::vector` 扩容

---

<div class="cols">

<div class="col-55">

```cpp
std::vector<Buffer> v;
v.push_back(Buffer(100));   // 临时对象 -> 移动
v.emplace_back(200);        // 原地构造，无移动

Buffer b(300);
v.push_back(std::move(b));  // 明确转移所有权
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">扩容时发生什么</div>

- `vector` 申请更大的新数组
- 把旧元素**移动**到新数组（若移动构造是 `noexcept`）
- 销毁旧元素，释放旧数组

</div>

<div class="pitfall">
<span class="label">关键</span>
如果移动构造没有标记 <code>noexcept</code>，<code>vector</code> 可能退回使用拷贝构造，以提供强异常安全保证。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 返回值优化：不要画蛇添足

---

<div class="cols">

<div class="col">

**推荐写法**

```cpp
Buffer make_buffer(std::size_t n) {
    return Buffer(n);       // RVO
}

Buffer b = make_buffer(10);
```

**或者**

```cpp
Buffer make_buffer(std::size_t n) {
    Buffer tmp(n);
    // ...
    return tmp;             // NRVO
}
```

</div>

<div class="col">

**不推荐**

```cpp
Buffer make_buffer(std::size_t n) {
    Buffer tmp(n);
    return std::move(tmp);  // 阻止 NRVO
}
```

<div class="card mt1">

<div class="card-title">原因</div>

编译器可以直接把 `tmp` 构造在调用方预留的空间里，连移动都省掉。显式 `std::move` 反而迫使它走移动构造。

</div>

<div class="small muted mt1">
C++17 起，返回纯右值（如 <code>return Buffer(n);</code>）的复制省略是强制的。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### RAII：资源获取即初始化

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

<div class="card-title">RAII 的三条承诺</div>

1. 构造成功 → 资源已获取
2. 对象存活 → 资源可用
3. 对象析构 → 资源必释放

</div>

<div class="keypoint">
<span class="label">为什么可靠</span>
析构由编译器在作用域结束时自动调用，不依赖程序员记得写 <code>fclose</code> / <code>delete</code> / <code>unlock</code>。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### RAII 与异常安全

---

<div class="cols">

<div class="col-55">

```cpp
void process() {
    Buffer a(100);
    Buffer b(200);
    FileHandle f("data.txt");

    may_throw();   // 抛出异常

    // 正常路径和异常路径都会：
    // f 析构 -> 关闭文件
    // b 析构 -> 释放内存
    // a 析构 -> 释放内存
}
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">栈展开（stack unwinding）</div>

异常抛出后，程序沿调用栈向外查找 `catch`，途中所有已构造的局部对象都会析构。

</div>

<div class="keypoint">
<span class="label">结果</span>
只要资源由对象管理，就不需要为每条 <code>return</code> / <code>throw</code> 路径手写清理代码。
</div>

<div class="small muted mt1">
这也是标准库容器、<code>std::lock_guard</code>、智能指针的共同基础。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### RAII 的另一个例子：锁

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
class Mutex {
public:
    void lock();
    void unlock();
};

class LockGuard {
public:
    explicit LockGuard(Mutex& m) : m_(m) {
        m_.lock();
    }
    ~LockGuard() { m_.unlock(); }

    LockGuard(const LockGuard&) = delete;
    LockGuard& operator=(const LockGuard&) = delete;

private:
    Mutex& m_;
};
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">使用</div>

```cpp
Mutex m;

void critical() {
    LockGuard guard(m);
    // 临界区
    // 无论正常返回还是异常，
    // guard 析构时自动 unlock
}
```

</div>

<div class="keypoint">
<span class="label">标准库</span>
<code>std::lock_guard</code>、<code>std::unique_lock</code> 就是这一思想的标准实现，并发章节会使用。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 标准库中的 RAII：智能指针预告

---

<div class="cols">

<div class="col">

**裸指针**

```cpp
Task* p = new Task(1, "A", 1);
// ...
delete p;   // 可能忘记
```

**智能指针** <span class="std cxx11">C++11</span>

```cpp
auto p = std::make_unique<Task>(1, "A", 1);
// 离开作用域自动 delete
```

</div>

<div class="col">

<div class="card">

<div class="card-title">本质</div>

智能指针是“把裸指针包进 RAII 类”：

- 析构时 `delete` 所拥有的对象
- 通过 `operator*` / `operator->` 模拟指针
- 用类型系统表达“谁拥有资源”

</div>

<div class="tip">
<span class="label">后续</span>
<code>unique_ptr</code> / <code>shared_ptr</code> / <code>weak_ptr</code> 的所有权模型，在内存安全单元详细展开。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 主线案例：让 `Buffer` 支持移动

---

<div class="cols">

<div class="col-55 code-xs">

```cpp
class Buffer {
public:
    explicit Buffer(std::size_t n)
        : size_(n), data_(new int[n]{}) {}

    ~Buffer() { delete[] data_; }

    Buffer(const Buffer& other)
        : size_(other.size_),
          data_(other.size_ ? new int[other.size_] : nullptr) {
        if (size_) std::copy(other.data_,
                             other.data_ + size_, data_);
    }

    Buffer(Buffer&& other) noexcept
        : size_(other.size_), data_(other.data_) {
        other.size_ = 0;
        other.data_ = nullptr;
    }

    Buffer& operator=(Buffer&& other) noexcept {
        if (this != &other) {
            delete[] data_;
            size_ = other.size_;
            data_ = other.data_;
            other.size_ = 0;
            other.data_ = nullptr;
        }
        return *this;
    }

private:
    std::size_t size_;
    int* data_;
};
```

</div>

<div class="col-45">

**使用**

```cpp
std::vector<Buffer> v;
v.push_back(Buffer(100));
v.emplace_back(200);

Buffer a(300);
Buffer b = std::move(a);
```

<div class="small mt1">

**观察**

- `push_back(Buffer(100))` 走移动
- `emplace_back(200)` 原地构造
- `std::move(a)` 后 `a` 为空状态
- `vector` 扩容时移动而非深拷贝

</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 课堂任务 5：为 `Buffer` 补齐移动语义

---

<div class="cols">

<div class="col-55">

<div class="card">

<div class="card-title">任务</div>

在上一单元的 `Buffer` 基础上：

1. 添加移动构造函数（`noexcept`）
2. 添加移动赋值运算符（`noexcept`，处理自移动）
3. 保留拷贝构造与拷贝赋值（深拷贝）
4. 在 `main` 中用 `std::vector<Buffer>` 验证：
   - `push_back(Buffer(100))`
   - `emplace_back(200)`
   - `std::move` 后源对象为空

</div>

</div>

<div class="col-45">

<div class="card">

<div class="card-title">验收标准</div>

- 移动后源对象 `size() == 0`、`data() == nullptr`
- 自移动 `b = std::move(b)` 不崩溃
- `vector` 扩容不泄漏、不双重释放
- ASan/Valgrind 无报告
- 移动构造/赋值标记 `noexcept`

</div>

<div class="tip">
<span class="label">提示</span>
移动构造只复制指针并把源置空；移动赋值要先释放自己的旧资源。不要忘记 <code>if (this != &amp;other)</code>。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 任务 5 参考实现（移动部分）

---

<div class="cols">

<div class="col-55 code-sm">

```cpp{.line-numbers}
Buffer(Buffer&& other) noexcept
    : size_(other.size_), data_(other.data_) {
    other.size_ = 0;
    other.data_ = nullptr;
}

Buffer& operator=(Buffer&& other) noexcept {
    if (this != &other) {
        delete[] data_;
        size_ = other.size_;
        data_ = other.data_;
        other.size_ = 0;
        other.data_ = nullptr;
    }
    return *this;
}
```

</div>

<div class="col-45">

**测试**

```cpp
std::vector<Buffer> v;
v.push_back(Buffer(100));
v.emplace_back(200);

Buffer a(300);
Buffer b = std::move(a);

std::cout << a.size() << " "
          << b.size() << "\n";
```

<div class="out">0 300</div>

<div class="small mt1">

**要点**

- `noexcept` 让 `vector` 放心使用移动
- 源对象置空，避免双重释放
- 自移动检查保护 `delete[]`
- 移动后对象仍可安全析构

</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 常见陷阱

---

<div class="cols">

<div class="col">

**移动语义**

- 移动后继续读取源对象
- `const` 对象调用 `std::move` → 实际走拷贝
- 移动构造没有 `noexcept` → `vector` 退回拷贝
- 移动赋值忘记释放旧资源 → 泄漏
- 自移动未检查 → 释放后使用
- `return std::move(local)` → 阻止 NRVO

</div>

<div class="col">

**RAII**

- 构造失败时资源未释放（构造中抛异常）
- 析构函数抛异常 → `std::terminate`
- 拷贝 RAII 对象 → 重复释放
- 手动 `lock` / `unlock` 而不用 `lock_guard`
- 让资源生命周期与对象脱节（如返回裸指针）

</div>

</div>

<div class="pitfall">
<span class="label">判断</span>
“这个对象是否<strong>独占</strong>一份资源？”是，则认真考虑五法则；否，则优先让成员（容器、智能指针）管理资源。
</div>

---


<!-- slide data-notes="" -->

##### 课堂小测

---

1. 左值与右值的核心区别是什么？`std::move(x)` 对 `x` 做了什么？

2. 移动构造为什么通常标记 `noexcept`？不标记会对 `std::vector` 产生什么影响？

3. 被移动后的对象处于什么状态？可以安全地做哪些操作？

4. RAII 如何保证异常路径上的资源释放？请用栈展开解释。

---


<!-- slide data-notes="" -->

##### 小结：能搬就不要复制

---

<div class="cols">

<div class="col">

<div class="card">

<div class="card-title">移动</div>

- 右值引用识别临时对象
- 接管指针，O(1)
- `std::move` 只是类型转换
- 五法则与 `noexcept`

</div>

</div>

<div class="col">

<div class="card">

<div class="card-title">RAII</div>

- 构造函数获取资源
- 析构函数释放资源
- 栈展开保证异常安全
- 智能指针、锁、文件都靠它

</div>

</div>

<div class="col">

<div class="card">

<div class="card-title">选择</div>

- 资源由成员管理 → 不写五法则
- 直接持有裸资源 → 写全五法则
- 不需要复制 → `= delete`
- 返回局部对象 → 让 RVO 工作

</div>

</div>

</div>

<div class="motto mt1">
移动语义把“复制一份”变成“把钥匙交出去”；RAII 把“记得释放”变成“对象销毁时自动释放”。
</div>

---


<!-- slide data-notes="" -->

#####

---

<div class="bottom20"></div>

<hr class="width50 center">

## 未完待续

---
