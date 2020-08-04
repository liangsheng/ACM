#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <stack>
#include <queue>
#include <map>
#include <vector>
#include <cstdlib>
using namespace std;

#define LL long long
#define N 102000
#define M 200020
#define eps 1e-8
#define MP make_pair
#define Pi acos(-1.0)
#define inf 0x3f3f3f3f
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define ls (i << 1)
#define rs (ls | 1)
#define md ((ll + rr) >> 1)
#define lson ll, md, ls
#define rson md + 1, rr, rs
#define mod 998244353

int fst[N], nxt[M], to[M], e;
void init() {
    memset(fst, -1, sizeof fst);
    e = 0;
}
void add(int u, int v) {
    to[e] = v, nxt[e] = fst[u], fst[u] = e++;
}
int val[N];
int n, q;
int dep[N], sz[N], son[N], fa[N];
int dc, tid[N], lab[N];
int tp[N];
int s[N<<2];

void dfsH(int u, int p, int d) {
    dep[u] = d, fa[u] = p;
    son[u] = 0, sz[u] = 1;
    int mx = 0;
    for(int i = fst[u]; ~i; i = nxt[i]) {
        int v = to[i];
        if(v == p) continue;
        dfsH(v, u, d + 1);
        sz[u] += sz[v];
        if(sz[v] > mx)
            mx = sz[v], son[u] = v;
    }
}
void dfsC(int u, int anc) {
    tid[u] = ++dc;
    lab[dc] = u;
    tp[u] = anc;
    if(son[u])
        dfsC(son[u], anc);
    for(int i = fst[u]; ~i; i = nxt[i]) {
        int v = to[i];
        if(v == fa[u] || v == son[u]) continue;
        dfsC(v, v);
    }
}

int readint() {
    char c;
    while((c = getchar()) && !(c >= '0' && c <= '9'));
    int ret = c - '0';
    while((c = getchar()) && c >= '0' && c <= '9')
        ret = ret * 10 + c - '0';
    return ret;
}

void build(int ll, int rr, int i) {
    if(ll == rr) {
        s[i] = val[lab[ll]];
        return;
    }
    build(lson);
    build(rson);
    s[i] = s[ls] ^ s[rs];
}

void update(int x, int v, int ll, int rr, int i) {
    if(ll == rr) {
        s[i] = v;
        return;
    }
    if(x <= md) update(x, v, lson);
    else update(x, v, rson);
    s[i] = s[ls] ^ s[rs];
}
int query(int l, int r, int ll, int rr, int i) {
    if(ll == l && rr == r) {
        return s[i];
    }
    if(r <= md) return query(l, r, lson);
    if(l > md) return query(l, r, rson);
    return query(l, md, lson) ^ query(md + 1, r, rson);
}
int f(int u, int v) {
    int ret = 0;
    while(tp[u] != tp[v]) {
        if(dep[tp[u]] > dep[tp[v]]) swap(u, v);
        ret ^= query(tid[tp[v]], tid[v], 1, n, 1);
        v = fa[tp[v]];
    }
    if(dep[u] > dep[v]) swap(u, v);
    ret ^= query(tid[u], tid[v], 1, n, 1);
    return ret;
}

int main() {
    //freopen("tt.txt", "r", stdin);
    int cas;
    scanf("%d", &cas);
    while(cas--) {
        scanf("%d%d", &n, &q);
        init();
        for(int i = 1; i < n; ++i) {
            int u, v;
            u = readint();
            v = readint();
            add(u, v);
            add(v, u);
        }
        for(int i = 1; i <= n; ++i) {
            val[i] = readint();
            ++val[i];
        }
        dfsH(1, -1, 0);
        dc = 0;
        dfsC(1, 1);
        build(1, n, 1);

        while(q--) {
            int op, x, y;
            op = readint();
            x = readint();
            y = readint();
            if(op == 0) {
                ++y;
                update(tid[x], y, 1, n, 1);
            }
            else {
                int t = f(x, y);
                if(t == 0) {
                    puts("-1");
                }
                else
                    printf("%d\n", t - 1);
            }
        }
    }
    return 0;
}
