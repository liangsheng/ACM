#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

template <typename T>  // 使用 template 模板, 用法见定义
struct Fenwick {
	int n;
	vector<T> a;
	
	Fenwick(int N) {
        n = N;
        // 注意: 树状数组都是从 1 开始编号 a[1..n], 不要从 0 开始
        // 相当于 a = vector<int>(n + 1, 0)
		a.resize(n + 1, 0);
	}
	
    // 更新操作, 不断 p += lowbit(p)
	void add(int p, T v) {
		for (; p <= n; p += p & -p) a[p] += v;
	}
	
    // 求前缀和: sum(a[1..p]), 不断 p -= lowbit(p)
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
	int n;
	cin >> n;

    vector<int> a(n), c(n);
    for (int i = 0; i < n; i++) cin >> a[i], c[i] = a[i];

    // 离散化三连
    sort(c.begin(), c.end());                      // 第 1 步: 排序
    c.erase(unique(c.begin(), c.end()), c.end());  // 第 2 步: 去重
    int e = c.size();
    for (int i = 0; i < n; i++) {
        // 第 3 步: 给数组 a 里的数重新赋值到 1..e
        // 注意: 一定是 1..e, 从 1 开始, 因为后面要用树状数组
        a[i] = lower_bound(c.begin(), c.end(), a[i]) - c.begin() + 1;
    }

    LL ans = 0;
    Fenwick<int> b(e);
    for (int i = n - 1; i >= 0; i--) {
        ans += b.get(a[i] - 1);
        b.add(a[i], 1);
    }
    cout << ans << '\n';
    return 0;
}
