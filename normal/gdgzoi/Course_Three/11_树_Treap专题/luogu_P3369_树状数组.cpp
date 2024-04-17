#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct Fenwick {
	int n, lgn;
	vector<T> a;
	
	Fenwick(int n) : n(n) {
        // 使得 2^lgn > n
        // 比如 n = 5, lgn = 8; n = 8, lng = 16
		for (lgn = 0; (1 << lgn) <= n; lgn++);  // 2^lgn > n

        // 数组从 1 到 n, [1..n]
        // 相当于 a = vector<int>(n + 1, 0)
		a.resize(n + 1, 0);
	}
	
	void add(int p, T v) {
		for (; p <= n; p += p & -p) a[p] += v;
	}
	
	T get(int p) {
		T ans = 0;
		for (; p > 0; p -= p & -p) ans += a[p];
		return ans;
	}
	
	T get(int l, int r) {
		return get(r) - get(l - 1);
	}

	// 请重点理解这个函数
    // 查询从小到大排序后, 排名第 k 的数,
    int kth(T k) {
        int p = 0;
        for (int i = lgn - 1; i >= 0; i--) {
            p += 1 << i;
            if (p > n || a[p] >= k) p -= 1 << i;
            else k -= a[p];
        }
        return p + 1;
    }

    // 查询 x 的排名
    T rnk(int x) {
		return get(x - 1) + 1;
    }

	// 比 x 小的数里面最大的数
	int pre(int x) {
		return kth(get(x - 1));
	}

	// 比 x 大的数里面最小的数
	int suf(int x) {
		return kth(get(x) + 1);
	}
};

int main() {
    // 这两句是为了让 cin 更快
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	vector<int> cmd(n), x(n), c;
	for (int i = 0; i < n; i++) {
		cin >> cmd[i] >> x[i];
		// cmd[i] = 4 时, 是问排名为 x[i] 的数, 不需要离散化
		if (cmd[i] != 4) c.push_back(x[i]);
	}

    // 离散化三板斧, sort, erase/unique, lower_bound
	sort(c.begin(), c.end());
	c.erase(unique(c.begin(), c.end()), c.end());
	int e = c.size();
	for (int i = 0; i < n; i++) if (cmd[i] != 4) {  // cmd[i] = 4 时, 是问排名, 不需要离散化
        // x[i] 从 1 开始编号
		x[i] = lower_bound(c.begin(), c.end(), x[i]) - c.begin() + 1;
	}
	
	Fenwick<int> a(e + 1);
	for (int i = 0; i < n; i++) {
		if (cmd[i] == 1) a.add(x[i], 1);                           // 插入 x[i]
        else if (cmd[i] == 2) a.add(x[i], -1);                     // 删除 x[i]
        else if (cmd[i] == 3) cout << a.rnk(x[i]) << '\n';         // x[i] 的排名
        else if (cmd[i] == 4) cout << c[a.kth(x[i]) - 1] << '\n';  // 排名为 x[i] 的数
        else if (cmd[i] == 5) cout << c[a.pre(x[i]) - 1] << '\n';  // 比 x[i] 小的数中最大的
        else if (cmd[i] == 6) cout << c[a.suf(x[i]) - 1] << '\n';  // 比 x[i] 大的数中最小的
	}
	return 0;
}