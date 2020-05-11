#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define pause cout << " press any key to continue...",  cin >> chh
#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)
#define lowbit(x) ((x) & (-(x)))

using namespace std;
int chh;

const int N = 2005, M = N * N;

int T, n, e;
int head[N], vis[N], pnt[N], nxt[N];
char s[N][N];

bool dfs(int u, int fa) {
    int i, v;
    vis[u] = 1;
    for (i = 1; i <= n; i++) {
        if (s[u][i] == '0') continue;
        if (s[i][fa] == '1') return 1;
        if (!vis[i] && dfs(i, u)) return 1;
    }
    return 0;
}

int main() {
    int i, j, x, cas = 0;
    bool flag;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (i = 1; i <= n; i++) {
            scanf("%s", s[i] + 1);
        }
        memset(vis, 0, sizeof(vis));
        for (i = 1; i <= n; i++) {
            if (vis[i]) continue;
            flag = dfs(i, -1);
            if (flag) break;
        }
        if (flag) printf("Case #%d: Yes\n", ++cas);
        else printf("Case #%d: No\n", ++cas);
    }
    return 0;
}
