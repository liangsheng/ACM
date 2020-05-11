#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
#define LL __int64
#define maxN 100010
inline LL MIN(LL a, LL b)
{
    return a<b?a:b;
}
set<LL> Q;
int queue[maxN], front, rear;
LL a[maxN], dp[maxN];
int n;
LL m;
bool init()
{
    scanf("%d %I64d", &n, &m);
    for(int i=1; i<=n; i++)
    {
        scanf("%I64d", &a[i]);
        if(a[i]>m) return false;
    }
    return true;
}
LL calc()
{
    Q.clear();
    int li=1;
    LL sum=0;
    front=-1;
    rear=0;
    dp[0]=0;
    for(int i=1; i<=n; i++)
    {
        sum+=a[i];
        for(; sum>m; sum-=a[li], li++);
        if(front >= rear && queue[rear]<li)
        {
            if(front > rear) Q.erase(dp[queue[rear]] + a[queue[rear+1]]);
            rear++;
        }
        for(; front >= rear && a[i]>= a[queue[front]]; front--)
        {
            if(front > rear) Q.erase(dp[queue[front-1]] + a[queue[front]]);
        }
        if(front >= rear) Q.insert(dp[queue[front]] + a[i]);
        queue[++front]=i;
        dp[i]=dp[li-1]+a[queue[rear]];
        if(Q.begin()!=Q.end())
            dp[i]=MIN(dp[i], *Q.begin());
    }
    return dp[n];
}
int main()
{
//    freopen("1.txt", "r", stdin);
    if(!init()) printf("-1\n");
    else printf("%I64d\n", calc());
    return 0;
}



