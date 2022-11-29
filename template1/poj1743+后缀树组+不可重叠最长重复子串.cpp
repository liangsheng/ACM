# include <iostream>
# include <cstdio>
# define N 20010
using namespace std;

int r[N];
int sa[N],rank[N],height[N];
int wa[N],wb[N],wc[N],wv[N];

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

int judge(int *r,int *sa,int *rank,int *height,int n,int k)
{
    int mini,maxi,i;
    for (i=1;i<=n;i++)
    {
        if (height[i]<k)
        mini=maxi=sa[i];
        else if (sa[i]<mini)
        {
            mini=sa[i];
            if (maxi-mini>=k)
            return 1; 
        }
        else if (sa[i]>maxi)
        {
            maxi=sa[i];
            if (maxi-mini>=k)
            return 1; 
        }
    }
    return 0;
}

int main()
{
    int i,n,low,high,mid;
    while (scanf("%d",&n)!=EOF,n)
    {
        for (i=0;i<n;i++)
        scanf("%d",&r[i]);
        for (i=n-1;i>0;i--)
        r[i]-=r[i-1],r[i]+=88; 
        r[n]=0;
        da(r,sa,n+1,180);
        calheight(r,sa,n);
        low=0;
        high=n/2;
        while (low<high)
        {
            mid=(low+high+1)>>1;
            if (judge(r,sa,rank,height,n,mid))
            low=mid;
            else
            high=mid-1; 
        }
        if (low<4)
        printf("0\n");
        else
        printf("%d\n",low+1);        
    }
    system("pause");
    return 1;
}
