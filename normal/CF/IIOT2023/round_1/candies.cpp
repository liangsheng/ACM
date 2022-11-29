#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int n;
    while (cin >> n) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        LL ans = 1, now = 1;
        for (int i = 1; i < n; i++) {
            if (a[i] != a[i - 1]) now++;
            ans += now;
        }
        cout << ans << '\n';
    }
    return 0;
}