/*
平面上两点间的 Chebyshev距离为 max(|x1-x2|, |y1-y2|)
对于原坐标系中两点间的 Chebyshev 距离，是将坐标轴顺时针旋转45度
并将所有点的坐标值放大sqrt(2)倍所得到的新坐标系中的Manhattan距离的二分之一。
x2 = x1 * cos(a) - y1 * sin(a);
y2 = y1 * cos(a) + x1 * sin(a);
*/
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

const LL N = 100005, INF = ~0ULL >> 2;

struct NODE {
    LL x, y;
} p[N];

LL T, n;
LL x[N], y[N];
LL dx1[N], dx2[N], dy1[N], dy2[N];

int main() {
    LL i, j, tx, ty, ans, tmp, u, v;
    scanf("%lld", &T);
    while (T--) {
        scanf("%lld", &n);
        for (i = 0; i < n; i++) {
            scanf("%lld %lld", &u, &v);
            p[i].x = u - v, p[i].y = u + v;
            x[i] = p[i].x, y[i] = p[i].y;
        }
        sort(x, x + n);
        sort(y, y + n);
        dx1[0] = dy1[0] = 0;
        for (i = 1; i < n; i++) {
            dx1[i] = dx1[i - 1] + x[i] - x[0];
            dy1[i] = dy1[i - 1] + y[i] - y[0];
        }
        dx2[n - 1] = dy2[n - 1] = 0;
        for (i = n - 2; i >= 0; i--) {
            dx2[i] = dx2[i + 1] + x[n - 1] - x[i];
            dy2[i] = dy2[i + 1] + y[n - 1] - y[i];
        }
        ans = INF;
        for (i = 0; i < n; i++) {
            tx = lower_bound(x, x + n, p[i].x) - x;
            ty = lower_bound(y, y + n, p[i].y) - y;
            tmp = dx2[0] - dx2[tx] - (x[n - 1] - x[tx]) * tx;
            tmp += dx1[n - 1] - dx1[tx] - (x[tx] - x[0]) * (n - 1 - tx);
            tmp += dy2[0] - dy2[ty] - (y[n - 1] - y[ty]) * ty;
            tmp += dy1[n - 1] - dy1[ty] - (y[ty] - y[0]) * (n - 1 - ty);
            ans = min(ans, tmp);
        }
        printf("%lld\n", ans / 2);
    }
    return 0;
}
