@import "css/theme/solarized.css"
@import "css/font.css"
@import "css/color.css"
@import "css/index.css"

## 高级程序设计（C++）

**2027 年春**

授课：杨已彪 _yangyibiao@nju.edu.cn_

- **2027 年春**，17 周 × 每周 2 学时，共 34 学时
- 面向计算机学院大一本科生
- 以 C++17 为基线，按知识点选讲 C++20

---

#### 课程简介

本课程从《程序设计基础》出发，逐步建立面向对象思维，理解现代 C++ 的语言机制与工程方法。课程围绕三条主线展开：

- **抽象与边界**：类、接口、继承、多态、模块
- **生命周期与资源**：构造/析构、拷贝/移动、RAII、智能指针、异常安全
- **复用与并发**：模板、STL、Lambda、并发与同步、声明式与事件驱动

课程以 **MiniBuild 构建系统** 为主线案例，随章节逐步扩展：从 C 结构体到类，从规则继承到多态，从依赖图到拓扑调度，从单线程到并行构建，最终形成一个可运行、可测试、可讲解的课程项目。

#### 课程安排

| 周次 | 课件 | 内容 |
| :--: | :-- | :-- |
| 1 | [课程概述与面向对象全景](slides/01-course-and-oop/1-1-course-and-oop.html) | 课程定位、抽象与封装、类/对象、OOP 四大特征 |
| 2 | [类与对象](slides/02-classes-and-objects/2-1-classes-and-objects.html) | 类定义、访问控制、`this`、const 成员、对象创建 |
| 3 | [构造与析构](slides/03-construction-destruction/3-1-construction-destruction.html) | 构造函数、初始化列表、析构函数、成员对象、RAII 初识 |
| 4 | [拷贝构造与赋值](slides/04-copy-assignment/4-1-copy-assignment.html) | 浅/深拷贝、拷贝赋值、三法则、RVO |
| 5 | [移动语义与 RAII](slides/05-move-raii/5-1-move-raii.html) | 左值/右值、移动构造/赋值、五法则、`std::move` |
| 6 | [const、static、友元与模块](slides/06-const-static-friend-module/6-1-const-static-friend-module.html) | const 重载、static 成员、友元、`.h/.cpp`、ODR |
| 7 | [继承、多继承与组合](slides/07-inheritance/7-1-inheritance.html) | 单/多继承、访问控制、构造/析构顺序、组合优于继承 |
| 8 | [多态与动态绑定](slides/08-polymorphism/8-1-polymorphism.html) | 虚函数、虚表、虚析构、抽象类、接口、RTTI |
| 9 | [运算符重载](slides/09-operator-overloading/9-1-operator-overloading.html) | 成员/非成员、`++/--`、`[]`、`()`、`->`、转换 |
| 10 | [输入输出流](slides/10-io-streams/10-1-io-streams.html) | 流模型、格式化、`getline`、文件流、文本/二进制 |
| 11 | [异常处理与程序健壮性](slides/11-exceptions/11-1-exceptions.html) | throw/try/catch、栈展开、异常安全、断言、Sanitizer |
| 12 | [模板与泛型程序设计](slides/12-templates/12-1-templates.html) | 函数/类模板、实例化、特化、可变参数、Concepts |
| 13 | [STL](slides/13-stl/13-1-stl.html) | 容器、迭代器、算法、Lambda、Ranges |
| 14 | [内存安全与智能指针](slides/14-memory-safety/14-1-memory-safety.html) | 空间/时间类错误、UB、ASan、`unique_ptr`/`shared_ptr`/`weak_ptr` |
| 15 | [并发与多线程](slides/15-concurrency/15-1-concurrency.html) | 线程、数据竞争、mutex、条件变量、atomic、async、线程池 |
| 16 | [声明式与事件驱动](slides/16-declarative-event/16-1-declarative-event.html) | filter/map/reduce、Ranges、事件循环、观察者 |
| 17 | [项目指导与总复习](slides/17-project-review/17-1-project-review.html) | 项目设计、测试、评分、知识地图、模拟题 |

#### 考核

- 平时作业与课堂任务
- 上机考核（OJ）
- 课程项目（设计 + 实现 + 答辩）
- 期末笔试

具体比例、提交方式与截止时间以课程网站通知为准。

#### 教材与参考

- 陈家骏、郑滔，《程序设计教程——用 C++ 语言编程（第 4 版）》，机械工业出版社
- [cppreference.com](https://en.cppreference.com/)：C++ 标准库与语言参考
- [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/)：现代 C++ 编码规范

#### 构建与维护

课件源码位于 `slides/`，构建方式与目录说明见 [slides/README.md](slides/README.md)。课程规划、案例设计与内容迁移对照表：

- [课程规划与案例设计](slides/课程规划与案例设计.md)
- [内容迁移对照表](slides/内容迁移对照表.md)
- [质量检查报告](slides/质量检查报告.md)
