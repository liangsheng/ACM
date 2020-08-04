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

const int N = 10005;

int n, w, v, u;
pii p[N];
LL F[N];

int main() {
    int id;
    bool flag;
    double ans, x, y, h, my;
    while (~scanf("%d %d %d %d", &n, &w, &v, &u)) {
        id = 0, my = 0;
        rep (i, n) {
            scanf("%d %d", &p[i].X, &p[i].Y);
            if (p[i].Y < p[id].Y || (p[i].Y == p[id].Y && p[i].X > p[id].X)) id = i;
            my = max(my, p[i].Y * 1.0);
        }
        p[n] = p[0];
        rep (i, n) {
            F[i] = (LL) p[i].X * u - (LL) p[i].Y * v;
            if (F[i] > 0) F[i] = 1;
            else if (F[i] < 0) F[i] = -1;
        }
        flag = 1;
        rep (i, n) if (F[i] * F[i + 1] < 0) {
            flag = 0;
            break;
        }
        //sc(flag);
        if (flag) {
            printf("%.10f\n", w * 1.0 / u);
            continue;
        }
        ans = 0, h = 0;
        //sc3(id, p[id].X, p[id].Y);
        for (int i = id; ; i++) {
            x = p[i].X - v * 1.0 * ans;
            y = p[i].Y;
            if (y == my) break;
            ans += max(x * 1.0 / v, (y - h) / u);
            h = p[i].Y;
            //sc2(i, ans);
        }
        ans += (w - h) * 1.0 / u;
        printf("%.10f\n", ans);
    }
    return 0;
}














