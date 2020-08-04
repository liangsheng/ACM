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

int T;
int x[3];

int main() {
    int ans, tmp;
    int c[3];
    vi a[7];
    vi b0;
    b0.pb(0); a[0] = b0;
    vi b1;
    b1.pb(1); a[1] = b1;
    vi b2;
    b2.pb(2); a[2] = b2;
    vi b3;
    b3.pb(0); b3.pb(1); a[3] = b3;
    vi b4;
    b4.pb(0); b4.pb(2); a[4] = b4;
    vi b5;
    b5.pb(1); b5.pb(2); a[5] = b5;
    vi b6;
    b6.pb(0); b6.pb(1); b6.pb(2); a[6] = b6;

    in(T);
    while (T--) {
        in3(x[0], x[1], x[2]);

        ans = 0;
        for (int st = 0; st < (1 << 7); st++) {
            tmp = 0;
            c[0] = c[1] = c[2] = 0;
            rep (i, 7) if ((st >> i) & 1) {
                repit (it, a[i]) c[*it]++;
                tmp++;
            }
            if (c[0] <= x[0] && c[1] <= x[1] && c[2] <= x[2]) {
                ans = max(ans, tmp);
                // printf("st= %d %d\n", st, tmp);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
