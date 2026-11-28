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

## 输入输出流：从控制台到文件

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](mailto:yangyibiao@nju.edu.cn)


<!-- slide data-notes="" -->

##### 本讲提纲

---

<div class="cols">

<div class="col">

**控制台与字符串**

- 流模型与 `iostream`
- 格式化输出
- `>>` 与 `getline`
- `stringstream`

</div>

<div class="col">

**文件与自定义类型**

- 文件流与打开模式
- 文本 vs 二进制
- 流状态与错误处理
- 重载 `<<` / `>>`

</div>

</div>

<div class="keypoint">
<span class="label">本讲目标</span>
能够安全地读写文本文件，并为自定义类型提供一致的输入输出接口。
</div>

---


<!-- slide data-notes="" -->

##### 流：把 I/O 看成字节的流动

---

<div class="cols">

<div class="col">

**输入流**

数据从外部（键盘、文件、字符串）流向程序：

```
键盘/文件 → 缓冲区 → 程序变量
```

**输出流**

数据从程序流向外部：

```
程序变量 → 缓冲区 → 屏幕/文件
```

</div>

<div class="col">

<div class="card">

<div class="card-title">流对象的三件事</div>

1. 方向：输入 / 输出
2. 来源/目标：控制台、文件、字符串
3. 状态：成功、失败、文件尾

</div>

<div class="tip">
<span class="label">统一抽象</span>
无论是键盘、文件还是字符串，读写方式都是一样的：用 <code>&lt;&lt;</code> / <code>&gt;&gt;</code> 或成员函数。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### `iostream` 的类层次

---

<div class="cols">

<div class="col-55">

<div class="fig">
<svg viewBox="0 0 460 210" width="560">
  <rect x="160" y="10" width="140" height="40" rx="6" fill="#fdf6e3" stroke="#586e75"/>
  <text x="230" y="35" font-size="14" text-anchor="middle" fill="#586e75">ios_base</text>
  <rect x="80" y="80" width="130" height="38" rx="6" fill="#fdf6e3" stroke="#268bd2"/>
  <text x="145" y="104" font-size="14" text-anchor="middle" fill="#268bd2">istream</text>
  <rect x="250" y="80" width="130" height="38" rx="6" fill="#fdf6e3" stroke="#859900"/>
  <text x="315" y="104" font-size="14" text-anchor="middle" fill="#859900">ostream</text>
  <rect x="165" y="155" width="130" height="38" rx="6" fill="#fdf6e3" stroke="#b58900"/>
  <text x="230" y="179" font-size="14" text-anchor="middle" fill="#b58900">iostream</text>
  <line x1="210" y1="50" x2="145" y2="80" stroke="#93a1a1"/>
  <line x1="250" y1="50" x2="315" y2="80" stroke="#93a1a1"/>
  <line x1="145" y1="118" x2="200" y2="155" stroke="#93a1a1"/>
  <line x1="315" y1="118" x2="260" y2="155" stroke="#93a1a1"/>
</svg>
</div>

</div>

<div class="col-45">

<div class="card">

<div class="card-title">常用对象</div>

- `std::cin`：标准输入（键盘）
- `std::cout`：标准输出（屏幕，带缓冲）
- `std::cerr`：标准错误（不带缓冲）
- `std::clog`：标准日志（带缓冲）

</div>

<div class="small muted mt1">
文件流继承自同样的基类：<code>ifstream</code> / <code>ofstream</code> / <code>fstream</code>；字符串流是 <code>istringstream</code> / <code>ostringstream</code>。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 格式化输出

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
#include <iostream>
#include <iomanip>

double pi = 3.1415926;
int id = 42;

std::cout << std::fixed << std::setprecision(2)
          << pi << "\n";              // 3.14

std::cout << std::setw(6) << id << "\n";    // "    42"
std::cout << std::left << std::setw(6) << id
          << "|\n";                   // "42    |"

std::cout << std::hex << 255 << "\n";       // ff
std::cout << std::setfill('0')
          << std::setw(4) << 7 << "\n";     // 0007
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">常用操纵符</div>

