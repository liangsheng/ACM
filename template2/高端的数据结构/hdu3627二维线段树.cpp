#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>
#include <set>

#define pause cout << " press any key to continue...",  cin >> chh
#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)

using namespace std;
int chh;

const int N = 200005, INF = ~0U >> 2;

struct NODE {
    int x, y, f;
} q[N];

int n, e;
int id[N];
int a[N << 2];
set<int> s[N];

void init(int k, int s, int t) {
    int mid = (s + t) >> 1;
    a[k] = -1;
    if (s == t) return;
    init(k << 1, s ,mid);
    init(k << 1 | 1, mid + 1, t);
}

void update(int k, int s, int t, int x, int y, bool f) {
    int mid = (s + t) >> 1;
    if (s == t && s == x) {
        if (f) a[k] = max(a[k], y);
        else a[k] = y;
        return;
    }
    if (x <= mid) update(k << 1, s, mid, x, y, f);
    else update(k << 1 | 1, mid + 1, t, x, y, f);
    a[k] = max(a[k << 1], a[k << 1 | 1]);
}

int find(int k, int s, int t, int x, int y) {
    int ans, tmp, mid = (s + t) >> 1;
    if (a[k] <= y) return INF;
    if (s == t) return s;
    if (mid > x) {
        ans = find(k << 1, s, mid, x, y);
        if (ans != INF) return ans;
    }
    ans =  find(k << 1 | 1, mid + 1, t, x, y);
    return ans;
}

int main() {
    int i, j, x, y, idx, tmp, cas = 0;
    char cmd[10];
    while (scanf("%d", &n) != EOF) {
        if (n == 0) break;
        if (cas++) puts("");
        printf("Case %d:\n", cas);
        e = 0;
        for (i = 1; i <= n; i++) {
            scanf("%s %d %d", cmd, &q[i].x, &q[i].y);
            if (cmd[0] == 'a') q[i].f = 0;
            else if (cmd[0] == 'r') q[i].f = 1;
            else q[i].f = 2;
            id[e++] = q[i].x;
        }
        sort(id, id + e);
        e = unique(id, id + e) - id;
        for (i = 0; i < e; i++) s[i].clear();
        init(1, 0, e - 1);
        for (i = 1; i <= n; i++) {
            x = lower_bound(id, id + e, q[i].x) - id;
            y = q[i].y;
            if (q[i].f == 0 || q[i].f == 1) {
                if (q[i].f == 0) {
                    s[x].insert(y);
                    update(1, 0, e - 1, x, y, 1);
                } else {
                    s[x].erase(y);
                    if (s[x].empty()) tmp = -1;
                    else tmp = *(--s[x].end());
                    update(1, 0, e - 1, x, tmp, 0);
                }
            } else {
                if (x >= e - 1) puts("-1");
                else {
                    idx = find(1, 0, e - 1, x, y);
                    if (idx == INF) puts("-1");
                    else {
                        tmp = *(s[idx].upper_bound(y));
                        printf("%d %d\n", id[idx], tmp);
                    }
                }
            }
        }
    }
    return 0;
}
