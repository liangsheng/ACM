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

typedef long long LL;

inline void in(int &t) {
    int n = 0, s = 1;
    char ch = getchar();
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-') s = -1, ch = getchar();
    while (ch >= '0' && ch <= '9') n = n * 10 + ch - '0', ch = getchar();
    t = n * s;
}

const int N = 20005;

struct NODE {
    int x, y1, y2, c;
    NODE() {}
    NODE(int Z, int X, int C, int V) : x(Z), y1(X), y2(C), c(V) {}
    bool operator <(const NODE& arg0) const {
        return x < arg0.x;
    }
} yline[N];

int T, n, e;
int id[N << 1];
int a[N << 2][8], b[N << 2][4];
int sc[7] = {1, 2, 4, 3, 5, 6, 7};
LL ans[8];

void update(int k, int s, int t, int l, int r, int v) {
    //printf("k= %d %d %d %d %d %d", k, s, t, l, r, v), pause;
    int i, mid = (s + t) >> 1, st, tmp;
    if (t <= l || s >= r) return ;
    if (s >= l && t <= r) v >= 0 ? b[k][v]++ : b[k][-v]--;
    else update(k << 1, s, mid, l, r, v), update(k << 1 | 1, mid, t, l, r, v);
    st = 0;
    if (b[k][1] > 0) st |= 1;
    if (b[k][2] > 0) st |= 2;
    if (b[k][3] > 0) st |= 4;
    memset(a[k], 0, sizeof(a[k]));
    a[k][st] = id[t] - id[s];
    if (s + 1 < t) {
        for (i = 1; i < 8; i++) {
            if ((i | st) == st) continue;
            tmp = a[k << 1][i] + a[k << 1 | 1][i];
            a[k][i | st] += tmp;
            a[k][st] -= tmp;
        }
    }
}

int main() {
    int i, j, x1, x2, y1, y2, c, cas = 0;
    LL tmp;
    char ch;
    in(T);
    while (T--) {
        in(n);
        e = 0;
        for (i = 0; i < n; i++) {
            ch = getchar();
            while (ch != 'R' && ch != 'G' && ch != 'B') ch = getchar();
            if (ch == 'R') c = 1;
            else if (ch == 'G') c = 2;
            else c = 3;
            in(x1), in(y1), in(x2), in(y2);
            yline[i * 2] = NODE(x1, y1, y2, c);
            yline[i * 2 + 1] = NODE(x2, y1, y2, -c);
            id[e++] = y1, id[e++] = y2;
        }
        sort(id, id + e);
        e = unique(id, id + e) - id;
        sort(yline, yline + 2 * n);
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(ans, 0, sizeof(ans));
        for (i = 0; i < 2 * n - 1; i++) {
            //cout << "i= " << i, pause;
            y1 = lower_bound(id, id + e, yline[i].y1) - id;
            y2 = lower_bound(id, id + e, yline[i].y2) - id;
            update(1, 0, e - 1, y1, y2, yline[i].c);
            //cout << y1 << " " << y2, pause;
            for (j = 1; j < 8; j++) {
                tmp = (LL) yline[i + 1].x - yline[i].x;
                ans[j] += tmp * a[1][j];
            }
        }
        printf("Case %d:\n", ++cas);
        for (i = 0; i < 7; i++) printf("%lld\n", ans[sc[i]]);
    }
    return 0;
}
