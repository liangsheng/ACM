#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define esp 0.00001
#define N 1010
#define INF (1 << 30)
using namespace std;

struct NODE
{
    int x, y, z;   
};
       
int n;
int vis[N], pre[N];
double dis[N];
NODE p[N];

int abs(int x)
{
    return x > 0 ? x : -x;
}

double cal(NODE p1, NODE p2)
{
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));   
}
       
double prim(double a)
{
    int i, j, key;
    double cost = 0.0, len = 0.0, mini, tmp;
    memset(vis, 0, sizeof(vis));
    for (i = 1; i <= n; i++)
    {
        dis[i] = abs(p[1].z - p[i].z) - a * cal(p[1], p[i]);
        pre[i] = 1;
    }   
    vis[1] = 1;
    for (i = 1; i < n; i++)
    {
        mini = INF;
        key = -1;
        for (j = 1; j <= n; j++)
        {
            if (! vis[j] && dis[j] < mini)
            {
                mini = dis[j];
                key = j;  
            }
        }
        vis[key] = 1;
        cost += abs(p[key].z - p[pre[key]].z);
        len += cal(p[key], p[pre[key]]);
        for (j = 1; j <= n; j++)
        {
            tmp = abs(p[key].z - p[j].z) - a * cal(p[key], p[j]);
            if (! vis[j] && dis[j] > tmp)
            {
                dis[j] = tmp;
                pre[j] = key;  
            }
        }
    }
    return cost / len;
}
       
int main()
{
    int i;
    double a, b;
    while (scanf("%d", &n) != EOF && n)
    {
        for (i = 1; i <= n; i++)
            scanf("%d%d%d", &p[i].x, &p[i].y, &p[i].z);
        //分数规划用：Dinkelbach算法
        //每次迭代子问题的解cost`/len`进去，这样会不断逼近最优解          
        a = 0;
        while (1)
        {
            b = prim(a);
            if (fabs(b - a) < esp) break;
            a = b;  
        }
        printf("%.3f\n", b);
    }
    system("pause");
    return 0;
}
