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

int T, n, m;
int a[N], b[N], f[N];
LL c[N];

void init() {
    memset(c, 0, sizeof(c));
}

void add(int x, int y) {
    //sc2(x, y);
    for (; x <= n; x += lowbit(x)) c[x] += y;
}

LL cal(int x) {
    LL ans = 0;
    for (; x > 0; x -= lowbit(x)) ans += c[x];
    return ans;
}

int main() {
    int cmd, x, y, ans;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        FOR (i, 1, n) scanf("%d", &a[i]);
        init();
        FOR (i, 1, n) {
            add(i, a[a[i]]);
            b[i] = a[a[i]];
            f[a[i]] = i;
        }
        scanf("%d", &m);
        while (m--) {
            scanf("%d %d %d", &cmd, &x, &y);
            if (cmd == 2) printf("%lld\n", cal(y) - cal(x - 1));
            else {
                if (x == y) continue;
                swap(a[x], a[y]);
                add(x, -b[x]), add(x, a[a[x]]), b[x] = a[a[x]];
                add(y, -b[y]), add(y, a[a[y]]), b[y] = a[a[y]];
                if (f[x] != x && f[x] != y) {
                    add(f[x], -b[f[x]]);
                    add(f[x], a[x]);
                    b[f[x]] = a[x];
                }
                if (f[y] != x && f[y] != y) {
                    add(f[y], -b[f[y]]);
                    add(f[y], a[y]);
                    b[f[y]] = a[y];
                }
                swap(f[a[x]], f[a[y]]);
            }
        }
        //FOR (i, 1, n) sc2(i, f[i]);
    }
    return 0;
}











