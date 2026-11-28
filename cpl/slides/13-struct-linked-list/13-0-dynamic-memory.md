<!-- slide data-notes="" -->

<div class="bottom20"></div>

# 智能程序设计（C语言）

<hr class="width50 center">

## 动态内存: malloc 与 free

<div class="bottom8"></div>

### 计算机学院 &nbsp;&nbsp; 杨已彪

#### [yangyibiao@nju.edu.cn](mailto:yangyibiao@nju.edu.cn)

---

<!-- slide data-notes="" -->

##### 提纲

---

- 为什么需要动态内存
- `malloc` 与 `free`
- 内存泄漏与悬空指针
- 动态数组示例
- 课堂任务与参考实现

---

<!-- slide data-notes="" -->##### 为什么需要动态内存

---

<div style="display:flex;align-items:flex-start;gap:24px;font-size:0.7em;line-height:1.5;text-align:left;">

<div style="flex:1.05;">

==问题==: `int a[10];` 的大小在编译时固定.

- 运行时读入的 n 可能大于 10, 固定数组放不下
- n 很小时又会浪费空间
- 局部数组在函数返回后自动消失, 不能长期保存数据

==动态内存==: 在运行时向堆申请一块内存; 大小由程序决定, 生存期到 `free` 为止.

</div>

<div style="flex:0.95;">

<table style="width:100%;margin-top:8px;font-size:0.92em;border-collapse:collapse;">
<tr style="color:#586e75;">
<th style="text-align:left;padding:2px 4px;border-bottom:1px solid #d6d6c8;">栈上数组 <code>int a[10]</code></th>
<th style="text-align:left;padding:2px 4px;border-bottom:1px solid #d6d6c8;">堆上 <code>malloc</code></th>
</tr>
<tr><td style="padding:2px 4px;">大小编译时固定</td><td style="padding:2px 4px;">大小运行时决定</td></tr>
<tr><td style="padding:2px 4px;">函数返回自动释放</td><td style="padding:2px 4px;">手动 <code>free</code></td></tr>
<tr><td style="padding:2px 4px;">大数组可能栈溢出</td><td style="padding:2px 4px;">堆空间更大</td></tr>
</table>

<div style="margin-top:8px;padding:6px 10px;background:#fdf6e3;border-left:4px solid #268bd2;border-radius:4px;">
动态内存 = 运行时按需申请, 手动归还.
</div>

</div>

</div>

---
<!-- slide data-notes="" -->##### malloc 的用法

---

<div style="display:flex;align-items:flex-start;gap:24px;font-size:0.68em;line-height:1.45;text-align:left;">

<div style="flex:1.05;">

<div class="col-label">函数原型</div>

```C
#include <stdlib.h>
void *malloc(size_t size);
```

- 参数 `size`: 要申请的==字节数==; 申请 n 个 int 要写 `n * sizeof(int)`.
- 返回 `void *`: 指向申请到的内存首地址; C 中可以直接赋给 `int *`.
- 失败返回 `NULL`; ==必须检查==.
- 内存内容==未初始化==, 不能假设为 0.

</div>

<div style="flex:0.95;">

<div class="col-label">典型写法</div>

```C
#include <stdlib.h>

int *make_array(int n)
{
    int *a = malloc(n * sizeof(int));
    if (a == NULL)
        return NULL;       /* 申请失败 */
    return a;              /* 调用者负责 free */
}
```

<div style="margin-top:8px;padding:6px 10px;background:#fff4f2;border-left:4px solid #dc322f;border-radius:4px;">
常见错误: <code>malloc(n)</code> 只申请 n 个字节, 不是 n 个 int; 应写 <code>n * sizeof(int)</code> (或 <code>n * sizeof(*a)</code>).
</div>

</div>

</div>

---
<!-- slide data-notes="" -->##### free 的用法

---

<div style="display:flex;align-items:flex-start;gap:24px;font-size:0.68em;line-height:1.45;text-align:left;">

<div style="flex:1.05;">

<div class="col-label">函数原型</div>

```C
#include <stdlib.h>
void free(void *ptr);
```

