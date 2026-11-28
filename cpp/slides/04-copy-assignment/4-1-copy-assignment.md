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

## 拷贝构造与赋值：对象如何复制

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](mailto:yangyibiao@nju.edu.cn)


<!-- slide data-notes="" -->

##### 本讲提纲

---

<div class="cols">

<div class="col">

**拷贝构造**

- 什么是拷贝构造
- 三个调用时机
- 默认拷贝构造：浅拷贝
- 深拷贝与资源所有权

</div>

<div class="col">

**拷贝赋值**

- 拷贝构造 vs 赋值
- 默认赋值的问题
- 自赋值、异常安全
- 三法则与禁止拷贝

</div>

</div>

<div class="keypoint">
<span class="label">本讲目标</span>
能够判断一个类是否需要自定义拷贝/赋值，并写出正确的深拷贝与赋值运算符。
</div>

---


<!-- slide data-notes="" -->

##### 对象复制的三个场景

---

<div class="cols">

<div class="col">

**1. 用已有对象初始化新对象**

```cpp
Target a(1, "main.o", 2);
Target b = a;      // 拷贝构造
Target c(a);       // 拷贝构造
```

**2. 按值传参**

```cpp
void print_target(Target t);  // 创建形参副本
print_target(a);
```

**3. 按值返回**

```cpp
Target make_target() {
    Target t(1, "临时", 1);
    return t;     // 可能调用拷贝/移动构造
}
```

</div>

<div class="col">

<div class="card">

<div class="card-title">注意区分</div>

```cpp
Target b = a;   // 初始化：拷贝构造
b = a;        // 赋值：operator=
```

虽然都写作 `=`，但语义完全不同：

- 初始化：对象从无到有
- 赋值：对象已经存在，用新值覆盖旧值

</div>

<div class="tip">
<span class="label">记忆</span>
看等号左边是不是<strong>新定义</strong>的变量。是，则初始化；不是，则赋值。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 拷贝构造函数

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
class Target {
public:
    Target(int id, std::string name, int priority)
        : id_(id), name_(std::move(name)),
          priority_(priority) {}

    // 拷贝构造函数
    Target(const Target& other)
        : id_(other.id_), name_(other.name_),
          priority_(other.priority_), built_(other.built_) {}

private:
    int id_;
    std::string name_;
    int priority_;
    bool built_ = false;
};
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">识别</div>

- 参数是本类对象的引用：`const Target&`
- 通常加 `const`，因为拷贝不应修改源对象
- 没有返回值
- 一个类只能有一个拷贝构造函数

</div>

<div class="pitfall">
<span class="label">为什么必须传引用</span>
如果写成 <code>Target(Target other)</code>，传参本身又要拷贝，会无限递归。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 默认拷贝构造：逐成员拷贝

---

<div class="cols">

<div class="col-55">

```cpp
class Target {
    int id_;
    std::string name_;
    int priority_;
    bool built_ = false;
    // 没有自定义拷贝构造
};

Target a(1, "main.o", 2);
Target b = a;
```

编译器生成的拷贝构造等价于：

```cpp
Target(const Target& other)
    : id_(other.id_), name_(other.name_),
      priority_(other.priority_), built_(other.built_) {}
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">逐成员含义</div>

- 基本类型：复制值
- 类类型成员：调用其拷贝构造
- 指针成员：只复制指针值（浅拷贝）
- 数组：逐元素复制（数组成员不能直接赋值）

</div>

<div class="tip">
<span class="label">结论</span>
如果所有成员都能安全地“按值复制”，默认拷贝构造就够用。<code>Target</code> 的 <code>std::string</code> 会自己深拷贝，所以安全。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 浅拷贝：两个对象共用一块资源

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
    ~String() { delete[] data_; }
private:
    std::size_t len_;
    char* data_;
};

String s1("abcd");
String s2 = s1;   // 默认拷贝：只复制指针
```

</div>

<div class="col-45">

<div class="mem">
<div class="mem-head">浅拷贝后的内存</div>
<div class="mem-row"><span class="addr">s1</span><span class="val">len_=4, data_=0x1000</span></div>
<div class="mem-row"><span class="addr">s2</span><span class="val">len_=4, data_=0x1000</span></div>
<div class="mem-row hot"><span class="addr">0x1000</span><span class="val">'a' 'b' 'c' 'd' '\0' ← 两个对象共享</span></div>
</div>

