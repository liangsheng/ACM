#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <algorithm>
#include <queue>
#define inf (1 << 30)
#define N 105
#define M 105
const double eps = 1e-12;
const double pi = acos(-1.0);
using namespace std;

int n, m;
int c1[M], c2[M], low[N], high[N];

int main()
{
    int i, j, k;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        for (i = 1; i <= n; i++) scanf("%d%d", &low[i], &high[i]);
        memset(c1, 0, sizeof(c1));
        for (i = low[1]; i <= high[1]; i++) c1[i] = 1;
        for (i = 2; i <= n; i++)
        {
            memset(c2, 0, sizeof(c2));
            for (j = 0; j <= m; j++)
            {
                for (k = low[i]; k + j <= m && k <= high[i]; k++)
                    c2[j + k] += c1[j];
            }
            for (j = 0; j <= m; j++) c1[j] = c2[j];
        }
        printf("%d\n", c1[m]);
    }
    system("pause");
    return 0;
}
