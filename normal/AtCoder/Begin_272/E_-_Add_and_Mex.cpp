#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int n, m, x, y;
    while (cin >> n >> m) {
        vector<vector<int>> b(m + 1, vector<int>());
        for (int i = 1; i <= n; i++) {
            cin >> x;
            y = x;
            if (x < 0) {
                x += (-x) / i * i;
                while (x < 0) x += i;
            }
            for (; x <= n && (x - y) / i <= m; x += i) if (x > y) {
                b[(x - y) / i].push_back(x);
            }
        }
        for (int i = 1; i <= m; i++) {
            sort(b[i].begin(), b[i].end());
            int now = 0;
            for (int j : b[i]) if (j == now) now++;
            cout << now << '\n';
        }
    }
    return 0;
}