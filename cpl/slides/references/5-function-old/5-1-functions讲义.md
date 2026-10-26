## leap.c（封装）
1. 函数命名IsLeapYear
2. 函数定义
3. 返回类型(bool, stdbool.h)
4. 函数声明(隐式默认返回值为int) 
5. 形式参数
6. 变量作用域(不同函数中相同leap)

## primes.c（封装）
1. return语句简化代码
2. 是否提前结束循环

## stars.c (复用)
1. 演示代码复用（大段拷贝、简单修改）
2. void类型（无返回）
3. 多个参数，逗号隔开

## binary-search.c
1. 数组作为函数参数[] int BinarySearch(int key, int arr[], int len);
2. 解释为什么不能直接传长度信息，数组第一个元素的地址，数组首地址
3. 实现该函数
4. const int arr[]
5. 实参如果是const
6. 用return优化
7. 8行dict全局变量，文件作用域
8. 放入main函数作为局部变量

---

## palindrome.c
1. 字符数组，可以不传长度信息

## selection-sort.c
1. 封装getminindex
2. 封装swap（解释封装没有效果）
3. 解释selectionsort中为什么有效果

## merge.c
1. 两个数组，两个长度

## game-of-life.c
1. 为什么二维数组第二个要传第二维信息
2. 板书：arr[3]是如何寻址
3. 板书：arr[3][4]如何寻址