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

## 模板与泛型程序设计

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](mailto:yangyibiao@nju.edu.cn)


<!-- slide data-notes="" -->

##### 本讲提纲

---

<div class="cols">

<div class="col">

**函数模板**

- 泛型问题与模板语法
- 实例化与类型推导
- 多参数与非类型参数
- 特化

</div>

<div class="col">

**类模板与现代特性**

- 类模板 `Stack<T>`
- 模板定义为什么放头文件
- 可变参数模板 <span class="std cxx11">C++11</span>
- Concepts <span class="std cxx20">C++20</span>

</div>

</div>

<div class="keypoint">
<span class="label">本讲目标</span>
能够把一段“只差类型”的代码抽成函数模板或类模板，并解释模板实例化、代码膨胀与链接错误。
</div>

---


<!-- slide data-notes="" -->

##### 泛型问题：同一算法，多种类型

---

<div class="cols">

<div class="col">

**三个几乎相同的函数**

```cpp
void sort(int a[], int n);
void sort(double a[], int n);
void sort(Target a[], int n);
```

实现完全一样，只是元素类型不同。

重复代码的代价：

- 修改算法要改多处
- 容易不一致
- 增加维护成本

</div>

<div class="col">

**目标**

写一次算法，让编译器为不同类型生成对应版本：

```cpp
template <typename T>
void sort(T a[], int n);
```

<div class="keypoint mt1">
<span class="label">泛型</span>
同一段代码能对多种类型进行操作。C++ 用<strong>模板</strong>实现泛型。
</div>

</div>

</div>

<div class="small muted center mt1">
模板是“代码的模具”：使用时给出具体类型，编译器才生成真正的函数/类。
</div>

---


<!-- slide data-notes="" -->

##### 函数模板：语法

---

<div class="cols">

<div class="col-55">

```cpp
template <typename T>
T max_value(const T& a, const T& b) {
    return a < b ? b : a;
}

int x = max_value(3, 5);          // T = int
double y = max_value(3.14, 2.71); // T = double
```

`typename` 也可以写成 `class`：

```cpp
template <class T>
T max_value(const T& a, const T& b);
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">要点</div>

- `template <...>` 声明模板参数
- `T` 是类型参数，使用时才确定
- 函数参数、返回值、局部变量都可以用 `T`
- 模板本身不是函数，实例化后才生成函数

</div>

<div class="tip">
<span class="label">约束</span>
<code>T</code> 必须支持模板体中用到的操作：这里要求 <code>operator&lt;</code> 和拷贝。否则实例化时编译失败。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 实例化与类型推导

---

<div class="cols">

<div class="col-55">

```cpp
template <typename T>
T max_value(const T& a, const T& b) {
    return a < b ? b : a;
}

max_value(3, 5);          // 推导 T = int
max_value(3.14, 2.71);    // 推导 T = double
max_value<int>(3, 4.5);   // 显式指定 T = int
```

编译器为每个用到的 `T` 生成一份函数：

```cpp
int max_value(const int&, const int&);
double max_value(const double&, const double&);
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">推导失败</div>

```cpp
max_value(3, 4.5);   // T 同时被推导为 int 和 double
```

<div class="small muted mt1">
解决：显式指定 <code>max_value&lt;double&gt;(3, 4.5)</code>，或使用两个类型参数。
</div>

</div>

<div class="keypoint">
<span class="label">实例化时机</span>
模板在<strong>使用时</strong>实例化；编译器必须看到模板的完整定义，才能生成代码。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 多个类型参数与非类型参数

---

<div class="cols">

<div class="col-55">

**多个类型参数**

```cpp
template <typename T, typename U>
auto add(T a, U b) {   // C++14 返回类型推导
    return a + b;
}

auto x = add(1, 2.5);   // double
```

**非类型参数**

