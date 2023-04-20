#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n, m;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        vector<pair<int, int>> a(n);

        int L = 1, R = 50;
        for (int i = 0; i < n; i++) {
            cin >> a[i].first >> a[i].second;
            if (m >= a[i].first && m <= a[i].second) {
                L = max(L, a[i].first);
                R = min(R, a[i].second);
            }
        }
        cout << (L == R ? "YES" : "NO") << '\n';
    }
    return 0;
}