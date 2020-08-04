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

const int N = 105;

int n;
int a[N][N], f[N][N];

void init() {
    memset(f, 0, sizeof(f));
    FOR (i, 1, n) FOR (j, 1, n) {
        f[i][j] = a[i][j] + f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
    }
}

int cal(int x1, int y1, int x2, int y2) {
    return f[x2][y2] - f[x2][y1 - 1] - f[x1 - 1][y2] + f[x1 - 1][y1 - 1];
}

int gao() {
    int ans = n * n;
    FOR (k, 2, n) {
        FOR (i, 1, n - k + 1) FOR (j, 1, n - k + 1) {
            int tmp = cal(i, j, i, j + k - 1), flag = 1;
            rep (x, k) {
                if (cal(i + x, j, i + x, j + k - 1) != tmp) {
                    flag = 0;
                    break;
                }
                if (cal(i, j + x, i + k - 1, j + x) != tmp) {
                    flag = 0;
                    break;
                }
            }
            if (!flag) continue;
            int y = 0;
            rep (x, k) y += a[i + x][j + x];
            if (y != tmp)  continue;
            y = 0;
            rep (x, k) y += a[i + k - 1 - x][j + x];
            if (y != tmp) continue;
            ans++;
        }
    }
    return ans;
}

int main() {
    while (~in(n)) {
        rep (i, n) rep (j, n) in(a[i + 1][j + 1]);
        init();
        printf("%d\n", gao());
    }
    return 0;
}
