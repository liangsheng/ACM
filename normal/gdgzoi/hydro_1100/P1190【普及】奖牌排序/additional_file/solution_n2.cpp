#include<bits/stdc++.h>
using namespace std;
int n,g[200005],s[200005],b[200005];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d%d",&g[i],&s[i],&b[i]);
	for(int i=1;i<=n;i++){
		int rkg=1,rks=1,rkb=1;
		for(int j=1;j<=n;j++)
			if(g[j]>g[i])
				rkg++;
		for(int j=1;j<=n;j++)
			if(s[j]>s[i])
				rks++;
		for(int j=1;j<=n;j++)
			if(b[j]>b[i])
				rkb++;
		printf("%d\n",min(min(rkg,rks),rkb));
	}
	return 0;
}