<div class="pitfall mt1">
<span class="label">后果</span>
① 一方修改会影响另一方；② 两个析构函数各 <code>delete[]</code> 一次 → 双重释放；③ 一方先销毁，另一方变成悬空指针。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 深拷贝：每个对象拥有自己的资源

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
class String {
public:
    String(const String& other)
        : len_(other.len_),
          data_(new char[other.len_ + 1]) {
        std::strcpy(data_, other.data_);
    }
    // ...
private:
    std::size_t len_;
    char* data_;
};
```

</div>

<div class="col-45">

<div class="mem">
<div class="mem-head">深拷贝后的内存</div>
<div class="mem-row"><span class="addr">s1</span><span class="val">len_=4, data_=0x1000</span></div>
<div class="mem-row"><span class="addr">s2</span><span class="val">len_=4, data_=0x2000</span></div>
<div class="mem-row"><span class="addr">0x1000</span><span class="val">'a' 'b' 'c' 'd' '\0'</span></div>
<div class="mem-row new"><span class="addr">0x2000</span><span class="val">'a' 'b' 'c' 'd' '\0' ← 新分配</span></div>
</div>

<div class="keypoint mt1">
<span class="label">所有权</span>
每个 <code>String</code> 对象拥有自己的一块字符数组，析构时各自释放，互不干扰。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 拷贝构造中的成员对象

---

<div class="cols">

<div class="col-55">

```cpp
class A {
public:
    A() { std::cout << "A() "; }
    A(const A&) { std::cout << "A(const A&) "; }
};

class B {
public:
    B() { std::cout << "B() "; }

    B(const B& b) : a_(b.a_) {   // 显式拷贝成员
        std::cout << "B(const B&) ";
    }
private:
    A a_;
};
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">关键规则</div>

- 自定义拷贝构造不会自动拷贝成员对象
- 默认调用成员对象的**默认构造函数**
- 要拷贝成员对象，必须在初始化列表中显式调用其拷贝构造

</div>

<div class="pitfall">
<span class="label">常见错误</span>
<code>B(const B&amp; b) { a_ = b.a_; }</code>：<code>a_</code> 先被默认构造，再被赋值；如果 <code>A</code> 不可默认构造，直接编译失败。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 拷贝赋值：对象已经存在

---

<div class="cols">

<div class="col-55">

```cpp
class Target {
public:
    Target& operator=(const Target& other) {
        if (this == &other) return *this;  // 自赋值

        id_ = other.id_;
        name_ = other.name_;
        priority_ = other.priority_;
        built_ = other.built_;
        return *this;
    }
    // ...
};
```

```cpp
Target a(1, "A", 1);
Target b(2, "B", 2);
b = a;      // 调用 operator=
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">默认赋值</div>

编译器生成逐成员赋值：

- 基本类型：赋值
- 类类型成员：调用其 `operator=`
- 指针成员：只复制指针值（浅拷贝）

</div>

<div class="tip">
<span class="label">返回引用</span>
返回 <code>*this</code> 的引用，支持 <code>a = b = c</code> 这样的连续赋值。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 自定义赋值：四个关键动作

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
String& operator=(const String& other) {
    if (this == &other) {       // 1. 自赋值检查
        return *this;
    }

    char* new_data = new char[other.len_ + 1];  // 2. 先分配
    std::strcpy(new_data, other.data_);

    delete[] data_;             // 3. 再释放旧资源
    data_ = new_data;
    len_ = other.len_;

    return *this;               // 4. 返回自身
}
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">为什么这个顺序</div>

- 先 `new`：如果分配失败抛出异常，旧对象仍然完好
- 再 `delete`：避免释放后拷贝源数据（源可能和自己是同一块）
- 先拷贝到临时指针：防止 `new` 成功后 `strcpy` 失败导致半成品

</div>

<div class="keypoint">
<span class="label">异常安全</span>
这个顺序提供<strong>强异常安全保证</strong>：赋值失败时，对象保持原值。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 自赋值：`a = a` 为什么危险？

---

<div class="cols">

<div class="col-55">

**没有自赋值检查**

```cpp
String& operator=(const String& other) {
    delete[] data_;                 // 释放自己的数据
    data_ = new char[other.len_ + 1];
    std::strcpy(data_, other.data_); // other 就是自己！
    // data_ 已被释放，other.data_ 悬空
}
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">两种处理方式</div>

1. 地址检查：`if (this == &other) return *this;`
2. 拷贝并交换：先复制实参，再交换，天然处理自赋值

</div>

<div class="tip">
<span class="label">现实场景</span>
自赋值不一定写成 <code>a = a</code>，也可能是 <code>v[i] = v[j]</code> 且 <code>i == j</code>，或通过引用间接发生。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 更稳健的写法：拷贝并交换

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
class String {
public:
    String& operator=(String other) {  // 按值：先复制
        swap(other);
        return *this;
    }

