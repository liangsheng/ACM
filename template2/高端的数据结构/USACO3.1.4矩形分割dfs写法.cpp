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

const int N = 1005, M = 2505;

struct NODE {
    int lx, ly, rx, ry, col;
} p[N];

int a, b, n, area;
int ans[M];

void dfs(int lx, int ly, int rx, int ry, int i) {
    if (i == 0) return ;
    if (p[i].lx >= rx || p[i].ly >= ry || p[i].rx <= lx || p[i].ry <= ly) {
        dfs(lx, ly, rx, ry, i - 1);
    } else {
        int k1, k2, k3, k4;
        k1 = max(lx, p[i].lx), k2 = min(rx, p[i].rx);
        if (k1 > lx) dfs(lx, ly, k1, ry, i - 1);
        if (k2 < rx) dfs(k2, ly, rx, ry, i - 1);
        k3 = max(ly, p[i].ly), k4 = min(ry, p[i].ry);
        if (k3 > ly) dfs(k1, ly, k2, k3, i - 1);
        if (k4 < ry) dfs(k1, k4, k2, ry, i - 1);
        ans[p[i].col] += (k2 - k1) * (k4 - k3);
        area -= (k2 - k1) * (k4 - k3);
    }
}

int main() {
    int i, j;
    while (~scanf("%d %d %d", &a, &b, &n)) {
        memset(ans, 0, sizeof(ans));
        for (i = 1; i <= n; i++) scanf("%d %d %d %d %d", &p[i].lx, &p[i].ly, &p[i].rx, &p[i].ry, &p[i].col);
        area = a * b;
        dfs(0, 0, a, b, n);
        ans[1] += area;
        for (i = 1; i <= 2500; i++) {
            if (ans[i] == 0) continue;
            printf("%d %d\n", i, ans[i]);
        }
        puts("");
    }
    return 0;
}
