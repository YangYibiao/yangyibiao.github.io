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

## 循环习题课

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](mailto:yangyibiao@nju.edu.cn)

<!-- slide data-notes="" -->

##### 提纲

---

- 例题: 成绩统计、完全数判定

- 练习: 数字三角形、跳水评分、水仙花数

- 进阶练习 (选做): 回文数、斐波那契、百钱百鸡

- 组合练习 (选做): 菜单计算器、成绩等级统计

- 每题都是"先任务后代码", 写完编译运行验证

---
<!-- slide data-notes="" -->


##### 例题: 成绩统计

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1;">

==现场演示==: 输入一批学生成绩 (0~100), 直到 ==-1== 结束, 输出==最高分==以及==得最高分的人数==

样例:

```
输入成绩 (-1 结束): 85 92 85 78 92 -1
最高分: 92
人数: 2
```

<span class="blue">:fa-lightbulb-o:</span> 提示: 哨兵值 -1 不参与统计; 出现==更高的分数==时, 人数要==重置==吗?

</div>

</div>

---
<!-- slide data-notes="" -->


##### 例题: 成绩统计 (参考代码)

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.25;font-size:0.62em;">

```C{.line-numbers}
#include <stdio.h>
int main(void) {
    int score, max = -1, count = 0;
    printf("输入成绩 (-1 结束): ");
    scanf("%d", &score);
    while (score != -1) {
        if (score > max) {
            max = score;      /* 新最高分 */
            count = 1;        /* 人数重新计 */
        } else if (score == max) {
            count++;          /* 并列最高分 */
        }
        scanf("%d", &score);
    }
    printf("最高分: %d\n", max);
    printf("人数: %d\n", count);
    return 0;
}
```

</div>

<div style="flex:1;">

- `max` 初始 -1 (成绩都 ≥ 0); 出现更高分时 ==max 更新、count 重置为 1==——这是并列计数的关键

- 哨兵 -1 只用来结束, 不进统计

- 与 5-1 的"找最大值"同型, 多了一个并列计数

</div>

</div>

---
<!-- slide data-notes="" -->


##### 例题: 完全数判定

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1;">

==现场演示==: 输入一个整数, 判断它是不是==完全数== (等于除自身外的所有因数之和, 如 6 = 1+2+3, 28 = 1+2+4+7+14)

样例:

```
输入一个数: 28
28 是完全数
输入一个数: 12
12 不是完全数
```

<span class="blue">:fa-lightbulb-o:</span> 提示: 完全数等于除自身外的因数之和——怎么==找出这些因数==?

</div>

</div>

---
<!-- slide data-notes="" -->


##### 例题: 完全数判定 (参考代码)

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.25;font-size:0.62em;">

```C{.line-numbers}
#include <stdio.h>
int main(void) {
    int n, i, sum = 0;
    printf("输入一个数: ");
    scanf("%d", &n);
    for (i = 1; i < n; i++) {
        if (n % i == 0) {
            sum += i;         /* 累加因数 */
        }
    }
    if (sum == n)
        printf("%d 是完全数\n", n);
    else
        printf("%d 不是完全数\n", n);
    return 0;
}
```

</div>

<div style="flex:1;">

- 枚举 1 ~ n-1, `n % i == 0` 就是因数——==模运算判断整除==的经典用法

- 累加器 `sum` 初值 0; 循环结束再和 n 比较

- 拓展: 输出 10000 以内的完全数 (6、28、496、8128)

</div>

</div>

---
<!-- slide data-notes="" -->


##### 练习: 数字三角形

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1;">

==独立练习==: 输入高度 n, 打印数字三角形——第 i 行打印 i 个数字 i

样例 (n = 4):

```
1
22
333
4444
```

<span class="blue">:fa-lightbulb-o:</span> 提示: 嵌套循环——外层管行, 内层管每行个数; 内层打印的是==行号==还是别的?

