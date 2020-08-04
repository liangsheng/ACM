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

const int N = 500005;

int n, a, b, t, ans;
char s[N];
int d[N], f[N];

void gao() {
    int now, id = 2, tmp;
    f[n] = d[n];
    FORD (i, n - 1, 1) f[i] = f[i + 1] + a + d[i];
    now = 0;
    FOR (i, 1, n) {
        if (i == 1) now += d[1];
        else now += a + d[i];
        if (now > t) break;
        while (id > 1 && now + i * a + f[id] > t) {
            id++;
            if (id == n + 1) {
                id = 1;
                break;
            }
        }
        //sc2(i, id);
        if (id == 1) ans = max(ans, i);
        else ans = max(ans, i + n - id + 1);
    }
}

int main() {
    int tol, l, r, mid;
    while (~scanf("%d %d %d %d", &n, &a, &b, &t)) {
        scanf("%s", s + 1);
        tol = 0;
        FOR (i, 1, n) {
            if (s[i] == 'w') d[i] = b + 1;
            else d[i] = 1;
            tol += d[i];
        }
        tol += (n - 1) * a;
        if (t >= tol) {
            printf("%d\n", n);
            continue;
        }
        if (d[1] > t) {
            puts("0");
            continue;
        }
        ans = 1;
        //FOR (i, 1, n) sc2(i, d[i]);
        gao();
        FOR (i, 2, (n + 1) / 2) swap(d[i], d[n + 2 - i]);
        //puts("DDDDD");
        gao();
        printf("%d\n", ans);
    }
    return 0;
}


















