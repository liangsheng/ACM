- [1、为什么需要高精度](#1为什么需要高精度)
- [2、字符串转 int 数组](#2字符串转-int-数组)
  - [2-1、如何输入一个位数很多的整数](#2-1如何输入一个位数很多的整数)
  - [2-2、如何将字符串转存到 int 数组](#2-2如何将字符串转存到-int-数组)
- [3、高精度加法](#3高精度加法)
  - [3-1、列式相加](#3-1列式相加)
- [4、高精度减法](#4高精度减法)

# 1、为什么需要高精度
* 大家还记得 32位整数（int）和 64 位整数（long long）的最大值是多少吗？
```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
    // 32 位整数的最大值是 2.1*10^9 左右
    cout << numeric_limits<int>::max() << '\n';

    // 64 位整数的最大值是 9.2*10^18 左右 
    cout << numeric_limits<long long>::max() << '\n';
 
    return 0
}
```
* 32 位整数的最大值是 $2.1*10^9$ 左右
* 64 位整数的最大值是 $9.2*10^{18}$ 左右 
* 如果我们要计算 2 个大于 $9.2*10^{18}$ 的数的和，要怎么办呢？

# 2、字符串转 int 数组
## 2-1、如何输入一个位数很多的整数
* 如果直接用 long long 存储超过 $9.2*10^{18}$ 的数，会怎么样？

```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a;

    // 输入 123456789876544332234567
    // 但输出 a = 9223372036854775807, 不符合预期
    cin >> a;
    cout << a << '\n';
    return 0;
}
```

* **<font color="#00BB00">可以先将输入保存到一个字符串 string 里，再将字符串里的每个字符转换成数字，存到一个 int 数组里面</font>**
* 那如何将字符 '1'（char 类型） 转换成数字 1（int 类型） 呢？
* C++ 中每个字符（char）都有一个对应的 ASCII 码（int）
* 可以通过 ch - '0' 将 ch 转换成对应的数字

| 字符 | '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9' |
| :-----| ----: | :----: | :----: | :----: | :----: | :----: | :----: | :----: | :----: | :----: |
| ASCII | 48 | 49 | 50 | 51 | 52 | 53 | 54 | 55 | 56 | 57 |

```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
    // 可以通过 int() 获取字符的 ASCII 码
    cout << int('0') << ' ' << int('1') << '\n';
    
    // '1' - '0' 实际上是 int('1') - int('0')
    // 可以通过 ch - '0' 将 ch 转换成对应的数字
    cout << '1' - '0' << '\n';
    cout << '7' - '0' << '\n';
    return 0;
}
```

## 2-2、如何将字符串转存到 int 数组
* 依次遍历 string 中的字符，转换成对应的数字，再转存到 vector<int>
```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
    // s[0] = '1', s[1] = '2', ..., s[8] = '9'
    string s = "123456789";
    
    // 将个位存在 a[0], 十位存在 a[1], ..., 与 s 相反
    // a = [9, 8, 7, 6, 5, 4, 3, 2, 1], 低位在前, 高位在后
    vector<int> a;
    for (int i = (int) s.size(); i >= 0; i--) {
        a.push_back(s[i] - '0');
    }
    for (int i = 0; i < (int) a.size(); i++) cout << a[i];
    cout << '\n';
    return 0;
}
```
* 字符串的顺序是从左往右的，也就是说 $s[0]$ 是最高位, 个位是 $s[n-1]$（假设 $s$ 的长度是 $n$）
* 如果两个数 $s = "1234"，t = "123"$，$s[0]$ 是 $s$ 的千位，而 $t[0]$ 是 $t$ 的百位，这样计算起来很不方便
* 所有我们在转存到数组 $a$ 的时候翻转下, 用 a[0] 存个位, $a[n-1]$存最高位

* **<font color="#00BB00">相比一维数组，vector<int> 有如下优势</font>**
  * vector<int> 可以动态调整长度，而一维数组在申明时就要指定长度
  * 在函数中可以申请长度很大的 vector<int>，但一维数组不行（最多申请到 $10^6$ 左右）
* 回忆下 vector<int> 的相关操作
```c++
#include <bits/stdc++.h>
using namespace std;

int main() {

    // 申请长度为 3 的 vector<int>, 初始值都是 1
    // 相当于: int a[3] = {1, 1, 1};
    vector<int> a(3, 1);

    // 输出 a 的长度: 3
    cout << a.size() << '\n';

    // 在 a 的最后插入 5, {1, 1, 1} => {1, 1, 1, 5}
    a.push_back(5);

    // 在 a 的最后插入 7, {1, 1, 1, 7} => {1, 1, 1, 5, 7}
    a.push_back(7);

    // 输出 a 的长度: 5
    cout << a.size() << '\n';

    // 删除 a 的最后一个元素，{1, 1, 1, 5, 7} => {1, 1, 1, 5}
    a.pop_back();

    // 输出 a 的第 1 个和最后 1 个元素: 1 5
    cout << a.front() << ' ' << a.back() << '\n';
    return 0;
}
```

# 3、高精度加法
## 3-1、列式相加
* 大家回忆下列示相加的过程

![img](file://高精度加法.png)

```c++
// 计算 a + b, 参数是 vector 的时候要传引用, 加 &
vector<int> add(vector<int>& a, vector<int>& b) {
    if (a.size() < b.size()) return add(b, a);  // 保证 a.size() >= b.size()
    vector<int> c = a;                          // 初始化答案 c = a
    for (int i = 0; i < (int) b.size(); i++) c[i] += b[i];   // 依次将 b[i] 加到 c[i]
    
    int d = 0;
    for (int i = 0; i < (int) a.size(); i++) {
        int sum = c[i] + d;
        c[i] = sum % 10;        // 计算当前位
        d = sum / 10;           // 计算进位
    }
    if (d > 0) c.push_back(d);  // 如果进位 > 0, 需要添加一位
    return c;
}
```

# 4、高精度减法
* 减法的步骤和加法类似，记得把进位改成借位
* 小技巧：优于结果可能是负数
  * 可以先判断 2 个数的大小，得出最后结果的正负情况
  * 然后用大数减小数

![img](file://高精度减法.png)

```c++
// a >= b: true
// a < b : false
bool cmp(vector<int>& a, vector<int>& b) {
    if (a.size() != b.size()) return a.size() > b.size();
    for (int i = (int) a.size() - 1; i >=0 ; i--) {  // 从高位开始比较
        if (a[i] != b[i]) return a[i] > b[i];
    }
    return true;
}

// 计算 a - b, 保证 a >= b
// 参数是 vector 的时候要传引用, 加 &
vector<int> sub(vector<int>& a, vector<int>& b) {
    vector<int> c = a;                          // 初始化答案 c = a
    for (int i = 0; i < (int) b.size(); i++) c[i] -= b[i];   // 依次将 c[i] 减 b[i]
    
    int d = 0;                  // 借位
    for (int i = 0; i < (int) a.size(); i++) {
        int sum = c[i] + d;     // sum 可能为负数
        if (sum < 0) c[i] = sum + 10, d = -1;
        else c[i] = sum, d = 0;
    }
    while (!c.empty() && c.back() == 0) c.pop_back();  // c 可能会有前导 0, 需要删除
    return c;
}
```