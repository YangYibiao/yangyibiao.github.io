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

## 运算符重载

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](mailto:yangyibiao@nju.edu.cn)


<!-- slide data-notes="" -->

##### 本讲提纲

---

<div class="cols">

<div class="col">

**基本做法**

- 为什么需要运算符重载
- 成员函数 vs 非成员函数
- 双目、单目、`++`/`--`
- `[]`、`()`、`->`

</div>

<div class="col">

**特殊运算符**

- 赋值 `=`
- `new` / `delete`
- 类型转换与 `explicit`
- 流运算符 `<<` / `>>`

</div>

</div>

<div class="keypoint">
<span class="label">本讲目标</span>
能够为自定义类型设计符合直觉的运算符，并知道哪些运算符不该重载、哪些必须作为非成员。
</div>

---


<!-- slide data-notes="" -->

##### 为什么需要运算符重载？

---

<div class="cols">

<div class="col-55">

```cpp
class Complex {
public:
    Complex(double r = 0, double i = 0)
        : re_(r), im_(i) {}

    Complex add(const Complex& other) const {
        return Complex(re_ + other.re_,
                       im_ + other.im_);
    }
private:
    double re_, im_;
};

Complex a(1, 2), b(3, 4);
Complex c = a.add(b);   // 能工作，但不像数学
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">目标</div>

让自定义类型像内置类型一样自然：

```cpp
Complex c = a + b;
if (a == b) { ... }
std::cout << c;
```

运算符重载让代码的**写法**贴近问题领域的**语义**。

</div>

<div class="tip">
<span class="label">本质</span>
<code>a + b</code> 只是 <code>operator+(a, b)</code> 的另一种写法；重载的是函数，不是语法。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 运算符重载的规则

---

<div class="cols">

<div class="col">

**可以做什么**

- 重载 C++ 已有运算符
- 改变运算符对自定义类型的含义
- 写成成员函数或非成员函数
- 至少一个操作数是类/枚举类型

</div>

<div class="col">

**不能做什么**

- 发明新运算符（如 `**`）
- 改变操作数个数
- 改变优先级和结合性
- 重载 `::`、`.`、`.*`、`?:`、`sizeof`
- 改变内置类型之间的运算含义

</div>

</div>

<div class="pitfall">
<span class="label">语义约束</span>
语言不强制你“保持原语义”，但滥用会让代码难以理解。例如把 <code>+</code> 定义成“删除元素”就是灾难。
</div>

---


<!-- slide data-notes="" -->

##### 成员函数 vs 非成员函数

---

<div class="table-sm">

| 形式 | 左操作数 | 典型场景 | 例子 |
| :-- | :-- | :-- | :-- |
| 成员函数 | 必须是当前类对象 | 修改自身、`+=`、`[]`、`()` | `a += b` |
| 非成员函数 | 可以是任意类型 | 左操作数不是当前类 | `2.5 + c`、`cout << t` |

</div>

<div class="cols mt1">

<div class="col code-sm">

```cpp
class Complex {
public:
    Complex operator+(const Complex& other) const;
};
```

`a + b` → `a.operator+(b)`

</div>

<div class="col code-sm">

```cpp
Complex operator+(double d, const Complex& c);
```

`2.5 + c` → `operator+(2.5, c)`

<div class="small muted mt1">
左操作数是 <code>double</code>，不可能写成 <code>Complex</code> 的成员函数。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 双目运算符：`+` 返回值

---

<div class="cols">

<div class="col-55">

```cpp
class Complex {
public:
    Complex(double r = 0, double i = 0)
        : re_(r), im_(i) {}

    Complex operator+(const Complex& other) const {
        return Complex(re_ + other.re_,
                       im_ + other.im_);
    }
private:
    double re_, im_;
};

Complex a(1, 2), b(3, 4);
Complex c = a + b;      // (4, 6)
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">为什么按值返回</div>

`a + b` 产生一个**新值**，不修改 `a` 或 `b`。返回新对象是正确语义。

</div>

<div class="pitfall">
<span class="label">不要返回引用</span>
返回局部对象的引用会悬空；返回 `a` 或 `b` 的引用会让 `c = a + b` 意外修改操作数。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 复合赋值：`+=` 返回引用

---

<div class="cols">

<div class="col-55">

