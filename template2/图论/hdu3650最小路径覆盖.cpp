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

const int N = 105;

struct NODE {
    int s, e;
    bool operator <(const NODE& arg0) const {
        if (s != arg0.s) return s < arg0.s;
        return e < arg0.e;
    }
} p[N];

int n;
int g[N][N], vis[N], match[N];

bool dfs(int x) {
    int i;
    for (i = 1; i <= n; i++) {
        if (vis[i] || !g[x][i]) continue;
        vis[i] = 1;
        if (match[i] == -1 || dfs(match[i])) {
            match[i] = x;
            return 1;
        }
    }
    return 0;
}

int main() {
    int i, j, ans;
    while (scanf("%d", &n) !=  EOF) {
        if (n == 0) break;
        for (i = 1; i <= n; i++) scanf("%d %d", &p[i].s, &p[i].e);
        sort(p + 1, p + n + 1);
        memset(g, 0, sizeof(g));
        for (i = 1; i <= n; i++) {
            for (j = i + 1; j <= n; j++) {
                if (p[i].e < p[j].s) g[i][j] = 1;
            }
        }
        memset(match, -1, sizeof(match));
        ans = 0;
        for (i = 1; i <= n; i++) {
            memset(vis, 0, sizeof(vis));
            if (dfs(i)) ans++;
        }
        printf("%d\n", n - ans);
    }
    return 0;
}
