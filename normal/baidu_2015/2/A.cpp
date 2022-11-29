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

const double eps = 1e-10;
struct point {
    double x, y;
    point() {}
    point(double X, double Y): x(X), y(Y) {}
};
double min(double a, double b) {
    return a < b ? a : b;
}
double max(double a, double b) {
    return a > b ? a : b;
}
bool inter(point a, point b, point c, point d) {
    if ( min(a.x, b.x) > max(c.x, d.x) ||
            min(a.y, b.y) > max(c.y, d.y) ||
            min(c.x, d.x) > max(a.x, b.x) ||
            min(c.y, d.y) > max(a.y, b.y) ) return 0;
    double h, i, j, k;
    h = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    i = (b.x - a.x) * (d.y - a.y) - (b.y - a.y) * (d.x - a.x);
    j = (d.x - c.x) * (a.y - c.y) - (d.y - c.y) * (a.x - c.x);
    k = (d.x - c.x) * (b.y - c.y) - (d.y - c.y) * (b.x - c.x);
    return h * i <= eps && j * k <= eps;
}

const int N = 25;

int n, T, e, ans;
int g[N][N], a[N];
double x0[N], y0[N], x1[N], y1[N];

void dfs(int p, int cnt) {
    if (cnt == 4) {
        //rep (i, e) cout << a[i] << '\n';
        //system("pause");
        int tmp = 0;
        FOR (i, 0, 3) FOR (j, i + 1, 3) tmp += g[a[i]][a[j]];
        if (tmp == 4) ans++;
        return ;
    }
    a[e++] = p;
    dfs(p + 1, cnt + 1);
    e--;
    if (cnt + n - p > 4) dfs(p + 1, cnt);
}

int main() {
    //cout << inter(point(3, 0), point(3, 3), point(2, 2), point(-5, 2)) << '\n';
    int cas = 0;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        rep (i, n) scanf("%lf %lf %lf %lf", &x0[i], &y0[i], &x1[i], &y1[i]);
        memset(g, 0, sizeof(g));
        rep (i, n) FOR (j, i + 1, n - 1) {
            g[i][j] = g[j][i] = inter(point(x0[i], y0[i]), point(x1[i], y1[i]), point(x0[j], y0[j]), point(x1[j], y1[j]));
            //if (i == 0 && j == 3) sc4(x0[i], y0[i], x1[i], y1[i]);
        }
//        rep (i, n) {
//            rep (j, n) cout << g[i][j] << ' ';
//            cout << '\n';
//        }
//        system("pause");
        ans = e = 0;
        dfs(0, 0);
        printf("Case #%d:\n%d\n", ++cas, ans);
    }
    return 0;
}






















