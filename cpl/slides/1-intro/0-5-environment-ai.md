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
@import "../../plugin/zoom/zoom.js"
@import "../../plugin/customcontrols/plugin.js"
@import "../../plugin/customcontrols/style.css"
@import "../../plugin/chalkboard/plugin.js"
@import "../../plugin/chalkboard/style.css"
@import "../../plugin/menu/menu.js"
@import "../../js/anychart/anychart-core.min.js"
@import "../../js/anychart/anychart-venn.min.js"
@import "../../js/anychart/pastel.min.js"
@import "../../js/anychart/venn-ml.js"


<!-- slide data-notes="" -->

<div class="bottom20"></div>

# 智能程序设计（C语言）

<hr class="width50 center">

## 上手: 开发环境与 AI 工具

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](mailto:yangyibiao@nju.edu.cn)

---

<!-- slide data-notes="" -->##### 提纲

---

- 开发环境: 编辑 → 编译 → 运行 → 调试

- 工具选择与安装 (CLion / VS Code / 命令行 gcc)

- 跑通第一个程序, 学会调试

- 常见环境问题与解法

- AI 辅助编程: 能做什么、不能做什么

- 上机清单

---


<!-- slide data-notes="" -->##### 开发环境 = 四件事

---

<div style="font-size:0.95em;line-height:1.6;">

==开发环境==: 把"写代码"变成"能运行、能排错"的一整套工具

<div style="display:flex;align-items:center;justify-content:center;gap:10px;font-size:0.95em;text-align:center;margin:14px 0;">
<div style="border:2px solid var(--solarized-blue);border-radius:8px;padding:10px 16px;">编辑<br>写 .c 文件</div>
<span class="blue" style="font-size:1.5em;">→</span>
<div style="border:2px solid var(--solarized-yellow);border-radius:8px;padding:10px 16px;">编译<br>gcc 把 C 变成可执行文件</div>
<span class="blue" style="font-size:1.5em;">→</span>
<div style="border:2px solid var(--solarized-green);border-radius:8px;padding:10px 16px;">运行<br>看输出对不对</div>
<span class="blue" style="font-size:1.5em;">→</span>
<div style="border:2px solid var(--solarized-red);border-radius:8px;padding:10px 16px;">调试<br>定位错误</div>
</div>

- ==集成开发环境 (IDE)== 把这四步放进一个窗口: 编辑器 + 编译器 + 运行按钮 + 调试器

- 命令行也能完成 (gcc + 终端), 但 ==IDE 更适合入门==——错误信息、断点、变量观察都在一处

</div>

---

<!-- slide data-notes="" -->##### 工具选择

---

<div style="font-size:0.95em;line-height:1.6;">

==推荐: CLion== (JetBrains)

- 学生邮箱可注册==免费 License==; 或使用校内激活服务器: `http://210.28.133.13:22737` (==仅校内网络==可用)

- 自带 C/C++ 编译与调试, 开箱即用

==备选: VS Code== (免费)

- 轻量编辑器 + ==C/C++ 插件== + 外部编译器; 配置多一些, 但生态最广

==兜底: 命令行==

- `gcc hello.c -o hello` 编译, `./hello` 运行——任何环境都能用, 也是理解编译流程的最好方式

<span class="blue">:fa-lightbulb-o:</span> 工具只选==一个==, 用熟比换来换去更重要

</div>

---

<!-- slide data-notes="" -->##### 安装与配置清单

---

<div style="font-size:0.95em;line-height:1.7;">

1. 安装 ==CLion== (推荐) 或 VS Code + C/C++ 插件

2. 确认==编译器==可用: 终端执行 `gcc --version`, 能看到版本号

3. 新建工程/文件, 保存为 `hello.c`

4. ==编译并运行==: IDE 里点运行按钮; 命令行 `gcc hello.c -o hello && ./hello`

5. 看到 `Hello, NJU!` —— ==环境就绪==

- 校内网络访问 CLion 激活服务器; 校外需学生 License 或校园 VPN

- macOS 若提示缺少编译工具: `xcode-select --install`

</div>

---

<!-- slide data-notes="" -->##### 跑通第一个程序

