#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T, n;
    cin >> T;
    while (T--) {
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        LL ans = 0, p = 1;
        for (int i = 0; i < n; i++) {
            if (a[i] == p) {
                while (i + 1 < n && a[i + 1] == a[i]) i++;
            } else {
                ans += a[i] - p;
                a[i] = p;
            }
            p++;
        }
        cout << ans << '\n';
    }
    return 0;
}