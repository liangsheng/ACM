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

const int N = 100005, INF = ~0U >> 2;

int n;
int t[N], c[N];

int main() {
	int maxt, mint, low, up, flag;
	LL ans;
	LL p, q;
	while (~in(n)) {
		maxt = -1, mint = INF;
		up = -1, low = INF, flag = 0;
		p = 0, q = 0;
		rep (i, n + 1) {
			in2(t[i], c[i]);
			maxt = max(maxt, t[i]);
			mint = min(mint, t[i]);
			if (i != 0) {
				low = min(low, t[i]);
				up = max(up, t[i]);
				if (t[i] != t[i - 1]) flag = 1;
			}
			p += (LL) c[i] * t[i];
			q += c[i];
		}
		if (!flag) {
			puts("Possible");
			printf("%.4f\n", t[0] * 1.0);
			continue;
		}
		if (t[0] == mint) {
			ans = 0;
			FOR (i, 1, n) {
				if (t[i] <= low) continue;
				ans += (LL) c[i] * (t[i] - low);
			}
			// cout << "ans=  " << ans << ' ' << low << '\n';
			if (ans <= (LL) c[0] * (low - t[0])) {
				puts("Possible");
				printf("%.4f\n", low * 1.0);
			} else {
				puts("Impossible");
			}

		} else if (t[0] == maxt) {
			puts("Possible");
			printf("%.4f\n", p * 1.0 / q);
		} else {
			puts("Impossible");
		}

	}
	return 0;
}




















