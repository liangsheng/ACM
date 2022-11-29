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

const int N = 300005;

int T, n, m;
char s[N];

bool gao() {
    vi c[3];
    rep (j, m) {
        c[0].clear(), c[1].clear(), c[2].clear();
        for (int i = j; i < n; i += m) {
            if (s[i] == '0') c[0].pb(i);
            else if (s[i] == '1') c[1].pb(i);
            else c[2].pb(i);
        }
        // printf("j= %d %d %d\n", j, c[0].size(), c[1].size());
        if (!c[0].empty() && !c[1].empty()) return 0;
        if (c[0].size() > 0) {
            repit (it, c[2]) s[*it] = '0';
        } else if (c[1].size() > 0) {
            repit (it, c[2]) s[*it] = '1';
        }
    }
    // puts("Hello");
    int c0 = 0, c1 = 0;
    c[2].clear();
    rep (i, m) {
        if (s[i] == '0') c0++;
        else if (s[i] == '1') c1++;
        else c[2].pb(i);
    }
    if (c0 > c1 + c[2].size()) return 0;
    if (c1 > c0 + c[2].size()) return 0;
    return 1;
}

int main() {
    in(T);
    while (T--) {
        in2(n, m);
        scanf("%s", s);
        puts(gao() ? "YES" : "NO");
    }
    return 0;
}
