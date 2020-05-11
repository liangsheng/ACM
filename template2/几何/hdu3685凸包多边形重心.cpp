#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

#define pause cout << " press any key to continue...",  cin >> chh
#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)

using namespace std;
int chh;

/*==================================================*\
| Graham 求凸包 O(N * logN)
| CALL: nr = graham(pnt, int n, res); res[]为凸包点集;
\*==================================================*/
struct point {
    double x, y;
    point() {}
    point(double X, double Y) : x(X), y(Y) {}
};

bool mult(point sp, point ep, point op) {
    return (sp.x - op.x) * (ep.y - op.y)
           >= (ep.x - op.x) * (sp.y - op.y);
}

bool operator < (const point &l, const point &r) {
    return l.y < r.y || (l.y == r.y && l.x < r.x);
}

int graham(point pnt[], int n, point res[]) {
    int i, len, k = 0, top = 1;
    sort(pnt, pnt + n);
    if (n == 0) return 0;
    res[0] = pnt[0];
    if (n == 1) return 1;
    res[1] = pnt[1];
    if (n == 2) return 2;
    res[2] = pnt[2];
    for (i = 2; i < n; i++) {
        while (top && mult(pnt[i], res[top], res[top-1]))
            top--;
        res[++top] = pnt[i];
    }
    len = top;
    res[++top] = pnt[n - 2];
    for (i = n - 3; i >= 0; i--) {
        while (top!=len && mult(pnt[i], res[top],
                                res[top-1])) top--;
        res[++top] = pnt[i];
    }
    return top;
// 返回凸包中点的个数
}

/*==================================================*\
| 求多边形重心
| INIT: pnt[]已按顺时针(或逆时针)排好序;
| CALL: res = bcenter(pnt, n);
\*==================================================*/
point bcenter(point pnt[], int n) {
    point p, s;
    double tp, area = 0, tpx = 0, tpy = 0;
    p.x = pnt[0].x;
    p.y = pnt[0].y;
    for (int i = 1; i <= n; ++i) { // point: 0 ~ n-1
        s.x = pnt[(i == n) ? 0 : i].x;
        s.y = pnt[(i == n) ? 0 : i].y;
        tp = (p.x * s.y - s.x * p.y);
        area += tp / 2;
        tpx += (p.x + s.x) * tp;
        tpy += (p.y + s.y) * tp;
        p.x = s.x;
        p.y = s.y;
    }
    s.x = tpx / (6 * area);
    s.y = tpy / (6 * area);
    return s;
}

const int N = 50005;

int T, n;
point p[N], res[N];

double cal_dis(point p1, point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

bool judge(point p1, point p2, point p) {
    double a, b, c, r1, r2, eps = 1e-8;
    a = cal_dis(p1, p2);
    b = cal_dis(p1, p);
    c = cal_dis(p2, p);
    r1 = (a * a + b * b - c * c) / (2 * a * b);
    r2 = (a * a + c * c - b * b) / (2 * a * c);
    if (r1 > eps && r2 > eps) return 1;
    return 0;
}

int main() {
    int i, j, k, num;
    point ans;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (i = 0; i < n; i++) scanf("%lf %lf", &p[i].x, &p[i].y);
        ans = bcenter(p, n);
        n = graham(p, n, res);
        num = 0;
        for (i = 0; i < n - 1; i++) {
            if (judge(res[i], res[i + 1], ans)) num++;
        }
        if (judge(res[0], res[n - 1], ans)) num++;
        printf("%d\n", num);
    }
    return 0;
}
