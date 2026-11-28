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

## 多态与动态绑定

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](mailto:yangyibiao@nju.edu.cn)


<!-- slide data-notes="" -->

##### 本讲提纲

---

<div class="cols">

<div class="col">

**动态绑定**

- 静态绑定的困境
- 虚函数与 `override`
- 虚函数表的基本原理
- 虚析构函数

</div>

<div class="col">

**抽象与接口**

- 纯虚函数与抽象类
- 面向接口编程
- 开闭原则
- `dynamic_cast` 与 RTTI

</div>

</div>

<div class="keypoint">
<span class="label">本讲目标</span>
能够用抽象基类定义稳定接口，让高层代码在新增派生类时保持不变，并解释动态绑定的代价与边界。
</div>

---


<!-- slide data-notes="" -->

##### 静态绑定的困境

---

<div class="cols">

<div class="col-55">

```cpp
class Task {
public:
    void run() const {
        std::cout << "Task::run\n";
    }
};

class PrintTask : public Task {
public:
    void run() const {
        std::cout << "PrintTask::run\n";
    }
};

void execute(const Task& t) {
    t.run();          // 调用哪个版本？
}

PrintTask p;
execute(p);           // 输出：Task::run
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">为什么</div>

编译器看到的是 `const Task&`，只知道 `Task::run`。它不会去猜“运行时引用实际指向谁”。

<div class="small muted mt1">
默认采用<strong>静态绑定</strong>：调用哪个函数由表达式的<strong>静态类型</strong>在编译时决定。
</div>

</div>

<div class="pitfall">
<span class="label">需求</span>
我们希望 <code>execute</code> 根据对象的<strong>动态类型</strong>选择 <code>run</code>——这就是动态绑定。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 虚函数：把选择推迟到运行时刻

---

<div class="cols">

<div class="col-55">

```cpp
class Task {
public:
    virtual void run() const {
        std::cout << "Task::run\n";
    }
    virtual ~Task() = default;
};

class PrintTask : public Task {
public:
    void run() const override {
        std::cout << "PrintTask::run\n";
    }
};

void execute(const Task& t) { t.run(); }

PrintTask p;
execute(p);           // 输出：PrintTask::run
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">两个条件</div>

1. 基类把函数声明为 `virtual`
2. 通过基类的**指针或引用**调用

缺少任何一个，仍然是静态绑定。

</div>

<div class="tip">
<span class="label">override</span>
派生类写 <code>override</code>，让编译器检查“确实重写了基类虚函数”。签名写错时会直接报错。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 动态绑定的三个条件

---

<div class="table-sm">

| 条件 | 满足时 | 不满足时 |
| :-- | :-- | :-- |
| 基类函数是 `virtual` | 动态绑定 | 静态绑定 |
| 通过指针/引用调用 | 动态绑定 | 按值调用 → 切片 + 静态绑定 |
| 派生类函数签名相同 | 重写成功 | 隐藏/新函数，不参与多态 |

</div>

<div class="cols mt1">

<div class="col">

```cpp
void f(Task& t)  { t.run(); }  // 动态
void g(Task* p)  { p->run(); } // 动态
void h(Task t)   { t.run(); }  // 静态 + 切片
```

</div>

<div class="col">

<div class="card">

<div class="card-title">签名相同的含义</div>

- 函数名相同
- 参数类型、个数相同
- 返回类型兼容
- `const` 限定相同

</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 重载、重写、隐藏

---

<div class="table-sm">

| 概念 | 作用域 | 条件 | 绑定 |
| :-- | :-- | :-- | :-- |
| 重载 overload | 同一作用域 | 同名、参数不同 | 编译时 |
| 重写 override | 基类/派生类 | 同名、同签名、基类 `virtual` | 运行时 |
| 隐藏 hide | 基类/派生类 | 同名但不同签名，或基类非虚 | 编译时 |

</div>

<div class="cols mt1">

<div class="col">

