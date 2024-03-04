#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<set>
#define ll long long
#define inf 100000000
using namespace std;
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int S,T;
int n,cnt=1,top;
int last[105],d[105],ans[205],x[105],y[105];
int mp[105][105];
void dfs(int x)
{
    for(int i=1;i<=7;i++)
		if(mp[x][i])
		{
			d[x]--;d[i]--;
			mp[x][i]--;
			mp[i][x]--;
			dfs(i);
		}
	ans[++top]=x;
}
bool equ(int u,int v,int t)
{
	if((u==x[t]&&v==y[t])||(u==y[t]&&v==x[t]))return 1;
	return 0;
}
int main()
{
	//freopen("greatunion.in","r",stdin);
	//freopen("greatunion.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
	{
		x[i]=read(),y[i]=read();
		x[i]++;y[i]++;
		d[x[i]]++;d[y[i]]++;
		mp[x[i]][y[i]]++;mp[y[i]][x[i]]++;
	}
	int tot=0;
	for(int i=1;i<=7;i++)
		if(d[i]&1)tot++;
	if(tot!=0&&tot!=2)
	{
		puts("No Solution");
		return 0;
	}
	for(int i=1;i<=7;i++)
	{
		if(d[i]&1)
		{
			if(S==0)S=i;
			else T=i;
		}
		if(d[i]&&!tot)S=i;
	}
	dfs(S);
    for(int i=1;i<=7;i++)
		if(d[i])
		{
			puts("No Solution");
			return 0;
		}
	for(int i=1;i<top;i++)
		for(int j=1;j<=n;j++)
			if(equ(ans[i],ans[i+1],j))
			{
				printf("%d ",j);
				if(ans[i]==x[j])puts("+");
				else puts("-");
				x[j]=-1;
				break;
			}
	return 0;
}