@import "css/theme/solarized.css"
@import "css/index.css"

## 智能程序设计（C语言）<span style="font-weight:900">2026</span> 秋

---

#### 概况

授课：杨已彪 _yangyibiao@nju.edu.cn_

- **2026学年：60 学时理论，第 1 ~ 15 周，每周两次（周二、周三各 2 节，每节 50 分钟）**
- **放假调休：中秋 9/25 ~ 9/27；国庆 10/1 ~ 10/7；9/20（周日）、10/10（周六）为调休上课日，课程按节次顺序进行**
- **第一学期：2026/8/24 ~ 2027/1/10（上课至 12/27，考试周 12/28 ~ 1/10）**


<div class="top-2"></div>

#### 考核

- 平时成绩 20%：课堂代码实操 + 在线OJ系统闯关
- 期末项目 20%：跨学科智能应用开发（代码 + 答辩 + 技术文档）
- 课程考试 60%：闭卷机试（语法基础、算法设计和智能应用）

#### 课件

在线浏览，Space 翻页，Esc 导航，可能需{==科学上网==}才能打开

课件按教学周陆续发布

<div class="threelines outline head-highlight">

|        |              讲义                | 内容                           |
| :----: | :--                             | :--                            |
| 第1周   | [课程介绍](slides/1-intro/0-0-intro.html)           |     课程介绍   |
|   ^    | [入门](slides/1-intro/0-1-programming-and-c.html)        | 程序设计与C语言入门                    |
|   ^    | [初识C程序](slides/1-intro/0-2-first-c-program.html)        | 初识C程序：Hello World 与 C 程序结构                    |
|   ^    | [C 语言历史与 AI](slides/1-intro/0-3-c-and-ai.html)        | C 语言历史与人工智能                    |
|   ^    | [变量与基本数据类型](slides/1-intro/0-4-variable-and-assignment.html)        | 变量与基本数据类型                    |
|   ^    | [上手: 开发环境与 AI 工具](slides/1-intro/0-5-environment-ai.html) | 开发环境与 AI 工具（安装、编译运行、调试、AI 规范）—— ==上机课 / 课后自学== |
| 第2周   | [数据类型深化](slides/2-types-io/2-1-types-deep-dive.html)   | 数据类型深化                    |
|   ^    | [格式化输入输出](slides/2-types-io/2-2-formatted-io.html)    | 格式化输入输出                    |
| 第3周   | [运算符和表达式](slides/3-types-io/3-1-operators-expressions.html) | 运算符和表达式                |
|   ^    | [类型转换与未定义行为](slides/3-types-io/3-2-conversion.html) | 类型转换与未定义行为                |
| 第4周   | [选择结构 (上)](slides/4-if-for-array/4-1-selection-i.html) | 选择结构 (上) |
|   ^    | [选择结构 (下)](slides/4-if-for-array/4-2-selection-ii.html) | 选择结构 (下) |
| 第5周   | [循环结构 (上)](slides/5-if-for-array/5-1-loops-i.html) | 循环结构 (上) |
|   ^    | [循环结构 (下)](slides/5-if-for-array/5-2-loops-ii.html) | 循环结构 (下) |
|   ^    | [循环习题课](slides/5-if-for-array/5-3-loops-practice.html) | 循环习题课 |
| 第6周   | [一维数组](slides/6-arrays/6-1-arrays-i.html) | 一维数组（与循环配合） |
|   ^    | [二维数组与矩阵运算](slides/6-arrays/6-2-arrays-2d.html) | 二维数组与矩阵运算 |
| 第7周   | [排序](slides/7-sorting-searching/7-1-sorting.html) | 排序 |
| 第8周   | [函数 (上)](slides/8-functions/8-1-functions-i.html) | 函数 (上) |
|   ^    | [函数 (下)](slides/8-functions/8-2-functions-ii.html) | 函数：函数化改造 + 数组作参数 + 函数调用栈 |
| 第9周   | [递归](slides/9-functions/9-1-recursion.html) | 递归：执行过程、Hanoi 与分治 |
| 第10周  | [指针（上）](slides/10-pointers/10-1-pointers-i.html) | 指针（上）：概念、& 与 *、赋值 |
|   ^    | [指针（下）](slides/10-pointers/10-2-pointers-ii.html) | 指针（下）：传址调用、const 与返回值 |
| 第11周  | [指针与数组（上）](slides/11-pointers/11-1-pointer-arrays-i.html) | 指针与数组（上）：算术运算、* 与 ++ |
|   ^    | [指针与数组（下）](slides/11-pointers/11-2-pointer-arrays-ii.html) | 指针与数组（下）：数组名、数组实参、多维数组 |
| 第12周  | [字符指针与字符串处理](slides/12-strings/12-1-strings.html) | 字符指针与字符串处理 |
|   ^    | [指针数组与函数指针](slides/12-strings/12-2-pointer-arrays-funcs.html) | 指针数组与函数指针 |
| 第13周  | [结构体](slides/13-struct-linked-list/13-1-struct.html) | 结构体 |
|   ^    | [链表（一）](slides/13-struct-linked-list/13-2-linked-list-i.html) | 链表（一）：动态内存 malloc/free 与建表 |
|   ^    | [链表（二）](slides/13-struct-linked-list/13-2-linked-list-ii.html) | 链表（二）：插入、删除与遍历 |
|   ^    | [链表（三）](slides/13-struct-linked-list/13-2-linked-list-iii.html) | 链表（三）：综合案例（约瑟夫问题等） |
| 第14周  | [文件操作](slides/14-files/14-1-files.html) | 文件操作 |
|   ^    | [预处理命令与多文件组织](slides/14-files/14-2-multi-file.html) | 预处理命令与多文件组织 |
| 第15周  | [期末项目指导](slides/15-project-review/15-1-project.html) | 期末项目指导 |
|   ^    | [总复习与答疑](slides/15-project-review/15-2-review.html) | 总复习与答疑 |

</div>

#### 教材

《C语言程序设计教程》 姜恒远主编，高等教育出版社，2010（ISBN 9787040302769）

#### 参考教材

[_C语言程序设计现代方法 第二版 修订版_](book/C语言程序设计现代方法-第二版.pdf) <br>K.N. King 著，吕秀峰、黄倩 译

#### 在线评测系统

[http://172.28.223.3/](http://172.28.223.3/)（仅校园网内访问，请用学号注册，[使用说明](OJ平台使用说明.pdf)）


<!-- #### 答疑相关

1. [如何提问](slides/smartquestion.html)
2. [共性问题](slides/commonquestion.html) -->

<!-- #### 答疑安排

[https://docs.cpl.icu/#/qa](https://docs.cpl.icu/#/qa) -->


