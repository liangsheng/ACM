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

const int NODE = 1005;
const int CH = 4;

int e;
int chd[NODE][CH];
int work[NODE];
int fail[NODE];
int q[NODE];
map<char, int> sw;

void init() {
    e = 1;
    memset(chd[0], -1, sizeof(chd[0]));
    work[0] = 0;
    sw.clear();
    sw['A'] = 0, sw['C'] = 1, sw['G'] = 2, sw['T'] = 3;
}

void add(char* str, int val) {
    //cout << "LLL " << str << '\n';
    int i, id, p = 0;
    for (i = 0; str[i]; i++) {
        id = sw[str[i]];
        if (chd[p][id] == -1) {
            memset(chd[e], -1, sizeof(chd[e]));
            work[e] = 0;
            chd[p][id] = e++;
        }
        p = chd[p][id];
    }
    work[p] = val;
}

void build() {
    int i, p, v, head, tail;
    fail[0] = head = tail = 0;
    for (i = 0; i < CH; i++) {
        if (chd[0][i] != -1) {
            fail[chd[0][i]] = 0;
            q[tail++] = chd[0][i];
        } else chd[0][i] = 0;
    }
    while (head != tail) {
        p = q[head++];
        for (i = 0; i < CH; i++) {
            v = chd[p][i];
            if (v != -1) {
                fail[v] = chd[fail[p]][i];
                work[v] |= work[fail[v]];
                q[tail++] = v;
            } else chd[p][i] = chd[fail[p]][i];
        }
    }
}

const int N = 55, L = 25, M = 1005, INF = M;

int n, m;
char str[L], s[M];
int dp[2][NODE];

void get_min(int &x, int y) {
    if (x == -1 || x > y) x = y;
}

void solve() {
    //sc(e);
    //FOR (i, 1, e - 1) cout << i << ' ' << fail[i] << '\n';
    int now = 0, pre = 1, ans = -1, p;
    memset(dp[now], -1, sizeof(now));
    dp[now][0] = 0;
    rep (i, m) {
        swap(now, pre);
        memset(dp[now], -1, sizeof(dp[now]));
        rep (j, e) {
            if (dp[pre][j] == -1) continue;
            rep (k, CH) {
                p = chd[j][k];
                if (work[p]) continue;
                get_min(dp[now][chd[j][k]], dp[pre][j] + !(sw[s[i]] == k));
            }
        }
    }
    rep (j, e) {
        if (dp[now][j] == -1) continue;
        get_min(ans, dp[now][j]);
    }
    printf("%d\n", ans);
}

int main() {
    int cas = 0;
    while (~scanf("%d", &n) && n) {
        init();
        rep (i, n) {
            scanf("%s", str);
            add(str, 1);
        }
        build();
        scanf("%s", s);
        m = strlen(s);
        printf("Case %d: ", ++cas);
        solve();
    }
    return 0;
}


























