# include <iostream>
# include <cstdio>
# include <cstring>
# define MAX 1010
using namespace std;

int test,n,cnt,sum;
int tre[MAX*3][MAX*3];

int Add_Y(int rootx,int rooty,int s,int t,int y1,int y2)
{
    if (s==y1&&t==y2)
    tre[rootx][rooty]=!tre[rootx][rooty];
    else
    {
        int mid=(s+t)>>1;
        if (y2<=mid)
        Add_Y(rootx,rooty<<1,s,mid,y1,y2);
        else if (y1>mid)
        Add_Y(rootx,(rooty<<1)+1,mid+1,t,y1,y2);
        else
        {
            Add_Y(rootx,rooty<<1,s,mid,y1,mid);
            Add_Y(rootx,(rooty<<1)+1,mid+1,t,mid+1,y2);
        }
    }
    return 1;
}

int Add_X(int root,int s,int t,int x1,int x2,int y1,int y2)
{
    if (s==x1&&t==x2)
    Add_Y(root,1,1,n,y1,y2);
    else
    {
        int mid=(s+t)>>1;
        if (x2<=mid)
        Add_X(root<<1,s,mid,x1,x2,y1,y2);
        else if (x1>mid)
        Add_X((root<<1)+1,mid+1,t,x1,x2,y1,y2);
        else
        {
            Add_X(root<<1,s,mid,x1,mid,y1,y2);
            Add_X((root<<1)+1,mid+1,t,mid+1,x2,y1,y2);
        }
    }
    return 1;
}

int Query_Y(int rootx,int rooty,int s,int t,int y)
{
    sum+=tre[rootx][rooty];
    if (s==t&&s==y)
    return 1;
    else
    {
        int mid=(s+t)>>1;
        if (y<=mid)
        Query_Y(rootx,rooty<<1,s,mid,y);
        else
        Query_Y(rootx,(rooty<<1)+1,mid+1,t,y);
    }
    return 1;
}

int Query_X(int root,int s,int t,int x,int y)
{
    Query_Y(root,1,1,n,y);
    if (s==t)
    return 1;
    else
    {
       int mid=(s+t)>>1;
       if (x<=mid)
       Query_X(root<<1,s,mid,x,y);
       else
       Query_X((root<<1)+1,mid+1,t,x,y); 
    }
    return 1;
}

int main()
{
    int x1,x2,y1,y2;
    char cmd;
    scanf("%d",&test);
    while (test--)
    {
         memset(tre,0,sizeof(tre));
         scanf("%d %d",&n,&cnt); 
         while (cnt--)
         {
             while (scanf("%c",&cmd)&&(cmd<'A'||cmd>'Z'));
             if (cmd=='C')
             {
                scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
                Add_X(1,1,n,x1,x2,y1,y2);          
             } 
             if (cmd=='Q')
             {
                sum=0;
                scanf("%d %d",&x1,&y1);
                Query_X(1,1,n,x1,y1);
                printf("%d\n",sum%2);          
             } 
         }
         printf("\n");
    }
    system("pause");
    return 1;
}
