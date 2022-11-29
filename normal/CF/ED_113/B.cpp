#include <bits/stdc++.h>
using namespace std;

const int N = 55;

int T, n;
string s;
int g[N][N];

bool gao() {
    memset(g, -1, sizeof(g));
    for (int i = 0; i < n; i++) if (s[i] == '1') {
        for (int j = 0; j < n; j++) {
            if (j != i) g[i][j] = -1, g[j][i] = -1;
        }
    }
    vector<int> q;
    for (int i = 0; i < n; i++) if (s[i] == '2') q.push_back(i);
    int m = q.size();
    if (m == 0) return 1;
    if (m == 1 || m == 2) return 0;
    for (int i = 0; i < m; i++) {
        int x = q[i], y = q[(i + 1) % m];
        g[x][y] = 1, g[y][x] = 0;
    }
    return 1;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        cin >> s;
        bool ans = gao();
        if (!ans) cout << "NO" << '\n';
        else {
            cout << "YES" << '\n';
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == j) cout << "X";
                    else if (g[i][j] == -1) cout << "=";
                    else cout << (g[i][j] ? "+" : "-");
                }
                cout << '\n';
            }
        }
    }
    return 0;
}