#let student-name = "请填写姓名"
#let student-id   = "请填写学号"

#set page(paper: "a4", margin: 2.2cm)
#set text(size: 11pt, lang: "zh")
#set par(leading: 0.78em, justify: true)

#show raw.where(block: true): block.with(
  fill: luma(250),
  stroke: 0.5pt + luma(191),
  inset: 8pt,
  width: 100%,
)

#let problem(title, body) = {
  v(0.8em)
  block(breakable: false)[#text(size: 14pt, weight: "bold")[#title]]
  v(0.35em)
  body
  v(0.3em)
}

#let solution(ai, body) = {
  v(0.8em)
  block({
    [AI Usage: #ai]
    linebreak()
    [*Solution*]
  })
  v(0.35em)
  body
  v(0.3em)
}

#align(center)[
  #text(size: 17pt, weight: "bold")[平时作业 1]
  #v(0.6em)
  *姓名：*#student-name #h(2em) *学号：*#student-id
]
#v(0.4em)

=== 1. 提交规范
- 本次作业提供 `hw1.md`、`hw1.tex`、`hw1.typ` 三份内容相同的模版。请任选一种格式直接在各题的*作答区*内填写解答，并将修改后的*源文件*命名为 `姓名-学号.md`（或 `.tex` / `.typ`）提交至 #link("https://cslab-cms.nju.edu.cn/")[南京大学在线实验平台]，无需导出 PDF 或上传代码目录。
- *选做题说明*：标有 Optional 的题目为选做拓展题，不要求作答，且其中涉及的内容均为课堂未讲授的课外拓展知识，供学有余力的同学了解。
- *AI 使用标注*：作业中可能包含少量课上尚未展开的语法、工具细节或背景概念，遇到不熟悉的内容时，可以自行查阅资料或询问 AI 辅助理解。每道题均设有 *AI Usage* 栏，请如实填写是否使用了 AI；若使用了 AI，须具体写明用途。
- 如果提交格式不正确，或没有诚实填写 AI 使用说明，可能会影响分数。

=== 2. CMake 构建指南
开始编写代码前，请先确认本机已安装 C++ 编译器与 CMake：
- *Windows*：安装 Visual Studio / CLion（已内置编译器与 CMake），或通过 MSYS2 / MinGW-w64 安装 `g++` 与 `cmake`，或在 WSL 中通过 Linux 包管理器安装。
- *macOS*：终端执行 `xcode-select --install` 安装命令行工具，并通过 Homebrew（`brew install cmake`）或官网安装包安装 CMake。
- *Linux*：通过包管理器安装，例如 Debian 下执行 `sudo apt update && sudo apt install build-essential cmake`。

在终端进入 `attachments/` 目录后，使用以下三条标准命令完成配置、编译与测试：
```bash
cmake -B build                              # 在 build/ 目录生成构建配置（首次执行即可）
cmake --build build                         # 编译并链接生成可执行程序（每次改完代码后执行）
ctest --test-dir build --output-on-failure  # 运行全部测试；失败时会输出断言所在行号
```
若只想单独运行 Problem 2 或 Problem 4 的测试，可使用 `-R` 参数过滤测试名：
```bash
ctest --test-dir build -R p2 --output-on-failure
ctest --test-dir build -R p4 --output-on-failure
```

当然，你也可以在 IDE（如 VS Code）中直接使用 CMake 插件进行构建和测试。

#pagebreak()

#problem("Problem 1")[
  课上我们介绍了过程抽象与数据封装的区别，以及“类（Class）”与“对象（Object）”的基本概念。对尚未接触过 C++ 面向对象语法的同学，可以先了解以下三条基础规则：
  + *引用参数*：C++ 函数参数默认只传递副本；若在类型后加上 `&`（如 `int &v`），则形参 `v` 成为调用方实参的引用，在函数内修改 `v` 会直接修改外部实参。
  + *访问控制*：`class` 中位于 `public:` 下的成员可被外部代码直接调用或访问；位于 `private:` 下的成员仅允许本类的成员函数访问，外部直接访问会在编译阶段报错。
  + *构造函数与只读成员函数*：与类同名的成员函数为构造函数，在创建对象时自动执行以完成数据初始化；成员函数声明末尾的 `const` 表示该函数承诺不修改对象的任何成员变量。

  现在，请阅读下方程序：
  ```cpp
  #include <iostream>

  void reset(int v) {
      v = 0;
  }

  int main() {
      int x = 42;
      reset(x);
      std::cout << x << "\n";
      return 0;
  }
  ```

  请写出程序运行输出的结果；若希望调用 `reset(x)` 后 `x` 的值变为 `0`，应如何修改？

  #solution("未使用")[
  ]

  #pagebreak()

  下方 `BoundedCounter` 类希望封装一个计数值始终保持在 `[0, limit_]` 范围内的计数器：
  ```cpp
  class BoundedCounter {
    private:
      int count_;

    public:
      int limit_;

      // Constructor, initialize count_ to 0 and limit_ to the given limit
      BoundedCounter(int limit) : count_(0), limit_(limit) {}

      void increment() {
          if (count_ < limit_) {
              ++count_;
          }
      }

      int get() const {
          return count_;
      }
  };

  int main() {
      BoundedCounter c(5); // Create a BoundedCounter object with limit 5
      c.increment();
      c.count_ = 100;      // Statement 1
      c.limit_ = -3;       // Statement 2
      return 0;
  }
  ```

  `main` 函数中的 *Statement 1* 和 *Statement 2* 哪一句会导致编译报错？哪一句能通过编译但破坏了计数器的设计约束？应如何调整 `BoundedCounter` 的类定义以消除该隐患？

  #solution("未使用")[
  ]
]

