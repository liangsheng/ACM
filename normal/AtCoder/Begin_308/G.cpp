// and问题
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int D = 57;

int n, k;
vector<LL> a, p;
set<LL> ans;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while (cin >> n >> k) {
        a = vector<LL>(n + 1, 0);
        p = vector<LL>(n + 1, 0);
        for (int i = 1; i <= n; i++) cin >> a[i], p[i] = p[i - 1] + a[i];
        ans.clear();
        for (int i = 1; i <= 7; i++) for (int j = 1; i + j <= 8; j++) for (int h = 1; h + i + j <= 9; h++) {
            LL tmp = p[i];
            tmp &= p[i + j] - p[i];
            tmp &= p[i + j + h] - p[i + j];
            tmp &= p[n] - p[i + j + h];
            if (!ans.count(tmp)) {
                ans.insert(tmp);
                cout << tmp << '\n';
                cout << i << ' ' << j << ' ' << h << ' ' << n - i - j - h << '\n';
            }
        }
        // cout << ans.size() << '\n';
        // for (LL it : ans) cout << it << '\n';
    }
    return 0;
}