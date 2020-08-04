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

const int N = 1005;

int n;
int a[N][N];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int bfs() {
    int x, y, u, v, ans = 0;
    queue<pii> q;
    FOR (i, 1, n) FOR (j, 1, n) {
        if (a[i][j] != -1) q.push(mp(i, j));
    }
    while (!q.empty()) {
        x = q.front().X, y = q.front().Y, q.pop();
        rep (k, 4) {
            u = x + dx[k], v = y + dy[k];
            // printf("u= %d %d %d\n", u, v, a[u][v]);
            if (u == 0 || u == n + 1 || v == 0 || v == n + 1) continue;
            if (a[u][v] != -1) continue;
            a[u][v] = a[x][y] + 1;
            
            // pause;
            q.push(mp(u, v));
            ans = max(ans, a[u][v]);
        }
    }
    return ans;
}

int main() {
    char ch;
    while (~in(n)) {
        memset(a, -1, sizeof(a));
        FOR (i, 1, n) FOR (j, 1, n) {
            ch = getchar();
            while (ch != '0' && ch != '1') ch = getchar();
            if (ch == '0') a[i][j] = 0;
        }
        // FOR (i, 1, n) {
        //     FOR (j, 1, n) cout << a[i][j] << ' ';
        //     cout << '\n';
        // }
        cout << bfs() << '\n';
    }
    return 0;
}
