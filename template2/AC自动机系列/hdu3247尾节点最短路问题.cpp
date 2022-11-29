/*
题目：Searching the String
题目来源：hdu3247
题目内容或思路：
    AC自动机+动规
    在没有子串时, 动规时不用考虑fail, TSP
做题日期：2012.3.8
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define M 1005
#define LEN 1005
#define INF 999999
using namespace std;

const int N = 15;
const int NODE = 60005;
const int CH = 2;

int end;
int chd[NODE][CH];
int work[NODE];
int fail[NODE];
int q[NODE];

int n, m, e1;
int p1[N], able[N];
int d[N][N], vis[NODE], dis[NODE];
int dp[1030][N];

char s[N][LEN];

void init()
{
    end = 1;
    memset(chd[0], -1, sizeof(chd[0]));
    work[0] = 0;
}

void add(char* str, int val)
{
    int i, id, p = 0;
    for (i = 0; str[i]; i++)
    {
        id = str[i] - '0';
        if (chd[p][id] == -1)
        {
            memset(chd[end], -1, sizeof(chd[end]));
            work[end] = 0;
            chd[p][id] = end++;
        }
        p = chd[p][id];
    }
    work[p] = val;
    if (val == 1) p1[++e1] = p, d[0][e1] = strlen(str);
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
                if (work[fail[v]] == -1) work[v] = -1;
                q[tail++] = v;
            }
            else chd[p][i] = chd[fail[p]][i];
        }
    }
}

/*==================================================*\
| KMP匹配算法O(M+N)
| CALL: res=kmp(str, pat); 原串为str; 模式为pat(长为P);
\*==================================================*/
int kmp(char* str, char* pat)
{
    int i, j, k;
    memset(fail, -1, sizeof(fail));
    for (i = 1; pat[i]; ++i)
    {
        for (k = fail[i-1]; k >= 0 && pat[i] != pat[k + 1];
                k = fail[k]);
        if (pat[k + 1] == pat[i]) fail[i] = k + 1;
    }
    i = j = 0;
    while( str[i] && pat[j] )  // By Fandywang
    {
        if( pat[j] == str[i] ) ++i, ++j;
        else if (j == 0) ++i;//第一个字符匹配失败，从str下个字符开始
        else j = fail[j - 1] + 1;
    }
    if (pat[j]) return j;
    else return -1;
}

int get_sub()
{
    int i, j;
    fill(able + 1, able + n + 1, 1);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n && able[i]; j++)
        {
            if (j == i || (! able[j])) continue;
            if (kmp(s[j], s[i]) == -1) able[i] = 0;
        }
    for (i = 1; i <= n; i++)
    {
        if (! able[i]) continue;
        add(s[i], 1);
    }
    return 1;
}

int solve()
{
    int i, j, tmp, k, t, p, ans, head, tail;
    for (i = 1; i <= e1; i++)
    {
        fill(dis, dis + end, INF);
        memset(vis, 0, sizeof(vis));
        head = tail = 0;
        vis[p1[i]] = 1, dis[p1[i]] = 0;
        q[tail++] = p1[i];
        while (head != tail)
        {
            t = q[head++];
            for (j = 0; j < CH; j++)
            {
                p = chd[t][j];
                if (vis[p] || work[p] == -1) continue;
                vis[p] = 1, dis[p] = dis[t] + 1, q[tail++] = p;
            }
        }
        for (j = 1; j <= e1; j++) d[i][j] = dis[p1[j]];
    }
    tmp = (1 << e1);
    for (i = 0; i < tmp; i++)
        for (j = 0; j <= e1; j++) dp[i][j] = INF;
    dp[0][0] = 0;
    for (i = 0; i < tmp; i++)
        for (j = 0; j <= e1; j++)
        {
            if (dp[i][j] == INF) continue;
            for (k = 1; k <= e1; k++)
            {
                if ((i >> (k - 1)) & 1) continue;
                t = i | (1 << (k - 1));
                dp[t][k] = min(dp[t][k], dp[i][j] + d[j][k]);
            }
        }
    ans = INF;
    for (i = 1; i <= e1; i++) ans = min(dp[tmp - 1][i], ans);
    printf("%d\n", ans);
    return 1;
}

int main()
{
    int i, j;
    while (scanf("%d%d", &n, &m) != EOF && n != 0 && m != 0)
    {
        init();
        e1 = 0;
        for (i = 0; i <= n; i++)
            for (j = 0; j <= n; j++) d[i][j] = INF;
        for (i = 1; i <= n; i++) scanf("%s", s[i]);
        get_sub();
        for (i = 1; i <= m; i++)
        {
            scanf("%s", s[1]);
            add(s[1], -1);
        }
        build();
        solve();
    }
    system("pause");
    return 0;
}
