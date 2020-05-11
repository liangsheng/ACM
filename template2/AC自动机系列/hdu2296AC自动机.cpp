#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define LEN 12
using namespace std;

const int N = 55;
const int M = 110;
const int NODE = 1010;
const int CH = 26;

int n, m, least;
int dp[N][NODE];
char str[M][LEN];
string s[N][NODE];

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
    work[0] = 0;
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
    int i, j, k, p, t, maxi = 0;
    string str, ans;
    memset(dp, -1, sizeof(dp));
    for (i = 0; i <= n; i++)
        for (j = 0; j < end; j++) s[i][j] = "";
    ans.clear();
    dp[0][0] = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < end; j++)
        {
            if (dp[i][j] == -1) continue;
            for (k = 0; k < CH; k++)
            {
                p = chd[j][k];
                t = dp[i][j] + work[p];
                if (t > dp[i + 1][p])
                {
                    dp[i + 1][p] = t;
                    str = s[i][j];
                    str.push_back('a' + k);
                    s[i + 1][p] = str;
                }
                else if ((t == dp[i + 1][p]) && (str < s[i + 1][p]))
                {
                    str = s[i][j];
                    str.push_back('a' + k);
                    s[i + 1][p] = str;
                }
                if (dp[i + 1][p] > maxi) maxi = dp[i + 1][p], ans = s[i + 1][p];
                else if (dp[i + 1][p] == maxi && s[i + 1][p].size() == ans.size() && s[i + 1][p] < ans) ans = s[i + 1][p];
            }
        }
    }
    cout << ans << endl;
}

int T;

int main()
{
    int i, val;
    for (i = 0; i < 26; i++) sw['a' + i] = i;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        init();
        for (i = 1; i <= m; i++) scanf("%s", str[i]);
        for (i = 1; i <= m; i++)
        {
            scanf("%d", &val);
            add(str[i], val);
        }
        build();
        solve();
    }
    //system("pause");
    return 0;
}
