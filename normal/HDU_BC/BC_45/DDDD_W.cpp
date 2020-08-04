#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <stack>
#include <bitset>
#pragma comment(linker,"/STACK:102400000,102400000")
#define INF 0x3f3f3f3f
#define eps 1e-8
#define FI first
#define SE second
using namespace std;
typedef long long LL;

inline void R(int &x) {
  char c; bool sign = false;
  for (c = getchar(); c<'0' || c>'9'; c = getchar()) if (c=='-') sign = true;
  for (x = 0; c>='0' && c<='9'; c = getchar()) x = x*10+c-'0';
  sign && (x=-x);
}

const int N = 100005;
int head[N];
struct Edge {
    int nxt, to;
} ed[N * 2];
int ecnt;

void addedge(int u, int v) {
    ed[ecnt].nxt = head[u];
    ed[ecnt].to = v;
    head[u] = ecnt++;
}

int w[N], fa[N][20], dep[N], in[N], out[N], label;
int sum[N];
void dfs(int u, int father) {
    fa[u][0] = father;
    in[u] = ++label;
    for(int i = 1; i < 20; ++i) {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }
    for(int e = head[u]; ~e; e = ed[e].nxt) {
        int v = ed[e].to;
        if(v == father) continue;
        dep[v] = dep[u] + 1;
        sum[v] = sum[u] ^ w[v];
        dfs(v, u);
    }
    out[u] = label;
}

int lca(int u, int v) {
    if(dep[u] < dep[v]) swap(u, v);
    for(int i = 19; i >= 0; --i) if(dep[fa[u][i]] >= dep[v]) {
        u = fa[u][i];
    }
    if(u == v) return u;
    for(int i = 19; i >= 0; --i) if(fa[u][i] ^ fa[v][i]) {
        u = fa[u][i];
        v = fa[v][i];
    }
    return fa[u][0];
}

int bit[N];
inline int read(int x) {
    int res = 0;
    for(; x; x ^= x & -x) res ^= bit[x];
    return res;
}

inline void add(int x, int v) {
    for(; x <= label; x += x & -x) bit[x] ^= v;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n, q;
        R(n); R(q);
        memset(head, -1, (n + 3) * sizeof(int));
        memset(bit, 0, (n + 3) * sizeof(int));
        ecnt = 0;
        for(int i = 1; i < n; ++i) {
            int u, v;
            R(u); R(v);
            addedge(u, v);
            addedge(v, u);
        }
        for(int i = 1; i <= n; ++i) R(w[i]);
        label = 0;
        sum[1] = w[1];
        dfs(1, 1);
        printf("ll= %d\n", label);
        while(q--) {
            int op; R(op);
            if(op) {
                int u, v;
                R(u); R(v);
                int lc = lca(u, v);
                int dis = dep[u] + dep[v] - 2 * dep[lc] + 1;
                if(dis & 1) {
                    int ans = sum[u] ^ read(in[u]);
                    ans ^= sum[v] ^ read(in[v]);
                    ans ^= w[lc];
                    printf("%d\n", ans);
                }
                else puts("-1");
            }
            else {
                int x, y;
                R(x); R(y);
                add(in[x], w[x] ^ y);
                add(out[x] + 1, w[x] ^ y);
                w[x] = y;
            }
        }
    }
    return 0;
}