```cpp
class Complex {
public:
    Complex& operator+=(const Complex& other) {
        re_ += other.re_;
        im_ += other.im_;
        return *this;
    }
};

Complex a(1, 2), b(3, 4);
a += b;          // 修改 a
(a += b) += b;   // 支持连续复合赋值
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">设计习惯</div>

- 复合赋值修改左操作数
- 返回 `*this` 的引用
- `a += b` 通常比 `a = a + b` 更高效（避免临时对象）
- 可以用 `+=` 实现 `+`，减少重复

</div>

<div class="tip">
<span class="label">对称性</span>
提供 <code>+</code> 时通常也提供 <code>+=</code>；提供 <code>&lt;</code> 时通常也提供 <code>&gt;</code>、<code>&lt;=</code>、<code>&gt;=</code>（C++20 可用 <code>&lt;=&gt;</code> 一次生成）。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 比较运算符与三路比较

---

<div class="cols">

<div class="col-55">

```cpp
class Target {
public:
    bool operator==(const Target& other) const {
        return id_ == other.id_;
    }
    bool operator!=(const Target& other) const {
        return !(*this == other);
    }
    bool operator<(const Target& other) const {
        return priority_ < other.priority_;
    }
private:
    int id_;
    int priority_;
};
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">C++20：`<=>`</div>

```cpp
#include <compare>

class Target {
public:
    auto operator<=>(const Target&) const = default;
};
```

编译器自动生成 `==`、`!=`、`<`、`<=`、`>`、`>=`，按成员依次比较。

</div>

<div class="pitfall">
<span class="label">严格弱序</span>
用于 <code>std::sort</code> / <code>std::map</code> 的比较必须满足严格弱序：不可出现 <code>a &lt; b</code> 和 <code>b &lt; a</code> 同时为真。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 单目运算符：`-` 与 `!`

---

<div class="cols">

<div class="col-55">

```cpp
class Complex {
public:
    Complex operator-() const {   // 取负
        return Complex(-re_, -im_);
    }

    bool operator!() const {      // 是否为零
        return re_ == 0 && im_ == 0;
    }
private:
    double re_, im_;
};

Complex a(1, 2);
Complex b = -a;     // (-1, -2)
if (!a) { ... }     // false
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">成员 vs 非成员</div>

- 单目运算符常写成成员函数
- 也可以写成非成员：`operator-(const Complex&)`
- 返回新值（取负/取反不修改原对象）

</div>

<div class="small muted mt1">
不要混淆 <code>operator-()</code>（单目取负）与 <code>operator-(a, b)</code>（双目减法）。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 前置与后置 `++` / `--`

---

<div class="cols">

<div class="col-55">

```cpp
class Counter {
public:
    Counter& operator++() {      // 前置 ++c
        ++value_;
        return *this;
    }

    Counter operator++(int) {    // 后置 c++
        Counter old = *this;
        ++(*this);
        return old;
    }
private:
    int value_ = 0;
};

Counter c;
++c;        // 前置：返回引用
c++;        // 后置：返回旧值的副本
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">区分方式</div>

- 前置：无参数，返回 `T&`
- 后置：多一个 `int` 参数（不使用其值），返回 `T`
- 后置的 `int` 只是标记，不参与运算

</div>

<div class="pitfall">
<span class="label">返回值不同</span>
前置返回引用以支持 <code>++(++c)</code>；后置返回旧值副本，不能返回引用（局部对象会悬空）。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 下标 `[]`：const 与非 const

---

<div class="cols">

<div class="col-55">

```cpp
class IntArray {
public:
    int& operator[](std::size_t i) {
        return data_[i];
    }
    const int& operator[](std::size_t i) const {
        return data_[i];
    }
private:
    int* data_;
    std::size_t size_;
};

IntArray a(10);
a[2] = 42;              // 非 const：可写

const IntArray& ca = a;
int x = ca[2];          // const：只读
// ca[2] = 1;           // 错误
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">要点</div>

- 返回引用，才能支持 `a[i] = x`
- 提供 const 重载，常量对象才能读
- 通常不做越界检查；需要时用 `at()` 抛异常
- 下标类型常用 `std::size_t`

</div>

<div class="small muted mt1">
标准库 <code>vector</code>、<code>string</code> 同时提供 <code>operator[]</code>（不检查）与 <code>at()</code>（检查并抛 <code>out_of_range</code>）。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 函数调用 `()`：函数对象

---

<div class="cols">

<div class="col-55">

```cpp
struct GreaterThan {
    int threshold;

