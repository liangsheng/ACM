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

int T;
pii p[4], a[3], b[3];

bool ok() {
    bool flag = 0;
    rep (i, 8) {
        rep (j, 3) {
            if ((i >> j) & 1) swap(a[j].X, a[j].Y);
        }
        if (a[0].X == a[1].X && a[1].X == a[2].X) return 1;
        if (a[0].Y == a[1].Y && a[1].Y == a[2].Y) return 1;
        if (a[0].X == a[1].X && a[0].Y + a[1].Y == a[2].Y) return 1;
        if (a[0].Y == a[1].Y && a[0].X + a[1].X == a[2].X) return 1;
    }
    return 0;
}

int main() {
    int flag, e;
    scanf("%d", &T);
    while (T--) {
        rep (i, 4) scanf("%d %d", &p[i].X, &p[i].Y);
        flag = 0;
        rep (i, 4) {
            e = 0;
            rep (j, 4) {
                if (j == i) continue;
                b[e++] = p[j];
            }
            a[0] = b[0], a[1] = b[1], a[2] = b[2];
            if (ok()) {
                flag = 1;
                break;
            }

            a[0] = b[0], a[1] = b[2], a[2] = b[1];
            if (ok()) {
                flag = 1;
                break;
            }

            a[0] = b[1], a[1] = b[0], a[2] = b[2];
            if (ok()) {
                flag = 1;
                break;
            }

            a[0] = b[1], a[1] = b[2], a[2] = b[0];
            if (ok()) {
                flag = 1;
                break;
            }

            a[0] = b[2], a[1] = b[0], a[2] = b[1];
            if (ok()) {
                flag = 1;
                break;
            }

            a[0] = b[2], a[1] = b[1], a[2] = b[0];
            if (ok()) {
                flag = 1;
                break;
            }
        }
        puts(flag ? "Yes" : "No");
    }
    return 0;
}





















