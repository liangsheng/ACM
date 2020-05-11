# include <iostream>
# include <cstdio>
# include <cstring>
# include <cmath>
# define MAX 50001
using namespace std;

struct NODE
{
    int l,r;
    int v;   
};

int n;
int s[MAX],x[MAX],y[MAX],dp[MAX];
NODE node[MAX*3];

int Build_Tree(int s,int t,int k)
{
    node[k].l=s;
    node[k].r=t;
    node[k].v=0;
    if (s==t)
    return 1;
    int mid=(s+t)>>1;
    Build_Tree(s,mid,k<<1);
    Build_Tree(mid+1,t,(k<<1)+1);
    return 1;
}

int get_max(int s,int t,int k)
{ 
    if (s>n)
    return 0;
    if (node[k].l==s&&node[k].r==t)
    return node[k].v;                                                     
    int mid=(node[k].l+node[k].r)>>1,sum=-1;
    if (t<=mid)
    sum=max(sum,get_max(s,t,k<<1));
    else
    if (s>mid)
    sum=max(sum,get_max(s,t,(k<<1)+1));
    else
    {
        sum=max(sum,get_max(s,mid,k<<1));
        sum=max(sum,get_max(mid+1,t,(k<<1)+1));
    }
    return sum;
}

int find(int x,int k)
{
    if (node[k].l==node[k].r&&node[k].l==x)
    {
       node[k].v=dp[x];
       return 1;                                    
    }
    node[k].v=max(node[k].v,dp[x]);
    int mid=(node[k].l+node[k].r)>>1;
    if (x<=mid)
    find(x,k<<1);
    else
    find(x,(k<<1)+1);
    return 1;
}

int solve(int k)
{
    int l,r;
    l=k+x[k];
    r=min(k+y[k]-1,n);    
    dp[k]=s[k]+get_max(l,r,1);
    find(k,1);
    return 1;
}

int main()
{
    int i;
    while (scanf("%d",&n)!=EOF)
    {
        Build_Tree(1,n,1);
        memset(dp,-1,sizeof(dp)); 
        for (i=1;i<=n;i++)
        scanf("%d%d%d",&s[i],&x[i],&y[i]);
        for (i=n;i>=1;i--)
        solve(i);
        printf("%d\n",dp[1]); 
    }
    system("pause");
    return 0;
}
