/*
题意:有n个女生和n个男生,给定一些关系表示男生喜欢女生(即两个人可以结婚),再给定一个初始匹配,
表示这个男生和哪个女生结婚,初始匹配必定是合法的.求每个男生可以和哪几个女生可以结婚且能与所有人不发生冲突
(即确定某2个顶点连边后,其他2*(n-1)个顶点的2分图是否还可以构成完美匹配)
将男生从1到n编号,女生从(n+1)到2*n编号,输入时如果男生u可以和女生v结婚,那么就做一条从u到v的边(u,v),
对于输入的初始匹配(u,v)(表示男生u和女生v结婚),那么从v做一条到u的边(v,u),然后求解改图的强连通分量,如果男身和女生在同一个强连通分量内,则他们可以结婚,因为如果在同一个强连通分量内,当某个男生挑选另外的女生做老婆的话,那么先前给他说好了的那个老婆就可以在强连通分量里面寻找别的男生做老公.最后统计和该男生在同一个强连通分量的女生有多少,并将他们的编号升序输出.
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define pause cout << " press any key to continue...", cin >> chh
#define file_r(x) freopen(x, "r", stdin)
#define file_w(x) freopen(x, "w", stdout)

using namespace std;
int chh;

const int N = 2005 * 2, M = 200005 + N;

struct NODE {
    int v, next;
} edge[M];

int n, e, ct, scc, t, top;
int head[N], dfn[N], low[N], ins[N], sccf[N], s[N];
int ans[N];

void init() {
    e = ct = scc = top = 0;
    fill(head + 1, head + n * 2 + 1, -1);
    fill(dfn + 1, dfn + n * 2 + 1, 0);
    fill(low + 1, low + n * 2 + 1, 0);
    fill(ins + 1, ins + n * 2 + 1, 0);
}

void add_edge(int u, int v) {
    edge[e].v = v;
    edge[e].next = head[u];
    head[u] = e++;
}

int Tarjan(int u) {
    int i, v;
    low[u] = dfn[u] = ++ct;
    s[top++] = u;
    ins[u] = 1;
    for (i = head[u]; i != -1; i = edge[i].next) {
        v = edge[i].v;
        if (dfn[v] == 0) {
            Tarjan(v);
            low[u] = low[u] < low[v] ? low[u] : low[v];
        } else if (ins[v] && dfn[v] < low[u]) low[u] = dfn[v];
    }
    if (low[u] == dfn[u]) {
        scc++;
        do {
            v = s[--top];
            ins[v] = 0;
            sccf[v] = scc;
        }  while(u != v);
    }
    return 1;
}

void solve() {
    int i, j, v, size;
    for (i = 1; i <= n * 2; i++)
        if (dfn[i] == 0) Tarjan(i);
    for (i = 1; i <= n; i++) {
        size = 0;
        for (j = head[i]; j != -1; j = edge[j].next) {
            v = edge[j].v;
            if (sccf[i] == sccf[v]) ans[size++] = v - n;
        }
        sort(ans, ans + size);
        printf("%d ", size);
        for (j = 0; j < size - 1; j++) printf("%d ", ans[j]);
        printf("%d\n", ans[size - 1]);
    }
}

int main() {
    int i, j, v, m;
    while (scanf("%d", &n) != EOF) {
        init();
        for (i = 1; i <= n; i++) {
            scanf("%d", &m);
            while (m--) {
                scanf("%d", &v);
                add_edge(i, v + n);
            }
        }
        for (i = 1; i <= n; i++) {
            scanf("%d", &v);
            add_edge(v + n, i);
        }
        solve();
    }
    return 0;
}
