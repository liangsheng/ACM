#include <bits/stdc++.h>
#include <fstream>

#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)
#define rep(i, n) for (int i = 0; i < n; i++)
#define FOR(i, n, m) for (int i = n; i <= m; i++)
#define repe(i, u) for (int i = head[u]; ~i; i = nxt[i])
#define FORD(i, n, m) for (int i = n; i >= m; i--)
#define repit(i, c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define pause cout << " press ant key to continue...", cin >> chh

#define pb push_back
#define mp make_pair
#define ins insert
#define X first
#define Y second
#define be begin
#define nb rbegin
#define er erase
#define SZ(c) c.size()
#define sqr(x) ((x) * (x))

#define sc(n) cout << #n << "= " << n, system("pause")
#define sc2(n, m) cout << #n << "= " << n << " " << #m << "= " << m, system("pause")
#define sc3(n, m, k) cout << #n << "= " << n << " " << #m << "= " << m << " " << #k << "= " << k, system("pause")
#define sc4(n, m, k, b) cout << #n << "= " << n << " " << #m << "= " << m << " " << #k << "= " << k << " " << #b << "= " << b, system("pause")

using namespace std;
int chh;

typedef long long LL;

const int N = 105, M = 1005, TI = 10005;

int T, n, m, q;
int p[N], h[N], c[M];

int main() {
    file_r("B-large.in");
    file_w("B.txt");
    int cas = 0, ans, l, r, mid, t, flag, x, y, co, u, v;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &n, &m, &q);
        rep (i, m) scanf("%d", &c[i]);
        rep (i, n) scanf("%d %d", &p[i], &h[i]);
        l = 0, r = TI;
        while (l != r) {
            //sc2(l, r);
            mid = (l + r) >> 1, flag = 1, t = q;
            rep (i, n) {
                //sc(i);
                x = -1;
                if (p[i] == 0) continue;
                rep (j, m) {
                    //sc(j);
                    if (p[i] * c[j] >= 0) continue;
                    if (abs(h[i] - j) > t) continue;
                    u = abs(p[i]), v = abs(c[j]);
                    co = u / v;
                    if (u % v) co++;
                    if (co > mid) continue;
                    if (x == -1 || abs(h[i] - j) < x) x = abs(h[i] - j);
                }
                if (x == -1) {
                    flag = 0;
                    break;
                }
                t -= x;
            }
            if (flag) r = mid;
            else l = mid + 1;
        }
        printf("Case #%d: ", ++cas);
        if (l == TI) puts("IMPOSSIBLE");
        else printf("%d\n", l);
    }
    return 0;
}




















