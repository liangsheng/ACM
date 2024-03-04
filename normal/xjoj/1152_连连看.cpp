#include <bits/stdc++.h>
#define X first              // 代码里可以用 X 代替 first
#define Y second             // 代码里可以用 Y 代替 second
using namespace std;
typedef long long LL;
typedef pair<pair<int, int>, int> pii;

int main() {
    // 下面 2 是为了让 cin, cout 更快, 不理解可以先不写
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    int n;
    while (cin >> n) {
        pii t;
        set<pii> a, b;
        for (int i = 0; i < n; i++) {
            cin >> t.X.X >> t.X.Y;
            t.Y = i + 1;
            a.insert(t);
            swap(t.X.X, t.X.Y);
            b.insert(t);
        }

        LL ans = 0;
        vector<pair<int, int>> res;
        for (int i = 1; i <= n / 2; i++) {
            pii lx = *a.begin(), rx = *a.rbegin();
            pii ly = *b.begin(), ry = *b.rbegin();
            int d1 = rx.X.X - lx.X.X , d2 = ry.X.X - ly.X.X;
            if (d1 >= d2) {
                ans += d1;
                res.push_back({lx.Y, rx.Y});
                a.erase(lx), a.erase(rx);
                swap(lx.X.X, lx.X.Y), b.erase(lx);
                swap(rx.X.X, rx.X.Y), b.erase(rx);
            } else {
                ans += d2;
                res.push_back({ly.Y, ry.Y});
                b.erase(ly), b.erase(ry);
                swap(ly.X.X, ly.X.Y), a.erase(ly);
                swap(ry.X.X, ry.X.Y), a.erase(ry);                
            }
        }
        // cout << ans << ' ' << res.size() << '\n';
        cout << res.size() << '\n';
        for (auto it : res) cout << it.X << ' ' << it.Y << '\n';
    }
    return 0;
}