#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define pause cout << " press any key to continue...", cin >> chh
#define file_r(x) freopen(x, "r", stdin)
#define file_w(x) freopen(x, "w", stdout)

using namespace std;
int chh;

const int N = 105;

int T, p, n;
int a[N][N], ans[N];
char str[N];

int gause() {
    int i, j, k, row, col, x, y, sum;
    for (row = 0, col = 0; row < n && col < n; row++, col++) {
        for (i = row, j = row; i < n; i++)
            if (a[i][col] > a[j][col]) j = i;
        if (a[j][col] == 0) {
            row--;
            continue;
        }
        if (j != row)
            for (i = col; i <= n; i++) swap(a[row][i], a[j][i]);
        x = a[row][col];
        for (i = row + 1; i < n; i++) {
            y = a[i][col];
            for (j = col; j <= n; j++)
                a[i][j] = ((a[i][j] * x - a[row][j] * y) % p + p) % p;
        }
    }
    i = row - 1, j = n - 1;
    while (i >= 0) {
        sum = 0;
        for (k = j + 1; k < n; k++) {
            sum += a[i][k] * ans[k];
            sum %= p;
        }
        sum = a[i][n] - sum;
        while (sum  % a[i][j] != 0) sum += p;
        ans[j] = sum / a[i][j];
        ans[j] = (ans[j] % p + p) % p;
        i--, j--;
    }
}

int main() {
    int i, j;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%s", &p, str);
        n = strlen(str);
        memset(a, 0, sizeof(a));
        for (i = 0; i < n; i++) {
            if (str[i] == '*') a[i][n] = 0;
            else a[i][n] = str[i] - 'a' + 1;
            a[i][0] = 1;
            for (j = 1; j < n; j++)
                a[i][j] = a[i][j - 1] * (i + 1) % p;
        }
        gause();
        for (i = 0; i < n; i++)
            printf("%d%c", ans[i], i == n - 1 ? '\n' : ' ');
    }
    return 0;
}
