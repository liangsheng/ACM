#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++) cin >> a[i].first, a[i].second = i;
        sort(a.begin(), a.end());
        int p, ans;
        for (int i = 0; i < n; i++) if (a[i].second == 0) {
            p = i, ans = a[i].first;
            break;
        }
        for (int i = p + 1; i < n; i++) {
            if (a[i].first > ans) ans = (ans + a[i].first + 1) / 2;
        }
        cout << ans << '\n';
    }
    return 0;
}