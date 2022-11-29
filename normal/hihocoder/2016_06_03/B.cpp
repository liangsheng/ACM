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

const int N = 55;

int n, m, cnt, acnt, scnt;
char g[N][N];
bool f[N][N];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pii> q;
vpii h;

struct Node {
    int h, w, sz;
    bool a[N][N];
};

vector<Node> d;

void bfs(int u, int v) {
    int x, y, s = 0, w0, w1, h0, h1;
    Node tmp;
    w0 = h0 = 55;
    w1 = h1 = -1;
    f[u][v] = 1;
    q.push(mp(u, v));
    h.clear();
    while (!q.empty()) {
        u = q.front().X, v = q.front().Y;
        q.pop();
        h.pb(mp(u, v));
        w0 = min(w0, v), w1 = max(w1, v);
        h0 = min(h0, u), h1 = max(h1, u);
        s++;
        rep (k, 4) {
            x = u + dx[k], y = v + dy[k];
            if (x < 0 || x >= n || y < 0 || y >= m) continue;
            if (g[x][y] == '.') continue;
            if (f[x][y]) continue;
            f[x][y] = 1;
            q.push(mp(x, y));
        }
    }
    tmp.h = h1 - h0 + 1, tmp.w = w1 - w0 + 1, tmp.sz = s;
    rep (i, tmp.h) rep (j, tmp.w) tmp.a[i][j] = 0;
    repit (it, h) tmp.a[it->X - h0][it->Y - w0] = 1;//, sc2(it->X - h0, it->Y - w0);
    d.pb(tmp);
    //sc(tmp.sz);
}

bool ok(int x, int y) {
    Node &u = d[x], &v = d[y];
    if (u.h != v.h || u.w != v.w) return 0;
    rep (i, u.h) rep (j, u.w) if (u.a[i][j] ^ v.a[i][j]) return 0;
    return 1;
}

int main() {
    bool flag;
    while (~scanf("%d %d", &n, &m)) {
        rep (i, n) scanf("%s", g[i]);
        cnt = acnt = scnt = 0;
        memset(f, 0, sizeof(f));
        d.clear();
        rep (i, n) rep (j, m) {
            if (g[i][j] == '.') continue;
            if (f[i][j]) continue;
            bfs(i, j);
        }
        cnt = SZ(d);
        rep (i, cnt) {
            flag = 1;
            rep (j, i) if (d[j].sz == d[i].sz) {
                flag = 0;
                break;
            }
            acnt += flag;
        }
        rep (i, cnt) {
            flag = 1;
            rep (j, i) if (ok(i, j)) {
                flag = 0;
                break;
            }
            scnt += flag;
        }
        printf("%d %d %d\n", cnt, acnt, scnt);
    }
    return 0;
}




















