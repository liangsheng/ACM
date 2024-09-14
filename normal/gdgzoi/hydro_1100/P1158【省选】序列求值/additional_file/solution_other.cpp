// 来自: https://blog.csdn.net/lalala445566/article/details/101386798

#include <iostream>
#include <cstring> 
#include <cstdio>
using namespace std;
typedef long long ll;
#define wfor(i,j,k) for(i=j;i<k;++i)
#define mfor(i,j,k) for(i=j;i>=k;--i)
// void read(ll &x) {
// 	char ch = getchar(); x = 0;
// 	for (; ch < '0' || ch > '9'; ch = getchar());
// 	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
// }
const ll mod=1e9+6;
const ll mod2=1e9+7;
struct Matix
{
    ll ma[5][5];
};
Matix mul(Matix a,Matix b,ll n)
{
    ll i,j,k;
    Matix c;
    memset(c.ma,0,sizeof(c.ma));
    wfor(i,0,n)
    {
        wfor(j,0,n)
        {
            wfor(k,0,n)
            {
                c.ma[i][j]=(c.ma[i][j]+(a.ma[i][k]*b.ma[k][j]%mod))%mod;
            }
        }
    }
    return c;
}
Matix ksm(Matix a,ll b,ll n)
{
    Matix ans;
    memset(ans.ma,0,sizeof(ans.ma));
    ll i;
    wfor(i,0,n)
    {
        ans.ma[i][i]=1;
    }
    while(b)
    {
        if(b&1)
            ans=mul(ans,a,n);
        a=mul(a,a,n);
        b>>=1;
    }
    return ans;
}
ll ksm_num(ll a,ll b)
{
    ll ans=1;
    while(b)
    {
        if(b&1)
        {
            ans=ans*a%mod2;
        }
        a=a*a%mod2;
        b>>=1;
    }
    return ans;
}
int main()
{
    std::ios::sync_with_stdio(false);
    #ifdef test
    freopen("F:\\Desktop\\question\\in.txt","r",stdin);
    #endif
    #ifdef ubuntu
    freopen("/home/time/debug/debug/in","r",stdin);
    freopen("/home/time/debug/debug/out","w",stdout);
    #endif
    ll n, f1,f2,f3,c;
    cin>>n>>f1>>f2>>f3>>c;
    Matix ori={{{0,0,1},{1,0,1},{0,1,1}}};
    Matix F1={{{1,1,2}}};
    Matix F2={{{1,2,3}}};
    Matix F3={{{1,2,4}}};
    Matix C={{{2,6,14,6,2}}};
    Matix C_ori={{{0,0,1,0,0},{1,0,1,0,0},{0,1,1,0,0},{0,0,1,1,0},{0,0,1,1,1}}};
    ll res=0;
    if(n>=7)
    {
        n-=6;
        Matix temp=ksm(ori,n,3);
        Matix ans=mul(F1,temp,3);//算f1的指数
        cout << "fn1= " << ans.ma[0][2];
        res=ksm_num(f1,ans.ma[0][2]);
        ans=mul(F2,temp,3);//算f2的指数
        cout << ", fn2= " << ans.ma[0][2];
        res=res*ksm_num(f2,ans.ma[0][2])%mod2;
        ans=mul(F3,temp,3);//算f3的指数
        cout << ", fn3= " << ans.ma[0][2] << '\n';
        res=res*ksm_num(f3,ans.ma[0][2])%mod2;
        temp=ksm(C_ori,n,5);
        ans=mul(C,temp,5);//算c的指数
        cout << "cnt= " << ans.ma[0][2] << '\n';
        res=res*ksm_num(c,ans.ma[0][2])%mod2;
        cout<<res<<endl;
    }else 
    {
        n-=4;
        res=ksm_num(f1,F1.ma[0][n])%mod2;
        res=res*ksm_num(f2,F2.ma[0][n])%mod2;
        res=res*ksm_num(f3,F3.ma[0][n])%mod2;
        res=res*ksm_num(c,C.ma[0][n])%mod2;
        cout<<res<<endl;
    }
    return 0;
}
/*
1000000000000000000 1000000000 1000000000 1000000000 1000000000
*/