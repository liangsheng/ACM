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

int n;
int sz[N], id[N], f[N];
string s[N];
map<string, vector<string> > q;

bool ok(int i, int j) {
    return s[i].substr(0, id[i]) == s[j].substr(0, id[j]);
}

int main() {
    int ans = 0;
    string tmp;
    cin >> n;
    rep (i, n) {
        cin >> s[i];
        s[i] = s[i].substr(7);
    }
    sort(s, s + n);
    n = unique(s, s + n) - s;
    rep (i, n) {
        sz[i] = SZ(s[i]);
        id[i] = s[i].find('/');
        if (id[i] == -1) id[i] = sz[i];
        f[i] = sz[i] - id[i];
    }
    //puts("");
    //rep (i, n) cout << i << ' ' << s[i] << '\n';
    rep (i, n) {
        tmp = s[i].substr(id[i], f[i]);
        //sc2(i, id[i]);
        while (i + 1 < n && ok(i, i + 1)) {
            i++;
            tmp += "#" + s[i].substr(id[i], f[i]);
        }
        q[tmp].pb(s[i].substr(0, id[i]));
        //sc2(tmp, s[i].substr(0, id[i]));
    }
    repit (it, q) {
        if (SZ(it->Y) >= 2) ans++;
    }
    cout << ans << '\n';
    repit (it, q) {
        if (SZ(it->Y) < 2) continue;
        repit (i, it->Y) cout << "http://" + *i << ' ';
        cout << '\n';
    }
    return 0;
}
