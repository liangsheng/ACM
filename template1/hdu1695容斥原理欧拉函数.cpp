#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define eps 1e-8
#define PI 3.14159265358979
#define inf 0x3fffffff
#define L 100005

long long e[L];
int prime[L][20], num[L];    //prime[i][j]储存i的第j个质因子，num[i]储存i的质因子个数

void Euler ()
{
    int i, j;
    for (i = 1; i < L; i++)    //初始化
        e[i] = i;
    for (i = 2; i < L; i++)
    {
        if (e[i] == i)    //只有素数才可进来
        {
            e[i] = i - 1;
            for (j = i << 1; j < L; j += i)    //求欧拉的同时求质因子
                e[j] = e[j] - e[j] / i, prime[j][num[j]++] = i;
        }
    }
    for (i = 2; i < L; i++)    //递推求和
        e[i] += e[i-1];
}

int dfs (int x, int b, int n)    //求[1,b]中有多少个与n非互质
{
    if (!b)
        return 0;
    int ans = 0, i;
    for (i = x; i < num[n]; i++)
        ans += b/prime[n][i] - dfs (i+1, b/prime[n][i], n);    //容斥原理
    return ans;
}

int main()
{
    int t, a, b, c, d, k, cc = 1, i;
    long long res;
    memset (num, 0, sizeof(num));
    Euler ();
    scanf ("%d", &t);
    while (t--)
    {
        scanf ("%d%d%d%d%d", &a, &b, &c, &d, &k);
        printf ("Case %d: ", cc++);
        if (!k)    //k==0下面作为分母会出大错
        {
            puts ("0");
            continue;
        }
        b /= k, d /= k;    //问题的转化，转化成求gcd=1的对数
        if (d < b)
            d ^= b, b ^= d, d ^= b;
        res = e[b];    //[1,b]和[1,b]的gcd为1的对数
        for (i = b + 1; i <= d; i++)    //求[b+1,d]与[1,d]的互质对数
            res += b - dfs (0, b, i);    //已经无法用语言形容了，我反正信了
        printf ("%I64d\n", res);
    }
    return 0;
}
