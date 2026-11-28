# MiniBuild 起始代码

这是《高级程序设计（C++）》MiniBuild 主线的第 1-2 周起始代码：一个 `Target` 类、一个简单 `main` 和一份示例 `Buildfile`。

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic target.cpp main.cpp -o minibuild
./minibuild
```

后续周次逐步加入：

- 依赖图 / 拓扑排序
- Buildfile 解析
- 文件时间戳与增量构建
- 异常与错误上下文
- 模板容器
- 并行构建
- 构建事件与观察者
