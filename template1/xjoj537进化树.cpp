#include <iostream>
#include <cstdio>
#include <cstring>
#define N 1030
using namespace std;

int test, n;
int g[N][N];

int main()
{
    int i, j, k, sum, mini, p;
    scanf("%d", &test);
    while (test--)
    {
        scanf("%d", &n);
        memset(g, 0, sizeof(g));
        for (i = 1; i < n; i++)
        {
            for (j = i + 1; j <= n; j++)
            {
                scanf("%d", &g[i][j]);
                g[j][i] = g[i][j];
            }
        }  
        sum = 0;
        for (i = 1; i <= n - 2; i++)
        {
            mini = -1;
            k = i + 1;
            for (j = k + 1; k <= n; k++)
            {
                p = (g[i][k] + g[i][j] - g[k][j]) / 2;
                if (mini == -1 || p < mini)
                    mini = p;
            }
            sum += mini;
        }
        sum += g[n - 1][n];
        printf("%d\n", sum + 1 - n);
    }
    system("pause");
    return 0;
}
