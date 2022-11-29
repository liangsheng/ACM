#include <cstdio>
const int N=10005,M=10;
int n,m,a[N][M];
inline int read() {
	int x=0,flag=0;char ch=getchar();
	while(ch<'0'||ch>'9') {flag|=(ch=='-');ch=getchar();}
	while('0'<=ch&&ch<='9') {x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return flag?-x:x;
}
inline int mx(int x,int y) {return x>y?x:y;}
int main() {
// #ifndef ONLINE_JUDGE
// 	freopen("1.in","r",stdin);
// 	freopen("1.out","w",stdout);
// #endif
	n=read();m=read();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			a[i][j]=read();
	for(int i=2;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(a[i][j]%7!=a[1][j]%7) {
				printf("No\n");
				return 0;
			}
	for(int j=2;j<=m;++j)
		if((a[1][j]-1)%7+1!=(a[1][j-1]-1)%7+2) {
			printf("No\n");
			return 0;
		}
	printf("Yes\n");
	return 0;
}