# C++ 第2章实验

`exercises/` 包含四个独立的小题，每个 `.cpp` 有自己的 `main()`。在 Visual Studio 中，每题用一个控制台项目，或在同一项目里只将当前题加入生成。

`campus-card/` 是校园一卡通。把两个 `.cpp` 加入同一个控制台项目，`.h` 与它们放在同一目录。该项目的入口是 `CampusCardSystem.cpp`。

| 文件 | 实验 |
|---|---|
| `01_student_scores.cpp` | 学生成绩统计 |
| `02_count_vowels.cpp` | 元音统计 |
| `03_calculator.cpp` | 多功能计算器 |
| `04_swap.cpp` | 引用与指针交换 |

## 编译示例

在仓库根目录运行以下命令（GCC，C++11）。

```sh
g++ -std=c++11 exercises/01_student_scores.cpp -o scores
g++ -std=c++11 campus-card/CampusCardSystem.cpp campus-card/card_operations.cpp -o campus_card
```

一卡通输入示例。第一行是人数，之后每张卡单独一行。

```text
2
1001 LiMing 20
1002 WangHua 35.5
```

源文件统一为 UTF-8。解压后，将 README.md 和两个源码目录上传至 GitHub 仓库根目录。
