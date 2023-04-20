#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n, m, x;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        vector<int> a(n, 0);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) {
            cin >> x;
            int p = 0;
            for (int j = 1; j < n; j++) if (a[j] < a[p]) p = j;
            a[p] = x;
        }
        sort(a.begin(), a.end(), greater<int>());
        LL ans = 0;
        for (int i = 0; i < n; i++) ans += a[i];
        cout << ans << '\n';
    }
    return 0;
}