#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define LEN 45
#define INF 999999
using namespace std;

const int N = 55;
const int NODE = 505;
const int CH = 4;

int end;
int chd[NODE][CH];
int work[NODE];
int fail[NODE];
int q[NODE];

int n;
int a[CH], b[CH], c[CH];
int dp[20000][NODE];
char s[LEN];

void init()
{
    end = 1;
    memset(chd, -1, sizeof(chd));
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

void solve()
{
    int i, j, p, u, v, w, maxi = 0;
    memset(dp, -1, sizeof(dp));
    memset(a, 0, sizeof(a));
   // cout << "end= " << fail[4], system("pause");
    for (i = 0; s[i]; i++) a[getId(s[i])]++;
    b[0] = 1;
    b[1] = b[0] * (a[0] + 1);
    b[2] = b[1] * (a[1] + 1);
    b[3] = b[2] * (a[2] + 1);
    dp[0][0] = 0;
    for (c[3] = 0;  c[3] <= a[3]; c[3]++)
        for (c[2] = 0;  c[2] <= a[2]; c[2]++)
            for (c[1] = 0;  c[1] <= a[1]; c[1]++)
                for (c[0] = 0;  c[0] <= a[0]; c[0]++)
                {
                    u = c[0] + c[1] * b[1] + c[2] * b[2] + c[3] * b[3];
                    //cout << "u= " << u, system("pause");
                    for (i = 0; i < end; i++)
                    {
                        if (dp[u][i] == -1) continue;
                        //cout << "FUck= " << u << " " << i, system("pause");
                        for (j = 0; j < CH; j++)
                        {
                            if (c[j] + 1 > a[j]) continue;
                            //cout << "j= " << j << " " << c[j] + 1, system("pause");
                            p = u + b[j];
                            v = chd[i][j];
                            w = dp[u][i] + work[v];
                            //cout << "OPOP" << p << " " << v, system("pause");
                            if (w > dp[p][v]) dp[p][v] = w;
                            maxi = max(maxi, dp[p][v]);
                        }
                    }
                }
    printf("%d\n", maxi);
    //system("pause");
}

int main()
{
    int i, j, cas = 0;
    while (scanf("%d", &n) != EOF && n != 0)
    {
        printf("Case %d: ", ++cas);
        init();
        for (i = 1; i <= n; i++)
        {
            scanf("%s", s);
            add(s, 1);
        }
        scanf("%s", s);
        build();
        solve();
    }
    system("pause");
    return 0;
}
