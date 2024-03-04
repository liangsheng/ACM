#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    int n, m, k;
    while (cin >> n >> m >> k) {
        vector<pii> a(n);
        for (auto& [x, y]: a) {
            cin >> x >> y;
            y = min(y, m);
        }
        
        LL ans = 0, l = 0, r = 0;
        sort(a.begin(), a.end());
        vector<pii> q(n + 5);
        q[r++] = {1 - k, m};
        for (auto [w, c] : a) {
            int cnt = 0;
            // cout << "w= " << w << ", c= " << c << '\n';
            while (cnt < c && l != r && q[l].X + k <= w) {
                // cout << "cnt= " << cnt << ", l= " << l << ", r= " << r << '\n';
                if (q[l].Y <= c - cnt) {
                    cnt += q[l].Y;
                    ans += q[l++].Y;
                } else {
                    ans += c - cnt, q[l].Y -= c - cnt;
                    cnt = c;
                    break;
                }
            }
            if (cnt != 0) q[r++] = {w, cnt};
        }
        cout << ans << '\n';
    }
    return 0;
}