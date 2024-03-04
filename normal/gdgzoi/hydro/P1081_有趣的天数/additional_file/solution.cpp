#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    // 下面 2 句话是为了让 cin 更快，不理解可以先不写
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    vector<LL> b(n + 1, 0);
    for (int i = 1; i <= n; i++) b[i] = b[i - 1] + a[i - 1];

    auto ok = [&](LL mid) {
        int id = upper_bound(a.begin(), a.end(), mid) - a.begin();
        LL tmp = b[id] + mid * (n - id);
        // printf("tmp= %d\n", tmp);
        return tmp >= mid * t;
    };

    LL l = 1, r = b[n] / t, mid;
    while (l != r) {
        mid = (l + r) / 2 + 1;  // 求最大值这里要 +1
        // printf("l= %d, r= %d, mid= %d, ok= %d\n", l, r, mid, ok(mid));
        if (ok(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << '\n';
    return 0;
}