---

<div style="display:flex;align-items:flex-start;gap:24px;font-size:0.85em;">

<div style="flex:1.05;">

```C{.line-numbers}
#include <stdio.h>

int main(void)
{
  printf("Hello, NJU!\n");
  return 0;
}
```

</div>

<div style="flex:1;line-height:1.7;">

- 编辑: 把代码存成 `hello.c` (==扩展名必须是 .c==)

- 编译: `gcc hello.c -o hello` —— 没报错才会生成可执行文件

- 运行: `./hello` (Windows 下 `hello.exe`)

- IDE 里: 点 ==▶ 运行== 一步完成; 出错时先看==第一条错误==, 从它开始改

</div>

</div>

---

<!-- slide data-notes="" -->##### 调试入门: 断点与单步

---

<div style="font-size:0.95em;line-height:1.7;">

==调试==: 让程序在指定位置==停下来==, 看当时的变量值

1. 在行号旁点一下, 设==断点== (红点)

2. 以 ==Debug 模式== 运行, 程序停在断点处

3. ==单步执行== (Step Over / Step Into), 一行一行往下走

4. 在变量窗口观察值的变化——==和你想的不一样的地方, 就是 bug 藏身处==

<span class="blue">:fa-lightbulb-o:</span> 新手最常用的两招: `printf` 打印中间值 + 断点单步; 先会用, 再谈技巧

</div>

---

<!-- slide data-notes="" -->##### 常见环境问题

---

<div class="fullborder">

| 现象 | 常见原因 | 解决 |
| :-- | :-- | :-- |
| `gcc: command not found` | 没装编译器 / PATH 未配置 | 安装编译器, 或重启终端 |
| 中文显示乱码 | 终端/文件编码不一致 (GBK vs UTF-8) | 统一为 ==UTF-8== |
| 编译报错一堆 | 缺 `#include`、少了分号、拼写错误 | 看==第一条==错误, 逐个消灭 |
| 程序一闪而过 | 双击运行, 窗口自动关闭 | 在 IDE/终端里运行, 或末尾加 `getchar()` |
| 路径含中文/空格 | 编译器找不到文件 | 工程放在==纯英文无空格==路径下 |

</div>

---

<!-- slide data-notes="" -->##### AI 辅助编程工具

---

<div style="font-size:0.95em;line-height:1.7;">

==常见工具==: GitHub Copilot、Cursor; DeepSeek、ChatGPT、Claude、Gemini

==可以帮你==:

- ==概念理解==: 让 AI 解释一段代码、解释报错信息

- ==练习==: 让 AI 出题、改题、给测试数据

- ==审查==: 让 AI 指出潜在问题, 再自己验证

<span class="blue">:fa-lightbulb-o:</span> 关键不是"能不能用", 而是==用完你是否真的会了==

</div>

---

<!-- slide data-notes="" -->##### AI 使用规范

---

<div style="font-size:0.95em;line-height:1.7;">

==三条规则==:

1. ==先自己写, 再让 AI 改==——依赖 AI 的学生学不会编程

2. ==AI 是副驾驶, 方向盘在自己手里==: AI 给的每一行, 你都要能解释

3. 要求==独立完成==的作业, 不用 AI 代写; 用了 AI 的部分, 按课程要求注明

- 老师会当面问"这段为什么这么写"——==答不上来, 就等于没写==

</div>

---

<!-- slide data-notes="" -->##### 上机清单

---

<div style="font-size:0.95em;line-height:1.7;">

==本周完成==:

1. 装好 ==CLion / VS Code==, `gcc --version` 能看到版本号

2. 跑通 `hello.c`, 并会用==断点单步==调试

3. 注册 ==OJ== 账号 (学号), 完成第一道题

4. 遇到环境问题: 先查本页"常见环境问题", 再问助教

<span class="blue">:fa-lightbulb-o:</span> 环境问题是==一次性成本==——今天花 30 分钟装好, 后面一学期都省心

</div>

---

<!-- slide data-notes="" -->

#####

---

<div class="bottom20"></div>

<hr class="width50 center">

## 未完待续

---
