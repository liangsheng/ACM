/*
ID:Shuaicpp
Prog:HDU3310-Volume of a cylinder
Lang:C++
Algorithm:f = sqrt((sqr(r1)-sqr(x))*(sqr(r2)-sqr(x)));求0~r1的积分
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#define sqr(x) ((x)*(x))
using namespace std;
const int LEN = 1<<18;
double f(double r1,double r2,double x)
{
    return sqrt((sqr(r1)-sqr(x))*(sqr(r2)-sqr(x)));
}
double calc(double r1,double r2)
{
    double sum = 0,dx = r1 / LEN;
    for (int i = 0;i < LEN;i++)
        sum += f(r1,r2,i * dx + dx / 2);
    return 8 * sum * dx;
}
int main()
{
    int m;
    scanf("%d",&m);
    while (m--)
    {
        double r1,r2;
        scanf("%lf%lf",&r1,&r2);
        if (r1 > r2)
            swap(r1,r2);
        printf("%.2lf\n",calc(r1,r2));
    }
    return 0;
}
