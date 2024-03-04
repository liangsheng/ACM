#include <bits/stdc++.h>
#define ll long long
#define IOS {ios::sync_with_stdio(0);cin.tie(0);}
using namespace std;
const int N = 1e5+100;
int dp[20][120][120][120];
int dig[20];
int len;
ll dfs(int pos,int sum,int last,int mod,bool limit){
    int i;
    if(pos==0) {
        if(last==0&&mod==sum) return 1;
        return 0;
    }
    if(!limit&&dp[pos][sum][last][mod]!=-1) return dp[pos][sum][last][mod];
    int up;
    ll ans=0;
    up = limit?dig[pos]:9;
    for(i = 0;i <= up;i ++)
        ans += dfs(pos-1,sum+i,(last*10+i)%mod,mod,limit&&i==up);
    if(!limit) dp[pos][sum][last][mod] = ans;
    return ans;
}
ll solve(ll n){
    len = 0;
    while(n!=0){
        int x = n%10;
        n /= 10;
        dig[++len] = x;
    }
    ll ans = 0;
    for(int i = 1;i <= 108;i ++)
        ans += dfs(len,0,0,i,1);
    return ans;
}
int main(){
//    freopen("just.in","r",stdin);
//    freopen("just.out","w",stdout);
//    freopen("a.txt","r",stdin);
    IOS;
    ll n;
    memset(dp,-1,sizeof(dp));
    cin>>n;
    cout<<solve(n);
    return 0;
}