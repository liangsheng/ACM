#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define pause cout << " press any key to continue...",  cin >> chh
#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)
#define lowbit(x) ((x) & (-(x)))
#define rep(i, l, r) for (int i = l; i <= r; i++)

using namespace std;
int chh;

const int N = 100005, LEN = 15, C = 10005, INF = ~0U >> 2;

struct NODE {
    int id, v;
    NODE() {}
    NODE(int X, int Y) : id(X), v(Y) {}
} q[C];

int n, t;
int dp[C], g[105][105];

int main() {
    file_r("in.txt");
    file_w("out.txt");
    int i, j, d, m, s, c, l, r, tmp, ans;
    while (~scanf("%d %d", &n, &t)) {
        memset(g, 0, sizeof(g));
        for (i = 1; i <= n; i++) {
            scanf("%*c%*s %d %d", &s, &m);
            g[s][m]++;
        }
        memset(dp, 0, sizeof(dp));
        ans = 0;
        for (s = 1; s <= 100; s++) {
            for (m = 0; m <= 100; m++) {
                c = g[s][m];
                if (c == 0) continue;
                if (m == 0) {
                    ans += c * s;
                    continue;
                }
                for (d = 0; d < m; d++) {
                    l = r = 0;
                    for (j = 0; j <= (t - d) / m; j++) {
                        tmp = dp[j * m + d] - j * s;
                        while (l != r && q[r - 1].v <= tmp) r--;
                        q[r++] = NODE(j, tmp);
                        while (l != r && q[l].id < j - c) l++;
                        dp[j * m + d] = q[l].v + j * s;
                    }
                }
            }
        }
        printf("%d\n", dp[t] + ans);
    }
    return 0;
}
