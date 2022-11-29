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

const int N = 25, M = 105;

int n, m;
int dx[N], h[N];
vi g[N];

int main() {
    int tol, p, x0, y0, x1, y1, cnt, sz, l, r;
    int a[2] = {4, 2};
    pii p1[1], p2[3];
    p1[0] = mp(0, 0);
    p2[0] = mp(0, 0);
    p2[1] = mp(2, -2);
    p2[2] = mp(2, 2);
    while (~scanf("%d %d", &n, &m)) {
        if (n == 1) {
            rep (i, m) {
                scanf("%d %d %d %d", &x0, &y0, &x1, &y1);
                if (0 >= x0 && 0 <= x1 && 0 >= y0 && 0 <= y1) puts("1");
                else puts("0");
            }
            continue;
        }
        if (n == 2) {
            rep (i, m) {
                scanf("%d %d %d %d", &x0, &y0, &x1, &y1);
                cnt = 0;
                rep (i, 3) {
                    if (p2[i].X >= x0 && p2[i].X <= x1 && p2[i].Y >= y0 && p2[i].Y <= y1) cnt++;
                }
                printf("%d\n", cnt);
            }
            continue;
        }

        FOR (i, 1, n) g[i].clear();
        tol = 1 << (n - 2), p = -1;
        rep (i, tol) {
            g[n].pb(p);
            g[n].pb(-p);
            p -= a[i % 2];
        }
        sort(ALL(g[n]));
        //repit (it, g[n]) sc(*it);
        FORD (i, n, 2) {
            sz = SZ(g[i]);
            rep (j, sz) {
                g[i - 1].pb((g[i][j] + g[i][j + 1]) / 2);
                j++;
            }
            dx[i - 1] = (g[i][1] - g[i][0] - 1) / 2;
            //cout << "i= " << i - 1 << '\n';
            //repit (it, g[i - 1]) sc(*it);
            //sc2(i - 1, dx[i - 1]);
        }
        h[1] = 0;
        FOR (i, 2, n) h[i] = h[i - 1] + dx[i - 1] + 1;
        //FOR (i, 1, n) sc3(i, h[i], dx[i]);
        while (m--) {
            scanf("%d %d %d %d", &x0, &y0, &x1, &y1);
            cnt = 0;
            FOR (i, 1, n) {
                if (h[i] < x0 || h[i] > x1) continue;
                //sc(i);
                r = upper_bound(ALL(g[i]), y1) - g[i].begin();
                l = lower_bound(ALL(g[i]), y0) - g[i].begin();
                //sc3(i, l, r);
                cnt += r - l;
            }
            printf("%d\n", cnt);
        }
    }
    return 0;
}
















