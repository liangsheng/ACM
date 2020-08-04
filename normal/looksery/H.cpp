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

int aa, bb, cc, dd;
double a, b, c, d;

int main() {
    double l, r, mid, k0, k1, k2, k3;
    double max0, min0, max1, min1;
    scanf("%d %d %d %d", &aa, &bb, &cc, &dd);
    a = aa * 1.0;
    b = bb * 1.0;
    c = cc * 1.0;
    d = dd * 1.0;
    l = 0, r = 1e9;
    for (int _ = 0; _ < 150; _++) {
        //sc2(l, r);
        mid = (l + r) * 0.5;
        k0 = (a + mid) * (d + mid);
        k1 = (a + mid) * (d - mid);
        k2 = (a - mid) * (d + mid);
        k3 = (a - mid) * (d - mid);
        max0 = max(max(k0, k1), max(k2, k3));
        min0 = min(min(k0, k1), min(k2, k3));
        //sc3(mid, min0, max0);

        k0 = (b + mid) * (c + mid);
        k1 = (b + mid) * (c - mid);
        k2 = (b - mid) * (c + mid);
        k3 = (b - mid) * (c - mid);
        max1 = max(max(k0, k1), max(k2, k3));
        min1 = min(min(k0, k1), min(k2, k3));

        //sc3(mid, min1, max1);
        if (min0 > max1 || min1 > max0) l = mid;
        else r = mid;
    }
    printf("%.11f\n", l);
    return 0;
}























