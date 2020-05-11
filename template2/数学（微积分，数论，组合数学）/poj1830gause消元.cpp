#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define pause cout << " press any key to continue...", cin >> ch
#define file_r(x) freopen(x, "r", stdin)
#define file_w(x) freopen(x, "w", stdout)

using namespace std;
int ch;

const int N = 35;

int T, n;
int ss[N], se[N];
int matrix[N][N];

int power(int x, int y) {
    int ans = 1;
    while (y) {
        if (y & 1) ans *= x;
        x *= x;
        y >>= 1;
    }
    return ans;
}

int gause() {
    int i, j, row, col, a, b;
    for (row = 0, col = 0; row < n && col < n; row++, col++) {
        for (i = row, j = row; i < n; i++)
            if (matrix[i][col] > matrix[j][col])  j = i;
        if (matrix[j][col] == 0) {
            row--;
            continue;
        }
        if (j != row)
            for (i = col; i <= n; i++) swap(matrix[row][i], matrix[j][i]);
        a = matrix[row][col];
        for (i = row + 1; i < n; i++) {
            b = matrix[i][col];
            if (b == 0) continue;
            for (j = col; j <= n; j++)
                matrix[i][j] = (matrix[i][j] * a - matrix[row][j] * b + 2) % 2;
        }
    }
    for (i = row; i < n; i++)
        if (matrix[i][n] != 0) return -1;   //无解
    if (row == n) return 1;              //唯一解
    return power(2, n - row);            //多解,  2 ^自由变元的个数
    /*i = row - 1, j = n - 1;    //有唯一解时,输出解
    while (i >= 0) {
        sum = 0;
        for (k = j + 1; k < n; k++)
            sum += matrix[i][k] * ans[k];
        ans[j] = (matrix[i][n] - sum) / matrix[i][j];
        ans[j] %= 2;     //%2是对于该题的特殊
        i--, j--;
    }*/
}

int main() {
    int i, j, a, b, ans;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (i = 0; i < n; i++) scanf("%d", &ss[i]);
        for (i = 0; i < n; i++) scanf("%d", &se[i]);
        memset(matrix, 0, sizeof(matrix));
        while (scanf("%d%d", &a, &b) != EOF) {
            if (a == 0 && b == 0) break;
            matrix[b - 1][a - 1] = 1;
        }
        for (i = 0; i < n; i++) {
            matrix[i][i] = 1;
            matrix[i][n] = (se[i] - ss[i] + 2) % 2;
        }
        ans = gause();
        if (ans == -1) printf("Oh,it's impossible~!!\n");
        else printf("%d\n", ans);
    }
    return 0;
}
