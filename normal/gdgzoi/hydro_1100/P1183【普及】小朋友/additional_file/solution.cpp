#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int INF = numeric_limits<int>::max() / 2;
const int M = 12, D = 11, MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    // freopen("xpy.in", "r", stdin);
    // freopen("xpy.out", "w", stdout);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i], a[i] -= 10;
    
    int ans = 0;
    vector<bool> ok(M, false), f(D * 100 + D + 1, false);
    function<void(int)> dfs = [&](int p) {
        if (p == n) {
            ans++;
            return ;
        }
        if (!ok[a[p]]) {
            ok[a[p]] = true;
            dfs(p + 1);
            ok[a[p]] = false;
        }
        if (p + 1 < n) {
            int d = a[p] * 100 + a[p + 1];
            if (!ok[d]) {
                ok[d] = true;
                dfs(p + 2);
                ok[d] = false;
            }
        }
    };
    dfs(0);
    cout << ans << '\n';
    return 0;
}