```cpp
template <typename T, std::size_t N>
class Array {
public:
    constexpr std::size_t size() const { return N; }
private:
    T data_[N]{};
};

Array<int, 10> a;   // N = 10
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">非类型参数</div>

- 可以是整数、枚举、指针、引用（C++20 起更多）
- 必须在编译期确定
- 常用于固定大小的容器、维度
- `std::array<T, N>` 就是典型例子

</div>

<div class="pitfall">
<span class="label">C++11 写法</span>
如果返回类型依赖参数，C++11 需要尾置返回类型：<code>auto add(T a, U b) -&gt; decltype(a + b)</code>；C++14 起可以直接 <code>auto</code>。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 模板特化：为特定类型定制

---

<div class="cols">

<div class="col-55">

```cpp
template <typename T>
class Stack {
public:
    void push(const T& x);
    T pop();
private:
    std::vector<T> data_;
};

// 全特化：为 bool 单独实现
template <>
class Stack<bool> {
public:
    void push(bool x) { bits_.push_back(x); }
    bool pop() { /* ... */ }
private:
    std::vector<bool> bits_;
};
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">特化 vs 重载</div>

- 全特化：为某个具体类型提供完全不同的实现
- 偏特化：为“某种模式”提供实现，如 `Stack<T*>`
- 函数模板通常用**重载**而不是特化

</div>

<div class="pitfall">
<span class="label">不要滥用</span>
特化会让“同一模板”在不同类型下行为不同，增加理解成本。优先用重载、Concepts 或类型萃取。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 类模板：`Stack<T>`

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
template <typename T>
class Stack {
public:
    void push(const T& x) {
        data_.push_back(x);
    }

    T pop() {
        T x = data_.back();
        data_.pop_back();
        return x;
    }

    bool empty() const { return data_.empty(); }

private:
    std::vector<T> data_;
};

Stack<int> s1;
Stack<std::string> s2;
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">类模板的实例化</div>

- `Stack<int>` 和 `Stack<std::string>` 是两个不同的类型
- 各自有独立的静态成员
- 成员函数在**使用时**才实例化

</div>

<div class="tip">
<span class="label">命名</span>
类模板的成员函数在类外定义时，要写两套模板参数：
<code>template &lt;typename T&gt; void Stack&lt;T&gt;::push(...)</code>。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 类模板成员函数：类外定义

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
template <typename T>
class Stack {
public:
    void push(const T& x);
    T pop();
    bool empty() const;
private:
    std::vector<T> data_;
};

template <typename T>
void Stack<T>::push(const T& x) {
    data_.push_back(x);
}

template <typename T>
T Stack<T>::pop() {
    T x = data_.back();
    data_.pop_back();
    return x;
}
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">规则</div>

- 每个成员函数定义前都要写 `template <...>`
- 类名要写成 `Stack<T>`
- 定义通常放在头文件（或 `.tpp` 后包含）
- 不要放到普通 `.cpp` 中

</div>

<div class="pitfall">
<span class="label">链接错误</span>
如果成员函数定义在 `.cpp`，其他翻译单元实例化时看不到定义，链接器会报 <code>undefined reference to Stack&lt;int&gt;::push</code>。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 模板为什么放在头文件？

---

<div class="cols">

<div class="col-55">

```cpp
// stack.h
template <typename T>
class Stack {
public:
    void push(const T& x);
};

template <typename T>
void Stack<T>::push(const T& x) { ... }
```

```cpp
// main.cpp
#include "stack.h"

Stack<int> s;
s.push(1);   // 编译器必须看到 push 的定义
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">原因</div>

模板不是“已编译的代码”，而是“生成代码的蓝图”。实例化发生在使用点，编译器必须同时看到：

- 模板声明
- 模板定义
- 具体类型

因此定义要放在头文件，随 `#include` 进入每个使用它的翻译单元。

</div>

