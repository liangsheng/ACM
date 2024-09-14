- [0、解决动态规划问题的一般步骤](#0解决动态规划问题的一般步骤)
- [1、从左往右的动规](#1从左往右的动规)
  - [1-1、一维](#1-1一维)
  - [1-2、二维](#1-2二维)
- [2、从左上到右下的动规](#2从左上到右下的动规)
- [3、从任意点开始到任意点结束的动规（记忆化搜索）](#3从任意点开始到任意点结束的动规记忆化搜索)
- [4、从短到长的动规（区间动规）](#4从短到长的动规区间动规)
- [5、环形动规](#5环形动规)
- [6、【提高】整数划分问题](#6提高整数划分问题)
- [7、【提高】数位动规](#7提高数位动规)

# 0、解决动态规划问题的一般步骤
- 1、状态怎么表示
- 2、状态怎么转移
- 3、状态的初始值要如何确定

# 1、从左往右的动规
- 状态表示：$dp[i]$ 表示前 $i$ 个元素的某个性质
- 状态转移：由 $dp[1], dp[2], \cdots dp[i]$ 来推出 $dp[i + 1]$
- [背包问题](https://www.gzezoi.cn/d/gzezoi2023/p/P0008) 就是最常见的从左往右的动规（由前 $i$ 个物品推出前 $i+1$ 个物品）

## 1-1、一维
[P1016.【入门】最大子数组和](https://www.gzezoi.cn/d/gzezoi2023/p/P1016)
- 【题意】给你一个整数数组 $a$ ，请你找出一个具有最大和的连续子数组
- 【状态表示】$dp[i]$ 表示以 $a[i]$ 结尾的最大子数组和
- 【状态转移】
$$
\begin{equation}
dp[i] = \left\{
\begin{array}{lr}
a[i], & 不需要a[i]之前的数 \\
dp[i-1]+a[i], & 需要a[i]之前的数
\end{array}
\right.
\end{equation}
$$
- 最后的结果就是 $max(dp[0], dp[2], \cdots, dp[n-1])$
- 状态的个数是 $O(n)$，转移是 $O(1)$，所以时间复杂度是 $O(n)$
- [参考代码](https://www.gzezoi.cn/d/gzezoi2023/record/6559b97df7726adb17dd3ad8)


[P1113.【入门】最长上升子序列_简单版](https://www.gzezoi.cn/d/gzezoi2023/p/P1113)
- 【题意】给定一个长度为 $n$ 的数组 $a$，求数值严格单调递增的子数组（不一定要连续）的长度最长是多少。
- 【状态表示】$dp[i]$ 表示以 $a[i]$ 结尾的最长子数组长度
- 【状态转移】
$$
dp[i] = max\{dp[j]+1 \;| \; \forall \; 0 \le j < i, \; a[j] < a[i]\}
$$
- 公式中的 $\forall$ 表示 对任意的 
- 最后的结果就是 $max(dp[0], dp[2], \cdots, dp[n-1])$
- 状态的个数是 $O(n)$，转移是 $O(n)$，所以时间复杂度是 $O(n^2)$
- [参考代码](https://www.gzezoi.cn/d/gzezoi2023/record/662f67279118344962471efb)

[P1114.【入门】最长上升子序列_困难版](https://www.gzezoi.cn/d/gzezoi2023/p/P1114)
- 【题意】同上一题，但是 $n$ 最大是 $10^5$，$O(n^2)$ 的做法太慢，需要 $O(nlog(n))$ 的做法
- **<font color="#00BB00">复杂度中有 $log(n)$，一般来说不是二分答案，就是和二进制相关</font>**
- 【状态表示】$dp[i]$ 表示长度为 $i+1$ 的子序列的最后一个数的最小值
- 那么，$dp$ 必然是单调上升的（$dp[i] < dp[i+1]$），思考下为什么？
- 既然是单调上升的，就可以二分查找
- 状态的个数是 $O(n)$，转移是 $O(log(n))$，所以时间复杂度是 $O(n^2)$
- [参考代码](https://www.gzezoi.cn/d/gzezoi2023/record/661c9b7d46e7b78e56ee0712)

## 1-2、二维
[P1115.【入门】最长公共子序列](https://www.gzezoi.cn/d/gzezoi2023/p/P1115)
- 【题意】给定两个长度分别为 $n$ 和 $m$ 的字符串 $s$ 和 $t$，求既是 $s$ 的子序列又是 $t$ 的子序列的字符串长度最长是多少。
- 【状态表示】$dp[i][j]$ 表示 $s[1..i]$ 和 $t[1..j]$ 的最长公共子序列长度
- 【状态转移】
$$
\begin{equation}
dp(i,j) = max\left\{
\begin{array}{lr}
dp(i-1,j), & 没有用到 \; s[i] \\
dp(i,j-1), & 没有用到 \; t[j]  \\
dp(i-1,j-1), & s[i] \not= t[j] \\
dp(i-1,j-1)+1, & s[i] == t[j] \\
\end{array}
\right.
\end{equation}
$$
- 最后的结果就是 $dp(n,m)$
- 状态的个数是 $O(n^2)$，转移是 $O(1)$，所以时间复杂度是 $O(n^2)$
- [参考代码](https://www.gzezoi.cn/d/gzezoi2023/record/661ca1ef46e7b78e56ee0733)

[P1116.【入门】最短编辑距离](https://www.gzezoi.cn/d/gzezoi2023/p/P1116)
- 【题意】给定两个字符串 $s$ 和 $t$，可以通过插入，删除，替换字符的操作将 $s$ 变为 $t$，请问最少的操作次数。
- 【状态表示】$dp[i][j]$ 表示 $s[1..i]$ 和 $t[1..j]$ 的最短编辑距离
- 【状态转移】
$$
\begin{equation}
dp(i,j) = max\left\{
\begin{array}{lr}
dp(i-1,j)+1, & 删除 \; s[i] \\
dp(i,j-1)+1, & 在 \; s[i] \; 后增加 \; t[j]  \\
dp(i-1,j-1), & s[i] == t[j] \\
dp(i-1,j-1)+1, & 将 \; s[i] \; 改成 \; t[j] \\
\end{array}
\right.
\end{equation}
$$
- 最后的结果就是 $dp(n,m)$
- 状态的个数是 $O(n^2)$，转移是 $O(1)$，所以时间复杂度是 $O(n^2)$
- [参考代码](https://www.gzezoi.cn/d/gzezoi2023/record/661cc63d46e7b78e56ee0848)

# 2、从左上到右下的动规
- 此类问题和从左往右的动规类似
- 状态表示：$dp(i,j)$ 表示 $(1, 1)$ 到 $(i, j)$ 的某个性质
- 状态转移：由 $dp(1..i-1,1..j-1)$ 来推出 $dp(i,j)$

[P1127.【入门】最大子正方形](https://www.gzezoi.cn/d/gzezoi2023/p/P1127)
- 【题意】给你一个只由 $0$ 和 $1$ 组成的二维矩阵 $g$，请你求出只包含 $1$ 的最大正方形的面积
- 【状态表示】
  - $L[i][j]$ 表示从 $(i, j)$ 开始往 `左` 数有多少个连续的 1
  - $U[i][j]$ 表示从 $(i, j)$ 开始往 `上` 数有多少个连续的 1
  - $dp[i][j]$ 表示以 $(i, j)$ 为 `右下角` 的最大正方形的边长
- 【状态转移】当 $g[i][j] == 1$ 时，有
$$
\begin{equation}
dp(i,j) = min\left\{
\begin{array}{lr}
L(i,j-1)+1, & 底边的最大值 \\
U(i-1,j)+1, & 右边的最大值 \\
dp(i-1,j-1)+1, & 内部的最大值 \\
\end{array}
\right.
\end{equation}
$$
- 最后的结果就是 $dp$ 的最大值的平方
- 状态的个数是 $O(n^2)$，转移是 $O(1)$，所以时间复杂度是 $O(n^2)$
- [参考代码](https://www.gzezoi.cn/d/gzezoi2023/record/6630a65491183449624720a9)

[P1118.【入门】卖木头块](https://www.gzezoi.cn/d/gzezoi2023/p/P1118)
- 【题意】给你一个矩形木块，你可以将沿着水平或垂直方向切割木板，切割得到的小木板可以卖钱（不同尺寸的小木板价钱不同），问最多能卖多少钱
- 【状态表示】$dp[i][j]$ 表示形状为 $i \times j$ 的木板最多能卖的钱数
- 【状态转移】
$$
\begin{equation}
dp(i,j) = max\left\{
\begin{array}{lr}
price(i,j), & 不切，直接卖 \\
max\{dp(k,j)+dp(i-k,j)\;| \; \forall \; 1 \le k < i\}, & 水平切一刀 \\
max\{dp(i,k)+dp(i,j-k)\;| \; \forall \; 1 \le k < j\}, & 垂直切一刀 \\
\end{array}
\right.
\end{equation}
$$
- 最后的结果就是 $dp(n,m)$
- 状态的个数是 $O(n^2)$，转移是 $O(n)$，所以时间复杂度是 $O(n^3)$
- [参考代码](https://www.gzezoi.cn/d/gzezoi2023/record/661e30a746e7b78e56ee1241)

# 3、从任意点开始到任意点结束的动规（记忆化搜索）
- [P1117.【入门】记忆化搜索_滑雪](https://www.gzezoi.cn/d/gzezoi2023/p/P1117)

# 4、从短到长的动规（区间动规）
- [P1119.【入门】区间动规_石子合并_简单版](https://www.gzezoi.cn/d/gzezoi2023/p/P1119)

# 5、环形动规
- [P1120.【入门】区间动规_石子合并_困难版](https://www.gzezoi.cn/d/gzezoi2023/p/P1120)

# 6、【提高】整数划分问题
- [P1121.【提高】整数划分问题_多重部分和](https://www.gzezoi.cn/d/gzezoi2023/p/P1121)
- [P1122.【提高】整数划分问题_划分数](https://www.gzezoi.cn/d/gzezoi2023/p/P1122)
- [P1123.【提高】整数划分问题_多重集组合数](https://www.gzezoi.cn/d/gzezoi2023/p/P1123)

# 7、【提高】数位动规
- [P1125.【普及】数位动规_不要62](https://www.gzezoi.cn/d/gzezoi2023/p/P1125)
- [P1126.【提高】数位动规_吉哥系列故事_恨7不成妻](https://www.gzezoi.cn/d/gzezoi2023/p/P1126)
- [P1124.【提高】数位动规_数字计数](https://www.gzezoi.cn/d/gzezoi2023/p/P1127)


