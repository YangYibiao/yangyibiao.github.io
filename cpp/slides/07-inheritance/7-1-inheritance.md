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

## 继承、多继承与组合

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](mailto:yangyibiao@nju.edu.cn)


<!-- slide data-notes="" -->

##### 本讲提纲

---

<div class="cols">

<div class="col">

**继承**

- is-a 关系与单继承
- 访问控制与 protected
- 构造/析构顺序
- 名字隐藏与子类型

</div>

<div class="col">

**更复杂的关系**

- 多继承与名字冲突
- 菱形继承与虚基类
- 聚合/组合
- 组合优于继承

</div>

</div>

<div class="keypoint">
<span class="label">本讲目标</span>
能够判断两个类之间应该是继承还是组合，并写出正确的继承层次与构造/析构顺序。
</div>

---


<!-- slide data-notes="" -->

##### 为什么需要继承？

---

<div class="cols">

<div class="col">

**代码复用**

```cpp
class Target {
public:
    void build() { built_ = true; }
    bool is_built() const { return built_; }
    // 公共数据与操作
};

class FileTarget {
    // 希望拥有 Target 的全部能力
    // 再增加文件时间戳
};
```

复制粘贴一份 `Target` 的代码，会产生两个互相独立的类型，修改时容易不一致。

</div>

<div class="col">

**概念分类**

<div class="fig">
<svg viewBox="0 0 360 210" width="360">
  <rect x="110" y="15" width="140" height="46" rx="8" fill="#fdf6e3" stroke="#268bd2"/>
  <text x="180" y="43" font-size="16" text-anchor="middle" fill="#268bd2">Target</text>
  <rect x="15" y="125" width="150" height="46" rx="8" fill="#fdf6e3" stroke="#859900"/>
  <text x="90" y="153" font-size="14" text-anchor="middle" fill="#859900">FileTarget</text>
  <rect x="195" y="125" width="150" height="46" rx="8" fill="#fdf6e3" stroke="#b58900"/>
  <text x="270" y="153" font-size="14" text-anchor="middle" fill="#b58900">CommandTarget</text>
  <line x1="150" y1="61" x2="90" y2="125" stroke="#93a1a1" marker-end="url(#inh)"/>
  <line x1="210" y1="61" x2="270" y2="125" stroke="#93a1a1" marker-end="url(#inh)"/>
  <text x="105" y="92" font-size="11" fill="#93a1a1">is-a</text>
  <text x="245" y="92" font-size="11" fill="#93a1a1">is-a</text>
  <defs><marker id="inh" markerWidth="10" markerHeight="10" refX="8" refY="3" orient="auto"><path d="M0,0 L8,3 L0,6 z" fill="#93a1a1"/></marker></defs>
</svg>
</div>

`FileTarget` **是一种** `Target`，可以出现在任何需要 `Target` 的地方。

</div>

</div>

<div class="pitfall">
<span class="label">前提</span>
继承表达 <strong>is-a</strong>。如果两个类只是“有”的关系（如 `Scheduler` 有 `TargetList`），应该用组合，而不是继承。
</div>

---


<!-- slide data-notes="" -->

##### 单继承：语法与派生类成员

---

<div class="cols">

<div class="col-55">

