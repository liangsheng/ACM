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
#define eps 1e-4
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

/*==================================================*\
| Graham  求凸包 O(N * logN)
| CALL: nr = graham(pnt, int n, res); res[] 为凸包点集;
\*==================================================*/
struct point {
    double x, y;
    point() {}
    point(double X, double Y): x(X), y(Y) {}
};
bool mult(point sp, point ep, point op) {
    return (sp.x - op.x) * (ep.y - op.y)
           >= (ep.x - op.x) * (sp.y - op.y);
}
bool operator < (const point &l, const point &r) {
    return l.y < r.y || (l.y == r.y && l.x < r.x);
}
int graham(point pnt[], int n, point res[]) {
    int i, len, k = 0, top = 1;
    sort(pnt, pnt + n);
    if (n == 0) return 0;
    res[0] = pnt[0];
    if (n == 1) return 1;
    res[1] = pnt[1];
    if (n == 2) return 2;
    res[2] = pnt[2];
    for (i = 2; i < n; i++) {
        while (top && mult(pnt[i], res[top], res[top-1]))
            top--;
        res[++top] = pnt[i];
    }
    len = top;
    res[++top] = pnt[n - 2];
    for (i = n - 3; i >= 0; i--) {
        while (top!=len && mult(pnt[i], res[top], res[top-1])) top--;
        res[++top] = pnt[i];
    }
    return top; //  返回凸包中点的个数
}

double p2pdis(point p1,point p2) {
    return ((p1.x-p2.x) * (p1.x-p2.x) + (p1.y-p2.y) * (p1.y-p2.y));
}

double xmulti(point p1, point p2, point p0) {
    return((p1.x-p0.x) * (p2.y-p0.y) - (p2.x - p0.x) * (p1.y - p0.y));
}
const int N = 105;

int T, n, m;
point p[N], res[N];

int main() {
    int flag;
    scanf("%d", &T);
    while (T--) {
        n = 5;
        rep (i, n) scanf("%lf %lf", &p[i].x, &p[i].y);
        m = graham(p, n, res);
        //sc(m);
        //rep (i, m) cout << res[i].x << ' ' << res[i].y << '\n';
        if (m != n) {
            if (m == 2 && res[0].x == res[1].x && res[0].y == res[1].y) puts("Yes");
            else puts("No");
            continue;
        }
        flag = 1;
        rep (i, n - 1) {
            double d1 = p2pdis(res[i], res[(i + 1) % n]);
            double d2 = p2pdis(res[(i + 1) % n], res[(i + 2) % n]);
            //sc2(d1, d2);
            if (fabs(d1 - d2) > eps) {
                flag = 0;
                break;
            }
        }
        //sc(flag);
        if (!flag) {
            puts("No");
            continue;
        }
        rep (i, n) {
            double d1 = xmulti(res[(i - 1 + n) % n], res[(i + 1 + n) % n], res[i]);
            double d2 = xmulti(res[(i - 1 + n + 1) % n], res[(i + 1 + n + 1) % n], res[(i + 1 + n) % n]);
            if (fabs(d1 - d2) > eps) {
                flag = 0;
                break;
            }
        }
        puts(flag ? "Yes" : "No");
    }
    return 0;
}
