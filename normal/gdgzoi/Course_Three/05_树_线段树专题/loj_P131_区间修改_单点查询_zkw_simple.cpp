// https://blog.csdn.net/weixin_43960287/article/details/108246164
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
    // 这两句是为了让 cin 更快
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m, e = 1;
	cin >> n >> m;

    // 使得 e >= n + 2
	for (e = 1; e < n + 2; e <<= 1);
    
    vector<LL> a(2 * e);
    for (int i = 1; i <= n; i++) cin >> a[i + e];
    // 维护的是 lazy 标记, 原数组就不要加上去了
    // for (int i = (n + e) >> 1; i > 0; i--) a[i] = a[i << 1] + a[i << 1 | 1];

    auto add = [&](int l, int r, int d) {
        for (l += e - 1, r += e + 1; l ^ r ^ 1; l >>= 1, r >>= 1) {
            if (~l & 1) a[l ^ 1] += d;
            if (r & 1) a[r ^ 1] += d;            
        }
    };

    auto query = [&](int p) {
        LL ans = 0;
        for (int i = p + e; i > 0; i >>= 1) ans += a[i];
        return ans;
    };

    int c, l, r, d, p;
    while (m--) {
        cin >> c;
        if (c == 1) {
            cin >> l >> r >> d;
            add(l, r, d);
        } else {
            cin >> p;
            cout << query(p) << '\n';
        }
    }

    return 0;
}