```cpp
class Target {
public:
    void build() { built_ = true; }
    void print() const;
protected:
    std::string name_;
private:
    int id_ = 0;
    bool built_ = false;
};

class FileTarget : public Target {
public:
    void set_stamp(FileStamp s) { stamp_ = s; }
private:
    FileStamp stamp_;
};
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">派生类拥有</div>

- 基类的全部数据成员与成员函数
- 自己新增的成员
- 可以重定义基类的成员函数
- 不能直接访问基类的 `private` 成员

</div>

<div class="tip">
<span class="label">继承方式</span>
<code>class Derived : public Base</code>；默认继承方式是 <code>private</code>（<code>class</code>）或 <code>public</code>（<code>struct</code>）。
</div>

</div>

</div>

<div class="small muted center">
基类的构造函数、析构函数、赋值运算符不会被继承（C++11 可用 `using Base::Base` 继承构造函数）。
</div>

---


<!-- slide data-notes="" -->

##### 访问控制：三层视角

---

<div class="table-sm">

| 基类成员 | public 继承 | protected 继承 | private 继承 |
| :-- | :-- | :-- | :-- |
| `public` | `public` | `protected` | `private` |
| `protected` | `protected` | `protected` | `private` |
| `private` | 不可访问 | 不可访问 | 不可访问 |

</div>

<div class="cols mt1">

<div class="col">

**public 继承：is-a**

```cpp
class FileTarget : public Target {
    // 外界可以把 FileTarget
    // 当作 Target 使用
};
```

</div>

<div class="col">

**private 继承：实现复用**

```cpp
class Queue : private LinearList {
    // 外界不知道 Queue 是 LinearList
    // 本质更接近“组合”
};
```

</div>

</div>

<div class="keypoint">
<span class="label">默认选择</span>
需要子类型关系 → <code>public</code> 继承；只想复用实现 → 优先用组合；<code>private</code> 继承很少是最好选择。
</div>

---


<!-- slide data-notes="" -->

##### `protected`：给派生类开的接口

---

<div class="cols">

<div class="col-55">

```cpp
class Target {
protected:
    std::string name_;   // 派生类可直接使用
public:
    void print() const;
private:
    int id_ = 0;           // 派生类也不可直接访问
};

class FileTarget : public Target {
public:
    void rename(const std::string& t) {
        name_ = t;        // OK
        // id_ = 1;        // 错误：private
    }
};
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">定位</div>

- 对派生类开放
- 对类外代码不可见
- 缓解“继承需要访问基类实现”与“封装”的矛盾

</div>

<div class="pitfall">
<span class="label">设计建议</span>
<code>protected</code> 数据成员会把基类的表示暴露给所有派生类，增加耦合。更推荐 <code>private</code> 数据 + <code>protected</code> 的受控操作。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 构造与析构顺序

---

<div class="cols">

<div class="col-55">

```cpp
class Base {
public:
    Base() { std::cout << "Base "; }
    ~Base() { std::cout << "~Base "; }
};

class Derived : public Base {
public:
    Derived() { std::cout << "Derived "; }
    ~Derived() { std::cout << "~Derived "; }
};

int main() { Derived d; }
```

</div>

<div class="col-45">

**输出**

<div class="out">Base Derived ~Derived ~Base</div>

<div class="card mt1">

<div class="card-title">顺序</div>

- 构造：基类 → 成员对象 → 派生类
- 析构：派生类 → 成员对象 → 基类
- 基类先构造完成，派生类才能安全使用基类部分

</div>

<div class="small muted mt1">
若基类没有默认构造函数，派生类必须在初始化列表中显式调用基类构造函数。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 派生类构造函数：显式初始化基类

---

<div class="cols">

<div class="col-55">

```cpp
class Target {
public:
    Target(int id, std::string name, int priority)
        : id_(id), name_(std::move(name)), priority_(priority) {}
private:
    int id_;
    std::string name_;
    int priority_;
};

class FileTarget : public Target {
public:
    FileTarget(int id, std::string name, int priority, FileStamp stamp)
        : Target(id, std::move(name), priority),   // 基类构造
          stamp_(stamp) {}
private:
    FileStamp stamp_;
};
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">规则</div>

- 默认调用基类的默认构造函数
- 要调用非默认版本，必须在初始化列表中写出
- 基类初始化先于成员对象
- 初始化列表只写一次基类名

</div>

<div class="tip">
<span class="label">顺序提醒</span>
即使把 <code>Target(...)</code> 写在 <code>stamp_</code> 后面，基类仍然先构造。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 继承构造函数 <span class="std cxx11">C++11</span>

---

<div class="cols">

<div class="col-55">

**传统写法：逐个转发**

```cpp
class Derived : public Base {
public:
    Derived(int x) : Base(x) {}
    Derived(char c) : Base(c) {}
    Derived(int x, char c) : Base(x, c) {}
};
```

**C++11：继承构造函数**

```cpp
class Derived : public Base {
public:
    using Base::Base;   // 继承 Base 的所有构造函数
};
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">注意</div>

