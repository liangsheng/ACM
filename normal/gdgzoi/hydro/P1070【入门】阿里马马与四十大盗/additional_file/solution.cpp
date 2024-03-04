#include <bits/stdc++.h>
using namespace std;
typedef long long LL;  // 表示以后需要写 long long 的地方可以用 LL 代替

const LL INF = numeric_limits<LL>::max();  // 表示 long long 的最大值

int main() {
    // 下面 2 句是为了让 cin, cout 更快, 不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    while (cin >> n >> m) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<LL> b(n);
        b[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; i--) b[i] = b[i + 1] + a[i];
        if (b[0] < m) {
            cout << n - 1 << '\n';
            continue;
        }
        
        bool ok = true;
        LL now = m, ans = 0, res = INF;
        for (int i = 0; i < n; i++) {
            if (a[i] > 0) {
                LL sum = a[i];
                while (i + 1 < n && a[i + 1] > 0) sum += a[++i];
                if (sum >= m) {
                    ok = false;
                    break;
                }
                if (sum < now) now -= sum;
                else ans += m - now, now = m - sum;

            } else if (i + 1 < n && b[i + 1] < m) {
                res = min(res, ans + m - now);
            }
        }
        if (!ok) cout << "NO" << '\n';
        else cout << min(res, ans) + n - 1 << '\n';
    }
    return 0;
}