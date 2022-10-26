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
@import "https://cdn.bootcdn.net/ajax/libs/jquery/3.5.0/jquery.js"

<!-- slide data-notes="" -->

<div class="bottom20"></div>

# C语言程序设计基础

<hr class="width50 center">

## 程序结构


<div class="bottom8"></div>

### 计算机系 &nbsp;&nbsp; 杨已彪

#### _yangyibiao@nju.edu.cn_

<!-- slide vertical=true data-notes="" -->



##### 提纲

---

- 局部变量

- 全局变量

- 程序块

- 作用域

- 构建C程序

<!-- slide vertical=true data-notes="" -->



##### 局部变量

---

在函数体中声明的变量被称为函数的局部变量: 

```C
int sum_digits(int n)
{
  int sum = 0;   /* local variable */

  while (n > 0) {
    sum += n % 10;
    n /= 10;
  }

  return sum;
}
```

<!-- slide data-notes="" -->



##### 局部变量

---

局部变量的默认性质: 

- 自动存储期限: 变量存储单元在函数==调用时自动分配==, 并在函数==返回时释放==. 

- 块作用域: 从局部变量声明的点到所在函数体的末尾是可见的. 

<!-- slide vertical=true data-notes="" -->


##### 局部变量

---

C99不要求在函数开头声明变量, 局部变量的作用域可能非常小: 

```C
void f(void)
{
  ...
  int i; // i的作用域开始点
  ...
} // i的作用域结束点
```

<!-- slide vertical=true data-notes="" -->



##### 静态局部变量

---

包含static可以使变量具有静态存储期限. 

具有静态存储期限的变量拥有永久的存储单元, 因此在整个程序执行过程中都会保留变量的值. 

例子: 
```C
void f(void)
{
  static int i;   /* static local variable */
  …
}
```

静态局部变量始终有块作用域, 所以它对其他函数不可见. 

<!-- slide vertical=true data-notes="" -->



##### 形式参数

---

形式参数与局部变量具有一样的性质: 自动存储期限和块作用域. 

函数调用时对形式参数自动初始化(分配相应实际参数的值). 


<!-- slide vertical=true data-notes="" -->



##### 外部变量

---

传递参数是将信息传递给函数的一种方式. 

函数还可以通过外部变量进行通信: 在任何函数体外声明的变量. 

外部变量有时也称为全局变量. 

<!-- slide vertical=true data-notes="" -->



##### 外部变量

---

外部变量的性质: 

- 静态存储期限

- 文件作用域

`文件作用域`意味着外部变量从声明点到所在文件的末尾都可见. 

<!-- slide vertical=true data-notes="" -->



##### 示例: 用外部变量实现栈

---

为了说明如何使用外部变量, 让我们看一下称为栈的数据结构. 

栈和数组一样, 可以存储相同类型的多个数据项. 

栈操作是受限制的: 

- 压入数据项(将它添加到一端——"栈顶")

- 弹出数据项(从同一端移走它)

禁止测试或修改不在栈顶的数据项. 

<!-- slide vertical=true data-notes="" -->



##### 示例: 用外部变量实现栈

---

在C中实现栈的一种方法是将元素存储在数组中, 我们将其称为contents. 

用名为top的一个整型变量标记栈顶的位置. 

当栈为空时, top的值为0. 

压入一个数据项: 将其存储在由top指示的位置中, 然后自增top. 

弹出一个数据项: 自减top, 然后将其作为contents的索引取回弹出的数据项. 

<!-- slide vertical=true data-notes="" -->



##### 示例: 用外部变量实现栈

---

以下程序片段声明了contents和top. 

并提供了一组表示栈操作的函数. 

所有5个函数都需要访问top变量, 其中2个函数还需要访问contents, 所以把contents和top设为外部变量. 

<!-- slide vertical=true data-notes="" -->



##### 示例: 用外部变量实现栈

---

```C
#include <stdbool.h>   /* C99 only */
 
#define STACK_SIZE 100
 
/* external variables */
int contents[STACK_SIZE];
int top = 0;
 
void make_empty(void)
{
  top = 0;
}
 
bool is_empty(void)
{
  return top == 0;
}
bool is_full(void)
{
  return top == STACK_SIZE;
}

void push(int i)
{
  if (is_full()
    stack_overflow();
  else
    contents[top++] = i;
}
 
int pop(void)
{
  if (is_empty())
    stack_underflow();
  else
    return contents[--top];
}
```