```cpp
class Base {
public:
    virtual void f(int);
    void g(int);
};

class Derived : public Base {
public:
    void f(int) override;   // 重写
    void f(double);         // 隐藏 Base::f(int)
    void g(int);            // 隐藏 Base::g(int)
};
```

</div>

<div class="col">

<div class="card">

<div class="card-title">注意</div>

派生类的同名函数会隐藏基类的**所有**同名重载，即使参数不同。需要时用 `using Base::f;` 引入。

</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 虚函数表：动态绑定的实现（示意）

---

<div class="cols">

<div class="col-55">

```cpp
class Base {
public:
    virtual void f();
    virtual void g();
    void h();
};

class Derived : public Base {
public:
    void f() override;
    void h();
};

Base* p = new Derived;
p->h();   // 静态绑定：Base::h
p->f();   // 动态绑定：Derived::f
```

</div>

<div class="col-45">

<div class="fig">
<svg viewBox="0 0 560 250" width="520">
  <rect x="20" y="30" width="190" height="150" rx="8" fill="#fdf6e3" stroke="#268bd2"/>
  <text x="115" y="52" font-size="14" text-anchor="middle" fill="#268bd2">Derived 对象</text>
  <line x1="35" y1="62" x2="195" y2="62" stroke="#93a1a1"/>
  <text x="40" y="82" font-size="13" fill="#657b83">vptr</text>
  <text x="40" y="105" font-size="13" fill="#657b83">Base 部分</text>
  <text x="40" y="128" font-size="13" fill="#657b83">Derived 部分</text>
  <rect x="300" y="30" width="220" height="120" rx="8" fill="#fdf6e3" stroke="#859900"/>
  <text x="410" y="52" font-size="14" text-anchor="middle" fill="#859900">Derived 的虚函数表</text>
  <line x1="315" y1="62" x2="505" y2="62" stroke="#93a1a1"/>
  <text x="320" y="84" font-size="13" fill="#657b83">[0] &amp;Derived::f</text>
  <text x="320" y="106" font-size="13" fill="#657b83">[1] &amp;Base::g</text>
  <line x1="210" y1="76" x2="300" y2="76" stroke="#dc322f" stroke-width="2" marker-end="url(#vt)"/>
  <text x="255" y="68" font-size="11" text-anchor="middle" fill="#dc322f">vptr</text>
  <defs><marker id="vt" markerWidth="8" markerHeight="8" refX="7" refY="4" orient="auto"><path d="M0,0 L8,4 L0,8 z" fill="#dc322f"/></marker></defs>
</svg>
</div>

<div class="small muted center">
`p->f()` 大致编译为：取 `p` 的 vptr → 查表第 0 项 → 以 `p` 为 `this` 调用。
</div>

</div>

</div>

<div class="keypoint">
<span class="label">代价</span>
每个多态对象多一个指针；每次虚调用多一次间接寻址。通常可接受，但在极端性能敏感的代码中要权衡。
</div>

---


<!-- slide data-notes="" -->

##### 虚析构函数：通过基类指针删除

---

<div class="cols">

<div class="col-55">

```cpp
class Base {
public:
    virtual ~Base() = default;
};

class Derived : public Base {
public:
    ~Derived() override {
        std::cout << "~Derived\n";
    }
};

Base* p = new Derived;
delete p;   // 两个析构函数都会执行
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">规则</div>

- 基类析构函数声明为 `virtual`
- 派生类析构函数自动成为虚函数
- 通过基类指针 `delete` 时，才能正确调用派生类析构

</div>

<div class="pitfall">
<span class="label">不写的后果</span>
如果 <code>~Base()</code> 不是虚函数，<code>delete p</code> 只调用 <code>~Base()</code>，派生类的资源不会释放——未定义行为。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 构造/析构中的虚调用

---

<div class="cols">

<div class="col-55">

```cpp
class Base {
public:
    Base() { f(); }      // 调用 Base::f
    virtual void f() const {
        std::cout << "Base::f\n";
    }
};

class Derived : public Base {
public:
    void f() const override {
        std::cout << "Derived::f\n";
    }
};