- 继承构造函数不能初始化派生类新增成员
- 新增成员用就地初始化或默认值
- 如果派生类需要额外逻辑，仍需自己写构造函数

</div>

<div class="pitfall">
<span class="label">适用</span>
派生类只是“基类 + 少量默认状态”时很方便；一旦需要控制新增成员，显式写构造函数更清晰。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 名字隐藏：派生类作用域是内层

---

<div class="cols">

<div class="col-55">

```cpp
class Base {
public:
    void f(int x) { std::cout << "Base::f(int)"; }
};

class Derived : public Base {
public:
    void f(const std::string& s) {
        std::cout << "Derived::f(string)";
    }
};

Derived d;
d.f(1);            // 错误：Base::f 被隐藏
d.Base::f(1);      // OK：显式限定
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">规则</div>

- 派生类作用域嵌套在基类作用域内
- 同名成员会隐藏基类的所有同名重载
- 用 `Base::f` 显式访问
- 用 `using Base::f;` 把基类重载引入派生类作用域

</div>

<div class="pitfall">
<span class="label">不是重载</span>
基类与派生类的同名函数属于不同作用域，不构成重载；参数不同也一样会隐藏。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 子类型与向上转型

---

<div class="cols">

<div class="col-55">

```cpp
class Target { /* ... */ };
class FileTarget : public Target { /* ... */ };

FileTarget d(1, "main.o", 1, FileStamp(1700000000));

Target a = d;          // OK：切片，只复制 Target 部分
Target& r = d;         // OK：引用绑定到基类子对象
Target* p = &d;        // OK：指针指向基类子对象

void f(Target t);      // 按值：切片
void g(Target& t);     // 引用：不切片
void h(Target* t);     // 指针：不切片
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">public 继承 = 子类型</div>

- 派生类对象可以替代基类对象
- 基类接口可以作用于派生类对象
- 反过来不成立

</div>

<div class="pitfall">
<span class="label">对象切片</span>
按值传递/赋值时，派生类新增的成员被丢弃，只剩基类部分。多态必须通过指针或引用。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 派生类的拷贝与赋值

---

<div class="cols">

<div class="col-55">

```cpp
class Derived : public Base {
public:
    Derived(const Derived& other)
        : Base(other),      // 调用基类拷贝构造
          extra_(other.extra_) {}

    Derived& operator=(const Derived& other) {
        if (this != &other) {
            Base::operator=(other);  // 基类部分
            extra_ = other.extra_;
        }
        return *this;
    }
private:
    int extra_;
};
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">规则</div>

- 默认拷贝构造会调用基类拷贝构造
- 自定义拷贝构造默认调用基类**默认构造**，需要显式 `Base(other)`
- 默认赋值会调用基类赋值
- 自定义赋值不会自动调用基类赋值，需要显式 `Base::operator=`

</div>

<div class="small muted mt1">
与成员对象的规则一致：自定义操作不会自动帮你处理“父对象部分”。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 多继承：一个类，多个直接基类

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
class A {
public:
    void fa();
};

class B {
public:
    void fb();
};

class C : public A, public B {
public:
    void fc();
};

C c;
c.fa();   // 来自 A
c.fb();   // 来自 B
c.fc();   // 自己的
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">对象布局</div>

<div class="mem">
<div class="mem-head">C 对象（示意）</div>
<div class="mem-row"><span class="addr">+0</span><span class="val">A 子对象</span></div>
<div class="mem-row"><span class="addr">+?</span><span class="val">B 子对象</span></div>
<div class="mem-row"><span class="addr">+?</span><span class="val">C 自己的成员</span></div>
</div>

<div class="small muted mt1">
<code>A* pa = &amp;c;</code> 与 <code>B* pb = &amp;c;</code> 可能指向对象的不同偏移。
</div>

</div>

</div>

</div>

<div class="keypoint">
<span class="label">用途</span>
多继承适合“一个对象同时具备多种能力”的场景；但会增加语言复杂度，很多语言只支持单继承 + 接口。
</div>

---


<!-- slide data-notes="" -->

##### 多继承的名字冲突

---

<div class="cols">

<div class="col-55">

```cpp
class A { public: void f(); };
class B { public: void f(); };

