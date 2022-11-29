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

const int N = 200005;

int n;
LL a[N * 4], b[N * 4], d[N * 4];
int h[N];

void push_up(int k) {
    a[k] = a[k << 1] + a[k << 1 | 1];
    b[k] = max(b[k << 1], b[k << 1 | 1]);
}

void init(int k, int s, int t) {
    d[k] = -1;
    if (s == t) a[k] = b[k] = h[s];
    else {
        int mid = (s + t) >> 1;
        init(k << 1, s, mid);
        init(k << 1 | 1, mid + 1, t);
        push_up(k);
    }
}

void push_down(int k, int s, int t) {
    if (d[k] == -1) return ;
    int l = k << 1, r = k << 1 | 1, mid = (t + s) >> 1;
    a[l] = d[k] * (mid - s + 1), b[l] = d[k], d[l] = d[k];
    a[r] = d[k] * (t - mid), b[r] = d[k], d[r] = d[k];
    d[k] = -1;
}

void update(int k, int s, int t, int l, int r, int f) {
    if (r < s || l > t) return ;
    if (s >= l && t <= r) {
        a[k] = (LL) f * (t - s + 1);
        b[k] = f, d[k] = f;
        return ;
    }
    push_down(k, s, t);
    int mid = (s + t) >> 1;
    update(k << 1, s, mid, l, r, f);
    update(k << 1 | 1, mid + 1, t, l, r, f);
    push_up(k);
}

LL gao(int k, int s, int t, int l, int r) {
    if (r < s || l > t) return 0;
    if (s >= l && t <= r) return a[k];
    push_down(k, s, t);
    int mid = (s + t) >> 1;
    LL ans = gao(k << 1, s, mid, l, r) + gao(k << 1 | 1, mid + 1, t, l, r);
    return ans;
}

int wid(int k, int s, int t, int val) {
    int mid = (s + t) >> 1;
    if (s == t) return s;
    push_down(k, s, t);
    if (b[k << 1] >= val) return wid(k << 1, s, mid, val);
    return wid(k << 1 | 1, mid + 1, t, val);
}

int c[N], nxt[N];
bool vis[N];
map<int, int> q;

int main() {
    int p, l, r;
    LL ans;
    while (~scanf("%d", &n) && n) {
        FOR (i, 1, n) scanf("%d", &c[i]);
        memset(vis, 0, sizeof(vis));
        memset(nxt, -1, sizeof(nxt));
        p = 0, ans = 0, q.clear();
        FOR (i, 1, n) {
            if (c[i] < N) vis[c[i]] = 1;
            while (vis[p] == 1) p++;
            h[i] = p, ans += p;
            if (q.count(c[i])) nxt[q[c[i]]] = i;
            q[c[i]] = i;
        }
        init(1, 1, n);
        FOR (i, 1, n - 1) {
            update(1, 1, n, i, i, -1);
            if (b[1] >= c[i]) {
                l = wid(1, 1, n, c[i]);
                r = nxt[i];
                if (r == -1) r = n;
                else r--;
                if (l <= r) update(1, 1, n, l, r, c[i]);
            }
            ans += gao(1, 1, n, i + 1, n);
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
