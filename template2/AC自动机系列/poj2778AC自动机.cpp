#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define N 105
#define M 15
#define mod 100000
using namespace std;

const long long UNDEF = -1;
const long long MAXN = 105;
const long long CHARSET = 4;

long long n, m, NN;
long long a[N][N], tmp[N][N], ans[N][N];
char str[M];

long long fail[MAXN], tag[MAXN];
long long trie[MAXN][CHARSET];

struct AC
{
    long long end;

    void init()
    {
        tag[0] = UNDEF;
        fill(trie[0], trie[0] + CHARSET, -1);
        end = 1;
    }

    long long getId(char ch)
    {
        if (ch == 'A') return 0;
        if (ch == 'T') return 1;
        if (ch == 'C') return 2;
        if (ch == 'G') return 3;
    }

    void add(char *str, long long val)
    {
        long long p = 0, id;
        for (long long i = 0; str[i]; ++i)
        {
            id = getId(str[i]);
            if (trie[p][id] == -1)
            {
                tag[end] = UNDEF;
                fill(trie[end], trie[end] + CHARSET, -1);
                trie[p][id] = end++;
            }
            p = trie[p][id];
        }
        tag[p] = val;
    }

    void build()
    {
        queue<long long> bfs;
        fail[0] = 0;
        for (long long i = 0; i < CHARSET; ++i)
        {
            if (trie[0][i] != -1)
            {
                fail[trie[0][i]] = 0;
                bfs.push(trie[0][i]);
            }
            else trie[0][i] = 0;
        }
        while (!bfs.empty())
        {
            long long p = bfs.front();
            bfs.pop();
            for (long long i = 0; i < CHARSET; ++i)
            {
                if (trie[p][i] != -1)
                {
                    fail[trie[p][i]] = trie[fail[p]][i];
                    bfs.push(trie[p][i]);
                }
                else trie[p][i] = trie[fail[p]][i];
            }
        }
    }
} ac;

int mul(long long a[N][N], long long b[N][N])
{
    int i, j, k;
    memset(tmp, 0, sizeof(tmp));
    for(i = 0; i < NN; i++)
        for(j = 0; j < NN; j++)
            for(k = 0; k < NN; k++)
                tmp[i][j] = (tmp[i][j] + a[i][k] * b[k][j]) % mod;
    return 1;
}

long long solve()
{
    long long i, j, t, sum = 0;
    bool flag;
    NN = ac.end;
    memset(a, 0, sizeof(a));
    for (i = 0; i < ac.end; i++)
    {
        if (tag[i] != -1) continue;
        for (j = 0; j < 4; j++)
        {
            t = trie[i][j];
            flag = 1;
            while (t && flag)
            {
                if (tag[t] != -1) flag = 0;
                t = fail[t];
            }
            if (flag) a[i][trie[i][j]]++;
        }
    }
    for (i = 0; i < NN; i++) ans[i][i] = 1;
    while (n)
    {
        if (n & 1)
        {
            mul(a, ans);
            memcpy(ans, tmp, sizeof(tmp));
        }
        n >>= 1;
        mul(a, a);
        memcpy(a, tmp, sizeof(a));
    }
    for (i = 0; i < NN; i++)
        sum = (sum + ans[0][i] ) % mod;
    return sum;
}

int main()
{
    long long i, j, sum;
    while (cin >> m >> n)
    {
        ac.init();
        for (i = 1; i <= m; i++)
        {
            scanf("%s", str);
            ac.add(str, i);
        }
        ac.build();
        sum = solve();
        cout << sum << endl;
    }
    system("pause");
    return 0;
}