</div>

</div>

---
<!-- slide data-notes="" -->


##### 练习: 数字三角形 (参考代码)

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.25;font-size:0.62em;">

```C{.line-numbers}
#include <stdio.h>
int main(void) {
    int n;
    printf("输入高度: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d", i);      /* 打印行号 i */
        }
        printf("\n");
    }
    return 0;
}
```

</div>

<div style="flex:1;">

- 内层 `j` 控制个数 (1 到 i), 打印的内容是==外层变量 i==

- 常见错误: 内层打印 `j` (会打成 123/123/123) 或 `n` (全行一样)

- 和星号塔同结构, 换了个"打印什么"

</div>

</div>

---
<!-- slide data-notes="" -->


##### 练习: 跳水评分

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1;">

==独立练习==: 跳水比赛 8 个裁判打分 (0~10, 一位小数), 去掉一个最高分、一个最低分, 输出剩余 6 个的平均分 (保留两位)

样例:

```
输入 8 个分数: 9.5 9.0 8.5 9.5 8.0 9.0 9.5 8.5
最终得分: 9.00
```

<span class="blue">:fa-lightbulb-o:</span> 提示: 去掉最高和最低——你需要在循环里同时维护==哪几个量==?

</div>

</div>

---
<!-- slide data-notes="" -->


##### 练习: 跳水评分 (参考代码)

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.25;font-size:0.6em;">

```C{.line-numbers}
#include <stdio.h>
int main(void) {
    double score, sum = 0, max = -1, min = 11;
    int i;
    for (i = 0; i < 8; i++) {
        scanf("%lf", &score);
        sum += score;
        if (score > max) max = score;
        if (score < min) min = score;
    }
    printf("最终得分: %.2f\n", (sum - max - min) / 6);
    return 0;
}
```

</div>

<div style="flex:1;">

- `max` 初值 -1、`min` 初值 11——比所有可能分数都"更差"的起点

- 循环里==同时维护== sum、max、min 三个量

- 一次遍历搞定, 不需要数组——流式处理的典型

</div>

</div>

---
<!-- slide data-notes="" -->


##### 练习: 水仙花数

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1;">

==独立练习==: 输出所有的三位==水仙花数== (各位数字的立方和等于本身, 如 153 = 1³+5³+3³)

样例:

```
153 370 371 407
```

<span class="blue">:fa-lightbulb-o:</span> 提示: 怎么判断一个数是不是水仙花数? 每位数字怎么拆出来? (第 3 周的老朋友)

</div>

</div>

---
<!-- slide data-notes="" -->


##### 练习: 水仙花数 (参考代码)

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.25;font-size:0.6em;">

```C{.line-numbers}
#include <stdio.h>
int main(void) {
    int n, ge, shi, bai;
    for (n = 100; n <= 999; n++) {
        bai = n / 100;
        shi = n / 10 % 10;
        ge = n % 10;
        if (bai * bai * bai + shi * shi * shi + ge * ge * ge == n)
            printf("%d ", n);
    }
    printf("\n");
    return 0;
}
```

</div>

<div style="flex:1;">

- 外层枚举所有三位数, 内层每个数==拆分 + 判定==——枚举与拆分的组合

- 数位拆分是第 3 周的"先除后模"套路, 这里在循环里批量使用

- 立方直接连乘 (`bai*bai*bai`), 不需要 pow

</div>

</div>

<!-- slide data-notes="" -->


##### 练习: 回文数判定 (选做)

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1;">

==独立练习==: 输入一个正整数, 判断它是不是==回文数== (正着读和反着读一样)

样例:

```
输入一个数: 12321
12321 是回文数
输入一个数: 12345
12345 不是回文数
```

<span class="blue">:fa-lightbulb-o:</span> 提示: 怎么把数"反过来读"? 数位拆分的老朋友, 但这次要把拆出来的数字==重新拼起来==

</div>

</div>

