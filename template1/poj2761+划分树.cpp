# include <iostream>
# include <cstdio>
# include <algorithm>
# define N 100005
using namespace std;

struct NODE
{
    int l,r;   
};

int n,m;
NODE node[N*4];
int sorted[N],toleft[20][N],val[20][N];

int Build_Tree(int l,int r,int d,int k)
{
    int i;
    node[k].l=l;
    node[k].r=r;
    if (l==r) return 1;
    int mid=(l+r)>>1;
    int lsame=mid-l+1;
    for (i=l;i<=r;i++)
    if (val[d][i]<sorted[mid])
    lsame--;
    int lpos=l,rpos=mid+1,same=0;
    for (i=l;i<=r;i++)
    {
        if (i==l)
        toleft[d][i]=0;
        else
        toleft[d][i]=toleft[d][i-1];
        if (val[d][i]<sorted[mid])
        {
            toleft[d][i]++;
            val[d+1][lpos++]=val[d][i];
        }
        else if (val[d][i]>sorted[mid])
        val[d+1][rpos++]=val[d][i];
        else
        {
            if (same<lsame)
            {
                same++;
                toleft[d][i]++;
                val[d+1][lpos++]=val[d][i]; 
            }
            else
            val[d+1][rpos++]=val[d][i];
        }
    }
    Build_Tree(l,mid,d+1,k<<1);
    Build_Tree(mid+1,r,d+1,(k<<1)+1);
    return 1;
}

int query(int l,int r,int k,int d,int idx)
{
    if (l==r)
    return val[d][l];
    int s;  //s表示[l,r]中有多少个分到左边 
    int ss; //ss表示[node[idx].l,l-1]中有多少个分到左边
    int newl,newr;
    if (l==node[idx].l)
    {
        ss=0;
        s=toleft[d][r];                
    } 
    else
    {
        ss=toleft[d][l-1];
        s=toleft[d][r]-toleft[d][l-1];
    }
    if (s>=k)
    {
        newl=node[idx].l+ss;
        newr=node[idx].l+ss+s-1;
        return query(newl,newr,k,d+1,idx<<1);     
    }
    else
    {
        int mid=(node[idx].l+node[idx].r)>>1;
        int bb=l-node[idx].l-ss;//bb表示[node[idx].l,l-1]中有多少个分到右边
        int b=r-l+1-s;//b表示[l,r]中有多少个分到右边
        newl=mid+bb+1;
        newr=mid+bb+b;
        return query(newl,newr,k-s,d+1,(idx<<1)+1); 
    }
}

int main()
{
    int i,l,r,k,ans;
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;i++)
    {
        scanf("%d",&val[0][i]);
        sorted[i]=val[0][i];
    }
    sort(sorted+1,sorted+n+1);
    Build_Tree(1,n,0,1);
    for (i=1;i<=m;i++)
    {
        scanf("%d%d%d",&l,&r,&k);
        ans=query(l,r,k,0,1);
        printf("%d\n",ans);
    }
    system("pause");
    return 1;
}
