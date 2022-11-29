#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>

#define pause cout << " press any key to continue...", cin >> chh
#define file_r(x) freopen(x, "r", stdin)
#define file_w(x) freopen(x, "w", stdout)

using namespace std;
int chh;

typedef long long LL;

const int N = 100010, MOD = 400005;

struct Node {
    int l, r;
    bool operator < (const Node& arg0) const {
        if (l != arg0.l) return l < arg0.l;
        return r < arg0.r;
    }
} t[2][N];

struct Hash {
    int head[MOD], nxt[MOD], size;
    Node s[MOD];

    void init() {
        size = 1;
        memset(head, -1, sizeof(head));
    }

    int update(Node arg0) {
        int i;
        LL c = (LL(arg0.l) * 200001LL + LL(arg0.r)) % MOD;
        for (i = head[c]; i != -1; i = nxt[i])
            if (s[i].l == arg0.l && s[i].r == arg0.r) return i;
        s[size] = arg0, nxt[size] = head[c], head[c] = size++;
        return size - 1;
    }
} h;

int T, n, m, e;
int num[2][N << 1], f[N], s[N];
map<Node, int> q;

int find(Node arg0) {
    if (q.find(arg0) == q.end()) q[arg0] = ++e;
    return q[arg0];
}

void dfs(int k) {
    int i, u, v, id, top = 0;
    memset(f, -1, sizeof(f));
    s[top++] = 1, f[1] = 0;
    while (top) {
        u = s[top - 1];
        if (u == 0) v = 0, top--;
        else {
            if (f[u] == 0) {
                f[u] = 1, f[t[k][u].l] = 0;
                s[top++] = t[k][u].l;
            } else if (f[u] == 1) {
                f[u] = 2, f[t[k][u].r] = 0;
                t[k][u].l = v;
                s[top++] = t[k][u].r;
            } else if (f[u] == 2) {
                t[k][u].r = v;
                //v = find(t[k][u]);
                v = h.update(t[k][u]);
                num[k][v]++;
                top--;
            }
        }
    }
}

int main() {
    int i, j, u, v;
    LL ans;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        memset(num, 0, sizeof(num));
        for (i = 1; i <= n; i++) {
            scanf("%d%d", &u, &v);
            if (u == -1) u = 0;
            if (v == -1) v = 0;
            t[0][i].l = u, t[0][i].r = v;
        }
        for (i = 1; i <= m; i++) {
            scanf("%d%d", &u, &v);
            if (u == -1) u = 0;
            if (v == -1) v = 0;
            t[1][i].l = u, t[1][i].r = v;
        }
        //q.clear(), e = 0;
        h.init();
        dfs(0), dfs(1);
        ans = 0;
        for (i = 1; i < h.size; i++) ans += LL(num[0][i]) * LL(num[1][i]);
        printf("%lld\n", ans);
    }
    return 0;
}
