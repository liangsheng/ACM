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
typedef unsigned long long ULL;

const int N = 4105, INF = ~0U >> 2;
const ULL P = 10007;

int n, m, l, r;
char s[N], t[N];
ULL h[N], d[N], c[N];
set<ULL> q;
int dp[N];
pii pre[N], p[N];

int ok(int i, int j) {
    ULL tmp = (c[i] - c[j + 1]) * h[i - 1 + n];
    //sc3(i, j, tmp);
    if (q.count(tmp)) return 1;
    tmp = (d[j] - d[i - 1]) * h[m - j + n];
    //sc3(i, j, tmp);
    if (q.count(tmp)) return -1;
    return 0;
}

int main() {
    int f, flag;
    ULL tmp;
    h[0] = 1;
    FOR (i, 1, N - 1) h[i] = h[i - 1] * P;
    while (~scanf("%s %s", s + 1, t + 1)) {
        n = strlen(s + 1);
        m = strlen(t + 1);
        q.clear();
        d[0] = 0;
        FOR (i, 1, n) d[i] = s[i] * h[i - 1] + d[i - 1];
        c[n + 1] = 0;
        FORD (i, n, 1) c[i] = s[i] * h[n - i] + c[i + 1];
        FOR (i, 1, n) FOR (j, i, n) {
            tmp = (c[i] - c[j + 1]) * h[i - 1 + m];
            q.insert(tmp);
            //sc4(i, j, tmp, 1);
            //tmp = (d[j] - d[i - 1]) * h[n - j + m];
            //q.insert(tmp);
            //sc4(i, j, tmp, -1);
        }
        d[0] = 0;
        FOR (i, 1, m) d[i] = t[i] * h[i - 1] + d[i - 1];
        c[m + 1] = 0;
        FORD (i, m, 1) c[i] = t[i] * h[m - i] + c[i + 1];

        //sc(ok(4, 6));
        dp[0] = 0, pre[0] = mp(-1, -1);
        l = r = 0, flag = 1;
        p[r++] = mp(0, 0);
        FOR (i, 1, m) {
            f = ok(p[l].X + 1, i), dp[i] = INF;
            while (l != r && !f) l++, f = ok(p[l].X + 1, i);
            if (l == r) dp[i] = INF, pre[i] = mp(-1, -1);
            else dp[i] = p[l].Y + 1, pre[i] = mp(p[l].X, f);
            while (l != r && p[r - 1].Y >= dp[i]) r--;
            p[r++] = mp(i, dp[i]);
            if (dp[i] == INF) {
                flag = 0;
                break;
            }
        }
        if (!flag) puts("-1");
        else {
            printf("%d\n", dp[m]);
            int u = m;
            while (u != -1) {
                if (pre[u].Y == 1) printf("%d %d\n", pre[u].X + 1, u);
                else printf("%d %d\n", u, pre[u].X + 1);
                u = pre[u].X;
            }
        }
    }
    return 0;
}














