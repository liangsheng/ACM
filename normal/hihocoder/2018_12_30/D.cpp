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

const int N = 105, M = 14;

int n, m;
LL f[M];
vi ans;

void init() {
    f[1] = 1;
    f[0] = 1;
    FOR (i, 2, M - 1) f[i] = f[i - 1] * i;
}

bool ok(int x, int y, int k) {
    if (x >= 13 || y >= 13) return 1;
    return f[x] * f[y] >= k;
}

void dfs(vi a, int m) {
    int sz = a.size();
    if (sz == 0) return ;
    int d[2] = {0, 0};
    repit (it, a) d[*it % 2]++;
    int pre = -1;
    if (ans.size() != 0) pre = ans[ans.size() - 1];
    rep (i, sz) {
        int t = a[i] % 2;
        d[t]--;
        if (pre % 2 == a[i] % 2) continue;
        if (abs(d[0] - d[1]) > 1) {
            d[t++];
            continue;
        }
        // printf("a[i]= %d %d %d\n", a[i], d[0], d[1]);

        if (ok(d[0], d[1], m)) {
            ans.pb(a[i]);
            a.erase(a.begin() + i);
            dfs(a, m);
            return ;
        } 
        // cout << f[d[0]] << ' ' << f[d[1]] << '\n';
        LL cnt = f[d[0]] * f[d[1]];
        // printf("cnt= %lld\n", cnt);
        m -= cnt;
        d[t]++;
    }
}

int main() {
    init();
    vi a;
    while (~in2(n, m)) {
        ans.clear(), a.clear();
        rep (i, n) a.pb(i + 1);
        dfs(a, m);
        rep (i, n - 1) printf("%d ", ans[i]);
        printf("%d\n", ans[n - 1]);
    }
    return 0;
}
