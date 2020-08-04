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
#include <cfloat>
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

#define sc(x) cout << #x" = " << x << endl, pause
#define sc2(x, y) cout << #x" = " << x << " " << #y" = " << y << endl, pause
#define sc3(x, y, z) cout << #x" = " << x << " " << #y" = " << y << " " << #z" = " << z << endl, pause
#define sc4(x, y, z, w) cout << #x" = " << x << " " << #y" = " << y << " " << #z" = " << z << " " << #w" = " << w << endl, pause

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

int T;

LL ok(string n) {
	rep (i, SZ(n)) {
		LL d = n[i] - '0';
		if (d & 1) return i;
	}
	return -1;
}

LL change(string n) {
	LL ans = 0;
	rep (i, SZ(n)) ans = ans * 10 + n[i] - '0';
	return ans;
}

LL gao(string n) {
	LL p, x, y, ans = change(n), tmp, m = SZ(n);
	cout << "ans= " << ans << '\n';
	p = ok(n);
	if (p == -1) return 0;

	LL d = change(n.substr(p, m - p));
	x = n[p] - '0';
	y = 1;
	FOR (i, i + 1, m - 1) y *= 10;

	// ans = min(ans, (x + 1) * y - d);
	cout << "x= " << x << '\n';
	if (x != 9LL) ans = min(ans, (x + 1) * y - d);
	else {
		tmp = (x + 1) * y - d;
		tmp += y * 10;
		ans = min(ans, tmp);
	}

	// if (p == 0 && x == 1) {
	// 	string t;
	// 	rep (i, m - 1) t.pb('9');
	// 	tmp = change(n) - change(t);
	// 	tmp += gao(t);
	// 	ans = min(ans, tmp);
	// } else {
	// 	n[p]--;
	// 	FOR (i, p + 1, m - 1) n[p] = '8';
	// 	tmp = y + gao(n);
	// 	ans = min(ans, tmp);
	// }
	return ans;
}

int main() {
	LL cas = 0, ans;
	string n;
	cin >> T;
	while (T--) {
		cin >> n;
		ans = gao(n);
		cout << "Case #" << ++cas << ": " << ans << '\n';
	}
    return 0;
}

