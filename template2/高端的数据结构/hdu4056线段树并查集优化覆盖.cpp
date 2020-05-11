#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#define inf (1 << 30)
#define mod 1000000007
#define N 205
#define M 50005
const double eps = 1e-12;
const double pi = acos(-1.0);
using namespace std;

struct NODE
{
    char s[10];
    int x, y, l, r, c;
};

int n, m, q;
int ans[10];
int next[N][M];
NODE d[M];

int init()
{
    int i, j;
    for (i = 0; i <= n; i++)
        for (j = 0; j <= m; j++) next[i][j] = j;
    memset(ans, 0, sizeof(ans));
    return 1;
};

int find(int i, int j)
{
    if (next[i][j] == j) return j;
    next[i][j] = find(i, next[i][j]);
    return next[i][j];
}

int cal(int i, int l, int r)
{
    int ret = 0;
    l = find(i, l);
    while (l <= r)
    {
        ret++;
        next[i][l] = l + 1;
        l = find(i, l);
    }
    return ret;
}

int main()
{
    int i, j, t1, t2, t3, t4, t, h;
    while (~scanf("%d%d%d", &n, &m, &q))
    {
        init();
        for (i = 1; i <= q; i++)
        {
            scanf("%s", d[i].s);
            if (d[i].s[0] == 'R') scanf("%d%d%d%d%d", &d[i].x, &d[i].y, &d[i].l, &d[i].r, &d[i].c);
            else scanf("%d%d%d%d", &d[i].x, &d[i].y, &d[i].r, &d[i].c);
        }
        for (i = q; i >= 1; i--)
        {
            if (d[i].s[0] == 'D')
            {
                t1 = max(0, d[i].x - d[i].r);
                t2 = min(n - 1, d[i].x + d[i].r);
                //cout << t1 << " " << t2, system("pause");
                for (j = t1; j <= t2; j++)
                {
                    t3 = max(0, d[i].y - d[i].r + abs(d[i].x - j));
                    t4 = min(m - 1, d[i].y + d[i].r - abs(d[i].x - j));
                    //cout << "ttt" << t3 << " " << t4, system("pause");
                    ans[d[i].c] += cal(j, t3, t4);
                }
            }
            else if (d[i].s[0] == 'T')
            {
                t1 = d[i].x;
                t2 = min(n - 1, d[i].x + (d[i].r + 1) / 2 - 1);
                h = d[i].r;
                for (j = t1; j <= t2; j++)
                {
                    t3 = max(0, d[i].y - (h - 1) / 2);
                    t4 = min(m - 1, d[i].y + (h - 1) / 2);
                    ans[d[i].c] += cal(j, t3, t4);
                    h -= 2;
                }
            }
            else if (d[i].s[0] == 'R')
            {
                t1 = d[i].x;
                t2 = min(n - 1, d[i].x + d[i].l - 1);
                t3 = d[i].y;
                t4 = min(m - 1, d[i].y + d[i].r - 1);
                for (j = t1; j <= t2; j++) ans[d[i].c] += cal(j, t3, t4);
            }
            else if (d[i].s[0] == 'C')
            {
                t1 = max(0, d[i].x - d[i].r);
                t2 = min(n - 1, d[i].x + d[i].r);
                for (j = t1; j <= t2; j++)
                {
                    t = (int) sqrt(d[i].r * d[i].r - (d[i].x - j) * (d[i].x - j));
                    t3 = max(0, d[i].y - t);
                    t4 = min(m - 1, d[i].y + t);
                    ans[d[i].c] += cal(j, t3, t4);
                }
            }
        }
        for (i = 1; i < 9; i++) printf("%d ", ans[i]);
        printf("%d\n", ans[9]);
    }
    system("pause");
    return 0;
}
