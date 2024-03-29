# 题目描述

给你 1 个空数组 $a$，现在要依次插入 $n$ 个数到数组 $a$ 里面，请在每次插入后输出，当前数组中众数的个数，以及每个众数出现的次数

# 输入格式

第 1 行包含 1 个整数正 $n(1 \le n \le 10^5), 表示插入数的个数

接下来 1 行包含 $n$ 个正整数，用空格分开

# 输出格式
输出 $n$ 行，每行 2 个整数用空格分开，分别表示每次插入后众数的个数，和每个众数出现的次数

```input1
7
1 2 3 1 2 3 1
```

```output1
1 1
2 1
3 1
1 2
2 2
3 2
1 3
```

# 提示
* 样例解释
* 当 a = [1] 时，众数是 [1], 出现的次数是 1
* 当 a = [1,2] 时，众数是 [1,2], 出现的次数是 1
* 当 a = [1,2,3] 时，众数是 [1,2,3], 出现的次数是 1
* 当 a = [1,2,3,1] 时，众数是 [1], 出现的次数是 2
* 当 a = [1,2,3,1,2] 时，众数是 [1,2], 出现的次数是 2
* 当 a = [1,2,3,1,2,3] 时，众数是 [1,2,3], 出现的次数是 2
* 当 a = [1,2,3,1,2,3,1] 时，众数是 [1], 出现的次数是 3
* 考虑用 map<int, int> 实时存储每个数出现的次数
```c++
map<int, int> q;
for (int i = 0; i < n; i++) {
    cin >> x;
    // 当 map 中不存在 x 时, q[x] 默认是 0
    q[x]++;
}
```

# 数据规模与限制
* $1 \le n \le 10^5, 1 \le a[i] \le 10^9$
* 1s, 1024KiB for each test case.