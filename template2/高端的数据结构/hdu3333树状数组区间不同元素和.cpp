#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>

#define all(c) (c).begin(), c.end()
#define sz(c) (c).size()
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define X first
#define Y second
#define vi vector < int >
#define pii pair < int, int >
#define LL long long
#define mem(v, i) memset(v, i, sizeof(v))
#define rep(i, a) for (int i = 0; i <= (a); i++)
#define repu(i, a, b) for (int i = (a); i <= (b); i++)
#define repd(i, a, b) for (int i = (a); i >= (b); i--)
#define repit(it, v) for (typeof(v.begin()) it = v.begin(); it != v.end(); it++)
#define repitd(it, v) for (typeof(v.rbegin()) it = v.rbegin(); it != v.rend(); it++)
#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)
#define lowbit(x) ((x) & (-(x)))
#define pause cout << " press any key to continue...",  cin >> chh

using namespace std;
int chh;

inline void in(int &t) {
    int n = 0, s = 1;
    char ch = getchar();
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-') s = -1, ch = getchar();
    while (ch >= '0' && ch <= '9') n = n * 10 + ch - '0', ch = getchar();
    t = n * s;
}

const int N = 30005, M = 100005;

struct NODE{
    int l, r, id;
    bool operator <(const NODE& arg0) const {
        return r < arg0.r;
    }
} p[M];

int T, n, m, e;
int val[N], pre[N], b[N];
LL a[N], res[M];

void add(int x, int val) {
    while (x > 0) {
        a[x] += (LL) val;
        x -= lowbit(x);
    }
}

LL cal(int x) {
    LL ans = 0;
    while (x <= n) {
        ans += a[x];
        x += lowbit(x);
    }
    return ans;
}

int main() {
    int k, x, y;
    in(T);
    while (T--) {
        in(n);
        e = 0;
        repu (i, 1, n) {
            in(val[i]);
            b[e++] = val[i];
        }
        sort(b, b + e);
        e = unique(b, b + e) - b;
        repu (i, 1, n) val[i] = lb(b, b + e, val[i]) - b + 1;
        in(m);
        repu (i, 1, m) {
            in(p[i].l), in(p[i].r);
            p[i].id = i;
        }
        sort(p + 1, p + m + 1);
        mem(a, 0), mem(pre, 0);
        k = 1;
        repu (i, 1, n) {
            x = pre[val[i]], y = i;
            add(y, b[val[i] - 1]);
            if (x != 0) add(x, -b[val[i] - 1]);
            pre[val[i]] = i;
            while (k <= m && p[k].r == i) {
                res[p[k].id] = cal(p[k].l);
                k++;
            }
        }
        repu (i, 1, m) printf("%lld\n", res[i]);
    }
    return 0;
}
