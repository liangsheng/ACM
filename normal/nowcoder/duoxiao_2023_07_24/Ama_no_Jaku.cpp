#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int INF = ~0U >> 2;

int work(vector<vector<int>> g, bool f) {
    int n = g.size(), m = n, ans = 0;
    if (f) {
        ans++;
        for (int j = 0; j < n; j++) g[0][j] ^= 1;
    } 
    for (int j = 0; j < n; j++) if (g[0][j] == 1) {
        ans++;
        for (int i = 0; i < n; i++) g[i][j] ^= 1;
    }
    for (int i = 1; i < n; i++) {
        int c = 0;
        for (int j = 0; j < n; j++) c += g[i][j];
        if (c == 0) continue;
        if (c == n) ans++;
        else return INF;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    string s;
    while (cin >> n) {
        vector<vector<int>> g(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            cin >> s;
            for (int j = 0; j < n; j++) g[i][j] = (s[j] == '1');
        }
        int a = work(g, 0);
        int b = work(g, 1);
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) g[i][j] ^= 1;
        int c = work(g, 0);
        int d = work(g, 1);
        int ans = min(min(a, b), min(c, d));
        if (ans == INF) ans = -1;
        cout << ans << '\n';
    }
    return 0;
}