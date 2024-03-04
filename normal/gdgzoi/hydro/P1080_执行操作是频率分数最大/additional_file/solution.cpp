#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    // 这两句话是为了让 cin 和 cout 操作更快
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    LL m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    // 排序后计算前缀和
    sort(a.begin(), a.end());
    vector<LL> f(n + 2, 0);
    for (int i = 1; i <= n; i++) f[i] = f[i - 1] + a[i - 1];

    auto gao = [&](int d) {
        if (d == 1) return true;
        for (int l = 1, r = l + d - 1; r <= n; l++, r++) {
            // 把 a[l] 到 a[r] 都变成中位数 a[p]
            int p = (l + r) / 2;
            LL cl = p - l, cr = r - p, t = a[p - 1];
            LL sl = f[p - 1] - f[l - 1], sr = f[r] - f[p];
            LL tmp = cl * t - sl + sr - cr * t;
            if (tmp <= m) return true;
        }
        return false;
    };
    int l = 1, r = n, mid;
    while (l != r) {
        mid = (l + r) / 2 + 1;  // 注意: 二分求最大, 这里记得 +1, 不然会死循环
        if (gao(mid)) l = mid;  // mid 符合要求, l = mid
        else r = mid - 1;       // mid 不符合要求, r = mid - 1
    }
    cout << l << '\n';
    return 0;
}