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

我的启示 =="Talk is cheap. Show me the code."== -- Linus Torvalds
我的启示 ==纸上得来终觉浅，绝知此事要躬行== -- 陆游



<!-- slide vertical=true data-notes="" -->

##### 课程助教

---

- ==xxx==(软件学院, 鼓楼), wjmao_nju@163.com



<!-- slide vertical=true data-notes="" -->

##### 考核方式

---
(六个班级一致)

- ==平时编程: 40%==(12次OJ编程练习: 每周发布, 需在线提交评测)

- 期中项目: 10%(小项目)

- ==期末机试: 30%==(上机编程考试: 在线、限时、闭卷)

- 期末笔试: 20%

- 教案发布: https://yangyibiao.github.io/cpl/index.html

- 课程网站: http://docs.cpl.icu

- 在线评测: http://oj.cpl.icu/



<!-- slide vertical=true data-notes="" -->

##### 课程说明

---

申请免修不免考的学生须在教务网提交申请, 同时发邮件给教师说明缘由.

申请免修不免考意味着: 因免修造成的一切后果自负, 而且平时作业、大作业、上机测验和期中/期末等均不免.

==强烈建议== 加倍认真自学课件与教材中的内容(教学团队在答疑时, 有可能拒绝回复课堂讲过的内容, 尤其是反复强调过的内容); 

==友情提醒== 在参加本课程的任何环节之前, 需得到冲突课程老师的允许(本课程教学团队从不鼓励学生旷其他课).



<!-- 

##### 课程网站

---

发布教案、讨论、发布OJ实训作业

- 课程网站: https://cslab-cms.nju.edu.cn/

- 邀请码: H3RPB

- 课程QQ群: 651382342

<div class="top-2">
  <img src="../img/QQgroup.jpeg" width=200px>
</div> -->



<!-- slide vertical=true data-notes="" -->

##### 课程教材

---

<div class="top-2">
  <img src="../img/book/cpm.jpg" width=200px height=270px>
</div>

- 书名: C语言程序设计 现代方法 第2版·修订版 (吕秀锋, 黄倩 译)

- 作者: K.N.King

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

##### C语言的起源

---

C 是 UNIX 的副产品, 由 Ken Thompson, Dennis Ritchie 等人在贝尔实验室开发.

Thompson 设计了一种名为 B 的小型语言. 

B 基于 BCPL, 一种在 1960 年代中期开发的系统编程语言.



<!-- slide data-notes="" -->

##### C语言的起源

---

到 1971 年, Ritchie 开始开发 B 的扩展版本.

起初, 他称他的语言为 NB("New B").

随着语言开始与B越来越不同, 他将其名称改为C.

到 1973 年, 该语言已经足够稳定, 可以用 C 重写 UNIX.



<!-- slide data-notes="" -->

##### C语言的标准化

---

K&R C

- Kernighan和Ritchie合作编写了《C程序设计语言》(1978)
- 没有正式的C语言标准, 这本书成了事实标准

C89/C90
- ANSI标准X3.159-1989(1988年完成, 1989年12月正式批准)
- 国际标准ISO/IEC 9899:1990

C99
- 国际标准ISO/IEC 9899:1999
- 包含了一些重要的改变



<!-- slide data-notes="" -->

##### 基于C的语言

---

C++包括C的所有特性, 添加了类和其他特性以支持面向对象编程

Java基于C++, 因此继承了许多C特性

C#是从C++和Java派生的新的语言

Perl吸收了C的许多特性。



<!-- slide data-notes="" -->

##### C的性质

---

低层语言
- 提供了对机器级概念的访问(字节和地址)

小型语言
- 更有限的特性集合(K&R第2版参考手册仅用49页描述了整个C语言)
- C语言很大程度依赖一个标准函数的库

宽松包容
- 提供了比其他语言更高的自由度, 不强制进行详细的错误检查




<!-- slide data-notes="" -->

##### C的优点

---

- 效率高

- 可移植

- 功能强大: 庞大的数据类型和运算符集合

- 灵活: C语言特性使用的限制非常少, 在其他语言中认定为非法操作在C中往往是允许的

- 标准库

- 与UNIX集成


<!-- slide data-notes="" -->

##### C的弱点

---

- 程序容易隐藏错误

- 程序可能难以理解

- 程序可能难以维护



<!-- slide data-notes="" -->

##### 有效使用 C

---

- 避免C语言的陷阱

- 使用软件工具(lint, 调试器)使程序更可靠

- 利用现有的代码库

- 采用一套合理的编码规范

- 避免"投机取巧"和过于复杂的代码

- 紧贴标准



