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
#define dis(x1, y11, x2, y2) (((x1) - (x2)) * ((x1) - (x2)) + ((y11) - (y2)) * ((y11) - (y2)))
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
int x0, x1, y00, y11, z0, z1;

int main() {
    LL s1, s2, s3, s4, s5, s6, s7, s8;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d %d %d", &x0, &x1, &y00, &y11, &z0, &z1);
        if (x1 > 0 && y11 > 0 && z1 > 0) {
            s1 = (LL) min(x1 - 0, x1 - x0) * min(y11 - 0, y11 - y00) * min(z1 - 0, z1 - z0);
        } else s1 = 0;

        if (x0 < 0 && y11 > 0 && z1 > 0) {
            s2 = (LL) min(0 - x0, x1 - x0) * min(y11 - 0, y11 - y00) * min(z1 - 0, z1 - z0);
        } else s2 = 0;

        if (x0 < 0 && y00 < 0 && z1 > 0) {
            s3 = (LL) min(0 - x0, x1 - x0) * min(0 - y00, y11 - y00) * min(z1 - 0, z1 - z0);
        } else s3 = 0;

        if (x1 > 0 && y00 < 0 && z1 > 0) {
            s4 = (LL) min(x1 - 0, x1 - x0) * min(0 - y00, y11 - y00) * min(z1 - 0, z1 - z0);
        } else s4 = 0;

        if (x1 > 0 && y11 > 0 && z0 < 0) {
            s5 = (LL) min(x1 - 0, x1 - x0) * min(y11 - 0, y11 - y00) * min(0 - z0, z1 - z0);
        } else s5 = 0;

        if (x0 < 0 && y11 > 0 && z0 < 0) {
            s6 = (LL) min(0 - x0, x1 - x0) * min(y11 - 0, y11 - y00) * min(0 - z0, z1 - z0);
        } else s6 = 0;

        if (x0 < 0 && y00 < 0 && z0 < 0) {
            s7 = (LL) min(0 - x0, x1 - x0) * min(0 - y00, y11 - y00) * min(0 - z0, z1 - z0);
        } else s7 = 0;

        if (x1 > 0 && y00 < 0 && z0 < 0) {
            s8 = (LL) min(x1 - 0, x1 - x0) * min(0 - y00, y11 - y00) * min(0 - z0, z1 - z0);
        } else s8 = 0;
        cout << s1 << ' ' << s2 << ' ' << s3 << ' ' << s4 << ' ' << s5 << ' ' << s6 << ' ' << s7 << ' ' << s8 << '\n';
    }
    return 0;
}





























