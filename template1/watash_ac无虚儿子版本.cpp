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
        int t, p, i;
        queue<int> bfs;
        fail[0] = -1;
        bfs.push(0);
        while (!bfs.empty())
        {
            t = bfs.front();
            bfs.pop();
            for (i = 0; i < CHARSET; i++)
            {
                if (trie[t][i] != -1)
                {
                    if (t == 0) fail[trie[t][i]] = 0;
                    else
                    {
                        p = fail[t];
                        while (p != -1)
                        {
                            if (trie[p][i] != -1)
                            {
                                fail[trie[t][i]] = trie[p][i];
                                break;
                            }
                            p = fail[p];
                        }
                        if (p == -1) fail[trie[t][i]] = 0;
                    }
                    bfs.push(trie[t][i]);
                }
            }
        }
    }

    int query(char *str)
    {
        int i, ans = 0, p = 0, t, id, len = strlen(str);
        for (i = 0; str[i]; i++)
        {
            id = str[i] - 'a';
            while (trie[p][id] == -1 && p != 0) p = fail[p];
            p = trie[p][id];
            p = (p == -1) ? 0 : p;
            t = p;
            while (t!= 0 && tag[t] != -1)
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
