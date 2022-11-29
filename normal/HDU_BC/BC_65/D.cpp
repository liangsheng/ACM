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

const int N = 500005, M = N * 2;

int T, n, e, K, A, B;
int head[N], pnt[M], nxt[M], f[N];
int dp[N][15], a[15];

void init() {
    e = 0;
    memset(head, -1, sizeof(head));
}

void add(int u, int v) {
    pnt[e] = v, nxt[e] = head[u], head[u] = e++;
}

void dfs(int p, int fa) {
    int v;
    dp[p][0] = 1;
    FOR (i, 1, K) dp[p][i] = 0;
    repe (i, p) {
        v = pnt[i];
        if (v == fa) continue;
        dfs(v, p);
        FOR (j, 0, K - 1) dp[p][j + 1] += dp[v][j];
    }
    //printf("p= %d\n", p);
    //FOR (j, 0, K) printf("%d %d\n", j, dp[p][j]); system("pause");
}

void ok(int p, int fa) {
    //sc2(p, fa);
    FOR (i, 0, K) a[i] = dp[fa][i];
    //FOR (i, 0, K) sc2(i, a[i]);
    FOR (i, 0, K - 1) a[i + 1] = a[i + 1] - dp[p][i];
    //FOR (i, 0, K) sc2(i, a[i]);
    FOR (i, 1, K) dp[p][i] += a[i - 1];
    repe (i, p) {
        int v = pnt[i];
        if (v == fa) continue;
        ok(v, p);
    }
    //printf("p= %d\n", p);
    //FOR (j, 0, K) printf("%d %d\n", j, dp[p][j]); system("pause");
}

int main() {
    int ans, v, t;
    scanf("%d", &T);
    while (T--) {
        init();
        scanf("%d %d %d %d", &n, &K, &A, &B);
        f[1] = 0;
        FOR (i, 2, n) {
            f[i] = ((LL) A * i + B) % (i - 1) + 1;
            add(f[i], i), add(i, f[i]);
            //sc2(f[i], i);
        }
        dfs(1, 0);
        //puts(")))");
        repe (i, 1) {
            v = pnt[i];
            ok(v, 1);
        }
        ans = 0;
        FOR (i, 1, n) {
            t = 0;
            FOR (j, 0, K) t += dp[i][j];
            //sc2(i, t);
            ans ^= t;
        }
        printf("%d\n", ans);
    }
    return 0;
}





















