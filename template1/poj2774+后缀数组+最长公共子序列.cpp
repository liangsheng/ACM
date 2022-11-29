# include <iostream>
# include <cstdio>
# include <cstring>
# include <cmath>
# define N 200010
using namespace std;

char str[100010];
int sa[N];  //index range 1~n value range 0~n-1
int rank[N];   //index range 0~n-1 value range 1~n
int height[N]; //index from 1   (height[1] = 0) 
int r[N],wa[N],wb[N],wc[N],wv[N];

int cmp(int *r,int a,int b,int j)
{
    return r[a]==r[b]&&r[a+j]==r[b+j];
}

int da(int *r,int *sa,int n,int m)
{
    int i,j,p,*x=wa,*y=wb,*t;
    for (i=0;i<m;i++) wc[i]=0;
    for (i=0;i<n;i++) wc[x[i]=r[i]]++;
    for (i=1;i<m;i++) wc[i]+=wc[i-1];
    for (i=n-1;i>=0;i--) sa[--wc[x[i]]]=i;
    for (j=1,p=1;p<n;j*=2,m=p)
    {
        for (p=0,i=n-j;i<n;i++) y[p++]=i;
        for (i=0;i<n;i++) if (sa[i]>=j) y[p++]=sa[i]-j;
        for (i=0;i<n;i++) wv[i]=x[y[i]];
        for (i=0;i<m;i++) wc[i]=0;
        for (i=0;i<n;i++) wc[wv[i]]++;
        for (i=1;i<m;i++) wc[i]+=wc[i-1];
        for (i=n-1;i>=0;i--) sa[--wc[wv[i]]]=y[i];
        for (t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
        x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }
    return 1;
}

int calheight(int *r,int *sa,int n)
{
    int i,j,k=0;
    for (i=1;i<=n;i++) rank[sa[i]]=i;
    for (i=0;i<n;height[rank[i++]]=k)
    for (k?k--:0,j=sa[rank[i]-1];r[i+k]==r[j+k];k++);
    return 1;
}

int main()
{
    int i,l,n=0,len,p=0;
    for (l=1;l<=2;l++)
    {
        scanf("%s",str);
        len=strlen(str);
        if (p==0) p=len;
        for (i=0;i<len;i++)
        r[n++]=str[i]-96;
        if (l!=2) r[n++]=27;
    }
    r[n]=0;
    da(r,sa,n+1,28);  
    calheight(r,sa,n);
    int ans=0;
    for (i=2;i<=n;i++)
    if ((sa[i]<p&&sa[i-1]>p)||(sa[i]>p&&sa[i-1]<p))
    ans=max(ans,height[i]);
    printf("%d\n",ans);
    system("pause");
    return 1;
}
