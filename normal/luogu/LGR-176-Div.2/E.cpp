#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

inline LL read() { 
    LL x=0,w=0; char ch=0; while(!isdigit(ch)) w|=ch=='-',ch=getchar();
    while(isdigit(ch)) x=x*10+ch-'0',ch=getchar(); return w?-x:x; 
}

/*
 * abc_339_G: https://atcoder.jp/contests/abc339/submissions/49962098
 */
namespace SegTree {

	const int N = 1000005;

	int e;
	int T[N], L[N * 40], R[N * 40];
	int val[N * 40];

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

	void update(int& k, int s, int t, int x, int w) {
		if (x < s || x > t) return ;
        if (k == 0) k = ++e;  // 动态开点
        // printf("k= %d, s= %d, t= %d, x= %d\n", k, s, t, x);
        val[k] += w;
        if (s == t) return ;
		int mid = (s + t) >> 1;
		update(L[k], s, mid, x, w);
		update(R[k], mid + 1, t, x, w);
	}

	/**
	 * 	区间查询
	 */ 
	int query(int S, int E, int U, int V, int s, int t, int id) {
		if (s == t) return s;
		int mid = (s + t) >> 1, num = val[L[E]] - val[L[S]] + val[L[V]] - val[L[U]];
        // printf("s= %d, t= %d, id= %d, num= %d\n", s, t, id, num);
        // printf("ss= %d, tt= %d, s= %d, %d, e= %d, %d, u= %d, %d, v= %d, %d, id= %d, num= %d\n", s, t, S, val[S], E, val[E], U, val[U], V, val[V], id, num);
        if (num >= id) return query(L[S], L[E], L[U], L[V], s, mid, id); 
		return query(R[S], R[E], R[U], R[V], mid + 1, t, id - num); 
	}
}

int main() {
    // srand(0);
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr); cout.tie(nullptr);
    int T, n, m, x, y;
    LL u;
    // cin >> T;
    T = read();
    while (T--) {
        // cin >> n >> m;
        n = read(), m = read();
        // n = 5, m = 5;
        // cout << n << ' ' << m << '\n';
        vector<LL> a;
        vector<int> p(n), h(n);
        LL maxi = 0;
        for (int i = 0; i < n; i++) {
            p[i] = (int) a.size();
            // cin >> h[i];
            h[i] = read();
            // h[i] = rand() % n + 1;
            // cout << h[i];
            for (int j = 0; j < h[i]; j++) {
                // cin >> u;
                u = read();
                // u = rand() % n + 1;
                // cout << ' ' << u;
                a.push_back(u);
                maxi = max(maxi, u);
            }
            // cout << '\n';
        }
        for (int i = 0; i < n; i++) sort(a.begin() + p[i], a.begin() + p[i] + h[i]);
        
        auto ok = [&](int x, int y, LL mid) {
            int id = (h[x] + h[y] + 1) / 2;
            int c = upper_bound(a.begin() + p[x], a.begin() + p[x] + h[x], mid) - a.begin() - p[x];
            int d = upper_bound(a.begin() + p[y], a.begin() + p[y] + h[y], mid) - a.begin() - p[y];
            return c + d >= id;
        };

        while (m--) {
            cin >> x >> y;
            LL l = 1, r = maxi;
            while (l != r) {
                LL mid = (l + r) / 2;
                if (ok(x - 1, y - 1, mid)) r = mid;
                else l = mid + 1;
            }
            // cout << l << '\n';
            printf("%lld\n", l);
        }


        // vector<LL> c = a;
        // sort(c.begin(), c.end());
        // c.erase(unique(c.begin(), c.end()), c.end());
        // int e = c.size(), tol = a.size();
        // for (int i = 0; i < tol; i++) {
        //     a[i] = lower_bound(c.begin(), c.end(), a[i]) - c.begin() + 1;
        // }
        // // cout << "e= " << e << ", tol= " << tol << '\n';
        // SegTree::init();
        // // for (int i = 1; i <= n; i++) {
        // //     SegTree::update(SegTree::T[i], SegTree::T[i - 1], 1, e, a[p[i - 1]], 1);
        // //     for (int j = p[i - 1] + 1; j < p[i - 1] + h[i - 1]; j++) {
        // //         SegTree::update(SegTree::T[i], 1, e, a[j], 1);
        // //     }
        // // }
        // for (int i = 1; i <= tol; i++) {
        //     SegTree::update(SegTree::T[i], SegTree::T[i - 1], 1, e, a[i - 1], 1);
        // }

        // while (m--) {
        //     cin >> x >> y;
        //     // x = rand() % n + 1;
        //     // y = rand() % n + 1;
        //     // while (y == x) y = rand() % n + 1;
        //     // cout << x << ' ' << y << '\n';
        //     int id = (h[x - 1] + h[y - 1] + 1) / 2;
        //     // int ans = SegTree::query(SegTree::T[x - 1], SegTree::T[x], SegTree::T[y - 1], SegTree::T[y], 1, e, id);
        //     int ans = SegTree::query(SegTree::T[p[x - 1]], SegTree::T[p[x - 1] + h[x - 1]], SegTree::T[p[y - 1]], SegTree::T[p[y - 1] + h[y - 1]], 1, e, id);
        //     cout << c[ans - 1] << '\n';

        //     // vector<int> d;
        //     // for (int i = p[x - 1]; i < p[x - 1] + h[x - 1]; i++) d.push_back(a[i]);
        //     // for (int i = p[y - 1]; i < p[y - 1] + h[y - 1]; i++) d.push_back(a[i]);
        //     // sort(d.begin(), d.end());
        //     // int res = d[id - 1];
        //     // if (res != ans) {
        //     //     cout << "ERROR " << c[ans - 1] << ' ' << c[res - 1] << '\n';
        //     // } else {
        //     //     cout << "RIGHT " << c[ans - 1] << ' ' << c[res - 1] << '\n';
        //     // }
        // }
    }
    return 0;
}