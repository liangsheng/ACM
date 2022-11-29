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

const int N = 100005;

int T, n, m;
char s[N];

int gao() {
    int sum = 0, ans = 0, id = -1;
    rep (i, n) sum += (s[i] == 'L');
    if (m >= sum) return n * 2 - 1;

    rep (i, n) if (s[i] == 'W') {
        id = i;
        break;
    }
    if (id == -1) {
        if (m == 0) return 0;
        return m * 2 - 1;
    }

    // printf("id= %d\n", id);
    vi t;
    FOR (i, id, n - 1) {
        if (s[i] == 'W') {
            ans += (i > 0 && (s[i - 1] == 'W')) ? 2 : 1;
            continue;
        }
        int j = i;
        while (i + 1 < n && s[i + 1] == 'L') i++;
        // printf("j= %d %d\n", j, i);
        if (i != n - 1) t.pb(i - j + 1);
    }
    // printf("ans= %d %d\n", ans, t[0]);
    sort(ALL(t));
    repit (it, t) {
        int x = *it;
        if (m >= x) ans += 2 * x + 1, m -= x;
        else break;
    }
    // printf("m= %d\n", m);
    ans += m * 2;
    return ans;
}

int main() {
    in(T);
    while (T--) {
        in2(n, m);
        scanf("%s", s);
        printf("%d\n", gao());
    }
    return 0;
}