Derived d;   // 输出：Base::f
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">为什么</div>

构造 `Derived` 时，先构造 `Base` 子对象。此时 `Derived` 部分还没构造，对象还不算完整的 `Derived`，所以虚调用只能绑定到当前构造层次。

析构时同理：先销毁派生类部分，再析构基类；基类析构中的虚调用只到基类。

</div>

<div class="tip">
<span class="label">设计建议</span>
构造/析构函数中尽量不要调用虚函数；需要“构造后初始化”时，提供显式的 <code>init()</code> 或工厂函数。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 纯虚函数与抽象类

---

<div class="cols">

<div class="col-55">

```cpp
class Task {
public:
    virtual ~Task() = default;

    virtual void run() const = 0;     // 纯虚函数
    virtual std::string name() const = 0;
};

// Task t;   // 错误：抽象类不能实例化
```

<div class="small muted mt1">
纯虚函数可以没有实现；也可以提供默认实现（`= 0` 仍可有函数体），但派生类仍必须重写。
</div>

</div>

<div class="col-45">

<div class="card">

<div class="card-title">抽象类的用途</div>

- 定义一组派生类的公共接口
- 不能创建对象，只能作为基类
- 强制派生类实现关键操作
- 让高层代码依赖抽象，而不是具体类型

</div>

<div class="keypoint">
<span class="label">接口即契约</span>
抽象类规定“必须能做什么”，派生类决定“怎么做”。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 接口类：只包含纯虚函数

---

<div class="cols">

<div class="col-55">

```cpp
class Serializable {
public:
    virtual ~Serializable() = default;
    virtual std::string serialize() const = 0;
    virtual void deserialize(const std::string&) = 0;
};

class Printable {
public:
    virtual ~Printable() = default;
    virtual void print(std::ostream&) const = 0;
};

class Task : public Serializable, public Printable {
public:
    // 实现两个接口
};
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">接口类的特征</div>

- 没有数据成员
- 只有纯虚函数 + 虚析构
- 表达“具备某种能力”
- 一个类可以实现多个接口

</div>

<div class="tip">
<span class="label">与抽象基类区别</span>
抽象基类可以有数据成员和已实现的方法；接口类只描述能力，不携带状态。C++ 没有单独的 `interface` 关键字。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 多态案例：图形绘制

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
class Figure {
public:
    virtual ~Figure() = default;
    virtual void draw() const = 0;
    virtual double area() const = 0;
};

class Circle : public Figure {
public:
    explicit Circle(double r) : r_(r) {}
    void draw() const override {
        std::cout << "Circle r=" << r_ << "\n";
    }
    double area() const override {
        return 3.14159 * r_ * r_;
    }
private:
    double r_;
};
```

</div>

<div class="col-45">

```cpp
std::vector<Figure*> figures;
figures.push_back(new Circle(2));
figures.push_back(new Rectangle(3, 4));

for (Figure* f : figures) {
    f->draw();          // 动态绑定
    std::cout << f->area() << "\n";
}
```

<div class="keypoint">
<span class="label">关键</span>
循环只依赖 <code>Figure</code> 接口；新增 <code>Triangle</code> 时，循环代码<strong>不需要修改</strong>。
</div>

<div class="small muted mt1">
这里用裸指针是为了聚焦多态；对象的释放与所有权在内存安全单元用智能指针处理。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 开闭原则：对扩展开放，对修改关闭

---

<div class="cols">

<div class="col">

**违反开闭**

```cpp
void draw_all(const std::vector<Shape>& shapes) {
    for (const auto& s : shapes) {
        switch (s.type) {
        case Shape::Circle:
            draw_circle(s);
            break;
        case Shape::Rectangle:
            draw_rectangle(s);
            break;
        // 每新增一种图形都要改这里
        }
    }
}
```

</div>

<div class="col">

**多态方案**

```cpp
void draw_all(const std::vector<Figure*>& figures) {
    for (Figure* f : figures) {
        f->draw();
    }
}
```

<div class="card mt1">

