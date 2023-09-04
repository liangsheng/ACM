#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T, n, m;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        vector<string> g(n);
        char s[2] = {'x', 'o'};
        for (int i = 0; i < n - 1; i += 2) {
            for (int j = 0, f = 0; j < m; j += 4, f ^= 1) {
                int l = j, r = min(m, l + 4);
                for (int k = l; k < r; k++) g[i].push_back(s[f]), g[i + 1].push_back(s[f ^ 1]);
            }
        }
        if (n % 2) {
            for (int j = 0, f = 0; j < m; j++, f ^= 1) g[n - 1].push_back(s[f]); 
        }
        for (int i = 0; i < n; i++) cout << g[i] << '\n';
        // int x = 0, o = 0;
        // for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        //     if (g[i][j] == 'x') x++;
        //     else o++;
        // }
        // cout << x << ' ' << o << '\n';
    }
    return 0;
}