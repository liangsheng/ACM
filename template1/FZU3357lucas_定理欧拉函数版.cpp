/*
1）根据一下公式，直接计算

     C(n,m) mod p = n*``*(n-m+1)/(1*``*m) mod p

　　计算分别分子nn、分母mm中p的个数和对p的余数，若分子中p的个数多余分母中p的个数，则结果为0，

　　若不是，则原式变为nn/mm mod p (nn,p)=1,(mm,p)=1

　　此时如何求逆元变得至关重要，以下有两种解法。

2） Lucas 定理：是用来求 C(n,m) mod p的值,p是素数。

　　描述为:

　　Lucas(n,m,p)=C(n%p,m%p)* Lucas(n/p,m/p,p)

　　Lucas(n,0,p)=1;

　　而

　　C(a,b)=a*(a-1)*```*(a-b+1)/(1*2*```*b)%p,

　　其中分子为aa分母为bb，故C(a,b)=aa/bb%p,（此时求法同上）

　　至此逆元的求法也很重要，逆元的求法，如下会有所解释。

补充知识：逆元的求法

　　 (a/b) mod p=a*(b逆) mod p

     b*x=1(mod p) x就是b的逆元

     而b逆可以利用扩展欧几里德或欧拉函数求得：

      1).扩展欧几里德：b*x+p*y=1 有解，x就是所求

      2).欧拉函数：b^(p-1)=1(mod p),故b*b^(p-2)=1(mod p),所以x=b^(p-2)

综上所述，其实方法一可以看成是暴力计算，而方法二中只是将大数变为数，再采用方法一的方法计算，这样时间上会有所降低。


*/
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

__int64 power(__int64 a, __int64 b, __int64 n)
{
    __int64 res = 1;
    for (; b; b >>= 1, a = a * a % n)
        if (b & 1) res = res * a % n;
    return res;
}

__int64 cal(__int64 n, __int64 r, __int64 p)
{
    __int64 i, res = 1, re;
    for(i = 1; i <= r; i++)
    {
        res = res * (n - i + 1) % p;
        re = power(i, p - 2, p);
        res = res * re % p;
    }
    return res;
}

__int64 lucas(__int64 n, __int64 m, __int64 p)
{
    if (n < m) return 0;
    else return cal(n, m, p);
}

int main()
{
    __int64 T, n, m, p;
    __int64 i, j, res, add;
    scanf("%I64d", &T);
    while (T--)
    {
        scanf("%I64d%I64d%I64d", &n, &m, &p);
        res = 1;
        while (n && m)
        {
            res = res * lucas(n % p, m % p, p) % p;
            if (res == 0) break;
            n = n / p;
            m = m / p;
        }
        printf("%I64d\n", res);
    }
    system("pause");
    return 0;
}
