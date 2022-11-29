#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, x, y;
    while (cin >> n >> m) {
        vector<vector<int>> a(n + 1, vector<int>());
        for (int i = 1; i <= m; i++) {
            cin >> x >> y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        for (int i = 1; i <= n; i++) {
            sort(a[i].begin(), a[i].end());
            cout << a[i].size();
            for (int j = 0; j < a[i].size(); j++) cout << ' ' << a[i][j];
            cout << '\n';
        }
    }
    return 0;
}