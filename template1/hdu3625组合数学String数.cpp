/*
　　第一类Stirling数是有正负的，其绝对值是包含n个元素的集合分作k个环排列的方法数目。
　　递推公式为，
　　S(n,0) = 0, S(1,1) = 1.
　　S(n+1,k) = S(n,k-1) + nS(n,k)。
　　第二类Stirling数是把包含n个元素的集合划分为正好k个非空子集的方法的数目。
　　递推公式为：
　　S(n,k)=0; (n<k||k=0)
　　S(n,n) = S(n,1) = 1,
　　S(n,k) = S(n-1,k-1) + kS(n-1,k).
　　将n个有区别的球的球放入k个无标号的盒子中( n>=k>=1，且盒子不允许为空)的方案数就是stirling数.(即含 n 个元素的集合划分为 k 个集合的情况数)
　　递推公式:
　　S(n,0) = 0
　　S(n,1) = 1 (k = 1)
　　S(n,n) = 1
　　S(n,k) = 0 (k > n)
　　S(n,k) = S(n-1,k-1)+k*S(n-1,k) (n >= k >= 2)
　　分析：设有n个不同的球，分别用b1,b2,...,bn表示。从中取出一个球bn，bn的放法有以下两种：
　　1.bn独占一个盒子，那么剩下的球只能放在k-1个盒子里，方案数为S（n-1,k-1);
　　2.bn与别的球共占一个盒子，那么可以将b1,b2,...,bn-1这n-1个球放入k个盒子里，然后将bn放入其中一个盒子中，方案数为k*S(n-1,k).
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define inf (1 << 30)
#define N 21
const double eps = 1e-12;
const double pi = acos(-1.0);
using namespace std;

__int64 ans[N][N], f[N];

int main()
{
    int i , j, n, a, b;
    __int64 sum;
    memset(ans, 0, sizeof(ans));
    memset(f, 0, sizeof(f));
    ans[1][1] = 1;
    for (i = 2; i <= 20; i++)
    {
        for (j = 1; j <= i; j++)
            ans[i][j] = ans[i - 1][j - 1] + (i - 1) * ans[i - 1][j];
    }
    f[0] = 1;
    for (i = 1; i <= 20; i++) f[i] = f[i - 1] * i;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d%d", &a, &b);
        sum = 0;
        for (i = 1; i <= b; i++)
            sum += ans[a][i] - ans[a - 1][i - 1];
        printf("%.4lf\n", double(sum) / double(f[a]));
    }
    system("pause");
    return 0;
}
