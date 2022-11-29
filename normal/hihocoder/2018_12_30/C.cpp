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

const int N = 100005, M = 1000005;

int n;
vpii a, b;

int main() {
    char L, R;
    int x, y, l, r;
    while (~in(n)) {
        a.clear();
        rep (i, n) {
            L = getchar();
            while (L != '(' && L != '[') L = getchar();
            scanf("%d, %d", &x, &y);
            R = getchar();
            while (R != ')' && R != ']') R = getchar();
            x *= 2, y *= 2;
            if (L == '(') x++;
            if (R == ')') y--;
            a.pb(mp(x, y));
        }
        sort(ALL(a));
        // repit (it, a) cout << it->X << ' ' << it->Y << '\n';
        b.clear();
        l = a[0].X, r = a[0].Y;
        FOR (i, 1, n - 1) {
            x = a[i].X, y = a[i].Y;
            // printf("bb %d %d %d %d\n", l, r, x, y);
            if (y <= r) continue;
            else if (x > r + 1) {
                // printf("l= %d %d\n", l, r);
                b.pb(mp(l, r));
                l = x, r = y;
            } else {
                r = y;
            }
        }
        b.pb(mp(l, r));
        cout << b.size() << '\n';
        repit (it, b) {
            x = it->X, y = it->Y;
            if (x % 2) L = '(', x /= 2;
            else L = '[', x /= 2;
            if (y % 2) R = ')', y = y / 2 + 1;
            else R = ']', y /= 2;
            printf("%c%d, %d%c\n", L, x, y, R);
        }
    }
    return 0;
}
