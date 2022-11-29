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

const int N = 505, INF = ~0U >> 2;

int n, m, K, Q;
int B[N], A[N];
bool f[N][N];
bool vis[N][N];
int dis[N][N];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void solve(int x0, int y0, int x1, int y1) {
    int x, y, u, v, d, tmp;
    queue<pii> q;
    FOR (i, 1, n) FOR (j, 1, m) {
        vis[i][j] = 0;
        dis[i][j] = INF;
    }
    vis[x0][y0] = 1, dis[x0][y0] = 0;
    q.push(mp(x0, y0));
    while (!q.empty()) {
        x = q.front().X, y = q.front().Y;
        q.pop(), vis[x][y] = 0;
        //sc3(x, y, dis[x][y]);
        rep (i, 4) {
            u = x + dx[i], v = y + dy[i];
            if (u < 1 || u > n || v < 1 || v > m) continue;
            if (f[u][v]) continue;
            if (u == x - 1) d = B[u];
            else if (u == x + 1) d = B[x];
            else if (v == y - 1) d = A[v];
            else if (v == y + 1) d = A[y];
            tmp = dis[x][y] + d;
            if (tmp < dis[u][v]) {
                dis[u][v] = tmp;
                if (!vis[u][v]) vis[u][v] = 1, q.push(mp(u, v));
            }
        }
    }
    if (dis[x1][y1] == INF) puts("-1");
    else printf("%d\n", dis[x1][y1]);
}

int main() {
    int x, y, u, v;
    while (~scanf("%d %d", &n, &m)) {
        FOR (i, 1, n - 1) scanf("%d", &B[i]);
        FOR (i, 1, m - 1) scanf("%d", &A[i]);
        memset(f, 0, sizeof(f));
        scanf("%d", &K);
        while (K--) {
            scanf("%d %d", &x, &y);
            f[x][y] = 1;
        }
        scanf("%d", &Q);
        while (Q--) {
            scanf("%d %d %d %d", &x, &y, &u, &v);
            solve(x, y, u, v);
        }
    }
    return 0;
}










