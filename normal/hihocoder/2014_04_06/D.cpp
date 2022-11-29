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

const int N = 105, D = 101, M = 100005;

int T, n, mx, my, mz, maxi;
bool f[N][N][N], g[N][N][N];
int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};
int px[M], py[M], pz[M];

bool ok(int x) {
    return x >= 0 && x <= maxi;
}

bool ok(int x, int y, int z) {
    if (z == 1) return 1;
    //if (x == 2 && y == 1 && z == 2) puts("FFFf"), sc(f[2][1][1]);
    int u, v, w;
    rep (i, 6) {
        u = x + dx[i], v = y + dy[i], w = z + dz[i];
        //if (x == 2 && y == 1 && z == 2) sc4(u, v, w, f[u][v][w]), sc4(ok(u), ok(v), ok(w), f[u][v][w]);
        if (f[u][v][w]) return 1;
    }
    return 0;
}

struct Node {
    int x, y, z;
    Node() {}
    Node(int X, int Y, int Z): x(X), y(Y), z(Z) {}
};

queue<Node> q;

void bfs() {
    int x, y, z;
    Node t;
    g[mx][my][mz] = 1;
    q.push(Node(mx, my, mz));
    while (!q.empty()) {
        t = q.front(), q.pop();
        rep (i, 6) {
            x = t.x + dx[i];
            y = t.y + dy[i];
            z = t.z + dz[i];
            if (ok(x) && ok(y) && ok(z) && !g[x][y][z] && !f[x][y][z]) {
                g[x][y][z] = 1;
                q.push(Node(x, y, z));
            }
        }
    }
}

int main() {
    int x, y, z;
    bool flag, t;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        memset(f, 0, sizeof(f));
        flag = 1, mx = my = mz = -1;
        rep (i, n) {
            scanf("%d %d %d", &x, &y, &z);
            f[x][y][z] = 1;
            px[i] = x, py[i] = y, pz[i] = z;
            mx = max(x, mx);
            my = max(y, my);
            mz = max(z, mz);
            if (!ok(x, y, z)) flag = 0;
            //cout << "flag= " << flag << '\n';
        }
        if (flag) {
            memset(g, 0, sizeof(g));
            mx++, my++, mz++;
            maxi = max(mx, max(my, mz));
            //sc4(mx, my, mz, maxi);
            bfs();
            rep (i, n) {
                t = 0;
                rep (k, 6) {
                    x = px[i] + dx[k];
                    y = py[i] + dy[k];
                    z = pz[i] + dz[k];
                    if (g[x][y][z]) {
                        t = 1;
                        break;
                    }
                }
                if (t == 0) {
                    flag = 0;
                    sc3(px[i], py[i], pz[i]);
                    break;
                }
            }
        }
        puts(flag ? "Yes" : "No");
    }
    return 0;
}












