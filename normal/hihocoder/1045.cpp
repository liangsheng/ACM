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

const int N = 1000005;

int n, L, R, C, T;
int a[N], b[N], s[N];
LL c[N], d[N];
LL p1, p2;

LL gcd(LL a, LL b) {
    return a % b ? gcd(b, a % b) : b;
}

pair<LL, LL> gao(int l, int r) {
    LL p1 = 0, p2 = 1;
    int sum = s[r - 1] - s[l] + (n - r + 1) * R + l * L, tmp, sz = r - l - 1;
    p1 += c[l] + d[r];
    //sc4(l, r, p1, sum);
    if (sum <= C) {
        tmp = C - sum;
        if (a[r - 1] > R || (R - a[r - 1]) * sz < tmp) return {-1, -1};
        if (a[l + 1] < L && (L - a[l + 1]) * sz > tmp) return {-1, -1};

    } else {
        tmp = sum - C;
        if (a[l + 1] < L || (a[l + 1] - L) * sz < tmp) return {-1, -1};
        if (a[r - 1] > R && (a[r - 1] - R) * sz > tmp) return {-1, -1};
    }
    LL x = (LL) tmp * tmp, y = sz;
    if (x == 0) return {p1, p2};
    LL d = gcd(x, y);
    //sc2(x, y);
    x /= d, y /= d;
    LL z1 = x * p2 + y * p1, z2 = y * p2;
    d = gcd(z1, z2);
    p1 = z1 / d, p2 = z2 / d;
   // sc2(p1, p2);
    return {p1, p2};
}

int main() {
   // file_r("in.txt");
//    file_w("out.txt");
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d", &n, &L, &R, &C);
        FOR (i, 1, n) scanf("%d", &a[i]);
        sort(a + 1, a + n + 1);
        s[0] = 0, c[0] = 0, d[n + 1] = 0;
        FOR (i, 1, n) {
            s[i] = s[i - 1] + a[i];
            c[i] = sqr(L - a[i]) + c[i - 1];
            d[n + 1 - i] = d[n + 2 - i] + sqr(R - a[n + 1 - i]);
        }
        p1 = -1, p2 = 1;
       // gao(0, 6);
        FOR (r, 1, n + 1) {
            FOR (l, 0, r - 1) {
                pair<LL, LL> t = gao(l, r);
                if (t.X == -1) continue;
                if (p1 == -1 || t.X * p2 < t.Y * p1) p1 = t.X, p2 = t.Y;
            }
        }
        if (p2 == 1) cout << p1 << '\n';
        else cout << p1 << '/' << p2 << '\n';
    }
    return 0;
}
