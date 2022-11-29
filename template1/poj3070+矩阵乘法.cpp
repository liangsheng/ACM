#include <iostream>
#include <cstdio>
#define N 2
#define mod 10000
using namespace std;

int a[N][N] = {0, 1, 1, 1};

int martrix_mul(int ans[N][N], int n)
{
    int i, j, k;
    if (n == 1)
    {
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
                ans[i][j] = a[i][j];
        }  
        return 1;
    }
    int temp[N][N];
    martrix_mul(temp, n / 2);
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            ans[i][j] = 0;
            for (k = 0; k < N; k++)
                ans[i][j] = (ans[i][j] + temp[i][k] * temp[k][j]) % mod;
        }
    }
    if (n & 1)
    {
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
                temp[i][j] = ans[i][j];
        }
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
            {
                ans[i][j] = 0;
                for (k = 0; k < N; k++)
                    ans[i][j] = (ans[i][j] + temp[i][k] * a[k][j] ) % mod;
            }
        }  
    }
    return 1;
}

int main()
{
    int n, i, j, ans[N][N];
    while (scanf("%d", &n) != EOF && n != -1)
    {
        if (n == 0)
        {
            printf("0\n");
            continue;  
        }  
        if (n == 1 || n == 2)
        {
            printf("1\n");
            continue;  
        }
        martrix_mul(ans, n - 1);
        printf("%d\n", (ans[0][0] + ans[0][1]) % mod);
    }
    system("pause");
    return 0;
}
