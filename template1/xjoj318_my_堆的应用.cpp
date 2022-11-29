#include <iostream>
#include <cstdio>
#include <cstring>
#define N 250005
#define INF 1 << 29
#define LL long long
using namespace std;
       
int n, size;
int a[105];
int p[N], v[N], heap[N], place[N], pred[N], next[N];

int abs(int x)
{
    return x > 0 ? x : -x; 
}

int lowbit(int x)
{
    return x & (-x);
}

int add(int x)
{
    while (x <= 101)
    {
        a[x]++;
        x += lowbit(x);  
    }
    return 1;
}

int cal(int x)
{
    int sum = 0;
    while (x > 0)
    {
        sum += a[x];
        x -= lowbit(x);  
    } 
    return sum;
}

int calc(int x, int y)
{
    if (x == -1 || y == -1) return 0;
    if (v[x] == v[y] || v[x] < v[y]) return 0;
    return  1;  
}

int judge(int i, int j)
{
    int t1, t2;
    int f1, f2, g1, g2;
    double p1, p2;
    i = heap[i], j = heap[j];
    f1 = p[pred[i]] - p[i];
    f2 = v[i] - v[pred[i]];
    g1 = p[pred[j]] - p[j];
    g2 = v[j] - v[pred[j]];
    if (pred[i] == -1 || i == -1 || f2 <= 0)
        t1 = INF;
    else
        t1 = f1 * g2;      
    if (pred[j] == -1 || j == -1 || g2 <= 0)
        t2 = INF;
    else
        t2 = g1 *f2;
    if (abs(t1 - t2) == 0)
    {
        p1 = double(p[i]) + double(f1) / double(f2) * double(v[i]);
        p2 = double(p[j]) + double(g1) / double(g2) * double(v[j]);
        if (p1 < p2)
            return 1;
        else return 0;        
    }
    if (t1 < t2) return 1;
    else return 0;
}
 
int swap(int i, int j)
{
    int x, y, t;
    x = heap[i], y = heap[j];
    t = heap[i], heap[i] = heap[j], heap[j] = t;
    t = place[x], place[x] = place[y], place[y] = t;
    return 1;
}
 
int up(int x)
{
    while (x > 1)
    {
        if (judge(x, x / 2))
        {
            swap(x, x / 2);
            x /= 2;         
        }  
        else return 1;
    }
    return 1;
}

int down(int x)
{
    int y;
    while (x * 2 <= size)
    {
        y = x * 2;
        if (y < size && judge(y + 1, y)) y++;
        if (judge(y, x))
        {
            swap(x, y);
            x = y;         
        } 
        else return 1;
    }
    return 1;
}

int update(int x)
{
    up(place[x]);
    down(place[x]);
    return 1;   
}

int main()
{   
    int i, j, now, pre, nex, ans = 0;
    scanf("%d", &n);
    memset(a, 0, sizeof(a));
    for (i = 1; i <= n; i++)
    scanf("%d%d", &p[i], &v[i]);
    for (i = 1; i <= n; i++)
    {
        ans = (ans + i - 1 - cal(v[i])) % 1000000;
        add(v[i]);
    }
    //printf("%d\n", ans);
    for (i = 1; i <= n; i++)
        pred[i] = i + 1, next[i] = i - 1;
    pred[n] = -1, next[1] = -1;
    heap[1] = 1, place[1] = 1, size = 1;
    for (i = 2; i <= n; i++)
    {
        ++size;
        heap[size] = i;
        place[i] = size;
        up(size);
    }
    for (i = 1; i <= 10000; i++)
    {
        now = heap[1];
        pre = pred[now], nex = next[now];
        if (! calc(now, pre)) break;
        pred[now] = pred[pre];
        next[now] = pre;
        if (pred[pre] != -1) next[pred[pre]] = now;
        pred[pre] = now;
        next[pre] = nex;
        if (nex != -1) pred[nex] = pre;
        printf("%d %d\n", now, pre);
        if (now != -1) update(now);     
        if (pre != -1) update(pre);      
        if (nex != -1) update(nex);     
    }
    system("pause");
    return 0;
}
