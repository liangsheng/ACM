#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 300005;

int n, w;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    while (cin >> n >> w) {
        vector<pair<int, int> > a(n);
        for (auto& [x, y]: a) cin >> x >> y;
        sort(a.begin(), a.end(), [&](const pair<int, int>& x, const pair<int, int>& y) {
            return x.first > y.first;
        });
        LL ans = 0, now = 0;
        for (int i = 0; i < n; i++) {
            if (now + a[i].second <= w) {
                now += a[i].second;
                ans += (LL) a[i].first * a[i].second;
            } else {
                ans += (LL) a[i].first * (w - now);
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}