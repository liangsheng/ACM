#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
struct Point {
    double x,y;
};
struct Line {
    Point a,b;
    Line (Point a,Point b):a(a),b(b) {}
    Line() {}
} l[1600];
int cmp(double a) {
    if(abs(a)<1e-6)return 0;
    return a < -1e-6 ? -1 : 1;
}
inline int cross_product(Point a,Point b,Point c) {
    return cmp((a.x-c.x)*(b.y-c.y)-(b.x-c.x)*(a.y-c.y));
}
inline bool dot_online_in(Point p,Line l) {
    return (cross_product(p,l.a,l.b)==0)&&(cmp((l.a.x-p.x)*(l.b.x-p.x))<=0)
           &&(cmp((l.a.y - p.y)*(l.b.y-p.y))<=0);
}
inline int same_said(Point a,Point b,Line l) {
    return cross_product(l.a,a,b)*cross_product(l.b,a,b);
}
inline bool intersect_in(Line la,Line lb) {
    if(cross_product(la.a,la.b,lb.a)||cross_product(la.a,la.b,lb.b))
        return(same_said(la.a,la.b,lb)<=0 && same_said(lb.a,lb.b,la)<=0);
    return dot_online_in(la.a,lb)||dot_online_in(la.b,lb)
           ||dot_online_in(lb.a,la)||dot_online_in(lb.b,la);
}
bool ans(Point o,Point q,Line l) {
    Point tp;
    tp.x = q.x - o.x;
    tp.y = q.y - o.y;
    tp.x = 10000*tp.x + o.x;
    tp.y = 10000*tp.y + o.y;
    return intersect_in(l,Line(o,tp));
}
int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        Point o;
        int n;
        scanf("%d",&n);
        for(int i = 0; i < n; i++ ) {
            scanf("%lf%lf%lf%lf",&l[i].a.x,&l[i].a.y,&l[i].b.x,&l[i].b.y);
        }
        scanf("%lf%lf",&o.x,&o.y);
        int re=1;
        for(int i = 0; i < n; i++ ) {
            int cnt1 =0,cnt2=0;
            for(int j = 0; j<n; j++) {
                if(ans(o,l[i].a,l[j]))
                    cnt1++;
                if(ans(o,l[i].b,l[j]))
                    cnt2++;
            }
            if(cnt1>re) re = cnt1;
            if(cnt2>re) re =cnt2;
        }
        printf("%d\n",re);
    }
    return 0;
}
