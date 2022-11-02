---
presentation:
  margin: 0
  center: false
  transition: "convex"
  enableSpeakerNotes: true
  slideNumber: "c/t"
  navigationMode: "linear"
---

@import "../css/font-awesome-4.7.0/css/font-awesome.css"
@import "../css/theme/solarized.css"
@import "../css/logo.css"
@import "../css/font.css"
@import "../css/color.css"
@import "../css/margin.css"
@import "../css/table.css"
@import "../css/main.css"
@import "../plugin/zoom/zoom.js"
@import "../plugin/customcontrols/plugin.js"
@import "../plugin/customcontrols/style.css"
@import "../plugin/chalkboard/plugin.js"
@import "../plugin/chalkboard/style.css"
@import "../plugin/menu/menu.js"
@import "../js/anychart/anychart-core.min.js"
@import "../js/anychart/anychart-venn.min.js"
@import "../js/anychart/pastel.min.js"
@import "../js/anychart/venn-ml.js"

<!-- slide data-notes="" -->

<div class="bottom20"></div>

# C语言程序设计基础

<hr class="width50 center">

## 引言

<div class="bottom8"></div>

### 计算机系 &nbsp;&nbsp; 杨已彪

#### _yangyibiao@nju.edu.cn_

<!-- slide vertical=true data-notes="" -->

##### 课程安排

---

授课: 杨已彪, yangyibiao@nju.edu.cn

形式: ==教考== 分离

时间: 

- 理论: 42学时, 周四 2-4 节课(第 3 ~ 16 周)

- 实验: 在线测试(OJ: Online Judge)

> =="Talk is cheap. Show me the code."== -- Linus Torvalds

<!-- slide vertical=true data-notes="" -->

##### 课程助教

---

- ==茆文杰==(软件学院, 鼓楼), wjmao_nju@163.com

- ==姜钊炜==(软件学院, 鼓楼), jiangzhaowei0704@sina.com

- ==李清扬==(计算机系, 仙林), liqingyang0207@163.com

<!-- slide vertical=true data-notes="" -->

##### 考核方式

---
(六个班级一致)

- ==平时编程: 40%==(12次OJ编程练习: 每周发布, 需在线提交评测)

- 期中项目: 10%(小项目)

- ==期末机试: 30%==(上机编程考试: 在线、限时、闭卷)

- 期末笔试: 20%

- 课程网站: http://47.122.3.40/#/

- 课程网站(校内或校外VPN): http://docs.cpl.icu

- OJ地址: http://oj.cpl.icu/

<!-- slide vertical=true data-notes="" -->

##### 课程说明

---

申请免修不免考的学生须在教务网提交申请, 同时发邮件给教师说明缘由.

申请免修不免考意味着: 因免修造成的一切后果自负, 而且平时作业、大作业、上机测验和期中/期末等均不免.

==强烈建议== 加倍认真自学课件与教材中的内容(教学团队在答疑时, 有可能拒绝回复课堂讲过的内容, 尤其是反复强调过的内容); 

==友情提醒== 在参加本课程的任何环节之前, 需得到冲突课程老师的允许(本课程教学团队从不鼓励学生旷其他课).

<!-- slide vertical=true data-notes="" -->

##### 课程网站

---

发布教案、讨论、发布OJ实训作业(~~选做~~)

- 课程网站: https://cslab-cms.nju.edu.cn/

- 邀请码: H3RPB

- 课程QQ群: 651382342

<div class="top-2">
    <img src="../img/QQgroup.jpeg" width=200px>
</div>

<!-- slide vertical=true data-notes="" -->

##### 课程教材

---

<div class="top-2">
    <img src="../img/book/cpm.jpg" width=200px height=270px>
</div>

- 书名: C语言程序设计 现代方法 第2版·修订版

- 作者: K.N.King

- 译者: 吕秀锋, 黄倩

- 出版: 人民邮电出版社


<!-- slide data-notes="" -->

##### 参考书目

---

<div class="top-2">
    <img src="../img/book/The_C_Programming_Language.png" width=200px height=270px>
</div>

- 书名: C程序设计语言

- 作者: (美)Brian W. Kernighan / (美)Dennis M. Ritchie

- 译者: 徐宝文、李志

- 出版: 机械工业出版社

<!-- slide data-notes="" -->

##### 课程目标

---

了解: 

- 计算机程序的工作原理

- 从程序设计角度分析问题的基本思路

掌握: 

