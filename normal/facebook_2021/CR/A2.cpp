#include <bits/stdc++.h>
using namespace std;

const int N = 26;

int T, n, m;
string s, a;
int g[N][N];

int gao() {
    for (int k = 0; k < N; k++) for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
        if (k == i || k == j || i == j) continue;
        if (g[i][k] == -1 || g[k][j] == -1) continue;
        int tmp = g[i][k] + g[k][j];
        if (g[i][j] == -1 || g[i][j] > tmp) g[i][j] = tmp;
    }
    int ans = -1;
    for (int k = 0; k < 26; k++) {
        int tmp = 0;
        for (int i = 0; i < n; i++) {
            if (g[s[i] - 'A'][k] == -1) {
                tmp = -1;
                break;
            }
            tmp += g[s[i] - 'A'][k];
        }
        if (tmp != -1) {
            if (ans == -1 || ans > tmp) ans = tmp;
        }
    }
    return ans;
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int cas = 0;
    cin >> T;
    while (T--) {
        cin >> s;
        n = s.size();

        memset(g, -1, sizeof(g));
        for (int i = 0; i < N; i++) g[i][i] = 0;
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> a;
            g[a[0] - 'A'][a[1] - 'A'] = 1;
        }
        int d = gao();
        cout << "Case #" << ++cas << ": " << d << '\n';
    }
    return 0;
}