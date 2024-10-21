// https://www.luogu.com.cn/article/2f5x5316
#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,a[N],even[N],odd[N],pre[N];
int main(){
	scanf("%d",&n);
	int b1=0,b2=0;
	odd[0]=-1e9;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[b1]==a[i])
			odd[i]=even[b2]+1;
		else odd[i]=even[b1]+1;
		even[i]=odd[pre[a[i]]]+1;
		if(even[i]>=even[b1]){
			if(a[i]!=a[b1])
				b2=b1;
			b1=i;
		}
		else if(even[i]>=even[b2] && a[i]!=a[b1])
			b2=i;
		pre[a[i]]=i;
	}
	printf("%d\n",even[b1]);
	return 0;
}