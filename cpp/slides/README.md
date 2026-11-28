# 高级程序设计（C++）课件

南京大学计算机学院《高级程序设计（C++）》课程课件。以原课程 PPT 的知识体系为基础，按现代 C++（C++11/14/17/20）重新组织内容，并复用 `slides-cpl`（C 语言课程）的 reveal.js 框架、solarized 主题与版式。

- 授课对象：计算机学院大一本科生
- 教学安排：17 周 × 每周 2 学时，共 17 个教学单元
- 每份课件约 18–33 页，按一次课（2 学时）组织
- 全部页面按 1280×720 设计，已在无头 Chrome 下完成溢出检查

## 目录结构

```text
slides-cpp/
├── README.md                     # 本文件
├── build.sh                      # 一键构建全部课件
├── genhtml.py                    # Markdown -> HTML（复用并扩展 slides-cpl）
├── template.html                 # 生成用的 head/tail 模板（来自 slides-cpl 的成品 deck）
├── revealjs_deps/
│   └── notes.js                  # reveal.js 演讲者笔记插件
├── css/
│   └── cpp.css                   # C++ 课件专用样式（图示、代码尺寸、提示框）
├── tools/
│   ├── check_overflow.py         # 无头 Chrome 检查每页是否超出 1280×720
│   └── check_code.py             # 抽取完整代码块并用 g++ 做语法检查
├── 课程规划与案例设计.md          # 17 周规划、案例设计、现代特性分布
├── 内容迁移对照表.md              # 原 PPT -> 新课件的内容映射
├── 质量检查报告.md                # 构建、溢出、代码、内容检查结果
│
├── 01-course-and-oop/            # 第 1 周：课程概述与面向对象全景
├── 02-classes-and-objects/       # 第 2 周：类与对象
├── 03-construction-destruction/  # 第 3 周：构造与析构
├── 04-copy-assignment/           # 第 4 周：拷贝构造与赋值
├── 05-move-raii/                 # 第 5 周：移动语义与 RAII
├── 06-const-static-friend-module/# 第 6 周：const、static、友元、模块
├── 07-inheritance/               # 第 7 周：继承、多继承与组合
├── 08-polymorphism/              # 第 8 周：多态与动态绑定
├── 09-operator-overloading/      # 第 9 周：运算符重载
├── 10-io-streams/                # 第 10 周：输入输出流
├── 11-exceptions/                # 第 11 周：异常处理与健壮性
├── 12-templates/                 # 第 12 周：模板与泛型
├── 13-stl/                       # 第 13 周：STL
├── 14-memory-safety/             # 第 14 周：内存安全与智能指针
├── 15-concurrency/               # 第 15 周：并发与多线程
├── 16-declarative-event/         # 第 16 周：声明式与事件驱动
└── 17-project-review/            # 第 17 周：项目指导与总复习
```

每个教学单元目录包含：

```text
NN-topic/
├── N-1-topic.md      # Markdown 源文件（唯一需要编辑的源）
└── N-1-topic.html    # 生成的单文件 HTML（可直接双击打开）
```

HTML 已内联主题 CSS；reveal.js 与演讲者笔记脚本使用 `slides-cpp/js`、`slides-cpp/revealjs_deps` 下的本地文件，字体、插件等引用 `cpp/css`、`cpp/plugin` 下的共享资源。因此**不要单独拷贝 HTML 到其他目录**，否则相对路径会失效。

## 构建

环境要求：

- Python 3.8+
- 现代浏览器（Chrome / Edge / Safari / Firefox）
- 可选：`g++` 11+ 或 Clang 14+，用于编译课件中的示例代码
- 可选：无头 Chrome，用于自动溢出检查

构建全部课件：

```bash
cd slides-cpp
./build.sh
```

构建单份课件：

```bash
python3 genhtml.py 2-1-classes-and-objects 02-classes-and-objects
```

`genhtml.py` 会：

1. 以 `template.html` 为模板，保留 head/tail 与 16:9 设置；
2. 按 `<!-- slide data-notes="" -->` 切分页面；
3. 生成 C++ 语法高亮、表格、列表、行内代码、`==高亮==`、LaTeX；
4. 内联 `@import` 的本地 CSS；
5. 做列表配对、重复标题、残留 Markdown 自检。

生成后浏览器直接打开 `.html` 即可演示：`Space` 翻页，`Esc` 进入概览，`S` 打开演讲者笔记。

## 编写规范

### 页面

- 每页只讲一个核心问题；标题用“问题式/结论式”，避免“概述”“其他”这类空泛标题。
- 推荐节奏：问题 → 概念 → 原理 → 代码 → 执行过程 → 小结。
- 一页内容控制在 1280×720 内；新增页后必须运行溢出检查。
- 代码页优先“左代码、右要点”；两栏比例常用 `col-55` / `col-45`。
- 重要提示用 `.keypoint`（蓝）、`.tip`（绿）、`.pitfall`（红）、`.question`（黄）。
- 图示优先用 HTML/CSS 与内联 SVG，不依赖外部图片。

### Markdown 语法约定

