/*
方案：对于不互质的模线性方程组，可以进行方程组合并，求出合并后的方程的解，这样就可以很快地推出方程的最终解，复杂度比较低，在一般竞赛中能够很快搞定。
具体实现如下（给出两个方程合并的一种方法）：
x = c1 (mod b1）
x = c2(mod b2)
此时b1,b2不必互质的。
显然可以得到x = k1 * b1 + c1   x = k2* b2 + c2，两个方程合并一下就可以得到：k1 * b1 = c2 - c1 (mod b2)，
这样可以设g=gcd(b1,b2),于是就有b1/g*k1-b2/g*k2=(c2-c1)/g，显然判断(c2-c1)/g是否为整数就能判断是否存在解，
这样在经过类似的变换就能得到k1 = K (mod （b2/g))，最后得到x = K*b1 + c1 (mod (b1 * b2/g))。
对于题目所给正整数的要求，只有一种反例，就是结果输出为0的情况，这个可以特殊考虑，只需要考虑所有数的最小公倍数即可。
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cassert>

#define pause cout << " press any key to continue...",  cin >> chh
#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)

using namespace std;
int chh;

typedef __int64 ll;

ll n, k;
ll m[15], c[15], N;
bool check;

ll exgcd(ll a, ll b, ll &x, ll &y) {
    if(!b) {
        x=1;
        y=0;
        return a;
    } else {
        ll res=exgcd(b,a%b,x,y);
        ll t=x;
        x=y;
        y=t-(a/b)*y;
        return res;
    }
}

ll mod(ll x,ll y) {
    ll res=x%y;
    if(res<=0)
        res=res+y;
    return res;
}

void solve() {
    ll i;
    check=true;
    ll ans=c[1],lcm=m[1],x,y,g;
    if(ans==0)
        ans=m[1];
    for(i=2; i<=n; i++) {
        g=exgcd(lcm,m[i],x,y);
        if((c[i]-ans)%g) {
            check=false;
            break;
        }
        ans=mod(ans+lcm*mod((c[i]-ans)/g*x,m[i]/g),lcm/g*m[i]);
        lcm=lcm/g*m[i];
    }
    if(check) {
        if(N>=ans) {
            printf("%I64d\n",(N-ans)/lcm+1);
        } else {
            printf("0\n");
        }
    } else {
        printf("0\n");
    }
}

int main() {
    ll i,t;
    scanf("%I64d",&t);
    while(t--) {
        scanf("%I64d%I64d",&N,&n);
        for(i=1; i<=n; i++)
            scanf("%I64d",&m[i]);
        for(i=1; i<=n; i++)
            scanf("%I64d",&c[i]);
        solve();
    }
    return 0;
}
