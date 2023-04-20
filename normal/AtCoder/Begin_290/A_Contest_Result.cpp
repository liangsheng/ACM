#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    while (cin >> n >> m) {
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        int ans = 0;
        for (int i = 1; i <= m; i++) {
            int x;
            cin >> x;
            ans += a[x];
        }
        cout << ans << '\n';
    }
    return 0;
}