<!-- slide vertical=true data-notes="" -->



##### 外部变量的利与弊

---

当多个函数必须共享一个变量或少数几个函数共享大量变量时, 外部变量很方便. 

大多数情况下, 函数通过参数而不是通过共享变量进行通信更好: 

- 在程序维护期间, 如果改变外部变量(比如改变它的类型), 就将需要检查同一文件中的每个函数, 以确认该变化如何对函数产生影响. 

- 如果外部变量被赋了错误的值, 则可能难以确定出错的函数. 

- 依赖外部变量的函数很难在其他程序中复用. 

<!-- slide vertical=true data-notes="" -->



##### 外部变量的利与弊

---

不要在不同的函数中为不同的目的使用相同的外部变量. 

假设几个函数需要一个名为i的变量来控制for语句. 

一些程序员不是在使用i的每个函数中声明它, 而是在程序的顶部只声明一次. 

这种做法具有误导性; 稍后阅读该程序的人可能会认为i的使用彼此关联, 而实际上并非如此. 

<!-- slide vertical=true data-notes="" -->



##### 外部变量的利与弊

---

确保外部变量的名称有意义. 

局部变量并不总是需要有意义的名称: 通常很难为for循环中的控制变量想出一个比i更好的名称. 

<!-- slide vertical=true data-notes="" -->



##### 外部变量的利与弊

---

把应该是局部的变量声明为外部变量可能会导致一些错误. 

显示$10×10$星号排列的代码: 

```C
int i;
 
void print_one_row(void)
{
  for (i = 1; i <= 10; i++)
    printf("*");
}
 
void print_all_rows(void)
{
  for (i = 1; i <= 10; i++) {
    print_one_row();
    printf("\n");
  }
}
```

print_all_rows不是打印 10 行, 而是只打印1行. 


<!-- slide vertical=true data-notes="" -->



##### 程序: 猜数字

---

*guess.c*程序生成一个介于1和100之间的随机数, 用户尝试用尽可能少的次数猜出这个数: 

```
Guess the secret number between 1 and 100.
 
A new number has been chosen.
Enter guess: 55
Too low; try again.
Enter guess: 65
Too high; try again.
Enter guess: 60
Too high; try again.
Enter guess: 58
You won in 4 guesses!
Play again? (Y/N) y

A new number has been chosen.
Enter guess: 78
Too high; try again.
Enter guess: 34
You won in 2 guesses!
 
Play again? (Y/N) n
```

<!-- slide vertical=true data-notes="" -->



##### 程序: 猜数字

---

程序要执行的任务: 

- 初始化随机数生成器

- 选择一个神秘数

- 与用户交互直到选出正确数

- 每个任务都可以由一个独立的函数处理. 

<!-- slide vertical=true data-notes="" -->



##### 程序: 猜数字

---

*guess.c*

```C
/* 让用户猜一个隐藏的数字 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
#define MAX_NUMBER 100
 
/* external variable */
int secret_number;
 
/* prototypes */
void initialize_number_generator(void);
void choose_new_secret_number(void);
void read_guesses(void);

int main(void)
{
  char command;
  printf("Guess the secret number between 1 and %d.\n\n",
         MAX_NUMBER);
  initialize_number_generator();
  do {
    choose_new_secret_number();
    printf("A new number has been chosen.\n");
    read_guesses();
    printf("Play again? (Y/N) ");
    scanf(" %c", &command);
    printf("\n");
  } while (command == 'y' || command == 'Y');
 
  return 0;
}

/**********************************************************
 * initialize_number_generator: Initializes the random    *
 *                              number generator using    *
 *                              the time of day.          *
 **********************************************************/
void initialize_number_generator(void)
{
  srand((unsigned) time(NULL));   
}
 
/**********************************************************
 * choose_new_secret_number: Randomly selects a number    *
 *                           between 1 and MAX_NUMBER and *
 *                           stores it in secret_number.  *
 **********************************************************/
void choose_new_secret_number(void)
{
  secret_number = rand() % MAX_NUMBER + 1;
}

/**********************************************************
 * read_guesses: Repeatedly reads user guesses and tells  *
 *               the user whether each guess is too low,  *
 *               too high, or correct. When the guess is  *
 *               correct, prints the total number of      *
 *               guesses and returns.                     *
 **********************************************************/
void read_guesses(void)
{
  int guess, num_guesses = 0;
 
  for (;;) {
    num_guesses++;
    printf("Enter guess: ");
    scanf("%d", &guess);
    if (guess == secret_number) {
      printf("You won in %d guesses!\n\n", num_guesses);
      return;
    } else if (guess < secret_number)
      printf("Too low; try again.\n");
    else
      printf("Too high; try again.\n");
  }
}
```