---


<!-- slide data-notes="" -->


##### 练习: 回文数判定 (参考代码)

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.25;font-size:0.6em;">

```C{.line-numbers}
#include <stdio.h>
int main(void) {
    int n, m, rev = 0;
    printf("输入一个数: ");
    scanf("%d", &n);
    m = n;
    while (m > 0) {
        rev = rev * 10 + m % 10;   /* 末位接到 rev 后面 */
        m /= 10;
    }
    if (rev == n)
        printf("%d 是回文数\n", n);
    else
        printf("%d 不是回文数\n", n);
    return 0;
}
```

</div>

<div style="flex:1;">

- `rev = rev * 10 + m % 10` 是==反转构造==的经典一行: 每次把末位"接"到 rev 后面

- `m` 复制了 n——n 要留到最后比较, 不能改

- 数位拆分 (水仙花) 是"拆", 这里是"拆了再拼"——同一套 `% 10` / `/ 10` 的两种用法

</div>

</div>

---


<!-- slide data-notes="" -->


##### 练习: 斐波那契数列 (选做)

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1;">

==独立练习==: 输入 n, 输出斐波那契数列的前 n 项 (1、1、2、3、5、8、…)

样例 (n = 10):

```
1 1 2 3 5 8 13 21 34 55
```

<span class="blue">:fa-lightbulb-o:</span> 提示: 每项是前两项之和——需要同时==记住哪两个数==? 每轮它们怎么变?

</div>

</div>

---


<!-- slide data-notes="" -->


##### 练习: 斐波那契数列 (参考代码)

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.25;font-size:0.6em;">

```C{.line-numbers}
#include <stdio.h>
int main(void) {
    int n, i, a = 1, b = 1, t;
    printf("输入 n: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        printf("%d ", a);
        t = a + b;      /* 下一项 */
        a = b;          /* 滚动: 旧 b 变新 a */
        b = t;          /* 新 b 是刚才的和 */
    }
    printf("\n");
    return 0;
}
```

</div>

<div style="flex:1;">

- 两个变量 `a`、`b` ==滚动更新==——循环里"记住前两项"的标准模型

- 每轮: 打印 a → 算下一项 t → a、b 各往前挪一格

- 这个数列==第 9 周递归会再见==——到时对比两种写法

</div>

</div>

---


<!-- slide data-notes="" -->


##### 练习: 百钱百鸡 (选做)

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1;">

==独立练习==: 公鸡 5 文一只、母鸡 3 文一只、小鸡 1 文 3 只。用 100 文钱买 100 只鸡, 输出所有方案

样例:

```
公鸡 0   母鸡 25  小鸡 75
公鸡 4   母鸡 18  小鸡 78
公鸡 8   母鸡 11  小鸡 81
公鸡 12  母鸡 4   小鸡 84
```

<span class="blue">:fa-lightbulb-o:</span> 提示: 公鸡和母鸡的只数都枚举一遍, 小鸡只数能==推出来==吗? 价钱条件怎么写?

</div>

</div>

---


<!-- slide data-notes="" -->


##### 练习: 百钱百鸡 (参考代码)

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.25;font-size:0.6em;">

```C{.line-numbers}
#include <stdio.h>
int main(void) {
    int g, h, c;
    for (g = 0; g <= 20; g++) {        /* 公鸡最多 20 只 */
        for (h = 0; h <= 33; h++) {    /* 母鸡最多 33 只 */
            c = 100 - g - h;           /* 小鸡只数: 推出来 */
            if (5 * g + 3 * h + c / 3 == 100 && c % 3 == 0)
                printf("公鸡 %d  母鸡 %d  小鸡 %d\n", g, h, c);
        }
    }
    return 0;
}
```

</div>

<div style="flex:1;">

- ==枚举两个、推导第三个==: c 由 g、h 直接算出, 少一层循环

