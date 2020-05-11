//============================================================================
// Name        : hdu4117.cpp
// Author      : 0222_
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#define N 200005
#define LEN 300005
#define pause cout << "按任意键继续......", cin >> ch;
using namespace std;

int ch;
int T, n, e;
int begin[N], len[N], w[N], pos[LEN], size[LEN];
int head[LEN], next[LEN], dp[N], value[LEN << 2];
char s[LEN];
map<char, int> trie[LEN];
map<char, int> :: iterator iter;

void dfs(int u)
{
	pos[u] = e++;
	size[u] = 1;
	for (int i = head[u]; i != -1; i = next[i])
	{
		if (pos[i] != -1) continue;
		dfs(i);
		size[u] += size[i];
	}
}

struct AhoCorasick
{
    static const int MAXN = LEN;
    static const int CHARSET = 26;

    int end;
    int fail[MAXN];

    void init()
    {
        end = 1;
    }

    void add(char *str, int p1, int p2)
    {
        int p = 0;
        for (int i = p1; i < p2; ++i)
        {
            if (! trie[p].count(str[i]))
            {
                trie[end].clear();
                trie[p][str[i]] = end++;
            }
            p = trie[p][str[i]];
        }
    }

    void build()
    {
        queue<int> bfs;
        fail[0] = 0;
        for (iter = trie[0].begin(); iter != trie[0].end(); iter++)
        {
        	fail[iter -> second] = 0;
        	bfs.push(iter -> second);
        }
        while (!bfs.empty())
        {
            int p = bfs.front();
            bfs.pop();
            for (iter = trie[p].begin(); iter != trie[p].end(); iter++)
            {
            	fail[iter -> second] = 0;
            	int tmp = p;
            	while (tmp != 0)
            	{
            		tmp = fail[tmp];
            		if (trie[tmp][iter -> first])
            		{
            			fail[iter -> second] = trie[tmp][iter -> first];
            			break;
            		}
            	}
            	bfs.push(iter -> second);
            }
        }
        memset(head, -1, sizeof(head));
        for (int i = 0; i < end; i++)
        {
        	next[i] = head[fail[i]];
        	head[fail[i]] = i;
        }
    }
} ac;

int find(int k, int l, int r, int x)
{
	if (x < l || x > r) return 0;
	if (l == x && r == x) return value[k];
	int mid = (l + r) >> 1, ans;
	ans = max(find(k << 1, l, mid, x), find(k << 1 | 1, mid + 1, r, x));
	ans = max(ans, value[k]);
	return ans;
}

int update(int k, int l, int r, int s, int t, int v)
{
	if (r < s || l > t) return 1;
	if (l >= s && r <= t) value[k] = max(value[k], v);
	else
	{
		int mid = (l + r) >> 1;
		update(k << 1, l, mid, s, t, v);
		update(k << 1 | 1, mid + 1, r, s, t, v);
	}
	return 1;
}

int main()
{
	int i, j, cas = 0, cur, ans;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		begin[0] = 0;
		for (i = 0; i < n; i++)
		{
			scanf("%s%d", s + begin[i], &w[i]);
			len[i] = strlen(s + begin[i]);
			begin[i + 1] = begin[i] + len[i];
		}
		ac.init();
		for (i = 0; i < n; i++)
			ac.add(s, begin[i], begin[i] + len[i]);
		ac.build();
		memset(pos, -1, sizeof(pos));
		e = 0;
		dfs(0);
		memset(value, 0, sizeof(value));
		ans = 0;
		for (i = 0; i < n; i++)
		{
			dp[i] = 0;
			cur = 0;
			for (j = begin[i]; j < begin[i] + len[i]; j++)
			{
				cur = trie[cur][s[j]];
				dp[i] = max(dp[i], find(1, 0, e - 1, pos[cur]));
			}
			dp[i] += w[i];
			ans = max(ans, dp[i]);
			update(1, 0, e - 1, pos[cur], pos[cur] + size[cur] - 1, dp[i]);
		}
		printf("Case #%d: %d\n", ++cas, ans);
		for (i = 0; i < ac.end; i++)
			trie[i].clear();
	}
	return 0;
}
