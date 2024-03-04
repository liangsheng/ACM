#include <bits/stdc++.h>
#define X first              // 代码里可以用 X 代替 first
#define Y second             // 代码里可以用 Y 代替 second
using namespace std;
typedef pair<int, int> pii;  // 代码里可以用 pii 代替 pair<int, int>
typedef long long LL;        // 代码里可以用 LL 代替 long long

int main() {
    // 下面 2 是为了让 cin, cout 更快, 不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n) {
        vector<pii> a(n);
        for (int i = 0; i < n; i++) cin >> a[i].X >> a[i].Y;

        sort(a.begin(), a.end(), [&](const pii& u, const pii& v) {
            return u.X * u.Y + v.X * (u.Y + v.Y) < v.X * v.Y + u.X * (v.Y + u.Y);
        });

        LL ans = 0, now = 0;
        for (int i = 0; i < n; i++) {
            now += a[i].Y;
            ans += a[i].X * now;
        }
        cout << ans << '\n';
    }
    return 0;
}