#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define file_r(x) freopen(x,  "r",  stdin)
#define file_w(x) freopen(x,  "w",  stdout)
using namespace std;
const int INF=1000000000;
int T,n,c[3000],f[2050][2050];
int main()
{
    //file_r("in.in");
    //file_w("2.out");
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i=0;i<n-1;i++) scanf("%d",&c[i]);
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
				f[i][j]=-INF;
		f[0][0]=n*c[0];
		for(int i=1;i<=n-2;i++)
		{
			for(int j=1;j<=n;j++)
				f[i][j]=max(f[i][j],f[i-1][j-1]+c[j]-c[j-1]);
			int res=-INF;
			for(int j=0;j<=n;j++)
				res=max(res,f[i-1][j]);
			f[i][1]=res+c[1]-c[0];
		}
		int res=-INF;
		for(int i=0;i<=n;i++)
			res=max(res,f[n-2][i]);
		printf("%d\n",res);
	}
	return 0;
}