<!-- slide vertical=true data-notes="" -->



##### 程序: 猜数字
---

虽然*guess.c*工作正常, 但它依赖于外部变量secret_number. 

对choose_new_secret_number和read_guesses稍作改动, 可以将secret_number移到main函数中. 

接下来是新版本的*guess.c*, 更改的部分粗体表示. 

<!-- slide vertical=true data-notes="" -->



##### 程序: 猜数字

---

*guess2.c*

```C
/* 让用户猜一个隐藏的数字 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
#define MAX_NUMBER 100
 
/* prototypes */
void initialize_number_generator(void);
int new_secret_number(void);
void read_guesses(int secret_number);

int main(void)
{
  char command;
  int secret_number;
 
  printf("Guess the secret number between 1 and %d.\n\n",
         MAX_NUMBER);
  initialize_number_generator();
  do {
    secret_number = new_secret_number();
    printf("A new number has been chosen.\n");
    read_guesses(secret_number);
    printf("Play again? (Y/N) ");
    scanf(" %c", &command);
    printf("\n");
  } while (command == 'y' || command == 'Y');
 
  return 0;
}

/**********************************************************
 * initialize_number_generator: Initializes the random    *
 *                              number generator using    *
 *                              the time of day.          *
 **********************************************************/
void initialize_number_generator(void)
{
  srand((unsigned) time(NULL));   
}
 
/**********************************************************
 * new_secret_number: Returns a randomly chosen number    *
 *                    between 1 and MAX_NUMBER.           *
 **********************************************************/
int new_secret_number(void)
{
  return rand() % MAX_NUMBER + 1;
}

/**********************************************************
 * read_guesses: Repeatedly reads user guesses and tells  *
 *               the user whether each guess is too low,  *
 *               too high, or correct. When the guess is  *
 *               correct, prints the total number of      *
 *               guesses and returns.                     *
 **********************************************************/
void read_guesses(int secret_number)
{
  int guess, num_guesses = 0;
 
  for (;;) {
    num_guesses++;
    printf("Enter guess: ");
    scanf("%d", &guess);
    if (guess == secret_number) {
      printf("You won in %d guesses!\n\n", num_guesses);
      return;
    } else if (guess < secret_number)
      printf("Too low; try again.\n");
    else
      printf("Too high; try again.\n");
  }
}
```

<!-- slide vertical=true data-notes="" -->



##### 程序块

---

在 5.2 节中, 我们遇到了以下形式的复合语句
{多条语句}

C允许包含声明的<u>复合语句</u>: 
[程序块]&emsp;{多条声明 多条语句}

这种复合语句称为程序块. 

<!-- slide vertical=true data-notes="" -->



##### 程序块

---

程序块示例: 

```C
if (i > j) {
  /* swap values of i and j */
  int temp = i;
  i = j;
  j = temp;
}
```

<!-- slide vertical=true data-notes="" -->



##### 程序块

---

默认情况下, 声明在程序块中的变量的存储期限是自动的: 进入程序块时为变量分配存储单元, 退出程序块时释放. 

该变量具有块作用域; 不能在程序块外引用. 

属于一个程序块的变量可以声明为静态的, 以赋予静态存储期限. 

<!-- slide vertical=true data-notes="" -->



##### 程序块

---

函数体是程序块. 

当需要临时使用变量时, 函数体内的程序块也很有用. 

在程序块中声明临时变量的好处: 

- 避免在函数体起始位置的声明与只是临时使用的变量相混淆. 
- 减少名字冲突. 

C99 允许在程序块的任何位置声明变量. 

<!-- slide vertical=true data-notes="" -->



##### 作用域

---

在 C 程序中, 同一个标识符可能有几种不同的含义. 

