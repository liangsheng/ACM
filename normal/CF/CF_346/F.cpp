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

const int N = 1005;

int n, m;
LL k, cnt;
int g[N][N];
pii a[N * N];
bool f[N][N];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pii> q;

void bfs(int u, int v, int val) {
    int x, y;
    f[u][v] = 1, cnt++;
    q.push(mp(u, v));
    while (!q.empty()) {
        u = q.front().X, v = q.front().Y, q.pop();
        rep (i, 4) {
            x = u + dx[i], y = v + dy[i];
            if (x < 0 || x >= n || y < 0 || y >= m) continue;
            if (g[x][y] < val) continue;
            q.push(mp(x, y)), cnt++;
        }
    }
}

int main() {
    int id, x, y, flag;
    while (cin >> n >> m >> k) {
        rep (i, n) rep (j, m) {
            scanf("%d", &g[i][j]);
            id = i * m + j;
            a[id] = mp(-g[i][j], id);
        }
        sort(a, a + n * m);
        memset(f, 0, sizeof(f));
        cnt = 0, falg = 0;
        rep (th, n * m) {
            id = a[th].Y, x = id / m, y = id % m;
            bfs(x, y, g[x][y]);
            if (k % g[x][y]) continue;
            if (cnt >= (k / g[x][y])) {
                flag = 1;
                break;
            }
        }
    }
    return 0;
}