class C : public A, public B {
public:
    void g() {
        // f();        // 错误：A::f 还是 B::f？
        A::f();        // OK
        B::f();        // OK
    }
};

C c;
c.A::f();
c.B::f();
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">解决方式</div>

- 用基类名限定：`A::f()`
- 在派生类中重定义 `f()`，内部显式调用需要的版本
- 设计上避免两个基类提供同名接口

</div>

<div class="tip">
<span class="label">接口设计</span>
如果多继承用于“实现多个接口”，接口应使用不同名字，或只保留一个实现。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 菱形继承与虚基类

---

<div class="cols">

<div class="col-55">

```cpp
class A { protected: int x_; };
class B : virtual public A { };
class C : virtual public A { };
class D : public B, public C { };

D d;   // d 中只有一个 A 子对象
```

不加 `virtual` 时，`D` 中有两份 `A`：`B::A::x_` 与 `C::A::x_`，访问 `d.x_` 产生歧义。

</div>

<div class="col-45">

<div class="fig">
<svg viewBox="0 0 340 220" width="310">
  <rect x="130" y="10" width="80" height="36" rx="6" fill="#fdf6e3" stroke="#268bd2"/>
  <text x="170" y="33" font-size="14" text-anchor="middle" fill="#268bd2">A</text>
  <rect x="40" y="90" width="80" height="36" rx="6" fill="#fdf6e3" stroke="#859900"/>
  <text x="80" y="113" font-size="14" text-anchor="middle" fill="#859900">B</text>
  <rect x="220" y="90" width="80" height="36" rx="6" fill="#fdf6e3" stroke="#b58900"/>
  <text x="260" y="113" font-size="14" text-anchor="middle" fill="#b58900">C</text>
  <rect x="130" y="160" width="80" height="36" rx="6" fill="#fdf6e3" stroke="#dc322f"/>
  <text x="170" y="183" font-size="14" text-anchor="middle" fill="#dc322f">D</text>
  <line x1="150" y1="46" x2="80" y2="90" stroke="#93a1a1"/>
  <line x1="190" y1="46" x2="260" y2="90" stroke="#93a1a1"/>
  <line x1="80" y1="126" x2="150" y2="160" stroke="#93a1a1"/>
  <line x1="260" y1="126" x2="190" y2="160" stroke="#93a1a1"/>
</svg>
</div>

<div class="small muted center">
虚继承让 `D` 只保留一份 `A` 子对象；构造 `A` 的责任转移到最派生类。
</div>

</div>

</div>

<div class="pitfall">
<span class="label">代价</span>
虚基类会增加对象布局和构造的复杂度。多数业务代码应优先用组合，而不是菱形继承。
</div>

---


<!-- slide data-notes="" -->

##### 聚合与组合：has-a 关系

---

<div class="cols">

<div class="col">

**聚合（aggregation）**

- 被包含对象在外部创建
- 可以独立存在
- 通常用指针/引用表示

```cpp
class Company {
    std::vector<Employee*> staff_;
};
```

员工离职后仍存在。

</div>

<div class="col">

**组合（composition）**

- 被包含对象随整体创建/销毁
- 不能独立存在
- 通常用对象成员表示

```cpp
class TargetList {
    std::vector<Target> targets_;
};
```

`TargetList` 销毁，目标也销毁。

</div>

</div>