C 的作用域规则使程序员(和编译器)能够确定与程序中给定点相关的是哪种含义. 

最重要的作用域规则: 当程序块内的声明一个已经可见的标识符时, 新的声明会临时"隐藏"旧的声明, 标识符获得了新的含义. 

在程序块的末尾, 标识符恢复了它的旧含义. 

<!-- slide vertical=true data-notes="" -->



##### 作用域

---

在示例中, 标识符i有四种不同的含义: 

- 在声明 1 中, i是一个具有静态存储期限和文件作用域的变量. 
- 在声明 2 中, i是具有块作用域的形式参数. 
- 在声明 3 中, i是具有块作用域的自动变量. 
- 在声明 4 中, i也是具有块作用域的自动变量. 

每次使用时确定i的含义. 

```C
int i;         /* Declaration 1 */

void f(int i)  /* Declaration 2 */
{
  i = 1;       /* use i in 2 */
}

void g(void)
{
  int i = 2;   /* Declaration 3 */
  if (i > 0) {
    int i;     /* Declaration 4 */
    i = 3;     /* use i in 4 */
  }
  i = 4;       /* use i in 3 */
}

void h(void)
{
  i = 5;      /* use i in 1 */
}
```

<!-- slide vertical=true data-notes="" -->



##### 构建C程序

---

C程序的主要元素: 

- `#include`和`#define`等预处理指令

- 类型定义

- 外部变量的声明

- 函数原型

- 函数定义

<!-- slide vertical=true data-notes="" -->



##### 构建C程序
---

C仅对这些项目的顺序施加了一些规则: 

- 预处理指令直到它出现的行才会生效. 

- 类型名定义后才能使用. 

- 变量声明后才能使用. 

C99要求在第一次调用之前定义或声明每个函数. 

<!-- slide vertical=true data-notes="" -->



##### 构建C程序
---

为了遵守这些规则, 有几种构建程序的方法. 一种可能的顺序: 

- #include指令

- #define指令

- 类型定义

- 外部变量的声明

- main以外的函数原型

- main函数的定义

- 其他函数的定义

<!-- slide vertical=true data-notes="" -->



##### 构建C程序

---

在每个函数定义之前有一个盒型注释是个好的编码风格. 

要包含在注释中的信息: 

- 函数名

- 函数的目的

- 每个形式参数的含义

- 返回值说明(如果有)

- 副作用说明(如修改外部变量)

<!-- slide vertical=true data-notes="" -->



##### 程序: 给一手牌分类

---

*poker.c*程序将对一手牌进行分类. 

手中的每张牌都有花色和等级. 

- 花色: 梅花, 方块, 红心, 黑桃

- 等级: 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K, A

没有王牌, 假设A是最高等级. 

程序在读取五张牌后, 将使用下一张幻灯片上的类别对牌进行分类. 

如果一手牌属于两个或更多类别, 程序将选择最好的一个. 

<!-- slide vertical=true data-notes="" -->



##### 程序: 给一手牌分类

---

类别(列出的顺序从最好到最差): 

- 同花顺(顺序相连且同花色)

- 四张(4张牌等级相同)

- 葫芦(3张牌是同样的花色, 另外2张牌是同样的花色)

- 同花(5张牌同花色)

- 顺子(5张牌的等级顺序相连)

- 三张(3张牌的等级相同)

- 两对

- 一对(2张牌的等级相同)

- 高牌(任何其他情况的牌)

<!-- slide vertical=true data-notes="" -->



##### 程序: 给一手牌分类

---

为了便于输入, 等级和花色简化为单个字母: 

```
等级:  2 3 4 5 6 7 8 9 t j q k a
花色:  c d h s
```

如果用户输入非法牌或尝试输入同一张牌两次时要采取的措施: 

- 忽略此牌

- 产生错误消息

- 要求输入另一张牌

输入数字0将导致程序终止. 

<!-- slide vertical=true data-notes="" -->



##### 程序: 给一手牌分类

---

该程序的示例会话: 

```C
Enter a card: 2s
Enter a card: 5s
Enter a card: 4s
Enter a card: 3s
Enter a card: 6s
Straight flush
Enter a card: 8c
Enter a card: as
Enter a card: 8c
Duplicate card; ignored.
Enter a card: 7c
Enter a card: ad
Enter a card: 3h
Pair
Enter a card: 6s
Enter a card: d2
Bad card; ignored.
Enter a card: 2d
Enter a card: 9c
Enter a card: 4h
Enter a card: ts
High card
 
Enter a card: 0
```

