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

const int N = 100005;

int n, m, k;
int c[N];

struct SegTree {
    int a[N << 2], lz[N << 2], id[N << 2];

    void push_down(int k, int s, int t) {
        int l = k << 1, r = l + 1;
        a[l] += lz[k], a[r] += lz[k];
        lz[l] += lz[k], lz[r] += lz[k];
        lz[k] = 0;
    }

    void push_up(int k, int s, int t) {
        int l = k << 1, r = l + 1;
        if (a[l] >= a[r]) a[k] = a[l], id[k] = id[l];
        else a[k] = a[r], id[k] = id[r];
    }

    void init(int k, int s, int t) {
        lz[k] = 0;
        if (s == t) a[k] = c[s], id[k] = s;
        else {
            int mid = (s + t) >> 1;
            init(k << 1, s, mid);
            init(k << 1 | 1, mid + 1, t);
            push_up(k, s, t);
        }
    }

    void update(int k, int s, int t, int l, int r, int val) {
        if (s > r || t < l) return ;
        if (s >= l && t <= r) {
            a[k] += val;
            lz[k] += val;
            return ;
        }
        push_down(k, s, t);
        int mid = (s + t) >> 1;
        update(k << 1, s, mid, l, r, val);
        update(k << 1 | 1, mid + 1, t, l, r, val);
        push_up(k, s, t);
    }

    pii findMax() {
        return mp(a[1], id[1]);
    }

    int find(int k, int s, int t, int x) {
        if (s == t) return a[k];
        push_down(k, s, t);
        int mid = (s + t) >> 1;
        if (x <= mid) return find(k << 1, s, mid, x);
        return find(k << 1 | 1, mid + 1, t, x);
    }

} segTree;

int main() {
    while (~scanf("%d %d %d", &n, &m, &k)) {
        rep (i, n) scanf("%d", &c[i + 1]);
        segTree.init(1, 1, n);
        rep (tim, m) {
            segTree.update(1, 1, n, 1, n, k * 100);
            // rep (i, n) printf("i= %d ", segTree.find(1, 1, n, i + 1));
            // puts("");

            pii tmp = segTree.findMax();
            // cout << "v= " << tmp.Y << ' ' << tmp.X / 2 - tmp.X << '\n';
            segTree.update(1, 1, n, tmp.Y, tmp.Y, tmp.X / 2 - tmp.X);
            // rep (i, n) printf("j= %d ", segTree.find(1, 1, n, i + 1));
            // puts("");
        }
        LL ans = 0;
        rep (i, n) ans += segTree.find(1, 1, n, i + 1);
        cout << ans << '\n';
    }
    return 0;
}
