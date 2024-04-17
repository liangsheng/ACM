// https://blog.csdn.net/weixin_43960287/article/details/108246164
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    // 这两句是为了让 cin 更快
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m, e = 1, x, y, z;
	cin >> n >> m;

    // 使得 e >= n + 2
	for (e = 1; e < n + 2; e <<= 1);
    
    vector<LL> a(2 * e);
    for (int i = 1; i <= n; i++) cin >> a[i + e];
    for (int i = (n + e) >> 1; i > 0; i--) a[i] = a[i << 1] + a[i << 1 | 1];

    auto add = [&](int p, int x) {
        for (int i = p + e; i > 0; i >>= 1) a[i] += x;
    };

    auto query = [&](int l, int r) {
        LL ans = 0;
        for (l += e - 1, r += e + 1; l ^ r ^ 1; l >>= 1, r >>= 1) {
            if (~l & 1) ans += a[l ^ 1];
            if (r & 1) ans += a[r ^ 1];
        }
        return ans;
    };

    while (m--) {
        cin >> x >> y >> z;
        if (x == 1) add(y, z);
        else cout << query(y, z) << '\n';
    }

    return 0;
}