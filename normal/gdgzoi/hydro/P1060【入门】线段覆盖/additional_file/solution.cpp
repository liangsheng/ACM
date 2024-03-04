#include <bits/stdc++.h>
#define X first              // 代码里可以用 X 代替 first
#define Y second             // 代码里可以用 Y 代替 second
using namespace std;
typedef long long LL;        // 代码里可以用 LL 代替 long long
typedef pair<LL, LL> pii;    // 代码里可以用 pii 代替 pair<long long, long long>

int main() {
    // 下面 2 是为了让 cin, cout 更快, 不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    LL m;
    while (cin >> m >> n) {
        vector<pii> a(n);
        for (int i = 0; i < n; i++) cin >> a[i].X >> a[i].Y;

        sort(a.begin(), a.end(), [&](const pii& u, const pii& v) {
            if (u.X != v.X) return u.X < v.X;
            return u.Y > v.Y;
        });

        int cnt = 0;
        LL now = 1;
        for (int i = 0; i < n; i++) {
            cnt++;
            LL tmp = a[i].Y;
            while (i + 1 < n && a[i + 1].X <= now) tmp = max(tmp, a[++i].Y);
            now = tmp + 1;
            if (now > m) break;
        }
        cout << cnt << '\n';
    }
    return 0;
}