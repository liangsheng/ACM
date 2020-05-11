#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 10005, M = 100005;

struct Node
{
    int v, next, id;
} edge[M << 1];

int n, m, e, cnt;
int head[N], dfn[N], low[N];
vector<int> q;

void init()
{
    e = cnt = 0;
    q.clear();
    memset(head, -1, sizeof(head));
    memset(dfn, -1, sizeof(dfn));
}

void add_edge(int u, int v, int id)
{
    edge[e].v = v, edge[e].id = id;;
    edge[e].next = head[u];
    head[u] = e++;
}

int dfs(int p, int fa)     //注意,此题有重边,所以fa是边的id,若无重边,应该是点的id
{
    int i, v, id, ans = 0, tmp;
    dfn[p] = low[p] = ++cnt;
    if (p == 0) ans = 1;
    else if (p == n - 1) ans = n;
    for (i = head[p]; i != -1; i = edge[i].next)
    {
        v = edge[i].v, id = edge[i].id;
        if (dfn[v] == -1)
        {
            tmp = dfs(v, id);   //重边,边的id
            if (low[v] < low[p]) low[p] = low[v];
            if (low[v] > dfn[p] && (tmp == 1 || tmp == n)) q.push_back(id);
            ans += tmp;
        }
        else if (id != fa) low[p] = min(low[p], dfn[v]);
    }
    return ans;
}

int main()
{
    int i, j, u, v, size;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        init();
        for (i = 0; i < m; i++)
        {
            scanf("%d%d", &u, &v);
            add_edge(u, v, i), add_edge(v, u, i);
        }
        dfs(0, -1);
        sort(q.begin(), q.end());
        size = q.size();
        printf("%d\n",size);
        for (i = 0; i < size - 1; i++) printf("%d ", q[i]);
        if (size != 0) printf("%d", q[size - 1]);
        printf("\n");
    }
    system("pause");
    return 0;
}
