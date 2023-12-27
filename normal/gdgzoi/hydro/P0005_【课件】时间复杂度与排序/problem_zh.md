# 1、时间复杂度

* 为什么有的代码执行速度快，有的会超时（**<font color="#FF0000">Time Execeeded</font>**）
* 时间复杂度就是用来衡量一个算法执行快慢的指标
* 我们通过几个例子，来学习如何计算时间复杂度

```c++
int n, sum = 0;
int a[105];
cin >> n;
for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
}
cout << sum << endl;
```

* 上面的代码，通过一个 for 循环遍历了数组 $a$ 的 $n$ 个数，在做了 $n$ 次加法后求出了 $sum$
* 我们称这段代码的时间复杂度是 $O(n)$

```c++
int n, m, sum = 0;
int a[105], b[105];
cin >> n;
cin >> m
for (int i = 0; i < n; i++) cin >> a[i];
for (int i = 0; i < m; i++) cin >> b[i];
for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        sum += a[i] * b[j];
    }
}
cout << sum << endl;
```

* 上面的代码，通过 2 个 for 循环枚举了数组 $a$ 和数组 $b$ 两两组合的所有情况（总共 $n*m$ 种情况）
* 我们称这段代码的时间复杂度是 $O(n*m)$
* **<font color="#FF0000">其实就是找到嵌套的 for 循环，将每个 for 循环的执行次数相乘</font>**

```c++
// 嵌套 2 个 for, 时间复杂度 O(n*m)
for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        sum += a[i] * b[j];
    }
}
// 嵌套 3 个 for, 时间复杂度 O(n*m*d)
for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        for (int k = 0; k < d; k++) {
            sum += a[i] * b[j] * c[k];
        }
    }
}
cout << sum << endl;
```

* 上面的代码，有 2 个嵌套的 for 循环, 第 1个 嵌套的时间复杂度是 $O(n*m)$，第 2 个嵌套的时间复杂度是 $O(n*m*d)$
* 我们称这段代码的时间复杂度是 $O(n*m*d)$
* **<font color="#FF0000">当有多个嵌套的 for 循环结构时，我们只保留复杂度最高的嵌套 for 循环</font>**
  * 这是因为，随时数据量的变大（$n, m, d$ 越来越大）, $n*m*d$ 要远大于 $n*m$，计算量将主要由 $n*m*d$ 决定

```c++
// 嵌套 2 个 for
for (int i = 1; i <= n; i++) {
    // 第二个 for 每次 j += i
    for (int j = i; j <= n; j += i) {
        sum += i * j;
    }
}
```

* i = 1 时, j = 1, 2, 3, 4, ..., n, 共计算 $n$ 次
* i = 2 时, j = 2, 4, 6,..., 共计算 $\frac{n}{2}$ 次
* i = 3 时, j = 3, 6, 9,..., 共计算 $\frac{n}{3}$ 次
* i = n 时, j = n 共计算 $\frac{n}{n}=1$ 次
* 所以总共计算了 $n*(\frac{1}{1}+\frac{1}{2}+\frac{1}{3}+\frac{1}{4}+...+\frac{1}{n})$ 次
* $\frac{1}{1}+\frac{1}{2}+\frac{1}{3}+\frac{1}{4}+\frac{1}{5}+\frac{1}{6}+\frac{1}{7}$，小于下面的式子
* $\frac{1}{1}+\frac{1}{2}+\frac{1}{2}+\frac{1}{4}+\frac{1}{4}+\frac{1}{4}+\frac{1}{4}$ = 3
* 所以 $\frac{1}{1}+\frac{1}{2}+\frac{1}{3}+\frac{1}{4}+...+\frac{1}{n}$ 是不超过 $log(n)$ 的
* 所以上述代码的复杂度是不超过 $O(nlog(n))$ 的
  
  * 大家回忆下筛素数算法，其时间复杂度不超过 $O(nlog(n))$
* **<font color="#FF0000">$log(x) = y$: 是指 $2^y==x$</font>**
  
  * 比如: $log(8) = 3$, 因为 $2^3=8$; $log(4) = 2$, 因为 $2^2=4$
  * $3 \lt log(9) \lt 4$
  * $log(1000) \approx 10, log(10^6) \approx 20$

