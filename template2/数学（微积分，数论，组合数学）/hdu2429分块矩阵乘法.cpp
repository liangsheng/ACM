#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define pause cout << " press any key to continue...", cin >> ch
#define file_r(x) freopen(x, "r", stdin)
#define file_w(x) freopen(x, "w", stdout)
using namespace std;
int ch;

const int N = 65, MOD = 10001, LEN = 15;

int T, n, m, s, t;
int len[N];
int a[N][N], b[N][N], c[N][N], a2[N][N], d[N][N];
char str[35][LEN], ss[LEN], tt[LEN];

void mul(int a[N][N], int b[N][N], int size)
{
    int i, j, k;
    memset(c, 0, sizeof(c));
    for (i = 0; i < size; i++)
    {
        for (k = 0; k < size; k++)
        {
            if (a[i][k] == 0) continue;
            for (j = 0; j < size; j++)
            {
                if (b[k][j] == 0) continue;
                c[i][j] += a[i][k] * b[k][j] % MOD;
                c[i][j] %= MOD;
            }
        }
    }
}

int main()
{
    int i, j, p, u, v;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(d, 0, sizeof(d));
        getchar();
        for (i = 0; i < n; i++)
        {
            scanf("%s", str[i]);
            len[i] = strlen(str[i]);
        }
        scanf("%s%s%d", ss, tt, &m);
        for (i = 0; i < n; i++)
        {
            if (strcmp(ss, str[i]) == 0) s = i;
            if (strcmp(tt, str[i]) == 0) t = i;
            for (j = 0; j < n; j++)
                if (str[i][len[i] - 1] == str[j][0]) a[i][j] = 1;
        }
        if (m == 1 || m == 2)
        {
            printf("%d\n", a[s][t]);
            continue;
        }
        mul(a, a, n);
        memcpy(a2, c, sizeof(c));
        for (i = 0; i < n; i++)
        {
            a2[i + n][i] = a2[i + n][i + n] = 1;
            b[i][i] = b[i][i + n] = 1;
            d[i][i] = d[i + n][i + n] = 1;
        }
        if (m % 2 == 0) p = (m - 2) / 2;
        else p = (m - 1) / 2;
        while (p)
        {
            if (p & 1)
            {
                mul(d, a2, n << 1);
                memcpy(d, c, sizeof(c));
            }
            mul(a2, a2, n << 1);
            memcpy(a2, c, sizeof(c));
            p >>= 1;
        }
        mul(b, d, n << 1);
        memcpy(b, c, sizeof(c));
        mul(a, b, n);
        printf("%d\n", c[s][t]);
    }
    return 0;
}
