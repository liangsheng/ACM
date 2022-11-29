#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define INF 1000005
#define N 50005
#define lowbit(x) (x & (-x))
using namespace std;

int n, m;
int a[N], b[N], num[N];

void init(int n)
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        b[i] = num[i];
        for (j = 1; j < lowbit(i); j <<= 1)
            b[i] = max(b[i], b[i - j]);
    }
}

int modify(int p, int v, int n)
{
    int i, j;
    num[p] = v;
    for (i = p; i <= n; i += lowbit(i))
    {
        b[i] = v;
        for (j = 1; j < lowbit(i); j <<= 1)
            b[i] = max(b[i], b[i - j]);
    }
}

int add(int x, int y)
{
    while (x <= n)
    {
        a[x] = min(a[x], y);
        b[x] = max(b[x], y);
        x += lowbit(x);
    }
    return 1;
}

int find1(int l, int r)
{
    int ans = num[r];
    while (1)
    {
        ans = min(ans, num[r]);
        if (r == l) break;
        for (r -= 1; r - l >= lowbit(r); r -= lowbit(r)) ans = min(ans, a[r]);
    }
    return ans;
}

int find2(int l, int r)
{
    int ans = num[r];
    while (1)
    {
        ans = max(ans, num[r]);
        if (l == r) break;
        for (r -= 1; r - l >= lowbit(r); r -= lowbit(r)) ans = max(ans, b[r]);
    }
    return ans;
}
int main()
{
    int i, x, y;
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n; i++) a[i] = INF, b[i] = 0;
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        num[i] = x;
        add(i, x);
    }
    for (i = 1; i <= m; i++)
    {
        scanf("%d%d", &x, &y);
        printf("%d\n", find2(x, y) - find1(x, y));
    }
    system("pause");
    return 0;
}
