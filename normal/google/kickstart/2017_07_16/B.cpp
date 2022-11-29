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

const int N = 55, M = 1005;

int T, R, C, ans;
int h[N][N];
bool g[M][N][N];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int k, int x, int y) {
    //sc3(k, x, y);
    int u, v;
    g[k][x][y] = 1;
    ans++;
    rep (i, 4) {
        u = x + dx[i];
        v = y + dy[i];
        if (u < 1 || u > R || v < 1 || v > C) continue;
        if (h[u][v] >= k) continue;
        if (g[k][u][v] == 1) continue;
        dfs(k, u, v);
    }
}

int main() {
    file_r("B-large.in");
    file_w("B-large.out");
    int cas = 0, t, sum;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &R, &C);
        t = 0, sum = 0;
        FOR (i, 1, R) FOR (j, 1, C) {
            scanf("%d", &h[i][j]);
            t = max(t, h[i][j]);
            sum += h[i][j];
        }
        memset(g, 0, sizeof(g));
        ans = 0;
        FORD (k, t, 1) {
            FOR (j, 1, C) {
                if (g[k][1][j] == 1) continue;
                if (h[1][j] < k) {
                    dfs(k, 1, j);
                }
            }

            FOR (j, 1, C) {
                if (g[k][R][j] == 1) continue;
                if (h[R][j] < k) {
                    dfs(k, R, j);
                }
            }

            FOR (i, 1, R) {
                if (g[k][i][1] == 1) continue;
                if (h[i][1] < k) {
                    dfs(k, i, 1);
                }
            }

            FOR (i, 1, R) {
                if (g[k][i][C] == 1) continue;
                if (h[i][C] < k) {
                    dfs(k, i, C);
                }
            }
        }
        printf("Case #%d: %d\n", ++cas, R * C * t - ans - sum);
    }
    return 0;
}



















