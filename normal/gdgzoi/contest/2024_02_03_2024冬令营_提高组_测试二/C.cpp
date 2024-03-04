#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int n, m, p, q;
vector<vector<bool>> a;
map<vector<bool>, int> h;

vector<bool> rev(vector<bool>& a) {
    vector<bool> b = a;
    for (int i = 0; i < m; i++) b[i] = 1 - b[i];
    return b;
}

void solve() {
    if (p > 0 || q > 0) {
        bool ok = 0;
        vector<bool> ans;
        for (auto it : h) {
            vector<bool> x = it.first;
            vector<bool> y = rev(x);
            int cx = it.second, cy = (h.count(y) ? h[y] : 0);
            if (cx == p && cy == q) {
                if (!ok || x < ans) ok = 1, ans = x;
            } else if (cx == q && cy == p) {
                if (!ok || y < ans) ok = 1, ans = y;
            }
        }
        if (ok) {
            for (int i = 0; i < m; i++) cout << (ans[i] ? 'Y' : 'N');
            cout << '\n';
        } else {
            cout << -1 << '\n';
        }
        return ;
    }
    int c = 0;
    vector<bool> ans(m, 0);
    while (1) {
        vector<bool> res = rev(ans);
        if (!h.count(ans) && !h.count(res)) {
            for (int i = 0; i < m; i++) cout << (ans[i] ? 'Y' : 'N');
            cout << '\n';
            return ;
        }
        if (c == m) break;
        c = 0;
        int d = 1;
        for (int i = m - 1; i >= 0; i--) {
            int tol = ans[i] + d;
            ans[i] = tol % 2;
            d = tol / 2;
            c += ans[i];
        }
    }
    cout << -1 << '\n';
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    cin >> n >> m >> p >> q;
    string s;
    a = vector<vector<bool>>(n, vector<bool>(m, 0));
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) a[i][j] = (s[j] == 'Y');
        h[a[i]]++;
    }
    solve();
    return 0;
}

