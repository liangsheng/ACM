/*============================================================*\
 | 2台机器工作调度
   2台机器, n件任务, 必须先在S1上做, 再在S2上做. 任务之间先做后
做任意. 求最早的完工时间. 这是一个经典问题: 2台机器的情况下有多
项式算法(Johnson算法), 3台或以上的机器是NP-hard的. Johnson算法:
(1) 把作业按工序加工时间分成两个子集,
    第一个集合中在S1上做的时间比在S2上少,
  其它的作业放到第二个集合.
  先完成第一个集合里面的作业, 再完成第二个集合里的作业.
(2) 对于第一个集合, 其中的作业顺序是按在S1上的时间的不减排列;
  对于第二个集合, 其中的作业顺序是按在S2上的时间的不增排列.
\*============================================================*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 10005
using namespace std;

struct NODE
{
    int t1, t2;
};

int n;
NODE a[N], b[N];

bool cmp1(NODE p1, NODE p2) { return p1.t1 < p2.t1; }

bool cmp2(NODE p1, NODE p2) { return p1.t2 > p2.t2; }

int main()
{
    int i, e1, e2, p1, p2;
    while (scanf("%d", &n) != EOF && n)
    {
        for (i = 0; i < n; i++) scanf("%d%d", &a[i].t1, &a[i].t2);
        e1 = 0, e2 = n;
        for (i = 0; i < n; i++)
        {
            if (a[i].t1 < a[i].t2) b[e1++] = a[i];
            else b[--e2] = a[i];
        }
        sort(b, b + e1, cmp1), sort(b + e1, b + n, cmp2);
        p1 = b[0].t1 + b[1].t1, p2 = b[0].t1 + b[0].t2;
        for (i = 2; i < n; i++)
        {
            p2 = max(p1, p2) + b[i - 1].t2;
            p1 += b[i].t1;
        }
        p2 = max(p1, p2) + b[n - 1].t2;
        printf("%d\n", p2);
    }
    system("pause");
    return 0;
}
