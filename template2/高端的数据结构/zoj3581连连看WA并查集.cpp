#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>
#include <cmath>

#define pause cout << " press any key to continue...",  cin >> chh
#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)
#define sqr(x) ((x)*(x))

using namespace std;
int chh;

const int N = 305;

int n, m, e, q;
int g[N][N], L1[N][N], R1[N][N], L2[N][N], R2[N][N];

void init() {
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 0; j <= m + 1; j++) {
            L1[i][j] = j;
            R1[i][j] = j;
        }
    }
    for (i = 1; i <= m; i++) {
        for (j = 0; j <= n + 1; j++) {
            L2[i][j] = j;
            R2[i][j] = j;
        }
    }
}

int find(int LR[], int p) {
    if (LR[p] == p) return LR[p];
    LR[p] = find(LR, LR[p]);
    return LR[p];
}

void del(int L[], int R[], int p) {
//    int l = find(L, p), r = find(R, p);
//    L[l] = l - 1, R[r] = r + 1;
    L[p] = p - 1, R[p] = p + 1;
}

bool judge(int x1, int y1, int x2, int y2) {
    int i, j, l1, r1, l2, r2, l3, r3;
    bool f = 0;
    if (!g[x1][y1] || !g[x2][y2]) return 0;
    l1 = find(L1[x1], y1 - 1) + 1, r1 = find(R1[x1], y1 + 1) - 1;
    l2 = find(L1[x2], y2 - 1) + 1, r2 = find(R1[x2], y2 + 1) - 1;
    for (i = l1; i <= r1 && f == 0; i++) {
        l3 = find(L2[i], x1 - 1) + 1, r3 = find(R2[i], x1 + 1) - 1;
        if (i >= l2 && i <= r2 && x2 >= l3 && x2 <= r3) f = 1;
    }
    if (!f) {
        l1 = find(L2[y1], x1 - 1) + 1, r1 = find(R2[y1], x1 + 1) - 1;
        l2 = find(L2[y2], x2 - 1) + 1, r2 = find(R2[y2], x2 + 1) - 1;
        for (i = l1; i <= r1 && f == 0; i++) {
            l3 = find(L1[i], y1 - 1) + 1, r3 = find(R1[i], y1 + 1) - 1;
            if (y2 >= l3 && y2 <= r3 && i >= l2 && i <= r2) f = 1;
        }
    }
    if (f) {
        g[x1][y1] = g[x2][y2] = 0;
        del(L1[x1], R1[x1], y1);
        del(L2[y1], R2[y1], x1);
        del(L1[x2], R1[x2], y2);
        del(L2[y2], R2[y2], x2);
    }
    return f;
}

int main() {
    int i, j, k, u, v, x, y, res;
    while (scanf("%d %d", &n, &m) != EOF) {
        memset(g, 0, sizeof(g));
        scanf("%d", &e);
        for (i = 1; i <= e; i++) {
            scanf("%d %d", &u, &v);
            u++, v++;
            g[u][v] = 1;
        }
        init();
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                if (g[i][j]) continue;
                del(L1[i], R1[i], j);
                del(L2[j], R2[j], i);
            }
        }
        res = 60;
        scanf("%d", &q);
        for (i = 1; i <= q; i++) {
            scanf("%d %d %d %d", &u, &v, &x, &y);
            u++, v++, x++, y++;
            if (u < 1 || u > n || v < 1 || v > m || x < 1 || x > n || y < 1 || y > m) res--;
            else {
                if (judge(u, v, x, y)) res += 2;
                else res--;
            }
            printf("%d\n", res);
        }
    }
    return 0;
}
