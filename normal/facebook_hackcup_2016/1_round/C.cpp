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

int T, n;
LL A, B;
LL s[N];

int main() {
    file_r("yachtzee.txt");
    file_w("out.out");
    int cas = 0;
    double ans;
    LL l, r, d, c, t, x, dp, p;
    cin >> T;
    while (T--) {
        cin >> n >> A >> B;
        s[0] = 0;
        FOR (i, 1, n) {
            cin >> x;
            s[i] = s[i - 1] + x;
        }
        ans = 0;
        rep (i, n) {
            //sc(i);
            l = s[i], dp = s[i + 1] - s[i];
            //sc2(i, l);
            if (l < A) {
                d = A - 1 - l;
                l += d / s[n] * s[n];
                while (l + s[n] < A) l += s[n];
                if (l + dp >= A) {
                    p = l + dp;
                    p = min(p, B);
                    //sc2(l, p);
                    ans += (double) (p - A) / (B - A) * (A + p - 2 * l) * 0.5;
                }
                l += s[n];
            }
            //sc2(ans, l);
            if (l >= B) continue;
            d = (B - l) / s[n];
            t = dp * d, l += d * s[n];
            ans += (double) t / (B - A) * dp * 0.5;
            //sc(ans);
            //sc2(ans, l);
            if (l < B) {
                p = min(l + dp, B);
                ans += (double) (p - l) / (B - A) * (p - l) * 0.5;
            }
            //sc2(i, ans);
        }
        printf("Case #%d: %.10f\n", ++cas, ans);
    }
    return 0;
}

