- 归还 `malloc/calloc/realloc` 申请的内存.
- `free(NULL)` 是安全的 (什么也不做).
- 只能 free 一次; 重复 free 是==未定义行为==.
- free 后指针悬空; 置 `NULL`, 不要再访问.

</div>

<div style="flex:0.95;">

<div class="col-label">正确 / 错误</div>

<table style="width:100%;font-size:0.9em;border-collapse:collapse;">
<tr style="color:#586e75;">
<th style="text-align:left;padding:2px 4px;border-bottom:1px solid #d6d6c8;">写法</th>
<th style="text-align:left;padding:2px 4px;border-bottom:1px solid #d6d6c8;">结果</th>
</tr>
<tr><td style="padding:2px 4px;"><code>free(a); a = NULL;</code></td><td style="padding:2px 4px;color:#859900;">正确</td></tr>
<tr><td style="padding:2px 4px;"><code>free(a); free(a);</code></td><td style="padding:2px 4px;color:#dc322f;">重复 free, UB</td></tr>
<tr><td style="padding:2px 4px;">不 free</td><td style="padding:2px 4px;color:#dc322f;">内存泄漏</td></tr>
<tr><td style="padding:2px 4px;"><code>free(&amp;x)</code> / free 局部数组</td><td style="padding:2px 4px;color:#dc322f;">不是 malloc 的指针</td></tr>
</table>

<div style="margin-top:8px;padding:6px 10px;background:#fdf6e3;border-left:4px solid #268bd2;border-radius:4px;">
忘记 free 是内存泄漏; free 后继续访问是悬空指针.
</div>

</div>

</div>

---
<!-- slide data-notes="" -->##### 不 free 会怎样: 内存持续增长

---

<div style="display:flex;align-items:flex-start;gap:24px;font-size:0.6em;line-height:1.45;text-align:left;">

<div style="flex:1.15;">

<div class="col-label">完整代码 · malloc-exhaust.c</div>

<style>.exhaust-code pre code{font-size:13px;line-height:1.2;}</style>

<div class="exhaust-code">

```C{.line-numbers}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>

#define BLOCK_MB 1
#define LIMIT_MB 128

static long rss_mb(void)
{
    struct rusage ru;
    getrusage(RUSAGE_SELF, &ru);
#ifdef __APPLE__
    return ru.ru_maxrss / (1024 * 1024);
#else
    return ru.ru_maxrss / 1024;
#endif
}

int main(void)
{
    int used = 0;
    for (;;) {
        if (used >= LIMIT_MB) {
            printf("已分配 %d MB, 达到演示上限 %d MB\n", used, LIMIT_MB);
            printf("真实程序会继续增长, 最终 malloc 返回 NULL 或被 OOM 杀死.\n");
            break;
        }
        unsigned char *p = malloc(BLOCK_MB * 1024 * 1024);
        if (p == NULL) {
            printf("malloc failed after %d MB\n", used);
            break;
        }
        memset(p, 0, BLOCK_MB * 1024 * 1024);
        used += BLOCK_MB;
        if (used % 16 == 0)
            printf("allocated %3d MB, RSS ~ %ld MB\n", used, rss_mb());
    }
    return 0;
}
```

</div>

<div style="margin-top:8px;">
<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/11-pointers/code/malloc-exhaust.c" style="display:inline-block;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.95em;text-decoration:none;">⚡ 在 VS Code 中打开 malloc-exhaust.c (现场演示)</a>
</div>

</div>

<div style="flex:0.85;font-size:0.78em;line-height:1.45;">

<div class="col-label">运行结果</div>

```text
allocated  16 MB, RSS ~ 17 MB
allocated  32 MB, RSS ~ 33 MB
...
allocated 128 MB, RSS ~ 129 MB
已分配 128 MB, 达到演示上限 128 MB
真实程序会继续增长, 最终 malloc 返回 NULL 或被 OOM 杀死.
```