# 2、排序算法
* [数据结构与算法系列--十大排序（附动态图解）](https://zhuanlan.zhihu.com/p/60152722)
  * 这个网站有各种解释和动图，代码可以不用参考 
* [visualgo.net 各种动图](https://visualgo.net/zh/sorting)
  * 这个网站可以自定义数据生成动图

## 2-1、选择排序

* 请参考之前的课件 [【课件】数组和字符串](http://43.136.49.238/d/gzezoi2023/p/P0003)

```c++
#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

/*--------------------- 选择排序, 时间复杂度 O(n^2) begin -----*/
// 将 a[l], a[l + 1], ..., a[r - 1], a[r] 排序
// select_sort(a, 1, n);
void select_sort(int* a, int l, int r) {
    for (int i = r; i > l; i--) {
        int p = l;
        for (int j = l; j <= i; j++) if (a[j] > a[p]) p = j;
        swap(a[p], a[i]);
    }
}
/*--------------------- 选择排序, 时间复杂度 O(n^2) end -------*/

int main() {
    int n;
    int a[N];
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    select_sort(a, 1, n);
    for (int i = 1; i <= n - 1; i++) cout << a[i] << ' ';
    cout << a[n] << '\n';
    return 0;
}
```

* 选择排序共计比较的次数: $(n-1)+(n-2)+...+1=n*(n-1)/2=\frac{1}{2}n^2-\frac{1}{2}n$
* **<font color="#FF0000">当 $n$ 很大时使劲复杂度主要由 $\frac{1}{2}n^2$ 决定；时间复杂度只保留和数据量 $n$ 相关的项，忽略常数项 $\frac{1}{2}$，所以：</font>**
* **<font color="#FF0000">选择排序的时间复杂度是 $O(n^2)$ </font>**

## 2-2、冒泡排序

* 冒泡排序攻击执行 $n-1$ 轮
* 每一轮比较相邻的 2 个数，将较大的数交换到后面，这样每一轮都能找到 1 个最大的数

```c++
#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

/*--------------------- 冒泡排序, 时间复杂度 O(n^2) begin -----*/
// 将 a[l], a[l + 1], ..., a[r - 1], a[r] 排序
// bubble_sort(a, 1, n);
void bubble_sort(int* a, int l, int r) {
    // 冒泡排序攻击执行 r - l - 1 轮(从 r 到 l - 1)
    for (int i = r; i > l; i--) {
        for (int j = l; j < i; j++) {
            // 比较相邻的 2 个数，将较大的数交换到后面
            if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
        }
    }
}

/*--------------------- 冒泡排序, 时间复杂度 O(n^2) end -------*/

int main() {
    int n;
    int a[N];
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    bubble_sort(a, 1, n);
    for (int i = 1; i <= n - 1; i++) cout << a[i] << ' ';
    cout << a[n] << '\n';
    return 0;
}
```

* **<font color="#FF0000">冒泡排序的时间复杂度是 $O(n^2)$ </font>**

## 2-3、归并排序
* 先考虑一个简单的问题，有 2 个排序好的数组 $a$ 和 $b$, 如何将 $a,b$ 合并成一个新的排序好的数组 $c$ ？
  * $a = [1, 3, 5, 7, 9, 10]$
  * $b = [2, 4, 6, 8]$
  * 设 p = 1, 为 a 的第 1 个数；q = 2，为 b 的第 1 个数
  * $(p=1) \lt (q=2)$，于是把 p 放到数组 $c$，c = [1], p 指向 a 的第 2 个数 3
  * $(p=3) \gt (q=2)$，于是把 q 放到数组 $c$，c = [1, 2], q 指向 b 的第 2 个数 4
  * $(p=3) \lt (q=4)$，于是把 p 放到数组 $c$，c = [1, 2, 3], p 指向 a 的第 3 个数 5
  * $(p=5) \gt (q=4)$，于是把 q 放到数组 $c$，c = [1, 2, 3, 4], q 指向 b 的第 3 个数 6
  * $(p=5) \lt (q=6)$，于是把 p 放到数组 $c$，c = [1, 2, 3, 4, 5], p 指向 a 的第 4 个数 7
  * $(p=7) \gt (q=6)$，于是把 q 放到数组 $c$，c = [1, 2, 3, 4, 5, 6], q 指向 b 的第 4 个数 8
  * $(p=7) \lt (q=8)$，于是把 p 放到数组 $c$，c = [1, 2, 3, 4, 5, 6, 7], p 指向 a 的第 5 个数 9
  * $(p=9) \gt (q=8)$，于是把 q 放到数组 $c$，c = [1, 2, 3, 4, 5, 6, 7, 8], 此时 b 已经没有数了
  * 把 a 中剩下的 9 和 10 放到数组 $c$，c = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
  * 至此我们成功将 a 和 b 合并成 1 个新的有序数组 c，我们共计比较了 8 次
  * **<font color="#FF0000">合并 2 个有序数组，最差需要比较的次数不超过 $O(n+m)$ 次, n, m 为 2 个有序数组的大小</font>**

* 用代码描述上述过程
```c++
int a[N], n;                           // 数组 a 存放在 a[0: n)
int b[N], m;                           // 数组 b 存放在 b[0: m)
int c[N], e = 0;                       // 数组 c 的大小是 e, 初始是 0

int i = 0, j = 0;                      // i = 0, 指向 a 的第 1 个数; j = 0, 指向 b 的第一个数
while (i < n &&  j < m) {
    if (a[i] < b[j]) c[e++] = a[i++];  // 把 a[i] 放到 c, i 指向 a 的下一个数
    else c[e++] = b[j++];              // 把 b[j] 放到 c, j 指向 b 的下一个数
}
while (i < n) c[e++] = a[i++];         // 把 a 中剩余的数放到 c
while (j < m) c[e++] = b[j++];         // 把 b 中剩余的数放到 c
```
* 归并排序需要用到递归的思想
* 假设要对 a[l: r] 排序
* 我们将 a[l: r] 分成左右 2 部分，a[l: mid] 和 a[mid + 1: r], 其中 mid=(l+r)/2
* 如果 a[l: mid] 和 a[mid + 1: r] 都排序好了，再调用上述过程合并左右 2 部分即可！！！
* 完整的代码如下

```c++
/*--------------------- 归并排序, 时间复杂度 O(nlog(n)) begin ----*/
#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

// 将 a[l], a[l + 1], ..., a[r - 1], a[r] 排序
// merge_sort(a, 1, n);
int c[N];
void merge_sort(int* a, int l, int r) {
    if (l == r) return ;
    int mid = (l + r) / 2;
    merge_sort(a, l, mid);             // 将 a[l] 到 a[mid] 排序
    merge_sort(a, mid + 1, r);         // 将 a[mid + 1] 到 a[r] 排序
    int i = l, j = mid + 1, e = 0;
    while (i <= mid && j <= r) {       // 将 2 段排好序的子数组合并
        if (a[i] < a[j]) c[e++] = a[i++];
        else c[e++] = a[j++];
    }
    while (i <= mid) c[e++] = a[i++];  // 防止最后还有一些没合并的数
    while (j <= r) c[e++] = a[j++];
    for (i = 0; i < e; i++) a[l + i] = c[i];  // 还原到 a 数组
}
/*--------------------- 归并排序, 时间复杂度 O(nlog(n)) end ------*/

int main() {
    int n;
    int a[N];
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    merge_sort(a, 1, n);
    for (int i = 1; i <= n - 1; i++) cout << a[i] << ' ';
    cout << a[n] << '\n';
    return 0;
}
```
* 可以查看 [luogu_P1177_【模板】排序](https://www.luogu.com.cn/problem/solution/P1177)，加深理解
* 下面的动图是归并排序的全过程
![归并排序图解](file://归并排序.gif)
* 下面的表格第 1 行代表原始数组
* 第 2 行代表相邻 2 个数排好序后情况，即 a[1, 2], a[3, 4], a[5, 6], a[7, 8] 排好序
* 第 3 行代表相邻 4 个数排好序后情况，即 a[1, 2, 3, 4] 排好序, a[5, 6, 7, 8] 排好序
* 第 4 行代表相邻 8 个数排好序后情况，数组全部排好序

|  |  |  |  |  |  |  |  |
| :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: |
| 6 | 5	| 3	| 1 | 8	| 7	| 2	| 4 |
| 5 | 6	| 1	| 3 | 7	| 8	| 2	| 4 |
| 1 | 3	| 5	| 6 | 2	| 4	| 7	| 8 |
| 1 | 2	| 3	| 4 | 5	| 6	| 7	| 8 |
* 长度为 n 的数组，由于每次平分成 2 段
* 因此最多平分 $log(n)$ 次后，每段只剩下 1 个元素
* 而每次平分后，最多需要 $n$ 次比较可以合并已经有序的多个数组
* **<font color="#FF0000">因此归并排序的时间复杂度是 $O(nlog(n))$, 要远比选择排序和冒泡排序快</font>**
  * 但是归并排序需要额外申明 1 个数组 c（用来合并有序数组），需要 $O(n)$ 的存储空间


## 2-4、快速排序
* 简称快排，顾名思义，快速排序的特点就是速度很快（事实上，快排是 C++ 的 sort 函数的主力排序算法）
* 其主要思想和归并排序相似，都是将一个大的数组，分成 2 个小的数组
* 而它分割数组的方法，是随机选取数组里的 1 个值（大多数情况下会取数组的第 1 个元素 a[0]）
  * **<font color="#FF0000">将所有比 a[0] 小的数放到 a[0] 的左边</font>**
  * **<font color="#FF0000">将所有比 a[0] 大的数放到 a[0] 的右边</font>**
  * **<font color="#FF0000">然后递归的，分别对比 a[0] 小的数和比 a[0] 大的数排序</font>**
* 下面的代码是快排的一种实现
  * 该实现不是选的 a[0]，而是随机选取 1 个元素
  * 该实现实际上分了 3 段，左边是比 p（选取的元素）小的数，中间是等于 p 的数，右边是比 p 大的数
```c++
/*--------------------- 快速排序, 时间复杂度 O(nlog(n)) begin ----*/
#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

void quick_sort(int* a, int l, int r) {
    if (l >= r) return ;
    int p = a[rand() % (r - l + 1) + l];  // 随机选取基准
    // i: 当前操作的元素下标
    // a[l: j-1] 存储小于 p 的元素(a[l], a[l + 1], ..., a[j - 1])
    // a[j: k] 存储等于 p 的元素(a[j], a[j + 1], ..., a[k - 1])
    // a[k+1: r] 存储大于 p 的元素(a[k+1], a[k + 2], ..., a[r])
    int i = l, j = l, k = r;
    while (i <= k) {
        if (a[i] < p) swap(a[i++], a[j++]);
        else if (a[i] > p) swap(a[i], a[k--]);
        else i++;
    }
    quick_sort(a, l, j - 1);
    quick_sort(a, k + 1, r);
}

int main() {
    int n;
    int a[N];
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    quick_sort(a, 1, n);
    for (int i = 1; i <= n - 1; i++) cout << a[i] << ' ';
    cout << a[n] << '\n';
    return 0;
}
/*--------------------- 快速排序, 时间复杂度 O(nlog(n)) end ------*/
```
* 上面的代码，$i, j, k$ 的计算部分不太好理解，我们通过一个具体的例子来理解下
* 数组 $a = [7, 1, 4, 8, 2, 3, 5, 4, 4, 7, 3]$
* 初始值：$i = 0(指向第 1 个元素 7), j = 0, k = 10(指向最后 1 个元素 7)$，选取 $p = 4$
* i = 0 时, (a[0]=7) > 4, 于是: swap(a[i], a[k--]), i=0 不变, k = k - 1 = 9, a=[3,1,4,8,2,3,5,4,4,7,7]
* i = 0 时, (a[0]=3) < 4, 于是：swap(a[i++], a[j++]), i=i+1=1, j=j+1=1, a=[3,1,4,8,2,3,5,4,4,7,7]
* i = 1 时, (a[1]=1) < 4, 于是：swap(a[i++], a[j++]), i=i+1=2, j=j+1=2, a=[3,1,4,8,2,3,5,4,4,7,7]
* i = 2 时, (a[2]=4) == 4, 于是：i=i+1=3, j=2不变, a=[3,1,4,8,2,3,5,4,4,7,7]
* i = 3 时, (a[3]=8) > 4, 于是：swap(a[i], a[k--]), i 不变, k = k - 1 = 8, a=[3,1,4,7,2,3,5,4,4,8,7]
* i = 3 时, (a[3]=7) > 4, 于是：swap(a[i], a[k--]), i 不变, k = k - 1 = 7, a=[3,1,4,4,2,3,5,4,7,7,8]
* i = 3 时, (a[3]=4) == 4, 于是：i=i+1=4, j=2不变, a=[3,1,4,4,2,3,5,4,7,7,8]
* i = 4 时, (a[4]=2) < 4, 于是：swap(a[i++], a[j++]), i=i+1=5, j=j+1=3, a=[3,1,2,4,4,3,5,4,7,7,8]
* i = 5 时, (a[5]=3) < 4, 于是：swap(a[i++], a[j++]), i=i+1=6, j=j+1=4, a=[3,1,2,3,4,4,5,4,7,7,8]
* i = 6 时, (a[6]=5) > 4, 于是：swap(a[i], a[k--]), i 不变, k = k - 1 = 6, a=[3,1,2,3,4,4,4,5,7,7,8]
* i = 6 时, (a[6]=4) == 4, 于是：i=i+1=7, j=4不变, a=[3,1,2,3,4,4,4,5,7,7,8]
* 此时 $(i=7) > (k=6)$，while 循环停止
* a[0:j-1] = a[0:3] = [3,1,2,3] 全部比 4 小
* a[j:k] = a[4:6] = [4,4,4] 全部等于 4
* a[k+1:10] = a[7:10] = [5,7,7,8] 全部大于 4

* **<font color="#FF0000">快速排序的时间复杂度是 $O(nlog(n))$, 分析方法类似归并排序</font>**
  * 每次将数组分成比 p 小的一段，和比 p 大的一段，按概率来讲，这种分法相当于平分
  * 因此快排大多数情况也只会分割 $log(n)$ 次
  * 而每次分割，同样最多需要比较 $O(n)$ 次
  * 因此快排的时间复杂度是 $O(nlog(n))$
* 需要注意的是
  * 如果运气不好，每次选取的 p 都是最小值（或者最大值）
  * 那么每次只能分割出比 p 大的一段（或者比 p 小的一段）
  * 此时快排的时间复杂度是 $O(n^2)$
  * **<font color="#FF0000">因此我们称快排的最差时间复杂度是 $O(n^2)$</font>**
* 可以在这个网站查看动图：[visualgo.net](https://visualgo.net/zh/sorting)

## 2-5、堆排序
* 堆排序类似于选择排序，总共执行 n - 1 轮，每一轮选出最大的数
* 不同于选择排序的是，**<font color="#FF0000">堆排序每次选出最大的数只需要比较 $O(log(n))$ 次</font>**
* 设数组 a=[91,60,96,13,35,65,46,65,10,30,20,21,77,81,22]（从 a[1] 到 a[15]）
* 我们将数组 a 的 15 个数，排列成下图的样子
  * 15 个数分成 4 层，每层分别有 1，2，4，8 个数
  * 前 3 层，每个数都向下连接 2 个其他数，数 a[i] 左下方的数是 a[i\*2]（称为 a[i] 的左儿子），右下方的数是 a[i\*2+1]（称为 a[i] 的右儿子）
  * **<font color="#FF0000">$n$ 个数，按上述方法，最多可分成 $O(log(n))$ 层</font>**

![最大堆](file://最大堆.jpg)

* 堆排序分为 2 步
* 第 1 步：从 a[15] 到 a[1] 遍历每个数，找出 a[i] 的儿子中最大的数 a[p]，如果 $a[p] > a[i]$，就交换 a[i] 和 a[p] 的值；如果交换之后 a[p] 的儿子中，也有比 a[p] 大的数，就继续交换；直到 a[p] 的 儿子都比 a[p] 小；
  * 第 1 步完成后，每个节点的数都比他的儿子节点要大
  * 所以此时，a[1] 必然是最大值
  * **<font color="#FF0000">我们把这种数据结构（每个节点都比其儿子节点大），称为最大堆</font>**
* 第 2 步：交换 a[1] 和 a[15] 的值，此时 a[15] 中存放的是最大的数，而 a[1] 的左右儿子中，可能会存在比 a[1] 大的数，继续按第 1 步中的方法往下交换
  * 此时，a[1] 中存放的数，必然是第 2 大的数，将 a[1] 与 a[14] 交换
  * 不断重复第 2 步 14 次（n - 1）次，即可完成排序
* 可参考下面的动图

![堆排序图解](file://堆排序.gif)

* 堆排序的实现如下
```c++
/*--------------------- 堆排序, 时间复杂度 O(nlog(n)) begin ------*/
#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

void down(int* a, int p, int n) {
    while (true) {
        int x = p;
        if (p * 2 <= n && a[p * 2] > a[x]) x = p * 2;
        if (p * 2 + 1 <= n && a[p * 2 + 1] > a[x]) x = p * 2 + 1;
        if (x == p) return ;
        swap(a[p], a[x]);
        p = x;
    }
}


// 将 a[1], a[2], ..., a[n - 1], a[n] 排序
// heap_sort(a, n);
void heap_sort(int* a, int n) {
    // 第 1 步
    for (int i = n / 2; i >= 1; i--) down(a, i, n);

    // 第 2 步
    for (int i = n; i > 1; i--) {
        swap(a[1], a[i]);
        down(a, 1, i - 1);
    }
}

/*--------------------- 堆排序, 时间复杂度 O(nlog(n)) end --------*/

int main() {
    int n;
    int a[N];
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    heap_sort(a, n);
    for (int i = 1; i <= n - 1; i++) cout << a[i] << ' ';
    cout << a[n] << '\n';
    return 0;
}
```
* 在第 1 步，每个数最多被交换 $O(long(n))$ 次
  * 因此第 1 步的时间复杂度最多是 $O(nlong(n))$，实际上其复杂度是 $O(n)$，可参考 [建堆时间复杂度的计算](https://www.jianshu.com/p/83842d5cb3e3)
* 第 2 步执行 $n-1$ 次，而每次最多将 a[1] 节点交换 $O(long(n))$ 次
  * 因此第 2 步的时间复杂度是 $O(nlong(n))$
* **<font color="#FF0000">所以堆排序的时间复杂度是 $O(nlong(n))$</font>**

## 2-6、自定义 sort

* 大家更多时候不需要自己编写排序函数，直接用 C++ 自带的 sort 函数即可
* C++ 自带的 sort 函数，默认是从小到大排序，语法如下
* 对 a[0: n) 排序(a[0], a[1], ..., a[n - 1]
  * sort(a, a + n)
* 对 a[l: r) 排序(a[l], a[l + 1], ..., a[r - 1])
  * sort(a + l, a + r)
* 对 a[1], a[2], a[3], a[4] 排序
  * sort(a + 1, a + 5)

```c++
#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int main() {
    int n;
    int a[N];
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    // 对 a[1], a[2], ..., a[n] 排序
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n - 1; i++) cout << a[i] << ' ';
    cout << a[n] << '\n';

    // 对 a[3], a[4], a[5], a[6] 排序
    sort(a + 3, a + 7);
    return 0;
}
```

* 如果想从大到小排序，应该怎么办呢？可以用到 sort 的自定义排序功能
* 自定义排序的语法
  * 大家不太理解语法的话，可以先记住，以后会理解

```c++
sort(a + 1, a + n + 1, [&](const int& x, const int& y) {
    // 你的比较逻辑
    // 判断 x 能否排在 y 前面,
    // 若 x 可以排在 y 前面, return true; 否则返回 false;

    // 从小到大排序
    // [1, 3, 5, 2, 4] -> [1, 2, 3, 4, 5]
    if (x < y) return true;  // x 比 y 小的时候, x 能排在 y 前面 
    return false;

    // 也可以简写成 
    // return x < y;
}); 

sort(a + 1, a + n + 1, [&](const int& x, const int& y) {
    // 从大到小排序
    // [1, 3, 5, 2, 4] -> [5, 4, 3, 2, 1]
    if (x > y) return true;  // x 比 y 大的时候, x 能排在 y 前面 
    return false;

    // 也可以简写成 
    // return x > y;
});
```

* 除了简单的从小到大和从大到小，还可以自定义更复杂的排序逻辑

```c++
#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int main() {
    int n;
    int a[N];
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    // 对 a[1], a[2], ..., a[n]
    // 奇数排前, 偶数排后, 同奇偶的数从小到大
    // [5, 4, 3, 2, 1] -> [1, 3, 5, 2, 4]
    sort(a + 1, a + n + 1, [&](const int& x, const int& y) {
        int p = x % 2, q = y % 2;
        // 同奇偶的情况下, 小的排在前面
        if (p == q) return x < y;
        // 不同奇偶的情况下, x 如果是奇数, 就能排在 y 前面
        if (p == 1) return true;
        return false;
    });    

    for (int i = 1; i <= n - 1; i++) cout << a[i] << ' ';
    cout << a[n] << '\n';

    int b[N];
    for (int i = 1; i <= n; i++) b[i] = i;
    // 假设数组 a 是 [6, 8, 10, 7, 9]
    // 那么数组 b 是 [1, 2, 3, 4, 5]
    // 排序之后的数组 b 是 [1, 4, 2, 5, 3]
    // 因为 (a[1]=6) < (a[4]=7) < (a[2]=8) < (a[5]=9) < (a[3]=10)
    sort(b + 1, b + n + 1, [&](const int& x, const int& y) {
        // 如果 a[x] < a[y], 那么在数组 b 中 x 就能排在 y 前面
        return a[x] < a[y];
    });
    for (int i = 1; i <= n - 1; i++) cout << b[i] << ' ';
    cout << b[n] << '\n';    
    return 0;
}
```
