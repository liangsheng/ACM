#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define pause cout << " press any key to continue...",  cin >> chh
#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)
#define lowbit(x) ((x) & (-(x)))

using namespace std;
int chh;

const int NN = 200005, INF = ~0U >> 2;

int mn;
int mi[NN], miv[NN << 1];

struct BIT {
    void init(int nn) {
        mn = nn;
        fill(mi + 1, mi + mn + 1, INF);
        fill(miv + 1, miv + mn + 1, INF);
    }

    void update(int i, int a) {
        miv[i] = min(miv[i], a);
        for (; i <= mn; i += lowbit(i)) mi[i] = min(mi[i], a);
    }

    int find(int l, int r) {
        int ans = INF, nr;
        while (l <= r) {
            nr = r - lowbit(r);
            if (nr + 1 >= l) ans = min(ans, mi[r]), r = nr;
            else ans = min(ans, miv[r]), r--;
        }
        return ans;
    }
} bt;

inline void in(int &t) {
    int n = 0, s = 1;
    char ch = getchar();
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-') s = -1, ch = getchar();
    while (ch >= '0' && ch <= '9') n = n * 10 + ch - '0', ch = getchar();
    t = n * s;
}

const int  N = 100005;

struct NODE {
    int x, h;
    bool operator <(const NODE& arg0) const {
        return x < arg0.x;
    }
} p[N];

int n, e;
int id[N << 1], l[N], r[N];
int dp[N];

inline int find(int x) {
    return lower_bound(id, id + e, x) - id + 1;
}

void call() {
    int i, j, k;
    e = 0;
    for (i = 1; i <= n; i++) id[e++] = p[i].x, id[e++] = p[i].x - p[i].h;
    sort(id, id + e);
    e = unique(id, id + e) - id;
    bt.init(e);
    for (i = 1; i <= n; i++) {
        l[i] = i, k = find(p[i].x);
        j = bt.find(find(p[i].x - p[i].h), k);
        l[i] = min(l[i], j);
        bt.update(k, l[i]);
    }
}

void calr() {
    int i, j, k;
    e = 0;
    for (i = 1; i <= n; i++) id[e++] = p[i].x, id[e++] = p[i].x + p[i].h;
    sort(id, id + e);
    e = unique(id, id + e) - id;
    bt.init(e);
    for (i = n; i >= 1; i--) {
        r[i] = i, k = find(p[i].x);
        j = bt.find(k, find(p[i].x + p[i].h));
        r[i] = max(r[i], -j);
        bt.update(k, -r[i]);
    }
}

int main() {
    int i, j;
    while (~scanf("%d", &n)) {
        for (i = 1; i <= n; i++) in(p[i].x), in(p[i].h);
        sort(p + 1, p + n + 1);
        call(), calr();
        fill(dp + 1, dp + n + 1, INF);
        bt.init(n);
        for (i = 1; i <= n; i++) {
            if (l[i] <= 1) dp[i] = min(dp[i], 1);
            else dp[i] = min(dp[i], 1 + bt.find(l[i] - 1, i));
            bt.update(i, dp[i]);
            dp[r[i]] = min(dp[r[i]], dp[i - 1] + 1);
        }
        printf("%d\n", dp[n]);
    }
    return 0;
}
