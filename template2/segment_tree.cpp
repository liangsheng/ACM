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

const int N = 100005;

int b[N];
LL a[N << 2], lz[N << 2];

struct SegmentTree {
    void push_up(int k) {
        a[k] = a[k << 1] + a[k << 1 | 1];
    }

    void init(int k, int s, int t) {
        if (s == t) {
            a[k] = b[s];
            return ;
        }
        int mid = (s + t) >> 1;
        init(k << 1, s, mid);
        init(k << 1 | 1, mid + 1, t);
        push_up(k);
    }

    void push_down(int k, int s, int t) {
        int l = k << 1, r = l + 1, mid = (s + t) >> 1;
        a[l] += lz[k] * (mid - s + 1), lz[l] += lz[k];
        a[r] += lz[k] * (t - mid), lz[r] += lz[k];
        lz[k] = 0;
    }

    void update(int k, int s, int t, int l, int r, int v) {
        if (l > t || r < s) return ;
        if (s >= l && t <= r) {
            a[k] += (t - s + 1) * (LL) v;
            lz[k] += v;
            return ;
        }
        push_down(k, s, t);
        int mid = (s + t) >> 1;
        update(k << 1, s, mid, l, r, v);
        update(k << 1 | 1, mid + 1, t, l, r, v);
        push_up(k);
    }

    LL query(int k, int s, int t, int l, int r) {
        if (s >= l && t <= r) return a[k];
        if (s > r || t < l) return 0;
        push_down(k, s, t);
        int mid = (s + t) >> 1;
        LL ans = query(k << 1, s, mid, l, r) + query(k << 1 | 1, mid + 1, t, l, r);
        return ans;
    }
} seg;

int n, m;

int main() {
    SegmentTree seg;
    while (~in2(n, m)) {
        rep (i, n) in(b[i + 1]);
        seg.init(1, 1, n);

        char cmd[5];
        int l, r, x;
        while (m--) {
            scanf("%s", cmd);
            if (cmd[0] == 'C') {
                in3(l, r, x);
                seg.update(1, 1, n, l, r, x);
            } else {
                in2(l, r);
                cout << seg.query(1, 1, n, l, r) << '\n';
            }
        }
    }
    return 0;
}
