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
#define clr(a, x) memset(a, x, sizeof(a))

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

const int N = 500005, MOD = 1000000007;

int n, h, w;
char s[N];
string ss = "URDL";
int cmd[N];
vector< pair<LL, int> > a;
vector<int> b;

void gao(int id) {
    int c = max(h, w), fid = (id + 2) % 4;
    int x, e, p, sz, tim, tmp;
    x = e = 0;
    b.clear();
    rep (i, n) {
        if (cmd[i] != id && cmd[i] != fid) continue;
        if (cmd[i] == id && x == 0) b.pb(i), a.pb(mp(i, id % 2));
        else x += (cmd[i] == fid) ? 1 : -1;
    }
    sz = SZ(b), tim = 1;
    while (e < c && x < sz) {
        FOR (i, x, sz - 1) a.pb(mp((LL) tim * n + b[i], id % 2)), e++;
        tim++;
    }
}

int main() {
    //file_r("in.txt");
    //file_w("out1.txt");
    int sz, d, ans, x, y;
    while (~scanf("%d %d %d", &n, &h, &w)) {
        scanf("%s", s);
        rep (i, n) rep (j, 4) {
            if (ss[j] == s[i]) cmd[i] = j;
        }
        a.clear();
        rep (i, 4) gao(i);
        sort(ALL(a));
        ans = 0, x = h, y = w, sz = SZ(a);
        rep (i, sz) {
            d = 1;
            if (i != 0) d = (a[i].X - a[i - 1].X) % MOD;
            ans = (ans + (LL) x * y % MOD * d % MOD) % MOD;
            if (a[i].Y) y--; else x--;
            if (x == 0 || y == 0) break;
        }
        if (x != 0 && y != 0) ans = -1;
        cout << ans << '\n';
    }
    return 0;
}
