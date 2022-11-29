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

const int N = 105;

/*==================================================*\
|  扩展 GCD
|  求x, y 使得gcd(a, b) = a * x + b * y;
\*==================================================*/
int extgcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int d = extgcd(b, a % b, x, y);
    int t = x;
    x = y;
    y = t - a / b * y;
    return d;
}

int n, p, q;
char s[N];

int main() {
    int d, x, y, k, ans;
    //d = extgcd(3, 5, x, y);
    //sc3(d, x, y);
    while (~scanf("%d %d %d", &n, &p, &q)) {
        scanf("%s", s);
        d = extgcd(p, q, x, y);
        if (n % d) {
            puts("-1");
            continue;
        }
        x *= n / d, y *= n / d;
        //sc3(d, x, y);
        if (x < 0) {
            k = (-x) / (q / d);
            x += k * (q / d), y -= k * (p / d);
            while (x < 0) x += q / d, y -= p / d;
        }
        if (y < 0) {
            k = (-y) / (p / d);
            x -= k * (q / d), y += k * (p / d);
            while (y < 0) x -= q / d, y += p / d;
        }
        if (x < 0 || y < 0) {
            puts("-1");
            continue;
        }
        //sc3(d, x, y);
        ans = x + y;
        printf("%d\n", ans);
        rep (i, x) {
            rep (j, p) printf("%c", s[i * p + j]);
            puts("");
        }
        rep (i, y) {
            rep (j, q) printf("%c", s[x * p + i * q + j]);
            puts("");
        }
    }
    return 0;
}














