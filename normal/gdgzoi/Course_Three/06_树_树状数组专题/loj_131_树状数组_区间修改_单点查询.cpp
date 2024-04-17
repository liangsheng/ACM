#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

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

    // O(n) 建树
    // https://oiwiki.com/ds/fenwick/
    Fenwick(vector<LL>& A) {
        n = A.size();
        for (lgn = 0; (1 << lgn) <= n; lgn++);
        a.resize(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            a[i] += A[i - 1];
            int j = i + (i & -i);
            if (j <= n) a[j] += a[i];
        }
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
};

int main() {
    // 这两句是为了让 cin 更快
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m, c, l, r, v;
	cin >> n >> m;

    vector<int> A(n);
    for (int& x: A) cin >> x;

    Fenwick<LL> a(n + 1);
    while (m--) {
        cin >> c;
        if (c == 1) {
            cin >> l >> r >> v;
            a.add(l, v);
            a.add(r + 1, -v);
        } else {
            cin >> l;
            cout << a.get(l) + A[l - 1] << '\n';
        }
    }

    return 0;
}