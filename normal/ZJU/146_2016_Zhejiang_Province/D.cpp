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
#define Aint(c) (c).begin(), (c).end()
#define sqr(r) ((int) (r) * (r))
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

int gao(int year1, int month1, int day1, int year2, int month2, int day2)   {
    int nd, nm, ny; //new_day, new_month, new_year
    int od, om, oy; //old_day, oldmonth, old_year

    nm = (month2 + 9) % 12;
    ny = year2 - nm/10;
    nd = 365*ny + ny/4 - ny/100 + ny/400 + (nm*306 + 5)/10 + (day2 - 1);

    om = (month1 + 9) % 12;
    oy = year1 - om/10;
    od = 365*oy + oy/4 - oy/100 + oy/400 + (om*306 + 5)/10 + (day1 - 1);

    return od - nd;
}

const int N = 800 * 36 + 5;

int e, tol;
int Y[N], M[N], D[N], V[N], pos[N];
int c[N][7];
int dx[3] = {1, 11, 21};
vi g[7];

void init() {
    int x;
    e = 0, tol = 36 * 400;
    rep (i, 800) FOR (j, 1, 12) rep (k, 3) {
        Y[e] = i, M[e] = j, D[e] = dx[k];
        x = gao(i, j, dx[k], 0, 1, 1) % 7;
        //if (e == 587) sc4(Y[e], M[e], D[e], x);
        V[e] = x;
        c[e][x]++;
        pos[e] = SZ(g[x]), g[x].pb(e);
        if (e != 0) rep (l, 7) c[e][l] += c[e - 1][l];
        e++;
    }
}

int T;
int y, m, d, n;

void solve() {
    int y1 = y % 400, m1 = m, d1 = d, cnt, mod, p;
    int id = 36 * y1 + 3 * (m1 - 1);
    rep (k, 3) {
        if (dx[k] == d1) break;
        id++;
    }
    //sc2(id, V[id]);
    cnt = c[id + tol][V[id]] - c[id][V[id]];
    //sc(cnt);
    p = n / cnt, cnt = n % cnt;
    //sc3(cnt, gao(16, 4, 11, 0, 1, 1) % 7, V[id]);
    id = g[V[id]][pos[id] + cnt];
    printf("%d %d %d\n", Y[id] - y1 + y + p * 400, M[id], D[id]);
}

int main() {
    //file_w("out.txt");
    init();
    scanf("%d", &T);
    //T = 1000;
    while (T--) {
        scanf("%d %d %d %d", &y, &m, &d, &n);
        //y = 9999, m = 12, d = 21, n = 1000000000;
        n--;
        solve();
    }
    return 0;
}