- `std::fixed` / `std::scientific`
- `std::setprecision(n)`
- `std::setw(n)`（只影响下一次输出）
- `std::left` / `std::right`
- `std::setfill(c)`
- `std::hex` / `std::dec` / `std::oct`
- `std::boolalpha`

</div>

<div class="pitfall">
<span class="label">状态会保留</span>
<code>std::fixed</code>、<code>std::hex</code> 等会改变流的长期状态；<code>setw</code> 只影响下一次输出。需要时记得恢复。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### `>>` 与 `getline`：换行符的陷阱

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
int id;
std::string title;

std::cout << "id: ";
std::cin >> id;                 // 读取 42，留下 '\n'

std::cout << "title: ";
std::getline(std::cin, title);  // 读到空串！
```

修正：

```cpp
std::cin >> id;
std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                '\n');
std::getline(std::cin, title);
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">`>>` 的行为</div>

- 跳过前导空白（空格、`\t`、`\n`）
- 读到空白或类型不匹配为止
- 不读取分隔符本身

</div>

<div class="card mt1">

<div class="card-title">`getline` 的行为</div>

- 读取整行，包含空格
- 丢弃行尾 `\n`
- 遇到流结束或失败时停止

</div>

</div>

</div>

<div class="pitfall">
<span class="label">规则</span>
在 <code>&gt;&gt;</code> 之后使用 <code>getline</code>，先清掉残留的换行符；或者统一用 <code>getline</code> + <code>stringstream</code> 解析。
</div>

---


<!-- slide data-notes="" -->

##### `stringstream`：在字符串上读写

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
#include <sstream>
#include <string>

int id = 42;
std::string title = "写作业";

std::ostringstream oss;
oss << id << "," << title << ",2";
std::string line = oss.str();   // "42,写作业,2"

std::istringstream iss(line);
std::string token;
while (std::getline(iss, token, ',')) {
    std::cout << "[" << token << "]";
}
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">用途</div>

- 把多个值拼成一行
- 解析一行中的多个字段
- 做类型转换（`std::stoi` 的替代）
- 单元测试中构造输入

</div>

<div class="tip">
<span class="label">CSV 注意</span>
如果字段本身可能包含逗号或换行，需要转义或使用专门的 CSV 库；教学项目可先约定“标题不含逗号”。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 文件流：打开、读写、关闭

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
#include <fstream>

std::ofstream out("tasks.txt");       // 默认 ios::out
if (!out) {
    std::cerr << "cannot open file\n";
    return 1;
}
out << "1 写作业 2\n";
out << "2 复习 4\n";
out.close();

std::ifstream in("tasks.txt");
if (!in) { /* ... */ }

int id, priority;
std::string title;
while (in >> id >> title >> priority) {
    std::cout << id << " " << title << "\n";
}
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">打开模式</div>

- `std::ios::in`：读
- `std::ios::out`：写（清空/创建）
- `std::ios::app`：追加
- `std::ios::binary`：二进制
- 组合：`in | binary`

</div>

<div class="pitfall">
<span class="label">必须检查</span>
文件可能不存在、无权限、磁盘已满。打开后立即检查 <code>if (!in)</code>，不要假设一定成功。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 文本 vs 二进制

---

<div class="cols">

<div class="col">

**文本方式**

```cpp
out << 1234567;   // 7 个字符
```

- 人可读
- 跨平台较好（注意换行符）
- 需要解析
- 浮点数精度/格式可能丢失

</div>

<div class="col">

**二进制方式**

```cpp
int x = 1234567;
out.write(reinterpret_cast<const char*>(&x),
          sizeof(x));
```

- 紧凑、读写快
- 与内存布局绑定
- 受字节序、类型大小、对齐影响
- 跨平台/跨编译器不稳定

</div>

</div>

<div class="keypoint">
<span class="label">选择</span>
配置文件、日志、交换格式优先文本；性能敏感且两端环境一致的内部数据才考虑二进制。
</div>

<div class="small muted center">
以文本方式写出的文件要以文本方式读入；以二进制方式写出的文件要以二进制方式读入。
</div>

---


