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

const int N = 1000005;

struct Node {
    int l, r, id;

    Node() {}
    Node(int L, int R, int ID): l(L), r(R), id(ID) {}

    bool operator <(const Node& arg) const {
        if (r != arg.r) return r < arg.r;
        return l < arg.l;
    }
} p[N];

int n, m;
int a[N], b[N], ans[N];
mii q;

void add(int x, int y) {
    for (; x > 0; x -= lowbit(x)) b[x] ^= y;
}

int cal(int x) {
    int ans = 0;
    for (; x <= n; x += lowbit(x)) ans ^= b[x];
    return ans;
}

int main() {
    int now, t;
    while (~scanf("%d", &n)) {
        FOR (i, 1, n) scanf("%d", &a[i]);
        scanf("%d", &m);
        FOR (i, 1, m) {
            scanf("%d %d", &p[i].l, &p[i].r);
            p[i].id = i;
        }
        sort(p + 1, p + m + 1);
        memset(b, 0, sizeof(b));
        now = 1, q.clear();
        FOR (i, 1, n) {
            if (!q.count(a[i])) q[a[i]] = i;
            else {
                t = q[a[i]];
                q[a[i]] = i;
                add(t, a[i]);
            }
            while (p[now].r == i) {
                ans[p[now].id] = cal(p[now].l);
                now++;
            }
        }
        FOR (i, 1, m) printf("%d\n", ans[i]);
    }
    return 0;
}
