#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<string>
#include<map>
#include<set>
//#pragma comment(linker, "/STACK:36777216") //if stack overflow
using namespace std;

#define LarN 100000
typedef long long LL;
const double d_pi = 57.2957795;

template<class T> inline void ReMin(T &a,T b){if(b<a) a=b;}
template<class T> inline void ReMax(T &a,T b){if(b>a) a=b;}
template<class T> inline T sqr(T x){return x*x;}


LL fact[LarN + 5], factInv[LarN + 5], powNum[LarN + 5];
LL MOD;
int X1, X2, Y1, Y2, p;

LL mypow(LL x, LL p){
    LL ret = 1;
    while(p > 0){
        if(p&1)ret = ret*x%MOD;
        p >>= 1;
        x = x*x%MOD;
    }
    return ret;
}

LL numberReverse_int64(LL a,LL b){
    if( b ==0 )return 0;
    LL ret=1,c=0,d,p,m=b;
    //a*ret % b == 1
    if ( a>b ) a = a%b;
    while(a>1){
        p = b/a;
        d = a;
        a = b - p*a;
        b = d;

        d = ret;
        ret = c - ret*p;
        c = d;
    }
    if( a==0 )return 0;
    return ((ret%m)+m)%m;
}

void init(){
    fact[0] = 1;
    powNum[0] = 0;
    factInv[0] = 1;
    for(int i = 1; i <= LarN ; i++){
        int acc = 0;
        int k = i;
        while(k%MOD==0){
            acc ++;
            k /= MOD;
        }
        powNum[i] = powNum[i-1] + acc;
        fact[i] = fact[i-1]*k%MOD;
        factInv[i] = numberReverse_int64(fact[i], MOD);
    }
}

LL comb(int x, int y){
    if(y < 0 || y > x)return 0;
    if(powNum[x] > powNum[y] + powNum[x-y]) return 0;
    return fact[x]*factInv[y]%MOD*factInv[x-y]%MOD;
}

void solve(){
    MOD = p;
    init();
    LL ans = 0;
    LL a0 = comb(X1, Y1-1), ak = comb(X1, Y2);
    LL mid = 0;
    for(int i = Y1; i <= Y2; i ++){
        mid += comb(X1, i);
    }
    mid %= MOD;
    ans += mid;
    for(int r = X1 + 1; r <= X2; r ++){
        mid = (2*mid + a0 - ak + MOD)%MOD;
        a0 = comb(r, Y1-1);
        ak = comb(r, Y2);
        ans += mid;
    }

    ans %= MOD;
    printf("%I64d\n", ans);
}



int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

    while(scanf("%d%d%d%d%d",&X1, &Y1, &X2, &Y2, &p) != EOF){
        solve();
    }
    return 0;
}
