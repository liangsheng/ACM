# include <iostream>
# include <cstdio>
# include <cmath>
# include <cstring>
# define MAX 15005
using namespace std;

struct Node
{
    int l,r,v;   
};

int n,input_x[MAX],ans[MAX];
Node node[32000*3];

int Build_Tree(int s,int t,int cnt)
{
    int mid;
    node[cnt].l=s;
    node[cnt].r=t;
    node[cnt].v=0;
    if (s==t)
    return 1;
    mid=(s+t)/2;
    Build_Tree(s,mid,2*cnt);
    Build_Tree(mid+1,t,2*cnt+1);
    return 1;
}

int Find(int s,int t,int cnt)
{//cout<<cnt;system("pause");
    int mid,sum=0;
    if (node[cnt].l==s&&node[cnt].r==t)
    return node[cnt].v;
    mid=(node[cnt].l+node[cnt].r)/2;
    if (s>mid)
    sum+=Find(s,t,2*cnt+1);
    else
    {
        if (t<=mid)
        sum+=Find(s,t,2*cnt);
        else
        sum+=Find(s,mid,2*cnt)+Find(mid+1,t,2*cnt+1); 
    }
    return sum;
}

int insert(int x,int cnt)
{
    int mid;
    node[cnt].v++;
    if (node[cnt].l==node[cnt].r&&node[cnt].l==x)
    return 1;
    mid=(node[cnt].l+node[cnt].r)/2;
    if (x<=mid)
    insert(x,cnt*2);
    else
    insert(x,2*cnt+1);
    return 1;
}

int main()
{
    int i,y,mmax;
    while (scanf("%d",&n)!=EOF)
    {
        mmax=-1;
        memset(ans,0,sizeof(ans));
        for (i=1;i<=n;i++)
        {
            scanf("%d %d",&input_x[i],&y);
            mmax=max(input_x[i],mmax);
        } 
        Build_Tree(0,mmax,1); //起点,终点,节点序号
        for (i=1;i<=n;i++)
        {   
            ans[Find(0,input_x[i],1)]++;
            insert(input_x[i],1);
        }
        for (i=0;i<n;i++)
        printf("%d\n",ans[i]);
    }
    system("pause");
    return 1;
}
