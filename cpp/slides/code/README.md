# 可运行示例

本目录保存课件中案例的完整可编译版本。`minibuild/` 是 MiniBuild 主线起始代码；`taskflow/` 是旧版 TaskFlow 参考。

## 目录

| 目录 | 内容 | 对应课件 |
| :-- | :-- | :-- |
| `minibuild/` | MiniBuild 起始版：`Target` 类、构造/析构、静态计数、`operator<<`、STL 排序 | 第 2、3、6、9、13 周（主线） |
| `taskflow/` | 旧版 `Task` 示例：封装、构造/析构、静态计数、`operator<<`、STL 排序 | 旧版参考 |
| `polymorphic_tasks/` | 抽象 `Task` 接口、`PrintTask` / `RecurringTask`、`TaskList` 独占所有权、多态执行 | 第 8、14、17 周 |

## 构建与运行

```bash
cd minibuild
g++ -std=c++17 -Wall -Wextra -Wpedantic \
    -fsanitize=address,undefined -g \
    target.cpp main.cpp -o minibuild_demo
./minibuild_demo

cd ../taskflow
g++ -std=c++17 -Wall -Wextra -Wpedantic \
    -fsanitize=address,undefined -g \
    task.cpp main.cpp -o taskflow_demo
./taskflow_demo

cd ../polymorphic_tasks
g++ -std=c++17 -Wall -Wextra -Wpedantic \
    -fsanitize=address,undefined -g \
    task.cpp task_list.cpp main.cpp -o poly_tasks_demo
./poly_tasks_demo
```

## 设计说明

### `minibuild/`

- `Target` 是 MiniBuild 主线的起始类：名称、优先级、是否已构建。
- 与旧版 `Task` 相比，下一周会把名称/优先级扩展为依赖和命令，并引入 `Graph`。

### `taskflow/`（旧版参考）

- `Task` 自己管理 `std::string`，不需要手写 `delete`。
- 为了演示 `static` 计数，自定义了拷贝构造与拷贝赋值；真实工程中若不需要计数，优先使用编译器生成的版本（Rule of Zero）。
- `Task::count()` 统计存活对象数；拷贝构造也必须计数，否则计数会失真。

### `polymorphic_tasks/`

- `Task` 是抽象接口，析构函数为 `virtual`。
- `TaskList` 通过 `std::vector<std::unique_ptr<Task>>` 独占拥有任务。
- `sorted_by_priority()` 返回 `const Task*` 的借用视图，不转移所有权。
- 新增任务类型只需继承 `Task` 并实现接口，`TaskList` / `main` 不需要修改。

## 清理

编译产物未提交；如需清理：

```bash
rm -f minibuild/minibuild_demo taskflow/taskflow_demo polymorphic_tasks/poly_tasks_demo
```
