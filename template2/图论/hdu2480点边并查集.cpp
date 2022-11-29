#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>

#define pause cout << " press any key to continue...",  cin >> chh
#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)

using namespace std;
int chh;

const int N = 1005, M = 1000 * 1000 / 2 + 5;

struct NODE {
    int u, v, w, f;
    bool operator <(const NODE& arg0) const {
        return w > arg0.w;
    }
} a[M];

int n, m;
int f[N], vis[N];

int find(int x) {
    if (f[x] == x) return f[x];
    f[x] = find(f[x]);
    return f[x];
}

void solve() {
    int i, j, x, y, cnt = 0, ans = 0;
    for (i = 1; i <= n; i++) {
        f[i] = i;
        vis[i] = 0;
    }
    for (i = 0; i < m && cnt < n; i++) {
        x = find(a[i].u);
        if (a[i].f == 1) {
            if (vis[x]) continue;
            ans += a[i].w, cnt++, vis[x] = 1;
        } else {
            y = find(a[i].v);
            if (vis[x] && vis[y]) continue;
            ans += a[i].w, cnt++;
            if (vis[x] + vis[y] == 1) vis[x] = vis[y] = 1;
            else {

                if (x == y) vis[x] = 1;
                else f[x] = y;
            }
        }
    }
    printf("%d\n", ans);
}

int main() {
    int i, j;
    while (scanf("%d %d", &n, &m) != EOF) {
        for (i = 0; i < m; i++) scanf("%d %d %d %d", &a[i].u, &a[i].v, &a[i].f, &a[i].w);
        sort(a, a + m);
        solve();
    }
    return 0;
}
