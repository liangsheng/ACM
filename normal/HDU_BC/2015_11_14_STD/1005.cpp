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

const int N = 15;

int T, n, m, ans;
char g[N][N];
int f[N][N];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int a[N][N], e[N], h[N], d[N][N];
queue<pii> q;
vi b;

void bfs(int x, int y) {
    int id = g[x][y] - '0', u, v;
    e[id] = 0, q.push(mp(x, y)), b.pb(id);
    f[x][y] = 1;
    while (!q.empty()) {
        x = q.front().X, y = q.front().Y, q.pop();
        //sc2(x, y);
        rep (i, 4) {
            u = x + dx[i], v = y + dy[i];
            //sc2(u, v);
            if (u < 0 || u >= n || v < 0 || v >= m) continue;
            if (g[u][v] != '.' && g[u][v] - '0' != id) a[id][e[id]++] = g[u][v] - '0';
            if (g[u][v] - '0' == id && !f[u][v]) f[u][v] = 1, q.push(mp(u, v));
        }
    }
    sort(a[id], a[id] + e[id]);
    e[id] = unique(a[id], a[id] + e[id]) - a[id];
}

int gao(int x, int y) {
    int ans = 0, tol = 0;
    q.push(mp(x, y));
    d[x][y] = 2;
    //while (!q.empty()) cout << q.front().X << ' ' << q.front().Y << '\n', q.pop();
    while (!q.empty()) {
        x = q.front().X, y = q.front().Y, q.pop();
        tol++;
        //sc2(x, y);
        //sc(q.size());
        ans += d[x][y] == 2;
        rep (i, 4) {
            int u = x + dx[i], v = y + dy[i];
            //sc2(u, v);
            if (u < 0 || u >= n || v < 0 || v >= m) continue;
            if (d[u][v]) continue;
            //sc2(u, v);
            d[u][v] = d[x][y] ^ 1;
            q.push(mp(u, v));
        }
    }
    //puts("CVCVCC");
    //sc4(x, y, ans, tol);
    return max(ans, tol - ans);
}

int solve() {
    int ans = 0;
    memset(d, 0, sizeof(d));
    rep (i, n) rep (j, m) {
        if (g[i][j] == '.') {
            rep (k, 4) {
                int u = i + dx[k], v = j + dy[k];
                if (u < 0 || u >= n || v < 0 || v >= m) continue;
                if (g[u][v] != '.' && h[g[u][v] - '0']) {
                    d[i][j] = 1;
                    break;
                }
            }
        } else d[i][j] = 1;
    }
    //rep (i, n) {
    ////    rep (j, m) cout << d[i][j];
    //    cout << '\n';
   //}
    rep (i, n) rep (j, m) {
        if (d[i][j]) continue;
        ans += gao(i, j);
    }
    //sc(ans);
    return ans;
}

void dfs(int p, int val) {
    if (p == b.size()) {
       // repit (it, b) cout << *it << ' ' << h[*it] << '\n'; system("pause");
        int tmp = val + solve();
        ans = max(ans, tmp);
        return ;
    }
    if (h[b[p]] != -1) dfs(p + 1, val);
    else {
        h[b[p]] = 0;
        dfs(p + 1, val);

        h[b[p]] = 1;
        //sc2(b[p], h[0]);
        rep (i, e[b[p]]) if (a[b[p]][i] > b[p]) h[a[b[p]][i]] = 0;
        dfs(p + 1, val + 1);

        h[b[p]] = -1;
        rep (i, e[b[p]]) if (a[b[p]][i] > b[p]) h[a[b[p]][i]] = -1;
    }

}

int main() {
    int cas = 0;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        rep (i, n) scanf("%s", g[i]);
        memset(f, 0, sizeof(f));
        b.clear();
        rep (i, n) rep (j, m) {
            if (g[i][j] == '.') continue;
            if (f[i][j]) continue;
            //sc3(i, j, g[i][j]);
            bfs(i, j);
        }
        sort(ALL(b));
//        rep (i, 10) {
//            if (e[i] == 0) continue;
//            cout << "i= " << i << ' ' << e[i] << '\n';
//            rep (j, e[i]) cout << a[i][j] << ' ';
//            cout << '\n';
//        }
        memset(h, -1, sizeof(h));
        ans = 0;
        dfs(0, 0);
        printf("Case #%d: %d\n", ++cas, ans);
    }
    return 0;
}
