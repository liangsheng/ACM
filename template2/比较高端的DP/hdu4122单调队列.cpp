#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 2505
#define M 100005
#define lowbit(x) (x & (-x))
using namespace std;

typedef pair<__int64, __int64> PAIR;
struct Order
{
    __int64 t, need;
};

__int64 n, m, t, s;
__int64 monn[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char monc[12][5] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov" , "Dec"};
Order order[N];
__int64 cost[M];
__int64 b[M];

__int64 init(Order &p, char *ch, __int64 d, __int64 y, __int64 h, __int64 r)
{
    __int64 i, j, k, ans = 0;
    p.need = r;
    for (i = 2000; i < y; i++)
    {
        if (i % 4 == 0) ans += 366 * 24;
        else ans += 365 * 24;
    }
    for (k = 0; k < 12; k++)
        if (strcmp(monc[k], ch) == 0) break;
    for (i = 0; i < k; i++)
    {
        if (i == 1 && y % 4 == 0) ans += 29 * 24;
        else ans += monn[i] * 24;
    }
    ans += (d - 1) * 24;
    ans += h + 1;
    p.t = ans;
    return 1;
}

struct Line
{
    __int64 head, end;
    PAIR q[M];

    void init()
    {
        head = end = 0;
    }

    void update(__int64 x)
    {
        __int64 i;
        for (i = head; i != end; i++) q[i].second += x;
    }

    void push(PAIR p)
    {
        while (head != end && q[end - 1].second >= p.second) end--;
        q[end++] = p;
    }

    __int64 pop(__int64 p)
    {
        while (head != end && q[head].first < p) head++;
        return q[head].second;
    }
};

int main()
{
    __int64 i, j, d, y, h, r, ans;
    char ch[5];
    Line line;
    while (scanf("%I64d%I64d", &n, &m) != EOF)
    {
        if (n == 0 && m == 0) break;
        for (i = 1; i <= n; i++)
        {
            scanf("%s%I64d%I64d%I64d%I64d", ch, &d, &y, &h, &r);
            init(order[i], ch, d, y, h, r);
        }
        scanf("%I64d%I64d", &t, &s);
        for (i = 1; i <= m; i++)
            scanf("%I64d", &cost[i]);
        line.init();
        order[0].t = 0;
        ans = 0;
        for (i = 1; i <= n; i++)
        {
            line.pop(order[i].t - t);
            line.update((order[i].t - order[i - 1].t) * s);
            for (j = order[i - 1].t + 1; j <= order[i].t; j++) line.push(PAIR(j, cost[j] + (order[i].t - j) * s));
            ans += line.pop(order[i].t - t) * order[i].need;
        }
        printf("%I64d\n", ans);
    }
    system("pause");
    return 0;
}
