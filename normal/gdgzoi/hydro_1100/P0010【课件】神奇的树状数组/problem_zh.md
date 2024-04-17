- [1、单点修改，区间查询](#1单点修改区间查询)
  - [1-1、lowbit() 函数](#1-1lowbit-函数)
  - [1-2、树状数组的定义](#1-2树状数组的定义)
  - [1-3、树状数组的求和](#1-3树状数组的求和)
  - [1-4、树状数组的更新](#1-4树状数组的更新)
  - [1-5、树状数组模板](#1-5树状数组模板)
- [2、区间修改，单点查询](#2区间修改单点查询)
  - [2-1、差分与前缀和](#2-1差分与前缀和)
  - [2-2、用树状数组维护差分数组](#2-2用树状数组维护差分数组)
- [3、区间修改，区间查询](#3区间修改区间查询)
- [4、权值树状数组](#4权值树状数组)
  - [4-1、全局逆序对](#4-1全局逆序对)
  - [4-2、登峰造极：平衡树](#4-2登峰造极平衡树)
- [5、二维树状数组（以后再讲）](#5二维树状数组以后再讲)


# 1、单点修改，区间查询
树状数组（Binary Indexed Tree, BIT）是能够完成下述操作的数据结构

给定一个初始值全为 0 的数列 $a_0, a_1, \dots, a_n$
* **<font color="#00DD00">计算数组 $a$ 的前缀和 $sum(i)$</font>**：给定 $i$，计算 $a_1+a_2+\dots+a_i$
* **<font color="#00DD00">更新数组 $a$ 中某个数的值</font>**：给定 $i$ 和 $x$，执行 $a_i+=x$
  
例题：[P1101.【普及】树状数组 1：单点修改，区间查询](http://www.gzezoi.cn/d/gzezoi2023/p/P1101)
  * 例题中要求 $a_l+a_{l+1}\dots+a_r$，这其实等于 2 个前缀和的差 $sum(r) - sum(l-1)$

尝试用如下 3 种方法解决问题
* 1、直接模拟
  * 求前缀和：O(n)，单点更新：O(1)
* 2、维护一个前缀和数组
  * 求前缀和：O(1)，单点更新：O(n)
* 3、将数组分成 $sqrt(n)$ 块，每块里有 $sqrt(n)$ 个数，维护每块里面的数的和
  * 求前缀和：O(sqrt(n))，单点更新：O(1)
  * **<font color="#00DD00">分块是非常重要的思想，以后会专门训练</font>**

**<font color="#00DD00">而树状数组，可以将更新和查询操作的复杂度都保持在 $O(log(n))$，同时非常简洁，好写</font>**

## 1-1、lowbit() 函数
我们首先来认识一个神奇的二进制操作

* $lowbit(x)$：找到 $x$ 的二进制表达中最靠右的 $1$（也就是最低位的 $1$），将除这个 $1$ 以外的其他 $1$ 全部变成 $0$

![img](file://lowbit.png)

在 表 1 中，我们从第 0 行（黄色）开始观察

* 十进制数 $53$ 的二进制表达式为 $(0110101)_2$（高位省略）
* 保留最靠右的 1，其余的 1 全部变成 0，得到 $lowbit(53)=(0000001)_2=1$（绿色部分）
* 看第 -1 行：$53-lowbit(53)=(0110101)_2-(0000001)_2=(0110100)_2=52$
* 看第 1 行：$53+lowbit(53)=(0110101)_2+(0000001)_2=(0110110)_2=54$

我们可以发现如下 2 个规律
* **<font color="#00DD00">不断的执行 $x = x - lowbit(x)$，最多执行 $log(x) + 1$ 次，$x$ 将变成 0</font>**
  * 每次执行，$x$ 的二进制表达中 $1$ 的个数都会 -1，而 $x$ 的二进制中 $1$ 的个数不会超过 $log(x) + 1$
* 不断的执行 $x = x + lowbit(x)$，最多执行 $log(x) + 1$ 次，$x$ 将变成 $2$ 的整数幂；而之后继续执行的话，$x$ 每次都变成 $x=x*2$
  * **<font color="#00DD00">那么对于某个 $y > x$，最多执行 $log(y)$ 次 $x = x + lowbit(x)$，就会有 $x >= y$</font>**

那么如何计算 lowbit(x) 呢？
```c++
int lowbit(x) {
    return x & (-x);  // 负数的二进制是补码, 也就是反码+1
}

for (; x > 0; x -= lowbit(x));   // 最多执行 log(x) + 1 次
for (; x <= n; x -= lowbit(x));  // 最多执行 log(n) + 1 次
```

## 1-2、树状数组的定义
树状数组在原数组 $a[1..n]$ 的基础上，维护一个新的数组 $c[1..n]$，我们以 $n = 8$ 为例

![img](file://树状数组.png)

在 表-2 中，树状数组的值 $c[x] = sum(a[x - lowbit(x) + 1], ..., a[x])$
* 也就是说，**<font color="#00DD00">$c[x]$ 存储了从 $a[x]$ 开始往前数 $lowbit(x)$ 个数的和（包含 $a[x]$）</font>**

![img](file://树状数组的形态.png)

## 1-3、树状数组的求和
计算前 $sum(a[1], ..., a[i])$ 的和需要从 $i$ 开始，不断把当前位置的 $c[i]$ 加到结果中，然后令 $i = i - lowbit(i)$，直到 $i == 0$

* 由 $lowbit()$ 函数的性质 1 可知，这一步的时间复杂度是 $O(log(i))$

![img](file://树状数组求和.png)

## 1-4、树状数组的更新
更新 $a[i] += x$ 需要从 $i$ 开始，不断的更新 $c[i] += x$，然后令 $i = i + lowbit(i)$，直到 $i > n$

* 由 $lowbit()$ 函数的性质 2 可知，这一步的时间复杂度是 $O(log(n))$

![img](file://树状数组更新.png)

## 1-5、树状数组模板

```c++
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

template <typename T>  // 使用 template 模板, 用法见定义
struct Fenwick {
	int n;
	vector<T> a;
	
	Fenwick(int N) {
        n = N;
        // 注意: 树状数组都是从 1 开始编号 a[1..n], 不要从 0 开始
        // 相当于 a = vector<int>(n + 1, 0)
		a.resize(n + 1, 0);
	}
	
    // 更新操作, 不断 p += lowbit(p)
	void add(int p, T v) {
		for (; p <= n; p += p & -p) a[p] += v;
	}
	
    // 求前缀和: sum(a[1..p]), 不断 p -= lowbit(p)
	T get(int p) {
		T ans = 0;
		for (; p > 0; p -= p & -p) ans += a[p];
		return ans;
	}
	
    // 求区间和: sum(a[1..r]) - sum(a[1..(l-1)])
	T get(int l, int r) {
		return get(r) - get(l - 1);
	}
};

int main() {
    // 下面 2 句话是为了让 cin 更快，比赛时一定要写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int n, m, x, y, z;
	cin >> n >> m;

    // 利用 template, 申明为 LL 的树状数组
    // Fenwick<int> 可以申明为 int 的树状数组
	Fenwick<LL> a(n);
    for (int i = 1; i <= n; i++) {
        cin >> x;
        a.add(i, x);
    }

    while (m--) {
        cin >> x >> y >> z;
        if (x == 1) a.add(y, z);           // 更新
        else cout << a.get(y, z) << '\n';  // 求前缀和
    }

    return 0;
}
```

# 2、区间修改，单点查询
通过计算原数组的差分数组，树状数组同样可以解决区间修改，单点查询的问题。
## 2-1、差分与前缀和
例题：[P1104.【普及】差分与前缀和](http://www.gzezoi.cn/d/gzezoi2023/p/P1104)
一个数组的差分数组是指这样一个数组
```c++
// 假设数组从 1 开始编号, 即 a[1] = 2, a[2] = 6,..., a[5] = 1
int n = 5
// 原数组 a = [2, 6, 6, 1, 1]
int a[5] = [2, 6, 6, 1, 1];

// 差分数组 b = [2, 4, 0, -5, 0]
int b[5];
b[1] = a[1];
for (int i = 2; i <= n; i++) b[i] = a[i] - a[i - 1];

while (m--) {  // m 是操作数
    cin >> l >> r >> x;  // 将 a[l..r] += x;
    b[l] += x, b[r + 1] -= x;
}

// 求出 b 的前缀和, 即是原数组
for (int i = 2; i <= n; i++) b[i] += b[i - 1];
```
* 对于差分数组 $b$，我们有 $a[i] = sum(b[1],b[2],...,b[i])$
* 也就是说, **<font color="#00DD00">对差分数组 $b[]$ 求前缀和，就可以得到原数组 $a[]$</font>**

* 在原数组 $a$ 上的区间操作 $a[l..r] += x$，可以转变成在差分数组上的单点操作 $b[l] += x, b[r + 1] -= x$
* 在原数组 $a$ 上的单点查询 $a[i]$，可以转变成在差分数组上求前缀和 $sum(b[1],b[2],...,b[i])$

## 2-2、用树状数组维护差分数组
再来看下面的例题，需要在区间修改的同时，实时查询单点的值

例题：[P1102.【普及】树状数组 2：区间修改，单点查询](http://www.gzezoi.cn/d/gzezoi2023/p/P1102)

那么，我们直接用树状数组来维护差分数组就好
```c++
// 注意树状数组从 1 开始编号, 1..n, 不要从 0 开始
Fenwick<LL> b(n + 1);
for (int i = 1; i <= n; i++) {
	b.add(i, a[i] - a[i - 1]);  // 计算差分
}
while (m--) {
    cin >> c;
    if (c == 1) {
        cin >> l >> r >> v;
        b.add(l, v);
        b.add(r + 1, -v);
    } else {
        cin >> l;
        cout << b.get(l) << '\n';
    }
}
```

# 3、区间修改，区间查询
例题：[P1103.【普及】树状数组 3：区间修改，区间查询](http://www.gzezoi.cn/d/gzezoi2023/p/P1103)

我们沿用差分数组的思想，但是现在要求的区间和 $sum(a[l..r])$，还是沿用前缀和相减的方法，来考虑如何求 $a[1..r]$ 的和

$$
\begin{aligned}
&\sum_{i=1}^{r} a_i
\\=&\sum_{i=1}^r\sum_{j=1}^i b_j
\\=&\sum_{i=1}^r b_i\times(r-i+1)
\\=&\sum_{i=1}^r b_i\times (r+1)-\sum_{i=1}^r b_i\times i
\end{aligned}
$$
可以考虑用 2 个树状数组，一个用来维护差分数组 $b$，另一个维护 $b_i \times i$

当执行更新操作 $a[l..r] += x$ 时
* 对于维护差分数组 $b$ 的树状数组, 对 $l$ 单点加 $v$，$r + 1$ 单点加 $-v$
* 对于维护 $d_i \times i$ 的树状数组，对 $l$ 单点加 $v \times l$，$r + 1$ 单点加 $-v \times (r + 1)$。

```c++
// b: 差分数组的树状数组, bi: 维护 b_i * i 
Fenwick<LL> b(n + 1), bi(n + 1);
for (int i = 1; i <= n; i++) {
    cin >> x;
    b.add(i, x), b.add(i + 1, -x);
    bi.add(i, (LL) i * x), bi.add(i + 1, (LL) -(i + 1) * x);
}
while (m--) {
    cin >> c;
    if (c == 1) {
        cin >> l >> r >> x;
        b.add(l, x), b.add(r + 1, -x);
        bi.add(l, (LL) l * x), bi.add(r + 1, (LL) -(r + 1) * x);
    } else {
        cin >> l >> r;
        LL sumr = b.get(r) * (r + 1) - bi.get(r);    // sum(a[1..r])
        LL suml = b.get(l - 1) * l - bi.get(l - 1);  // sum(a[1..(l-1)])
        cout << sumr - suml << '\n';
    }
}
```

# 4、权值树状数组
我们知道，普通树状数组直接在原序列的基础上构建，$c_6$ 表示的就是 $a[5 \ldots 6]$ 的区间信息。

然而事实上，我们还可以在原序列的权值数组上构建树状数组，这就是权值树状数组。

## 4-1、全局逆序对
例题：[P1105.【普及】全局逆序对](http://www.gzezoi.cn/d/gzezoi2023/p/P1105)

题意是说对于每个数 $a_i$，要求排在 $a_i$ 之后，但比 $a_i$ 小的数的个数

事实上，这就是冒泡排序中总的交换次数，这个交换总数，我们称之为全局逆序对数。

考虑下面的做法：
```c++
// n 是数组 a 的长度, m 是数组 a 中最大的数
int n = 6, m = 6;
vector<int> a = {5, 4, 2, 6, 3, 1};

// b 数组用来记录 a 中每个数出现的次数
vector<LL> b(m + 1, 0);

// 从后往前扫描 a
LL ans = 0;
for (int i = n - 1; i >= 0; i--) {
    // 统计 a[i] 右边比 a[i] 小的数
	LL cnt = 0;
	for (int j = a[i] - 1; j >= 1; j--) cnt += b[j]; // 求前缀和
	ans += cnt;
	b[a[i]]++;  // a[i] 出现的次数 +1, 单点更新
}
cout << ans << '\n';
```

**<font color="#00DD00">数组 $b$ 成为数组 $a$ 的权值数组</font>**，需要支持单点更新和求前缀和 2 个操作，而这正是树状数组所擅长的。

于是我们可以改进上面的代码

```c++
// n 是数组 a 的长度, m 是数组 a 中最大的数
int n = 6, m = 6;
vector<int> a = {5, 4, 2, 6, 3, 1};

// b 数组用来记录 a 中每个数出现的次数
Fenwick<LL> b(m + 1);

// 从后往前扫描 a
LL ans = 0;
for (int i = n - 1; i >= 0; i--) {
	ans += b.get(a[i] - 1);  // 统计 a[i] 右边比 a[i] 小的数, 求前缀和
	b.add(a[i], 1);  // a[i] 出现的次数 +1, 单点更新
}
cout << ans << '\n';
```

可现在还有一个问题，就是 $m$ 的值，题目中 $m$ 最大可能是 $10^9$，我们不可能开一个长度是 $10^9$ 的数组
* 考虑到数组的长度 $n$ 只有 $5 \times 10^5$
* 因此数组 $a$ 中最多只有 $5 \times 10^5$ 个不同的数
* **<font color="#00DD00">能不能将 $a$ 中的值，按大小映射到 $5 \times 10^5$ 以内呢？这个操作，我们称之为离散化</font>**

```c++
int n = 6;
vector<int> a = {15, 14, 14, 16, 13, 11};

vector<int> c = a;  // 用来离散化的数组
// 离散化三连: 排序(sort), 去重(unique), 重新赋值(lower_bound)
sort(c.begin(), c.end());                      // 第 1 步: 排序, {11, 13, 14, 14, 15, 16}
c.erase(unique(c.begin(), c.end()), c.end());  // 第 2 步: 去重, {11, 13, 14, 15, 16}
int e = c.size();                              // e: 是不同数的个数
for (int i = 0; i < n; i++) {
    // 第 3 步: 给数组 a 里的数重新赋值到 1..e
    // 注意: 一定是 1..e, 从 1 开始, 因为后面要用树状数组
    a[i] = lower_bound(c.begin(), c.end(), a[i]) - c.begin() + 1;
}
// 将 a 映射到 1..e: a = {4, 3, 3, 5, 2, 1}
```

## 4-2、登峰造极：平衡树
例题：[P1106.【提高】普通平衡树](http://www.gzezoi.cn/d/gzezoi2023/p/P1106)

此题的关键在于操作4，查询排名第 $k$ 的数
* 一个直观的想法是二分答案（$O(log(n))$），然后判断（O($log(n)$)），复杂度是 $O(log(n)^2)$
* 但更优的做法是利用树状数组的性质 

假设我们的数组 $a=[3, 9, 6, 5, 7]$，那么权值数组和对应的树状数组如下（也就是每个数计数），我们要查询排名第 $k=3$ 的数（也就是 6）

![img](file://权值数组.png)

* 我们考虑 **<font color="#00DD00">按二进制位，从高位到低位枚举，来查找最后 1 个 满足 $c[x] < k$ 的 $x$，从而 $x + 1$ 就是我们的答案</font>**
* 首先看答案的最高位（最低位是第 0 位，最高位是第 3 位）能否是 1
  * 由于 $c[8] = 4$，也就是说从 $0001$ 到 $1000$ 有 4 个数（树状数组的性质）
  * 因此 $x < 8$，也就是说二进制最高位肯定是 0（$0???$）
* 再看答案的第 2 位能否是 1
  * 由于 $c[4] = 1$，也就是说从 1($0001$) 到 4($0100$) 有 1 个数
  * 因此 $x >= 4$，也就是这个二进制位肯定是 1（$01??$）
  * 我们要在 4($0100$) 到 7($0111$) 之间查找最后 1 个 满足 $c[x] < (k - c[4] = 3 - 1 = 2)$ 的 $x$ 
*  再看答案的第 1 位能否是 1
   *  由于 $c[6] = 2$，也就是说从 5($0101$) 到 6($0110$) 有 2 个数
   *  因此 $x < 6$，也就是这个二进制位肯定是 0（$010?$）
*  再看答案的第 0 位能否是 1
   *  由于 $c[5] = 1$，也就是说从 4($0101$) 到 5($0110$) 有 1 个数
   *  因此 $x >= 5$，也就是这个二进制位肯定是 1（$0101$）
*  自此，我们得出 $5 \leq x < 6$，也就是说 $x = 5$ 是最后 1 个 满足 $c[x] < k$ 的 $x$，那么排名第 $k=3$ 的数就是 $x+1=6$
*  **<font color="#00DD00">由于是按二进制位枚举，每次确定二进制的一位，所以复杂度是 $O(log(n))$ </font>**

操作5（前驱） 和操作 6（后继），都可以通过操作 3和操作 4 来表示

<details>
  <summary> <font color="#00DD00">点击查看：用树状数组实现平衡树</font> </summary>

```c++
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct Fenwick {
	int n, lgn;
	vector<T> a;
	
	Fenwick(int n) : n(n) {
        // 使得 2^lgn > n
        // 比如 n = 5, lgn = 8; n = 8, lng = 16
		for (lgn = 0; (1 << lgn) <= n; lgn++);  // 2^lgn > n

        // 数组从 1 到 n, [1..n]
        // 相当于 a = vector<int>(n + 1, 0)
		a.resize(n + 1, 0);
	}
	
	void add(int p, T v) {
		for (; p <= n; p += p & -p) a[p] += v;
	}
	
	T get(int p) {
		T ans = 0;
		for (; p > 0; p -= p & -p) ans += a[p];
		return ans;
	}
	
	T get(int l, int r) {
		return get(r) - get(l - 1);
	}

	// 请重点理解这个函数
    // 查询从小到大排序后, 排名第 k 的数,
    int kth(T k) {
        int p = 0;
        for (int i = lgn - 1; i >= 0; i--) {
            p += 1 << i;
            if (p > n || a[p] >= k) p -= 1 << i;
            else k -= a[p];
        }
        return p + 1;
    }

    // 查询 x 的排名
    T rnk(int x) {
		return get(x - 1) + 1;
    }

	// 比 x 小的数里面最大的数
	int pre(int x) {
		return kth(get(x - 1));
	}

	// 比 x 大的数里面最小的数
	int suf(int x) {
		return kth(get(x) + 1);
	}
};

int main() {
    // 这两句是为了让 cin 更快
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	vector<int> cmd(n), x(n), c;
	for (int i = 0; i < n; i++) {
		cin >> cmd[i] >> x[i];
		// cmd[i] = 4 时, 是问排名为 x[i] 的数, 不需要离散化
		if (cmd[i] != 4) c.push_back(x[i]);
	}

    // 离散化三板斧, sort, erase/unique, lower_bound
	sort(c.begin(), c.end());
	c.erase(unique(c.begin(), c.end()), c.end());
	int e = c.size();
	for (int i = 0; i < n; i++) if (cmd[i] != 4) {  // cmd[i] = 4 时, 是问排名, 不需要离散化
        // x[i] 从 1 开始编号
		x[i] = lower_bound(c.begin(), c.end(), x[i]) - c.begin() + 1;
	}
	
	Fenwick<int> a(e + 1);
	for (int i = 0; i < n; i++) {
		if (cmd[i] == 1) a.add(x[i], 1);                           // 插入 x[i]
        else if (cmd[i] == 2) a.add(x[i], -1);                     // 删除 x[i]
        else if (cmd[i] == 3) cout << a.rnk(x[i]) << '\n';         // x[i] 的排名
        else if (cmd[i] == 4) cout << c[a.kth(x[i]) - 1] << '\n';  // 排名为 x[i] 的数
        else if (cmd[i] == 5) cout << c[a.pre(x[i]) - 1] << '\n';  // 比 x[i] 小的数中最大的
        else if (cmd[i] == 6) cout << c[a.suf(x[i]) - 1] << '\n';  // 比 x[i] 大的数中最小的
	}
	return 0;
}
```
</details>

# 5、二维树状数组（以后再讲）