<div class="tip">
<span class="label">重复实例</span>
多个 `.cpp` 可能各自生成 `Stack&lt;int&gt;::push`；链接器会合并相同实例（弱符号），通常不需要你处理。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 可变参数模板 <span class="std cxx11">C++11</span>

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
template <typename... Args>
void print_all(const Args&... args) {
    ((std::cout << args << ' '), ...);   // C++17 折叠
}

print_all(1, 2.5, "hello");
// 输出：1 2.5 hello
```

递归展开（C++11 写法）：

```cpp
void print_all() {}

template <typename T, typename... Rest>
void print_all(const T& first, const Rest&... rest) {
    std::cout << first << ' ';
    print_all(rest...);
}
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">用途</div>

- 日志、调试输出
- 工厂函数：把参数转发给构造函数
- `std::make_unique` / `emplace_back` 的底层机制
- 元编程、类型列表

</div>

<div class="small muted mt1">
C++17 的折叠表达式让参数包展开更简洁；C++11 需要递归 + 终止重载。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### Concepts：给模板参数加约束 <span class="std cxx20">C++20</span>

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
#include <concepts>

template <typename T>
concept Printable = requires(const T& x,
                             std::ostream& os) {
    { os << x } -> std::same_as<std::ostream&>;
};

template <Printable T>
void print_all(const std::vector<T>& v) {
    for (const T& x : v) std::cout << x << '\n';
}
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">解决什么问题</div>

传统模板在实例化时才报错，错误信息又长又难读。Concepts 在模板参数处声明约束：

- 类型必须支持什么操作
- 不满足时给出清晰错误
- 支持重载选择（约束越具体越优先）

</div>

<div class="tip">
<span class="label">建议</span>
初学阶段先掌握传统模板；遇到“模板报错看不懂”时，再学习 Concepts 与 <code>requires</code>。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 模板的代价：代码膨胀与编译时间

---

<div class="cols">

<div class="col">

**代码膨胀**

```cpp
Stack<int> a;
Stack<double> b;
Stack<Target> c;
```

每个实例都会生成一份成员函数代码。二进制体积增大，编译时间变长。

</div>

<div class="col">

**应对方式**

- 只实例化真正需要的类型
- 把与类型无关的逻辑抽到非模板基类
- 使用显式实例化控制生成位置
- 接受“模板换来性能与复用”的权衡

</div>

</div>

<div class="keypoint">
<span class="label">权衡</span>
模板把“类型检查 + 代码生成”推迟到编译期，换来零运行时开销与强类型复用；代价是编译时间、二进制体积和错误信息复杂度。
</div>

---


<!-- slide data-notes="" -->

##### 主线案例：泛型 `Repository<T>`

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
template <typename T>
class Repository {
public:
    void add(T item) {
        items_.push_back(std::move(item));
    }

    const std::vector<T>& items() const {
        return items_;
    }

    std::size_t size() const {
        return items_.size();
    }

private:
    std::vector<T> items_;
};

Repository<Target> tasks;
Repository<std::string> names;
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">设计点</div>

- 一套容器逻辑适配任意元素类型
- `T` 需要可拷贝/可移动（`vector` 的要求）
- 元素类型自己负责资源管理
- 后续可以加 `find`、`remove`、`for_each`

</div>

<div class="tip">
<span class="label">与 STL 的关系</span>
<code>std::vector&lt;T&gt;</code> 本身就是类模板；<code>Repository&lt;T&gt;</code> 是在容器之上封装业务语义。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 课堂任务 12：泛型仓库与打印

---

<div class="cols">

<div class="col-55">

<div class="card">

<div class="card-title">任务</div>

实现两个模板：

1. `Repository<T>`：
   - `void add(T item)`
   - `const std::vector<T>& items() const`
   - `std::size_t size() const`

2. `print_all<T>(const std::vector<T>& v)`：
   - 逐行输出元素，要求 `T` 支持 `operator<<`

在 `main` 中用 `Repository<Target>` 与 `Repository<int>` 测试。

</div>

</div>

<div class="col-45">

<div class="card">

