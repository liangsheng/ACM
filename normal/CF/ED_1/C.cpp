#include <bits/stdc++.h>

#define file_r(x) freopen(x, stdin, "r")
#define file_w(x) freopen(x, stdout, "w")
#define rep(i, n) for (int i = 0; i < n; i++)
#define FOR(i, n, m) for (int i = n; i <= m; i++)
#define repe(i, u) for (int i = head[u]; ~i; i = nxt[i])
#define FORD(i, n, m) for (int i = n; i >= m; i--)
#define repit(i, c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define pause cout << " press ant key to continue...", cin >> chh

#define pb push_back
#define mp make_pair
#define ins insert
#define X first
#define Y second
#define be begin
#define nb rbegin
#define er erase
#define SZ(c) c.size()
#define sqr(x) ((x) * (x))

#define sc(n) cout << #n << "= " << n, system("pause")
#define sc2(n, m) cout << #n << "= " << n << " " << #m << "= " << m, system("pause")
#define sc3(n, m, k) cout << #n << "= " << n << " " << #m << "= " << m << " " << #k << "= " << k, system("pause")
#define sc4(n, m, k, b) cout << #n << "= " << n << " " << #m << "= " << m << " " << #k << "= " << k << " " << #b << "= " << b, system("pause")

using namespace std;
int chh;

typedef long long LL;

const int N = 100005;
const double PI = acos(-1);

int n;

struct point {
    double x, y;
    int id;
};
point p[N];

double cross(const point &p1, const point &p2, const point &q1, const point &q2) {
    return (q2.y - q1.y) * (p2.x - p1.x) - (q2.x - q1.x) * (p2.y - p1.y);
}

bool cmp(const point &a, const point &b) {
    point origin;
    origin.x = origin.y = 0;
    return cross(origin, a, origin, b) < 0;
}

double gao(point p0, point p1) {
    double res = p0.x * p1.x + p0.y * p1.y;
    double l0 = sqrt(p0.x * p0.x + p0.y * p0.y);
    double l1 = sqrt(p1.x * p1.x + p1.y * p1.y);
    return acos(res / l0 / l1);
}

int main() {
    //cout << 0.75*3.14 << '\n';
    int l, r;
    double ans, tmp;
    cin >> n;
    rep (i, n) cin >> p[i].x >> p[i].y, p[i].id = i + 1;
    sort(p, p + n, cmp);
    //rep (i, n) cout << p[i].id << '\n';
    l = p[0].id, r = p[n - 1].id;
    ans = gao(p[0], p[n - 1]);
    //sc(ans);
    FOR (i, 0, n - 2) {
        tmp = gao(p[i], p[i + 1]);
        //sc(tmp);
        if (tmp < ans) ans = tmp, l = p[i].id, r = p[i + 1].id;
    }
    cout << l << ' ' << r << '\n';
    return 0;
}



