    void swap(String& other) noexcept {
        std::swap(len_, other.len_);
        std::swap(data_, other.data_);
    }
private:
    std::size_t len_ = 0;
    char* data_ = nullptr;
};
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">优点</div>

- 自赋值安全：交换自己不会出问题
- 异常安全：复制在进入函数前完成
- 代码短，`swap` 可复用
- 移动语义章节可以直接复用

</div>

<div class="pitfall">
<span class="label">前提</span>
<code>swap</code> 必须不抛出异常（<code>noexcept</code>），否则异常安全保证会被破坏。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 三法则

---

<div class="motto">
如果你需要自定义<strong>析构函数</strong>、<strong>拷贝构造函数</strong>或<strong>拷贝赋值运算符</strong>中的任何一个，通常三个都需要。
</div>

<div class="cols mt1">

<div class="col">

<div class="card">

<div class="card-title">析构函数</div>

释放对象拥有的资源。

</div>

</div>

<div class="col">

<div class="card">

<div class="card-title">拷贝构造</div>

复制资源，而不是复制指针。

</div>

</div>

<div class="col">

<div class="card">

<div class="card-title">拷贝赋值</div>

先释放旧资源，再复制新资源。

</div>

</div>

</div>

<div class="keypoint mt1">
<span class="label">为什么</span>
三者共同定义“对象如何拥有资源”。只写其中一个，另外两个的默认行为（浅拷贝、浅赋值）就会破坏所有权模型。
</div>

<div class="small muted center">
C++11 引入移动语义后，三法则扩展为<strong>五法则</strong>：再加上移动构造与移动赋值。下一单元展开。
</div>

---


<!-- slide data-notes="" -->

##### 不需要拷贝的类：禁止拷贝

---

<div class="cols">

<div class="col-55">

```cpp
class FileHandle {
public:
    explicit FileHandle(const char* path)
        : fp_(std::fopen(path, "r")) {}

    ~FileHandle() { if (fp_) std::fclose(fp_); }

    FileHandle(const FileHandle&) = delete;
    FileHandle& operator=(const FileHandle&) = delete;

private:
    std::FILE* fp_;
};
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">语义</div>

文件句柄、锁、网络连接等资源通常<strong>不能被复制</strong>：

- 复制后两个对象都以为自己拥有资源
- 析构时重复关闭/释放

`= delete` 让错误在编译期暴露。

</div>

<div class="tip">
<span class="label">C++11 之前</span>
把拷贝构造/赋值声明为 <code>private</code> 且不实现，也能达到禁止拷贝的效果；<code>= delete</code> 更清晰。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 传值、传引用与返回值优化

---

<div class="cols">

<div class="col">

**按值传参：一次拷贝**

```cpp
void print_target(Target t);   // 拷贝构造
print_target(a);
```

**传常量引用：零拷贝**

```cpp
void print_target(const Target& t);
print_target(a);
```

</div>

<div class="col">

**返回对象：通常零拷贝**

```cpp
Target make_target() {
    return Target(1, "临时", 1);
}

Target t = make_target();
```

<div class="card mt1">

<div class="card-title">RVO / NRVO</div>

编译器可以把返回值直接构造在调用方预留的空间中，省略拷贝/移动。这是允许的优化，C++17 起部分场景是<strong>强制</strong>的。

</div>

</div>

</div>

<div class="pitfall">
<span class="label">不要做的优化</span>
不要为了“减少拷贝”而返回局部对象的引用或指针——对象已经销毁，结果是悬空引用。让编译器做 RVO。
</div>

---


<!-- slide data-notes="" -->

##### 主线案例：`Target` 需要自定义拷贝吗？

---

<div class="cols">

<div class="col-55">

```cpp
class Target {
public:
    Target(int id, std::string name, int priority)
        : id_(id), name_(std::move(name)), priority_(priority) {}

    void rename(const std::string& name) { name_ = name; }

private:
    int id_;
    std::string name_;
    int priority_;
    bool built_ = false;
};

Target a(1, "main.o", 2);
Target b = a;      // 默认拷贝：安全
b.rename("util.o"); // b 的 name_ 独立
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">判断依据</div>

`Target` 的成员：

- `int`、`bool`：值复制
- `std::string`：自己的拷贝构造做深拷贝

因此默认拷贝构造和默认赋值<strong>已经正确</strong>，不需要三法则。

</div>

<div class="keypoint">
<span class="label">原则</span>
只有当类<strong>直接持有裸资源</strong>（`new` 出来的指针、文件句柄、锁）时，才需要自己管理拷贝。优先让成员替你管理资源。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 课堂任务 4：实现 `String` 的深拷贝

---

<div class="cols">

<div class="col-55">

<div class="card">

<div class="card-title">任务</div>

实现一个完整的 `String` 类：

