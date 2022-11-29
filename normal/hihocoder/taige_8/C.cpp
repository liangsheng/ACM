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

int x, y, z;
int a, b, c;
int u, v, w;

bool gao(int x, int y, int z, int t) {
    a = x, b = y, c = z;
    if (t <= 15) {
        while (t > 0) {
            if (x > 0 && x >= y && x >= z) x--, t--;
            else if (y > 0 && y >= x && y >= z) y--, t--;
            else if (z > 0 && z >= x && z >= y) z--, t--;
            else return 0;
        }
        a -= x, b -= y, c -= z;
        return 1;
    }
    int s = t / 2, d[3] = {0, 0, 0};
    pii p[3];
    p[0] = mp(x, 0);
    p[1] = mp(y, 1);
    p[2] = mp(z, 2);
    while (t > 0) {
        sort(p, p + 3);
        if (p[2].X > 0 && d[p[2].Y] < s) p[2].X--, d[p[2].Y]++, t--;
        else if (p[1].X > 0 && d[p[1].Y] < s) p[1].X--, d[p[1].Y]++, t--;
        else if (p[0].X > 0 && d[p[0].Y] < s) p[0].X--, d[p[0].Y]++, t--;
        else return 0;
        //sc3(d[0], d[1], d[2]);
    }
    a = d[0], b = d[1], c = d[2];
    return 1;
}

void hao(int t, int x, int y, int z) {
    t = min(t, 20);
    //sc(t);
    FORD (i, t, 1) if (gao(x, y, z, i)) return ;
}

int main() {
    //sc(gao(4, 40, 4, 16));
    //sc3(a, b, c);
    int ans, t;
    while (~scanf("%d %d %d", &x, &y, &z)) {
        hao(20, x, y, z);
        u = a, v = b, w = c;
        x -= a, y -= b, z -= c;
        ans = 0;
        while (u > 0 || v > 0 || w > 0) {
            hao(20, u, v, w);
            //sc3(u, v, w);
            u -= a, v -= b, w -= c;
            ans += 6;
            //sc3(u, v, w);

            t = 35 - u - v - w;
            hao(t, x, y, z);
            u += a, v += b, w += c;
            x -= a, y -= b, z -= c;
            //sc3(a, b, c);

            hao(20, x, y, z);
            u += a, v += b, w += c;
            x -= a, y -= b, z -= c;
            //sc3(a, b, c);
        }
        printf("%d\n", ans);
    }
    return 0;
}













