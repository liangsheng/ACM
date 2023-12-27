# Description

Bessie and Elsie are plotting to overthrow Farmer John at last! They plan it out over $N(1 \le N \le 2 \times 10^5)$ text messages. Their conversation can be represented by a string $S$ of length $N$ where $S_i$ is either $B$ or $E$, meaning the $i$th message was sent by Bessie or Elsie, respectively.

However, Farmer John hears of the plan and attempts to intercept their conversation. Thus, some letters of $S$ are $F$, meaning Farmer John obfuscated the message and the sender is unknown.

The excitement level of a non-obfuscated conversation is the number of times a cow double-sends - that is, the number of occurrences of substring $BB$ or $EE$ in $S$. You want to find the excitement level of the original message, but you don’t know which of Farmer John’s messages were actually Bessie’s / Elsie’s. Over all possibilities, output all possible excitement levels of $S$
.

# Input
The first line will consist of one integer $N$.

The next line contains $S$.

# Output
First output $K$, the number of distinct excitement levels possible. On the next $K$ lines, output the excitement levels, in increasing order.

```input1
4
BEEF
```

```output1
2
1
2
```

```input2
9
FEBFEBFEB
```

```output2
2
2
3
```

```input3
10
BFFFFFEBFE
```

```output3
3
2
4
6
```

# Hint
* Sample 1 have 2 possible strings
  * BEEE: score 2
  * BEEB: score 1

# Limitation
* Inputs 4-8: $N \le 10$
* Inputs 9-20: No additional constraints.
* 1s, 1024KiB for each test case.

# Source
* [【USACO_2023_open_Bronze】Problem_1_FEB](http://www.usaco.org/index.php?page=viewproblem2&cpid=1323)