#include <bits/stdc++.h>
using namespace std;

int a[105][105];
int d[4][2] = {
    {0, 1}, {1, 0}, {0, -1}, {-1, 0}
};

int main() {
    int n;
    cin >> n;
    int x = 0, y = 0, p = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) a[i][j] = -1;
    for (int i = 1; i <= n * n; i++) {
        a[x][y] = i;
        int u = x + d[p][0], v = y + d[p][1];
        if (u < 0 || u >= n || v < 0 || v >= n || a[u][v] != -1) p = (p + 1) % 4;
        x = x + d[p][0], y = y + d[p][1];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << a[i][j] << ' ';
        cout << '\n';
    }
    return 0;
}