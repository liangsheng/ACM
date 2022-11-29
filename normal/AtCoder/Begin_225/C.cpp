#include <bits/stdc++.h>
using namespace std;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int n, m;
    while (cin >> n >> m) {
        vector<vector<int> > g(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> g[i][j];
        bool flag = 1;
        for (int i = 1; i < n; i++) {
            if (!flag) break;
            for (int j = 0; j < m; j++) if (g[i][j] != g[i - 1][j] + 7) {
                flag = 0;
                break;
            }
        } 
        if (!flag) {
            cout << "No" << '\n';
            continue;
        }
        flag = 1;
        for (int j = 1; j < m; j++) if ((g[0][j] - 1) % 7 != (g[0][j - 1] - 1) % 7+ 1) {
            flag = 0;
            break;
        }
        if (flag) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
    return 0;
}

// 2 2
// 7 8
// 14 15
// No