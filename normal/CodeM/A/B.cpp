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

const int N = 100005;

int n;
int a[N];
int x[N], y[N];

int main() {
	int p, l, e;
	LL ans, res;
	while (~in(n)) {
		FOR (i, 1, n) {
			in(a[i]);
			x[i] = a[i];
		}
		FOR (i, 1, n) {
			in(e);
			a[i] -= e;
			y[i] = e;
		}
		p = 1, ans = 0;
		// FOR (i, 1, n) cout << a[i] << ' ';
		// puts("");
		FOR (i, 1, n) {
			if (a[i] >= 0) continue;
			while (p <= n) {
				if (a[p] <= 0) {
					p++;
					continue;
				}
				if (a[p] + a[i] < 0) {
					
					if (i < p) {
						ans += (LL) a[p] * (p - i);
					} 
					if (i > p) {
						ans += (LL) a[p] * (i + p - 2);
					}
					

					a[i] += a[p];
					a[p] = 0;
					p++;
				} else {
					if (i < p) {
						ans += (LL) (0 - a[i]) * (p - i);
					} 
					if (i > p) {
						ans += (LL) (0 - a[i]) * (i + p - 2);
					}

					a[p] += a[i];
					a[i] = 0;
					break;
				}
			}
			// FOR (j, 1, n) cout << a[j] << ' ';
			// cout << '\n' << ans << ' ' << p << '\n';
		}
		// cout << ans << '\n';

		res = 0;
		p = 1;
		FORD (i, n, 1) {
			if (y[i] > x[i]) {
				y[i] -= x[i], x[i] = 0;
				while (p <= n) {
					if (x[p] < y[i]) {
						res += (LL) (p + i - 2) * x[p];
						y[i] -= x[p];
						x[p] = 0;
						p++;
					} else {
						res += (LL) (p + i - 2) * y[i];
						x[p] -= y[i];
						y[i] = 0;
						break;
					}
				}
			}
			x[i] -= y[i];
			x[i - 1] += x[i];
			res += x[i];
			// cout << "res= " << res << ' ' << i << ' ' << x[i] << '\n';
		}
		cout << res << '\n';

	}
	return 0;
}



















