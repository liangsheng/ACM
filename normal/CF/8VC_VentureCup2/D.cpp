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

const int N = 200005, M = 1 << 20, INF = 2139062143;

int n, vol, m;
int h[N];
pii p[N];
int a[M << 1];

void init() {
    memset(a, 127, sizeof(a));
}

void add(int x, int y) {
    for (a[x += M] = y, x >>= 1; x; x >>= 1) {
        a[x] = min(a[x << 1], a[x << 1 | 1]);
    }
}

int gao(int s, int t) {
    int ans = INF;
    for (s = s + M - 1, t = t + M + 1; s ^ t ^ 1; s >>= 1, t >>= 1) {
        if (~s & 1) ans = min(ans, a[s ^ 1]);
        if (t & 1) ans = min(ans, a[t ^ 1]);
    }
    return ans;
}

int main() {
    int x, y, flag, now, tmp;
    LL ans;
    while (~scanf("%d %d %d", &n, &vol, &m)) {
        FOR (i, 1, m) scanf("%d %d", &p[i].X, &p[i].Y);
        sort(p + 1, p + m + 1);
        p[0].X = 0, p[0].Y = 0;
        p[m + 1].X = n, p[m + 1].Y = 0;
        flag = 1;
        rep (i, m + 1) if (p[i + 1].X - p[i].X > vol) {
            flag = 0;
            break;
        }
        if (!flag) {
            puts("-1");
            continue;
        }
        init();
        memset(h, -1, sizeof(h));
        FORD (i, m, 1) {
            add(p[i].Y, i);
            if (p[i].Y == 1) h[i] = -1;
            else {
                h[i] = gao(1, p[i].Y - 1);
                if (h[i] == INF || p[h[i]].X - p[i].X > vol) h[i] = -1;
            }
        }
        h[0] = -1, h[m] = m + 1, ans = 0;
        FOR (i, 0, m) {
            y = p[i + 1].X - p[i].X;
            if (h[i] == -1) {
                x = min(vol, n - p[i].X);
                if (now < x) ans += (LL) p[i].Y * (x - now), now = x;
                now = now - y;
            } else {
                tmp = p[h[i]].X - p[i].X;
                if (tmp <= now) now -= y;
                else {
                    ans += (LL) p[i].Y * (tmp - now);
                    now = tmp - y;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
