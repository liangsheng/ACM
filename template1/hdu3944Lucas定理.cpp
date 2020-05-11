#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int prime[1300];
bool flag[10000];
int map[10000];
int pi[1300][10000];
int re[1300][10000];

int extend_gcd(int a,int b,int &x,int &y)
{
	int t,ret;
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	else
	{
		ret=extend_gcd(b,a%b,x,y);
		t=x;
		x=y;
		y=t-a/b*y;
		return ret;
	}
}

void init()
{
	int i,j,num=0,k,x,y;
	for(i=2;i<10000;i++)
	{
		if(!flag[i])
		{
			prime[num++]=i;
			for(j=i*i;j<10000;j=j+i)
				flag[j]=true;
		}
	}
	for(i=0;i<num;i++)
	{
		k=prime[i];
		map[k]=i;
		pi[i][0]=1,pi[i][1]=1;
		re[i][0]=1,re[i][1]=1;
		for(j=2;j<k;j++)
		{
			pi[i][j]=j*pi[i][j-1]%prime[i];
			int tmp=extend_gcd(j,prime[i],x,y);
			re[i][j]=(x%prime[i]+prime[i])%prime[i];
		}
	}
	for(i=0;i<num;i++)
	{
		k=prime[i];
		for(j=1;j<k;j++)
			re[i][j]=(re[i][j]*re[i][j-1])%prime[i];
	}
}

int lucas(int n,int m,int p)
{
	if(n<m)
		return 0;
	int x=map[p];
	return pi[x][n]*re[x][m]%p*re[x][n-m]%p;
}

int main()
{
	int n,k,cnt=1,p,tmp,res;
	init();
	while(scanf("%d%d%d",&n,&k,&p)!=EOF)
	{
		if(k>n/2)
			k=n-k;
		tmp=n-k,res=1;
		n=n+1;
		while(n&&k)
		{
			res=res*lucas(n%p,k%p,p)%p;
			n=n/p;
			k=k/p;
		}
		printf("Case #%d: %d\n",cnt++,(res+tmp)%p);
	}
	return 0;
}
