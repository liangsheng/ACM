#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>

#define all(c) (c).begin(), c.end();
#define sz(c) (c).size()
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define X first
#define Y second
#define vi vector < int >
#define pii pair < int, int >
#define LL long long
#define mem(v, i) memset(v, i, sizeof(v))
#define rep(i, a) for (int i = 0; i <= (a); i++)
#define repu(i, a, b) for (int i = (a); i <= (b); i++)
#define repd(i, a, b) for (int i = (a); i >= (b); i--)
#define repit(it, v) for (typeof(v.begin()) it = v.begin(); it != v.end(); it++)
#define repitd(it, v) for (typeof(v.rbegin()) it = v.rbegin(); it != v.rend(); it++)
#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)
#define pause cout << " press any key to continue...",  cin >> chh

using namespace std;
int chh;

inline void in(LL &t) {
    LL n = 0, s = 1;
    char ch = getchar();
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-') s = -1, ch = getchar();
    while (ch >= '0' && ch <= '9') n = n * 10 + ch - '0', ch = getchar();
    t = n * s;
}

inline void in2(LL &x, LL &y) { in(x), in(y); }

const int N = 100, INF = 100;

LL n, m;
LL p[N][N], f[N][N];

int main() {
    LL u, v, maxi, tmp;
    double ans;
    while (cin >> n >> m) {
        rep (i, n - 1) {
            rep (j, n - 1) {
                f[i][j] = INF, p[i][j] = 1;
            }
            f[i][i] = 0;
        }
        rep (i, m - 1) {
            in(u), in(v);
            u--, v--;
            f[u][v] = f[v][u] = 1;
        }
        rep (k, n - 1) rep (i, n - 1) rep (j, n - 1) {
            if (i == j || i == k || j == k) continue;
            if (f[i][k] + f[k][j] < f[i][j]) {
                f[i][j] = f[i][k] + f[k][j];
                p[i][j] = p[i][k] * p[k][j];
            } else if (f[i][k] + f[k][j] == f[i][j]) p[i][j] += p[i][k] * p[k][j];
        }
        ans = 1.0;
        repu (k, 1, n - 2) {
            if (f[0][k] + f[k][n - 1] != f[0][n - 1]) continue;
            tmp = p[0][k] * p[k][n - 1] * 2;
            ans = max(ans, (double) tmp / p[0][n - 1]);
        }
        printf("%.12lf\n", ans);
    }
    return 0;
}
