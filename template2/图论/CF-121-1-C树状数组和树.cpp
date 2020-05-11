#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>
#include <set>

#define pause cout << " press any key to continue...",  cin >> chh
#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)
#define lowbit(x) ((x) & (-x))

using namespace std;
int chh;

int const N = 100005;
int const M = 20;

struct E {
    int v, nxt, id;
    void read(int v, int nxt, int id) {
        this->v = v;
        this->nxt = nxt;
        this->id = id;
    }
} e[N * 2];

int son[N], L[N], R[N], Node;
int dp[N][M], dep[N];
int tr[N * 2], rcd[N];

void dfs(int x, int id) {
    L[x] = ++Node;
    rcd[id] = x;
    dep[x] = dep[dp[x][0]] + 1;

    for (int i = 1; i < M; i++)
        dp[x][i] = dp[dp[x][i - 1]][i - 1];

    int v;
    for (int t = son[x]; t; t = e[t].nxt) {
        v = e[t].v;
        if (v == dp[x][0])
            continue;
        dp[v][0] = x;
        dfs(v, e[t].id);
    }

    R[x] = ++Node;
}

int LCA(int a, int b) {
    if (dep[a] < dep[b])
        swap(a, b);
    for (int i = M - 1; i >= 0; i--)
        if (dep[dp[a][i]] >= dep[b])
            a = dp[a][i];
    if (a == b)
        return a;
    for (int i = M - 1; i >= 0; i--)
        if (dp[a][i] != dp[b][i]) {
            a = dp[a][i], b = dp[b][i];
        }
    return dp[a][0];
}

void insert(int t, int n) {
    for (int i = n; i > 0; i -= lowbit(i)) tr[i] += t;
}

int query(int n, int N) {
    int res = 0;
    for (int i = n; i <= N; i += lowbit(i)) res += tr[i];
    return res;
}

int main() {

    int n, m, T, a, b, cnt, lca;
    dep[0] = -1;
    while (scanf("%d", &n) != -1) {

        cnt = Node = 0;
        memset(son, 0, (n + 1) * sizeof(int));

        for (int i = 1; i < n; i++) {
            scanf("%d%d", &a, &b);
            e[++cnt].read(a, son[b], i);
            son[b] = cnt;
            e[++cnt].read(b, son[a], i);
            son[a] = cnt;
        }
        dfs(1, 0);
        memset(tr, 0, (Node + 1) * sizeof(int));
        scanf("%d", &m);
        for (int i = 1; i <= m; i++) {
            scanf("%d%d", &a, &b);
            lca = LCA(a, b);
            insert(1, L[a]);
            insert(1, L[b]);
            insert(-2, L[lca]);
        }
        for (int i = 1; i < n; i++) {
            printf("%d ", query(L[rcd[i]], Node) - query(R[rcd[i]], Node));
        }
        puts("");

    }
    return 0;
}