<div style="margin-top:8px;padding:6px 10px;background:#fdf6e3;border-left:4px solid #268bd2;border-radius:4px;">
- 每轮 `malloc` 都不 `free`, 已分配内存无法复用, RSS 持续增长.
- 为了不拖垮机器, 演示到 128 MB 停止; 真实程序会继续到 `malloc` 失败/OOM.
- 修复: 每轮 `free(p)` 或复用同一块.
- 小规模泄漏可以用 `leaks --atExit` 查看.
</div>

</div>

</div>

---
<!-- slide data-notes="" -->##### free 后不置 NULL: 悬空指针现场演示

---

<div style="display:flex;align-items:flex-start;gap:24px;font-size:0.6em;line-height:1.45;text-align:left;">

<div style="flex:1.15;">

<div class="col-label">完整代码 · use-after-free.c</div>

<style>.uaf-code pre code{font-size:13px;line-height:1.2;}</style>

<div class="uaf-code">

```C{.line-numbers}
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *p = malloc(sizeof(int));
    if (p == NULL) return 1;

    *p = 42;
    printf("*p = %d\n", *p);

    free(p);
    /* p = NULL; 忘记 */

    printf("p after free = %p\n", (void *)p);
    printf("*p after free = %d\n", *p);   /* use-after-free */
    return 0;
}
```

</div>

<div style="margin-top:8px;">
<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/11-pointers/code/use-after-free.c" style="display:inline-block;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.95em;text-decoration:none;">⚡ 在 VS Code 中打开 use-after-free.c (现场演示)</a>
</div>

</div>

<div style="flex:0.85;font-size:0.75em;line-height:1.4;">

<div class="col-label">普通编译: 看起来正常</div>

```text
$ cc use-after-free.c -o uaf
$ ./uaf
*p = 42
*p after free = 3     ← 本机; 实际是未定义行为
```

<div class="col-label" style="margin-top:6px;">AddressSanitizer: 报错</div>

```text
$ cc -g -fsanitize=address use-after-free.c -o uaf-asan
$ ./uaf-asan
==ERROR: AddressSanitizer: heap-use-after-free ...
READ of size 4 ...
    #0 main use-after-free.c:17
freed by thread T0 here:
    #1 main use-after-free.c:13
SUMMARY: AddressSanitizer: heap-use-after-free ...
```

<div style="margin-top:8px;padding:6px 10px;background:#fff4f2;border-left:4px solid #dc322f;border-radius:4px;">
- `free(p)` 不会把 p 变成 NULL; p 中仍是旧地址 (悬空指针).
- 不置 NULL 继续访问是未定义行为: 可能读到 3/42, 也可能崩溃.
- `p = NULL` 后误用会立即 NULL 解引用 (容易定位); 也允许 `free(NULL)`.
- 规则: free 后立即 `p = NULL`.
</div>

</div>

</div>

---
<!-- slide data-notes="" -->##### 完整示例: dynamic-array.c

---

<div style="display:flex;align-items:flex-start;gap:24px;">

<div class="dyn-code" style="flex:1.1;font-size:0.62em;">

<style>.dyn-code pre code{max-height:none!important;font-size:13.5px;line-height:1.2;}</style>

<div class="col-label">完整代码 · dynamic-array.c</div>

```C{.line-numbers}
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    scanf("%d", &n);

    int *a = malloc(n * sizeof(int));   /* 借 n 个 int */
    if (a == NULL) {
        printf("内存不足\n");
        return 1;
    }

    for (int i = 0; i < n; i++) a[i] = i + 1;
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");

    free(a);                            /* 用完归还 */
    a = NULL;
    return 0;
}
```

<div style="margin-top:8px;">
<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/11-pointers/code/dynamic-array.c" style="display:inline-block;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 dynamic-array.c (示例)</a>
</div>

</div>

<div style="flex:0.9;font-size:0.78em;line-height:1.45;">

<div class="col-label">样例运行</div>

```text
输入: 5
输出: 1 2 3 4 5
```

<div style="margin-top:8px;padding:6px 10px;background:#fdf6e3;border-left:4px solid #268bd2;border-radius:4px;">
- `malloc(n * sizeof(int))` 借 n 个 int
- 借不到返回 `NULL`, 必须检查
- 用完 `free(a)`, 再把 `a = NULL`
</div>

