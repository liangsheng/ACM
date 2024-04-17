// https://blog.csdn.net/weixin_43960287/article/details/108246164
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

template <typename T>
struct ZKW {
	int n, e;
	vector<T> info;
	
	ZKW(int n_, vector<T>& a) : n(n_) {
        // 使得 e >= n + 2
		for (e = 1; e < n + 2; e <<= 1);

        // 原数组存放在 a[e + 1] 到 a[e + n]
		info.assign(2 * e, 0);
        for (int i = 1; i <= n; i++) info[e + i] = a[i];
        for (int i = (e + n) >> 1; i > 0; i--) {
            info[i] = info[i << 1] + info[i << 1 | 1];
        }
	}

    // 单点修改
    void updatePoint(int p, T x) {
        for (int i = p + e; i > 0; i >>= 1) info[i] += x;
    }

    // 区间查询
    T queryRange(int l, int r) {
        T ans = 0;
        for (l += e - 1, r += e + 1; l ^ r ^ 1; l >>= 1, r >>= 1) {
            if (~l & 1) ans += info[l ^ 1];
            if (r & 1) ans += info[r ^ 1];
        }
        return ans;
    }
};

int main() {
    // 这两句是为了让 cin 更快
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m, x, y, z;
	cin >> n >> m;

    vector<LL> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    ZKW<LL> b(n, a);

    while (m--) {
        cin >> x >> y >> z;
        if (x == 1) b.updatePoint(y, z);
        else cout << b.queryRange(y, z) << '\n';
    }

    return 0;
}