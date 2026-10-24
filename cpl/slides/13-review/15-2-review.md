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

## 总复习

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](mailto:yangyibiao@nju.edu.cn)



<!-- slide data-notes="" -->

##### 提纲

---

- 全学期知识地图

- 重点与易错点串讲

- 考试形式与评分

- 模拟练习

---


<!-- slide data-notes="" -->


##### 全学期知识地图

---

还记得第 1 周的「程序需要什么」吗? 一学期下来, 它们都补齐了:

<div class="fullborder">

| 需求 | 元素 | 什么时候学的 |
| :-- | :-- | :-- |
| 记住数据 | 变量、类型 | 第 2 周 |
| 计算 | 表达式、运算符 | 第 3 周 |
| 不同情况 | 判断 if / switch | 第 4 周 |
| 重复 | 循环 while / for | 第 5 周 |
| 一批数据 | 数组、排序与查找 | 第 6-7 周 |
| 复用与分解 | 函数、递归 | 第 8-9 周 |
| 内存与地址 | 指针 | 第 10-11 周 |
| 字符串 | 字符串处理、函数指针 | 第 12 周 |
| 复杂数据组织 | 结构体、链表 | 第 13 周 |
| 长期保存 | 文件、多文件 | 第 14 周 |
| 综合应用 | 期末项目 | 第 15 周 + 考试周答辩 |

</div>

---


<!-- slide data-notes="" -->


##### 易错点串讲 (1): 类型与运算

---

- ==整数除法==: `7 / 2` = ==3== 不是 3.5; `7.0 / 2` 才是 3.5

- ==溢出不报错==: `INT_MAX + 1` 会"绕回"成负数

- ==类型转换==: `double` 赋给 `int` 会截断 (3.9 → 3); `(double) a / b` 才能保住小数

- ==自增优先级==: `*p++` 是 `*(p++)`; `++i + j++` 这种表达式==不要写==

- ==浮点比较==: `a == 0.1` 往往不成立, 用 `fabs(a - 0.1) < 1e-9`

---


<!-- slide data-notes="" -->


##### 易错点串讲 (2): 控制与函数

---

- `if (a = 1)` 是==赋值==不是比较——要写 `==`; 编译器可能只给个警告

- `switch` 漏写 `break` 会"穿透"到下一个 case

- 循环三要素: ==初值、条件、更新==——少一个就是死循环或无循环

- 数组下标从 ==0== 开始, `a[n]` 是第 n+1 个 (越界了!)

- 函数==值传递==: 想改实参必须传==指针== (`swap(int *, int *)`)

- 递归两要素: ==基准情形== + 每次调用规模变小

---


<!-- slide data-notes="" -->


##### 易错点串讲 (3): 指针与内存

---

- 指针 = ==地址==; `&` 取地址, `*` 解引用, 两者互逆

- `a[i]` ==等价于== `*(a + i)`; 数组名就是首元素地址

- 指针算术按==元素==走: `p + 1` 地址加 `sizeof(*p)` 字节

- 野指针: 未初始化的指针==不能解引用==; `free` 之后要把指针置 NULL

- `malloc` 必须配 `free`; 忘了 free 就是==内存泄漏==

- 字符串: `strcpy` / `strcat` ==不检查长度==, 目标数组要够大; 比较用 `strcmp` 不是 `==`

---


<!-- slide data-notes="" -->


##### 易错点串讲 (4): 文件与结构体

---

- 结构体可以==整体赋值== (`p1 = p2`), 但==不能用判等运算符比较== (`p1 == p2` 不合法)

- 结构体指针用 ==`->`== 访问成员: `p->x` 等价于 `(*p).x`

- 文件: `fopen` 后必须检查返回值是否为 `NULL`; 用完 `fclose`

- `fgetc` / `fgets` 返回 `int`, 判断文件结束用返回值而不是 `feof`

- 多文件: 函数原型和类型定义放 ==.h==, 实现放 ==.c==, 头文件加保护宏

---


<!-- slide data-notes="" -->


##### 考试形式与评分

---

==闭卷机试== (占总评 60%)

- 形式: 在线、限时、闭卷, 现场写程序并提交评测

- 考核内容: 语法基础 + 算法设计 + 智能应用

- 评分维度: ==代码正确性==、==时间复杂度==、==内存效率==

<span class="blue">:fa-lightbulb-o:</span> 备考建议:

- 每周 OJ 的题过一遍, 尤其是做错过的

- 手写几个"经典小程序": 排序、查找、字符串处理、链表插入删除

- 牢记本页的==易错点清单==——机试最常见的失分点

---


<!-- slide data-notes="" -->


##### 模拟练习

---

==课堂限时练习== (10 分钟, 选做 1-2 题):

1. 输入一行字符串, 统计其中大写字母、小写字母、数字、其他字符的个数

2. 输入 n 个整数存入数组, 用指针实现: 输出最大值及其下标

3. 定义一个结构体 `Student {char name[20]; int score;}`。输入 5 个学生, 按成绩从高到低排序输出

提示: 每题先想==输入 → 处理 → 输出==, 再想需要哪些==循环/判断/数组==

---


<!-- slide data-notes="" -->

##### 一学期的旅程

---

从第一个 Hello World 到今天的项目:

```text
第1周  Hello World / 猜数字        →  让程序跑起来
第2周  变量、类型、输入输出        →  数据进得来、出得去
第3周  表达式与运算                →  算得对
第4-5周 判断与循环                 →  程序会"思考"和"重复"
第6-7周 数组、排序与查找           →  处理批量数据
第8-9周 函数与递归                 →  会分解、会复用
第10-11周 指针与内存               →  触及内存
第12周 字符串与函数指针            →  字符串处理进阶
第13周 结构体与链表                →  组织复杂数据
第14周 文件与多文件                →  数据能保存、代码能分工
第15周 项目与总复习                →  把一切拼起来做一个"聪明"的程序
```

<span class="blue">:fa-lightbulb-o:</span> 这门课学的不是"背语法", 而是==用计算思维解决问题==的能力——它会陪你走很远

---


<!-- slide data-notes="" -->


##### 课程结语

---

==做中学==

- 每一个知识点都走过: 为什么需要 → 是什么 → 怎么用

- OJ 上的每一道题、项目里的每一行代码, 都是你自己的积累

==接着走==

- 想深入 C: 读 K.N. King《C程序设计语言: 现代方法》, 或做更复杂的系统编程

- 想转向应用: Python / C++ / Rust——你在 C 里学的内存、指针、数据结构, 全都用得上

- 想继续 AI: 你会发现框架的每一层都还能看到这几周写过的影子

<span class="blue">:fa-lightbulb-o:</span> 感谢一学期的陪伴, 祝大家在后面的学习和项目里一切顺利!

---


<!-- slide data-notes="" -->

#####

---

<div class="bottom20"></div>

# 考试周见!

<hr class="width50 center">

## 项目答辩 + 闭卷机试

---


