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

const int N = 100005, M = N * 4;

int n, m;
int p[N];
int a[M], L[N], R[N];

void cal() {
	R[n] = 1;
	FORD (i, n - 1, 1) {
		R[i] = 2;
		if (p[i] - p[i + 1] == p[i + 1] - p[i + 2]) R[i] = R[i + 1] + 1;
	}

	L[1] = 1;
	FOR (i, 2, n) {
		L[i] = 2;
		if (p[i] - p[i - 1] == p[i - 1] - p[i - 2]) L[i] = L[i - 1] + 1;
	}
}

void push_up(int k, int s, int t) {
	int l = k << 1, r = l + 1, mid = (s + t) >> 1, d;
	a[k] = max(a[l], a[r]);
	d = min(R[mid], t - mid + 1) + min(L[mid + 1], mid - s + 2) - 2;
	a[k] = max(a[k], d);
}

void init(int k, int s, int t) {
	if (s == t) {
		a[k] = 1;
		return ;
	}	
	int mid = (s + t) >> 1;
	init(k << 1, s, mid);
	init(k << 1 | 1, mid + 1, t);
	push_up(k, s, t);
	//printf("k= %d s= %d t= %d %d\n", k, s, t, a[k]);
}

int query(int k, int s, int t, int l, int r) {
	if (s > r || t < l) return 0;
	if (s >= l && t <= r) return a[k];
	int ans, mid = (s + t) >> 1, d;
	ans = query(k << 1, s, mid, l, r);
	ans = max(ans, query(k << 1 | 1, mid + 1, t, l, r));

	d = min(R[mid], r - mid + 1) + min(L[mid + 1], mid - l + 2) - 2;
	ans = max(ans, d);
	return ans;
}

int main() {
	int l, r;
	while (~in2(n, m)) {
		FOR (i, 1, n) in(p[i]);
		cal();
		init(1, 1, n);
		while (m--) {
			in2(l, r);
//			int ans = 0;
//			FOR (i, l, r) ans = max(ans, min(R[i], r - i + 1));
			printf("%d\n", query(1, 1, n, l, r));

		}
	}
	return 0;
}
