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

int n, h0, h1, c0, c1, h, c, e;
char cmd[N];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
string s = "NESW";
int g[N][N][4];
int f[N][N];
queue<pii> q;

void dfs(int x, int y, int val) {
    int u, v;
    f[x][y] = val;
    q.push(mp(x, y));
    while (!q.empty()) {
        x = q.front().X, y = q.front().Y, q.pop();
        rep (i, 4) {
            if (g[x][y][i] > 0) continue;
            u = x + dx[i], v = y + dy[i];
            if (u < 1 || u > h || v < 1 || v > c) continue;
            if (!f[u][v]) f[u][v] = val, q.push(mp(u, v));
        }
    }
}

#define typec int // type of cost
const typec inf = 0x3f3f3f3f; // max of cost
int vis[N];
typec lowc[N];
typec prim(typec cost[][N], int n) { // vertex: 0 ~ n-1
    int i, j, p;
    typec minc, res = 0;
    memset(vis, 0, sizeof(vis));
    vis[0] = 1;
    for (i=1; i<n; i++) lowc[i] = cost[0][i];
    for (i=1; i<n; i++) {
        minc = inf;
        p = -1;
        for (j=0; j<n; j++)
            if (0 == vis[j] && minc > lowc[j]) {
                minc = lowc[j];
                p = j;
            }
        if (inf == minc) return -1; //  原图不连通
        res += minc;
        vis[p] = 1;
        for (j=0; j<n; j++)
            if (0 == vis[j] && lowc[j] > cost[p][j])
                lowc[j] = cost[p][j];
    }
    return res;
}

int cost[N][N];

int main() {
    //file_r("gates.in");
    //file_w("gates.out");
    int x = 0, y = 0, x0, y0, id, ans, u, v;
    scanf("%d %s", &n, cmd);
    h0 = h1 = c0 = c1 = 0;
    rep (i, n) {
        rep (j, 4) if (cmd[i] == s[j]) id = j;
        x += dx[id], y += dy[id];
        h0 = min(h0, x), h1 = max(h1, x);
        c0 = min(c0, y), c1 = max(c1, y);
    }
    h = h1 - h0 + 10 , c = c1 - c0 + 10;
    x = 0 - h0, y = 0 - c0, x += 2, y += 2;
    x0 = x, y0 = y;
    //sc4(x, y, h0, c0);
    rep (i, n) {
        rep (j, 4) if (cmd[i] == s[j]) id = j;

        if (id == 0) {
            g[x - 1][y - 1][1]++;
            g[x - 1][y][3]++;
        } else if (id == 1) {
            g[x - 1][y][2]++;
            g[x][y][0]++;
        } else if (id == 2) {
            g[x][y - 1][1]++;
            g[x][y][3]++;
        } else {
            g[x - 1][y - 1][2]++;
            g[x][y - 1][0]++;
        }

        x += dx[id], y += dy[id];
        //sc2(x, y);
    }
    //sc(g[1][6][2]);
    //sc4(x, y, h, c);
    e = 0;
    FOR (i, 1, h - 1) FOR (j, 1, c - 1) {
        if (f[i][j]) continue;
        //sc2(i, j);
        dfs(i, j, ++e);
    }
    if (e == 1) {
        printf("%d", 0);
        return 0;
    }
    rep (i, e) {
        rep (j, e) cost[i][j] = inf;
        cost[i][i] = 0;
    }

    x = x0, y = y0;
    rep (i, n) {
        rep (j, 4) if (cmd[i] == s[j]) id = j;

        if (id == 0) {
            u = f[x - 1][y - 1] - 1, v = f[x - 1][y] - 1;
            cost[u][v] = min(cost[u][v], g[x - 1][y - 1][1]);
            cost[v][u] = cost[u][v];
        } else if (id == 1) {
            u = f[x - 1][y] - 1, v = f[x][y] - 1;
            cost[u][v] = min(cost[u][v], g[x - 1][y][2]);
            cost[v][u] = cost[u][v];
        } else if (id == 2) {
            u = f[x][y - 1] - 1, v = f[x][y] - 1;
            cost[u][v] = min(cost[u][v], g[x][y - 1][1]);
            cost[v][u] = cost[u][v];
        } else {
            u = f[x - 1][y - 1] - 1, v = f[x][y - 1] - 1;
            cost[u][v] = min(cost[u][v], g[x - 1][y - 1][2]);
            cost[v][u] = cost[u][v];
        }
        if (u == v) continue;
        //sc2(u, v);

        x += dx[id], y += dy[id];
        //sc2(x, y);
    }
//    rep (i, e) {
//        rep (j, e) cout << cost[i][j] << ' ';
//        cout << '\n';
//    }
    ans = prim(cost, e);
    printf("%d\n", ans);
    return 0;
}
