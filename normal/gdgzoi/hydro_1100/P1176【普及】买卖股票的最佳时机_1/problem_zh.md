# [leetcode-121] 买卖股票的最佳时机_1

给定一个数组 $prices$ ，它的第 $i$ 个元素 $prices[i]$ 表示一支给定股票第 $i$ 天的价格。

你只能选择 `某一天` 买入这只股票，并选择在 `未来的某一个不同的日子` 卖出该股票。设计一个算法来计算你所能获取的最大利润。

返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。

# 输入格式

第一行包含 $1$ 个正整数 $n$，表示 $prices[]$ 的长度

第二行包含 $n$ 个正整数，表示 $prices[i]$

# 输出格式

输出最大利润

```input1
5
7 1 5 3 6 4
```

```output1
5
```

```input2
5
7 6 4 3 1
```

```output2
0
```

## 提示
**【样例解释 #1】**
- $6 - 1 = 5$

**【样例解释 #2】**
- 不能获利

**【数据范围】**
- $2 \leq n \leq 10^5$
- $1 \leq prices[i] \leq 10^4$

<details>
<summary><font color="#FF0000">请思考后再点击查看提示</font></summary>

</details>

# 来源
* [【leetcode-121】 买卖股票的最佳时机_1](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/description/)