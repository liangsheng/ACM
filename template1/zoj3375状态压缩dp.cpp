# include <iostream>
# include <cstdio>
# include <algorithm>
# include <cmath>
# define MAX 16
using namespace std;

int n;
int a[MAX],b[MAX],x[MAX],y[MAX],d[MAX];
int dp[(1<<15)+10];

int main()
{
    int i,j,pv,tv;
    while (scanf("%d",&n)!=EOF)
    {
        for (i=0;i<n;i++)
        scanf("%d%d%d%d",&a[i],&b[i],&x[i],&y[i]);
        for (i=0;i<n;i++)
        d[i]=max(a[i],b[i])*x[i]*y[i];//cout<<d[0];system("pause");
        fill(dp,dp+(1<<n),0);
        for (i=1;i<(1<<n);i++)
        {
            pv=0,tv=0;
            for (j=0;j<n;j++)
            if (i&(1<<j))
            {
               pv+=b[j]*y[j];
               tv+=a[j]*x[j];          
            }
            for (j=0;j<n;j++)
            if (i&(1<<j))
            dp[i]=max(dp[i],dp[i^(1<<j)]+(pv-b[j]*y[j])*x[j]+(tv-a[j]*x[j])*y[j]+d[j]);  
        }
        printf("%d\n",dp[(1<<n)-1]);  
    }
    system("pause");
    return 1;
}
