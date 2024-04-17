#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m, q, h, w, p;
    cin >> n >> m >> q;
    vector<vector<LL>> f(n + 1, vector<LL>(m + 1, 0));
    for (int i = 0; i < q; i++) {
        cin >> h >> w >> p;
        f[h][w] = p;
    }
    
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
        // 水平切一刀
        for (int k = 1; k < i; k++) f[i][j] = max(f[i][j], f[k][j] + f[i - k][j]);
        
        // 垂直切一刀
        for (int k = 1; k < j; k++) f[i][j] = max(f[i][j], f[i][k] + f[i][j - k]);
    }
    cout << f[n][m] << '\n';
    return 0;
}