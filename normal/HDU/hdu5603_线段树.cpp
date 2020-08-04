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

const int N = 300005, M = 1000005;

int n, m, e;
int ans[N], a[M];
pii l[N];
pair<int, pair<int, int> > p[N + N];

void init() {
    memset(a, 0, sizeof(a));
}

void add(int x, int y) {
    for (; x > 0; x -= x & (-x)) a[x] += y;
}

int cal(int x) {
    int ans = 0;
    for (; x < M; x += x & (-x)) ans += a[x];
    return ans;
}

int main() {
    int cnt, x;
    while (~scanf("%d %d", &n, &m)) {
        rep (i, n) scanf("%d %d", &l[i].Y, &l[i].X);
        sort(l, l + n);
        e = 0;
        rep (i, m) {
            scanf("%d", &cnt);
            x = 0;
            rep (j, cnt) {
                scanf("%d", &p[e].X);
                p[e].Y.X = x, p[e].Y.Y = i;
                x = p[e++].X;
            }
            p[e].X = M - 4, p[e].Y.X = x, p[e++].Y.Y = i;
        }
        sort(p, p + e);
        memset(ans, 0, sizeof(ans));
        init();
        x = 0;
        rep (i, e) {
            while (x < n && l[x].X < p[i].X) add(l[x++].Y, 1);
            ans[p[i].Y.Y] += cal(p[i].Y.X + 1);
        }
        rep (i, m) printf("%d\n", n - ans[i]);
    }
    return 0;
}