- 每页用 `<!-- slide data-notes="" -->` 分隔，不能漏。
- 页面标题用 `##### 标题`，页内小节用 `**粗体**` 或 `####`。
- 代码块：

````markdown
```cpp{.line-numbers}
// 代码
```
````

- 代码块外层的字号控制：

```html
<div class="code-pane code-sm"> ... </div>
```

可用尺寸：`code-lg`、`code-md`、`code-sm`、`code-xs`、`code-xxs`。字号越小，单页可容纳行数越多；优先保证投影可读性，不要低于 `code-xs`。

- 标准标记：

```html
<span class="std cxx11">C++11</span>
```

可用：`cxx98`、`cxx11`、`cxx14`、`cxx17`、`cxx20`、`cxx23`。

- 行内高亮用 `==文字==`；行内代码用反引号；数学用 `$...$` / `$$...$$`。
- 表格用标准 Markdown；紧凑表格外层加 `<div class="xsmall-table">` 或 `<div class="small-table">`。

### 代码

- 默认按 C++17 编写；使用更高标准时在页面或代码块旁标注。
- 不写 `using namespace std;` 到头文件；示例中可有限使用。
- 动态资源优先 `std::unique_ptr` / 容器；需要演示裸指针问题时明确标注“反例”。
- 每个完整示例应能通过：

```bash
g++ -std=c++20 -Wall -Wextra -fsyntax-only example.cpp
```

- 故意展示编译错误的代码，应在页面文字中说明“错误示例”，不要把整段代码伪装成可运行程序。

## 质量检查

### 溢出检查

```bash
cd slides-cpp
python3 tools/check_overflow.py 02-classes-and-objects/2-1-classes-and-objects.html
```

输出 `overflow 0` 表示该 deck 每页的 `section.scrollHeight <= 720` 且代码块无横向溢出。需要本机安装 Chrome；如路径不同，修改脚本中的 `chrome` 变量。

批量检查：

```bash
for f in */*.html; do
  case "$f" in *template*) continue;; esac
  echo -n "$f: "
  python3 tools/check_overflow.py "$f" | head -1
done
```

### 代码检查

```bash
cd slides-cpp
python3 tools/check_code.py
```

脚本会抽取同时包含 `#include` 与 `int main` 的代码块，用 `g++ -std=c++20 -fsyntax-only` 检查。**注意**：部分页面为了讲解“类定义 / 使用”分两页，单独的 `main` 片段会缺少类型定义，这类片段不计为错误；完整示例见对应页面与 `code/` 目录（若存在）。

### 结构检查

`genhtml.py` 自带三项自检：列表配对、重复标题、残留 Markdown。输出 `issues: NONE` 即通过。

## 与 `slides-cpl` 的关系

| 项目 | 来源 | 说明 |
| :-- | :-- | :-- |
| `genhtml.py` | `slides-cpl/genhtml.py` | 扩展了 C++ 关键字、`::`、`->*` 等运算符高亮；模板查找改为 `slides-cpp/template.html` |
| `template.html` | `slides-cpl` 的成品 deck | 只取 head/tail；已把 `revealjs_deps/notes.js` 路径改为 `../revealjs_deps/notes.js` |
| `revealjs_deps/notes.js` | `slides-cpl` | 演讲者笔记插件 |
| CSS / 字体 / 插件 | `cpp/css`、`cpp/plugin` | 与 C 语言课程共用站点资源 |
| 视觉风格 | `slides-cpl` | solarized 浅色主题、标题/代码/两栏版式一致 |

`slides-cpl/` 与 `ppt/` 均为只读参考，不应在本课件构建中修改。

## 新增一份课件

1. 新建 `NN-topic/` 目录。
2. 复制任意 `.md` 的头部（front matter + `@import`），修改标题。
3. 按 `<!-- slide data-notes="" -->` 编写页面。
4. 运行 `python3 genhtml.py <name> <dir>` 生成 HTML。
5. 运行 `tools/check_overflow.py <dir>/<name>.html`，修复所有 `OVER` / `PRE`。
6. 运行 `tools/check_code.py`，确认新增完整示例可编译。
7. 更新 `课程规划与案例设计.md` 与 `内容迁移对照表.md`。

## 已知约束

- 页面固定 1280×720；信息密度高时优先拆页，不要靠无限缩小字号。
- `template.html` 约 1.8 MB，包含 reveal.js 与主题 CSS；请勿用浏览器“另存为”覆盖它。
- `genhtml.py` 的 `@import` 只内联不含 `url(` 的 CSS；带字体的 CSS 仍通过相对路径加载。
- 本课程不使用公式与 Mermaid，因此未引入相关 CDN；如需公式/图表，可按 `slides-cpl/genhtml.py` 的注入方式自行恢复。

## 站点首页

课程首页位于上一级目录：

- `../index.md`：首页的 Markdown 源（课程概况、17 周表格、教材）
- `../index.html`：首页的 HTML 版本

`index.html` 目前为手写页面（本机未配置 mpe2html）。修改 `index.md` 后，请同步更新 `index.html` 中对应的课程表格与链接。

首页链接指向 `slides-cpp/NN-topic/N-1-topic.html`；新增/重命名课件时，两处都要更新。
