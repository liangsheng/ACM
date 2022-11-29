#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>

#define pause cout << " press any key to continue...",  cin >> chh
#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)
#define lowbit(x) ((x) & (-(x)))
#define foreach(i, c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)

using namespace std;
int chh;

const int N = 100005;

struct NODE {
    int l, r, id;
    bool operator <(const NODE& arg0) const {
        return r < arg0.r;
    }
} b[N];

int n, m;
int val[N], nxt[N];
int a[N], res[N];
queue<int> q[N];
map<int, int> f;

void add(int x, int val) {
    while (x > 0) a[x] += val, x -= lowbit(x);
}

int find(int x) {
    int ans = 0;
    while (x <= n) ans += a[x], x += lowbit(x);
    return ans;
}

int main() {
    int i, j, k, x, y, z;
    while (~scanf("%d %d", &n, &m)) {
        memset(nxt, -1, sizeof(nxt));
        f.clear();
        for (i = 1; i <= n; i++) {
            scanf("%d", &val[i]);
            if (f.count(val[i])) nxt[f[val[i]]] = i;
            f[val[i]] = i;
        }
        for (i = 1; i <= m; i++) {
            scanf("%d %d", &b[i].l, &b[i].r);
            b[i].id = i;
        }
        sort(b + 1, b + m + 1);
        for (i = 1; i <= n; i++) {
            while (! q[i].empty()) q[i].pop();
        }
        memset(a, 0, sizeof(a));
        k = 1;
        for (i = 1; i <= n; i++) {
            j = val[i];
            if (j <= n) {
                if (q[j].size() == j + 1) {
                    x = q[j].front(), q[j].pop(), q[j].push(i);
                    y = nxt[x], z = nxt[y];
                    add(x, 1), add(y, -1);
                    add(y, -1), add(z, 1);
                } else if (q[j].size() == j) {
                    x = q[j].front(), q[j].push(i);
                    y = nxt[x];
                    add(x, -1);
                    add(x, -1), add(y, 1);
                } else if (q[j].size() == j - 1) {
                    q[j].push(i), x = q[j].front();
                    add(x, 1);
                } else q[j].push(i);
            }
            for (; k <= m && b[k].r == i; k++) {
                res[b[k].id] = find(b[k].l);
            }
        }
        for (i = 1; i <= m; i++) printf("%d\n", res[i]);
    }
    return 0;
}
