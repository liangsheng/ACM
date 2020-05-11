#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define LEN 1005
#define INF 999999
using namespace std;

const int N = 55;
const int NODE = 1020;
const int CH = 4;

int end;
int chd[NODE][CH];
int work[NODE];
int fail[NODE];
int q[NODE];

int n;
char s[LEN];
int dp[2][NODE];

void init()
{
    int i;
    end = 1;
    memset(chd[0], -1, sizeof(chd[0]));
    work[0] = 0;
}

int getId(char ch)
{
    if (ch == 'A') return 0;
    if (ch == 'T') return 1;
    if (ch == 'C') return 2;
    if (ch == 'G') return 3;
}

void add(char* str, int val)
{
    int i, id, p = 0;
    for (i = 0; str[i]; i++)
    {
        id = getId(str[i]);
        if (chd[p][id] == -1)
        {
            memset(chd[end], -1, sizeof(chd[end]));
            work[end] = 0;
            chd[p][id] = end++;
        }
        p = chd[p][id];
    }
    work[p] = val;
}

void build()
{
    int i, p, v, head, tail;
    fail[0] = head = tail = 0;
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
            v = chd[p][i];
            if (v != -1)
            {
                fail[v] = chd[fail[p]][i];
                q[tail++] = v;
                if (work[fail[v]] != 0) work[v] += work[fail[v]];
            }
            else chd[p][i] = chd[fail[p]][i];
        }
    }
}

int solve()
{
    int i, j, k, p, v, mini = INF, now = 0, pre = 1;
    for (j = 0; j < end; j++) dp[0][j] = INF;
    dp[0][0] = 0;
    for (i = 0; i < n; i++)
    {
        swap(now, pre);
        for (j = 0; j < end; j++) dp[now][j] = INF;
        for (j = 0; j < end; j++)
        {
            if (dp[pre][j] == INF) continue;
            for (k = 0; k < 4; k++)
            {
                p = chd[j][k];
                v = (k == getId(s[i])) ? 0 : 1;
                if (work[p] != 0) continue;
                //cout << "Fuck= "  << dp[now][p] << " " << v, system("pause");
                dp[now][p] = min(dp[now][p], dp[pre][j] + v);
                //cout << i << " " << j << " " << dp[pre][j] << " " << v << " " << i + 1 << " " << p << " " << dp[now][p], system("pause");
            }
        }
    }
    for (j = 0; j < end; j++) mini = min(mini, dp[now][j]);
    if (mini == INF) mini = -1;
    printf("%d\n", mini);
    //system("pause");
    return 1;
}

int main()
{
    int i, cas = 0;
    while (scanf("%d", &n) != EOF && n != 0)
    {
        init();
        printf("Case %d: ", ++cas);
        for (i = 1; i <= n; i++)
        {
            scanf("%s", s);
            add(s, 1);
        }
        scanf("%s", s);
        n = strlen(s);
        build();
        solve();
    }
    system("pause");
    return 0;
}