<!-- slide data-notes="" -->

##### 流状态：判断读写是否成功

---

<div class="xsmall-table">

| 状态 | 含义 | 检查方式 |
| :-- | :-- | :-- |
| good | 一切正常 | `if (in)` |
| fail | 类型不匹配/格式错误 | `in.fail()` |
| eof | 到达文件尾 | `in.eof()` |
| bad | 严重错误（如磁盘故障） | `in.bad()` |

</div>

<div class="cols mt1">

<div class="col">

```cpp
int x;
while (in >> x) {
    // 读取成功才进入循环
}
if (in.eof()) {
    std::cout << "done\n";
} else if (in.fail()) {
    std::cout << "format error\n";
}
```

</div>

<div class="col">

<div class="pitfall">
<span class="label">经典错误</span>
<code>while (!in.eof()) { in &gt;&gt; x; ... }</code>：文件尾时仍会多执行一次循环，最后一条数据被重复处理。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 为 `Task` 重载 `<<` 与 `>>`

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
std::ostream& operator<<(std::ostream& os, const Task& t) {
    return os << t.id() << ' '
              << t.title() << ' '
              << t.priority();
}

std::istream& operator>>(std::istream& is, Task& t) {
    int id, priority;
    std::string title;
    if (is >> id >> title >> priority) {
        t = Task(id, title, priority);
    }
    return is;
}
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">约定</div>

- 返回流引用，支持链式
- 输入失败时不修改对象，或保持对象有效
- 格式与 `operator<<` 对应
- 标题含空格时改用 `getline` + 分隔符

</div>

<div class="pitfall">
<span class="label">注意</span>
<code>&gt;&gt;</code> 读取 <code>title</code> 时遇到空格就停；如果标题是 <code>"write report"</code>，只会读到 <code>"write"</code>。需要整行读取时用 <code>getline</code>。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 主线案例：`TaskRepository` 的保存与加载

---

<div class="cols">

<div class="col-55 code-sm">

```cpp
class TaskRepository {
public:
    explicit TaskRepository(std::string path)
        : path_(std::move(path)) {}

    bool save(const std::vector<Task>& tasks) const {
        std::ofstream out(path_);
        if (!out) return false;
        for (const Task& t : tasks) {
            out << t << '\n';
        }
        return static_cast<bool>(out);
    }

    std::vector<Task> load() const {
        std::vector<Task> tasks;
        std::ifstream in(path_);
        if (!in) return tasks;
        Task t(0, "", 0);
        while (in >> t) tasks.push_back(t);
        return tasks;
    }
private:
    std::string path_;
};
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">设计点</div>

- 构造时只保存路径，不立即打开文件
- `save` 返回 `bool`，调用方决定如何处理失败
- `load` 遇到文件不存在返回空列表
- 格式与 `operator<<` / `>>` 一致

</div>

<div class="tip">
<span class="label">异常 vs 返回码</span>
这里用返回值表示 I/O 失败；也可以抛异常。两种方式都合理，关键是<strong>在整个项目中保持一致</strong>。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 课堂任务 10：任务文件读写

---

<div class="cols">

<div class="col-55">

<div class="card">

<div class="card-title">任务</div>

实现 `save_tasks` 与 `load_tasks`：

- 文件格式：每行 `id|title|priority`
- 标题可以包含空格
- 保存时检查文件是否成功打开
- 加载时跳过空行与格式错误的行
- 返回加载到的任务数量

在 `main` 中保存 3 个任务，再加载并打印。

</div>

</div>

<div class="col-45">

<div class="card">

<div class="card-title">验收标准</div>

- 标题含空格也能正确保存/加载
- 文件不存在时不会崩溃
- 格式错误行被跳过，不进入死循环
- 保存后立即读取，内容一致
- 使用 `std::getline` + `std::stringstream`

</div>

<div class="tip">
<span class="label">提示</span>
用 <code>getline(in, line)</code> 读整行，再用 <code>stringstream</code> 按 <code>|</code> 切分；不要用 <code>&gt;&gt;</code> 直接读标题。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 任务 10 参考实现

---

<div class="cols">

<div class="col-55 code-xs">

```cpp{.line-numbers}
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
bool save_tasks(const std::string& path,
                const std::vector<Task>& tasks) {
    std::ofstream out(path);
    if (!out) return false;
    for (const Task& t : tasks) {
        out << t.id() << '|' << t.title()
            << '|' << t.priority() << '\n';
    }
    return static_cast<bool>(out);
}