- 构造：`explicit String(const char* s = "")`
- 析构：释放字符数组
- 拷贝构造：深拷贝
- 拷贝赋值：处理自赋值、异常安全、返回 `*this`
- `const char* c_str() const`
- `std::size_t size() const`

在 `main` 中验证：

```cpp
String a("hello");
String b = a;      // 拷贝构造
b = a;             // 自赋值
b = b;             // 自赋值
```

</div>

</div>

<div class="col-45">

<div class="card">

<div class="card-title">验收标准</div>

- 两个对象修改互不影响
- ASan/Valgrind 无泄漏、无双重释放
- `a = a` 不崩溃
- 赋值后原对象内容正确
- 不使用 `std::string`、`std::vector`

</div>

<div class="tip">
<span class="label">提示</span>
先写析构、拷贝构造、拷贝赋值三个函数；再思考赋值时“先分配、后释放”的顺序。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 任务 4 参考实现

---

<div class="cols">

<div class="col-55 code-xs">

```cpp{.line-numbers}
#include <cstddef>
#include <cstring>
#include <iostream>
#include <utility>

class String {
public:
    explicit String(const char* s = "")
        : len_(std::strlen(s)),
          data_(new char[len_ + 1]) {
        std::strcpy(data_, s);
    }

    String(const String& other)
        : len_(other.len_),
          data_(new char[other.len_ + 1]) {
        std::strcpy(data_, other.data_);
    }

    String& operator=(const String& other) {
        if (this == &other) return *this;
        char* new_data = new char[other.len_ + 1];
        std::strcpy(new_data, other.data_);
        delete[] data_;
        data_ = new_data;
        len_ = other.len_;
        return *this;
    }

    ~String() { delete[] data_; }

    const char* c_str() const { return data_; }
    std::size_t size() const { return len_; }

private:
    std::size_t len_;
    char* data_;
};
```

</div>

<div class="col-45">

**测试**

```cpp
int main() {
    String a("hello");
    String b = a;
    b = a;
    b = b;
    std::cout << a.c_str() << " "
              << b.c_str() << "\n";
}
```

<div class="out">hello hello</div>

<div class="small mt1">

**要点**

- 拷贝构造分配新数组
- 赋值先分配后释放，保证异常安全
- 自赋值检查避免释放后使用
- 三法则齐全

</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 常见陷阱

---

<div class="cols">

<div class="col">

**拷贝构造**

- 参数不写引用 → 无限递归
- 忘记拷贝成员对象 → 成员被默认构造
- 只复制指针 → 浅拷贝
- 拷贝构造中修改源对象

</div>

<div class="col">

**拷贝赋值**

- 忘记自赋值检查
- 先 `delete` 再读源数据 → 悬空指针
- 返回 `void` → 无法连续赋值
- 只复制指针 → 双重释放
- 异常发生后对象处于半成品状态

</div>

</div>

<div class="pitfall">
<span class="label">判断口诀</span>
“有资源，想三件事：谁释放、怎么复制、怎么赋值。”如果资源已经由成员（如 <code>std::string</code>、<code>std::vector</code>）管理，就让成员去做。
</div>

---


<!-- slide data-notes="" -->

##### 课堂小测

---

1. `Target b = a;` 与 `b = a;` 分别调用哪个函数？如果 `Target` 没有自定义拷贝构造，编译器会做什么？

2. 默认拷贝构造对指针成员执行的是深拷贝还是浅拷贝？会产生哪些后果？

3. 自定义拷贝赋值时，为什么建议“先分配新资源，再释放旧资源”？

4. 三法则指的是哪三个函数？为什么它们通常要一起出现？

---


<!-- slide data-notes="" -->

##### 小结：复制的是值，管理的是所有权

---

<div class="cols">

<div class="col">

<div class="card">

<div class="card-title">拷贝构造</div>

用已有对象初始化新对象；默认逐成员拷贝；有裸资源时要深拷贝。

</div>

</div>

<div class="col">

<div class="card">

<div class="card-title">拷贝赋值</div>

覆盖已存在对象；处理自赋值、异常安全、返回 `*this`；可用拷贝并交换。

</div>

</div>

<div class="col">

<div class="card">

<div class="card-title">三法则</div>

析构、拷贝构造、拷贝赋值共同定义资源所有权；不需要就 `= delete`。

</div>

</div>

</div>

<div class="motto mt1">
拷贝的难点不在“复制数据”，而在<strong>谁拥有资源、谁负责释放</strong>。想清楚所有权，代码自然正确。
</div>

---


<!-- slide data-notes="" -->

#####

---

<div class="bottom20"></div>

<hr class="width50 center">

## 未完待续

---
