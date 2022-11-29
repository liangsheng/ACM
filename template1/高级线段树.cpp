# include <iostream>
# include <cstdio>
# include <algorithm>
# include <cmath>
# include <cstring>
# define MAX 10010
using namespace std;

struct Node
{
    int l,r;
    int len;          //线段长度
    int cover;        //是否被覆盖
    int sum;          //被覆盖的总长度
    int segnum;       //被覆盖的几段
    int l_cover,r_cover;//左右节点是否被覆盖
    Node()
    {
        l=r=0;
        len=cover=sum=0;
        segnum=l_cover=r_cover=0;
    }
};

struct Line
{
    int y1,y2;
    int x;
    int is_in;
    Line()
    {
        y1=y2=0;
        x=0;
    }
};

int n,cnt;
int indexx[MAX];
Line yline[MAX];
Node node[MAX*4];

int cmp(Line k1,Line k2)
{
    if (k1.x<k2.x) return 1;
    if (k1.x == k2.x && k1.is_in == 1) return 1;
    return 0;
}

int Build_Tree(int s,int t,int k)
{
    node[k].l=s;
    node[k].r=t;
    node[k].len=indexx[t]-indexx[s];
    if (t-s>1)
    {
       int mid=(s+t)>>1;
       Build_Tree(s,mid,k*2);
       Build_Tree(mid,t,k*2+1);
    }
    return 1;
}

int get_len(int x)
{
    if (node[x].cover>0)
    node[x].sum=node[x].len;
    else
    {
        if (node[x].r-node[x].l>1)
        node[x].sum=node[x*2].sum+node[x*2+1].sum;
        else
        node[x].sum=0;
    }
    return 1;
}

int get_segnum(int x)
{
    if (node[x].cover>0)
    {
       node[x].l_cover=node[x].r_cover=1;
       node[x].segnum=1;
       return 1;
    }
    if (node[x].r-node[x].l>1)
    {
       node[x].l_cover=node[x*2].l_cover;
       node[x].r_cover=node[x*2+1].r_cover;
       node[x].segnum=node[x*2].segnum+node[x*2+1].segnum-node[x*2].r_cover*node[x*2+1].l_cover;
       return 1;
    }
    node[x].l_cover=node[x].r_cover=0;
    node[x].segnum=0;
    return 1;
}

int insert(int s,int t,int k)
{
    if (node[k].l==s&&node[k].r==t)
    node[k].cover++;
    else
    {
        int mid=(node[k].l+node[k].r)>>1;
        if (t<=mid)
        insert(s,t,k*2);
        else
        if (s>=mid)
        insert(s,t,k*2+1);
        else
        {
            insert(s,mid,k*2);
            insert(mid,t,k*2+1);
        }
    }
    get_len(k);
    get_segnum(k);
    return 1;
}

int Delete(int s,int t,int k)
{
    if (node[k].l==s&&node[k].r==t)
    node[k].cover--;
    else
    {
        int mid=(node[k].l+node[k].r)>>1;
        if (t<=mid)
        Delete(s,t,k*2);
        else
        if (s>=mid)
        Delete(s,t,k*2+1);
        else
        {
            Delete(s,mid,k*2);
            Delete(mid,t,k*2+1);
        }
    }
    get_len(k);
    get_segnum(k);
    return 1;
}

int get_indexx(int x)
{
    int i;
    for (i=0;i<=cnt;i++)
    if (indexx[i]==x)
    break;
    return i;
}

int main()
{
    int i,x1,x2,y1,y2,ans,last;
    cnt=0;
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        yline[i*2].y1=yline[i*2+1].y1=y1;
        yline[i*2].y2=yline[i*2+1].y2=y2;
        yline[i*2].x=x1;
        yline[i*2+1].x=x2;
        yline[i*2].is_in=1;
        yline[i*2+1].is_in=0;
        indexx[i*2]=y1;
        indexx[i*2+1]=y2;
    }
    sort(indexx,indexx+n*2);
    for (i=1;i<n*2;i++)
    {
        if (indexx[i]!=indexx[i-1])
        indexx[++cnt]=indexx[i];
    }
    sort(yline,yline+n*2,cmp);
    Build_Tree(0,cnt,1);
    last=0;
    ans=0;
    for (i=0;i<n*2-1;i++)
    {
        if (yline[i].is_in)
        insert(get_indexx(yline[i].y1),get_indexx(yline[i].y2),1);
        else
        Delete(get_indexx(yline[i].y1),get_indexx(yline[i].y2),1);
        ans+=node[1].segnum*(yline[i+1].x-yline[i].x)*2;
        ans+=abs(node[1].sum-last);
        last=node[1].sum;
    }
    Delete(get_indexx(yline[n*2-1].y1),get_indexx(yline[n*2-1].y2),1);
    ans+=abs(node[1].sum-last);
    printf("%d\n",ans);
    system("pause");
    return 1;
}