    bool operator()(int x) const {
        return x > threshold;
    }
};

GreaterThan gt{10};
bool b = gt(42);        // true

std::vector<int> v{5, 12, 3, 20};
auto n = std::count_if(v.begin(), v.end(), gt);
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">函数对象（functor）</div>

- 可以像函数一样调用
- 可以携带状态（`threshold`）
- 可以被 STL 算法接受
- Lambda 本质上是编译器生成的函数对象

</div>

<div class="tip">
<span class="label">与函数指针</span>
函数对象通常更容易被编译器内联，且能保存状态；现代 C++ 中 Lambda 更常用。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### `->`：指针类与智能指针

---

<div class="cols">

<div class="col-55">

```cpp
class TargetPtr {
public:
    explicit TargetPtr(Target* p) : p_(p) {}
    Target* operator->() { return p_; }
    Target& operator*() { return *p_; }
private:
    Target* p_;
};

Target t(1, "main.o", 2);
TargetPtr p(&t);
p->priority();  // 等价于 p.operator->()->priority()
(*p).name();       // 等价于 p.operator*().name()
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">用途</div>

- 智能指针（`unique_ptr`、`shared_ptr`）
- 迭代器
- 代理对象：在访问成员前做额外操作（计数、日志、检查）

</div>

<div class="pitfall">
<span class="label">链式规则</span>
<code>operator-&gt;</code> 必须返回指针（或另一个重载了 <code>-&gt;</code> 的对象）；编译器会继续应用 <code>-&gt;</code> 直到得到裸指针。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 赋值运算符：复制与移动

---

<div class="cols">

<div class="col-55">

```cpp
class String {
public:
    String& operator=(const String& other) {
        if (this == &other) return *this;
        char* p = new char[other.len_ + 1];
        std::strcpy(p, other.data_);
        delete[] data_;
        data_ = p;
        len_ = other.len_;
        return *this;
    }

    String& operator=(String&& other) noexcept {
        if (this != &other) {
            delete[] data_;
            data_ = other.data_;
            len_ = other.len_;
            other.data_ = nullptr;
            other.len_ = 0;
        }
        return *this;
    }
};
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">要点</div>

- 赋值运算符只能作为成员函数
- 返回 `*this` 引用
- 处理自赋值
- 先分配后释放，保证异常安全
- 移动赋值标记 `noexcept`

</div>

<div class="small muted mt1">
拷贝/移动语义的完整讨论在第 4、5 单元；这里只强调“运算符形式”。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### `new` / `delete` 重载：为什么很少用

---

<div class="cols">

<div class="col-55">

```cpp
class Target {
public:
    static void* operator new(std::size_t size) {
        std::cout << "allocate " << size << "\n";
        return ::operator new(size);
    }

    static void operator delete(void* p) {
        std::cout << "free\n";
        ::operator delete(p);
    }
};
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">用途</div>

- 自定义内存池 / 对象池
- 调试分配行为
- 特定对齐要求

</div>

<div class="pitfall">
<span class="label">风险</span>
重载 <code>new</code> / <code>delete</code> 不影响构造/析构调用，但会改变内存来源；必须正确处理 <code>new[]</code>、对齐、失败与全局 <code>::operator new</code>。初学阶段不要轻易重载。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 类型转换运算符与 `explicit`

---

<div class="cols">

<div class="col-55">

```cpp
class Fraction {
public:
    Fraction(int n, int d) : n_(n), d_(d) {}

    explicit operator double() const {
        return static_cast<double>(n_) / d_;
    }
private:
    int n_, d_;
};

Fraction f(1, 2);
double x = static_cast<double>(f);  // OK
// double y = f;                    // 错误：explicit
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">隐式转换的风险</div>

单参数构造函数和转换运算符都可能引发隐式转换，导致重载歧义或意外行为。

- 构造函数加 `explicit`
- 转换运算符加 `explicit`（C++11）
- 需要转换时显式 `static_cast`

</div>

