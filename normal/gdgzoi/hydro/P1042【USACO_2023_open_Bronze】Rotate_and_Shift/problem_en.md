# 题目描述

To celebrate the start of spring, Farmer John's N cows ($1\le N \le 2⋅10^5
$) have invented an intriguing new dance, where they stand in a circle and re-order themselves in a predictable way.

Specifically, there are N positions around the circle, numbered sequentially from $0$ to $N−1$, with position $0$ following position $N−1$. A cow resides at each position. The cows are also numbered sequentially from $0$ to $N−1$. Initially, cow $i$ starts in position $i$. You are told a set of $K$ positions $0=A_1 \lt A_2 \lt … \lt A_K \lt N$ that are "active", meaning the cows in these positions are the next to move ($1 \le K \le N$).

In each minute of the dance, two things happen. First, the cows in the active positions rotate: the cow at position $A_1$ moves to position $A_2$, the cow at position $A_2$ moves to position $A_3$, and so on, with the cow at position $A_K$ moving to position $A_1$. All of these $K$ moves happen simultaneously, so the after the rotation is complete, all of the active positions still contain exactly one cow. Next, the active positions themselves shift: $A_1$ becomes $A_1+1$, $A_2$ becomes $A_2+1$, and so on (if $A_i=N−1$ for some active position, then $A_i$ circles back around to 0).

Please calculate the order of the cows after $T$ minutes of the dance ($1 \le T \le 10^9$).

# 输入格式

The first line contains three integers $N$, $K$, and $T$.

The second line contains $K$ integers representing the initial set of active positions $A_1,A_2,...,A_K$. Recall that $A_1=0$ and that these are given in increasing order.

# 输出格式
Output the order of the cows after $T$ minutes, starting with the cow in position $0$, separated by spaces.

```input1
5 3 4
0 2 3
```

```output1
1 2 3 4 0
```

# 提示
For the example above, here are the cow orders and $A$ for the first four timesteps:

Initial, T = 0: order = [0 1 2 3 4], A = [0 2 3]

T = 1: order = [3 1 0 2 4]

T = 1: A = [1 3 4]

T = 2: order = [3 4 0 1 2]

T = 2: A = [2 4 0]

T = 3: order = [2 4 3 1 0]

T = 3: A = [3 0 1]

T = 4: order = [1 2 3 4 0]  

# 数据规模与限制
* Inputs 2-7: $N \le 1000, T \le 10000$
* Inputs 8-13: No additional constraints.
* 1s, 1024KiB for each test case.

# 来源
* [【USACO_2023_open_Bronze】Problem_3_Rotate_and_Shift](http://www.usaco.org/index.php?page=viewproblem2&cpid=1325)