std::vector<Task> load_tasks(const std::string& path) {
    std::vector<Task> tasks;
    std::ifstream in(path);
    if (!in) return tasks;

    std::string line;
    while (std::getline(in, line)) {
        if (line.empty()) continue;
        std::istringstream iss(line);
        std::string id_s, title, prio_s;
        if (!std::getline(iss, id_s, '|')) continue;
        if (!std::getline(iss, title, '|')) continue;
        if (!std::getline(iss, prio_s, '|')) continue;
        try {
            int id = std::stoi(id_s);
            int p = std::stoi(prio_s);
            tasks.emplace_back(id, title, p);
        } catch (const std::exception&) {
            // 跳过格式错误的行
        }
    }
    return tasks;
}
```

</div>

<div class="col-45">

<div class="card">

<div class="card-title">要点</div>

- `getline(in, line)` 读整行
- `stringstream` 按 `|` 切分
- `stoi` 转换，失败抛异常
- `try/catch` 跳过坏行
- 返回 `vector<Task>`，由调用方决定后续

</div>

<div class="small muted mt1">
更严格的实现会记录错误行号，或返回 <code>expected&lt;vector&lt;Task&gt;, Error&gt;</code>；异常处理单元会讨论。
</div>

</div>

</div>

---


<!-- slide data-notes="" -->

##### 常见陷阱

---

<div class="cols">

<div class="col">

**输入**

- `>>` 后直接 `getline`，读到空串
- 用 `while (!eof())` 导致重复处理最后一条
- 不检查 `cin` 失败，变量保持旧值
- 标题含空格却用 `>>` 读取

</div>

<div class="col">

**文件/输出**

- 不检查文件是否成功打开
- 文本写出、二进制读入
- 忘记 `close`（析构通常会自动关闭，但错误检查会丢失）
- 格式状态（`hex`、`fixed`）污染后续输出
- 二进制直接写结构体，跨平台不可读

</div>

</div>

<div class="pitfall">
<span class="label">原则</span>
每次 I/O 后都问一句：“如果失败，程序会怎样？” 文件不存在、格式错误、磁盘满，都是正常世界的一部分。
</div>

---


<!-- slide data-notes="" -->

##### 课堂小测

---

1. `std::cin >> x` 与 `std::getline(std::cin, s)` 在处理空白字符上有什么不同？

2. 为什么 `while (!in.eof()) { in >> x; ... }` 可能重复处理最后一条数据？

3. 文本方式与二进制方式存储整数 `1234567` 各占多少字节？各有什么优缺点？

4. 为自定义类型重载 `>>` 时，如果读取失败，对象应该处于什么状态？

---


<!-- slide data-notes="" -->

##### 小结：I/O 是程序的边界

---

<div class="cols">

<div class="col">

<div class="card">

<div class="card-title">控制台</div>

- `cin` / `cout` / `cerr`
- 格式化操纵符
- `>>` 与 `getline` 的边界

</div>

</div>

<div class="col">

<div class="card">

<div class="card-title">文件</div>

- `ifstream` / `ofstream`
- 打开模式与状态检查
- 文本优先，二进制慎用

</div>

</div>

<div class="col">

<div class="card">

<div class="card-title">自定义类型</div>

- `operator<<` / `>>` 保持格式对称
- 输入失败不破坏对象
- 用 `stringstream` 解析复杂行

</div>

</div>

</div>

<div class="motto mt1">
I/O 代码必须假设“外部世界会出错”：文件可能不存在，输入可能格式不对。<strong>检查返回值，是所有 I/O 的第一原则。</strong>
</div>

---


<!-- slide data-notes="" -->

#####

---

<div class="bottom20"></div>

<hr class="width50 center">

## 未完待续

---
