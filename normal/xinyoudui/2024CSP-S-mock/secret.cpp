// https://contest.xinyoudui.com/contest/279/problem/1441
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    freopen("secret.in", "r", stdin);
    freopen("secret.out", "w", stdout);

    int n, q, x;
    string c;
    set<int> s;
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> x, s.insert(x);
    while (q--) {
        cin >> c >> x;
        if (c == "+") s.insert(x);
        else if (c == "-") s.erase(x);
        else {
            int l = *s.begin(), r = *s.rbegin();
            // cout << "l= " << l << ", x= " << x << ", r= " << r << '\n';
            double ans = 0.0;
            if (x == l || x == r) ans = (r - l) / 2.0;
            else {
                auto p = s.find(x);
                int lp = *prev(p), rp = *next(p);
                double tl = max((x - l) / 2.0, (x - lp) / 2.0 + (r - x) / 2.0);
                double tr = max((r - x) / 2.0, (rp - x) / 2.0 + (x - l) / 2.0);
                // cout << "tl= " << tl << ", tr= " << tr << '\n';
                ans = min(tl, tr);
            } 
            cout << fixed << setprecision(2) << ans << '\n';
        }
    }
    return 0;
}