#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#define mod 1000000007
#define N 100005
#define inf (1 << 30)
const double eps = 1e-12;
const double pi = acos(-1.0);
using namespace std;

int n, m, k;
int f[N], p[N], q[N];

int main()
{
    int i, x, ans, p1, p2, q1, q2, now;
    while (~scanf("%d%d%d", &n, &m, &k))
    {
        for (i = 1; i <= n; i++) scanf("%d", &f[i]);
        p1 = p2 = q1 = q2 = 0;
        ans =  0, now = 1;
        for (i = 1; i <= n; i++)
        {
            while (p1 < p2 && f[i] < f[p[p2 - 1]]) p2--;   //µÝÔö
            p[p2++] = i;
            while (q1 < q2 && f[i] > f[q[q2 - 1]]) q2--;    //µÝ¼õ
            q[q2++] = i;
            while (f[q[q1]] - f[p[p1]] > k)
            {
                if (p[p1] < q[q1]) now = p[p1] + 1, p1++;
                else now = q[q1] + 1, q1++;
            }
            if (f[q[q1]] - f[p[p1]] <= k && f[q[q1]] - f[p[p1]] >= m)
                ans = max(ans, i - now + 1);
        }
        printf("%d\n", ans);
    }
    system("pause");
    return 0;
}