<div class="keypoint mt1">
<span class="label">共同点</span>
两者都是“整体拥有部分”，区别在<strong>生命周期是否绑定</strong>。实现上都优先让成员对象/容器管理资源。
</div>

---


<!-- slide data-notes="" -->

##### 组合优于继承：Queue 的例子

---

<div class="cols">

<div class="col-55 code-xs">

**用组合实现队列**

```cpp
class Queue {
public:
    void enqueue(int x) {
        list_.insert(x, list_.length());
    }
    bool dequeue(int& x) {
        return list_.remove(x, 1);
    }
private:
    LinearList list_;   // has-a
};
```

</div>

<div class="col-45 code-xs">

**用 private 继承实现**

```cpp
class Queue : private LinearList {
public:
    void enqueue(int x) {
        insert(x, length());
    }
    bool dequeue(int& x) {
        return remove(x, 1);
    }
};
```

</div>

</div>

<div class="keypoint">
<span class="label">选择</span>
<code>private</code> 继承把基类 public 接口变成 private，外界看不到 is-a，本质更接近组合。若只是使用 <code>LinearList</code> 的能力，用组合；只有“Queue 是一种 LinearList”才用 public 继承。
</div>

---


<!-- slide data-notes="" -->

##### 继承 vs 组合：判断清单

---

<div class="table-sm">

| 问题 | 是 → 继承 | 否 → 组合 |
| :-- | :-- | :-- |
| B 是 A 的一种吗？ | `FileTarget` 是 `Target` | `Scheduler` 不是 `TargetList` |
| 需要把 B 传给接受 A 的函数吗？ | 需要子类型替换 | 不需要 |
| B 需要访问 A 的 protected 成员吗？ | 可能需要继承 | 用 public 接口 |
| 只是为了复用 A 的代码吗？ | 不应继承 | 用组合 |
| A 的实现变化会影响 B 吗？ | 继承耦合更强 | 组合更松 |

</div>

<div class="motto mt1">
优先使用组合：它耦合更低、更容易测试、生命周期更清晰。继承应留给真正的 is-a 与多态需求。
</div>

---


<!-- slide data-notes="" -->

##### 主线案例：`FileTarget`

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
class FileStamp {
public:
    explicit FileStamp(long mtime) : mtime_(mtime) {}
    long mtime() const { return mtime_; }
private:
    long mtime_;
};

class FileTarget : public Target {
public:
    FileTarget(int id, std::string name,
                 int priority, FileStamp stamp)
        : Target(id, std::move(name), priority),
          stamp_(stamp) {}

    void print_stamp() const {
        std::cout << "mtime: " << stamp_.mtime() << "\n";
    }
private:
    FileStamp stamp_;
};
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">关系</div>

- `FileTarget` **是一种** `Target`
- 继承 `Target` 的 `build()`、`is_built()`、`id()`
- 增加 `stamp_` 成员与 `print_stamp()`
- 构造时先构造 `Target`，再构造 `stamp_`

</div>

<div class="tip">
<span class="label">设计选择</span>
如果只是“文件目标带一个时间戳”，也可以把 `FileStamp` 作为 `Target` 的成员（组合）。只有确实需要“文件目标是构建目标”并参与多态时，才建立继承。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 课堂任务 7：设计 `CommandTarget`

---

<div class="cols">

<div class="col-55">

<div class="card">

<div class="card-title">任务</div>

设计 `CommandTarget`，继承 `Target`：

- 新增 `std::string command_`（要执行的命令）
- 构造函数：`CommandTarget(int id, std::string name, int priority, std::string command)`
- 新增 `const std::string& command() const`
- 新增 `void append_arg(const std::string& arg)`：追加一个参数
- 重定义 `print()`，在基类输出后追加 `[cmd: ...]`

在 `main` 中创建 `FileTarget` 与 `CommandTarget`，分别调用基类接口与自己的接口。

</div>

</div>

<div class="col-45">

<div class="card">

