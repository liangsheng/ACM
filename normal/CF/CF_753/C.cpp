#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<int> a(n, 0);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        int ans = a[0];
        for (int i = 1; i < n; i++) ans = max(ans, a[i] - a[i - 1]);
        cout << ans << '\n';
    }
    return 0;
}