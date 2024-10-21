# [leetcode-123] 买卖股票的最佳时机_3

给定一个数组 $prices$ ，它的第 $i$ 个元素 $prices[i]$ 表示一支给定股票第 $i$ 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 `两笔` 交易。

`注意`：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

# 输入格式

第一行包含 $1$ 个正整数 $n$，表示 $prices[]$ 的长度

第二行包含 $n$ 个正整数，表示 $prices[i]$

# 输出格式

输出最大利润

```input1
8
3 3 5 0 0 3 1 4
```

```output1
6
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
- $(3 - 0) + (4 - 1) = 6$

**【样例解释 #2】**
- $5 - 1 = 4$
- 注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。   
- 因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。

**【数据范围】**
- $1 \leq n \leq 10^5$
- $0 \leq prices[i] \leq 10^5$

<details>
<summary><font color="#FF0000">请思考后再点击查看提示</font></summary>

</details>

# 来源
* [【leetcode-123】 买卖股票的最佳时机_3](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/description/)
* [题解](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/solutions/552695/mai-mai-gu-piao-de-zui-jia-shi-ji-iii-by-wrnt)