#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

template <typename T>
struct Fenwick {
	int n;
	vector<T> a;
	
	Fenwick(int N) : n(N) {
        // 注意: 树状数组都是从 1 开始编号, 不要从 0 开始
        // 数组从 1 到 n, [1..n]
        // 相当于 a = vector<int>(n + 1, 0)
		a.resize(n + 1, 0);
	}
	
	void add(int p, T v) {
		for (; p <= n; p += p & -p) a[p] += v;
	}
	
    // 求前缀和: sum(a[1..p])
	T get(int p) {
		T ans = 0;
		for (; p > 0; p -= p & -p) ans += a[p];
		return ans;
	}
	
    // 求区间和: sum(a[1..r]) - sum(a[1..(l-1)])
	T get(int l, int r) {
		return get(r) - get(l - 1);
	}
};

int main() {
    // 这两句是为了让 cin 更快
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m, x, y, z;
	cin >> n >> m;

    // 404ms, 8.1M
	Fenwick<LL> a(n);
    for (int i = 1; i <= n; i++) {
        cin >> x;
        a.add(i, x);
    }

    while (m--) {
        cin >> x >> y >> z;
        if (x == 1) a.add(y, z);
        else cout << a.get(y, z) << '\n';
    }

    return 0;
}