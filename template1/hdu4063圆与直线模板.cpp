#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iostream>
#include <sstream>

const double eps = 1e-8;
const double inf = 1e20;

using namespace std;

bool EQ(const double &x, const double &y) { return fabs(x - y) < eps; }  //判相等
bool LT(const double &x, const double &y) { return x + eps < y; }        //判小于
bool GT(const double &x, const double &y) { return x > y + eps; }        //判大于
bool LE(const double &x, const double &y) { return x < y + eps; }        //判小于等于
bool GE(const double &x, const double &y) { return x + eps > y; }        //判大于等于

struct Pnt {                                                             //point点
    double x, y;
    Pnt(double _x = 0.0, double _y = 0.0) : x(_x), y(_y) {}
    bool operator < (const Pnt &oth) const {
        return LT(x, oth.x) || EQ(x, oth.x) && LT(y, oth.y);
    }
};
struct Rnd {                                                             //圆
    double x, y, r;
    Rnd(double _x = 0.0, double _y = 0.0, double _r = 0.0) : x(_x), y(_y), r(_r) {}
};
struct Lin {                                                             //线段
    Pnt a, b;
    bool operator < (const Lin &oth) const {
        return a < oth.a;
    }
};

double PP_dis(const Pnt &p1, const Pnt &p2) {                            //点与点间的距离
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

int Equa(const double &A, const double &B, const double &C, double &x1, double &x2) {    //解一元二次方程
    double f = B * B - 4.0 * A * C;
    if (f < 0.0) return -1;
    x1 = (-B + sqrt(f)) / (2.0 * A);
    x2 = (-B - sqrt(f)) / (2.0 * A);
    return 1;
}

void L_fmt(const Pnt &u, const Pnt &v, double &A, double &B, double &C) {      //Ax + By + c = 0, 计算过u, v的直线
    if (EQ(u.x, v.x)) {
        A = 1.0; B = 0.0; C = -u.x;
    } else if (EQ(u.y, v.y)) {
        A = 0.0; B = 1.0; C = -u.y;
    } else {
        A = v.y - u.y;
        B = u.x - v.x;
        C = -(A * u.x + B * u.y);
    }
}

double PL_dis(const Pnt &p, const Pnt &u, const Pnt &v) {          //点到直线的距离
    double A, B, C;
    L_fmt(u, v, A, B, C);
    return fabs(A * p.x + B * p.y + C) / sqrt(A * A + B * B);
}

Pnt LL_cro(const Pnt &u1, const Pnt &u2, const Pnt &v1, const Pnt &v2) {   //直线与直线的交点
    double t = ((u1.x - v1.x) * (v1.y - v2.y) - (u1.y - v1.y) * (v1.x - v2.x)) /
               ((u1.x - u2.x) * (v1.y - v2.y) - (u1.y - u2.y) * (v1.x - v2.x));
    return Pnt(u1.x + (u2.x - u1.x) * t, u1.y + (u2.y - u1.y) * t);
}

void LR_cro(const Rnd &r, const Pnt &a, const Pnt &b, Pnt &p1, Pnt &p2) {   //直线与圆的交点
    Pnt p(r.x + a.y - b.y, r.y - a.x + b.x);
    p = LL_cro(p, Pnt(r.x, r.y), a, b);
    double d1 = PP_dis(p, Pnt(r.x, r.y));
    double d2 = PP_dis(a, b);
    double t = sqrt(r.r * r.r - d1 * d1) / d2;
    p1.x = p.x + (b.x - a.x) * t;
    p1.y = p.y + (b.y - a.y) * t;
    p2.x = p.x - (b.x - a.x) * t;
    p2.y = p.y - (b.y - a.y) * t;
}

void SLR_cro(const Rnd &r, const Pnt &u, const Pnt &v, Pnt &p1, Pnt &p2) {   //线段与圆的交点
    double A, B, C, t1, t2;
    L_fmt(u, v, A, B, C);
    if (EQ(B, 0.0)) {
        p1.x = p2.x = -1.0 * C / A;
        Equa(1.0, -2.0 * r.y, r.y * r.y + (p1.x - r.x) * (p1.x - r.x) - r.r * r.r, t1, t2);
        p1.y = t1; p2.y = t2;
    } else if (EQ(A, 0.0)) {
        p1.y = p2.y = -1.0 * C / B;
        Equa(1.0, -2.0 * r.x, r.x * r.x + (p1.y - r.y) * (p1.y - r.y) - r.r * r.r, t1, t2);
        p1.x = t1; p2.x = t2;
    } else {
        Equa(A * A + B * B, 2.0 * A * C + 2.0 * A * B * r.y - 2.0 * B * B * r.x,
             B * B * r.x * r.x + C * C + 2.0 * B * C * r.y + B * B * r.y * r.y - B * B * r.r * r.r, t1, t2);
        p1.x = t1, p1.y = -1.0 * (A / B * t1 + C / B);
        p2.x = t2, p2.y = -1.0 * (A / B * t2 + C / B);
    }
}

int RR_cro(const Rnd &r1, const Rnd &r2, Pnt &p1, Pnt &p2) {    //圆与圆的交点
    double dis = PP_dis(Pnt(r1.x, r1.y), Pnt(r2.x, r2.y));
    if (GT(dis, r1.r + r2.r)) return 0;
    else if (EQ(dis, r1.r + r2.r)) {
        p1.x = (r1.r * r2.x + r2.r * r1.x) / (r1.r + r2.r);
        p1.y = (r1.r * r2.y + r2.r * r1.y) / (r1.r + r2.r);
        return 1;
    } else if (EQ(dis, fabs(r1.r - r2.r))) {
        p1.x = (r1.r * r2.x - r2.r * r1.x) / (r1.r - r2.r);
        p1.y = (r1.r * r2.y - r2.r * r1.y) / (r1.r - r2.r);
        return 1;
    } else {
        double t = (1.0 + (r1.r * r1.r - r2.r * r2.r) / dis / dis) / 2.0;
        Pnt u(r1.x + (r2.x - r1.x) * t, r1.y + (r2.y - r1.y) * t);
        Pnt v(u.x + r1.y - r2.y, u.y - r1.x + r2.x);
        LR_cro(r1, u, v, p1, p2);
        return 2;
    }
}

int n, k, cas = 1;
Rnd r[20], c[40];
Pnt p[400];
double dis[400][400], cst[400];
bool vis[400];

bool Check(Pnt u, Pnt v) {
    int i, t = 0;
    static Lin val[20];
    Pnt a, b, x;
    if (v < u) swap(u, v);
    for (i = 0; i < n; i++) {
        if (LT(PL_dis(Pnt(r[i].x, r[i].y), u, v), r[i].r)) {
            SLR_cro(r[i], u, v, a, b);
            if (b < a) swap(a, b);
            if (b < u) continue; if (v < a) continue;
            if (a < u) a = u;    if (v < b) b = v;
            val[t].a = a;        val[t].b = b;
            t++;
        }
    }
    sort(val, val + t);
    x = u;
    for (i = 0; i < t; i++) {
        if (!(x < val[i].a) && x < val[i].b)
            x = val[i].b;
    }
    if (x < v) return false;
    else return true;
}

void CalDis() {
    int i, j;
    for (i = 0; i < k; i++) {
        dis[i][i] = 0.0;
        for (j = i + 1; j < k; j++) {
            if (Check(p[i], p[j])) dis[i][j] = dis[j][i] = PP_dis(p[i], p[j]);
            else dis[i][j] = dis[j][i] = inf;
        }
    }
}

void Solve() {
    int i, j;
    double mi;

    for (i = 0; i < k; i++) cst[i] = inf;
    cst[0] = 0.0;
    memset(vis, 0, sizeof(vis));
    while (true) {
        mi = inf;
        for (i = 0; i < k; i++) {
            if (!vis[i] && LT(cst[i], mi)) {
                mi = cst[i];
                j = i;
            }
        }
        if (LT(mi, inf)) vis[j] = 1;
        else break;
        if (j == n - 1) break;
        for (i = 0; i < k; i++) {
            if (!vis[i] && LT(cst[j] + dis[i][j], cst[i]))
                cst[i] = cst[j] + dis[i][j];
        }
    }
    printf("Case %d: ", cas++);
    if (!vis[n-1]) printf("No such path.\n");
    else printf("%.4lf\n", cst[n-1]);
}

int main() {
    int test, cas, i, j, t;
    Pnt p1, p2;
    scanf("%d", &test);
    for (cas = 1; cas <= test; cas++) {
        scanf("%d", &n);
        k = 0;
        for (i = 0; i < n; i++) {
            scanf("%lf %lf %lf", &r[i].x, &r[i].y, &r[i].r);
            p[k++] = Pnt(r[i].x, r[i].y);
        }
        for (i = 0; i < n; i++) {
            for (j = i + 1; j < n; j++) {
                t = RR_cro(r[i], r[j], p1, p2);
                if (t == 1) { p[k++] = p1; }
                if (t == 2) { p[k++] = p1; p[k++] = p2; }
            }
        }
        CalDis();
        Solve();
    }
    return 0;
}
