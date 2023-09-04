#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    while (cin >> n >> k) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<LL> b(n);
        b[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; i--) b[i] = b[i + 1] + a[i];
        sort(b.begin() + 1, b.end(), greater<LL>());
        LL ans = 0;
        for (int i = 0; i < k; i++) ans += b[i];
        cout << ans << '\n';
    }
    return 0;
}
 