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

const int N = 200005;

int n, e;
int a[3], b[3];
multiset<int> s;
multiset<int> :: iterator it, l, r;

int main() {
    int ans, flag, x, sum, d, y;
    while (~scanf("%d", &n)) {
        e = ans = 0, flag = 1, s.clear();
        rep (i, 3) scanf("%d", &a[i]);
        b[0] = a[0] + a[1], b[1] = a[0] + a[2], b[2] = a[1] + a[2];
        sort(a, a + 3);
        sort(b, b + 3);
        sum = a[0] + a[1] + a[2];
        rep (i, n) {
            scanf("%d", &x);
            if (x > sum) flag = 0;
            else if (x > b[2]) ans++;
            else s.insert(x);
        }
        if (!flag) {
            puts("-1");
            continue;
        }
        while (!s.empty()) {
            it = s.end(), it--, x = *it;
            ans++, s.erase(it);
            if (s.empty()) break;
            if (x > a[2]) {
                d = b[lower_bound(b, b + 3, x) - b];
                rep (i, 3) if (a[i] + d == sum) {
                    y = a[i];
                    break;
                }
                it = s.upper_bound(y);
                if (it != s.begin()) it--, s.erase(it);
            } else {
                d = a[lower_bound(a, a + 3, x) - a];
                if (d == a[0]) x = a[1], y = a[2];
                else if (d == a[1]) x = a[0], y = a[2];
                else if (d == a[2]) x = a[0], y = a[1];
                l = s.upper_bound(x);
                r = s.upper_bound(y);
                if (l != s.begin() && r != s.begin() && SZ(s) >= 2) {
                    if (l == r) l--;
                    if (l == s.begin()) {
                        l = s.upper_bound(x + y);
                        if (l != s.begin()) l--, s.erase(l);
                    } else {
                        l--, r--;
                        s.erase(l), s.erase(r);
                    }
                } else {
                    l = s.upper_bound(x + y);
                    if (l != s.begin()) l--, s.erase(l);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
