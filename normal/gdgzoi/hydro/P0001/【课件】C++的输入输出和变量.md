- [1、你的第一个C++程序](#1你的第一个c程序)
  - [1-1、Hello World!](#1-1hello-world)
- [2、变量的类型，运算和转换](#2变量的类型运算和转换)
  - [2-1、C++中的变量类型](#2-1c中的变量类型)
  - [2-2、创建变量并赋值](#2-2创建变量并赋值)
    - [2-2-1、【实战应用】交换两个变量的值](#2-2-1实战应用交换两个变量的值)
  - [2-3、变量的输入输出](#2-3变量的输入输出)
  - [2-4、变量的四则运算运算](#2-4变量的四则运算运算)
    - [2-4-1、运算结果与类型判断](#2-4-1运算结果与类型判断)
    - [2-4-2、整数除法与取余](#2-4-2整数除法与取余)
    - [2-4-3、运算后给自身赋值](#2-4-3运算后给自身赋值)
    - [2-4-4、【实战练习】翻转三位数](#2-4-4实战练习翻转三位数)
  - [2-5、关系运算符](#2-5关系运算符)
  - [2-6、逻辑运算符](#2-6逻辑运算符)
  - [2-7、运算优先级](#2-7运算优先级)
  - [2-8、强制类型转换](#2-8强制类型转换)

# 1、你的第一个C++程序

## 1-1、Hello World!

* [安装 DevC++](http://gdgzoi.com/news.php?id=1046)
* ![image](file://新建源代码.jpg)
* 输入代码
```c++
#include <bits/stdc++.h>  // 头文件, 类似 python 的 import
using namespace std;  // 暂时不用理解

int main() {
    // 代码逻辑从这里开始

    // cout 用于在屏幕上打印出数据
    // endl 表示打印完后换行
    // 枚举代码结束要以 ; 结束, 是英文分号, 不要写中文分号
	cout << "Hello World!" << endl;

    // 代码逻辑在这里结束
	return 0;
} 
```
* 需要注意的是
  * // 后面的部分是注释，注释用来帮助阅读者更好理解程序，程序不执行注释部分
  * endl，表示换行，如果不写，后面输出的内容就会和这一行连在一起
  * **<font color="#FF0000">每句话都要以分号结尾</font>**，如果不加分号，系统会提示编译错误
  * **<font color="#FF0000">程序中不能有中文标点</font>**
* ![image](file://运行代码.jpg)
* ![image](file://运行成功.jpg)

# 2、变量的类型，运算和转换
* 一段代码最基础的功能包括**<font color="#FF0000">存储数据和计算</font>**
* 存储数据体现在代码里面，就是变量

## 2-1、C++中的变量类型
* 要在 C++ 中存放数据，首先要确定数据的类型。常见的基本数据类型有以下五种

| 代码 | 含义 | 范围 | 例子 |
| :-----| ----: | :----: | :----: |
| int | 整数 | [—2147483648, 2147483647] | int a = 1; |
| long long | 大整数 | [$-9.22*10^{18}, 9.22*10^{18}$] | long long a = 1; |
| double | 小数 | [$-\infty, \infty$] | double a=3.14; |
| char | 单个字符 | 'a'-'z', 'A'-'Z', '0'-'9'等 | char a='a'; |
| bool | 逻辑值 | false 是假, true 是真 | bool a=true; |
| string | 字符串 | 双引号包含 | string a="Hello"; |

## 2-2、创建变量并赋值
* 为了在内存中存储数据，可以创建变量
* 创建变量时，需要指定变量的类型，以及给变量命名
```c++
#include <bits/stdc++.h>  // 头文件, 类似 python 的 import
using namespace std;  // 暂时不用理解

int main() {
    // 代码逻辑从这里开始

    // 创建了一个整数变量, 其名字叫做 dog, 类型是 int
    int dog;

    // 代码逻辑在这里结束
	return 0;
}
```
* 变量命名规则
  * 一般使用的变量名以字符开头，后面跟若干字符，或者数字，或者下划线
  * C++ 语言区分大小写，例如，facebook 和 faceBook 是不同的变量
  * C++ 关键字例如 int double 都不能用作变量名
* 更多变量申明的例子
```c++
#include <bits/stdc++.h>  // 头文件, 类似 python 的 import
using namespace std;  // 暂时不用理解

int main() {
    // 代码逻辑从这里开始

    // 可以在一个语句中定义多个相同类型的变量
    int cat, dog;  // 两个变量都是 int 类型

    // 会报错, 变量名不能重复
    // int cat;

    // 在定义变量时可以给变量赋值
    int a = 10;  // a 中初始存放的值是 10

    // 在变量赋值的时候，可以使用前面定义过的变量
    int x = 11, y = 20;
    int difference = y - x;

    // 定义变量后可以随时改变变量的值，再次使用该变量是使用它最新的值
    int year = 2022;
    year = year + 1;  // 执行之后 year 变为 2023
    year = year + 1;  // 执行之后 year 变为 2024

    // 定义一个 double 类型 d_x, 初始值是 3.1415926
    double d_x = 3.1415926;

    // 定义一个 char 类型 c, 初始值是 'c'
    // char 类型的变量的值要用单引号包住
    char c = 'c';

    // 定义一个 string(字符串) 类型变量
    // 字符串类型的值要用双引号包住
    string s = "Hello World";

    // 定义一个 bool 类型变量, 初始值是 true(真)
    bool b = true;

    // 代码逻辑在这里结束
	return 0;
}
```
### 2-2-1、【实战应用】交换两个变量的值
* 交换两个 int 变量 a 和 b 的值，最简单的方法是借助第三个变量
```c++
#include <bits/stdc++.h>  // 头文件, 类似 python 的 import
using namespace std;  // 暂时不用理解

int main() {
    // 代码逻辑从这里开始

    int a = 1, b = 2;
    cout << "交换前, a= " << a << ", b= " << b << endl;

    int c = a;
    a = b;
    b = c;

    cout << "交换后, a= " << a << ", b= " << b << endl;
    // 代码逻辑在这里结束
	return 0;
}
```

## 2-3、变量的输入输出
* 可以用 cin 操作，从用户的输入读取变量的值
  * 在一行输入多个变量时，用空格分开，然后回车
* 可以用 cout 操作，将变量的值打印在屏幕上
```c++
#include <bits/stdc++.h>  // 头文件, 类似 python 的 import
using namespace std;  // 暂时不用理解

int main() {
    // 代码逻辑从这里开始

    // 输入 1 个变量的值
    // 在屏幕上输入 1 个整数, 然后回车
    int a;
    cin >> a;
    cout << "a= " << a << endl;

    // 输入 2 个变量的值
    // 在屏幕上输入 2 个整数(用空格分开), 然后回车
    int x, y;
    cin >> x >> y;
    cout << "x= " << x << ", y= " << y << endl;

    // 输出 double 类型值, 并保留有效数字
    double pi = 3.141592653;
    cout << pi << endl;
    cout << "保留 2 位小数, pi= " << fixed << setprecision(2) << pi << endl;
    cout << "保留 3 位小数, pi= " << fixed << setprecision(3) << pi << endl;
    // 代码逻辑在这里结束
	return 0;
}
```
## 2-4、变量的四则运算运算
* 常见的变量运算有 +(加),-(减),*(乘),/(商),%(取余)
* 
### 2-4-1、运算结果与类型判断
* 针对 int, long long, double 类型变量
* 同类型的变量，运算的结果类型不变
* 不同类型的变量，运算结果的类型按如下规则
  * **<font color="#FF0000">如果参加运算的数中有至少一个 double，那运算结果的类型就为 double</font>**
  * **<font color="#FF0000">否则，如果参加运算的数中有至少一个 long long，那运算结果的类型就为 long long</font>**
```c++
#include <bits/stdc++.h>  // 头文件, 类似 python 的 import
using namespace std;  // 暂时不用理解

int main() {
    // 代码逻辑从这里开始

    // 同类型变量运算, 结果类型不变
    int a = 1, b = 5;
    cout << a + b << endl;

    // 参加运算的变量有一个是 double, 那么结果就是 double
    int x = 1;
    double y = 3.14;
    cout << x + y << endl;

    // 参加运算的变量有一个是 long long, 那么结果就是 long long
    int c = 1;
    long long d = 2300000000;
    cout << c + d << endl;

    // 如果 2 个 int 类型变量的运算结果超出了 int 的范围
    // 要将其中一个变量转换成 long long 或者 double, 再运算
    int p = 123456, q = 654321;
    // 答案显示 -824525248, 是错误的
    cout << p * q << endl;
    // 先把其中一个转换成 long long, 再计算;
    // 显示 80779853376, 正确
    cout << (long long) p * q << endl;
    // 显示 8.07799e+10, 正确
    cout << (double) p * q << endl;
    // 代码逻辑在这里结束
	return 0;
}
```
* **<font color="#FF0000">还需要注意的是，如果 2 个 int 类型变量的运算结果超出了 int 的范围，要将其中一个变量转换成 long long 或者 double, 再运算</font>**
```c++
int p = 123456, q = 654321;
cout << (long long) p * q << endl;  // 将 p 转化成 long long 再计算
cout << (double) p * q << endl;  // 将 p 转化成 double 再计算

```

### 2-4-2、整数除法与取余
* 在 C++ 中，两个整数的除法运算使用带余除法，以商作为结果，不保留余数
* 如果想求余数，C++ 还支持取余运算 % (称为模)
```c++
#include <bits/stdc++.h>  // 头文件, 类似 python 的 import
using namespace std;  // 暂时不用理解

int main() {
    // 代码逻辑从这里开始

    int a = 7, b = 4;
    int p = a / b;  // p = 1, 是商
    int q = a % b;  // q = 3, 是余数
    cout << "7 / 4 的商是: " << p << ", 余数是: " << q << endl;

    // 如果想得到小数答案, 可以通过 a * 1.0, 先将 a 转成 double
    // double / int 的结果就是 double 了
    double ans = a * 1.0 / b;  // ans = 1.75
    cout << "7 / 4 的小数解是: " << ans << endl;

    // 代码逻辑在这里结束
	return 0;
}
```

### 2-4-3、运算后给自身赋值
* C++ 提供了如下的简写运算
  
| 简写 | 等同于 | 简写 | 等同于 |
| :-----| ----: | :----: | :----: |
| a += b; | a = a + b; | a -= b; | a = a - b; |
| a *= b; | a = a * b; | a /= b; | a = a / b; |
| a %= b; | a = a % b; |  |  |
* 特别的
  * a++; 和 ++a; 都表示 a = a + 1
  * 两者的区别参考下面的代码
  * a--; 和 --a; 同理
```c++
#include <bits/stdc++.h>  // 头文件, 类似 python 的 import
using namespace std;  // 暂时不用理解

int main() {
    // 代码逻辑从这里开始
    
    int a = 1, b = 3;
    a += b;  // 等同于 a = a + b;

    int x = 1, y = 1;
    cout << "x= " << x << ", (x++)=" << (x++) << ", x++之后 x 的值: " << x << endl;
    cout << "y= " << y << ", (++y)=" << (++y) << ", ++y之后 y 的值: " << x << endl;
    
    // 代码逻辑在这里结束
	return 0;
}
```
* 上面的代码会输出
  * x= 1, (x++)=1, x++之后 x 的值: 2
  * y= 1, (++y)=2, ++y之后 y 的值: 2
* **<font color="#FF0000">a++; 的返回值是 a 原来的值, 而 ++a; 的返回值是 a 加完 1 之后的值, 也就是 a + 1</font>**
  * 返回值的概念，在函数里会学到

### 2-4-4、【实战练习】翻转三位数
* 请读入一个三位正整数，前后翻转并输出
```c++
#include <bits/stdc++.h>  // 头文件, 类似 python 的 import
using namespace std;  // 暂时不用理解

int main() {
    // 代码逻辑从这里开始
    
    int n;
    cin >> n;

    // 考虑 n = 123, 个位数是 123 % 10 = 3;
    int a = n % 10;
    // 十位数是 123 / 10 % 10 = 12 % 10 = 2;
    int b = n / 10 % 10;
    // 百位数是 123 / 100 % 10 = 1 % 10 = 1;
    int c = n / 100 % 10;

    cout << a * 100 + b * 10 + c << endl;
    
    // 代码逻辑在这里结束
	return 0;
}
```

## 2-5、关系运算符
* C++ 中的关系运算符用于判断两个值的关系是否成立
* 得到的答案是 bool 类型，成立得到 true，不成立得到 false

| 运算符 | 含义 | 
| :-----| ----: |
| < | 判断前面的值是否小于后面的值 |
| <= | 判断前面的值是否小于等于后面的值 |
| > | 判断前面的值是否大于后面的值 |
| >= | 判断前面的值是否大于等于后面的值 |
| == | 判断两边的值是否相等 |
| != | 判断两边的值是否不等 |

## 2-6、逻辑运算符
* C++ 中的逻辑运算符对两个 bool 值做运算，生成一个 bool 值

| 名称 | 形式 | 含义 |
| :-----| :---- | :----- |
| 与运算符 | a && b | 仅当a和b都为真时，才为真，否则为假 |
| 或运算符 | a \|\| b | 仅当a和b都为假时，才为假，否则为真 |
| 非运算符 | !a | 仅当a为假时，才为真，否则为假 | 
* 短路逻辑判断
  * 如果 a && b 的计算过程中发现 a 为假，不再计算，因为结果肯定是假
  * 如果 a || b 的计算过程中发现 a 为真，不再计算 b，应为就是肯定是真
 
## 2-7、运算优先级
* 常见的运算优先级可以概括如下，同一格子优先级相同，左边格子高于右边格子

| 1 | 2 | 3 | 4 | 5 | 6 | 7 |
| :-----| :---- | :----- | :----- | :----- | :----- | :----- |
| ! | *,/,% | +,- | <, <=, >, >= | ==, != | && | \|\| \

* 不用死记硬背
* 如果拿不准运算优先级，初学者可以先多加些括号

## 2-8、强制类型转换
* 强制类型转换，说的是把一种类型的变量，转化成另一种类型的变量
* int, long long, double 之间的转换
* 需要注意的是:
  * int 转成 long long 和 double 没有问题
  * **<font color="#FF0000">long long 转成 int 可能会超出 int 范围</font>**
  * **<font color="#FF0000">double 转成 int 也可能会超出 int 范围, 并且只会保留整数部分, 丢失小数部分</font>**
```c++
#include <bits/stdc++.h>  // 头文件, 类似 python 的 import
using namespace std;  // 暂时不用理解

int main() {
    // 代码逻辑从这里开始
    
    int a = 123;
    cout << "a= " << a << endl;

    // 将 int 转换成 long long
    // 也可以写成 long long b = a * 1LL;
    long long b = (long long) a;
    cout << "将 a 转换成 long long: " << b << endl;

    // 将 int 转换成 double
    // 也可以写成 double c = a * 1.0;
    double c = (double) a;
    cout << "将 a 转换成 double: " << c << endl;
    
    // 将 long long 转化成 int, 可能会出错
    // 应为 long long 的范围比 int 大
    long long x = 2200000000;
    // 输出 -2094967296, 错误
    cout << (int) x << endl;

    // 将 double 转换成 int, 会丢失精度, 只保留整数部分
    double y = 3.14;
    // 输出 3
    cout << (int) 3.14 << endl;

    // 代码逻辑在这里结束
	return 0;
}
```
* int 和 bool 之间的转换
```c++
#include <bits/stdc++.h>  // 头文件, 类似 python 的 import
using namespace std;  // 暂时不用理解

int main() {
    // 代码逻辑从这里开始
    
    // bool 转 int, true -> 1, false -> 0
    bool a = true, b = false;
    // 输出 1 0
    cout << (int) a << " " << (int) b << endl;

    // int 转 bool, 0 -> false, 任何非 0 值 -> 1
    int x = 0, y = 12, z = -345;
    // 输出 0 1 1
    cout << (bool) x << " " << (bool) y << " " << (bool) z << endl;
    // 代码逻辑在这里结束
	return 0;
}
```
* int 和 char 之间的转换
  * 'a' 到 'z', 对应 97 到 122
  * 'A' 到 'Z', 对应 65 到 90
  * '0' 到 '9', 对应 48 到 57
```c++
#include <bits/stdc++.h>  // 头文件, 类似 python 的 import
using namespace std;  // 暂时不用理解

int main() {
    // 代码逻辑从这里开始
    
    // char 转 int
    cout << (int) 'a' << endl;
    cout << (int) 'c' << endl;
    cout << (int) 'z' << endl;

    cout << (int) 'A' << endl;
    cout << (int) 'C' << endl;
    cout << (int) 'Z' << endl;

    cout << (int) '0' << endl;
    cout << (int) '3' << endl;
    cout << (int) '9' << endl;

    // int 转 char
    cout << (char) 97 << endl;
    cout << (char) 99 << endl;
    cout << (char) 122 << endl;

    cout << (char) 65 << endl;
    cout << (char) 67 << endl;
    cout << (char) 90 << endl;

    cout << (char) 48 << endl;
    cout << (char) 51 << endl;
    cout << (char) 57 << endl;

    // 代码逻辑在这里结束
	return 0;
}
```