#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define N 100005
#define eps 1e-8
#define inf 99999999
using namespace std;

struct Point
{
    double x,y;
};

int n;
int ypos[N];
Point p[N];

inline double cal_dis(Point a,Point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool cmp_x(Point a, Point b)
{
    return a.x < b.x;
}

bool cmp_y(int a, int b)
{
    return p[a].y < p[b].y;
}

double closedis(Point *p, int l, int r)
{
    int i, j, mid = (l + r) / 2, num = 0, k;
    double ans;
    if (l == r) return inf;
    if (l + 1 == r) return cal_dis(p[l], p[r]);
    ans = min(closedis(p, l, mid), closedis(p, mid + 1, r));
    for (i = l; i <= r; i++)
        if (fabs(p[i].x - p[mid].x) < ans) ypos[num++] = i;
    sort(ypos, ypos + num, cmp_y);
    for (i = 0; i < num; i++)
    {
        k = 0;
        for (j = i + 1; j < num; j++)
        {
            if (fabs(p[ypos[i]].y-p[ypos[j]].y) > ans) break;
            else
            {
                ans = min(ans,cal_dis(p[ypos[i]], p[ypos[j]]));
                k++;
            }
            if (k > 6) break;
        }
    }
    return ans;
}

int main()
{
    int i;
    while (scanf("%d",&n) != EOF && n)
    {
        for (i = 0; i < n; i++) scanf("%lf%lf", &p[i].x, &p[i].y);
        sort(p, p + n, cmp_x);
        printf("%.2lf\n", closedis(p, 0, n - 1) / 2.0);
    }
    return 0;
}