<div class="card-title">变化点隔离</div>

- 高层代码：只调用接口
- 低层代码：每种图形自己实现
- 新增图形：新增类，不改循环

</div>

</div>

</div>

<div class="motto">
多态的工程价值：把“变化”关进派生类，把“稳定”留给高层代码。
</div>

---


<!-- slide data-notes="" -->

##### `dynamic_cast` 与 RTTI

---

<div class="cols">

<div class="col-55">

```cpp
void maybe_postpone(Task* t) {
    if (auto* r = dynamic_cast<RecurringTask*>(t)) {
        r->postpone_one_cycle();   // 安全向下转型
    }
}
```

- 需要基类至少有一个虚函数（多态类型）
- 转换失败返回 `nullptr`（指针）或抛出 `bad_cast`（引用）
- 运行时有开销

</div>

<div class="col-45">

<div class="card">

<div class="card-title">使用建议</div>

- 优先通过虚函数让对象自己处理，而不是外部 `dynamic_cast` 分支
- 确实需要“按具体类型做特殊操作”时才用
- 不要用 C 风格强转替代；失败时行为未定义

</div>

<div class="pitfall">
<span class="label">设计味道</span>
大量 <code>dynamic_cast</code> 往往说明接口缺少一个虚函数。把差异放进派生类，而不是堆在外部 <code>if</code> 里。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 对象切片：多态为什么必须用指针/引用

---

<div class="cols">

<div class="col-55">

```cpp
class Base {
public:
    virtual void f() const { std::cout << "Base"; }
};
class Derived : public Base {
public:
    void f() const override { std::cout << "Derived"; }
};

void by_value(Base b) { b.f(); }   // 切片

Derived d;
by_value(d);        // 输出 Base
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">切片时发生什么</div>

- 只复制 `Base` 子对象到形参 `b`
- 派生类新增成员丢失
- `b` 的静态类型和动态类型都是 `Base`
- 虚表指针被设置为 `Base` 的虚表

</div>

<div class="tip">
<span class="label">规则</span>
多态参数用 <code>const Base&amp;</code> 或 <code>Base*</code>；容器存指针/智能指针，而不是基类对象值。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 主线案例：抽象 `Task` 与统一执行

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
class Task {
public:
    virtual ~Task() = default;
    virtual void run() const = 0;
    virtual std::string describe() const = 0;
};

class PrintTask : public Task {
public:
    explicit PrintTask(std::string text)
        : text_(std::move(text)) {}
    void run() const override {
        std::cout << text_ << "\n";
    }
    std::string describe() const override {
        return "print: " + text_;
    }
private:
    std::string text_;
};
```

</div>

<div class="col-45">

```cpp
void execute_all(const std::vector<Task*>& tasks) {
    for (Task* t : tasks) {
        t->run();          // 动态绑定
    }
}

PrintTask p("hello");
RecurringTask r(...);
std::vector<Task*> tasks{&p, &r};
execute_all(tasks);
```

<div class="keypoint">
<span class="label">稳定点</span>
<code>execute_all</code> 不知道也不关心具体任务类型；新增任务类型时它不需要修改。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 课堂任务 8：为任务体系加入 `describe()`

---

<div class="cols">

<div class="col-55">

<div class="card">

<div class="card-title">任务</div>

在抽象基类 `Task` 上增加：

```cpp
virtual std::string describe() const = 0;
```

为 `PrintTask`、`RecurringTask`、`DeadlineTask` 分别实现：

- `PrintTask`：`"print: <text>"`
- `RecurringTask`：`"recurring every N days"`
- `DeadlineTask`：`"deadline: <date>"`

实现 `print_all(const std::vector<Task*>&)`，对每个任务输出 `describe()`。

</div>

</div>

<div class="col-45">

<div class="card">

<div class="card-title">验收标准</div>

- `Task` 不能实例化
- 每个派生类都实现 `describe()`
- `print_all` 不含 `switch` / `dynamic_cast`
- 新增一个任务类型时，`print_all` 不需要修改
- 所有派生类析构函数正确执行

