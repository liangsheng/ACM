#include <bits/stdc++.h>
using namespace std;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int n, m;
    while (cin >> n >> m) {
        vector<string> a(n), b(m);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];
        vector<bool> ans(n, 1);
        int p = 1;
        for (int i = 1; i < m; i++) {
            while (a[p] != b[i]) ans[p++] = 0;
            ans[p++] = 1;
            // cout << "i= " << i << ' ' << p << '\n';
        }
        for (int i = 0; i < n; i++) cout << (ans[i] ? "Yes" : "No") << '\n';
    }
    return 0;
}