<div class="pitfall">
<span class="label">经典歧义</span>
<code>a + 1</code> 既可以把 <code>a</code> 转成 <code>int</code>，也可以把 <code>1</code> 转成 <code>A</code>；编译器无法选择。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 流运算符：必须是非成员函数

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
class Target {
public:
    Target(int id, std::string name)
        : id_(id), name_(std::move(name)) {}

    friend std::ostream& operator<<(std::ostream& os,
                                    const Target& t);
private:
    int id_;
    std::string name_;
};

std::ostream& operator<<(std::ostream& os, const Target& t) {
    return os << "[" << t.id_ << "] " << t.name_;
}

std::cout << t << "\n";   // [1] main.o
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">为什么不能是成员</div>

`a << b` 如果写成成员，左操作数必须是 `Target`；但 `std::cout << t` 的左操作数是 `ostream`，所以只能写成非成员。

</div>

<div class="tip">
<span class="label">返回 ostream&amp;</span>
返回输出流本身，才能支持 <code>cout &lt;&lt; a &lt;&lt; b &lt;&lt; endl</code> 的链式调用。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 运算符重载的设计原则

---

<div class="cols">

<div class="col">

**应该重载**

- 语义与内置类型一致
- 能显著提升可读性
- 类型是数值、容器、迭代器、智能指针
- 与标准库算法/容器协作需要

</div>

<div class="col">

**不应该重载**

- 语义不直观（`+` 表示删除）
- 改变 `&&` / `||` 的短路语义
- 为了“炫技”而重载
- 让类型隐式转换到多种类型

</div>

</div>

<div class="motto">
运算符重载的目标是<strong>让代码更像领域语言</strong>，而不是让编译器接受奇怪的写法。
</div>

---


<!-- slide data-notes="" -->

##### 主线案例：`Target` 的运算符

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
class Target {
public:
    int id() const { return id_; }
    int priority() const { return priority_; }
    const std::string& name() const { return name_; }

    bool operator==(const Target& other) const {
        return id_ == other.id_;
    }
    bool operator<(const Target& other) const {
        return priority_ < other.priority();
    }
private:
    int id_;
    std::string name_;
    int priority_;
};

std::ostream& operator<<(std::ostream& os, const Target& t) {
    return os << "[" << t.id() << "] " << t.name()
              << " p=" << t.priority();
}
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">用途</div>

- `operator<`：放入 `std::priority_queue` 或 `std::set`
- `operator==`：查找、去重
- `operator<<`：日志与调试输出

</div>

<div class="tip">
<span class="label">访问方式</span>
这里通过 public 的 <code>id()</code> / <code>name()</code> 访问，不需要友元；只有需要直接访问私有数据时才用友元。
</div>

<div class="small muted mt1">
如果优先级相同的任务需要稳定顺序，可以把 <code>id</code> 作为第二比较键。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 课堂任务 9：完善 `Complex`

---

<div class="cols">

<div class="col-55">

<div class="card">

<div class="card-title">任务</div>

实现 `Complex` 类，至少支持：

- `Complex(double r = 0, double i = 0)`
- `operator+`、`operator+=`
- `operator-`（双目与单目取负）
- `operator==`、`operator!=`
- 前置/后置 `operator++`
- `operator<<` 输出 `a+bi`
- `operator double()` 返回模长（`explicit`）

在 `main` 中验证混合运算与输出。

</div>

</div>

<div class="col-45">

<div class="card">

<div class="card-title">验收标准</div>

- `a + b`、`a += b` 语义正确
- `++a` 与 `a++` 返回值不同
- `a == b` 与 `a != b` 一致
- `std::cout << a` 输出可读
- 不返回局部对象的引用
- 编译无警告

</div>

<div class="tip">
<span class="label">提示</span>
先用 <code>+=</code> 实现 <code>+</code>；用 <code>==</code> 实现 <code>!=</code>；前置 <code>++</code> 返回引用，后置返回旧值。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 任务 9 参考实现（一）：算术与比较

---

<div class="cols">

<div class="col-55 code-sm">

