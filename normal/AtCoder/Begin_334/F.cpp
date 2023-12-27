//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 200010
using namespace std;
ll n,k,dx[N],dy[N];
double sum[N],dp[N];
double dis(ll x,ll y)
{
	return sqrt((dx[x]-dx[y])*(dx[x]-dx[y])+(dy[x]-dy[y])*(dy[x]-dy[y]));
}
int main(){
	ll i;
	scanf("%lld%lld",&n,&k);
	for(i=0;i<=n;i++)
	{
		scanf("%lld%lld",&dx[i],&dy[i]);
	}
	for(i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+dis(i-1,i);
	}
	dp[0]=0;
	deque<pair<double,ll> > dq;
	dq.push_back(make_pair(0+dis(0,1)-sum[1],0));
	for(i=1;i<=n;i++)
	{
		while(dq.front().S<i-k)
		{
			dq.pop_front();
		}
		ll j=dq.front().S;
		dp[i]=dp[j]+dis(0,j+1)+sum[i]-sum[j+1]+dis(0,i);
		double curv=dp[i]+dis(0,i+1)-sum[i+1];
		while((!dq.empty())&&dq.back().F>curv)
		{
			dq.pop_back();
		}
		dq.push_back(make_pair(curv,i));
	}
	printf("%.12lf\n",dp[n]);
	return 0;
}