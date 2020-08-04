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

const int N = 1005, M = 107;

int n;
int c[N][N], dp[N][N];
int h[N], t[N];
char s[N];

void init() {
    h[0] = 0, t[0] = 1;
    FOR (i, 1, n) {
        t[i] = t[i - 1] * M;
        h[i] = h[i - 1] * M + s[i] - 'a';
    }
}

int cal(int l, int r) {
    return h[r] - h[l - 1] * t[r - l + 1];
}

void get_max(int &x, int y) {
    x = max(x, y);
}

void get_c() {
    int id, len, tmp;
    memset(c, 0, sizeof(c));
    FOR (i, 1, n) FOR (j, i, n) {
        id = cal(i, j);
        len = j - i + 1;
        for (int k = i + len, tim = 1; k + len <= n + 1; k += len, tim++) {
            tmp = cal(k, k + len - 1);
            //if (i == 1 && j == 2 && k == 3) sc3(id, tmp, cal(3, 4));
            if (tmp != id) break;
            get_max(c[i][k + len - 1], tim);
        }
    }

    memset(dp, 0, sizeof(dp));
    dp[n][0] = 1;
    FORD (i, n - 1, 1) {
        rep (j, n) dp[i][j] += dp[i + 1][j];
        FOR (j, i, n) dp[i][c[i][j]]++;
    }
}

void get_ans() {
    int t;
    LL ans = 0;
    FOR (i, 1, n) FOR (j, i, n) {
        t = c[i][j];
        ans += dp[j + 1][t];
    }
    cout << ans << '\n';
}

int main() {
    while (~scanf("%s", s + 1)) {
        n = strlen(s + 1);
        init();
        //FOR (i, 1, n) printf("i= %d %d\n", i, h[i]);
        get_c();
//        FOR (i, 1, n) {
//            FOR (j, i, n) printf("i= %d j= %d %d\n", i, j, c[i][j]);
//        }
        get_ans();
    }
    return 0;
}