<div style="margin-top:8px;padding:6px 10px;background:#f2f4f0;border-left:4px solid #93a1a1;border-radius:4px;">
数组大小可以==运行时决定==, 不用像 `int a[10]` 那样把长度定死.
</div>

</div>

</div>

---
<!-- slide data-notes="" -->##### 任务: 动态数组逆序

---

<div style="display:flex;align-items:flex-start;gap:24px;font-size:0.68em;line-height:1.4;text-align:left;">

<div style="flex:1.1;">

==任务==: 读入 n, 用 `malloc` 建 n 个 int 的数组, 填入 1..n, 逆序输出, 最后 `free`.

样例:

```text
输入: 5
输出: 5 4 3 2 1
```

</div>

<div style="flex:0.9;">

==提示==: 参照 `dynamic-array.c`, 把输出循环改成从 n-1 到 0.

<div class="task-criteria" style="margin:8px 0 0;padding:6px 10px;background:#f2f4f0;border-left:4px solid #93a1a1;border-radius:4px;">
<b>完成标准:</b>
<div>· 用 `malloc` 申请 n 个 int, 检查 `NULL`</div>
<div>· 填入 1..n, 逆序输出</div>
<div>· 最后 `free`, 并把指针置 `NULL`</div>
</div>

<div style="margin-top:10px;">
<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/11-pointers/code/task-reverse-array.c" style="display:inline-block;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 task-reverse-array.c (骨架)</a>
</div>

</div>

</div>

---
<!-- slide data-notes="" -->##### 任务参考: 动态数组逆序

---

<div style="display:flex;align-items:flex-start;gap:24px;font-size:0.6em;line-height:1.45;text-align:left;">

<div style="flex:1.1;">

<div class="col-label">参考实现 · reverse-array.c</div>

<style>.rev-code pre code{font-size:13.5px;line-height:1.2;}</style>

<div class="rev-code">

```C{.line-numbers}
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;

    scanf("%d", &n);

    int *a = malloc(n * sizeof(int));
    if (a == NULL) {
        printf("内存不足\n");
        return 1;
    }

    for (int i = 0; i < n; i++)
        a[i] = i + 1;

    for (int i = n - 1; i >= 0; i--)
        printf("%d ", a[i]);
    printf("\n");

    free(a);
    a = NULL;
    return 0;
}
```

</div>

<div style="margin-top:8px;">
<a href="vscode://file/Users/yangyibiao/Documents/Seafile/GitRepo/yangyibiao.github.io/cpl/slides/11-pointers/code/reverse-array.c" style="display:inline-block;padding:5px 14px;background:#268bd2;color:#fff;border-radius:6px;font-size:0.85em;text-decoration:none;">⚡ 在 VS Code 中打开 reverse-array.c</a>
</div>

</div>

<div style="flex:0.9;font-size:0.78em;line-height:1.45;">

<div class="col-label">运行结果</div>

```text
输入: 5
输出: 5 4 3 2 1
```

<div style="margin-top:8px;padding:6px 10px;background:#fdf6e3;border-left:4px solid #268bd2;border-radius:4px;">
- `malloc` 申请 n 个 int, 检查 `NULL`
- 逆序循环从 `n - 1` 到 `0`
- 用完 `free(a)`, 再把 `a = NULL`
</div>

</div>

</div>

---
<!-- slide data-notes="" -->

##### 课堂小测

---

<div style="display:flex;align-items:flex-start;gap:24px;font-size:0.78em;line-height:1.6;text-align:left;">
<div style="flex:1;">
1. `int a[n];` 这种写法为什么不一定可行？动态数组应该怎么申请？

2. `malloc` 之后必须检查什么？`free` 之后为什么建议把指针置 `NULL`？

3. 内存泄漏和悬空指针有什么区别？各举一个例子。

</div>
<div style="flex:1;">
4. 动态数组逆序的关键步骤是什么？最后必须做什么？

5. 如果 `malloc` 返回 `NULL`，程序应该怎么处理？
</div>
</div>

---

<!-- slide data-notes="" -->

#####

---

<div class="bottom20"></div>

<hr class="width50 center">

## 未完待续

---
