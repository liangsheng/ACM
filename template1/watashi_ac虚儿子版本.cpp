#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

struct AhoCorasick
{
    static const int UNDEF = 0;
    static const int MAXN = 500010;
    static const int CHARSET = 26;

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

    void add(char *str, int val)
    {
        int p = 0, id;
        for (int i = 0; str[i]; ++i)
        {
            id = str[i] - 'a';
            if (trie[p][id] == -1)
            {
                tag[end] = UNDEF;
                fill(trie[end], trie[end] + CHARSET, -1);
                trie[p][id] = end++;
            }
            p = trie[p][id];
        }
        tag[p] += val;
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
            //tag[p] += tag[fail[p]];
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

    int query(char *str)
    {
        int i, p = 0, ans = 0, t;
        for (i = 0; str[i]; i++)
        {
            p = trie[p][str[i] - 'a'];
            t = p;
            while (t && tag[t] != -1)
            {
                ans += tag[t];
                tag[t] = -1;
                t = fail[t];
            }
        }
        return ans;
    }
} ac;

int T, n;
char keyword[55], str[1000001];

int main()
{
    int i;
    scanf("%d", &T);
    while (T--)
    {
        ac.init();
        scanf("%d", &n);
        for (i = 1; i <= n; i++)
        {
            scanf("%s", keyword);
            ac.add(keyword, 1);
        }
        ac.build();
        scanf("%s", str);
        printf("%d\n", ac.query(str));
    }
    system("pause");
    return 0;
}