#pagebreak()

#problem("Problem 2")[
  与栈的“后进先出（LIFO）”不同，队列遵循“先进先出（FIFO）”原则。若用普通数组实现队列并在每次出队时将后续元素整体前移，开销较大；工程上通常采用*循环数组*——当下标推进到数组末尾 `CAPACITY - 1` 后，下一个位置通过取模运算 `(index + 1) % CAPACITY` 折返至下标 `0`。

  附件 `attachments/queue.hpp` 定义了固定容量 `CAPACITY = 8` 的整型队列类 `Queue`，其私有成员在任意时刻均须满足以下条件：
  - `data_[CAPACITY]`：存放元素的底层定长数组，有效下标为 `0` 至 `CAPACITY - 1`。
  - `count_`：当前队列中的元素个数，始终满足 `0 <= count_ <= CAPACITY`。
  - `head_`：当队列非空时，`data_[head_]` 为最早入队的队头元素。
  - `tail_`：当队列未满时，`data_[tail_]` 为下一个新元素的写入槽位。

  `queue.cpp` 中已给出构造函数以及 `empty()`、`full()`、`size()` 的实现。请按以下实现细节补全剩余三个成员函数，并粘贴在此处：
  - `bool push(int x)`：
    + 若队列已满（`full()` 为 `true`），不修改队列状态，直接返回 `false`；
    + 将 `x` 存入 `data_[tail_]`；
    + 更新 `tail_` 和 `count_`，返回 `true`。
  - `bool pop(int &out)`：
    + 若队列为空（`empty()` 为 `true`），不修改 `out`，直接返回 `false`；
    + 将队头元素 `data_[head_]` 赋值给引用参数 `out`；
    + 更新 `head_` 和 `count_`，返回 `true`。
  - `bool front(int &out) const`：
    + 若队列为空，不修改 `out`，直接返回 `false`；
    + 将 `data_[head_]` 赋值给 `out` 并返回 `true`。

  #solution("未使用")[
  ]

  #pagebreak()

  在循环数组中，队列为空和队列装满时都会出现 `head_ == tail_`。本类的实现是如何区分这两种状态的？如果去掉成员变量 `count_`，仅保留 `head_`、`tail_` 和长度为 `CAPACITY` 的数组，还能否区分空与满？如果能，请给出如何实现；如果不能，请说明理由。

  #solution("未使用")[
  ]
]

#pagebreak()

#problem("Problem 3")[
  假设在 Problem 2 中，类的设计者图方便将 `data_`、`head_`、`tail_` 全部放在 `public:` 下，而某段外部代码直接编写了遍历 `q.data_` 下标的循环来打印队列元素。当后续我们需要将 `Queue` 的内部存储改为单链表时，这会对外部代码造成什么影响？若外部确实需要“按序查看队列中所有元素”，符合数据封装原则的设计方式是什么？

  #solution("未使用")[
  ]
]

#pagebreak()

#problem("Problem 4 (Optional)")[
  在设计诸如“弹出并返回队头元素”的接口时，函数需要同时表达两种可能的结果：*成功取得一个元素*，或*因队列为空而无值可返*。传统写法通常有三种方案，但各有明显局限：
  - *内部终止或抛异常*：如空队列直接 `exit(-1)`，这可能会导致程序异常终止；
  - *返回特殊哨兵值*：例如定义 `int pop()` 并在队列为空时返回 `-1`。这会造成*值域冲突*——数据本身可能包含 `-1`；
  - *布尔返回值配合引用输出参数*：即 Problem 2 采用的 `bool pop(int &out)`。它消除了值域冲突，但调用方每次都必须先在外部声明一个占位变量，不仅代码略显繁琐，而且可能造成变量作用域泄露。当元素类型没有默认构造函数时，甚至无法轻易声明占位变量。

  为了在类型层面干净地解决这一问题，现代编程语言普遍引入了*可选值类型*。C++17 也在标准库头文件 `<optional>` 中引入了类模板 `std::optional<T>`：一个 `std::optional<int>` 对象在语义上要么含有一个合法的 `int` 值，要么处于显式的无值状态 `std::nullopt`。其核心用法如下：
  ```cpp
  #include <optional>

  std::optional<int> make_sample(bool ok) {
      if (!ok) {
          return std::nullopt;   // 显式返回“无值”状态
      }
      return -1;                 // 自动包装为“有值”的 optional，其值为 -1
  }

  void demo() {
      // 写法 A：利用 if 初始化语句将变量 s 的作用域严格限制在分支内部
      if (std::optional<int> s = make_sample(true)) {
          int val = *s;           // 通过 *s 或 s.value() 取出内部包含的整数
      }

      // 写法 B：显式查询是否有值
      auto empty_res = make_sample(false);
      bool has = empty_res.has_value(); // 返回 false
  }
  ```

  请打开 `attachments/queue.cpp`，补全成员函数 `Queue::try_pop` 并粘贴在此处。

  #solution("未使用")[
  ]

  #pagebreak()

  查阅 #link("https://cppreference.com/")[C++ 标准库文档]或编写几行测试验证：当 `std::optional<int> opt = std::nullopt;` 处于无值状态时，若未判空便直接调用 `opt.value()`，程序会发生什么行为？这与直接解引用 `*opt` 有何不同？

  #solution("未使用")[
  ]
]
