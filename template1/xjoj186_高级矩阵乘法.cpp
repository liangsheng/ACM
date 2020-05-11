#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n, k, m;
int a[50][35][35], cur[35][35], ans[35][35], sum[35][35];

int mul(int a[35][35], int b[35][35])
{
    int i, j, t;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        {
            ans[i][j] = 0;
            for (t = 1; t <= n; t++)
                ans[i][j] = (ans[i][j] + a[i][t] * b[t][j] ) % m;
        }
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            b[i][j] = ans[i][j];
    return 1;
}

int account(int p)
{
    int i, j, q = 1;
    memset(cur, 0, sizeof(cur));
    for (i = 1; i <= n; i++)
        cur[i][i] = 1;
    while (p)
    {
        if (p % 2 == 1) mul(a[q], cur);
        q++;
        p /= 2;  
    }
    return 1;
}

int resolve(int k)
{
    int i, j, p, t;
    if (k <= 2)
    {
        for (p = 1; p <= k; p++)
            for (i = 1; i <= n; i++)
                for (j = 1; j <= n; j++)
                {
                    sum[i][j] += a[p][i][j];
                    sum[i][j] %= m;
                }
        return 1;
    }
    resolve(k / 2);
    account((k - 1) / 2 + 1);
    if (k % 2 == 0)
        for (i = 1; i <= n; i++)
        {
            cur[i][i]++;
            cur[i][i] %= m;
        }
    else
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
            {
                cur[i][j] += a[1][i][j];
                cur[i][j] %= m;
            }
    mul(cur, sum);
    if (k % 2 == 1)
    {
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++) 
            {
                sum[i][j] += a[1][i][j];
                sum[i][j] %= m;
            }         
    }
    return 1;
}

int solve(int k)
{
    int i = k, j, t, p , size = 1;
    while (i)
    {
        size++;
        i /= 2;  
    }
    for (p = 2; p <= size + 1; p++)
        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                for (t = 1; t <= n; t++)
                {
                    a[p][i][j] += a[p - 1][i][t] * a[p - 1][t][j];
                    a[p][i][j] %= m; 
                }
    resolve(k);
    return 1;
}

int main()
{
    int i, j, t;
    scanf("%d%d%d", &n, &k, &m);
    memset(sum, 0, sizeof(sum));
    memset(a, 0, sizeof(a));
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &a[1][i][j]);
            a[1][i][j] %= m;
        }
    }
    solve(k);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j < n; j++)
            printf("%d ", sum[i][j]);
        printf("%d\n", sum[i][n]);
    }   
    system("pause");
    return 0;
}
