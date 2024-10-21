- [0、加速你的cin\_cout](#0加速你的cin_cout)
- [1、vector](#1vector)
- [1-1、数组有如下几个问题](#1-1数组有如下几个问题)
- [1-2、使用vector如下几个优点](#1-2使用vector如下几个优点)
- [1-3、vector的申明](#1-3vector的申明)
- [1-4、改变vector的长度和内容](#1-4改变vector的长度和内容)
- [2、迭代器](#2迭代器)
- [3、多值绑定pair和tuple](#3多值绑定pair和tuple)
- [4、匿名函数和lambda表达式](#4匿名函数和lambda表达式)
  - [4-1、自定义sort](#4-1自定义sort)
- [5、priority\_queue](#5priority_queue)
- [6、set](#6set)
- [7、map](#7map)
- [5、位操作与 bitset](#5位操作与-bitset)
- [6、其他常用函数](#6其他常用函数)

参考资料：
- [oiwiki: STL 容器, 迭代器/vector/set/map 等](https://oiwiki.org/lang/csl/container/)
- [oiwiki: STL 算法, next_permutaion 等](https://oiwiki.org/lang/csl/algorithm/)
  
# 0、加速你的cin_cout 
* 请大家参考以下模板答题
```c++
#include <bits/stdc++.h>  // 头文件此一项足以
using namespace std;

int main() {
    // 如果你想用 cin/cout, 请务必加上这两句
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // 这两句是将输入输出定向到文件
    // 平时做题用不着, csp 复赛的时候要加上!!
    // freopen("apple.in", "r", stdin);
    // freopen("apple.out", "w", stdout);

    // 开始你的表演

    return 0;
}
```
* ios::sync_with_stdio(false);
  * 说的是输入输出少做一次同步
* cin.tie(nullptr); cout.tie(nullptr);
  * 说的是 cin/cout 都采取批量方式
* [不加这两句, 5.58s](https://www.luogu.com.cn/record/177835150)
* [加上这两句, 3.68s](https://www.luogu.com.cn/record/177835150)
* [改用 scanf/printf, 3.54s](https://www.luogu.com.cn/record/177857521)
* **<font color="#00DD00">当题目的输入输出达到 $n=10^6$ 级别时，差距会非常明显</font>**
* **<font color="#FF0000">如果想用 scanf/printf，切记不要将 scanf/printf 和 cin/cout 混用！！</font>**

# 1、vector
* **<font color="#00DD00">请记住，在任何时候，当你想使用一维数组时，你都应该优先使用 vector！！</font>**
# 1-1、数组有如下几个问题
* **<font color="#FF0000">1、在申明数组的时候就必须指明大小，不能变长</font>**
* **<font color="#FF0000">2、在函数内不能申明长度过大的数组，下面的代码在运行时会 RE</font>**
```c++
#include <bits/stdc++.h>
using namespace std;

void test() {
    int a[3000000];  // 这竟然会 RE !!
    cout << "Hello World" << '\n';
}

int main() {
    test();
    return 0;
}
```
* **<font color="#FF0000">3、数组越界不一定会报错，给调试带来巨大的困扰</font>**
```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[10];
    cout << a[15] << '\n';  // 这竟然不报错 !!
    return 0;
}
```
# 1-2、使用vector如下几个优点
* **<font color="#00DD00">1、可以动态调整长度</font>**
```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> b;   // 申明数组 b, 初始为空 
    b.push_back(1);  // 通过 push_back 在数组末尾添加元素
    b.push_back(2);

    // 通过 b.size() 获取数组的长度
    // 输出: 1 2
    int n = b.size();
    for (int i = 0; i < n; i++) {
        // " \n"[i == n - 1] 是说在 i == n - 1 时回车, 其余情况空格
        cout << b[i] << " \n"[i == n - 1];
    }
    return 0;
}
```
* 2、**<font color="#00DD00">长度超过 3000000 的 vector 也不会 RE，当然也不能太大</font>**
```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;  // 输入 3000000
    vector<int> a(n, 1);  // 申明一个大小为 n 的数组, 且全部初始化为 1, 不会 RE !!
    cout << a[0] << '\n';
    return 0;
}
```
* 3、**<font color="#00DD00">平时比较粗心的同学，可以通过 at() 来防止越界，不过使用 at() 会带来一定的时间消耗，一般还是不用</font>**
```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a(10, 1);

    // 相当于 a[15]
    cout << a.at(15) << '\n';  // 运行时会告诉你越界
    // 一般不会用 at(), 除非你真的看不错哪里越界了...
    return 0;
}
```
* 4、**<font color="#00DD00">配合下面要将的迭代器，有一些列骚操作可以让你的代码又短又快</font>**
  
# 1-3、vector的申明
* **<font color="#00DD00">最佳实践：任何时候在申明 vector 的时候都应该指明初值，除非 vector 里面的元素即将被输入</font>**
```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
    // 申明一个长度为 10 的 int 数组, 并且全部初始化为 1
    vector<int> a(10, 1);

    // 可以在申明的时候直接将数组写出来
    vector<int> arr = {2, 4, 4, 5, 2};

    // 也可以不指定初始值
    // 除非 b 里面的值即将被输入, 其他情况请你赋初值！！
    vector<double> b(10);

    // 根据输入 n 来决定数组的长度
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];

    // 也可以申明的时候不指定长度
    // 之后在通过 assign() 指定长度和初值
    int m, x;
    vector<int> d;
    cin >> m >> x;
    // 将 d 的长度变为 m，初值为 x
    d.assign(m, x);

    // 申明二维 vector, 二维 vector 的初值是一维 vector
    // 相当于 int f[5][6]; 赋初值为 0
    vector<vector<int>> f(5, vector<int>(6, 0));
    
    // 申明三维 vector, 三维 vector 的初值是二维 vector
    // 相当于 int g[3][4][5]; 赋初值为 0
    vector<vector<vector<int>>> g(3, vector<vector<int>>(4, vector<int>(5, 0)));
    return 0;
}
```
# 1-4、改变vector的长度和内容
```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> b;   // 申明数组 b, 初始为空 
    b.push_back(1);  // 通过 push_back 在数组末尾添加元素
    b.push_back(2);

    // 通过 b.size() 获取数组的长度
    // 输出: 1 2
    int n = b.size();
    // 遍历 vector 中的内容
    for (int i = 0; i < n; i++) {
        // " \n"[i == n - 1] 是说在 i == n - 1 时回车, 其余情况空格
        cout << b[i] << " \n"[i == n - 1];
    }

    // 通过 assign() 将 b 调整为长度为 3, 初值为 2
    b.assign(3, 2);

    // clear(), 将 b 数组清空
    b.clear();

    // 此时 b 的长度为 0
    cout << b.size() << '\n';
    return 0;
}
```

# 2、迭代器
* 指针可以用来标记数组的位置
* **<font color="#00DD00">对于 vector/set/map 来说, 迭代器就是 vector/set/map 的指针，可以用来标记元素的位置</font>**
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

    // 但凡编译器能推断出类型的地方, 都可以用 auto 代替具体类型
    auto pi = 3.14;
    cout << "pi= " << pi << '\n';
    return 0;
}
```
* **<font color="#00DD00">下面将展示一些列基于迭代器的骚操作</font>**
```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a = {2, 4, 4, 5, 2};

    // 输出: 2 4 4 5 2
    for (auto i = a.begin(); i != a.end(); i++) cout << *i << ' ';
    cout << '\n';
    
    // max_element(a.begin(), a.end()) 返回的是一个迭代器
    // 可以通过 * 操作得到迭代器指向的数值
    // 输出: 5, 表示 a 中最大的元素是 5
    cout << *max_element(a.begin(), a.end()) << '\n';
    
    // 输出: 3, 表示 a 中最大的素数是 a[3]
    cout << max_element(a.begin(), a.end()) - a.begin() << '\n';
    
    // 将 a 中的数全部修改为 3
    // a = {3, 3, 3, 3, 3}
    fill(a.begin(), a.end(), 3);

    // 把从 2 开始的自然数赋值给 a.begin() 到 a.end()
    // a = {2, 3, 4, 5, 6}
    iota(a.begin(), a.end(), 2);

    // 求 a.begin() 到 a.end() 的和, 并将结果累加到 1 上
    // sum = 2 + 3 + 4 + 5 + 6 + 1 = 21
    int sum = accumulate(a.begin(), a.end(), 1);

    a = {2, 4, 4, 5, 2};

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
    // 删掉 new_end 到 a.end() 之间的元素
    a.erase(new_end, a.end());
    // 输出: 2 4 5
    for (auto i = a.begin(); i != a.end(); i++) cout << *i << ' ';
    cout << '\n';

    // 在有序的 a 中二分查找第一个 >= 4 的位置
    // p = 1
    int p = lower_bound(a.begin(), a.end(), 4) - a.begin();
    
    // 在有序的 a 中二分查找第一个 > 4 的位置
    // q = 2
    int q = upper_bound(a.begin(), a.end(), 4) - a.begin();
    return 0;
}
```

# 3、多值绑定pair和tuple
* pair 类型可以将 2 个值绑定到一个变量中（这个 2 个值可以是同一类型，也可以是不同类型）
* 如果想将超过 2 个值绑定到一个变量中，可以用 tuple
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
    // 在低版本的编译器中不支持 {1, 1.5}, 可以用 make_pair
    // pair<int, double> b = make_pair(1, 1.5);

    // 输出: 1 1.5
    cout << b.first << ' ' << b.second << '\n';

    // 在 c++17 及以上版本中还可以这样, 这个叫动态绑定
    auto [x, y] = b;
    cout << x << " " << y << '\n';

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
    
    // 使用 tuple 绑定多个值
    tuple<int, double, string> g = {1, 3.14, "liangsheng"};
    auto [u, v, w] = g;
    cout << "u= " << u << ", v= " << v << ", w= " << w << '\n';
    return 0;
}
```

# 4、匿名函数和lambda表达式
* 大家可能见过高手这么写
```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
    int x = 2;

    // 这个 fun 就叫匿名函数(lambda 表达式)
    // 实际上就是申明一个函数 int fun(int n) {}
    // [&] 表示在函数体内可以调用函数外面的变量, 比如 x
    auto fun = [&](int n) {
        return x * n;
    };

    // 输出 2 * 5 = 10
    cout << fun(5) << '\n';

    // 如果用 [] 替换 [&], 就不能用 x
    // 这里会报编译错误 
    // auto test = [](int n) {
    //     return x * n;
    // };
    return 0;
}
```
## 4-1、自定义sort
* 匿名函数可以当做 sort() 里面的自定义函数
```c++
#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a = {1, 2, 3, 4, 5};

    // 通过匿名函数将 a 从大到小排序
    sort(a.begin(), a.end(), [&](const int& x, const int& y) {
        return x > y;
    });
    
    // 输出 5 4 3 2 1
    for (int x : a) cout << x << ' ';
    cout << '\n';

    return 0;
}
```

# 5、priority_queue
* prioriyt_queue：还可以称为 `优先队列`，或者 `堆`，
  * 支持 $log(n)$ 的插入元素
  * 支持 $log(n)$ 的查询最大元素
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

    // 可以通过 empty() 判断是否为空
    // 输出: 5 4 3 2 1
    // 其实这个就是堆排序
    while (!q.empty()) {
        int x = q.top();    // 通过 top() 每次取出最大元素
        cout << x << ' ';
        q.pop();            // 通过 pop() 将当前最大元素删除
    }
    cout << '\n';
    return 0;
}
```
* 如果需要从小到大排序，可以在 push 的时候将数取反

# 6、set
* set 代表集合容器，用以 **<font color="#FF0000">有序地存储互异元素</font>**
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

    // 可以通过不断向后移动迭代器的方法, 来查找 set 中排名第 k 的元素
    set<int> a = {1, 3, 5, 7, 9};
    // 查找排名为 3 的元素
    auto p = a.begin();
    for (int i = 1; i < 3; i++) p++;
    // 也可以使用 next() 获取下一个迭代器
    // for (int i = 1; i < 3; i++) p = next(p)
    cout << "排名为 3 的元素是: " << *p << '\n';
    return 0;
}
```

# 7、map
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
    // 将 string 映射到 int
    // 我们把第 1 个类型 string 称为 key (键) 
    // 把第 2 个类型 int 称为 value (值)
    map<string, int> m;

    // Bob 对应 80 分; Dog 对应 60 分; Alice 对应 90 分
    m["Bob"] = 80;
    m["Dog"] = 60;
    m["Alice"] = 90;
    
    // 可以通过下面的方式遍历 m
    // i 是 pair<string, int> 类型
    // 可以通过 i.first 获取 key, 通过 i.second 获取 value
    // m 中的元素是按 key 值从小到大排序的
    // 输出: Alice 90
    // 输出: Bob 80
    // 输出: Dog 60
    for (auto i: m) {
        cout << i.first << ' ' << i.second << '\n';
    }

    // 会修改 Alice 对应的值
    m["Alice"] = 95;
    cout << "Alice 对应的值是: " << m["Alice"] << '\n';

    // 也可以通过迭代器遍历
    // 这里 i 是 pair<string, int> 类型的迭代器
    // 可以通过 i->first, i->second 获取值
    for (auto i = m.begin(); i != m.end(); i++) {
        cout << (i->first) << ' ' << (i->second) << '\n';
    }

    // 可以通过 m.count("Bob") 查看 m 中是否存在 Bob 对应的值
    if (m.count("Bob")) cout << "Bob 对应的值是: " << m["Bob"] << endl;
    else cout << "不存在 Bod 对应的值" << '\n';
    
    // 可以通过 m.empty() 判断 m 是否为空
    // 可以通过 m.size() 获取 m 中映射的个数
    if (m.empty()) cout << "m 是空" << endl;
    else cout << "m 的大小是: " << m.size() << '\n';

    // 可以通过 m.erase("Dog") 删除 key 是 Dog 的映射
    // 如果不存在 key 是 Dog 的映射, 则什么也不做
    m.erase("Dog");
    for (auto i : m) cout << i.first << ' ' << i.second << '\n';

    // 通过 m.clear()，可以将 m 清空
    m.clear();
    cout << (m.empty() ? "m 为空" : "m 不为空") << endl;

    // key 和 value 可以使复杂类型
    // key 是 int, value 是 vector<int>
    map<int, vector<int>> a;
    a[123] = {1, 2, 3};
    a[456] = {7, 8, 9};
    // 输出: key= 123, value= 1 2 3
    // 输出: key= 456, value= 7 8 9
    for (auto i : a) {
        cout << "key= " << i.first;
        cout << ", value= "; 
        for (int j : i.second) cout << j << ' ';
        cout << '\n';
    }

    // key 是 vector<int>, value 是 string
    map<vector<int>, string> b;
    b[{1, 2, 3, 4}] = "Hello";

    // 在 map 中, 不存在的 key 对应 0(当 value 是 int 时)
    map<int, int> t;
    cout << t[0] << '\n';  // 输出: 0

    // 在 map 中, 不存在的 key 对应空数组(当 value 是 vector<int> 时)
    map<int, vector<int>> tr;
    cout << tr[0].size() << '\n';  // 输出: 0

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

# 5、位操作与 bitset
* [位操作相关函数](https://blog.csdn.net/m0_73759312/article/details/132031633)
* [oiwiki: bitset](https://oiwiki.org/lang/csl/bitset/)
  

# 6、其他常用函数
* floor()
* ceil()
* round()
* sqrt()
* min(), max(), abs()
* next_permutation()