#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, x, y, p, q, op, z;
    cin >> n >> m >> x >> y;
    x--, y--;
    vector<string> g(n);
    for (auto& s : g) cin >> s;
    vector<vector<int>> a(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) a[i][j] = i * m + j;
    cin >> p >> q;
    while (q--) {
        cin >> op >> z;
        z--;
        if (op == 1) {
            int t = a[z][m - 1];
            for (int j = m - 1; j >= 1; j--) a[z][j] = a[z][j - 1];
            a[z][0] = t;
        } else {
            int t = a[n - 1][z];
            for (int i = n - 1; i >= 1; i--) a[i][z] = a[i - 1][z];
            a[0][z] = t;            
        }
    }
    vector<int> f(n * m);
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) f[i * m + j] = a[i][j];
    int ans = x * m + y;
    for (int i = 1; i <= p; i++) ans = f[ans];
    x = ans / m, y = ans % m;
    cout << g[x][y] << '\n';
    return 0;
}