<div class="card-title">验收标准</div>

- 构造函数正确调用 `Target` 的构造函数
- 基类 `private` 成员不直接被访问
- `CommandTarget` 可以传给接受 `const Target&` 的函数
- 输出格式统一
- 编译无警告

</div>

<div class="tip">
<span class="label">提示</span>
如果基类的 <code>print()</code> 不是虚函数，派生类的同名函数会隐藏它；在派生类中可以用 <code>Target::print()</code> 显式调用基类版本。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 任务 7 参考实现

---

<div class="cols">

<div class="col-55 code-sm">

```cpp{.line-numbers}
class CommandTarget : public Target {
public:
    CommandTarget(int id, std::string name,
                  int priority, std::string command)
        : Target(id, std::move(name), priority),
          command_(std::move(command)) {}

    const std::string& command() const {
        return command_;
    }

    void append_arg(const std::string& arg) {
        command_ += " " + arg;
    }

    void print() const {
        Target::print();   // 调用基类版本
        std::cout << " [cmd: " << command_ << "]\n";
    }

private:
    std::string command_;
};
```

</div>

<div class="col-45">

**使用**

```cpp
CommandTarget c(1, "app", 2, "g++ main.o util.o -o app");
c.build();          // 继承自 Target
c.print();

void show(const Target& t) {
    t.print();         // 静态绑定：Target::print
}
```

<div class="small mt1">

**观察**

- `c.build()` 来自基类
- `c.print()` 调用派生类版本
- 通过 `const Target&` 调用时，仍执行 `Target::print`——因为 `print` 不是虚函数
- 下一单元用 `virtual` 解决这个问题

</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 常见陷阱

---

<div class="cols">

<div class="col">

**继承语义**

- 为了复用代码而继承（应组合）
- `private` 继承后仍以为有 is-a 关系
- 把 `has-a` 写成继承
- 继承层次过深

</div>

<div class="col">

**语法与行为**

- 基类无默认构造，派生类忘记初始化
- 同名函数隐藏基类重载
- 按值传递导致对象切片
- 派生类自定义拷贝构造忘记 `Base(other)`
- 多继承名字冲突不用 `A::` 限定
- 菱形继承不加 `virtual`

</div>

</div>

<div class="pitfall">
<span class="label">下一单元的伏笔</span>
通过基类指针/引用调用派生类重定义的函数，默认仍然是基类版本——这就是“静态绑定”。要实现运行时多态，需要虚函数。
</div>

---


<!-- slide data-notes="" -->

##### 课堂小测

---

1. public 继承、protected 继承、private 继承分别如何改变基类成员的访问级别？

2. 构造 `Derived` 对象时，基类、成员对象、派生类的构造顺序是什么？析构顺序呢？

3. 什么是对象切片？为什么多态必须通过指针或引用？

4. `Scheduler` 需要管理一个 `TargetList`，应该用继承还是组合？请说明理由。

---


<!-- slide data-notes="" -->

##### 小结：继承是分类，组合是装配

---

<div class="cols">

<div class="col">

<div class="card">

<div class="card-title">继承</div>

- 表达 is-a
- public 继承形成子类型
- 构造：基类 → 成员 → 派生
- 注意名字隐藏、切片、菱形

</div>

</div>

<div class="col">

<div class="card">

<div class="card-title">组合</div>

- 表达 has-a
- 生命周期更清晰
- 耦合更低
- 优先选择

</div>

</div>

<div class="col">

<div class="card">

<div class="card-title">判断</div>

- 需要替换/多态 → 继承
- 只是使用能力 → 组合
- 不确定时 → 先组合

</div>

</div>

</div>

<div class="motto mt1">
继承让类型之间建立“是一种”的关系；组合让对象之间建立“有一个”的关系。<strong>用错关系，比写错语法更难维护。</strong>
</div>

---


<!-- slide data-notes="" -->

#####

---

<div class="bottom20"></div>

<hr class="width50 center">

## 未完待续

---
