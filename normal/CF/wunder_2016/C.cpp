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

const int N = 100005;

int n;
pair<pii, int> p[N];

LL cal(pii a, pii b, pii c) {
    LL ans = (LL) a.X * b.Y + (LL) b.X * c.Y + (LL) c.X * a.Y
          -(LL) a.X * c.Y - (LL) b.X * a.Y - (LL) c.X * b.Y;
    if (ans < 0) ans = -ans;
    return ans;
}

int main() {
    LL area, tmp;
    int id;
    while (cin >> n) {
        FOR (i, 1, n) cin >> p[i].X.X >> p[i].X.Y, p[i].Y = i;
        sort(p + 1, p + n + 1);
        //FOR (i, 1, n) sc2(i, p[i].Y);
        FOR (i, 3, n) {
            area = cal(p[1].X, p[i].X, p[2].X);
            if (area != 0) {
                id = i;
                break;
            }
        }
        //sc3(id, p[id].Y, area);
        FOR (i, id + 1, n) {
            tmp = cal(p[1].X, p[i].X, p[2].X);
            if (tmp == 0) continue;
            if (tmp < area) area = tmp, id = i;
        }
        cout << p[1].Y << ' ' << p[2].Y << ' ' << p[id].Y << '\n';
    }
    return 0;
}










