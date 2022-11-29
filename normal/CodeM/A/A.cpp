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

pii a[26];

void init() {
	a[0] = mp(1, 2);
	a[1] = mp(1, 2);
	a[2] = mp(1, 2);

	a[3] = mp(1, 3);
	a[4] = mp(1, 3);
	a[5] = mp(1, 3);

	a[6] = mp(2, 1);
	a[7] = mp(2, 1);
	a[8] = mp(2, 1);

	a[9] = mp(2, 2);
	a[10] = mp(2, 2);
	a[11] = mp(2, 2);

	a[12] = mp(2, 3);
	a[13] = mp(2, 3);
	a[14] = mp(2, 3);

	a[15] = mp(3, 1);
	a[16] = mp(3, 1);
	a[17] = mp(3, 1);
	a[18] = mp(3, 1);

	a[19] = mp(3, 2);
	a[20] = mp(3, 2);
	a[21] = mp(3, 2);

	a[22] = mp(3, 3);
	a[23] = mp(3, 3);
	a[24] = mp(3, 3);
	a[25] = mp(3, 3);
}

int T;
string s;

int abs(int x) {
	return x > 0 ? x : -x;
}

int main() {
	int ans, id;
	pii tmp;
	init();
	cin >> T;
	while (T--) {
		cin >> s;
		ans = 0;
		tmp = mp(1, 1);
		rep (i, SZ(s)) {
			id = s[i] - 'A';
			ans += abs(a[id].X - tmp.X) + abs(a[id].Y - tmp.Y);
			tmp = a[id];
		}
		cout << ans << '\n';
	}
	return 0;
}

















