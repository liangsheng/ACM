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
#define sqr(r) ((LL) (r) * (r))
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

const int N = 6;

int n, m, ans;
int a[20][3] = {0, 1, 2,
                0, 1, 3,
                0, 1, 4,
                0, 1, 5,
                0, 2, 3,
                0, 2, 4,
                0, 2, 5,
                0, 3, 4,
                0, 3, 5,
                0, 4, 5,
                1, 2, 3,
                1, 2, 4,
                1, 2, 5,
                1, 3, 4,
                1, 3, 5,
                1, 4, 5,
                2, 3, 4,
                2, 3, 5,
                2, 4, 5,
                3, 4, 5};
char g[N][N];
int r[N], c[N];

void dfs(int x) {
    //sc(x);
    if (x == 6) {
        ans++;
        return ;
    }
    int flag, u = x, y, dx, dy;
    rep (i, m) {
        flag = 1, dx = 0, dy = 0;
        rep (j, 3) {
            y = a[i][j];
            if (g[x][y] == 'o') continue;
            r[x]++, c[y]++;
        }
        if (r[x] <= 3 && c[0] <= 3 && c[1] <= 3 && c[2] <= 3 && c[3] <= 3 && c[4] <= 3 && c[5] <= 3) {
            dfs(x + 1);
        }
        rep (j, 3) {
            y = a[i][j];
            if (g[x][y] == 'o') continue;
            r[x]--, c[y]--;
        }
    }
}

int main() {
    n = 6, m = 20, ans = 0;
    rep (i, n) scanf("%s", g[i]);
    memset(r, 0, sizeof(r));
    memset(c, 0, sizeof(c));
    rep (i, n) rep (j, n) {
        if (g[i][j] == 'o') r[i]++, c[j]++;
    }
    dfs(0);
    printf("%d\n", ans);
    return 0;
}















