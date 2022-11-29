#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAX=250;
const int inf=1<<29;
struct node
{
	int v,c,next;
}g[100000];
int dis[MAX],num[MAX],cur[MAX],pre[MAX],adj[MAX],D[MAX];
int low[MAX][MAX],up[MAX][MAX],row[MAX],col[MAX],f[MAX][MAX];
int s,t,vn,e,flag,S,T,m,n;
void add(int u,int v,int c)
{
	g[e].v=v; g[e].c=c; g[e].next=adj[u]; adj[u]=e++;
	g[e].v=u; g[e].c=0; g[e].next=adj[v]; adj[v]=e++;
}
void set(int i,int j,char cons,int x)
{
	//if(flag)
		//return;
	if(cons=='=')
	{
		if(low[i][j]>x||up[i][j]<x)
		{
			flag=1;
 			return;
		}
		low[i][j]=up[i][j]=x;
	}
	else if(cons=='>')
	{
		low[i][j]=low[i][j]>x+1?low[i][j]:x+1;
	}
	else up[i][j]=up[i][j]<x-1?up[i][j]:x-1;
	if(low[i][j]>up[i][j])
		flag=1;
}
/*bool ok()
{
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
			if(low[i][j]>up[i][j])
				return false;
	return true;
}*/
int sap()
{
	int u,v,i,flow=0,aug=inf,flag;
	for(i=0;i<=vn;i++)
	{
		dis[i]=num[i]=0;
		cur[i]=adj[i];
	}
	num[0]=vn;
	pre[S]=u=S;
	while(dis[S]<vn)
	{
		flag=0;
		for(i=cur[u];i!=-1;i=g[i].next)
		{
			v=g[i].v;
			if(g[i].c&&dis[u]==dis[v]+1)
			{
				flag=1;
				cur[u]=i;
				aug=min(aug,g[i].c);
				pre[v]=u;
				u=v;
				if(u==T)
				{
					flow+=aug;
					while(u!=S)
					{
						f[pre[u]][u]+=aug;
						f[u][pre[u]]-=aug;//注意反向边，回流 
						u=pre[u];
						g[cur[u]].c-=aug;//u->v
						g[cur[u]^1].c+=aug;//v->u
					}
					aug=inf;
				}
				break;
			}
		}
		if(flag)
			continue;
		if(--num[dis[u]]==0)
			break;
		for(dis[u]=vn,i=adj[u];i!=-1;i=g[i].next)
		{
			v=g[i].v;
			if(g[i].c&&dis[v]<dis[u])
			{
				dis[u]=dis[v];
				cur[u]=i;
			}
		}
		dis[u]++;
		num[dis[u]]++;
		u=pre[u];
	}
	return flow;
}
void solve()
{
	int i,j;
	bool can=true;
	e=0;
	memset(adj,-1,sizeof(adj));
	memset(D,0,sizeof(D));
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
		{
			add(i,m+j,up[i][j]-low[i][j]);
			D[i]-=low[i][j];
			D[m+j]+=low[i][j];
		}
	for(i=1;i<=m;i++)
	{
		add(s,i,0);
		D[i]+=row[i];
		D[s]-=row[i];
	}
	for(i=1;i<=n;i++)
	{
		add(m+i,t,0);
		D[m+i]-=col[i];
		D[t]+=col[i];
	}
	add(t,s,inf);
	for(i=0;i<=m+n+1;i++)
	{
		if(D[i]>0)
			add(S,i,D[i]);
		else if(D[i]<0)
			add(i,T,-D[i]);
	}
	memset(f,0,sizeof(f));
	sap();
	for(i=adj[S];i!=-1;i=g[i].next)
	{
		//cout<<i<<" "<<g[i].v<<" "<<g[i].c<<endl;
		if(i%2==0&&g[i].c)
		{
			can=false;
			break;
		}
	}
	if(!can)
	{
		puts("IMPOSSIBLE");
		return;
	}
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			//if(j%2==0&&g[j].v>=m+1&&g[j].v<=m+n)
				//f[i][g[j].v-m]=g[j^1].c+low[i][g[j].v-m];
			printf("%d",low[i][j]+f[i][j+m]);
			if(j!=n)
				printf(" ");
		}
		printf("\n");
	}		
/*for(i = 1; i <= m; ++ i)
        for(j = 1; j <= n; ++ j)
            printf("%d%c",f[i][j], j == n ? '\n': ' ');*/
}
int main()
{
	int N,i,j,c,x,a,b,cnt=0;
	char constraint[2];
	scanf("%d",&N);
	while(N--)
	{
		if(cnt)	puts("");
		cnt=1;
		scanf("%d%d",&m,&n);
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=n;j++)
			{
				up[i][j]=inf;
				low[i][j]=0;
			}
		}
		s=0;
		t=m+n+1;
		S=t+1;
		T=S+1;
		vn=T+1;
		for(i=1;i<=m;i++)
			scanf("%d",&row[i]);
		for(j=1;j<=n;j++)
			scanf("%d",&col[j]);
		flag=0;
		scanf("%d",&c);
		while(c--)
		{
			scanf("%d%d%s%d",&i,&j,&constraint,&x);
			if(!i&&!j)
			{
				for(a=1;a<=m;a++)
					for(b=1;b<=n;b++)
						set(a,b,constraint[0],x);
			}
			else if(!i&&j)
				for(a=1;a<=m;a++) set(a,j,constraint[0],x);
			else if(i&&!j)
				for(a=1;a<=n;a++) set(i,a,constraint[0],x);
			else set(i,j,constraint[0],x);
			
		}
		
		if(!flag)
		{
			solve();
		}
		else 
			puts("IMPOSSIBLE");
	}
	system("pause"); 
	return 0;
}
