# [luogu_P1364] 医院设置

一个村庄有 $n$ 户人家，有 $n-1$ 条路将这个 $n$ 户人家俩连接起来，路的长度都是 $1$；第 $i$ 户人家有 $c[i]$ 口人；

现在要在这 $n$ 户人家里选一家建一所医院，希望所有人到医院的距离之和最小，请输出这个最小距离


# 输入格式

输入的第一行包含整数 $n$

第 $2$ 行包含 $n$ 个正整数 $c[i]$，表示每户人家的人数


接下来 $n - 1$ 行，每行包含 $2$ 个整数 $u, v$，表示 $u, v$ 之间有一条边长为 $1$ 的路

# 输出格式

输出所有人到医院的距离之和的最小值

```input1
5
13 4 12 20 40
1 2
1 3
3 4
3 5
```

```output1
81
```

## 提示
- [画图工具](https://csacademy.com/app/graph_editor/)
- [功能更多的画图工具](https://anacc22.github.io/another_graph_editor/)
- [直接画的画图工具](https://silverfoxxxy.github.io/miska924/DrawGraphJS/)

**【样例解释 #1】**
![](https://cdn.luogu.com.cn/upload/image_hosting/kawht13x.png)
- 若将医院建在 $1$，则距离和：$4+12+2*20+2*40=136$
- 若将医院建在 $3$，则距离和：$4*2+13+20+40=81$

**【数据范围】**
- $1 \leq n \leq 10^5$
- $1 \leq c[i] \leq 10$

<details>
<summary><font color="#FF0000">请思考后再点击查看提示</font></summary>

</details>

# 来源
* [luogu_P1364: 医院设置](https://www.luogu.com.cn/problem/P1364)