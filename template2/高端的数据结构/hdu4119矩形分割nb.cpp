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

typedef long long LL;

inline void in(int &t) {
    int n = 0, s = 1;
    char ch = getchar();
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-') s = -1, ch = getchar();
    while (ch >= '0' && ch <= '9') n = n * 10 + ch - '0', ch = getchar();
    t = n * s;
}

const int N = 10005;

struct NODE {
    int lx, ly, rx, ry, col;
    bool operator <(const NODE& arg0) const {
        return col < arg0.col;
    }
} p[N];

int T, n, a, b;
int num[5], e[7] = {1, 2, 4, 3, 5, 6, 7};
LL ans[8];

void dfs(int lx, int ly, int rx, int ry, int i, int c) {
    if (lx == rx || ly == ry) return ;
    if (i == n + 1) {
        if (c != 0) ans[c] += (LL) (rx - lx) * (ry - ly);
        return ;
    }
    if (i <= num[1] && (c | 1) == c) {
        dfs(lx, ly, rx, ry, num[1] + 1, c);
        return ;
    } else if (i > num[1] && i <= num[2] && (c | 2) == c) {
        dfs(lx, ly, rx, ry, num[2] + 1, c);
        return ;
    } else if (i > num[2] && i <= num[4] && (c | 4) == c) {
        dfs(lx, ly, rx, ry, n + 1, c);
        return ;
    }
    if (p[i].lx >= rx || p[i].rx <= lx || p[i].ly >= ry || p[i].ry <= ly) {
        dfs(lx, ly, rx, ry, i + 1, c);
    } else {
        int k1, k2, k3, k4;
        k1 = max(lx, p[i].lx), k2 = min(rx, p[i].rx);
        if (k1 > lx) dfs(lx, ly, k1, ry, i + 1, c);
        if (k2 < rx) dfs(k2, ly, rx, ry, i + 1, c);
        k3 = max(ly, p[i].ly), k4 = min(ry, p[i].ry);
        if (k3 > ly) dfs(k1, ly, k2, k3, i + 1, c);
        if (k4 < ry) dfs(k1, k4, k2, ry, i + 1, c);
        dfs(k1, k3, k2, k4, i + 1, c | p[i].col);
    }
}

int main() {
    int i, j, cas = 0;
    char ch;
    in(T);
    while (T--) {
        in(n);
        num[1] = num[2] = num[4] = a = b = 0;
        for (i = 1; i <= n; i++) {
            ch = getchar();
            while (ch != 'R' && ch != 'G' && ch != 'B') ch = getchar();
            if (ch == 'R') p[i].col = 1;
            else if (ch == 'G') p[i].col = 2;
            else p[i].col = 4;
            num[p[i].col]++;
            in(p[i].lx), in(p[i].ly), in(p[i].rx), in(p[i].ry);
            a = max(a, p[i].rx), b = max(b, p[i].ry);
        }
        sort(p + 1, p + n + 1);
        num[2] += num[1], num[4] += num[2];
        memset(ans, 0, sizeof(ans));
        dfs(0, 0, a, b, 1, 0);
        printf("Case %d:\n", ++cas);
        for (i = 0; i < 7; i++) printf("%lld\n", ans[e[i]]);
    }
    return 0;
}