- 条件两个: 总价 `5g + 3h + c/3 == 100`, 且小鸡数 `c % 3 == 0` (不能买半只)

- 共 4 组解——第一次体会"循环暴力求解"的快感

</div>

</div>

<!-- slide data-notes="" -->


##### 练习: 菜单计算器 (选做)

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1;">

==独立练习==: 写一个菜单计算器——循环显示菜单, 用户选择运算, 直到选择退出

样例:

```
1. 加法
2. 减法
3. 退出
请选择: 1
输入两个数: 3 5
3 + 5 = 8
请选择: 2
输入两个数: 10 4
10 - 4 = 6
请选择: 3
再见!
```

<span class="blue">:fa-lightbulb-o:</span> 提示: 菜单要==反复出现==——哪种循环最合适? 选择项用什么结构处理? 退出要跳出哪一层?

</div>

</div>

---


<!-- slide data-notes="" -->


##### 练习: 菜单计算器 (参考代码)

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.25;font-size:0.58em;">

```C{.line-numbers}
#include <stdio.h>
int main(void) {
    int choice, a, b;
    do {
        printf("1. 加法\n2. 减法\n3. 退出\n");
        printf("请选择: ");
        scanf("%d", &choice);
        if (choice == 1 || choice == 2) {
            printf("输入两个数: ");
            scanf("%d%d", &a, &b);
        }
        switch (choice) {
            case 1: printf("%d + %d = %d\n", a, b, a + b); break;
            case 2: printf("%d - %d = %d\n", a, b, a - b); break;
            case 3: printf("再见!\n"); break;
            default: printf("无效选择\n");
        }
    } while (choice != 3);
    return 0;
}
```

</div>

<div style="flex:1;">

- ==do-while + switch== 的经典组合: 菜单至少出现一次, 选项用 switch 分发

- `choice != 3` 控制循环结束——switch 里的 break 只跳出 switch, ==不会跳出循环==

- 非法输入走 default, 循环继续——菜单程序天然容错

</div>

</div>

---


<!-- slide data-notes="" -->


##### 练习: 成绩等级统计 (选做)

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1;">

==独立练习==: 输入一批成绩 (0~100, -1 结束), 统计各等级人数: 90~100 为 A, 80~89 为 B, 70~79 为 C, 60~69 为 D, 0~59 为 F

样例:

```
输入成绩 (-1 结束): 85 92 78 61 45 92 -1
A: 2  B: 1  C: 1  D: 1  F: 1
```

<span class="blue">:fa-lightbulb-o:</span> 提示: 怎么把 0~100 的成绩划分成 A~F 五档? 每个等级需要一个什么?

</div>

</div>

---


<!-- slide data-notes="" -->


##### 练习: 成绩等级统计 (参考代码)

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div style="flex:1.25;font-size:0.58em;">

```C{.line-numbers}
#include <stdio.h>
int main(void) {
    int score, a = 0, b = 0, c = 0, d = 0, f = 0;
    printf("输入成绩 (-1 结束): ");
    scanf("%d", &score);
    while (score != -1) {
        switch (score / 10) {
            case 10: case 9: a++; break;
            case 8:  b++; break;
            case 7:  c++; break;
            case 6:  d++; break;
            default: f++; break;
        }
        scanf("%d", &score);
    }
    printf("A: %d  B: %d  C: %d  D: %d  F: %d\n", a, b, c, d, f);
    return 0;
}
```

</div>

<div style="flex:1;">

- `score / 10` 把 0~100 映射成 10 个档——switch 的 case 就是档位

- `case 10: case 9:` ==共用一个语句== (A 档)——第 4 周学的多 case 标签在这里兑现

- ==忘写 break 会串档== (所有档都往下漏)——统计类程序的经典 bug

</div>

</div>

---


<!-- slide data-notes="" -->

#####

---

<div class="bottom20"></div>

# 下周见!

<hr class="width50 center">

## 未完待续

---
