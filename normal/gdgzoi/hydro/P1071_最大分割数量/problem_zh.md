# 题目描述

给你一个下标从 $0$ 开始的字符串 $s$ 和一个整数 $k$。

你需要执行以下分割操作，直到字符串 $s$ 变为空：

* 选择 $s$ 的最长前缀，该前缀最多包含 $k$ 个不同字符。
* 删除这个前缀，并将分割数量加一。如果有剩余字符，它们在 $s$ 中保持原来的顺序。

执行操作之前 ，你可以将 $s$ 中至多一处 下标的对应字符更改为另一个小写英文字母。

在最优选择情形下改变至多一处下标对应字符后，用整数表示并返回操作结束时得到的最大分割数量。

# 输入格式

输入包含 $2$ 行

第 $1$ 行包含字符串 $s$

第 $2$ 行包含整数 $k$

# 输出格式

输出一行，表示最大分割数

```input1
accca
2
```

```output1
3
```

```input2
aabaab
3
```

```output2
1
```

```input3
xxyz
1
```

```output3
4
```

# 提示
**【样例解释 1】**
* 在此示例中，为了最大化得到的分割数量，可以将 s[2] 改为 'b'。
s 变为 "acbca"。
按照以下方式执行操作，直到 s 变为空：
* 选择最长且至多包含 2 个不同字符的前缀，"acbca"。
* 删除该前缀，s 变为 "bca"。现在分割数量为 1。
* 选择最长且至多包含 2 个不同字符的前缀，"bca"。
* 删除该前缀，s 变为 "a"。现在分割数量为 2。
* 选择最长且至多包含 2 个不同字符的前缀，"a"。
* 删除该前缀，s 变为空。现在分割数量为 3。
* 因此，答案是 3。
* 可以证明，分割数量不可能超过 3。

**【样例解释 2】**
* 在此示例中，为了最大化得到的分割数量，可以保持 s 不变。
按照以下方式执行操作，直到 s 变为空： 
* 选择最长且至多包含 3 个不同字符的前缀，"aabaab"。
* 删除该前缀，s 变为空。现在分割数量为 1。
* 因此，答案是 1。可以证明，分割数量不可能超过 1。

**【样例解释 3】**
* 在此示例中，为了最大化得到的分割数量，可以将 s[1] 改为 'a'。s 变为 "xayz"。按照以下方式执行操作，直到 s 变为空：
* 选择最长且至多包含 1 个不同字符的前缀，"xayz"。
* 删除该前缀，s 变为 "ayz"。现在分割数量为 1。
* 选择最长且至多包含 1 个不同字符的前缀，"ayz"。
* 删除该前缀，s 变为 "yz"，现在分割数量为 2。
* 选择最长且至多包含 1 个不同字符的前缀，"yz"。
* 删除该前缀，s 变为 "z"。现在分割数量为 3。
* 选择最且至多包含 1 个不同字符的前缀，"z"。
* 删除该前缀，s 变为空。现在分割数量为 4。
* 因此，答案是 4。可以证明，分割数量不可能超过 4。

<details>
<summary><font color="#FF0000">请思考后再点击查看提示</font></summary>

* 在不修改的情况下，怎么求得最大分割数？
* 现在可以修改一次，必然是找之前重复出现过的字符，将其修改成之前没出现的字符

</details>

# 数据规模与限制
* $1 \le s.length \le 10^4$, $s$ 只包含小写英文字母
* $1 \le k \le 26$
* 1s, 1024KiB for each test case.

# 来源
* [leetcode_379_执行操作后的最大分割数量](https://leetcode.cn/contest/weekly-contest-379/problems/maximize-the-number-of-partitions-after-operations/)