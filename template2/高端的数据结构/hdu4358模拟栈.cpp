#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>

#define pause cout << " press any key to continue...",  cin >> chh
#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)
#define lowbit(x) ((x) & (-(x)))

using namespace std;
int chh;

const int V = 100005, E = 200005;

struct NODE {
    int u, fa, h;
    NODE() {}
    NODE(int U, int FA, int H) : u(U), fa(FA), h(H) {}
} s[V];

int T, n, m, tim, e;
int head[V], val[V], pnt[E], nxt[E];
int res[V];
map<int, int> q[V];
map<int, int> :: iterator iter;

void init() {
    e = 0;
    memset(head, -1, sizeof(head));
}

void add_edge(int u, int v) {
    pnt[e] = v, nxt[e] = head[u], head[u] = e++;
}

void dfs(int u, int fa) {
    int i, v, first, second;
    q[u][val[u]]++;
    if (tim == 1) res[u] = 1;
    else res[u] = 0;
    for (i = head[u]; i != -1; i = nxt[i]) {
        v = pnt[i];
        if (v == fa) continue;
        dfs(v, u);
        if (q[u].size() < q[v].size()) {
            res[u] = res[v];
            for (iter = q[u].begin(); iter != q[u].end(); iter++) {
                first = iter -> first, second = iter -> second;
                if (q[v][first] == tim) res[u]--;
                q[v][first] += second;
                if (q[v][first] == tim) res[u]++;
            }
            swap(q[u], q[v]);
        } else {
            for (iter = q[v].begin(); iter != q[v].end(); iter++) {
                first = iter -> first, second = iter -> second;
                if (q[u][first] == tim) res[u]--;
                q[u][first] += second;
                if (q[u][first] == tim) res[u]++;
            }
        }
        q[v].clear();
    }
}

void my_stack() {
    int u, fa, h, v, first, second, cnt = 0;
    s[cnt++] = NODE(1, -2, -2);
    while (cnt) {
        u = s[cnt - 1].u, fa = s[cnt - 1].fa, h = s[cnt - 1].h;
        cnt--;
        if (h == -2) {
            q[u][val[u]]++;
            if (tim == 1) res[u] = 1;
            else res[u] = 0;
            h = head[u];
            if (h != -1) {
                if (pnt[h] == fa) h = nxt[h];
                if (h != -1) {
                    s[cnt++] = NODE(u, fa, h);
                    s[cnt++] = NODE(pnt[h], u, -2);
                }
            }
        } else {
            v = pnt[h];
            if (q[u].size() < q[v].size()) {
                res[u] = res[v];
                for (iter = q[u].begin(); iter != q[u].end(); iter++) {
                    first = iter -> first, second = iter -> second;
                    if (q[v][first] == tim) res[u]--;
                    q[v][first] += second;
                    if (q[v][first] == tim) res[u]++;
                }
                swap(q[u], q[v]);
            } else {
                for (iter = q[v].begin(); iter != q[v].end(); iter++) {
                    first = iter -> first, second = iter -> second;
                    if (q[u][first] == tim) res[u]--;
                    q[u][first] += second;
                    if (q[u][first] == tim) res[u]++;
                }
            }
            q[v].clear();
            h = nxt[h];
            if (h != -1) {
                if (pnt[h] == fa) h = nxt[h];
                if (h != -1) {
                    s[cnt++] = NODE(u, fa, h);
                    s[cnt++] = NODE(pnt[h], u, -2);
                }
            }
        }
    }
}

int main() {
    int i, j, u, v, cas = 0;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &tim);
        init();
        for (i = 1; i <= n; i++) {
            scanf("%d", &val[i]);
        }
        for (i = 1; i < n; i++) {
            scanf("%d %d", &u, &v);
            add_edge(u, v), add_edge(v, u);
        }
        for (i = 1; i <= n; i++) q[i].clear();
        my_stack();
        q[1].clear();
        printf("Case #%d:\n", ++cas);
        scanf("%d", &m);
        while (m--) {
            scanf("%d", &u);
            printf("%d\n", res[u]);
        }
        if (T != 0) puts("");
    }
    return 0;
}