</div>

<div class="tip">
<span class="label">提示</span>
每个派生类的 <code>describe()</code> 返回自己的描述；基类不需要知道格式细节。析构函数用 <code>override</code> 标记。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 任务 8 参考实现（节选）

---

<div class="cols">

<div class="col-55 code-xs">

```cpp{.line-numbers}
class Task {
public:
    virtual ~Task() = default;
    virtual void run() const = 0;
    virtual std::string describe() const = 0;
};

class PrintTask : public Task {
public:
    explicit PrintTask(std::string text)
        : text_(std::move(text)) {}
    void run() const override {
        std::cout << text_ << "\n";
    }
    std::string describe() const override {
        return "print: " + text_;
    }
private:
    std::string text_;
};

class RecurringTask : public Task {
public:
    RecurringTask(std::string title, int interval)
        : title_(std::move(title)),
          interval_(interval) {}
    void run() const override {
        std::cout << "run " << title_ << "\n";
    }
    std::string describe() const override {
        return "recurring every " +
               std::to_string(interval_) + " days";
    }
private:
    std::string title_;
    int interval_;
};
```

</div>

<div class="col-45 code-xs">

```cpp{.line-numbers}
void print_all(const std::vector<Task*>& tasks) {
    for (Task* t : tasks) {
        std::cout << t->describe() << "\n";
    }
}

int main() {
    PrintTask p("hello");
    RecurringTask r("背单词", 3);

    std::vector<Task*> tasks{&p, &r};
    print_all(tasks);
    for (Task* t : tasks) {
        t->run();
    }
}
```

<div class="out mt1">print: hello
recurring every 3 days
hello
run 背单词</div>

<div class="small mt1">
`print_all` 只依赖抽象接口；新增任务类型不需要修改它。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 常见陷阱

---

<div class="cols">

<div class="col">

**忘记多态条件**

- 基类函数没写 `virtual`
- 派生类签名不一致（漏 `const`）
- 按值传递 → 切片
- 容器存基类对象而不是指针

</div>

<div class="col">

**生命周期**

- 基类析构不是 `virtual`
- 在构造/析构中调用虚函数
- `delete` 通过基类指针删除派生对象
- `dynamic_cast` 用于非多态类型

</div>

</div>

<div class="pitfall">
<span class="label">检查清单</span>
① 基类析构是否 <code>virtual</code>？② 派生类是否写 <code>override</code>？③ 调用点是引用/指针吗？④ 对象由谁拥有、何时释放？
</div>

---


<!-- slide data-notes="" -->

##### 课堂小测

---

1. 动态绑定需要满足哪三个条件？按值传递为什么无法实现多态？

2. 重载、重写、隐藏有什么区别？`override` 关键字能帮你发现什么问题？

3. 为什么基类的析构函数通常要声明为 `virtual`？不声明会发生什么？

4. 抽象类与接口类有什么区别？`dynamic_cast` 失败时返回什么？

---


<!-- slide data-notes="" -->

##### 小结：面向接口，而不是面向实现

---

<div class="cols">

<div class="col">

<div class="card">

<div class="card-title">机制</div>

- `virtual` + 指针/引用 = 动态绑定
- 虚表实现运行时分派
- 虚析构保证正确释放

</div>

</div>

<div class="col">

<div class="card">

<div class="card-title">抽象</div>

- 纯虚函数定义接口
- 抽象类不能实例化
- 接口类只描述能力

</div>

</div>

<div class="col">

<div class="card">

<div class="card-title">设计</div>

- 高层代码依赖抽象
- 新增类型不改高层
- 少用 `dynamic_cast`，多用虚函数

</div>

</div>

</div>

<div class="motto mt1">
多态的本质不是“一个函数有多个版本”，而是<strong>让调用方只依赖稳定接口，把变化留给实现者</strong>。
</div>

---


<!-- slide data-notes="" -->

#####

---

<div class="bottom20"></div>

<hr class="width50 center">

## 未完待续

---