<!-- slide vertical=true data-notes="" -->



##### 程序: 给一手牌分类

---

该程序具有三个任务: 

- 读入一手5张牌
- 分析手牌的对子, 顺子等情况
- 打印一手牌的分类

函数read_cards, analyze_hand和print_result将完成这些任务. 

main只负责在无限循环中调用这些函数. 

<!-- slide vertical=true data-notes="" -->



##### 程序: 给一手牌分类

---
这些函数需要共享大量信息, 因此我们将让它们通过外部变量进行通信. 

read_cards会将一手牌的信息存储到几个外部变量中. 

analyze_hand将检查这些变量, 将结果分类存储到其他外部变量中, 以供print_result 使用. 

<!-- slide vertical=true data-notes="" -->



##### 程序: 给一手牌分类

---

程序轮廓: 

```C
/* #include directives go here */
/* #define directives go here */
/* declarations of external variables go here */
/* prototypes */
void read_cards(void);
void analyze_hand(void);
void print_result(void);
/********************************************************** 
 * main: Calls read_cards, analyze_hand, and print_result * 
 *       repeatedly.                                      * 
 **********************************************************/
int main(void)
{
  for (;;) {
    read_cards();
    analyze_hand();
    print_result();
  }
}
 
/********************************************************** 
 * read_cards:  Reads the cards into external variables;  * 
 *              checks for bad cards and duplicate cards. * 
 **********************************************************/
void read_cards(void)
{
  …
}

/********************************************************** 
 * analyze_hand: Determines whether the hand contains a   * 
 *               straight, a flush, four-of-a-kind,       * 
 *               and/or three-of-a-kind; determines the   * 
 *               number of pairs; stores the results into * 
 *               external variables.                      * 
 **********************************************************/
void analyze_hand(void)
{
  …
}
 
/********************************************************** 
 * print_result: Notifies the user of the result, using   * 
 *               the external variables set by            * 
 *               analyze_hand.                            *
 **********************************************************/
void print_result(void)
{
  …
} 
```

<!-- slide vertical=true data-notes="" -->



##### 程序: 给一手牌分类

---

我们应该如何表示一手牌?

analyze_hand需要知道每个等级和每个花色的牌的数量. 

建议使用两个数组, num_in_rank和num_in_suit. 

- num_in_rank[r]是等级为r的牌的数量. 
- num_in_suit[s]是花色为s的牌的数量. 

我们将等级编码为0到12之间的数字. 

花色编码为0到3之间的数字. 

<!-- slide vertical=true data-notes="" -->



##### 程序: 给一手牌分类

---

我们还需要第三个数组card_exists, 以便read_cards可以检测到重复的牌. 

每次read_cards读取等级为r且花色为s的牌时, 它都会检查card_exists[r][s]的值是否为真. 

- 如果是, 则该牌先前已输入. 
- 如果不是, read_cards将true分配给card_exists[r][s]. 

<!-- slide vertical=true data-notes="" -->



##### 程序: 给一手牌分类

---

read_cards函数和analyze_hand函数都需要访问num_in_rank和num_in_suit数组, 因此这两个数组须是外部变量. 

card_exists数组仅由read_cards使用, 因此声明为函数的局部变量. 

通常, 仅在必要时才将变量设置为外部变量. 


<!-- slide vertical=true data-notes="" -->



##### 程序: 给一手牌分类

---

*poker.c*

