- [1、什么是 STL 库](#1什么是-stl-库)
- [2、常用数学函数](#2常用数学函数)
- [3、迭代器](#3迭代器)
- [4、pair 类型](#4pair-类型)
- [5、序列容器](#5序列容器)
  - [5-1、vector](#5-1vector)
  - [5-2、deque](#5-2deque)
  - [5-3、queue](#5-3queue)
  - [5-4、stack](#5-4stack)
  - [5-5、priority\_queue](#5-5priority_queue)
- [6、关联容器](#6关联容器)
  - [6-1、set](#6-1set)
  - [6-2、map](#6-2map)

# 1、什么是 STL 库
* STL 即标准模板库（Standard Template Library），是 C++ 标准库的一部分，里面包含了一些模板化的通用的数据结构和算法，**<font color="#FF0000">可以极大简化代码</font>**
* **<font color="#FF0000">所以，大家务必从头到尾仔细阅读本课件，你会发现原来写代码可以这么简单</font>**

# 2、常用数学函数
* max, min, abs, floor, ceil, round, sqrt 具体见如下代码
```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a = 1, b = 3;
    double c = 2.0;

    // max(a, b), 用于返回 a, b 中较大的值
    // 注意: a, b 一定要是同类型的值
    // 输出: max(a, b)返回 a, b 中较大的数是: 3
    cout << "max(a, b)返回 a, b 中较大的数是: " << max(a, b) << '\n';
    // 错误: a 是 int, c 是 double, 会报编译错误
    // cout << max(a, c) << '\n';
    cout << '\n';

    // min(a, b), 用于返回 a, b 中较小的值
    // 注意: a, b 一定要是同类型的值
    // 输出: min(a, b)返回 a, b 中较小的数是: 1
    cout << "min(a, b)返回 a, b 中较小的数是: " << min(a, b) << '\n';
    cout << '\n';

    // abs(a) 返回 a 的绝对值
    // 输出: abs(1.2) 返回 1.2 的绝对值是: 1.2
    cout << "abs(1.2) 返回 1.2 的绝对值是: " << abs(1.2) << '\n';
    // 输出: abs(-1.2) 返回 -1.2 的绝对值是: 1.2
    cout << "abs(-1.2) 返回 -1.2 的绝对值是: " << abs(-1.2) << '\n';
    cout << '\n';

    // floor(x) 返回不超过 x 的最大 int 值
    // 输出: floor(5) 返回不超过 5 的最大整数是: 5
    cout << "floor(5) 返回不超过 5 的最大整数是: " << floor(5) << '\n';
    // 输出: floor(5.9) 返回不超过 5.9 的最大整数是: 5
    cout << "floor(5.9) 返回不超过 5.9 的最大整数是: " << floor(5.9) << '\n';
    // 输出: floor(-5.9) 返回不超过 -5.9 的最大整数是: -6
    cout << "floor(-5.9) 返回不超过 -5.9 的最大整数是: " << floor(-5.9) << '\n';
    cout << '\n';

    // ceil(x) 返回不小于 x 的最大 int 值
    // 输出: ceil(5) 返回不小于 5 的最大整数是: 5
    cout << "ceil(5) 返回不小于 5 的最大整数是: " << ceil(5) << '\n';
    // 输出: ceil(5.9) 返回不小于 5.9 的最大整数是: 6
    cout << "ceil(5.9) 返回不小于 5.9 的最大整数是: " << ceil(5.9) << '\n';
    // 输出: ceil(-5.9) 返回不小于 -5.9 的最大整数是: -5
    cout << "ceil(-5.9) 返回不小于 -5.9 的最大整数是: " << ceil(-5.9) << '\n';    
    cout << '\n';

    // round(x) 用于返回 x 四舍五入后的结果
    // 输出: round(5.4)=5
    cout << "round(5.4)=" << round(5.4) << '\n';
    // 输出: round(5.5)=6
    cout << "round(5.5)=" << round(5.5) << '\n';
    // 输出: round(-5.4)=-5
    cout << "round(-5.4)=" << round(-5.4) << '\n';
    // 输出: round(-5.5)=-6
    cout << "round(-5.5)=" << round(-5.5) << '\n'; 
    cout << '\n';

    // sqrt(x) 返回 x 开方的结果
    // 输出: sqrt(9)=3
    cout << "sqrt(9)=" << sqrt(9) << '\n';
    // 输出: sqrt(10)=3.16228
    cout << "sqrt(10)=" << sqrt(10) << '\n';   
    return 0;
}
```

# 3、迭代器
* 我们在 [【课件】指针与函数](http://www.gzezoi.cn/d/gzezoi2023/p/P0004) 中学习过数组和指针的关系（回忆下，数组名就是指向数组第一个元素的指针）
* 对于向量容器 vector 来说, 迭代器就是 vector 的指针，可以用来标记 vector 中的某个位置
```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a;
    for (int i = 0; i < 5; i++) a.push_back(i * 2);
    
    // 输出: 0 2 4 6 8
    for (int i = 0; i < a.size(); i++) cout << a[i] << ' ';
    cout << '\n';
    
    // a.beign() 返回指向 a[0] 的指针
    // 可以通过 *a.beign() 来获取 a[0] 的值
    cout << *a.begin() << '\n';           // 输出: 0

    // 迭代器可以做加法, 返回 a[1] 的值
    cout << *(a.begin() + 1) << '\n';     // 输出: 2

    // 返回 a[2] 的值
    cout << *(a.begin() + 2) << '\n';     // 输出: 4

    // a.end() 指向末尾元素的后一个(不存在的)元素
    // 可以通过 a.end() - a.begin() 计算 a 中元素的个数
    // 也可以用 a.size()
    cout << a.end() - a.begin() << '\n';  // 输出: 5
    
    // 可以通过迭代器来遍历 a
    // auto 可以代指任意类型
    // 输出: 0 2 4 6 8
    for (auto i = a.begin(); i != a.end(); i++) cout << *i << ' ';
    cout << '\n';

    // 下面的方法更简单
    // 输出: 0 2 4 6 8
    for (int x: a) cout << x << ' ';
    cout << '\n';

    // 也可以把 int x 换成 auto x
    // 输出: 0 2 4 6 8
    for (auto x: a) cout << x << ' ';
    cout << '\n';
    return 0;
}
```

* 可以通过 max_element(a.begin(), a.end())，返回 a 中的最大值的迭代器
* 可以通过 reverse(a.begin(), a.end()) 来返回 a 中的值
* 假设 a 已经排好序，可以通过 unique(a.begin(), a.end()) 将 a 中相邻的重复元素去掉，返回新的 end 迭代器
* 还可以通过 a.erase(迭代器1, 迭代器2), 输出 2 个迭代器之间的元素 

```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a = {2, 4, 4, 5, 2};

    // 输出: 2 4 4 5 2
    for (auto i = a.begin(); i != a.end(); i++) cout << *i << ' ';
    cout << '\n';
    
    // 输出: 5, 表示 a 中最大的元素是 5
    cout << *max_element(a.begin(), a.end()) << '\n';
    // 输出: 3, 表示 a 中最大的素数是 a[3]
    cout << max_element(a.begin(), a.end()) - a.begin() << '\n';
    
    // 翻转 a
    reverse(a.begin(), a.end());
    // 输出: 2 5 4 4 2
    for (auto i = a.begin(); i != a.end(); i++) cout << *i << ' ';
    cout << '\n';

    // 将 a 从小到大 排序
    sort(a.begin(), a.end());
    // 输出: 2 2 4 4 5
    for (auto i = a.begin(); i != a.end(); i++) cout << *i << ' ';
    cout << '\n';

    // 通过 unique 去重, 返回新的 end
    auto new_end = unique(a.begin(), a.end());
    // 输出: 2 4 5
    for (auto i = a.begin(); i != new_end; i++) cout << *i << ' ';
    cout << '\n';

    // 还可以通过 erase 将 a 中去重后多余的部分删掉
    // 这个时候 a.end() 就等于 new_end 了
    a.erase(new_end, a.end());
    // 输出: 2 4 5
    for (auto i = a.begin(); i != a.end(); i++) cout << *i << ' ';
    cout << '\n';
    return 0;
}
```

# 4、pair 类型
* pair 类型可以将 2 个值绑定到一个变量中（这个 2 个值可以是同一类型，也可以是不同类型）
```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
    // pair<int, int> 表示将 2 个 int 类型的值绑定成新的类型
    pair<int, int> a;
    // 可以通过 a.first 获取第 1 个数, a.second 获取第二个数
    a.first = 1, a.second = 2;

    // 可以将不同类型的 2 个值绑定
    // 比如第 1 个是 int 类型, 第 2 个是 double 类型
    // 可以通过 {1, 1.5} 的形式生成 pair<int, double> 类型
    pair<int, double> b = {1, 1.5};
    // 输出: 1 1.5
    cout << b.first << ' ' << b.second << '\n';

    // 绑定 string 和 int
    // 输出: liangsheng 32
    pair<string, int> c = {"liangsheng", 32};
    cout << c.first << ' ' << c.second << '\n';

    // 还可以绑定 vector
    vector<int> arr = {1, 2, 3, 4};
    pair<int, vector<int>> d = {1, arr};
    // 输出: 1
    cout << d.first << '\n';
    // 输出: 1 2 3 4
    for (auto x : d.second) cout << x << ' ';
    cout << '\n';

    // pair 也可以嵌套绑定
    pair<int, pair<int, int>> e = {1, {2, 3}};
    // 输出: 1
    cout << e.first << '\n';
    // 输出: 2 3
    cout << e.second.first << ' ' << e.second.second << '\n';
    return 0;
}
```

# 5、序列容器
## 5-1、vector
* vector 大家已经比较熟悉
* 变长数组 vector 是标准模板库中的一种线性容器
  * 数据在内存中连续存放，可以按下标任意访问
  * 可以很快地在容器尾添加和删除元素
```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
    // 申明数组 a, 包含 10 个 int 类型变量, 初始值都是 1
    vector<int> a(10, 1);

    // 通过 b.push_back(1) 在数组末尾添加元素
    vector<int> b;
    b.push_back(1);
    b.push_back(2);

    // 通过 b.size() 获取数组的长度
    // 输出: 1 2
    for (int i = 0; i < b.size(); i++) cout << b[i] << ' ';
    cout << '\n';
    return 0;
}
```
* 还有很多关于 vector 中迭代器的用法，可参考本课件的迭代器部分

## 5-2、deque
* 除了在容器末尾添加元素，有时我们还需要在容器开头添加元素
* 可以使用标准模板库中的 deque 容器
  * 不保证数据在内存中连续存放，但可以按下标任意访问
  * 可以很快地在容器的头尾添加和删除元素
  * 要在容器头添加元素，使用 push_front
  * 要在容器头删除元素，使用 pop_front
```c++
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main() {
    deque<int> a;
    
    // 通过 push_back 在 a 末尾添加元素
    a.push_back(1);  // a = [1]
    a.push_back(2);  // a = [1, 2]
    a.push_back(3);  // a = [1, 2, 3]

    // 通过 push_front 在 a 开头添加元素
    a.push_front(4);  // a = [4, 1, 2, 3]
    a.push_front(5);  // a = [5, 4, 1, 2, 3];

    // 通过迭代器遍历 a 中的元素
    for (auto i = a.begin(); i != a.end(); i++) cout << *i << ' ';
    cout << '\n';

    // 通过下标访问 a 中的元素
    cout << a[0] << '\n';  // a[0] = 5;
    cout << a[1] << '\n';  // a[1] = 4;
    cout << a[2] << '\n';  // a[2] = 1;

    // 删除 a 中最前面的元素
    a.pop_front();  // a = [4, 1, 2, 3]
    for (int x : a) cout << x << ' ';
    cout << '\n';

    // 删除 a 中最后面的元素并
    a.pop_back();  // a = [4, 1, 2]
    for (int x : a) cout << x << ' ';
    cout << '\n';

    return 0;
}
```

## 5-3、queue
* 队列（queue）是 deque 的特殊情况
* 队列（queue） 要求所有元素先进先出
* **<font color="#FF0000">队列（queue） 总是在末尾添加元素，在开头删除元素</font>**
```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
    // 申明队列时，需要指明类型
    queue<string> qs;
    queue<int> q;

    // 通过 push 或者 emplace, 往队列里添加元素
    // push 和 emplace 几乎是一样的
    q.push(1);     // q = [1]
    q.push(2);     // q = [1, 2]
    q.emplace(3);  // q = [1, 2, 3]

    // 通过 front() 取队列开头的元素
    int x = q.front();
    cout << "x= " << x << '\n';  // x = 1
    // 通过 pop() 将队列开头的元素弹出, q 变成 [2, 3]
    q.pop();

    int y = q.front();
    cout << "y= " << y << '\n';  // y = 2
    q.pop();                     // q = [3]
    return 0;
}
```
* 队列（queue）也可以用 vector 来实现
```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
    // 假设队列最长是 100, l 和 r 分别指向队列的头和尾的后一个位置
    int n = 100, l = 0, r = 0;
    vector<int> q(n);

    // 往队列里添加元素
    q[r++] = 1;  // q = [1]
    q[r++] = 2;  // q = [1, 2]
    q[r++] = 3;  // q = [1, 2, 3]

    // 取队列开头元素
    int x = q[l];
    cout << "x= " << x << '\n';  // x = 1
    // 通过 l++ 将队列开头的元素弹出, q 变成 [2, 3]
    l++;

    int y = q[l];
    cout << "y= " << y << '\n';  // y = 2
    l++;                         // q = [3]
    return 0;
}
```

## 5-4、stack
* 栈（stack）是 deque 的特殊情况
* 栈（stack）要求所有元素后进先出.
* **<font color="#FF0000">栈（stack） 总是在末尾添加元素，在末尾删除元素</font>**
```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
    // 申明栈时，需要指明类型
    stack<int> s;

    // 通过 push 或者 emplace, 往栈里添加元素
    // push 和 emplace 几乎是一样的
    s.push(1);     // s = [1]
    s.push(2);     // s = [1, 2]
    s.emplace(3);  // s = [1, 2, 3]

    // 通过 front() 取栈顶的元素
    int x = s.top();
    cout << "x= " << x << '\n';  // x = 3
    // 通过 pop() 将栈顶的元素弹出, s 变成 [2, 3]
    s.pop();

    int y = s.top();
    cout << "y= " << y << '\n';  // y = 2
    s.pop();                     // s = [3]
    return 0;
}
```
* 栈（stack）也可以用 vector 来实现
```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
    // 假设栈最长是 100, e 表示栈里元素的个数, 初始是 0
    int n = 100, e = 0;
    vector<int> s(n);

    // 往栈里添加元素
    s[e++] = 1;  // s = [1]
    s[e++] = 2;  // s = [1, 2]
    s[e++] = 3;  // s = [1, 2, 3]

    // 取栈顶头元素
    int x = s[e - 1];
    cout << "x= " << x << '\n';  // x = 3
    // 通过 e-- 将栈顶的元素弹出, s 变成 [1, 2]
    e--;

    int y = s[e - 1];
    cout << "y= " << y << '\n';  // y = 2
    e--;                         // s = [3]
    return 0;
}
```

## 5-5、priority_queue
* 每次删除优先级最大的元素，不管这个元素是什么时候添加的
* 这个数据结构称为优先队列（prioriyt_queue）
* 下面的代码使用 priority_queue，将元素从大到小输出，也就是堆排序
```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
    // 优先队列申明时需要指明类型, 默认优先取出最大值
    priority_queue<string> qs;
    priority_queue<int> q;

    q.push(1);
    q.push(5);
    q.push(4);
    q.push(2);
    q.push(3);

    // 可以通过 empty() 判断是否为空, queue 和 stack 也有 empty() 方法
    // 输出: 5 4 3 2 1
    while (!q.empty()) {
        int x = q.top();    // 通过 top() 每次取出最大元素
        cout << x << ' ';
        q.pop();            // 通过 pop() 将当前最大元素删除
    }
    cout << '\n';
    return 0;
}
```
* 如果每次需要删除的是最小的数，可以在 push 的时候将数取反
```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
    // 优先队列申明时需要指明类型, 默认优先取出最大值
    priority_queue<int> q;

    // 如果每次需要删除的是最小的数，可以在 push 的时候将数取反
    q.push(-1);
    q.push(-5);
    q.push(-4);
    q.push(-2);
    q.push(-3);

    // 输出: 1 2 3 4 5
    while (!q.empty()) {
        int x = q.top();    // 通过 top() 每次取出最大元素
        cout << -x << ' ';  // 输出的时候取反
        q.pop();            // 通过 pop() 将当前最大元素删除
    }
    cout << '\n';
    return 0;
}
```
* 或者再申明的时候告诉 priority_queue 每次删除最小的
```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
    // 申明有限队列时, 指定每次删除最小的
    // 第 1 个参数 int 是指优先队列里的元素类型
    // 第 2 个参数 vector<int> 是有限队列的实现方式
    // 第 3 个参数 greater<int> 告诉优先队列 top() 取最小的数
    priority_queue<int, vector<int>, greater<int>> q;

    q.push(1);
    q.push(5);
    q.push(4);
    q.push(2);
    q.push(3);

    // 输出: 1 2 3 4 5
    while (!q.empty()) {
        int x = q.top();    // 通过 top() 每次取出最大元素
        cout << x << ' ';  // 输出的时候取反
        q.pop();            // 通过 pop() 将当前最大元素删除
    }
    cout << '\n';
    return 0;
}
```
* 优先队列（priority_queue）可以用 [【课件】时间复杂度与排序](http://www.gzezoi.cn/d/gzezoi2023/p/P0005) 中介绍的 堆（heap）来实现

# 6、关联容器
## 6-1、set
* set 代表集合容器，用以 **<font color="#FF0000">有序地存储互异元素的容器</font>**
* 每次添加新元素到集合时，都会判断该元素是否已经在集合里面
  * 如果不在，则将该元素插入
  * 如果存在，则什么也不做
* set 由红黑树实现（一类平衡二叉树，以后会讲到）
* **<font color="#FF0000">insert（插入）, erase（删除）, find（查找）, count（查找）的时间复杂度都是 $O(log(n))$，$n$ 是 set 中元素的个数</font>**

```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> s;

    // 插入集合 s 中的元素, 默认从小到大排列
    // 所以 set 也可以用来排序
    s.insert(3);  // s = {3}
    s.insert(2);  // s = {2, 3}
    s.insert(1);  // s = {1, 2, 3}
    s.insert(1);  // s = {1, 2, 3}, 元素 1 本来就存在

    // 通过 s.beign() 获取 s 中最小的数的迭代器
    // 通过 * 解引用, 可以获取迭代器指向的具体指
    cout << *s.begin() << '\n';   // 输出: 1

    // 通过 s.rbeign() 获取 s 中最小的数的迭代器
    cout << *s.rbegin() << '\n';  // 输出: 3 

    // 输出: 1 2 3
    for (int x : s) cout << x << ' ';
    cout << '\n';

    // 还可以通过迭代器遍历
    // 输出: 1 2 3
    for (auto i = s.begin(); i != s.end(); i++) cout << *i << ' ';
    cout << '\n';

    // 通过 s.count(x) 判断元素 x 是否在集合 s 中
    cout << (s.count(1) ? "s 中存在 1" : "s 中不存在 1") << '\n';
    cout << (s.count(4) ? "s 中存在 4" : "s 中不存在 4") << '\n';

    // 如果 s 中存在 x, 可以通过 s.find(x) 找到 x 对应的迭代器
    if (s.count(2)) {
        auto it = s.find(2);
        // 输出: 1, 也就是集合 s 中 2 的前一个数
        // 这里需要判断 it 是否是 s 的第 1 个指针
        // 如果 it == s.beign(), it 就不能再往前移
        if (it != s.begin()) {
            auto pre = it;
            cout << *(--pre) << '\n';
        }
        
        // 输出: 3, 也就是集合 s 中 2 的后一个数
        auto after = it;
        // 这里需要判断 after == s.end()
        if (++after != s.end()) cout << *after << '\n';
    }

    // 可以通过 s.erase(x), 删除 s 中的元素
    // 如果 s 中存在 x, 则删除 x; 否则, 就什么也不做
    s.erase(1);
    // 输出: 2 3
    for (int x : s) cout << x << ' ';
    cout << '\n';

    // erase() 里面的参数也可以是迭代器
    s.erase(s.find(2));
    // 输出: 3
    for (int x : s) cout << x << ' ';
    cout << '\n';

    // 通过 s.size() 获取 s 中元素的个数
    // 输出: 1
    cout << s.size() << '\n';

    // 通过 s.empty() 判断 s 是否为空集合
    // 输出: s 不为空
    cout << (s.empty() ? "s 为空" : "s 不为空") << '\n';

    // 通过 s.clear()，可以将 s 清空
    s.clear();
    cout << (s.empty() ? "s 为空" : "s 不为空") << '\n';
    return 0;
}
```
* set 中的元素默认会去重，如果想插入相同的数，可以利用 pair 类型， 给要插入的数匹配一个序
```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> s;

    s.insert(1);
    s.insert(2);
    s.insert(2);  // set 会去重, 前面已经插入过 2, 这里不会生效

    // 输出: 1 2
    for (int x : s) cout << x << ' ';
    cout << '\n';

    // 如果想插入相同的数, 可以利用 pair 类型, 给要插入的数匹配一个序号
    // pair 类型只有 pair 中的 2 个数都相同, 才会被判定相同
    // 而 pair 之间比较大小, 是先比较 first, 再比较 second
    set<pair<int, int>> ns;
    ns.insert({1, 1});  // 第 1 次插入 1
    ns.insert({2, 2});  // 第 2 次插入 2
    ns.insert({2, 3});  // 第 3 次插入 2

    // 输出: 1 2 2
    for (auto i : ns) cout << i.first << ' ';
    cout << '\n';
    return 0;
}
```

## 6-2、map
* 之前学过了数组，可以把下标对应到元素
  * a[1] = 2, 相当于把下标 1 对应到 2
  * a[5] = 9, 相当于把下标 5 对应到 9
* 如果我们的下标不是整数，是字符串怎么办？
  * 比如我想存储每个学生的姓名和成绩
  * 小明 80 分："xiaoming" -> 80
  * 小红 90 分："xiaohong" -> 90
* 可以使用 map，在两种任意类型的数据之间，形成映射
* **<font color="#FF0000">可以把 map 理解为，下标是任意类型，值也是任意类型的数组！！</font>**
```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
    set<int> s;

    // 插入集合 s 中的元素, 默认从小到大排列
    // 所以 set 也可以用来排序
    s.insert(3);  // s = {3}
    s.insert(2);  // s = {2, 3}
    s.insert(1);  // s = {1, 2, 3}
    s.insert(1);  // s = {1, 2, 3}, 元素 1 本来就存在

    // 通过 s.beign() 获取 s 中最小的数的迭代器
    // 通过 * 解引用, 可以获取迭代器指向的具体指
    cout << *s.begin() << '\n';   // 输出: 1

    // 通过 s.rbeign() 获取 s 中最小的数的迭代器
    cout << *s.rbegin() << '\n';  // 输出: 3 

    // 输出: 1 2 3
    for (int x : s) cout << x << ' ';
    cout << '\n';

    // 还可以通过迭代器遍历
    // 输出: 1 2 3
    for (auto i = s.begin(); i != s.end(); i++) cout << *i << ' ';
    cout << '\n';

    // 通过 s.count(x) 判断元素 x 是否在集合 s 中
    cout << (s.count(1) ? "s 中存在 1" : "s 中不存在 1") << '\n';
    cout << (s.count(4) ? "s 中存在 4" : "s 中不存在 4") << '\n';

    // 如果 s 中存在 x, 可以通过 s.find(x) 找到 x 对应的迭代器
    if (s.count(2)) {
        auto it = s.find(2);
        // 输出: 1, 也就是集合 s 中 2 的前一个数
        // 这里需要判断 it 是否是 s 的第 1 个指针
        // 如果 it == s.beign(), it 就不能再往前移
        if (it != s.begin()) {
            auto pre = it;
            cout << *(--pre) << '\n';
        }
        
        // 输出: 3, 也就是集合 s 中 2 的后一个数
        auto after = it;
        // 这里需要判断 after == s.end()
        if (++after != s.end()) cout << *after << '\n';
    }

    // 可以通过 s.erase(x), 删除 s 中的元素
    // 如果 s 中存在 x, 则删除 x; 否则, 就什么也不做
    s.erase(1);
    // 输出: 2 3
    for (int x : s) cout << x << ' ';
    cout << '\n';

    // erase() 里面的参数也可以是迭代器
    s.erase(s.find(2));
    // 输出: 3
    for (int x : s) cout << x << ' ';
    cout << '\n';

    // 通过 s.size() 获取 s 中元素的个数
    // 输出: 1
    cout << s.size() << '\n';

    // 通过 s.empty() 判断 s 是否为空集合
    // 输出: s 不为空
    cout << (s.empty() ? "s 为空" : "s 不为空") << '\n';

    // 通过 s.clear()，可以将 s 清空
    s.clear();
    cout << (s.empty() ? "s 为空" : "s 不为空") << '\n';

    // 思考下下面这个复杂的 map, 要如何遍历
    map<vector<int>, pair<int, set<int>>> f;
    for (auto i : f) {
        // i.first 是 vector<int>
        cout << "key: " << '\n';
        for (int j : i.first) cout << ' ';
        cout << '\n';

        // i.second 是 pair<int, set<int>>
        cout << "value: " << '\n';
        // i.second.first 是 int
        cout << i.second.first << '\n';
        // i.second.second 是 set<int>
        for (int j : i.second.second) cout << j << ' ';
        cout << '\n';
    }
    return 0;
}
```
* 和 set 一样，map 也是由红黑树实现（一种平衡二叉树，以后会讲）
* 插入，find（查找），count（查找），erase（删除）的时间复杂度都是 $O(log(n))$，$n$ 是 map 中元素的个数
