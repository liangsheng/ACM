/*
两个正整数a,b最大公约数GCD（a,b），一般也被写成（a,b）,例如(1,2) = 1,(12,6)=6.
GCD很容易用欧几里得算法求得。 但是现在有一个新的问题：给定两个正整数N,M，
问有多少个正整数X满足： 1<=X<=N,并且（X,N）>= M
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 40000;

int e, ans;
int prim[N], a[N], r[N];
bool is_prim[N];

void get_prim()
{
    int i, j;
    e = 0;
    fill(is_prim, is_prim + N, 1);
    for (i = 2; i < N; i++)
    {
        if (! is_prim[i]) continue;
        prim[e++] = i;
        for (j = i * i; j < N; j += i) is_prim[j] = 0;
    }
}

int euler(int n)
{
    int i, ans = 1;
    for (i = 2; i * i <= n; i++)
    {
        if (n % i) continue;
        n /= i, ans *= i - 1;
        while (n % i == 0) n /= i, ans *= i;
    }
    if (n > 1) ans *= n - 1;
    return ans;
}

int factor(int n)
{
    int i, m = 0;
    for (i = 0; i < e && prim[i] * prim[i] <= n; i++)
    {
        if (n % prim[i]) continue;
        n /= prim[i], a[++m] = prim[i], r[m] = 1;
        while (n % prim[i] == 0) n /= prim[i], r[m]++;
    }
    if (n > 1) a[++m] = n, r[m] = 1;
    return m;
}

void dfs(int now_p, int now_v, int n, int m, int k)
{
    if (now_p == k + 1)
    {
        if (now_v >= m) ans += euler(n / now_v);
        return;
    }
    for (int i = 0, t = 1; i <= r[now_p]; i++, t *= a[now_p])
        dfs(now_p + 1, now_v * t, n, m, k);
}

int main()
{
    int T, n, m, i, j, k;
    get_prim();
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        k = factor(n);
        ans = 0;
        dfs(1, 1, n, m, k);
        printf("%d\n", ans);
    }
    return 0;
}
