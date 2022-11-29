#include <bits/stdc++.h>
using namespace std;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int n, m, L, s, t, x;
    while (cin >> n >> m) {
        vector<vector<int>> a(n, vector<int>());
        for (int i = 0; i < n; i++) {
            cin >> L;
            for (int j = 0; j < L; j++) {
                cin >> x;
                a[i].push_back(x);
            }
        }
        while (m--) {
            cin >> s >> t;
            cout << a[s - 1][t - 1] << '\n';
        }
    }
    return 0;
}