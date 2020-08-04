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

const int MOD = 1000000007;

LL extend_gcd(LL a, LL b, LL &x, LL &y) {
    LL t, ret;
    if (b==0) {
        x = 1;
        y = 0;
        return a;
    } else {
        ret = extend_gcd(b,a%b,x,y);
        t = x;
        x = y;
        y = t - a / b * y;
        return ret;
    }
}

LL gao(LL z) {
    LL x, y;
    extend_gcd(z, MOD, x, y);
    if (x < 0) x += (-x) / MOD * MOD;
    while (x < 0) x += MOD;
    return x % MOD;
}

int T;
LL n, k;

int main() {
//    cout << 100001LL * 100000 / 2 << '\n' << 1000000000;
    int n = 92, ans = 0, a[10];
    FOR (i, 1, n) FOR (j, i + 1, n) FOR (k, j + 1, n) FOR (l, k + 1, n) {
        if (i + j + k + l != n) continue;
        int tmp = i * j * k * l;
        if (tmp > ans) ans = tmp, a[0] = i, a[1] = j, a[2] = k, a[3] = l;
    }
    sc4(a[0], a[1], a[2], a[3]);
    return 0;
}













