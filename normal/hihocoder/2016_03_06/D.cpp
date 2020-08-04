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

const int N = 4 + 5, M = 4 + 5, T = 1005;

int Q, n, m, t, s, tol;
int a[N][M], g[N][M], f[T], x[N * M], y[N * M];
int b[T], c[T];
int ax, ay;

void gao() {
    int cnt = 0, ok = 1, flag, tx, ty;
    FOR (i, 1, n) {
        flag = 0;
        FOR (j, 1, m) {
            g[i][j] = y[cnt++];
            if (c[g[i][j]] != 0) flag = 1;
        }
        if (flag == 0) ok = 0;
    }
    tx = ty = 0;
    FOR (i, 1, n) FOR (j, 1, m) {
        tx += a[i][j] * b[g[i][j]];
        ty += a[i][j] * c[g[i][j]];
    }
    if (tx < s) return ;
    //sc4(tx, ty, ok, ay);
    if (ty > ax) ax = ty, ay = ok;
    else if (ty == ax && ok == 1) ay = 1;
    //sc4(tx, ty, ok, ay);
}

void dfs(int p, int sum) {
    if (sum == tol) {
        copy(x, x + tol, y);
        sort(y, y + tol);
        do {
            //rep (i, tol) cout << y[i] << '\n';puts("FFFF");
            gao();
        } while (next_permutation(y, y + tol));
    } else {
        if (p == t + 1) return ;
        x[sum] = p;
        dfs(p + 1, sum + 1);
        dfs(p + 1, sum);
    }
}

int main() {
    int ans, flag;
    scanf("%d", &Q);
    while (Q--) {
        scanf("%d %d %d %d", &n, &m, &t, &s);
        FOR (i, 1, n) FOR (j, 1, m) scanf("%d", &a[i][j]);
        FOR (i, 1, t) scanf("%d", &b[i]);
        FOR (i, 1, t) scanf("%d", &c[i]);
        tol = n * m, ax = -1, ay = 0;
        //sc(tol);
        dfs(1, 0);
        if (ax == -1) puts("Not Exist");
        else {
            printf("%d\n", ax);
            if (ay == 0) puts("No");
            else puts("YES");
        }
    }
    return 0;
}













