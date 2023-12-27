# 题目描述

在一个网络系统中有 $n$ 个用户，$m$ 次上网记录。

每个用户可以自己注册一个用户名，每个用户名是一个只含小写字母且长度小于 1000 的字符串。

每个上网的账号每次上网都会浏览网页，网页名是以一个只含小写字母且长度小于 1000 的字符串。

每次上网日志里都会有记录，现在请统计每个用户每次浏览了多少个网页。

# 输入格式

第 1 行包含两个用 1 个空格隔开的正整数 $n(1 \le n \le 1000)$ 和 $m(1 \le m \le 5000)$

第 $2$ 到 $m + 1$ 行，每行包含 2 个用 1 个空格隔开的字符串，分别表示用户名和浏览的网页名。

# 输出格式
共 $n$ 行，每行的第一个字符串是用户名，接下来的若干字符串是这个用户依次浏览的网页名（之间用一个空格隔开）。**<font color="#FF0000">按照用户名出现的次序排序输出。</font>**

```input1
5 7
goodstudyer bookshopa
likespacea spaceweb
goodstudyer bookshopb
likespaceb spaceweb
likespacec spaceweb
likespacea juiceshop
gameplayer gameweb
```

```output1
goodstudyer bookshopa bookshopb
likespacea spaceweb juiceshop
likespaceb spaceweb
likespacec spaceweb
gameplayer gameweb
```

# 提示
* 考虑用 map<string, vector<string>> 来存储数据
```c++
map<string, vector<string>> q;  // 存储每个人看的网页
for (int i = 0; i < m; i++) {
    cin >> name >> web;
    q[name].push_back(web);
}
```

# 数据规模与限制
* $1 \le n \le 1000, 1 \le m \le 5000$
* 1s, 1024KiB for each test case.