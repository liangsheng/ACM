#include <bits/stdc++.h>

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
#define sqr(r) ((r) * (r))
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

const int N = 1000005, MOD = 1000000007;

int p, k;
int f[N];

int power(int x, int y) {
	int ans = 1;
	while (y) {
		if (y & 1) ans = (LL) ans * x % MOD;
		x = (LL) x * x % MOD;
		y >>= 1;
	}
	return ans;
}

int main() {
	int ans, t, d, num;
	while (~scanf("%d %d", &p, &k)) {
		if (k == 0) {
			ans = power(p, p - 1);
			printf("%d\n", ans);
			continue;
		}
		if (k == 1) {
			ans = power(p, p);
			printf("%d\n", ans);
			continue;
		}
		memset(f, 0, sizeof(f));
		num = 0;
		FOR (i, 1, p - 1) {
			if (f[i]) continue;
			f[i] = 1;
			t = (LL) k * i % p, d = 1;
			while (t != i) {
				d++, f[t] = 1;
				t = (LL) k * t % p;
			}
			num++;
		}
		ans = power(p, num);
		printf("%d\n", ans);
	}
    return 0;
}
