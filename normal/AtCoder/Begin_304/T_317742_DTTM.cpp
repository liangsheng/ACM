// https://www.luogu.com.cn/problem/T317742?contestId=102351
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long LL;

const int MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x, y;
    while (cin >> n) {
        vector<pii> a(n);
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            a[i].first = x, a[i].second = i + 1;
        }
        if (n & 1) {
            cout << -1 << '\n';
            continue;
        }
        sort(a.begin(), a.end());
        int ans = 0;
        for (int i = 0; i < n; i += 2) ans += a[i + 1].first - a[i].first;
        cout << ans << '\n';
        for (int i = 0; i < n; i += 2) cout << a[i].second << ' ' << a[i + 1].second << '\n';
    }
    return 0;
}