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

int n, k, a, b, q;
int f[N], sb[N], sa[N], g[N];

void init() {
    memset(sb, 0, sizeof(sb));
    memset(sa, 0, sizeof(sa));
    memset(f, 0, sizeof(f));
    memset(g, 0, sizeof(g));
}

void add_a(int x, int y) {
    //cout << "x= " << x << ' ' << y << '\n';
    while (x > 0) sa[x] += y, x -= lowbit(x);
}

int cal_a(int x) {
    if (x > n) return 0;
    int ans = 0;
    while (x <= n) ans += sa[x], x += lowbit(x);
    return ans;
}

void add_b(int x, int y) {
    while (x <= n) sb[x] += y, x += lowbit(x);
}

int cal_b(int x) {
    if (x < 1) return 0;
    int ans = 0;
    while (x > 0) ans += sb[x], x -= lowbit(x);
    return ans;
}

void add_f(int x, int y) {
    while (x <= n) f[x] += y, x += lowbit(x);
}

int cal_f(int x) {
    if (x < 1) return 0;
    int ans = 0;
    while (x > 0) ans += f[x], x -= lowbit(x);
    return ans;
}

int main() {
    int cmd, kth, x, p, tmp, sum, ans;
    while (cin >> n >> k >> a >> b >> q) {
        init();
        sum = 0;
        while (q--) {
            cin >> cmd;
            if (cmd == 1) {
                cin >> kth >> x;
                tmp = g[kth], sum += x;

                add_f(kth, x);
                g[kth] += x;

                if (tmp >= a) add_a(kth, x);
                else if (g[kth] > a) add_a(kth, g[kth] - a);

                if (tmp >= b) add_b(kth, x);
                else if (g[kth] > b) add_b(kth, g[kth] - b);
            } else {
                cin >> p;
                //sc4(sum, cal_b(p - 1), p + k, cal_a(p + k));
                ans = sum - (cal_f(p + k - 1) - cal_f(p - 1));
                //sc(ans);
                ans -= cal_b(p - 1) + cal_a(p + k);
                cout << ans << '\n';
            }
        }
    }
    return 0;
}
















