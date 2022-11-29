#include <stdio.h>
#include <memory.h>
#include <math.h>

void solve (int k);
void recursion (int k);
void account (int p);
void mul (int a[31][31],int b[31][31]);
void print (int d[31][31]);

int sum[31][31];              //结果矩阵
int cur[31][31];              //中间量矩阵
int dis[31][31];              //中间量矩阵
int num[50][31][31];          //保存2的k次幂的矩阵
int n,m;

int main ()
{
     memset (num,0,sizeof (num));
     memset (cur,0,sizeof (cur));
     memset (sum,0,sizeof (sum));
     memset (dis,0,sizeof (dis));
     int i,j;
     int k;
     scanf ("%d%d%d",&n,&k,&m);
     for (i=1 ;i<=n ;i++)                    //输入数据
          for (j=1 ;j<=n ;j++)
               scanf ("%d",&num[1][i][j]);
     solve (k);
     for (i=1 ;i<=n ;i++)
     {
          printf ("%d",sum[i][1]);
          for (j=2 ;j<=n ;j++)
               printf (" %d",sum[i][j]);
          printf ("\n");
     }
     return 0;
}
void solve (int k)                           //求解
{
     int size=1;
     int i,j,p,q;
     i=k;
     while (i)
     {
          size++;
          i/=2;
     }
     for (p=2 ;p<=size+1 ;p++)                             // O(50*30*30*30) 求解2的固定次数的矩阵
          for (i=1 ;i<=n ;i++)
               for (j=1 ;j<=n ;j++)
                    for (q=1 ;q<=n ;q++)
                    {
                         num[p][i][j]+=num[p-1][i][q] * num[p-1][q][j];
                         num[p][i][j]%=m;
                    }
     recursion (k);
     return ;
}
void recursion (int k)                       //迭代函数
{
     int i,j,l;
     if (k<=2)                               //迭代结束标志
     {
          for (l=1 ;l<=k ;l++)
               for (i=1 ;i<=n ;i++)
                    for (j=1 ;j<=n ;j++)
                    {
                         sum[i][j]+=num[l][i][j];
                         sum[i][j]%=m;
                    }
          return ;
     }
     recursion (k/2);
     account ((k-1)/2+1);                    //求后一块的因子
     if (k%2==0)
          for (i=1 ;i<=n ;i++)
          {
               cur[i][i]++;
               cur[i][i]%=m;
          }
     else
          for (i=1 ;i<=n ;i++)
               for (j=1 ;j<=n ;j++)
               {
                    cur[i][j]+=num[1][i][j];
                    cur[i][j]%=m;
               }
     mul (cur,sum);
     if (k%2==1)
     {
          for (i=1 ;i<=n ;i++)
               for (j=1 ;j<=n ;j++)
               {
                    sum[i][j]+=num[1][i][j];
                    sum[i][j]%=m;
               }
     }
     return ;
}
void account (int p)
{
     int q=1;
     int i,j;
     memset (cur,0,sizeof (cur));
     for (i=1 ;i<=n ;i++)
          cur[i][i]=1;
     while (p)
     {
          if (p%2==1)
               mul (num[q],cur);
          q++;
          p/=2;
     }
     return ;
}
void mul (int a[31][31],int b[31][31])
{
     int i,j,t;
     for (i=1 ;i<=n ;i++)
          for (j=1 ;j<=n ;j++)
          {
               dis[i][j]=0;
               for (t=1 ;t<=n ;t++)
               {
                    dis[i][j]+=a[i][t] * b[t][j];
                    dis[i][j]%=m;
               }
          }
     for (i=1 ;i<=n ;i++)
          for (j=1 ;j<=n ;j++)
               b[i][j]=dis[i][j];
     return ;
}
