# 题目描述

交换两个变量的值，请用函数实现，**<font color="#00BB00">请使用引用传值</font>**

**<font color="#FF0000">错误的写法</font>**
```c++
void swap(int x, int y) {
    // 实现你的逻辑
}
```

**<font color="#00BB00">正确的写法</font>**
```c++
void swap(int& x, int& y) {
    // 实现你的逻辑
}
```

# 输入格式
输入一行包含 2 个整数 $x, y$（$1 \lt x, y \le 2*10^9$)，用空格分开

# 输出格式

输出一行，x 和 y 交换后的值，用空格分开

```input1
8 4
```

```output1
4 8
```
# 提示

# 数据规模与限制
* 1s, 1024KiB for each test case.
