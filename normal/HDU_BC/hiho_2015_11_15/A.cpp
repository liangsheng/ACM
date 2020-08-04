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

const int N = 10005;

struct Node {
    int l, t, w, h;
    bool operator <(const Node& arg) const {
        if (l + w != arg.l + arg.w) return l + w > arg.l + arg.w;
        return l > arg.l;
    }
} p[N];

struct P {
    int y0, y1, x, f;
    P() {}
    P(int A, int B, int C, int D): y0(A), y1(B), x(C), f(D) {}
    bool operator <(const P& arg) const {
        if (x != arg.x) return x < arg.x;
        return 0;
    }
} li[N * 2];

int T, n, r, e, m;
int a[N * 2];

int main() {
    int l, ans, np;
    LL d, tol, now;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &r, &n);
        e = 0, tol = 0, m = 0;
        rep (i, n) {
            scanf("%d %d %d %d", &p[i].l, &p[i].t, &p[i].w, &p[i].h);
            a[e++] = p[i].l, a[e++] = p[i].l + p[i].w;
            tol += (LL) p[i].w * p[i].h;
            li[m++] = P(p[i].t - p[i].h, p[i].t, p[i].l, -1);
            li[m++] = P(p[i].t - p[i].h, p[i].t, p[i].l + p[i].w, 1);
        }
        if (tol == 0) {
            printf("%d\n", r);
            continue;
        }
        a[e++] = 0, a[e++] = r;
        sort(a, a + e);
        e = unique(a, a + e) - a;
        a[e] = a[e - 1];
        sort(li, li + m);
        now = 0, d = 0, ans = -1, np = m - 1;
        //FORD (i, m - 1, 0) cout << li[i].x << ' ' << li[i].y0 << ' ' << li[i].y1 << ' ' << li[i].f << '\n'; system("pause");
        FORD (i, e - 1, 0) {
            now += d * (a[i + 1] - a[i]);
            if (now * 2 == tol) {
                ans = a[i];
                break;
            }
            if (now * 2 > tol) break;
            ans = a[i];
            while (li[np].x == a[i]) {
                d += li[np].f * (li[np].y1 - li[np].y0);
                np--;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}















