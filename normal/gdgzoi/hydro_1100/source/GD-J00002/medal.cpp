#include<bits/stdc++.h>
using namespace std;
struct child{int g,s,b,ind;}a[200005];
bool cmpg(child x,child y){return x.g>y.g;}
bool cmps(child x,child y){return x.s>y.s;}
bool cmpb(child x,child y){return x.b>y.b;}
int n,rk[200005];
int main(){
	// freopen("medal.in","r",stdin);
	// freopen("medal.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i].g,&a[i].s,&a[i].b);
		a[i].ind=i;
	}
	sort(a+1,a+n+1,cmpg);
	a[0]={-1,-1,-1,0};
	int crk=1;
	for(int i=1;i<=n;i++){
		if(a[i].g!=a[i-1].g)
			crk=i;
		rk[a[i].ind]=crk;
	}
	sort(a+1,a+n+1,cmps);
	a[0]={-1,-1,-1,0};
	crk=1;
	for(int i=1;i<=n;i++){
		if(a[i].s!=a[i-1].s)
			crk=i;
		rk[a[i].ind]=min(rk[a[i].ind],crk);
	}
	sort(a+1,a+n+1,cmpb);
	a[0]={-1,-1,-1,0};
	crk=1;
	for(int i=1;i<=n;i++){
		if(a[i].b!=a[i-1].b)
			crk=i;
		rk[a[i].ind]=min(rk[a[i].ind],crk);
	}
	for(int i=1;i<=n;i++)
		printf("%d\n",rk[i]);
	return 0;
}