#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 30;
const int M = 11;
const int MAX = 1030;
const int NODE = 105;
const int CH = 26;
const int MOD = 20090717;

int n, m, least;
int dp[N][MAX][NODE];
char str[15];

int end;
int chd[NODE][CH];
int work[NODE];
int fail[NODE];
int q[NODE];
int sw[256];

 void init()
{
    int i;
    end = 1;
    memset(chd[0], -1, sizeof(chd[0]));
    work[0] = -1;
    for (i = 0; i < 26; i++) sw['a' + i] = i;
}

void add(char* str, int val)
{
    int i, id, p = 0;
    for (i = 0; str[i]; i++)
    {
        id = sw[str[i]];
        if (chd[p][id] == -1)
        {
            memset(chd[end], -1, sizeof(chd[end]));
            work[end] = -1;
            chd[p][id] = end++;
        }
        p = chd[p][id];
    }
    work[p] = val;
}

void build()
{
    int i, p, head, tail;
    fail[0] = 0;
    head = tail = 0;
    for (i = 0; i < CH; i++)
    {
        if (chd[0][i] != -1)
        {
            fail[chd[0][i]] = 0;
            q[tail++] = chd[0][i];
        }
        else chd[0][i] = 0;
    }
    while (head != tail)
    {
        p = q[head++];
        for (i = 0; i < CH; i++)
        {
            for (i = 0; i < CH; i++)
            {
                if (chd[p][i] != -1)
                {
                    fail[chd[p][i]] = chd[fail[p]][i];
                    q[tail++] = chd[p][i];
                }
                else chd[p][i] = chd[fail[p]][i];
            }
        }
    }
}

int count(int j)
{
    int i, s = 0;
    for (i = 1; i <= m; i++)
        if (((1 << (i - 1)) & j) != 0) s++;
    if (s < least) return 0;
    return 1;
}

void solve()
{
    int i, j, k, h, tmp, p, s, t, ans;
    tmp = 1 << m;
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;
    for (i = 0; i < n; i++)
        for (j = 0; j < tmp; j++)
            for (k = 0; k < end; k++)
            {
                if (dp[i][j][k] == 0) continue;
                for (h = 0; h < CH; h++)
                {
                    t = p = chd[k][h];
                    s = 0;
                    while (t != 0)
                    {
                        if (work[t] != -1) s |= 1 << (work[t] - 1);
                        t = fail[t];
                    }
                    dp[i + 1][s | j][p] += dp[i][j][k];
                    dp[i + 1][s | j][p] %= MOD;
                }
            }
    ans = 0;
    for (j = 0; j < tmp; j++)
    {
        if (! count(j)) continue;
        for (k = 0; k < end; k++) ans = (ans + dp[n][j][k]) % MOD;
    }
    printf("%d\n", ans);
}

int main()
{
    int i, j, k;
    while (scanf("%d%d%d", &n, &m, &least) != EOF)
    {
        if (n == 0 && m == 0 && least == 0) break;
        init();
        for (i = 1; i <= m; i++)
        {
            scanf("%s", str);
            add(str, i);
        }
        build();
        solve();
    }
    system("pause");
    return 0;
}
