// https://blog.csdn.net/weixin_43960287/article/details/108246164
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

template <typename Info>
struct ZKW {
	int n, e;
	vector<Info> info;
	
	ZKW(int n_, vector<Info>& a) : n(n_) {
        // 使得 e >= n + 2
		for (e = 1; e < n + 2; e <<= 1);

        // 原数组存放在 a[e + 1] 到 a[e + n]
		info.assign(2 * e, Info());
        for (int i = 1; i <= n; i++) info[e + i] = a[i];
        for (int i = (e + n) >> 1; i > 0; i--) {
            info[i] = info[i << 1] + info[i << 1 | 1];
        }
	}

    // 单点修改
    void updatePoint(int p, Info x) {
        info[p + e] = x;
        for (int i = (p + e) >> 1; i > 0; i >>= 1) {
            info[i] = info[i << 1] + info[i << 1 | 1];
        };
    }

    // 区间查询
    Info queryRange(int l, int r) {
        Info ans = Info();
        for (l += e - 1, r += e + 1; l ^ r ^ 1; l >>= 1, r >>= 1) {
            if (~l & 1) ans = ans + info[l ^ 1];
            if (r & 1) ans = ans + info[r ^ 1];
        }
        return ans;
    }
};

struct Info {
    LL sum = 0;
    Info() { sum = 0; }
    Info(LL sum_): sum(sum_) {}
};

Info operator +(const Info& a, const Info& b) {
    return Info(a.sum + b.sum);
}

int main() {
    // 这两句是为了让 cin 更快
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m, x, y, z;
	cin >> n >> m;

    vector<Info> a(n + 1, Info(0));
    for (int i = 1; i <= n; i++) cin >> a[i].sum;

    ZKW<Info> b(n, a);

    while (m--) {
        cin >> x >> y >> z;
        if (x == 1) a[y].sum += z, b.updatePoint(y, a[y]);
        else cout << b.queryRange(y, z).sum << '\n';
    }

    return 0;
}