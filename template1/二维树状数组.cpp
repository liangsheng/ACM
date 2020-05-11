# include <iostream>
# include <cstdio>
# include <cstring>
# define MAX 1010
using namespace std;

int test,n,cnt;
int tre[MAX][MAX];

int Lowbit(int x)
{
    return x&(-x);
}

int Add(int x,int y)
{
    while (x<=n)
    {
        int t=y;
        while (t<=n)
        {
            tre[x][t]++;
            t+=Lowbit(t);  
        }
        x+=Lowbit(x);  
    }
    return 1;
}

int get_ans(int x,int y)
{
    int sum=0;
    while (x>0)
    {
        int t=y;
        while (t>0)
        {
            sum+=tre[x][t];
            t-=Lowbit(t);  
        }
        x-=Lowbit(x);  
    }
    return sum%2;
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
               Add(x1,y1);
               Add(x1,y2+1);
               Add(x2+1,y1);
               Add(x2+1,y2+1);          
            }
            if (cmd=='Q')
            {
               scanf("%d %d",&x1,&y1);
               printf("%d\n",get_ans(x1,y1));          
            }  
        } 
        printf("\n");
    }
    system("pause");
    return 1;
}
