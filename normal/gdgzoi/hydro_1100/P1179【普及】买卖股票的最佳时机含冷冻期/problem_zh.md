# [leetcode-309] 买卖股票的最佳时机含冷冻期

给定一个数组 $prices$ ，它的第 $i$ 个元素 $prices[i]$ 表示一支给定股票第 $i$ 天的价格。

设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:
- 卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
  
`注意`：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

# 输入格式

第一行包含 $1$ 个正整数 $n$，表示 $prices[]$ 的长度

第二行包含 $n$ 个正整数，表示 $prices[i]$

# 输出格式

输出最大利润

```input1
5
1 2 3 0 2
```

```output1
3
```

## 提示
**【样例解释 #1】**
- 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]

**【数据范围】**
- $1 \leq n \leq 10^5$
- $0 \leq prices[i] \leq 10^5$

<details>
<summary><font color="#FF0000">请思考后再点击查看提示</font></summary>

</details>

# 来源
* [【leetcode-309】 买卖股票的最佳时机含冷冻期](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/)
* [题解](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/solutions/323509/zui-jia-mai-mai-gu-piao-shi-ji-han-leng-dong-qi-4)