<div class="card-title">验收标准</div>

- `Repository<Target>` 与 `Repository<int>` 都能实例化
- `print_all` 对两种类型都能工作
- 模板定义放在头文件中
- 不给 `Target` 增加 `operator<<` 时，`print_all<Target>` 编译失败（这是正确的约束）
- 编译无警告

</div>

<div class="tip">
<span class="label">提示</span>
<code>print_all</code> 的模板体里写 <code>std::cout &lt;&lt; x</code>；如果 <code>T</code> 不支持，实例化时才会报错。这正是模板的“隐式约束”。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 任务 12 参考实现

---

<div class="cols">

<div class="col-55 code-sm">

```cpp{.line-numbers}
#include <iostream>
#include <utility>
#include <vector>

template <typename T>
class Repository {
public:
    void add(T item) {
        items_.push_back(std::move(item));
    }

    const std::vector<T>& items() const {
        return items_;
    }

    std::size_t size() const {
        return items_.size();
    }

private:
    std::vector<T> items_;
};

template <typename T>
void print_all(const std::vector<T>& v) {
    for (const T& x : v) {
        std::cout << x << '\n';
    }
}
```

</div>

<div class="col-45">

**使用**

```cpp
Repository<Target> tasks;
tasks.add(Target(1, "main.o", 2));
print_all(tasks.items());

Repository<int> nums;
nums.add(10);
nums.add(20);
print_all(nums.items());
```

<div class="out">[1] main.o p=2
10
20</div>

<div class="small mt1">

**要点**

- 两个实例互不影响
- `T` 的要求由模板体隐式决定
- `Target` 需要 `operator<<` 才能被 `print_all` 打印
- 定义在头文件，供使用点实例化

</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 常见陷阱

---

<div class="cols">

<div class="col">

**定义位置**

- 模板定义放 `.cpp` → 链接错误
- 头文件中忘记写 `template <...>`
- 类外定义成员函数漏 `Stack<T>::`

</div>

<div class="col">

**推导与约束**

- 不同类型实参导致推导冲突
- 模板体使用了 `T` 不支持的操作
- 特化/重载选择不符合预期
- 代码膨胀、编译时间过长

</div>

</div>

<div class="pitfall">
<span class="label">排错</span>
模板错误信息通常从“实例化点”开始，真正原因在最后几行。先看“哪个类型不满足哪个操作”，再看模板定义。
</div>

---


<!-- slide data-notes="" -->

##### 课堂小测

---

1. 函数模板在什么时候实例化？为什么模板定义通常放在头文件？

2. `max_value(3, 4.5)` 为什么推导失败？有哪两种解决方式？

3. 类模板的静态成员在不同实例之间共享吗？`Stack<int>` 与 `Stack<double>` 是什么关系？

4. 可变参数模板与 Concepts 分别解决什么问题？各自属于哪个 C++ 标准？

---


<!-- slide data-notes="" -->

##### 小结：写一次，适配多种类型

---

<div class="cols">

<div class="col">

<div class="card">

<div class="card-title">函数模板</div>

- `template <typename T>`
- 类型推导与显式实例化
- 多参数、非类型参数
- 特化与重载

</div>

</div>

<div class="col">

<div class="card">

<div class="card-title">类模板</div>

- `Stack<T>`、`Repository<T>`
- 成员函数类外定义
- 定义放头文件
- 每个实例独立

</div>

</div>

<div class="col">

<div class="card">

<div class="card-title">现代扩展</div>

- 可变参数模板
- 折叠表达式
- Concepts 约束
- 模板元编程（进阶）

</div>

</div>

</div>

<div class="motto mt1">
模板把“类型”变成参数，让<strong>算法只写一次，类型检查仍在编译期完成</strong>。这是 STL 的基石。
</div>

---


<!-- slide data-notes="" -->

#####

---

<div class="bottom20"></div>

<hr class="width50 center">

## 未完待续

---
