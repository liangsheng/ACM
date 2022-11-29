#include <bits/stdc++.h>
#include <fstream>

#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)
#define rep(i, n) for (int i = 0; i < n; i++)
#define FOR(i, n, m) for (int i = n; i <= m; i++)
#define repe(i, u) for (int i = head[u]; ~i; i = nxt[i])
#define FORD(i, n, m) for (int i = n; i >= m; i--)
#define repit(i, c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define pause cout << " press ant key to continue...", cin >> chh

#define pb push_back
#define mp make_pair
#define ins insert
#define X first
#define Y second
#define be begin
#define nb rbegin
#define er erase
#define SZ(c) c.size()
#define sqr(x) ((x) * (x))

#define sc(n) cout << #n << "= " << n, system("pause")
#define sc2(n, m) cout << #n << "= " << n << " " << #m << "= " << m, system("pause")
#define sc3(n, m, k) cout << #n << "= " << n << " " << #m << "= " << m << " " << #k << "= " << k, system("pause")
#define sc4(n, m, k, b) cout << #n << "= " << n << " " << #m << "= " << m << " " << #k << "= " << k << " " << #b << "= " << b, system("pause")

using namespace std;
int chh;

typedef long long LL;

const int N = 105;

int T, n, m, Q;
int g[N][N];
bool f[N][N];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
queue< pair<int, int> > q;

void bfs(int x, int y) {
    int u, v;
    q.push(mp(x, y));
    while (!q.empty()) {
        u = q.front().X, v = q.front().Y, q.pop();
        f[u][v] = 1;
        rep (k, 4) {
            x = u + dx[k], y = v + dy[k];
            if (x < 0 || x >= n || y < 0 || y >= m) continue;
            if (f[x][y] || g[x][y] == 0) continue;
            q.push(mp(x, y));
        }
    }
}

int main() {
    file_r("A-large.in");
    file_w("out.txt");
    char cmd[10];
    char s[N];
    int cas = 0, x, y, val, ans;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        rep (i, n) {
            scanf("%s", s);
            rep (j, m) g[i][j] = (s[j] == '1');
        }
        scanf("%d", &Q);
        printf("Case #%d:\n", ++cas);
        while (Q--) {
            scanf("%s", cmd);
            if (cmd[0] == 'M') {
                scanf("%d %d %d", &x, &y, &val);
                g[x][y] = val;
            } else {
                ans = 0;
                memset(f, 0, sizeof(f));
                rep (i, n) rep (j, m) {
                    if (f[i][j]) continue;
                    if (g[i][j] == 0) continue;
                    ans++;
                    bfs(i, j);
                }
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}


