```C
/* Classifies a poker hand */
 
#include <stdbool.h>   /* C99 only */
#include <stdio.h>
#include <stdlib.h>
 
#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

/* external variables */
int num_in_rank[NUM_RANKS];
int num_in_suit[NUM_SUITS];
bool straight, flush, four, three;
int pairs;   /* can be 0, 1, or 2 */
/* prototypes */
void read_cards(void);
void analyze_hand(void);
void print_result(void);
 
/********************************************************** 
 * main: Calls read_cards, analyze_hand, and print_result * 
 *       repeatedly.                                      * 
 **********************************************************/
int main(void)
{
  for (;;) {
    read_cards();
    analyze_hand();
    print_result();
  }
}

/********************************************************** 
 * read_cards: Reads the cards into the external          * 
 *             variables num_in_rank and num_in_suit;     * 
 *             checks for bad cards and duplicate cards.  * 
 **********************************************************/
void read_cards(void)
{
  bool card_exists[NUM_RANKS][NUM_SUITS];
  char ch, rank_ch, suit_ch;
  int rank, suit;
  bool bad_card;
  int cards_read = 0;
 
  for (rank = 0; rank < NUM_RANKS; rank++) {
    num_in_rank[rank] = 0;
    for (suit = 0; suit < NUM_SUITS; suit++) 
      card_exists[rank][suit] = false;
  }
 
  for (suit = 0; suit < NUM_SUITS; suit++) 
    num_in_suit[suit] = 0;
  while (cards_read < NUM_CARDS) {
    bad_card = false;
 
    printf("Enter a card: ");
 
    rank_ch = getchar();
    switch (rank_ch) {
      case '0':           exit(EXIT_SUCCESS);
      case '2':           rank = 0; break;
      case '3':           rank = 1; break;
      case '4':           rank = 2; break;
      case '5':           rank = 3; break;
      case '6':           rank = 4; break;
      case '7':           rank = 5; break;
      case '8':           rank = 6; break;
      case '9':           rank = 7; break;
      case 't': case 'T': rank = 8; break;
      case 'j': case 'J': rank = 9; break;
      case 'q': case 'Q': rank = 10; break;
      case 'k': case 'K': rank = 11; break;
      case 'a': case 'A': rank = 12; break;
      default:            bad_card = true;
    }
    suit_ch = getchar();
    switch (suit_ch) {
      case 'c': case 'C': suit = 0; break;
      case 'd': case 'D': suit = 1; break;
      case 'h': case 'H': suit = 2; break;
      case 's': case 'S': suit = 3; break;
      default:            bad_card = true;
    }
 
    while ((ch = getchar()) != '\n')
      if (ch != ' ') bad_card = true;
 
    if (bad_card)
      printf("Bad card; ignored.\n");
    else if (card_exists[rank][suit])
      printf("Duplicate card; ignored.\n");
    else {
      num_in_rank[rank]++;
      num_in_suit[suit]++;
      card_exists[rank][suit] = true;
      cards_read++;
    }
  }
}

/********************************************************** 
 * analyze_hand: Determines whether the hand contains a   * 
 *               straight, a flush, four-of-a-kind,       * 
 *               and/or three-of-a-kind; determines the   * 
 *               number of pairs; stores the results into * 
 *               the external variables straight, flush,  * 
 *               four, three, and pairs.                  * 
 **********************************************************/
void analyze_hand(void)
{
  int num_consec = 0;
  int rank, suit;
  straight = false;
  flush = false;
  four = false;
  three = false;
  pairs = 0; 
 /* check for flush */
  for (suit = 0; suit < NUM_SUITS; suit++)
    if (num_in_suit[suit] == NUM_CARDS)
      flush = true;

  /* check for straight */
  rank = 0;
  while (num_in_rank[rank] == 0) rank++;
  for (; rank < NUM_RANKS && num_in_rank[rank] > 0; rank++)
    num_consec++;
  if (num_consec == NUM_CARDS) {
    straight = true;
    return;
  }

  /* check for 4-of-a-kind, 3-of-a-kind, and pairs */
  for (rank = 0; rank < NUM_RANKS; rank++) {
    if (num_in_rank[rank] == 4) four = true;
    if (num_in_rank[rank] == 3) three = true;
    if (num_in_rank[rank] == 2) pairs++;
  }
}

/********************************************************** 
 * print_result: Prints the classification of the hand,   * 
 *               based on the values of the external      * 
 *               variables straight, flush, four, three,  * 
 *               and pairs.                               * 
 **********************************************************/
void print_result(void)
{
  if (straight && flush) printf("Straight flush");
  else if (four)         printf("Four of a kind");
  else if (three &&
           pairs == 1)   printf("Full house");
  else if (flush)        printf("Flush");
  else if (straight)     printf("Straight");
  else if (three)        printf("Three of a kind");
  else if (pairs == 2)   printf("Two pairs");
  else if (pairs == 1)   printf("Pair");
  else                   printf("High card");
 
  printf("\n\n");
}
```
