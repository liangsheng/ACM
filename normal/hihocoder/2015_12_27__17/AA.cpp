#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
unsigned long long x[11000],key=10007,Key[110000],pre[110000],ne[110000];
char ch[110000];
int n,m,pd[11000],sign;
int find(unsigned long long k){
	int l=1,r=n+1;
	while (l<r){
		int mid=l+r>>1;
		if (x[mid]==k){
			if (pd[mid]!=sign){
				pd[mid]=sign; return 1;
			} else return 0;
		}
		if (x[mid]>k) r=mid; else l=mid+1;
	}
	return 0;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%s",ch+1); int len=strlen(ch+1);
		for (int j=1;j<=len;j++) x[i]=x[i]*key+ch[j];
	}
	Key[0]=1;
	for (int i=1;i<=100000;i++) Key[i]=Key[i-1]*key;
	sort(x+1,x+n+1);
	for (;m;m--){
		scanf("%s",ch+1); int len=strlen(ch+1); int ans=0; sign++;
		for (int j=1;j<=len;j++) pre[j]=pre[j-1]*key+ch[j];
		ne[len+1]=0;
		for (int j=len;j;j--) ne[j]=ne[j+1]+ch[j]*Key[len-j];
		for (int i=0;i<=len;i++)
			for (int j='a';j<='z';j++){
				unsigned long long now=pre[i]*Key[len-i+1]+j*Key[len-i]+ne[i+1];
				ans+=find(now);
			}
		printf("%d\n",ans);
	}
	return 0;
}
