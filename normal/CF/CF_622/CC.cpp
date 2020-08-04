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

const int N = 500005, INF = ~0U >> 2;

LL n;
LL a[N], c[N], L[N], R[N], t[N];
vector<LL> b;

void hao(LL a[N], LL L[N]) {
    int e = 0, p;
    a[0] = -1, L[0] = 0, t[e++] = 0,  L[n + 1] = 0;
    FOR (i, 1, n) {
        while (e > 0 && a[t[e - 1]] > a[i]) e--;
        p = t[e - 1];
        L[i] = L[p] + (i - p) * a[i];
        t[e++] = i;
    }
}

LL gao() {
    hao(a, L);
    hao(c, R);
    FOR (i, 1, n / 2) swap(R[i], R[n + 1 - i]);

    // FOR (i, 1, n) cout << L[i] << ' ';
    // puts("");
    // FOR (i, 1, n) cout << R[i] << ' ';
    // puts("");

    LL ans = 0, tmp, id, p;
    a[n + 1] = -1;
    FOR (i, 1, n) {
        if (a[i] < a[i + 1]) continue;
        tmp = L[i] + R[i + 1];
        // cout << "i= " << i << ' ' << tmp << '\n';
        if (tmp > ans) ans = tmp, id = i;
    }
    // cout << ans << '\n';

    // L[0] = 0, L[n + 1] = 0;
    // R[0] = 0, R[n + 1] = 0;
    // a[0] = INF;

    // FOR (i, 1, n) {
    //     L[i] = a[i], p = a[i];
    //     FORD (j, i - 1, 1) {
    //         p = min(p, a[j]);
    //         L[i] += p;
    //     }
    // }
    // FOR (i, 1, n) {
    //     R[i] = min(a[i], a[i - 1]), p = R[i];
    //     FOR (j, i + 1, n) {
    //         p = min(p, a[j]);
    //         R[i] += p;
    //     }
    // }

    // ans = 0, tmp, id;
    // FOR (i, 1, n) {
    //     if (a[i] < a[i + 1]) continue;
    //     tmp = L[i] + R[i + 1];
    //     // cout << "i= " << i << ' ' << tmp << '\n';
    //     if (tmp > ans) ans = tmp, id = i;
    // }
    // cout << ans << '\n';

    b.clear();
    rep (i, n) b.pb(0);

    // cout << "id= " << id << ' ' << L[id] << ' ' << R[id + 1] << '\n';
    p = a[id];
    FORD (i, id, 1) {
        p = min(p, a[i]);
        b[i - 1] = p;
    }
    p = a[id];
    FOR (i, id + 1, n) {
        p = min(p, a[i]);
        b[i - 1] = p;
    }

    return ans;
}

int main() {
    while (cin >> n) {
        rep (i, n) cin >> a[i + 1], c[n - i] = a[i + 1];
        // rep (i, n) a[i + 1] = rand() % 5 + 1, c[n - i] = a[i + 1];
        // rep (i, n) cout << a[i + 1] << ' ';
        // puts("");

        LL ans = gao();
        // cout << ans << '\n';
        rep (i, n - 1) cout << b[i] << ' ';
        cout << b[n - 1] << '\n';
    }
    return 0;
}
