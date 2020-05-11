#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define inf (1 << 30)
#define N 10005
const double eps = 1e-12;
const double pi = acos(-1.0);
using namespace std;

int T, n;
double a[N], b[N], c[N];

double get_ans(double mid)
{
    int i;
    double ans = a[1] * mid * mid + b[1] * mid + c[1];
    for (i = 2; i <= n; i++)
        ans = max(ans, a[i] * mid * mid + b[i] * mid + c[i]);
    return ans;
}

int main()
{
    int i, j;
    double low, high, mid, midmid, l1, l2;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (i = 1; i <= n; i++)
            scanf("%lf%lf%lf", &a[i], &b[i], &c[i]);
        low = 0.0, high = 1000.0;
        while (fabs(low - high) > eps)
        {
            mid = (low + high) * 0.5;
            midmid = (mid + high) * 0.5;
            l1 = get_ans(mid), l2 = get_ans(midmid);
            if (l1 < l2) high = midmid;
            else low = mid;
        }
        printf("%.4lf\n", l1);
    }
    system("pause");
    return 0;
}
