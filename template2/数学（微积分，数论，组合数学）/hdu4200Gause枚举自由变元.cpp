#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define pause cout << " press any key to continue...", cin >> chh
#define file_r(x) freopen(x, "r", stdin)
#define file_w(x) freopen(x, "w", stdout)

using namespace std;
int chh;

const int N = 105, P = 2;

int T, n, m, ans;
int a[N][N], res[N];

void debug() {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++) printf("%d ", a[i][j]);
        printf("\n");
    } pause;
}

void get_ans() {
    int i, j, num = 0, tmp;
    for (i = n - 1; i >= 0; i--) {
        if (res[i] != -1) {
            if (res[i] == 1) num++;
            continue;
        }
        tmp = 0;
        for (j = i + 1; j < n; j++) tmp = ((tmp + res[j] * a[i][j]) % P + P) % P;
        res[i] = ((a[i][n] - tmp) % P + P) % P;
        if (res[i] == 1) num++;
    }
    ans = min(ans, num);
}

void gause() {
    int i, j, row, col, x, y, jj, tmp, num, cnt;
    row = col = jj = 0;
    for (; row < n && col < n && jj < n; row++, col++, jj++) {
        for (i = row, j = row; i < n; i++)
            if (a[i][col] > a[j][col]) j = i;
        if (a[j][col] == 0) {
            tmp = n - jj + col - 1;
            for (i = 0; i < n; i++) swap(a[i][col], a[i][tmp]);
            row--, col--;
            continue;
        }
        if (j != row)
            for (i = col; i <= n; i++) swap(a[row][i], a[j][i]);
        x = a[row][col];
        for (i = row + 1; i < n; i++) {
            y = a[i][col];
            for (j = col; j <= n; j++)
                a[i][j] = ((a[i][j] * x - a[row][j] * y) % P + P) % P;
        }
    }
    ans = n;
    if (row == n) {
        memset(res, -1, sizeof(res));
        get_ans();
    } else {
        for (i = row; i < n; i++)
        if (a[i][n] != 0) {
                puts("impossible");
                return;
            }
        cnt = n - row;
        num = 1 << cnt;
        for (i = 0; i < num; i++) {
            memset(res, -1, sizeof(res));
            for (j = 0; j < cnt; j++) res[n - 1 - j] = (i >> j) & 1;
            get_ans();
        }
    }
    printf("%d\n", ans);
}

int main() {
    int i, j, l, r;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        memset(a, 0, sizeof(a));
        for (i = 0; i < n; i++) scanf("%d", &a[i][n]);
        for (i = 0; i < n; i++) {
            l = max(0, i - m), r = min(n - 1, i + m);
            for (j = l; j <= r; j++) a[i][j] = 1;
        };
        gause();
    }
    return 0;
}
