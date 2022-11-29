#include <bits/stdc++.h>
using namespace std;

const int N = 20;

int n, ans;
int a[N][N], b[N];

void dfs(int p) {
    if (p == 2 * n) {
        int tmp = 0;
        for (int i = 1; i <= 2 * n; i += 2) tmp ^= a[b[i]][b[i + 1]];
        ans = max(ans, tmp);
        return ;
    }
    for (int i = p; i <= 2 * n; i++) {
        swap(b[p], b[i]);
        dfs(p + 2);
        swap(b[p], b[i]);
    }
}

int main() {
    while (~scanf("%d", &n)) {
        for (int i = 1; i <= 2 * n - 1; i++) {
            for (int j = i + 1; j <= 2 * n; j++) scanf("%d", &a[i][j]), a[j][i] = a[i][j];
        }
        for (int i = 1; i <= 2 * n; i++) b[i] = i;
        ans = 0;
        dfs(2);
        cout << ans << '\n';
    }
    return 0;
}