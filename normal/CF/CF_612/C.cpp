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

const int N = 105;

int n;
int a[N], b[N];

int gao(int a[N]) {
    int p = 0, d[2] = {n / 2, n / 2 + n % 2};
    vector<pair<int, pii> > b;
    FOR (i, 1, n) {
        if (a[i] > 0) {
            d[a[i] % 2]--;
            if ((a[p] % 2) ^ (a[i] % 2) == 0 && i - p > 1) b.pb(mp(i - p - 1, mp(p, i)));
            p = i;
        }
    }
    if (p != n) {
        if ((a[p] % 2) ^ (a[n + 1] % 2) == 0) b.pb(mp(n - p, mp(p, n + 1)));
    }

    sort(b.begin(), b.end());
    repit (it, b) {
        int sz = it->X, l = it->Y.X, r = it->Y.Y, id = a[l] % 2;
        if (d[id] >= sz) {
            FOR (i, l + 1, r - 1) a[i] = id;
            d[id] -= sz;
        }
    }
    FOR (i, 1, n) if (a[i] == -1) {
        int id = a[i - 1] % 2;
        if (d[id] > 0) d[id]--, a[i] = id;
        else d[id ^ 1]--, a[i] = id ^ 1;
    }
    int ans = 0;
    FOR (i, 2, n) ans += (a[i] % 2) ^ (a[i - 1] % 2);
    return ans;
}

int main() {
    memset(a, 127,sizeof(a));
    cout << a[0] << '\n';
    int p, ans;
    while (~in(n)) {
        FOR (i, 1, n) {
            in(a[i]);
            if (a[i] == 0) a[i] = -1;
        }
        ans = n;

        a[0] = 0, a[n + 1] = 0;
        rep (i, n + 2) b[i] = a[i];
        ans = min(ans, gao(b));

        a[0] = 0, a[n + 1] = 1;
        rep (i, n + 2) b[i] = a[i];
        ans = min(ans, gao(b));

        a[0] = 1, a[n + 1] = 0;
        rep (i, n + 2) b[i] = a[i];
        ans = min(ans, gao(b));

        a[0] = 1, a[n + 1] = 1;
        rep (i, n + 2) b[i] = a[i];
        ans = min(ans, gao(b));

        printf("%d\n", ans);
    }
    return 0;
}
