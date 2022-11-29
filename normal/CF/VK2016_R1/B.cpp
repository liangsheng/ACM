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

const int N = 200005, M = 60;

int n, m, ans;
int a[N];
int b[2][M + 5], c[2][M + 5];

void gao(int x, int c, int id) {
    LL y = x;
    rep (i, M) {
        if ((y >> i) & 1) {
            b[id][c + i]++;
        }
    }
}

void cal(int p) {
    int l = 0;
    LL t, tmp;
    rep (k, 2) rep (i, M) {
        c[k][i] += l;
        l = c[k][i] / 2;
        c[k][i] %= 2;
    }
    rep (i, M) c[1][i] ^= 1;
    l = 1;
    rep (i, M - 1) {
        c[1][i] += l;
        l = c[1][i] / 2;
        c[1][i] %= 2;
    }
    l = 0;
    rep (i, M) {
        c[0][i] += l + c[1][i];
        l = c[0][i] / 2;
        c[0][i] %= 2;
    }
    if (c[0][M - 1] == 1) {
        rep (i, M - 1) c[0][i] ^= 1;
        l = 1;
        rep (i, M - 1) {
            c[0][i] += l;
            l = c[0][i] / 2;
            c[0][i] %= 2;
        }
    }
    t = 1, tmp = 0;
    rep (i, p) if (c[0][i]) return ;
    FOR (i, p, M - 1) {
        if (c[0][i]) tmp += t;
        if (tmp > m) break;
        t <<= 1;
    }
    if (tmp <= (LL) m && tmp != 0) ans++;
}

int main() {
    LL x;
    while (~scanf("%d %d", &n, &m)) {
        n++;
        rep (i, n) scanf("%d", &a[i]);
        memset(b, 0, sizeof(b));
        rep (i, n) {
            if (a[i] > 0) gao(a[i], i, 0);
            else gao(-a[i], i, 1);
        }
        ans = 0;
        rep (i, n) {
            rep (k, 2) rep (j, M) c[k][j] = b[k][j];
            if (a[i] > 0) {
                x = a[i];
                rep (j, M) {
                    if ((x >> j) & 1) c[1][j + i]++;
                }
            } else {
                x = -a[i];
                rep (j, M) {
                    if ((x >> j) & 1) c[0][j + i]++;
                }
            }
            cal(i);
        }
        printf("%d\n", ans);
    }
    return 0;
}
