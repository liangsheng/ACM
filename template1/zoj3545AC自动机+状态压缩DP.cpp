#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
#define inf (1 << 30)
#define N 105
using namespace std;

struct AhoCorasick
{
    static const int UNDEF = 0;
    static const int MAXN = 1001;
    static const int CHARSET = 4;

    int end;   //总节点数包括根节点0
    int tag[MAXN];   //每个节点记录的值, 各题不一样
    int fail[MAXN];   //失败指针
    int trie[MAXN][CHARSET];

    void init()
    {
        tag[0] = UNDEF;
        fill(trie[0], trie[0] + CHARSET, -1);
        end = 1;
    }

    int get_id(char ch)
    {
        if (ch == 'A') return 0;
        if (ch == 'T') return 1;
        if (ch == 'C') return 2;
        return 3;
    }

    void add(char *str, int val)
    {
        int p = 0, id;
        for (int i = 0; str[i]; ++i)
        {
            id = get_id(str[i]);
            if (trie[p][id] == -1)
            {
                tag[end] = UNDEF;
                fill(trie[end], trie[end] + CHARSET, -1);
                trie[p][id] = end++;
            }
            p = trie[p][id];
        }
        tag[p] |= val;
    }

    void build()
    {
        queue<int> bfs;
        fail[0] = 0;
        for (int i = 0; i < CHARSET; ++i)
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
            int p = bfs.front();
            tag[p] |= tag[fail[p]];
            bfs.pop();
            for (int i = 0; i < CHARSET; ++i)
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

int n, len;
int w[N];
bool dp[2][1000][1025];
char str[1001];

int main()
{
    int i, j, k, g, pre, cur, next, id, t, ans, sum, m;
    while (scanf("%d%d", &n, &len) != EOF)
    {
        ac.init();
        for (i = 0; i < n; i++)
        {
            scanf("%s%d", str, &w[i]);
            ac.add(str, 1 << i);
        }
        ac.build();
        pre = 1, cur = 0, m = (1 << n);
        for (j = 0; j < ac.end; j++)
            for (k = 0; k < m; k++) dp[cur][j][k] = 0;
        dp[cur][0][0] = 1;
        for (i = 0; i < len; i++)
        {
            swap(cur, pre);
            for (j = 0; j < ac.end; j++)
                for (k = 0; k < m; k++) dp[cur][j][k] = 0;
            for (j = 0; j < ac.end; j++)
            {
                for (k = 0; k < m; k++)
                {
                    if (dp[pre][j][k] == 0) continue;
                    for (g = 0; g < 4; g++)
                    {
                        next = ac.trie[j][g];
                        id = ac.tag[next];
                        dp[cur][next][k | id] |= dp[pre][j][k];
                    }
                }
            }
        }
        ans = -inf;
        for (i = 0; i < ac.end; i++)
            for (j = 0; j < m; j++)
            {
                if (dp[cur][i][j] == 0) continue;
                sum = 0;
                for (k = 0; k < n; k++)
                    if ((1 << k) & j) sum += w[k];
                ans = max(ans, sum);
            }
        if (ans < 0) printf("No Rabbit after 2012!\n");
        else printf("%d\n", ans);
    }
    system("pause");
    return 0;
}
