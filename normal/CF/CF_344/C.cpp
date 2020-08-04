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

const int N = 200005;

int n, m;
int a[N], b[N], c[N];
int t[N], r[N];
vi q;

int main() {
    int x, y, l, e, sz;
    while (~scanf("%d %d", &n, &m)) {
        FOR (i, 1, n) scanf("%d", &a[i]);
        FOR (i, 1, m) scanf("%d %d", &t[i], &r[i]);
        b[m] = m;
        FORD (i, m - 1, 1) b[i] = r[i] > r[b[i + 1]] ? i : b[i + 1];
        q.clear(), x = 1;
        while (x <= m) q.pb(b[x]), x = b[x] + 1;
        x = 1, y = r[q[0]];
        copy(a + x, a + y + 1, c + 1);
        sort(c + x, c + y + 1);
        sz = SZ(q);
        rep (i, sz) {
            if (i == sz - 1) e = 0;
            else e = r[q[i + 1]];
            l = r[q[i]];
            if (t[q[i]] == 1) while (l != e) a[l--] = c[y--];
            else while (l != e) a[l--] = c[x++];
        }
        FOR (i, 1, n) printf("%d ", a[i]);
        puts("");
    }
    return 0;
}
