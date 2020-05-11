#include<iostream>
#include<stack>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAX=2050;
struct node
{
	int v,next;
}g[MAX*MAX];
int low[MAX],dfn[MAX],adj[MAX],inStack[MAX],bel[MAX],ind[MAX];
int path[MAX][MAX],col[MAX],cf[MAX],op[MAX],dt[MAX],start[MAX],end[MAX];
int n,e,index,cnt;
stack<int>s;
void add(int u,int v)
{
	g[e].v=v; g[e].next=adj[u]; adj[u]=e++;
}
void tarjan(int u)
{
	int i,v;
	low[u]=dfn[u]=++index;
	s.push(u);
	inStack[u]=1;
	for(i=adj[u];i!=-1;i=g[i].next)
	{
		v=g[i].v;
		if(!dfn[v])
		{
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(inStack[v])
			low[u]=min(low[u],dfn[v]);
	}
	if(dfn[u]==low[u])
	{
		cnt++;
		do
		{
			v=s.top();
			s.pop();
			inStack[v]=0;
			bel[v]=cnt;
		}while(u!=v);
	}
}
bool contradict(int i,int j)
{
	if(i==op[j]||i==j)
		return false;
	//if(start[i]<=start[j]&&end[i]<=end[j]&&end[i]>=start[j])
	if(start[i]<end[j]&&start[j]<end[i])
		return true;
	//if(start[j]<=start[i]&&end[j]<=end[i]&&end[j]>=start[i])
		//return true;
	return false;
}
void topsort()
{
	int i,j,u,v;
	for(i=1;i<=cnt;i++)
		if(ind[i]==0)
			s.push(i);
	while(!s.empty())
	{
		u=s.top();
		s.pop();
		if(!col[u])
		{
			col[u]=1;
			col[cf[u]]=2;
		}
		for(v=1;v<=cnt;v++)
		{
			if(u!=v&&path[u][v])
			{
				if(--ind[v]==0)
					s.push(v);
			}
		}
	}
}
void solve()
{
	int i,j,h,m;
	for(i=0;i<2*n;i++)
	{
		for(j=0;j<2*n;j++)
		{
			if(contradict(i,j))
			{
				add(i,op[j]);
				//add(j,op[i]);
			}
		}
	}
	for(i=0;i<2*n;i++)
	{
		if(!dfn[i])
			tarjan(i);
	}
	for(i=0;i<n;i++)
	{
		if(bel[i]==bel[i+n])
		{
			puts("NO");
			return;
		}
		cf[bel[i]]=bel[i+n];
		cf[bel[i+n]]=bel[i];
	}
	puts("YES");
	memset(path,0,sizeof(path));
	memset(ind,0,sizeof(ind));
	for(int u=0;u<2*n;u++)
	{
		for(i=adj[u];i!=-1;i=g[i].next)
		{
	 		int v=g[i].v;
			if(bel[u]!=bel[v])
				path[bel[v]][bel[u]]=1;
		}
	}
	//for (i = 1; i < 3; i++){
	//    for (j = 1; j < 3; j++)
	 //       cout << path[i][j] << " ";
	  //      cout << endl;}
   // system("pause");	
	//cout<<"yes"<<endl;
	for(i=1;i<=cnt;i++)
		for(j=1;j<=cnt;j++)
		{
			if(path[i][j])
				ind[j]++;
		}
	
	memset(col,0,sizeof(col));
	topsort();
	//cout<<"yes"<<endl;
	//for(i=0;i<2*n;i++)
	//	cout<<col[bel[i]]<<endl;
	for(i=0;i<n;i++)
	{
		if(col[bel[i]]==1)
			j=i;
		else
			j=i+n;
		if((start[j]/60)<10)
			printf("0");
		printf("%d:",start[j]/60);
		if((start[j]%60)<10)
			printf("0");
		printf("%d ",start[j]%60);
		if((end[j]/60)<10)
			printf("0");
		printf("%d:",end[j]/60);
		if((end[j]%60)<10)
			printf("0");
		printf("%d\n",end[j]%60);
	}
}
int main()
{
	int i,j,t;
	char s[20];
	scanf("%d",&n);
	for(i=0;i<n;i++)
		op[i]=i+n;
	for(i=n;i<2*n;i++)
		op[i]=i-n;
	memset(adj,-1,sizeof(adj));
	memset(dfn,0,sizeof(dfn));
	e=index=cnt=0;
	for(j=0;j<n;j++)
	{
		scanf("%s",&s);
		t=((s[0]-'0')*10+s[1]-'0')*60+(s[3]-'0')*10+s[4]-'0';
		start[j]=t;
		scanf("%s",&s);
		t=((s[0]-'0')*10+s[1]-'0')*60+(s[3]-'0')*10+s[4]-'0';
		end[j+n]=t;
		scanf("%d",&dt[j]);
		end[j]=start[j]+dt[j];
		start[j+n]=end[j+n]-dt[j];
		//cout<<start[j]<<" "<<end[j]<<endl;
		//cout<<start[j+n]<<" "<<end[j+n]<<endl;
	}
	solve();
	system("pause");
	return 0;
}
