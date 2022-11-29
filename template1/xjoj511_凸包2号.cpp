#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath> 
using namespace std;

struct mypoint
{
    double x,y;   
};

mypoint a[35], b[35];
int stack[35], id[35];
int t, n, top, p, q, n1, n2;

double dis(mypoint p1, mypoint p2)
{
     double ans = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
     return sqrt(ans);  
}

double judge(mypoint p1, mypoint p2, mypoint p0)
{  
    mypoint t1,t2;
    t1.x = p1.x - p0.x;
    t1.y = p1.y - p0.y;
    t2.x = p2.x - p0.x;
    t2.y = p2.y - p0.y;
    double r = t1.x * t2.y - t1.y * t2.x;
    return r;
}

int cmp(mypoint p1 ,mypoint p2)
{
    double ans = judge(p1, p2, a[1]);
    if (ans > 0)  return 1;
    if (ans == 0 && dis(p1, a[1]) < dis(p2, a[1])) return 1;
    return 0;
}

int graham()
{
    double m;
    int i;
    top = 2;
    stack[1] = 1;
    stack[2] = 2;
    for (i = 3; i <= n; i++)
    {
        top++;
        stack[top] = i;
        m = judge(a[stack[top]], a[stack[top-2]], a[stack[top-1]]);
        while (m < 0)
        {
             stack[top-1] = stack[top];
             top--;
             m = judge(a[stack[top]], a[stack[top-2]], a[stack[top-1]]);
        }
    } 
    return 1;
}

int cout_ans()
{
    double ans = 0.0;
    int  i, hh, g1, g2;
    n1 = 0, n2 = 0; 
    for (i = 1; i < top; i++)
    {
        g1 = id[stack[i + 1]], g2 = id[stack[i]];
        if (abs(g1 - g2) != 1 && abs(g1 - g2) != (n - 1)) n1++;
        else n2++;
    }
    g1 = id[stack[top]], g2 = id[stack[1]];
    if (abs(g1 - g2) != 1 && abs(g1 - g2) != (n - 1)) n1++;
    else n2++;
    hh = (-p) * n1 + q * n2;
    if (hh < 0)
        printf("0\n");
    else
        printf("%d\n", hh);
    return 1;
}
int main()
{
    int i, j, k;
    scanf("%d", &t);
    while (t--)
    {
        double mx = 999999.0,my = 999999.0;
        scanf("%d%d%d", &p, &q, &n);
        for (i = 1;i <= n; i++)
        {
            scanf("%lf %lf", &a[i].x, &a[i].y);
            b[i] = a[i];
            if (a[i].x < mx || (a[i].x == mx && a[i].y < my))
            {
                mx = a[i].x;
                my = a[i].y;
                k = i;           
            }
        }
        swap(a[1], a[k]);
        sort(a + 2 ,a + n + 1, cmp);
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (b[j].x == a[i].x && b[j].y == a[i].y)
                    id[i] = j;
            }
        }
        graham();
        cout_ans();
    }
    system("pause");
    return 1;
}
