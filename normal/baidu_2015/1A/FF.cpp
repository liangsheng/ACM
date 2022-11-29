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

int sig(double d) {
    return fabs(d) < 1E-6 ? 0 : d < 0 ? -1 : 1;
}

/**
点的结构体
*/
struct Point {
    double x, y;
    double k;
    Point() {}
    Point(double x, double y): x(x), y(y) {}
    void set(double x, double y) {
        this->x = x;
        this->y = y;
    }
    double mod() {
        return sqrt(x*x+y*y);
    }
    double mod_pow() {
        return x*x + y*y;
    }
    void output() {
        printf("x = %f, y = %f\n", x, y);
    }
    bool operator < (const Point &p) const {
        return sig(x-p.x) != 0 ? x < p.x : sig(y-p.y) < 0;
    }
};

double area(Point * p, int n) {
    double res = 0;
    p[n] = p[0];
    for(int i = 0; i < n; i ++) {
        res += p[i].x*p[i+1].y - p[i+1].x*p[i].y;
    }
    return res / 2;
}

bool cmp2(const Point &a, const Point &b) {
    return sig(a.y-b.y)!=0 ? a.y<b.y : sig(a.x-b.x)>0;
}

const double M_PI = acos(-1);

//计算从curAng逆时针转到ab的角
double calRotate(Point a, Point b, double curAng) {
    double x = fmod(atan2(b.y-a.y, b.x-a.x)-curAng, M_PI*2);
    if(x<0)			x += M_PI*2;
    if(x>1.9*M_PI)	x = 0;		//in case x is nearly 2*M_PI
    if(x >= 1.01*M_PI)	while(1);
    return x;
}

//计算凸多边形的最小外接矩形面积
double minRect0(Point *p, int n) {
    if(n<=2)  return 0;
    if(area(p, n) < 0) reverse(p, p+n);
    int ai = min_element(p, p+n) -p;
    int bi = min_element(p, p+n, cmp2)-p;
    int ci = max_element(p, p+n) -p;
    int di = max_element(p, p+n, cmp2)-p;
    int aj, bj, cj, dj;
    double res = 1E100, ang = -M_PI/2;
    double ra, rb, rc, rd, r, s, c, ac, bd;
    while(ang < M_PI * 0.51) {
        aj=(ai+1)%n;
        ra = calRotate(p[ai], p[aj], ang);
        bj=(bi+1)%n;
        rb = calRotate(p[bi], p[bj], ang+0.5*M_PI);
        cj=(ci+1)%n;
        rc = calRotate(p[ci], p[cj], ang+1.0*M_PI);
        dj=(di+1)%n;
        rd = calRotate(p[di], p[dj], ang+1.5*M_PI);
        r = min(min(ra,rb), min(rc,rd));
        ang += r;
        s = sin(ang), c = cos(ang);
        ac = -s*(p[ci].x-p[ai].x) + c*(p[ci].y-p[ai].y);
        bd = c*(p[di].x-p[bi].x) + s*(p[di].y-p[bi].y);
        res = min(res, fabs(ac*bd)); //改为(fabs(ac)+fabs(bd))*2 就是求最小周长外接矩形
        if(sig(ra-r)==0)  ai=aj;
        if(sig(rb-r)==0)  bi=bj;
        if(sig(rc-r)==0)  ci=cj;
        if(sig(rd-r)==0)  di=dj;
    }
    return res==1E100 ? 0 : res;
}

/*==================================================*\
| Graham  求凸包 O(N * logN)
| CALL: nr = graham(pnt, int n, res); res[] 为凸包点集;
\*==================================================*/
struct point {
    double x, y;
    point() {}
    point(int X, int Y): x(X), y(Y) {}
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
        while (top!=len && mult(pnt[i], res[top],
                                res[top-1])) top--;
        res[++top] = pnt[i];
    }
    return top; //  返回凸包中点的个数
}

const int N = 4005;

int T, n, e, m;
point a[N], b[N];
Point ans[N];

int main() {
    int cas = 0;
    int x1, y1, x2, y2, x3, y3, x4, y4;
    double res;
    scanf("%d", &T);
    while (T--) {
        e = 0;
        scanf("%d", &n);
        rep (i, n) {
            scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
            a[e++] = point(x1, y1);
            a[e++] = point(x2, y2);
            a[e++] = point(x3, y3);
            a[e++] = point(x4, y4);
        }
        m = graham(a, e, b);
        rep (i, m) ans[i].x = (double) b[i].x, ans[i].y = (double) b[i].y;
        res = minRect0(ans, m);
        printf("Case #%d:\n%.0f\n", ++cas, res);
    }
    return 0;
}
