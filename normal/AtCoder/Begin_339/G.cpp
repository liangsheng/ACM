#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

namespace SegTree {

	const int N = 200005;

	int e;
	int T[N], L[N * 40], R[N * 40];
	LL val[N * 40];

	void init() {
		e = 0;
		L[0] = 0, R[0] = 0, val[0] = 0;
	}
	
	/**
	 * 单点更新
	 */
	void update(int& cur, int k, int s, int t, int x, int w) {
		if (x < s || x > t) return ;
		
		cur = ++e;
		L[e] = L[k], R[e] = R[k], val[e] = val[k] + w;
		if (s == t) return ;
		
		int mid = (s + t) >> 1;
		update(L[e], L[k], s, mid, x, w);
		update(R[e], R[k], mid + 1, t, x, w);
	}

	/**
	 * 	区间查询
	 */ 
	LL query(int S, int E, int s, int t, int l, int r) {
		if (t < l || s > r) return 0;
		if (s >= l && t <= r) return val[E] - val[S];
		int mid = (s + t) >> 1;
		return query(L[S], L[E], s, mid, l, r) + query(R[S], R[E], mid + 1, t, l, r);
	}
}

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

	int n, q, e;
	cin >> n;
	vector<int> a(n), c(n);
	for (int i = 0; i < n; i++) cin >> a[i], c[i] = a[i];
    sort(c.begin(), c.end());
    c.erase(unique(c.begin(), c.end()), c.end());
    e = c.size();
	for (int i = 0; i < n; i++) {
		a[i] = lower_bound(c.begin(), c.end(), a[i]) - c.begin();
	}

	SegTree::init();
	for (int i = 1; i <= n; i++) {
		int x = a[i - 1] + 1, w = c[a[i - 1]];
		SegTree::update(SegTree::T[i], SegTree::T[i - 1], 1, e, x, w);
	}

	cin >> q;
	LL X, Y, Z, pre = 0;
	while (q--) {
		cin >> X >> Y >> Z;
		int L = X ^ pre;
		int R = Y ^ pre;
		int X = Z ^ pre;
		int id = upper_bound(c.begin(), c.end(), X) - c.begin();
		// printf("L= %d, R= %d, X= %d, id= %d\n", L, R, X, id);
		pre = SegTree::query(SegTree::T[L - 1], SegTree::T[R], 1, e, 1, id);
		cout << pre << '\n';
	}
	return 0;
}