```cpp{.line-numbers}
class Complex {
public:
    Complex(double r = 0, double i = 0)
        : re_(r), im_(i) {}

    Complex& operator+=(const Complex& o) {
        re_ += o.re_; im_ += o.im_;
        return *this;
    }

    Complex operator+(const Complex& o) const {
        Complex tmp = *this;
        tmp += o;
        return tmp;
    }

    Complex operator-() const {
        return Complex(-re_, -im_);
    }

    bool operator==(const Complex& o) const {
        return re_ == o.re_ && im_ == o.im_;
    }
    bool operator!=(const Complex& o) const {
        return !(*this == o);
    }

private:
    double re_, im_;
};
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">要点</div>

- `+=` 修改自身，返回 `*this`
- `+` 复用 `+=`，返回新值
- 单目 `-` 不修改原对象
- `!=` 复用 `==`，保持语义一致

</div>

<div class="tip">
<span class="label">顺序</span>
先实现复合赋值，再基于它实现双目运算，可以减少重复代码，也更容易保证语义一致。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 任务 9 参考实现（二）：自增、转换与输出

---

<div class="cols">

<div class="col-55 code-sm">

```cpp{.line-numbers}
class Complex {
public:
    // ... 构造函数与算术运算符 ...

    Complex& operator++() {
        ++re_;
        return *this;
    }

    Complex operator++(int) {
        Complex old = *this;
        ++(*this);
        return old;
    }

    explicit operator double() const {
        return std::sqrt(re_ * re_ + im_ * im_);
    }

    friend std::ostream& operator<<(std::ostream& os,
                                    const Complex& c) {
        return os << c.re_
                  << (c.im_ >= 0 ? "+" : "")
                  << c.im_ << "i";
    }

private:
    double re_, im_;
};
```

</div>

<div class="col-45">

**使用**

```cpp
Complex a(1, 2), b(3, 4);
Complex c = a + b;
a += b;
std::cout << c << "\n";
std::cout << ++a << "\n";
std::cout << a++ << "\n";
```

<div class="out">4+6i
5+6i
5+6i</div>

<div class="small mt1">

**要点**

- 前置 `++` 返回引用
- 后置 `++` 返回旧值副本
- `explicit` 转换需要 `static_cast`
- `operator<<` 返回流引用

</div>

</div>

</div>

---
<!-- slide data-notes="" -->

##### 常见陷阱

---

<div class="cols">

<div class="col">

**返回值/引用**

- `+` 返回局部对象引用 → 悬空
- `+=` 返回值而不是引用 → 多一次拷贝
- 后置 `++` 返回引用 → 悬空
- `operator[]` 不返回引用 → 无法赋值

</div>

<div class="col">

**语义/设计**

- 重载 `&&` / `||` 破坏短路
- 隐式转换导致重载歧义
- 只重载 `==` 不重载 `!=`
- `operator<` 不满足严格弱序
- 把 `new` / `delete` 当普通函数随意重载

</div>

</div>

<div class="pitfall">
<span class="label">判断</span>
如果一段代码需要写注释解释“这里的 <code>+</code> 其实是删除”，那这个运算符就不该重载。
</div>

---


<!-- slide data-notes="" -->

##### 课堂小测

---

1. `operator+` 为什么通常按值返回，而 `operator+=` 按引用返回？

2. 前置 `++` 与后置 `++` 在参数和返回值上有什么区别？为什么后置版本多一个 `int` 参数？

3. `operator<<` 为什么通常写成非成员函数？返回 `ostream&` 的作用是什么？

4. 哪些运算符不能重载？为什么 `&&` / `||` 的重载要特别谨慎？

---


<!-- slide data-notes="" -->

##### 小结：让类型说人话

---

<div class="cols">

<div class="col">

<div class="card">

<div class="card-title">形式</div>

- 成员：左操作数是本类
- 非成员：左操作数可能是其他类型
- 至少一个操作数是类/枚举

</div>

</div>

<div class="col">

<div class="card">

<div class="card-title">语义</div>

- `+` 产生新值
- `+=` 修改自身并返回引用
- `[]` 返回引用
- `<<` 返回流引用

</div>

</div>

<div class="col">

<div class="card">

<div class="card-title">克制</div>

- 只重载语义直观的运算符
- 不改变优先级与操作数个数
- 不滥用隐式转换
- 与标准库协作时优先满足其约定

</div>

</div>

</div>

<div class="motto mt1">
运算符重载的最高标准：<strong>使用者不需要看实现，就能猜到它的行为</strong>。
</div>

---


<!-- slide data-notes="" -->

#####

---

<div class="bottom20"></div>

<hr class="width50 center">

## 未完待续

---
