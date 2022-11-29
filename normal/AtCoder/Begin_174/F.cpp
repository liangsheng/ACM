#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)

#define pause cout << " press ansy key to continue...",  cin >> chh
#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)
#define lowbit(x) ((x) & (-x))
#define repit(i, c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repe(i, u) for (int i = head[u]; i != -1; i = nxt[i])
#define repd(i, n) for (int i = (n - 1); i >= 0; i--)
#define FOR(i, n, m) for (int i = (n); i <= (m); i++)
#define FORD(i, n, m) for (int i = (n); i >= (m); i--)
#define pb push_back
#define X first
#define Y second
#define ins insert
#define rb rbegin
#define be begin
#define er erase
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define SZ(c) (c).size()
#define ALL(c) (c).begin(), (c).end()
#define sqr(r) ((LL) (r) * (r))
#define dis(x1, y1, x2, y2) (((x1) - (x2)) * ((x1) - (x2)) + ((y1) - (y2)) * ((y1) - (y2)))
#define FASTIO ios::sync_with_stdio(false);cin.tie(0)

#define sc(x) cout << #x" = " << x << endl, system("pause")
#define sc2(x, y) cout << #x" = " << x << " " << #y" = " << y << endl, system("pause")
#define sc3(x, y, z) cout << #x" = " << x << " " << #y" = " << y << " " << #z" = " << z << endl, system("pause")
#define sc4(x, y, z, w) cout << #x" = " << x << " " << #y" = " << y << " " << #z" = " << z << " " << #w" = " << w << endl, system("pause")

#define in(n) scanf("%d", &n)
#define in2(n, m) scanf("%d %d", &n, &m)
#define in3(x, y, z) scanf("%d %d %d", &x, &y, &z)

using namespace std;
int chh;

typedef vector<int> vi;
typedef set<int> si;
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef pair<int, pii> pi3;
typedef vector< pair<int, int> > vpii;
typedef long long LL;

const int N = 500005;

int n, m, e;
int a[N], c[N], pre[N];

int T[N], L[N * 40], R[N * 40], val[N * 40];
struct SegTree {
	
	int e;
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
	int query(int S, int E, int s, int t, int l, int r) {
		if (t < l || s > r) return 0;
		if (s >= l && t <= r) return val[E] - val[S];
		int mid = (s + t) >> 1;
		return query(L[S], L[E], s, mid, l, r) + query(R[S], R[E], mid + 1, t, l, r);
	}
} seg;

int main() {
	int l, r, tmp;
	while (~in2(n, m)) {
		e = 0;
		FOR (i, 1, n) in(a[i]), c[e++] = a[i];
		sort(c, c + e);
		e = unique(c, c + e) - c;
		FOR (i, 1, n) a[i] = lower_bound(c, c + e, a[i]) - c + 1;
		
		seg.init();
		memset(pre, -1, sizeof(pre));
		FOR (i, 1, n) {
			if (pre[a[i]] == -1) {
				seg.update(T[i], T[i - 1], 1, n, i, 1);
			} else {
				seg.update(tmp, T[i - 1], 1, n, pre[a[i]], -1);
				seg.update(T[i], tmp, 1, n, i, 1);
			}
			pre[a[i]] = i;
		}
		while (m--) {
			in2(l, r);
			printf("%d\n", seg.query(0, T[r], 1, n, l, r));
		}
	}
	return 0;
}