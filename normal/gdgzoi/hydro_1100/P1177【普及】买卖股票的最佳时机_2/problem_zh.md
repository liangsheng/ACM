# [leetcode-122] 买卖股票的最佳时机_2

给定一个数组 $prices$ ，它的第 $i$ 个元素 $prices[i]$ 表示一支给定股票第 $i$ 天的价格。

在每一天，你可以决定是否购买和/或出售股票。你在任何时候 `最多` 只能持有 `一股` 股票。你也可以先购买，然后在 `同一天` 出售。

返回 你能获得的 `最大` 利润 。

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
7
```

```input2
5
1 2 3 4 5
```

```output2
4
```

## 提示
**【样例解释 #1】**
- $(5 - 1) + (6 - 3) = 7$

**【样例解释 #2】**
- $5 - 1 = 4$

**【数据范围】**
- $2 \leq n \leq 10^5$
- $1 \leq prices[i] \leq 10^4$

<details>
<summary><font color="#FF0000">请思考后再点击查看提示</font></summary>

</details>

# 来源
* [【leetcode-122】 买卖股票的最佳时机_2](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/description/)
* [题解](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/solutions/476791/mai-mai-gu-piao-de-zui-jia-shi-ji-ii-by-leetcode-s)