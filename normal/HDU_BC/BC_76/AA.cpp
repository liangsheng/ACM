#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

#define MAXN 150
int ans[MAXN];
int n,k,sum;

int main()
{
    while(~scanf("%d",&n))
    {
        memset(ans,0,sizeof(ans));
        k=0;
        ans[k++]=2;
        ans[k++]=3;
        sum=5;
        while(sum+ans[k-1]+1<=n)
        {
            ans[k]=ans[k-1]+1;
            sum+=ans[k++];
        }
        int tmp=n-sum;
        while(tmp>0)
        {
            for(int i=k-1;tmp>0 && i>=0;i--)
                ans[i]++,tmp--;
        }
        printf("%d",ans[0]);
        for(int i=1;i<k;i++)
            printf(" %d",ans[i]);
        printf("\n");
    }
    return 0;
}