- ==从程序设计角度== 解决问题的基本方法

  1.1 只涉及简单算法和数据结构, 常用的开发环境和语言要素; 

  1.2 不会深入探讨算法或数据结构及其性能评价

  1.3 开发过程要规范: 熟练选用恰当的程序要素(流程、模块、数据及操作)表示和实现简单的算法和数据结构
  
  1.4 编写规范的程序: 养成良好的编程习惯

- 设计规范的小型计算机程序


<!-- slide data-notes="" -->

##### 评价指标

---

- 对于平时编程练习, 我们会留出充足的时间.

- 需要提醒大家的是, 不要以身试 DDL("Deadline"的简称, 意为"截止时间"), 虽然刺激, 但鲜有不失手的.

- 认真独立完成平时编程练习与期中项目, 期末机试就可以轻装上阵.

- 期末机试是限时编程模式, 实力与运气都很重要.

from 公共课程网站

<!-- slide data-notes="" -->

##### 发布习题

---

- 每周五晚 18:00 发布习题

- 每周五晚 23:00 截止

<!-- slide data-notes="" -->

##### 提交规则

---

未按时提交

规则一: 若需延迟提交, 请务必提前24小时向助教进行申请.

- 在截止时间 24 小时之内提交的, 扣除当次作业成绩的 20%

- 在截止时间 24 到 48 小时之内提交的, 扣除当次作业成绩的 40%

- 在截止时间 48 到 72 小时之内提交的, 扣除当次作业成绩的 50%

- 在截止时间 72 小时后提交的, 本次作业成绩记零

规则二: 若延迟提交, 但没有提前 24 小时进行申请

- 若能说明合理的紧急情况, 则按规则一执行

我的批注 千万不要踩红线

<!-- slide data-notes="" -->

##### 提交规则

---

对于"踩 DDL 提交"的情况: 

- 在截止时间 24 小时之内提交的, 扣除当次作业成绩的 50%

- 在截止时间 24 小时后提交的, 本次作业成绩记零

规则三: 其余超出截止时间的提交均记零

我的批注 千万不要踩红线

<!-- slide data-notes="" -->

##### 提交规则

---

抄袭的认定过程

- 每次OJ截止后, OJ系统自动对所有代码进行==查重==

- 对重复率较高的代码, 由多位助教人工判定是否为抄袭

- 助教约谈疑似抄袭的同学, 无异议则执行惩罚措施.

我的批注 千万不要踩红线

<!-- slide data-notes="" -->

##### 期中项目

---

- 占比: 10%

- 形式: 待定

<!-- slide data-notes="" -->

##### 期末机试

---

- 占比: 30%

- 形式: 上机测试、限时、闭卷

<!-- slide data-notes="" -->


##### 一个小调研

---

- 学过X编程？

- 学过C语言？

<!-- slide data-notes="" -->

##### C语言的历史

---

==起源==: 贝尔实验室Ken Thompson、Dennis Ritchie等人开发Unix操作系统的==副产品==

==标准化==: Brian Kernighan 和 Dennis Ritchie (K&R)合编==The C Programming Languages== -> C普及(K&R书对语言特性描述非常模糊, 编译器会做出不同的处理, 影响C程序的可移植性) -> 催生了C89、C90、C99等标准

==基于C的语言==: C++(增加面向对象)、Java(基于C++)、C#

我的启示 C语言: 基础适合入门、大量C代码、内存处理简单

<!-- slide data-transition="convex-in none" vertical=true data-notes="" -->

##### C语言的优缺点

---

优缺点

- 优点: 高效、可移植性、灵活、标准库、与UNIX(LINUX)集成

- 缺点: 更易隐藏错误、可能难以理解、难以维护

高效使用C

- 规避语言缺陷

- ~~使用分析工具: lint进行错误分析~~

- ~~利用现有代码库~~

- ==采用合理编码规范==

- 避免复杂的代码

- 避免C编译器C89或C99之外的特性和库函数

<!-- slide vertical=true data-notes="" -->


##### 基本概念

---

==C语言程序设计==

==(计算机)程序==: 指一组计算机能识别和执行的==指令序列==, 一个特定的指令序列用来==完成一定的功能==.通常用某种程序设计语言编写, 运行于某种目标体系结构上.

- ==源代码==程序: 程序员使用某种编程语言编写的代码

- ==二进制==程序: 编译器生成的可执行程序

<!-- slide vertical=true data-notes="" -->

##### 基本概念

---

==C语言程序设计==

- ==程序设计==: ==给出解决特定问题程序的过程==.以某种程序设计语言为工具, 给出这种语言下的程序.程序设计过程: 分析、设计、编码、测试、排错等.

- ==程序设计语言==: 一种计算机和人都能识别的语言, 人与计算机==交互==的语言, 也称编程语言(C、JAVA、Python等)


